# Minimum CMake version
cmake_minimum_required(VERSION 3.15)

# Project information
project(MyGameEngine VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Define the main executable target
add_executable(MyGameEngine ${SOURCES} ${HEADERS})

# Include headers
target_include_directories(MyGameEngine PRIVATE include)

# Link OpenSSL for encryption support
find_package(OpenSSL REQUIRED)
target_link_libraries(MyGameEngine PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# Set platform-specific options
if (WIN32)
    # Windows-specific configurations
    message(STATUS "Configuring for Windows...")
    
    # Define Windows-specific preprocessor directives or compiler flags
    target_compile_definitions(MyGameEngine PRIVATE PLATFORM_WINDOWS)
    
    # Set Windows build options (e.g., static runtime libraries)
    set_target_properties(MyGameEngine PROPERTIES
        COMPILE_FLAGS "/MT"
    )

    # Windows-specific libraries
    target_link_libraries(MyGameEngine PRIVATE ws2_32) # Windows Sockets API, if needed

elseif (APPLE)
    # macOS-specific configurations
    message(STATUS "Configuring for macOS...")

    # Define macOS-specific preprocessor directives or compiler flags
    target_compile_definitions(MyGameEngine PRIVATE PLATFORM_MACOS)

    # macOS-specific frameworks or libraries
    find_library(COCOA_FRAMEWORK Cocoa REQUIRED)
    target_link_libraries(MyGameEngine PRIVATE ${COCOA_FRAMEWORK})

    # Additional macOS options
    set_target_properties(MyGameEngine PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.mycompany.MyGameEngine"
    )
endif()
# Enable installation
install(TARGETS MyGameEngine DESTINATION bin)

add_subdirectory(core)
add_subdirectory(graphics)
add_subdirectory(input)
add_subdirectory(ai)
add_subdirectory(encryption)
set(SOURCES
    core/main.cpp
    core/engine_metadata.cpp
    graphics/splash_screen.cpp
    services/game_registry.cpp
)

set(HEADERS
    core/engine_metadata.h
    graphics/splash_screen.h
    services/game_registry.h
)

add_executable(GameEngine ${SOURCES} ${HEADERS})

add_executable(game-engine core/main.cpp)
target_link_libraries(game-engine core graphics input ai encryption)
