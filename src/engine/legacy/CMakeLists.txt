add_library(
  legacy
  STATIC
  include/legacy/sceneloader.h
  include/legacy/sceneloader2.h
  src/sceneloader.cpp
  src/sceneloader2.cpp
)

target_include_directories(legacy PUBLIC include)
target_link_libraries(legacy PUBLIC core)
target_link_libraries(legacy PRIVATE config runtime game utils component rapidjson asset)
