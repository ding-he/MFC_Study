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

	pBuf = (char*)malloc(size); //分配图像内存空间

	for (i = 0; i < 2000; i++) {
		if (flag == 0) {
			flag = 1;

			sockSrv = socket(AF_INET, SOCK_STREAM, 0); //创建套接字
			addrSrv.sin_family = AF_INET;
			addrSrv.sin_port = htons(6000);
			addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

			bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)); //绑定套接字

			listen(sockSrv, 5); //监听模式, 等待客户端请求

			len = sizeof(SOCKADDR);

			sockClient = accept(sockSrv, (SOCKADDR*)&addrClient, &len); //等待用户请求
		}

		contentLength = size;
		while (contentLength > 0) { //收不够再收 => 分多次接收
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

		/* 什么也不干, 等待处理, 原数据返回 */
		// 处理数据

		contentLength = size;
		while (contentLength > 0) { //发不够再发 => 分多次发送
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

	free(pBuf); //释放内存
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

	pBuf = (char*)malloc(size); //分配图像内存空间

	wVersionRequested = MAKEWORD(1, 1);		//高字节代表副版本, 低字节代表主版本
	//a是低字节, b是高字节

	err = WSAStartup(wVersionRequested, &wsaData);

	if (err != 0)
	{
		//非0加载失败
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		//版本号不一致, 关闭并返回
		WSACleanup();
		return;
	}

	while (1) {
		//printf("123456");

		if (flag == 0) {
			flag = 1;

			sockSrv = socket(AF_INET, SOCK_STREAM, 0); //创建套接字
			addrSrv.sin_family = AF_INET;
			addrSrv.sin_port = htons(6000);
			addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

			bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)); //绑定套接字

			listen(sockSrv, 5); //监听模式, 等待客户端请求

			len = sizeof(SOCKADDR);

			sockClient = accept(sockSrv, (SOCKADDR*)&addrClient, &len); //等待用户请求
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

		/* 什么也不干, 等待处理, 原数据返回 */


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

	free(pBuf); //释放内存
}


void main()
{
	// 1. 加载套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	int size = 0x22852;
	char *pBuf;

	pBuf = (char*)malloc(size); //分配图像内存空间

	wVersionRequested = MAKEWORD(1, 1);		//高字节代表副版本, 低字节代表主版本
											//a是低字节, b是高字节

	err = WSAStartup(wVersionRequested, &wsaData);

	if (err != 0)
	{
		//非0加载失败
		return;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		//版本号不一致, 关闭并返回
		WSACleanup();
		return;
	}

	// 2. 创建用于监听的套接字
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;						//主机字节序
	addrSrv.sin_port = htons(6000);						//网络字节序
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);	//网络字节序, 任意IP

	// 3. 绑定套接字
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	// 4. 将套接字设置为监听模式, 准备接受客户请求
	listen(sockSrv, 5);

	SOCKADDR_IN sockClient;
	int len = sizeof(SOCKADDR);

	while (1)
	{
		// 5. 等待客户请求到来
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&sockClient, &len);

		char sendBuf[100];
		char ipBuf[20];
		inet_ntop(AF_INET, &sockClient.sin_addr, ipBuf, 16);
		sprintf_s(sendBuf, "%s: hello World", ipBuf);

		// 6. 发送数据
		//send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
		recv(sockConn, pBuf, size, 0);

		printf("%s\n", pBuf);

		// 7. 接收数据
		char recvBuf[100];
		//recv(sockConn, recvBuf, 100, 0);
		send(sockConn, "aaaaa", strlen("aaaaa") + 1, 0);

		//printf("%s\n", recvBuf);

		// 8. 关闭套接字
		closesocket(sockConn);
	}
}