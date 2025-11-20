#include "server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(
    int domain, int service, int protocol,
    u_long iface, int port, int backlog,
    void (*launch)(struct Server *server))
{
    struct Server server;

#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed");
        exit(1);
    }
#endif

    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.iface = iface;
    server.port = port;
    server.backlog = backlog;

    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(iface);

    // Create socket
    server.socket = socket(domain, service, protocol);
#ifdef _WIN32
    if (server.socket == INVALID_SOCKET)
#else
    if (server.socket < 0)
#endif
    {
        perror("Failed to create socket");
        exit(1);
    }

    // Bind socket
    if (bind(server.socket, (struct sockaddr *)&server.address,
             sizeof(server.address)) < 0) {
        perror("Failed to bind");
#ifdef _WIN32
        closesocket(server.socket);
        WSACleanup();
#else
        close(server.socket);
#endif
        exit(1);
    }

    // Start listening for connections
    if (listen(server.socket, backlog) < 0) {
        perror("Listen failed");
        exit(1);
    }

    server.launch = launch;
    return server;
}
