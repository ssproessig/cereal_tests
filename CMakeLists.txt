cmake_minimum_required (VERSION 3.9)
set(P_NAME test_cereal)


project(${P_NAME})
set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 5.8 COMPONENTS Core REQUIRED)


add_executable(
    ${P_NAME}
    main.cpp
)
target_include_directories(
    ${P_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/ext/include>
    $<INSTALL_INTERFACE:ext/include>
)
target_link_libraries(
    ${P_NAME}
    Qt5::Core
)
