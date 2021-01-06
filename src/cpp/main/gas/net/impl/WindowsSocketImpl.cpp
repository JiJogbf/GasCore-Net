#include "WindowsSocketImpl.hpp"

#include "..\SocketException.hpp"

#include <string>
#include <windows.h>

namespace gas{
namespace net{
namespace impl{

WindowsSocketImpl::WindowsSocketImpl(): WindowsSocketImpl(INVALID_SOCKET){}

WindowsSocketImpl::WindowsSocketImpl(SOCKET handle): mHandle(handle){}

WindowsSocketImpl::~WindowsSocketImpl(){
    mHandle = INVALID_SOCKET;
}

void WindowsSocketImpl::create(){
    mHandle = socket(AF_INET, SOCK_STREAM, 0);
    if(INVALID_SOCKET == mHandle){
        throw SockException("socket in invalid state!");
    }
}

void WindowsSocketImpl::close(){
    shutdown(mHandle, SD_BOTH);
    closesocket(mHandle);
}

void WindowsSocketImpl::connect(SocketAddress& sockAddr){
    sockaddr_in addr; // переменная для TCP сокета
    port = sockAddr.port;
    // Заполним ее:
    ::ZeroMemory(&addr, sizeof(addr));
    // тип адреса (TCP/IP)
    addr.sin_family = AF_INET;
    //адрес сервера. Т.к. TCP/IP представляет адреса в числовом виде, то для перевода
    // адреса используем функцию inet_addr.
    addr.sin_addr.S_un.S_addr = inet_addr (sockAddr.ip.c_str());
    // Порт. Используем функцию htons для перевода номера порта из обычного в //TCP/IP представление.
    addr.sin_port = htons (port);

    // Дальше выполняем соединение:
    if (SOCKET_ERROR == (::connect(mHandle, (sockaddr *) &addr, sizeof(addr)))){
        throw SockException("Cant perform connect on socket!");
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
