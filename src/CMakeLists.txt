set(SOURCES main.c)

add_executable(Touhou-DanmakuReverseEng ${SOURCES})
target_include_directories(Touhou-DanmakuReverseEng PUBLIC ${CMAKE_SOURCE_DIR}/include)
