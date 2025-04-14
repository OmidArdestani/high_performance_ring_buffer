cmake_minimum_required(VERSION 3.16)

project(HighPerformanceRingBuffer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HighPerformanceRingBuffer
  main.cpp
  HPRingBuffer.hpp
)

include(GNUInstallDirs)
install(TARGETS HighPerformanceRingBuffer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
