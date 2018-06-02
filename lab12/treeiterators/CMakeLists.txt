
project(tree)

set(HEDEAR_FILES
Tree.h)
set(SOURCE_FILES
Tree.cpp)

add_library(libtreeiterators
STATIC ${SOURCE_FILES}
)
target_include_directories(libtreeiterators
PUBLIC .)

add_executable(treeiterators
${SOURCE_FILES} main.cpp)

target_link_libraries(treeiterators libiterable)
target_link_libraries(treeiterators libtreeiterators)
