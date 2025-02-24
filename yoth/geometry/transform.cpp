#include "transform.h"

namespace Yoth {

// clang-format off
Matrix4F Translate(const Point3F p) {
  return Matrix4F{1, 0, 0, p.x, 
                  0, 1, 0, p.y, 
                  0, 0, 1, p.z, 
                  0, 0, 0, 1};
}

Matrix4F Scale(FloatType x, FloatType y, FloatType z) {
  return Matrix4F{x, 0, 0, 0,
                  0, y, 0, 0,
                  0, 0, z, 0,
                  0, 0, 0, 1};
}

Matrix4F RotateX(FloatType theta) {
  auto s = std::sin(Radians(theta));
  auto c = std::cos(Radians(theta));
  return Matrix4F{1, 0, 0, 0,
                  0, c,-s, 0, 
                  0, s, c, 0,
                  0, 0, 0, 1};
}

Matrix4F RotateY(FloatType theta) {
  auto s = std::sin(Radians(theta));
  auto c = std::cos(Radians(theta));
  return Matrix4F{c, 0, s, 0,
                  0, 1, 0, 0, 
                 -s, 0, c, 0,
                  0, 0, 0, 1};
}

Matrix4F RotateZ(FloatType theta) {
  auto s = std::sin(Radians(theta));
  auto c = std::cos(Radians(theta));
  return Matrix4F{c,-s, 0, 0,
                  s, c, 0, 0,
                  0, 0, 1, 0,
                  0, 0, 0, 1};
}
// clang-format on

} // namespace Yoth
