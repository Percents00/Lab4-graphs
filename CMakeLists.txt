cmake_minimum_required(VERSION 3.29)
project(Lab4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8")

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(Lab4
        src/Graph.cpp
        include/Graph.h
        include/GraphGenerator.h
        src/GraphGenerator.cpp
        include/GraphColoring.h
        src/GraphColoring.cpp
        src/Main.cpp
        graphics/GraphVisualizer.h
        graphics/GraphVisualizer.cpp
        include/Chronometer.h
        src/Chronometer.cpp
        graphics/MainWindow.cpp
        graphics/MainWindow.h
        tests/AllTests.cpp
        tests/TestRunner.cpp
        tests/TestRunner.h)

target_link_libraries(Lab4 PRIVATE Qt6::Core Qt6::Widgets)
target_compile_options(Lab4 PRIVATE -finput-charset=UTF-8 -fexec-charset=UTF-8)