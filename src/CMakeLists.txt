set(SOURCES
  main.c
  sprite-base.c
  hitbox.c
  player.c
  local-cordinate.c
  config.c
  util.c
  tama.c
  game.c
  boss.c
  bosses/demo.c
  screens/title.c
  screens/gameSetup.c
  screens/gamePlay.c
  screens/gameEnd.c
)

set(ASESTS_SOURCES
  ${CMAKE_SOURCE_DIR}/assets/player_tama.c
)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 4.2.0)
find_package(raylib ${RAYLIB_VERSION} REQUIRED) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

add_executable(Touhou-DanmakuReverseEng ${SOURCES} ${ASESTS_SOURCES})
target_include_directories(Touhou-DanmakuReverseEng PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(Touhou-DanmakuReverseEng raylib m)
