add_executable(shell-app main.cpp PID-controller.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/app
)
