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

# DEBT: Switch this over to a lib, someday
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME} unity estd)
