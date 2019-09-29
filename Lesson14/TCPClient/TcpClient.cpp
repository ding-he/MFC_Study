#include <WinSock2.h>
#include <stdio.h>
#include <Ws2tcpip.h>

#define RXTX_BUFFER_SIZE		1024

int main()
{
	// 1. 加载套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	int contentLength;
	int retlen;
	int buffersize;
	char filename[100];
	int i;
	char *pBuf, *pBuf1;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return 0;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return 0;
	}

	// 2. 创建套接字
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	inet_pton(AF_INET, "127.0.0.1", &addrSrv.sin_addr.S_un.S_addr);

	// 3. 向服务器发出连接请求
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));



	for (i = 0; i < 2000; i++)
	{
		sprintf_s(filename, "E:\\文档\\数字图像处理\\20180524-082210_弱小目标（公开）\\处理前2\\%d.bmp", i + 1);
		FILE *fp;
		fopen_s(&fp, filename, "rb");
		if (!fp)
			return 0;

		fseek(fp, 0, SEEK_END);
		int len = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		pBuf = new char[len];
		pBuf1 = new char[len];
		fread(pBuf, sizeof(char), len, fp);
		fclose(fp);

		contentLength = len;
		while (contentLength > 0) {
			if (contentLength > RXTX_BUFFER_SIZE)
				buffersize = RXTX_BUFFER_SIZE;
			else
				buffersize = contentLength;
			retlen = send(sockClient, pBuf + len - contentLength, buffersize, 0);
			if (retlen > 0 && retlen == buffersize) {
				contentLength -= retlen;
			}
		}

		// 4. 接收数据
		contentLength = len;
		while (contentLength > 0) {
			if (contentLength > RXTX_BUFFER_SIZE)
				buffersize = RXTX_BUFFER_SIZE;
			else
				buffersize = contentLength;
			retlen = recv(sockClient, pBuf1 + len - contentLength, buffersize, 0);
			if (retlen > 0 && retlen == buffersize) {
				contentLength -= retlen;
			}
		}

		sprintf_s(filename, "E:\\文档\\数字图像处理\\20180524-082210_弱小目标（公开）\\处理后2\\%d.bmp", i + 1);
		FILE *pFile;
		fopen_s(&pFile, filename, "wb");
		if (!pFile)
			return 0;
		fwrite(pBuf1, sizeof(char), len, pFile);
		fclose(pFile);


		printf("**********\ttimes: %d\t**********\n", i + 1);
	}

	// 6. 关闭套接字
	closesocket(sockClient);
	WSACleanup();
	delete[]pBuf;
	delete[]pBuf1;

	return 0;
}


int main2()
{
	// 1. 加载套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	int num = 123;
	char buf[20];
	char fmt[50];
	int times = 0;
	int contentLength;
	int retlen;
	int buffersize;

	wVersionRequested = MAKEWORD(1, 1);
	
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return 0;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return 0;
	}

	// 2. 创建套接字
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	inet_pton(AF_INET, "192.168.2.100", &addrSrv.sin_addr.S_un.S_addr);
	//addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	// 3. 向服务器发出连接请求
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	FILE *fp;
	fopen_s(&fp, "C:\\Users\\30802\\Desktop\\lena.bmp", "rb");
	if (!fp)
		return 0;

	remove("");
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *pBuf = new char[len];
	char *pBuf1 = new char[len];
	fread(pBuf, sizeof(char), len, fp);
	fclose(fp);


	while (1)
	{
		memset(fmt, 0, 50);

		sprintf_s(buf, "%d", num);
		strcat_s(fmt, buf);

		//strcpy_s(buf, "123456789");
		//send(sockClient, buf, strlen(buf) + 1, 0);
		//retlen = send(sockClient, pBuf, len + 1, 0);
		contentLength = len;
		while (contentLength > 0) {
			if (contentLength > RXTX_BUFFER_SIZE)
				buffersize = RXTX_BUFFER_SIZE;
			else
				buffersize = contentLength;
			retlen = send(sockClient, pBuf + len - contentLength, buffersize, 0);
			if (retlen > 0 && retlen == buffersize) {
				contentLength -= retlen;
			}
		}

		strcat_s(fmt, " -> ");

		// 4. 接收数据
		//char recvBuf[100];
		//recv(sockClient, buf, 20, 0);
		//retlen = recv(sockClient, pBuf1, len, 0);
		contentLength = len;
		while (contentLength > 0) {
			if (contentLength > RXTX_BUFFER_SIZE)
				buffersize = RXTX_BUFFER_SIZE;
			else
				buffersize = contentLength;
			retlen = recv(sockClient, pBuf1 + len - contentLength, buffersize, 0);
			if (retlen > 0 && retlen == buffersize) {
				contentLength -= retlen;
			}
		}
		//printf(pBuf1);
		
		//strcat_s(fmt, buf);

		sprintf_s(fmt, "C:\\Users\\30802\\Desktop\\%d.bmp", ++times);
		FILE *pFile;
		fopen_s(&pFile, fmt, "wb");
		if (!pFile)
			return 0;
		fwrite(pBuf1, sizeof(char), len, pFile);
		fclose(pFile);


		//printf("%s\ttimes: %d\n", fmt, ++times);
		printf("**********\ttimes: %d\t**********\n", times);

		char ch = (char)getchar();
		if (ch == 'q')
			break;
	}

	// 5. 发送数据
	//send(sockClient, "This is lisi", strlen("This is lisi") + 1, 0);

	// 6. 关闭套接字
	closesocket(sockClient);
	WSACleanup();
	delete[]pBuf;
	delete[]pBuf1;
	

	/*// 1. 加载套接字库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return 0;
	}

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return 0;
	}

	// 2. 创建套接字
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	inet_pton(AF_INET, "127.0.0.1", &addrSrv.sin_addr.S_un.S_addr);
	//addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	// 3. 向服务器发出连接请求
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	// 4. 接收数据
	char recvBuf[5];
	recv(sockClient, recvBuf, 5, 0);
	printf("%s\n", recvBuf);

	for (int i = 1; i <= 2000; i++)
	{
		char name[256];
		sprintf_s(name, "C:\\Users\\30802\\Desktop\\1\\%d.bmp", i);
		FILE *fp;
		fopen_s(&fp, name, "wb");
		if (!fp)
			return 0;
		char *buf = new char[66614];
		recv(sockClient, buf, 66614, 0);
		fwrite(buf, 66614, 1, fp);
		fclose(fp);
		delete[]buf;
	}

	// 5. 发送数据
	//send(sockClient, "This is lisi", strlen("This is lisi") + 1, 0);

	// 6. 关闭套接字
	closesocket(sockClient);
	WSACleanup();*/

	return 0;
}
