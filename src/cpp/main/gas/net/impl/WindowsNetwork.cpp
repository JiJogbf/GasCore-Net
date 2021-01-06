#include "WindowsNetwork.hpp"

namespace gas{
namespace net{

WindowsNetwork::WindowsNetwork(){}

WindowsNetwork::~WindowsNetwork(){}

void WindowsNetwork::initialize(){
    int error = WSAStartup(0x0202, &mWsData);   
    if(error){
        
    }
}

void WindowsNetwork::finalize(){
    WSACleanup();
}


}
}
