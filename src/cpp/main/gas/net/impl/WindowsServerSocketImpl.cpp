#include "WindowsServerSocketImpl.hpp"

#include "..\SocketException.hpp"

#include "WindowsSocketImpl.hpp"
#include "..\Socket.hpp"

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
    local_addr.sin_family=AF_INET;
    local_addr.sin_port=htons(port);
             // не забываем о сетевом порядке!!!
    local_addr.sin_addr.s_addr=0;
             // сервер принимает подключения
             // на все IP-адреса

    // вызываем bind для связывания
    if (::bind(mHandle, (sockaddr *)&local_addr,
                sizeof(local_addr)))
    {
        close();
        throw SockException("Cant bind this port to socket!");
    }
}

void WindowsServerSocketImpl::listen(){
    // Шаг 4 ожидание подключений
    // размер очереди – 0x100
    if (::listen(mHandle, 0x100)){
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

    // цикл извлечения запросов на подключение из
    // // очереди
    // while((client_socket=accept(mysocket, (sockaddr *)
    //         &client_addr, &client_addr_size)))
    // {
    //   nclients++;      // увеличиваем счетчик
    //           // подключившихся клиентов

    //   // пытаемся получить имя хоста
    //   HOSTENT *hst;
    //   hst=gethostbyaddr((char *)
    //       &client_addr.sin_addr.s_addr,4, AF_INET);

    //   // вывод сведений о клиенте
    //   printf("+%s [%s] new connect!\n",
    //   (hst)?hst->h_name:"",
    //   inet_ntoa(client_addr.sin_addr));
    //   PRINTNUSERS

    //   // Вызов нового потока для обслужвания клиента
    //   // Да, для этого рекомендуется использовать
    //   // _beginthreadex но, поскольку никаких вызов
    //   // функций стандартной Си библиотеки поток не
    //   // делает, можно обойтись и CreateThread
    //   DWORD thID;
    //   CreateThread(NULL,NULL,SexToClient,
    //           &client_socket,NULL,&thID);
    // }
    return 0;
}


}
}
}