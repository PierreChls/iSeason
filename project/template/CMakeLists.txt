include_directories(include/)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)

set(EXECUTABLE "game")
add_executable(${EXECUTABLE} ${SRC_FILES} game.cpp)
target_link_libraries(${EXECUTABLE} ${ALL_LIBRARIES})

file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
