cmake_minimum_required(VERSION 3.16)

project(ExinCounterApp LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable automatic Qt processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find Qt 6 Widgets module
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Add your source and header files
set(SOURCES
    main.cpp
    mainwindow.cpp
)

set(HEADERS
    mainwindow.h
    oled_simulator.h
)

# Add the executable
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
)

# Link to Qt6 Widgets
target_link_libraries(${PROJECT_NAME}
    Qt6::Widgets
)
