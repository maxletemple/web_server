cmake_minimum_required(VERSION 3.24)
project(web_server)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Qt5_DIR "~/Qt/5.15.2/gcc_64/lib/cmake/Qt5/")

if (EXISTS )
    file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/public_html)
endif ()
file(COPY public_html DESTINATION .)

find_package(Qt5 COMPONENTS
        Core
        Widgets
        Network
        REQUIRED)
add_executable(web_server main.cpp Dialog.cpp Dialog.h ClientSocket.cpp ClientSocket.h ServerSocket.cpp ServerSocket.h)
target_link_libraries(web_server
        Qt5::Core
        Qt5::Widgets
        Qt5::Network
        )

