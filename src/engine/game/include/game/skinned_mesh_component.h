#pragma once

#include <game/primitive_component.h>
#include <runtime/skinned_mesh.h>
#include <game/transform_component.h>
#include <string>

namespace game {
using namespace component;
struct SkinnedMeshComponent {
  component::ComponentHandle2<game::TransformComponent> cached_transform_component;
  asset::AssetHandle<runtime::SkinnedMesh> mesh;
  
  String current_animation;
  float animation_time;

  
  struct Extents {
    glm::vec3 min, max;
  };
  Extents extents;
  std::vector<glm::mat4x4> object_to_bone_transforms;
  std::vector<glm::mat4x4> bone_transforms;
  i32 number_of_bones_used;
};
} // namespace component
declare_component(game::SkinnedMeshComponent)
