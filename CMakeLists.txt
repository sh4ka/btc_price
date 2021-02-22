cmake_minimum_required(VERSION 3.17)
project(btc_price)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(btc_price
        src/btc_price.cpp
        src/json.hpp)

find_library(curlpp curlpp /usr/include/curlpp)
target_link_libraries(btc_price LINK_PUBLIC curlpp)
find_library(curl curl /usr/include/curl)
target_link_libraries(btc_price LINK_PUBLIC curl)
