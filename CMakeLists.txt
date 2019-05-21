cmake_minimum_required(VERSION 3.13)
project(mucom88)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
        mucom88/src/*.c
        mucom88/src/*.cpp
        mucom88/src/dummy/*.cpp
        mucom88/src/fmgen/*.cpp
        mucom88/src/module/*.cpp
        mucom88/src/plugin/*.cpp
        mucom88/src/Z80/*.cpp
        src/*.cpp)

file (GLOB HTML_SOURCES html/*.*)

list(FILTER SOURCES EXCLUDE REGEX "/mucom88/src/mucomerror.cpp")

if (EMSCRIPTEN)
    list(FILTER SOURCES EXCLUDE REGEX "/mucom88/src/main.cpp")

    if (WEB_BROWSER)
        set(CMAKE_CXX_FLAGS "--bind -s WASM=0")
    else()
        set(CMAKE_CXX_FLAGS "--bind -s NODERAWFS=1 -s WASM=0")
    endif()

    set(CMAKE_CXX_FLAGS_DEBUG "-g4")
    set(CMAKE_CXX_FLAGS_RELEASE  "-Oz --llvm-lto 1")
endif()

file(COPY ${HTML_SOURCES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE openal)

if (EMSCRIPTEN)
    add_custom_command(
        TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND python ARGS "${PROJECT_SOURCE_DIR}/mucom88/clion/PostBuild.py" "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.js")
endif()

target_include_directories(${CMAKE_PROJECT_NAME}
        PRIVATE ${SDL_INCLUDE_DIR}
        PRIVATE mucom88/src
        PRIVATE mucom88/src/module
        PRIVATE src)
