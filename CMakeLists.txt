cmake_minimum_required(VERSION 2.6.4)
#add_definitions("-std=c++11")

project(naoValues)
find_package(qibuild)

include_directories(".")

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
#target_link_libraries(naoValues ${CMAKE_THREAD_LIBS_INIT})
qi_create_bin(naoValues main.cpp src/NAOValues.cpp src/Timer.cpp src/NAOV.cpp)
qi_use_lib(naoValues ALCOMMON ALPROXIES)



