#pragma once

#include <gas\Object.hpp>

namespace gas{
namespace net{

class Network: public Object{
public:
    virtual void initialize(){}
    virtual void finalize(){}
};

}
}
