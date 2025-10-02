#ifndef YOTH_VECTOR_H
#define YOTH_VECTOR_H

#include "vector_type.h"

namespace Yoth {

template <typename T>
class Vector2 : public VectorType2<T> {
public:
  using base_type = VectorType2<T>;

  Vector2() = default;

  template <typename U>
  Vector2(U v0, U v1) : base_type(T(v0), T(v1)) {
  }

  template <typename U>
  Vector2(const Vector2<U> &v) : base_type(T(v.x), T(v.y)) {
  }

  template <typename U>
  explicit Vector2(U v) : base_type(T(v)) {
  }
};

template <typename T>
class Vector3 : public VectorType3<T> {
public:
  using base_type = VectorType3<T>;
  using minus_dimension_type = Vector2<T>;

  using VectorType3<T>::x;
  using VectorType3<T>::y;
  using VectorType3<T>::z;

  Vector3() = default;

  template <typename U>
  Vector3(U v0, U v1, U v2) : base_type(T(v0), T(v1), T(v2)) {
  }

  template <typename U>
  Vector3(const Vector2<U> &v, U t) : base_type(T(v.x), T(v.y), T(t)) {
  }

  template <typename U>
  Vector3(U t, const Vector2<U> &v) : base_type(T(t), T(v.x), T(v.y)) {
  }

  template <typename U>
  Vector3(const Vector3<U> &v) : base_type(T(v.x), T(v.y), T(v.z)) {
  }

  template <typename U>
  explicit Vector3(U v) : base_type(T(v)) {
  }
};

template <typename T>
class Vector4 : public VectorType4<T> {
public:
  using base_type = VectorType4<T>;
  using minus_dimension_type = Vector3<T>;

  Vector4() = default;

  template <typename U>
  Vector4(U v0, U v1, U v2, U v3) : base_type(T(v0), T(v1), T(v2), T(v3)) {
  }

  template <typename U>
  Vector4(const Vector3<U> &v, U t) : base_type(T(v.x), T(v.y), T(v.z), T(t)) {
  }

  template <typename U>
  Vector4(U t, const Vector3<U> &v) : base_type(T(t), T(v.x), T(v.y), T(v.z)) {
  }

  template <typename U>
  Vector4(const Vector2<U> &v0, const Vector2<U> &v1) : base_type(T(v0.x), T(v0.y), T(v1.x), T(v1.y)) {
  }

  template <typename U>
  Vector4(const Vector4<U> &v) : base_type(T(v.x), T(v.y), T(v.z), T(v.w)) {
  }

  template <typename U>
  explicit Vector4(U v) : base_type(T(v)) {
  }
};

} // namespace Yoth

#include "vector.ipp"

#endif // YOTH_VECTOR_H