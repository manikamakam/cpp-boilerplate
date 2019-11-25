set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    mockvirtualPID.h
    gmockStatic.h
    PidControllerTest.cpp
    ../app/PID-controller.cpp
    ../app/virtualPID.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest PUBLIC gmock)

