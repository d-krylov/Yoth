#ifndef YOTH_VECTOR_H
#define YOTH_VECTOR_H

#include "vector_type.h"

namespace Yoth {

template <typename T> class Vector2 : public VectorType<T, 2, Vector2> {
public:
  Vector2() = default;
  template <typename U> Vector2(U v) : VectorType<T, 2, Vector2>(T(v)) {}
  template <typename U> Vector2(U v0, U v1) : VectorType<T, 2, Vector2>(T(v0), T(v1)) {}
};

template <typename T> class Vector3 : public VectorType<T, 3, Vector3> {
public:
  Vector3() = default;
  template <typename U> Vector3(U v) : VectorType<T, 3, Vector3>(T(v)) {}
  template <typename U> Vector3(U v0, U v1, U v2) : VectorType<T, 3, Vector3>(T(v0), T(v1), T(v2)) {}
};

template <typename T> class Vector4 : public VectorType<T, 4, Vector4> {
public:
  Vector4() = default;
  template <typename U> Vector4(U v) : VectorType<T, 4, Vector4>(T(v)) {}
  template <typename U>
  Vector4(U v0, U v1, U v2, U v3) : VectorType<T, 4, Vector4>(T(v0), T(v1), T(v2), T(v3)) {}
};

} // namespace Yoth

#include "vector.ipp"

#endif // YOTH_VECTOR_H