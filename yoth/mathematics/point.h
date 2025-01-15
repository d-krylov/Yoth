#ifndef YOTH_POINT_H
#define YOTH_POINT_H

#include "vector.h"

namespace Yoth {

template <typename T> class Point2 : public VectorType<T, 2, Point2> {
public:
  using VectorType<T, 2, Point2>::x;
  using VectorType<T, 2, Point2>::y;

  Point2() = default;

  template <typename U> Point2(U v) : VectorType<T, 2, Point2>(T(v)) {}
  template <typename U> Point2(U v0, U v1) : VectorType<T, 2, Point2>(T(v0), T(v1)) {}

  template <typename U> auto operator+=(const Vector2<U> &v) const { return Point2{x + v.x, y + v.y}; }
};

template <typename T> class Point3 : public VectorType<T, 3, Point3> {
public:
  using VectorType<T, 3, Point3>::x;
  using VectorType<T, 3, Point3>::y;
  using VectorType<T, 3, Point3>::z;

  Point3() = default;

  template <typename U> Point3(U v) : VectorType<T, 3, Point3>(T(v)) {}
  template <typename U> Point3(U v0, U v1, U v2) : VectorType<T, 3, Point3>(T(v0), T(v1), T(v2)) {}

  template <typename U> auto &operator+=(const Vector3<U> &v) const {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  template <typename U> auto operator+(Vector3<U> v) const -> Point3<decltype(T{} + U{})> {
    return {x + v.x, y + v.y, z + v.z};
  }
};

} // namespace Yoth

#endif // YOTH_POINT_H