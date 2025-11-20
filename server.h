#ifndef SERVER_H
#define SERVER_H

//  PLATFORM DETECTION 
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
    typedef int socklen_t;
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
#endif

struct Server {
    int domain;
    int service;
    int protocol;
    u_long iface;
    int port;
    int backlog;

#ifdef _WIN32
    SOCKET socket;
#else
    int socket;
#endif

    struct sockaddr_in address;
    void (*launch)(struct Server *server);
};

struct Server server_constructor(
    int domain,
    int service,
    int protocol,
    u_long iface,
    int port,
    int backlog,
    void (*launch)(struct Server *server)
);

#endif /* SERVER_H */
