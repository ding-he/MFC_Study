#include <WinSock2.h>
#include <stdio.h>
#include <Ws2tcpip.h>

#define RXTX_BUFFER_SIZE		1024

void main3()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	static SOCKET sockSrv;
	static SOCKET sockClient;
	static SOCKADDR_IN addrSrv;
	static SOCKADDR_IN addrClient;
	static int len;
	static unsigned char flag = 0;
	int size = 66614;
	char *pBuf;
	int contentLength;
	int retlen;
	int buffersize;
	int i;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return;
	}

	pBuf = (char*)malloc(size); //����ͼ���ڴ�ռ�

	for (i = 0; i < 2000; i++) {
		if (flag == 0) {
			flag = 1;

			sockSrv = socket(AF_INET, SOCK_STREAM, 0); //�����׽���
			addrSrv.sin_family = AF_INET;
			addrSrv.sin_port = htons(6000);
			addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

			bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)); //���׽���

			listen(sockSrv, 5); //����ģʽ, �ȴ��ͻ�������

			len = sizeof(SOCKADDR);

			sockClient = accept(sockSrv, (SOCKADDR*)&addrClient, &len); //�ȴ��û�����
		}

		contentLength = size;
		while (contentLength > 0) { //�ղ������� => �ֶ�ν���
			if (contentLength > RXTX_BUFFER_SIZE)
				buffersize = RXTX_BUFFER_SIZE;
			else
				buffersize = contentLength;
			retlen = recv(sockClient, pBuf + size - contentLength, buffersize,
				0);
			if (retlen > 0) {
				contentLength -= retlen;
			}
		}

		/* ʲôҲ����, �ȴ�����, ԭ���ݷ��� */
		// ��������

		contentLength = size;
		while (contentLength > 0) { //�������ٷ� => �ֶ�η���
			if (contentLength > RXTX_BUFFER_SIZE)
				buffersize = RXTX_BUFFER_SIZE;
			else
				buffersize = contentLength;
			retlen = send(sockClient, pBuf + size - contentLength,
				buffersize, 0);
			if (retlen > 0) {
				contentLength -= retlen;
			}
		}
	}

	free(pBuf); //�ͷ��ڴ�
}

void main2()
{
	static SOCKET sockSrv;
	static SOCKET sockClient;
	static SOCKADDR_IN addrSrv;
	static SOCKADDR_IN addrClient;
	//char ipBuf[20];
	static char sendBuf[20];
	static int len;
	static int num;
	static unsigned char flag = 0;
	static int times = 0;

	static int size = 0x22852;
	static char *pBuf;
	int contentLength;
	int retlen;
	int buffersize;

	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	pBuf = (char*)malloc(size); //����ͼ���ڴ�ռ�

	wVersionRequested = MAKEWORD(1, 1);		//���ֽڴ����汾, ���ֽڴ������汾
	//a�ǵ��ֽ�, b�Ǹ��ֽ�

	err = WSAStartup(wVersionRequested, &wsaData);

	if (err != 0)
	{
		//��0����ʧ��
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		//�汾�Ų�һ��, �رղ�����
		WSACleanup();
		return;
	}

	while (1) {
		//printf("123456");

		if (flag == 0) {
			flag = 1;

			sockSrv = socket(AF_INET, SOCK_STREAM, 0); //�����׽���
			addrSrv.sin_family = AF_INET;
			addrSrv.sin_port = htons(6000);
			addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

			bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)); //���׽���

			listen(sockSrv, 5); //����ģʽ, �ȴ��ͻ�������

			len = sizeof(SOCKADDR);

			sockClient = accept(sockSrv, (SOCKADDR*)&addrClient, &len); //�ȴ��û�����
		}

		//inet_ntop(AF_INET, &addrClient.sin_addr, ipBuf, 16);

		//		recv(sockClient, sendBuf, 20, 0);
		//recv(sockClient, pBuf, size, 0);
		contentLength = size;
		while (contentLength > 0) {
			if (contentLength > RXTX_BUFFER_SIZE)
				buffersize = RXTX_BUFFER_SIZE;
			else
				buffersize = contentLength;
			retlen = recv(sockClient, pBuf + size - contentLength, buffersize, 0);
			if (retlen > 0 && retlen == buffersize) {
				contentLength -= retlen;
			}
		}

		//		num = atoi(sendBuf);
		//		num *= 2;
		//		sprintf( sendBuf, "%d", num );

		/* ʲôҲ����, �ȴ�����, ԭ���ݷ��� */


		//		send(sockClient, sendBuf, strlen(sendBuf) + 1, 0);
		//send(sockClient, pBuf, size, 0);
		contentLength = size;
		while (contentLength > 0) {
			if (contentLength > RXTX_BUFFER_SIZE)
				buffersize = RXTX_BUFFER_SIZE;
			else
				buffersize = contentLength;
			retlen = send(sockClient, pBuf + size - contentLength, buffersize, 0);
			if (retlen > 0 && retlen == buffersize) {
				contentLength -= retlen;
			}
		}

		times++;
		if (times == 100) {
			times = 0;
			break;
		}
		//		shutdown(sockClient, 2);
		//		shutdown(sockSrv, 2);
	}

	free(pBuf); //�ͷ��ڴ�
}


void main()
{
	// 1. �����׽��ֿ�
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	int size = 0x22852;
	char *pBuf;

	pBuf = (char*)malloc(size); //����ͼ���ڴ�ռ�

	wVersionRequested = MAKEWORD(1, 1);		//���ֽڴ����汾, ���ֽڴ������汾
											//a�ǵ��ֽ�, b�Ǹ��ֽ�

	err = WSAStartup(wVersionRequested, &wsaData);

	if (err != 0)
	{
		//��0����ʧ��
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		//�汾�Ų�һ��, �رղ�����
		WSACleanup();
		return;
	}

	// 2. �������ڼ������׽���
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;						//�����ֽ���
	addrSrv.sin_port = htons(6000);						//�����ֽ���
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);	//�����ֽ���, ����IP

	// 3. ���׽���
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	// 4. ���׽�������Ϊ����ģʽ, ׼�����ܿͻ�����
	listen(sockSrv, 5);

	SOCKADDR_IN sockClient;
	int len = sizeof(SOCKADDR);

	while (1)
	{
		// 5. �ȴ��ͻ�������
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&sockClient, &len);

		char sendBuf[100];
		char ipBuf[20];
		inet_ntop(AF_INET, &sockClient.sin_addr, ipBuf, 16);
		sprintf_s(sendBuf, "%s: hello World", ipBuf);

		// 6. ��������
		//send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
		recv(sockConn, pBuf, size, 0);

		printf("%s\n", pBuf);

		// 7. ��������
		char recvBuf[100];
		//recv(sockConn, recvBuf, 100, 0);
		send(sockConn, "aaaaa", strlen("aaaaa") + 1, 0);

		//printf("%s\n", recvBuf);

		// 8. �ر��׽���
		closesocket(sockConn);
	}
}