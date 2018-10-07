cmake_minimum_required(VERSION 3.12)
project(smartPointerTest)

set(CMAKE_CXX_STANDARD 11)

add_executable(smartPointerTest main.cpp sharedPtr.h uniquePtr.h mySmartPtr.h weakPtr.h circleRef_orgPtr.h circleRef_ShPtr.h circleRef_solve.h)