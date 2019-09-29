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

	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	char recvBuf[100];
	char sendBuf[100];
	char tempBuf[200];
	char ipBuf[20];

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	//等消息
	while (1)
	{
		recvfrom(sockSrv, recvBuf, 100, 0, (SOCKADDR*)&addrClient, &len);
		if (recvBuf[0] == 'q')
		{
			//收到退出
			sendto(sockSrv, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrClient, len);	//也发送退出
			printf("Chat End!\n");
			break;
		}
		inet_ntop(AF_INET, &addrClient.sin_addr.S_un.S_addr, ipBuf, 16);
		sprintf_s(tempBuf, "%s say: %s", ipBuf, recvBuf);
		printf("%s\n", tempBuf);

		//发送
		printf("please input...\n");
		gets_s(sendBuf);
		sendto(sockSrv, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrClient, len);
	}

	//关闭
	closesocket(sockSrv);
	WSACleanup();
}