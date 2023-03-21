cmake_minimum_required(VERSION 3.24)
project(web_server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Qt5_DIR "~/Qt/5.15.2/gcc_64/lib/cmake/Qt5/")

if (EXISTS ${CMAKE_BINARY_DIR}/public_html)
    file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/public_html)
endif ()
file(COPY public_html DESTINATION .)

find_package(Qt5 COMPONENTS
        Core
        Widgets
        Network
        REQUIRED)
add_executable(web_server src/main.cpp src/Dialog.cpp src/Dialog.h src/network/ClientSocket.cpp src/network/ClientSocket.h src/network/ServerSocket.cpp src/network/ServerSocket.h src/network/Response.cpp src/network/Response.h src/network/RespFile.cpp src/network/RespFile.h src/network/CacheManager.cpp src/network/CacheManager.h src/network/RequestManager.cpp src/network/RequestManager.h)
target_link_libraries(web_server
        Qt5::Core
        Qt5::Widgets
        Qt5::Network
        )

