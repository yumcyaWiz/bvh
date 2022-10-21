#pragma once

#include "glm/glm.hpp"

struct Ray {
  glm::vec3 origin;     // ray origin
  glm::vec3 direction;  // ray direction
  float tmin = 0.0f;    // minimum hit distance
  mutable float tmax = 1e9f;
  ;  // maximum hit distance

  Ray() {}
  Ray(const glm::vec3& origin_, const glm::vec3& direction_)
      : origin(origin_), direction(direction_)
  {
  }

  // return position on the ray with distance t
  glm::vec3 operator()(float t) const { return origin + t * direction; }
};

struct IntersectInfo {
  float t = 0.0f;                        // hit distance
  glm::vec3 position = glm::vec3(0.0f);  // hit position
  glm::vec3 normal = glm::vec3(0.0f);    // hit normal
  glm::vec2 texcoord = glm::vec2(0.0f);  // hit texcoord

  int bvh_depth = 0;  // bvh intersection count(for debugging purpose)
};