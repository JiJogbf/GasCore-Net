#pragma once

#include <gas\Object.hpp>

#include "..\Socket.hpp"
#include "..\SocketAddress.hpp"

#include <vector>

namespace gas{
namespace net{
namespace impl{

struct ServerSocketImpl: public Object{
    virtual ~ServerSocketImpl() = 0;
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void bind(int port) = 0;
    virtual void listen() = 0;
    virtual Socket* accept() = 0;
};

}
}
}
