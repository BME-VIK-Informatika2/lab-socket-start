#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>

int main(int argc, char* argv[])
{
	// Ellenőrzés
	if (argc < 5)
	{
		printf("Hasznalat: %s IP port oldal fajl\n", argv[0]);
		return 1;
	}

	// Winsock inicializálás
	WSADATA	wsd;
	if (WSAStartup(0x0202, &wsd) != 0)
	{
		printf("WSAStartup: %d", WSAGetLastError());
		return 1;
	}

	// TODO

	WSACleanup();

	return 0;
}
