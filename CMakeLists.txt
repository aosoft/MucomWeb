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
        mucom88/src/Z80/*.cpp)

list(FILTER SOURCES EXCLUDE REGEX "/mucom88/src/mucomerror.cpp")

if (EMSCRIPTEN)
    list(FILTER SOURCES EXCLUDE REGEX "/mucom88/src/main.cpp")

    if (WEB_BROWSER)
        set(CMAKE_CXX_FLAGS "--pre-js ${PROJECT_SOURCE_DIR}/mucom88/clion/EmPre.js --post-js ${PROJECT_SOURCE_DIR}/mucom88/clion/EmPost.js -s WASM=0")
    else()
        set(CMAKE_CXX_FLAGS "-s NODERAWFS=1 -s WASM=0")
    endif()

    set(CMAKE_CXX_FLAGS_DEBUG "-g4")
endif()

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME}
        PRIVATE ${SDL_INCLUDE_DIR}
        PRIVATE mucom88/src
        PRIVATE mucom88/src/module)
