add_executable(Pid-app main.cpp PidController.cpp virtualPID.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)