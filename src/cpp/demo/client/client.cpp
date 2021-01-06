#include <iostream>
#include <exception>

#include <gas\net\SocketAddress.hpp>
#include <gas\net\Socket.hpp>
#include <gas\net\impl\WindowsNetwork.hpp>

int main(){
    gas::net::WindowsNetwork network;
    try{
        
        network.initialize();
        gas::net::Socket* socket = new gas::net::Socket();
        socket->create();
        gas::net::SocketAddress s = gas::net::SocketAddress("127.0.0.1", 7000);
        socket->connect(s);
        socket->close();
        delete socket;
        network.finalize();
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
        network.finalize();
    }
    return 0;
}