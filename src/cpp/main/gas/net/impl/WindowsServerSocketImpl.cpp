#include "WindowsServerSocketImpl.hpp"

#include "..\SocketException.hpp"

#include "WindowsSocketImpl.hpp"
#include "..\Socket.hpp"

#include <string>

namespace gas{
namespace net{
namespace impl{

WindowsServerSocketImpl::WindowsServerSocketImpl(): mHandle(INVALID_SOCKET),
    mPort(0), mIpAddress("") {}

WindowsServerSocketImpl::~WindowsServerSocketImpl(){
    mHandle = INVALID_SOCKET;
    mPort = 0;
}

void WindowsServerSocketImpl::open(){
    mHandle = socket(AF_INET, SOCK_STREAM, 0);
    if(INVALID_SOCKET == mHandle){
        throw SockException("socket in invalid state!");
    }
}

void WindowsServerSocketImpl::close(){
    closesocket(mHandle);
}

void WindowsServerSocketImpl::bind(int port){
    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(7000);
             // не забываем о сетевом порядке!!!
    local_addr.sin_addr.s_addr = htonl (INADDR_ANY);
             // сервер принимает подключения
             // на все IP-адреса

    // вызываем bind для связывания
    if (::bind(mHandle, (sockaddr *)&local_addr,
                sizeof(local_addr)) == SOCKET_ERROR)
    {
        int code = WSAGetLastError();
        std::string message = "Cant bind this port to socket! Error Code = " + std::to_string(code);
        close();
        throw SockException(message.c_str());
    }
}

void WindowsServerSocketImpl::listen(){
    // Шаг 4 ожидание подключений
    // размер очереди – 0x100
    if (::listen(mHandle, 0x100) == SOCKET_ERROR){
        close();
        throw SockException("Cant listen this port to socket!");
    }
}

Socket* WindowsServerSocketImpl::accept(){
    // Шаг 5 извлекаем сообщение из очереди
    SOCKET client_socket;    // сокет для клиента
    sockaddr_in client_addr;    // адрес клиента
              // (заполняется системой)
    // функции accept необходимо передать размер
    // структуры
    int client_addr_size=sizeof(client_addr);

    client_socket = ::accept(mHandle, (sockaddr *)
            &client_addr, &client_addr_size);

    return new Socket(new impl::WindowsSocketImpl(client_socket));
}


}
}
}