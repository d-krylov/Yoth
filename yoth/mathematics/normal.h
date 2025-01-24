#ifndef YOTH_NORMAL_H
#define YOTH_NORMAL_H

#include "vector.h"

namespace Yoth {

template <std::floating_point T> class Normal3 : public VectorType<T, 3, Normal3> {
public:
  Normal3() = default;
  template <std::floating_point U> Normal3(U v) : VectorType<T, 3, Normal3>(T(v)) {}
  template <std::floating_point U>
  Normal3(U v0, U v1, U v2) : VectorType<T, 3, Normal3>(T(v0), T(v1), T(v2)) {}
};

template <std::floating_point T> inline Vector3<T> Reflect(const Vector3<T> &v, const Vector3<T> &n) {
  return v - 2.0f * Dot(v, n) * n;
}

template <Arithmetic T> inline T Dot(const Normal3<T> &n, const Vector3<T> &v) {
  return FMA(n.x, v.x, SumOfProducts(n.y, v.y, n.z, v.z));
}

template <Arithmetic T> inline T Dot(const Normal3<T> &n1, const Normal3<T> &n2) {
  return FMA(n1.x, n2.x, SumOfProducts(n1.y, n2.y, n1.z, n2.z));
}

template <Arithmetic T> inline T Dot(const Vector3<T> &v, const Normal3<T> &n) { return Dot(n, v); }

} // namespace Yoth

#endif // YOTH_NORMAL_H