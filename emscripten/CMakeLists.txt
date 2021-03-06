include_directories(../laz-perf)

if (NOT EMSCRIPTEN)
	message(FATAL_ERROR "You should not be including this directory for non emscripten builds")
endif()

set(ALL_LIBRARIES ${LAZPERF_DEPENDENT_LIBRARIES})

# we need the bind flag to generate bindings
set(CMAKE_CXX_FLAGS "--bind -s TOTAL_MEMORY=167772160 -s DISABLE_EXCEPTION_CATCHING=2 ${CMAKE_CXX_FLAGS}")

# If wasm build was requested, then generate native output
if (WASM)
  message(MESSAGE " :: WASM Emscripten output has been enabled")
  set(CMAKE_CXX_FLAGS "-s WASM=1 -s \"BINARYEN_METHOD='native-wasm'\" ${CMAKE_CXX_FLAGS}")
endif()

add_executable(laz-perf laz-perf.cpp)
target_link_libraries(laz-perf ${ALL_LIBRARIES})

if (WASM)
  SET_TARGET_PROPERTIES(laz-perf PROPERTIES SUFFIX .html)
else()
  SET_TARGET_PROPERTIES(laz-perf PROPERTIES SUFFIX .asm.js)
endif()
