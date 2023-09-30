cmake_minimum_required(VERSION 3.10)

project(Project_Image_to_greyscale)

set(OpenCV_DIR C:/Projects/opencv/build)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})