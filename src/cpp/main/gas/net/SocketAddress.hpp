#pragma once

#include <string>

namespace gas{
namespace net{

struct SocketAddress{
    std::string ip;
    SocketAddress(const std::string& ip = "127.0.0.1");
};

}
}