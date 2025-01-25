#ifndef YOTH_TRANSFORM_IPP
#define YOTH_TRANSFORM_IPP

namespace Yoth {

// clang-format off
template <typename T> Matrix4<T> Translate(const Point3<T> p) {
  return Matrix4<T>(1, 0, 0, p.x, 
                    0, 1, 0, p.y, 
                    0, 0, 1, p.z, 
                    0, 0, 0, 1);
}

template <typename T> Matrix4<T> Scale(T x, T y, T z) {
  return Matrix4<T>(x, 0, 0, 0,
                    0, y, 0, 0,
                    0, 0, z, 0,
                    0, 0, 0, 1);
}

template <typename T> Matrix4<T> RotateX(T theta) {
  auto s = std::sin(Radians(theta));
  auto c = std::cos(Radians(theta));
  return Matrix4<T>(1, 0, 0, 0,
                    0, c,-s, 0, 
                    0, s, c, 0,
                    0, 0, 0, 1);
}

template <typename T> Matrix4<T> RotateY(T theta) {
  auto s = std::sin(Radians(theta));
  auto c = std::cos(Radians(theta));
  return Matrix4<T>(c, 0, s, 0,
                    0, 1, 0, 0, 
                   -s, 0, c, 0,
                    0, 0, 0, 1);
}

template <typename T> Matrix4<T> RotateZ(T theta) {
  auto s = std::sin(Radians(theta));
  auto c = std::cos(Radians(theta));
  return Matrix4<T>(c,-s, 0, 0,
                    s, c, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1);
}
// clang-format on

} // namespace Yoth

#endif // YOTH_TRANSFORM_IPP