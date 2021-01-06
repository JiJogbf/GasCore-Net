#include <iostream>
#include <exception>

#include <gas\net\ServerSocket.hpp>
#include <gas\net\Socket.hpp>
#include <gas\net\impl\WindowsNetwork.hpp>

int main(){
    gas::net::WindowsNetwork network;
    try{
        network.initialize();
        gas::net::ServerSocket* serverSocket = new gas::net::ServerSocket();
        serverSocket->open();
        
        serverSocket->bind(7000);
        serverSocket->listen();
        gas::net::Socket* socket = serverSocket->accept();
        

        serverSocket->close();
        delete socket;
        delete serverSocket;    
        network.finalize();
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
        network.finalize();
    }
    return 0;
}