cmake_minimum_required(VERSION 3.16)

set(CXX_STANDARD 17)

aux_source_directory(src/cpp/main/gas/net NetMainSrc)

add_library(Net ${NetMainSrc})

aux_source_directory(src/cpp/test NetTestsSrc)
add_executable(NetTest ${NetTestsSrc})
target_include_directories(Net PUBLIC src/cpp/main)
target_include_directories(NetTest PUBLIC src/cpp/test)
target_link_libraries(Net Core)
target_link_libraries(NetTest Net Core)
