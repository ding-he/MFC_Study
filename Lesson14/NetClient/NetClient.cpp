#include <WinSock2.h>
#include <stdio.h>
#include <WS2tcpip.h>

void main()
{
	// 1. �����׽��ֿ�
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

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

	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	inet_pton(AF_INET, "127.0.0.1", &addrSrv.sin_addr.S_un.S_addr);

	int len = sizeof(SOCKADDR);

	char recvBuf[100];
	char sendBuf[100];
	char tempBuf[200];
	char ipBuf[20];

	while (1)
	{
		//����
		printf("please input...\n");
		gets_s(sendBuf);
		sendto(sockClient, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrSrv, len);

		//�ȴ�������
		recvfrom(sockClient, recvBuf, 100, 0, (SOCKADDR*)&addrSrv, &len);
		if (recvBuf[0] == 'q')
		{
			//�˳�
			sendto(sockClient, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrSrv, len);	//�෢���˳�
			break;
		}
		inet_ntop(AF_INET, &addrSrv.sin_addr.S_un.S_addr, ipBuf, 16);
		sprintf_s(tempBuf, "%s say: %s", ipBuf, recvBuf);
		printf("%s\n", tempBuf);
	}

	//�ر�
	closesocket(sockClient);
	WSACleanup();
}