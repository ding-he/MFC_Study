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
	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	// 3. 绑定套接字
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	// 4. 等待并接收数据
	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	char recvBuf[100];
	recvfrom(sockSrv, recvBuf, 100, 0, (SOCKADDR*)&addrClient, &len);
	printf("%s\n", recvBuf);

	char ip[20];
	USHORT port;
	//ip = inet_ntoa(addrClient.sin_addr);
	inet_ntop(AF_INET, &addrClient.sin_addr, ip, 20);
	port = ntohs(addrClient.sin_port);
	
	printf("from IP : %d: %s\n", port, ip);

	// 5. 关闭套接字
	closesocket(sockSrv);
	WSACleanup();
}