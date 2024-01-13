cmake_minimum_required(VERSION 3.20.0)
project(drone-common VERSION 1.0)

add_library(drone-common INTERFACE)
target_include_directories(drone-common INTERFACE ./include)