#pragma once

#include <gas\types.hpp>

#include "..\SocketAddress.hpp"

#include <vector>

namespace gas{
namespace net{
namespace impl{

struct SocketImpl{
    virtual ~SocketImpl() = 0;
    virtual void close() = 0;
    virtual void connect(SocketAddress& sockAddr) = 0;
    virtual void send(ByteArray& array) = 0;
    virtual void recive(ByteArray& array) = 0;
};

class EmptySockImpl: public SocketImpl{
public:
    EmptySockImpl(){}
    ~EmptySockImpl() override{}
    void close() override{}
    void connect(SocketAddress& sockAddr) override{}
    void send(ByteArray& array) override{}
    void recive(ByteArray& array) override{}
};

}
}
}
