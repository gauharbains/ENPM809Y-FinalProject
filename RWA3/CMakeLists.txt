cmake_minimum_required(VERSION 3.15)
project(RWA3)

set(CMAKE_CXX_STANDARD 14)

add_executable(RWA3 main.cpp LandBasedRobot/landbasedrobot.cpp LandBasedRobot/landbasedrobot.h LandBasedWheeled/landbasedwheeled.cpp LandBasedWheeled/landbasedwheeled.h LandBasedTracked/landbasedtracked.cpp LandBasedTracked/landbasedtracked.h)