# tinyobjloader
add_library(tinyobjloader
    "tinyobjloader.cpp"
)
target_include_directories(tinyobjloader PUBLIC "tinyobjloader/")

# glm
add_subdirectory("glm/")

# spdlog
SET(SPDLOG_MASTER_PROJECT ON CACHE BOOL "" FORCE)
add_subdirectory(spdlog)