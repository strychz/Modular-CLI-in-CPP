cmake_minimum_required(VERSION 3.15)
project(todo-cli VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include(FetchContent)

# CLI11
FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
)
FetchContent_MakeAvailable(CLI11)

# nlohmann/json
FetchContent_Declare(
    JSON
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(JSON)

# Catch2
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.6.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(todo-cli src/main.cpp)
target_include_directories(todo-cli PRIVATE include)
target_link_libraries(todo-cli PRIVATE CLI11::CLI11 nlohmann_json::nlohmann_json)

enable_testing()
add_executable(tests tests/test_main.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
add_test(NAME all_tests COMMAND tests)
