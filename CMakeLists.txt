cmake_minimum_required(VERSION 3.24)
project(vulkan_tutorial)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

find_package(Threads REQUIRED)

set(VK_TUTORIAL_INCLUDE_DIRS
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(VK_TUTORIAL_HEADERS
)

set(VK_TUTORIAL_SOURCES
        src/main.cpp
)

set(PROJECT_SOURCES
        ${VK_TUTORIAL_HEADERS}
        ${VK_TUTORIAL_SOURCES}
)

add_executable(vulkan_tutorial ${PROJECT_SOURCES})

target_include_directories(vulkan_tutorial PRIVATE ${VK_TUTORIAL_INCLUDE_DIRS})
target_link_libraries(vulkan_tutorial Vulkan::Vulkan glfw glm::glm Threads::Threads)
