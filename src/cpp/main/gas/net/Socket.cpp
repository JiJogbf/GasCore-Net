#include "Socket.hpp"

#include "impl\WindowsSocketImpl.hpp"

namespace gas{
namespace net{

Socket::Socket(): Socket(new impl::WindowsSocketImpl()){}

Socket::Socket(impl::SocketImpl* newImpl): mImpl(newImpl){}

Socket::~Socket(){
    delete mImpl;
}

void Socket::create(){
    mImpl->create();
}

void Socket::close(){
    mImpl->close();
}

void Socket::connect(SocketAddress& sockAddr){
    mImpl->connect(sockAddr);
}

void Socket::send(ByteArray& array){
    mImpl->send(array);
}

void Socket::recive(ByteArray& array){
    mImpl->recive(array);
}

}
}