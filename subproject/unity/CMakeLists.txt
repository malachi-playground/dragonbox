cmake_minimum_required(VERSION 3.13)

project(unity-tests LANGUAGES C CXX)

include(FetchContent)

Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    unity
    GIT_REPOSITORY  https://github.com/ThrowTheSwitch/Unity
    GIT_TAG         v2.5.2
    GIT_PROGRESS    TRUE
    GIT_SHALLOW     TRUE
)

FetchContent_MakeAvailable(unity)

FetchContent_Declare(
    estd
    GIT_REPOSITORY  https://github.com/malachi-iot/estdlib
    GIT_TAG         v0.7.1
    GIT_PROGRESS    TRUE
    GIT_SHALLOW     TRUE
    # Due to https://github.com/malachi-iot/estdlib/issues/35 we have to
    # specify folder explicitly
    SOURCE_SUBDIR   src
)

FetchContent_MakeAvailable(estd)

include(sources.cmake)
# NOTE: I prefer target_include_directories, but in this case we must
# pull a prepend shenanigan so that to_chars cpp can pick it up
include_directories(BEFORE .)
# NOTE: Not working because dragonbox_to_chars is (reasonably) STATIC and not
# INTERFACE, but in this case it needs INTERFACE to work
#include_directories(BEFORE ../pio/basic/include)

add_subdirectory(../.. dragonbox)

# DEBT: Switch this over to a lib, someday
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

#target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} PUBLIC unity estd)
target_link_libraries(${PROJECT_NAME} PUBLIC dragonbox_to_chars)

#target_include_directories(${PROJECT_NAME} PUBLIC ../pio/basic/include)
