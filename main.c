#include "server.h"

// bring in the launch function from test.c
void launch(struct Server *server);

int main() {
    struct Server server = server_constructor(
        AF_INET, SOCK_STREAM, 0,
        INADDR_ANY, 8080, 10,
        launch
    );

    server.launch(&server);
    return 0;
}
