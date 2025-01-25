#ifndef YOTH_VECTOR_H
#define YOTH_VECTOR_H

#include "vector_type.h"

namespace Yoth {

template <typename T> class Vector2 : public VectorType2<T, Vector2> {
public:
  using base_type = VectorType2<T, Vector2>;

  Vector2() = default;
  template <typename U> Vector2(U v0, U v1) : base_type(T(v0), T(v1)) {}
  template <typename U> explicit Vector2(U v) : base_type(T(v)) {}
};

template <typename T> class Vector3 : public VectorType3<T, Vector3> {
public:
  using base_type = VectorType3<T, Vector3>;

  Vector3() = default;
  template <typename U> Vector3(U v0, U v1, U v2) : base_type(T(v0), T(v1), T(v2)) {}
  template <typename U> explicit Vector3(U v) : base_type(T(v)) {}
};

template <typename T> class Vector4 : public VectorType4<T, Vector4> {
public:
  using base_type = VectorType4<T, Vector4>;

  Vector4() = default;
  template <typename U> Vector4(U v0, U v1, U v2, U v3) : base_type(T(v0), T(v1), T(v2), T(v3)) {}
  template <typename U> explicit Vector4(U v) : base_type(T(v)) {}
};

} // namespace Yoth

#include "vector.ipp"

#endif // YOTH_VECTOR_H