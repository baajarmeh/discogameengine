#pragma once

#include <string>
#include <component/component.h>

namespace game {
using namespace component;
struct TransformComponent {
  glm::vec3 position = glm::vec3(0);
  glm::vec3 scale = glm::vec3(1.f);
  glm::quat rotation = glm::vec3(0, 0, 0);
  // This value is automatically recalculated each frame.
  glm::mat4 transform_matrix_previous = glm::mat4(1.f);
  glm::mat4 transform_matrix = glm::mat4(1.f);
};
} // namespace game
declare_component(game::TransformComponent)
