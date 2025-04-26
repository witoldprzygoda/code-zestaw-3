cmake_minimum_required(VERSION 3.25)
project(RSA LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include_directories(${PROJECT_SOURCE_DIR})

# Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Biblioteka RSA
add_library(rsa_lib rsa.cpp)
target_include_directories(rsa_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Program demonstracyjny
add_executable(rsa_demo main.cpp)
target_link_libraries(rsa_demo PRIVATE rsa_lib)

# Testy jednostkowe
add_executable(test_rsa tests/test_rsa.cpp)
target_link_libraries(test_rsa PRIVATE rsa_lib gtest gtest_main)

# rejestracja testów
include(GoogleTest)
gtest_discover_tests(test_rsa)

# instalacja
install(TARGETS rsa_demo RUNTIME DESTINATION .)
