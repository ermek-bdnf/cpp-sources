//simple_client666
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//-lws2_32
//-std=c++11
#include<winsock2.h>
//#pragma comment(lib, "Ws2_32.lib") //vs
#pragma warning(disable : 4996)

void chat(SOCKET s)
{
	char mes[200];
	WSAEventSelect(s, 0, FD_READ);
	do
	{
		if((GetKeyState(VK_F1) < 0) && (GetForegroundWindow() == GetConsoleWindow()))
		{
			printf("message: ");
			while(getch() != 0);
			scanf("\n%200[0-9a-zA-Z.,!?: ]", mes);
			send(s, mes, sizeof(mes), 0);
		}
		if(recv(s, mes, sizeof(mes), 0) > 0)
			printf("%s\n", mes);
		}
		while(GetKeyState(VK_ESCAPE) >= 0);
}

int main()
{
	WSADATA ws;
	WSAStartup(MAKEWORD(2,2), &ws);
	
	SOCKET s;
	s = socket(AF_INET, SOCK_STREAM, 0);
	
	SOCKADDR_IN sa;
		memset(&sa, 0, sizeof(sa));
		sa.sin_family = AF_INET;
		sa.sin_port = htons(666);
	
		char ip[100];
		printf("set ip address: ");
		scanf("\n%100[0-9.]", ip);
		
		sa.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		connect(s, (const struct sockaddr*)&sa, sizeof(sa)); //(const_sockaddr *)
		
		chat(s);
		
	closesocket(s);
	
	return 0;
}
