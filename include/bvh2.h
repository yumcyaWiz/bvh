#pragma once
#include <pthread.h>

#include <cstdint>
#include <vector>

#include "aabb.h"

template <typename Primitive>
class Intersector
{
 public:
  Intersector(Primitive* primitives, uint32_t n_primitives)
      : m_primitives(primitives), m_n_primitives(n_primitives)
  {
  }

  // find closest ray intersection
  virtual bool intersect(const Ray& ray, IntersectInfo& info) const = 0;

 protected:
  Primitive* m_primitives;  // array of primitives
  uint32_t m_n_primitives;  // number of primitives
};

template <typename Primitive>
class BVH2 : public Intersector<Primitive>
{
 public:
  BVH2(Primitive* primitives, uint32_t n_primitives)
      : Intersector<Primitive>(primitives, n_primitives)
  {
  }

 private:
  struct alignas(32) BVHNode {
    AABB bbox;  // bounding box
    union {
      uint32_t primitive_indices_offset;  // offset to primitives
      uint32_t second_child_offset;       // offset to second child node
    };
    uint16_t n_primitives = 0;  // number of primitives(0 means internal node)
    uint8_t axis = 0;           // splitting axis
  };

  struct BVHStatistics {
    int n_nodes = 0;           // number of nodes
    int n_internal_nodes = 0;  // number of internal nodes
    int n_leaf_nodes = 0;      // number of leaf nodes
  };

  std::vector<BVHNode> m_nodes;
  BVHStatistics m_stats;
};