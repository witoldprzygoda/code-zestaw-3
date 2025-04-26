cmake_minimum_required(VERSION 3.25)
project(MnozenieMacierzy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Włącz CTest
enable_testing()

# katalog główny z nagłówkami
include_directories(${PROJECT_SOURCE_DIR})

# Automatyczne pobranie Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# biblioteka z implementacją macierzy
add_library(macierze_lib macierze.cpp)
target_include_directories(macierze_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# aplikacja główna
add_executable(mnozenie_macierzy main.cpp)
target_link_libraries(mnozenie_macierzy PRIVATE macierze_lib)

# testy Google Test
add_executable(test_mnozenie tests/test_mnozenie.cpp)
target_link_libraries(test_mnozenie PRIVATE macierze_lib gtest gtest_main)

# rejestracja testów w CTest
include(GoogleTest)
gtest_discover_tests(test_mnozenie)

# opcjonalna instalacja
install(TARGETS mnozenie_macierzy
        RUNTIME DESTINATION .)
