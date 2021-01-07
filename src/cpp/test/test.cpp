#include <gas/test/Logger.hpp>
#include <gas/test/FileLogger.hpp>
#include <gas/test/Tester.hpp>

int main(){
    gas::test::Logger* logger = new gas::test::FileLogger("result.log");
    gas::test::Tester* tester;
    tester->run();
    delete tester;
    return 0;
}