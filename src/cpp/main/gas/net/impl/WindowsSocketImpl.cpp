#include "WindowsSocketImpl.hpp"

#include <string>
#include <windows.h>

namespace gas{
namespace net{
namespace impl{

// @todo: move to public folder
class WinSockException: public std::exception {
private:
    std::string message;
public:
    WinSockException(const char* message):
        message(message)
    {}

    const char* what() const noexcept override{
        return message.c_str();
    }
};

WindowsSocketImpl::WindowsSocketImpl(){
    mHandle = INVALID_SOCKET;
}

WindowsSocketImpl::~WindowsSocketImpl(){
    mHandle = INVALID_SOCKET;
}

void WindowsSocketImpl::create(){
    mHandle = socket(AF_INET, SOCK_STREAM, 0);
    if(INVALID_SOCKET == mHandle){
        throw WinSockException("socket in invalid state!");
    }
}

void WindowsSocketImpl::close(){
    shutdown(mHandle, SD_BOTH);
    closesocket(mHandle);
}

void WindowsSocketImpl::connect(SocketAddress& sockAddr){
    sockaddr_in addr; // переменная для TCP сокета
    // Заполним ее:
    ::ZeroMemory(&addr, sizeof(addr));
    // тип адреса (TCP/IP)
    addr.sin_family = AF_INET;
    //адрес сервера. Т.к. TCP/IP представляет адреса в числовом виде, то для перевода
    // адреса используем функцию inet_addr.
    addr.sin_addr.S_un.S_addr = inet_addr (sockAddr.ip.c_str());
    // Порт. Используем функцию htons для перевода номера порта из обычного в //TCP/IP представление.
    addr.sin_port = htons (1234);

    // Дальше выполняем соединение:
    if (SOCKET_ERROR == (::connect(mHandle, (sockaddr *) &addr, sizeof(addr)))){
        throw WinSockException("Cant perform connect on socket!");
    }
}

void WindowsSocketImpl::send(ByteArray& array){
    ::send(mHandle,(const char*)array.data(), array.size(), 0);
}

void WindowsSocketImpl::recive(ByteArray& array){
    // @todo: clean array before recive something
    ::recv(mHandle, (char*)array.data(), array.capacity(), 0);
}


}
}
}
