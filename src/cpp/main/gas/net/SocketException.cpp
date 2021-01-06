#include "SocketException.hpp"

namespace gas{
namespace net{

SockException::SockException(const char* message):
    message(message)
{}

const char* SockException::what() const noexcept{
    return message.c_str();
}

}
}
