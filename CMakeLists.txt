
cmake_minimum_required(VERSION 3.22)
enable_testing()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb")

project(
    "SimpleCompression"
    VERSION 1.0.0
    LANGUAGES C
)

add_subdirectory(src/libs)

file(GLOB SOURCES "src/*.c")
add_executable(

    main

    ${SOURCES}

)

target_compile_options(main PUBLIC src/libs)
