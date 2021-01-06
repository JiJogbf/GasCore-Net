#pragma once

#include <gas\types.hpp>
#include <gas\Object.hpp>

#include "Socket.hpp"

#include "SocketAddress.hpp"

namespace gas{
namespace net{

namespace impl{
    class ServerSocketImpl;
};

// @todo: adding getter for ip-addres and port

class ServerSocket: public Object{
private:
    impl::ServerSocketImpl* mImpl;
public:
    ServerSocket();
    ~ServerSocket();
    void bind(int port);
    void listen();
    Socket* accept();
    void open();
    void close();
};

}
}
