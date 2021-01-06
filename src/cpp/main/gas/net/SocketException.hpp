#pragma once 

#include <string>
#include <exception>

namespace gas{
namespace net{

// @todo: move to public folder
class SockException: public std::exception {
private:
    std::string message;
public:
    SockException(const char* message);
    const char* what() const noexcept override;
};

}
}
