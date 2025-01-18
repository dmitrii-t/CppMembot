cmake_minimum_required(VERSION 3.11.3)
set(CMAKE_CXX_STANDARD 17)

# Set output directories to the build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})

if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    set(VCPKG_TARGET_TRIPLET x64-windows)
endif()

project(Membot)

# Find wxWidgets dependency
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Add source files
file(GLOB project_SRCS src/*.cpp)

# Create an executable
if(WIN32)
    add_executable(membot WIN32 ${project_SRCS})
else()
    add_executable(membot ${project_SRCS})
endif()

# Link libraries
target_link_libraries(membot ${wxWidgets_LIBRARIES})
target_include_directories(membot PRIVATE ${wxWidgets_INCLUDE_DIRS})
