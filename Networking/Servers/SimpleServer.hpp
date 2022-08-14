

#ifndef SimpleServer_hpp

#define SimpleServer_hpp

#include "../hdelib-networking.hpp"

namespace HDE
{
    class SimpleServer
    {
    private:
        ListeningSocket *socket;
        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;

    public:
        SimpleServer(int domain, int service, int protocol, int port, u_long interface, int backlog);
        ListeningSocket *get_socket();
    };
}

#endif
