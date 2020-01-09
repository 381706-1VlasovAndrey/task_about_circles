file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${CircleLib} STATIC ${srcs} ${hdrs})