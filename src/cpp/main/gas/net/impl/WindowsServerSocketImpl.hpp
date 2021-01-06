#pragma once

#include <winsock2.h>
#include <string>

#include "ServerSocketImpl.hpp"

namespace gas{
namespace net{
namespace impl{
    
class WindowsServerSocketImpl: public ServerSocketImpl{
private:
    SOCKET mHandle;
    int mPort;
    std::string  mIpAddress;
public:
    WindowsServerSocketImpl();
    ~WindowsServerSocketImpl() override;
    void open() override;
    void close()  override;
    void bind(int port) override;;
    void listen() override;;
    Socket* accept() override;
};

}
}
}