file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${CircleTest} ${srcs} ${hdrs})
target_link_libraries(${CircleTest} ${CircleLib} gtest)
