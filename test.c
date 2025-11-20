#include <stdio.h>
#include <string.h>
#include "server.h"

void launch(struct Server *server)
{
    char buffer[30000];
    int address_length = sizeof(server->address);
    printf("====== SERVER RUNNING (CTRL+C to stop) ======\n");

    while (1) {  // infinite loop for continuous requests
        printf("\n====== WAITING FOR CONNECTION ======\n");

        int new_socket = accept(server->socket,
                                (struct sockaddr *)&server->address,
                                (socklen_t *)&address_length);

        if (new_socket < 0) {
            perror("Accept failed");
            exit(1);
        }

#ifdef _WIN32
        recv(new_socket, buffer, sizeof(buffer), 0);
#else
        read(new_socket, buffer, sizeof(buffer));
#endif

        printf("%s\n", buffer);

        const char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"
            "\r\n"
            "<html><body><h1>Mono Deus — Server Alive 🔥</h1></body></html>";

#ifdef _WIN32
        send(new_socket, response, (int)strlen(response), 0);
        closesocket(new_socket);
#else
        write(new_socket, response, strlen(response));
        close(new_socket);
#endif
    }
}
