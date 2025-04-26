cmake_minimum_required(VERSION 3.25)
project(BigIntProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------
# włącz CTest
enable_testing()

# katalog główny z nagłówkami
include_directories(${PROJECT_SOURCE_DIR})

# --------------------------------------------------
# Automatyczne pobranie Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)   # przyjazne dla MSVC
FetchContent_MakeAvailable(googletest)

# --------------------------------------------------
# biblioteka z implementacją BigInt
add_library(bigint_lib bigint.cpp)
target_include_directories(bigint_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# (opcjonalnie) krótka aplikacja demonstracyjna
add_executable(bigint_demo main.cpp)
target_link_libraries(bigint_demo PRIVATE bigint_lib)

# --------------------------------------------------
# testy Google Test
add_executable(test_bigint tests/test_bigint.cpp)
target_link_libraries(test_bigint PRIVATE bigint_lib gtest gtest_main)

# rejestracja w CTest
include(GoogleTest)
gtest_discover_tests(test_bigint)

# --------------------------------------------------
# instalacja aplikacji (opcjonalnie)
install(TARGETS bigint_demo
        RUNTIME DESTINATION .)
