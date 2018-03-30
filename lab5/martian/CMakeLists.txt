
project(martian)

set(HEDEAR_FILES
Martian.h)
set(SOURCE_FILES
Martian.cpp)

add_library(libmartian
STATIC ${SOURCE_FILES}
)
target_include_directories(libmartian
PUBLIC .)

add_executable(martian
${SOURCE_FILES} main.cpp)

target_link_libraries(martian
libmartian)
