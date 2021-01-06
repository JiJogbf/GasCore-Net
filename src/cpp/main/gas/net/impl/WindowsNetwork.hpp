#pragma once 

#include "../Network.hpp"

#include <winsock2.h>

namespace gas{
namespace net{

class WindowsNetwork: public Network{
private:
    WSADATA mWsData;
public:
    WindowsNetwork();
    ~WindowsNetwork();
    void initialize() override;
    void finalize() override;
};

}
}
