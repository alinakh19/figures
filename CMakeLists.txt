cmake_minimum_required(VERSION 3.16)

project(figures)

set(SOURCE_FILES
main.c
rectangle.c
rectangle.h
line.c
line.h
triangle.c
triangle.h
)

add_executable(${PROJECT_NAME} 
${SOURCE_FILES}
)

# find_package(Curses REQUIRED)
# include_directories(${CURSES_INCLUDE_DIR})
# target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY})