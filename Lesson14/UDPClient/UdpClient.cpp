#include <WinSock2.h>
#include <stdio.h>
#include <WS2tcpip.h>

void main()
{
	// 1. 加载套接字库
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

	// 2. 创建套接字
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	inet_pton(AF_INET, "127.0.0.1", &addrSrv.sin_addr.S_un.S_addr);
	
	// 3. 发送数据
	sendto(sockClient, "hello world", strlen("hello world") + 1, 0, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	// 4. 关闭套接字
	closesocket(sockClient);
	WSACleanup();
}