cmake_minimum_required(VERSION 3.22)
project(AugmentImages)

set(CMAKE_CXX_STANDARD 17)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include directories for both OpenCV and the header files
include_directories(${OpenCV_INCLUDE_DIRS} lib/include)

# Add executable
add_executable(AugmentImages main.cpp lib/src/AugmentImages.cpp
        lib/include/AugmentImages.h
        lib/src/ImageProcessor.cpp
        lib/include/ImageProcessor.h
        lib/include/ImageProcessor.h)

# Link libraries
target_link_libraries(AugmentImages ${OpenCV_LIBS})
