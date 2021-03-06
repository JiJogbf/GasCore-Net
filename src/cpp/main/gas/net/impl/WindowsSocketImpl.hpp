#pragma once

#include <winsock2.h>

#include "SocketImpl.hpp"

namespace gas{
namespace net{
namespace impl{

class WindowsSocketImpl: public SocketImpl{
private:
    SOCKET mHandle;
    int port;
public:
    WindowsSocketImpl();
    WindowsSocketImpl(SOCKET handle);
    ~WindowsSocketImpl();
    void close() override;
    void create() override;
    void connect(SocketAddress& sockAddr) override;
    void send(ByteArray& array) override;
    void recive(ByteArray& array) override;
};

}
}
}
