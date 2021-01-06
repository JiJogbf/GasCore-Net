#pragma once

#include <gas\types.hpp>
#include <gas\Object.hpp>

#include "SocketAddress.hpp"

namespace gas{
namespace net{

namespace impl{
    class SocketImpl;
}

// @todo: adding getter  for ip-addres and port

class Socket: public Object{
    impl::SocketImpl* mImpl;
public:
    Socket(impl::SocketImpl* newImpl);
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
