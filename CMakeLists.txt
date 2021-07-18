project(figures)

set(SOURCE_FILES
main.c
rectangle.c
rectangle.h
triangle.c
triangle.h
)

add_executable(${PROJECT_NAME} 
${SOURCE_FILES}
)