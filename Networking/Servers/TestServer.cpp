

#include "TestServer.hpp"

HDE::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)
{
    launch();
}

void HDE::TestServer::accepter()
{
    sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);

    read(new_socket, buffer, 30000);
}

void HDE::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void HDE::TestServer::responder()
{
    const char *hello = "Hello from server";
    write(new_socket, hello, strlen(hello));
    std::cout << "------------------Hello message sent-------------------" << std::endl;
    close(new_socket);
}

void HDE::TestServer::launch()
{
    while (1)
    {
        std::cout << "============waiting for server ===========" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "============ responded ===========" << std::endl;
    }
}
