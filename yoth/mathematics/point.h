#ifndef YOTH_POINT_H
#define YOTH_POINT_H

#include "vector.h"

namespace Yoth {

template <Arithmetic T> class Point2 : public VectorType2<T, Point2> {
public:
  using VectorType2<T, Point2>::x;
  using VectorType2<T, Point2>::y;

  using base_type = VectorType2<T, Point2>;

  Point2() = default;

  template <Arithmetic U> Point2(U v) : base_type(T(v)) {}
  template <Arithmetic U> Point2(U v0, U v1) : base_type(T(v0), T(v1)) {}

  template <Arithmetic U> auto operator+=(const Vector2<U> &v) const { return Point2{x + v.x, y + v.y}; }

  template <Arithmetic U> auto operator-(const Point2<U> &other) const -> Vector2<decltype(T{} - U{})> {
    return {x - other.x, y - other.y};
  }
};

template <Arithmetic T> class Point3 : public VectorType3<T, Point3> {
public:
  using VectorType3<T, Point3>::x;
  using VectorType3<T, Point3>::y;
  using VectorType3<T, Point3>::z;

  using base_type = VectorType3<T, Point3>;

  Point3() = default;

  template <Arithmetic U> Point3(U v) : base_type(T(v)) {}
  template <Arithmetic U> Point3(U v0, U v1, U v2) : base_type(T(v0), T(v1), T(v2)) {}

  template <typename U> auto &operator+=(const Vector3<U> &v) const {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  template <typename U> auto operator+(const Vector3<U> &v) const -> Point3<decltype(T{} + U{})> {
    return {x + v.x, y + v.y, z + v.z};
  }

  template <typename U> auto operator-(const Point3<U> &other) const -> Vector3<decltype(T{} - U{})> {
    return {x - other.x, y - other.y, z - other.z};
  }
};

// clang-format off
template <typename T>
concept IsPoint =
  std::same_as<T, Point2<typename T::value_type>> || 
  std::same_as<T, Point3<typename T::value_type>>;
// clang-format on

template <IsPoint T>
inline auto Distance(const T &p1, const T &p2) ->
  typename VectorTypeLength<typename T::value_type>::type {
  return Length(p1 - p2);
}

template <IsPoint T>
inline auto DistanceSquared(const T &p1, const T &p2) ->
  typename VectorTypeLength<typename T::value_type>::type {
  return LengthSquared(p1 - p2);
}

} // namespace Yoth

#endif // YOTH_POINT_H