#pragma once

#include <gas\types.hpp>
#include <gas\Object.hpp>

#include "SocketAddress.hpp"

namespace gas{
namespace net{

namespace impl{
    class SocketImpl;
}

class Socket: public Object{
    impl::SocketImpl* mImpl;
public:
    Socket();
    ~Socket();
    virtual void create();
    virtual void close();
    virtual void connect(SocketAddress& sockAddr);
    virtual void send(ByteArray& array);
    virtual void recive(ByteArray& array);
};

}
}
