#pragma once

#include <string>

namespace gas{
namespace net{

struct SocketAddress{
    std::string ip;
    int port;
    SocketAddress(const std::string& ip = "127.0.0.1", int port = 0);
};

}
}