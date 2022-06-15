cmake_minimum_required(VERSION 3.22)
project(Citer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Citer src/main.cpp src/window.cpp src/window.ui src/resource.qrc src/window.hpp src/Process.cpp src/Process.h src/Exception.cpp src/Exception.h)

target_link_libraries(Citer
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
