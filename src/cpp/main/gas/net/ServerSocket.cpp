#include "ServerSocket.hpp"

#include "impl\WindowsServerSocketImpl.hpp"

namespace gas{
namespace net{

ServerSocket::ServerSocket(): mImpl(new impl::WindowsServerSocketImpl()){}

ServerSocket::~ServerSocket(){
    delete mImpl;
}

void ServerSocket::bind(int port){
    mImpl->bind(port);
}

void ServerSocket::listen(){
    mImpl->listen();
}

Socket* ServerSocket::accept(){
    return mImpl->accept();
}

void ServerSocket::open(){
    mImpl->open();
}

void ServerSocket::close(){
    mImpl->close();
}

}
}
