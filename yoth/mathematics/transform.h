#ifndef YOTH_TRANSFORM_H
#define YOTH_TRANSFORM_H

#include "matrix.h"

namespace Yoth {

// clang-format off
template <std::floating_point T> inline Matrix4<T> Translate(const Vector3<T> d) {
  return Matrix4<T>{
    1, 0, 0, d.x,
    0, 1, 0, d.y,
    0, 0, 1, d.z,
    0, 0, 0, 1
  };
}

template <std::floating_point T> inline Matrix4<T> Scale(T x, T y, T z) {
  return Matrix4<T>{
    x, 0, 0, 0,
    0, y, 0, 0,
    0, 0, z, 0,
    0, 0, 0, 1
  };
}

template <std::floating_point T> inline Matrix4<T> RotateX(T theta) {
  auto s = std::sin(Radians(theta));
  auto c = std::cos(Radians(theta));
  return Matrix4<T>{
    1,  0,  0,  0,
    0,  c, -s,  0,
    0,  s,  c,  0,
    0,  0,  0,  1
  };
}
// clang-format on

} // namespace Yoth

#endif // YOTH_TRANSFORM_H