# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# IMGUI_SOURCES at CMakeLists.txt:26 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/Users/waz/GLRender/libs/imgui/src/*.cpp")
set(OLD_GLOB
  "/Users/waz/GLRender/libs/imgui/src/imgui.cpp"
  "/Users/waz/GLRender/libs/imgui/src/imgui_demo.cpp"
  "/Users/waz/GLRender/libs/imgui/src/imgui_draw.cpp"
  "/Users/waz/GLRender/libs/imgui/src/imgui_tables.cpp"
  "/Users/waz/GLRender/libs/imgui/src/imgui_widgets.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/waz/GLRender/cmake-build-debug/CMakeFiles/cmake.verify_globs")
endif()
