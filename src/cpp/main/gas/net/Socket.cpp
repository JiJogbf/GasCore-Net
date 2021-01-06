#include "Socket.hpp"


#include "impl\SocketImpl.hpp"

namespace gas{
namespace net{

Socket::Socket(): mImpl(new impl::EmptySockImpl()){

}

Socket::~Socket(){
    delete mImpl;
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