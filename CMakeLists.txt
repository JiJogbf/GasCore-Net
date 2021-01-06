cmake_minimum_required(VERSION 3.16)

set(CXX_STANDARD 17)

aux_source_directory(src/cpp/main/gas/net NetMainSrc)
aux_source_directory(src/cpp/main/gas/net/impl NetMainSrc)

add_library(Net ${NetMainSrc})

aux_source_directory(src/cpp/test NetTestsSrc)
add_executable(NetTest ${NetTestsSrc})
add_executable(Client src/cpp/demo/client/client.cpp)
add_executable(Server src/cpp/demo/server/server.cpp)
target_include_directories(Net PUBLIC src/cpp/main)
target_include_directories(NetTest PUBLIC src/cpp/test)
target_link_libraries(Net ws2_32)
target_link_libraries(Net Core)
target_link_libraries(NetTest Net Core)
target_link_libraries(Client Net Core)
target_link_libraries(Server Net Core)

