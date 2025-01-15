#ifndef YOTH_VECTOR_IPP
#define YOTH_VECTOR_IPP

namespace Yoth {

template <typename T> inline T dot(const Vector2<T> &v0, const Vector2<T> &v1) {
  return SumOfProducts(v0.x, v1.x, v0.y, v1.y);
}

template <typename T> inline T dot(const Vector3<T> &v0, const Vector3<T> &v1) {
  return FMA(v0.x, v0.x, SumOfProducts(v0.y, v1.y, v0.z, v1.z));
}

template <typename T> inline T dot(const Vector4<T> &v0, const Vector4<T> &v1) {
  auto s0 = SumOfProducts(v0.x, v1.x, v0.y, v1.y);
  auto s1 = SumOfProducts(v0.z, v1.z, v0.w, v1.w);
  return s0 + s1;
}

// clang-format off
template <typename T> inline T cross(const Vector3<T> &v0, const Vector3<T> &v1) {
  return {DifferenceOfProducts(v0.y, v1.z, v0.z, v1.y), 
          DifferenceOfProducts(v0.z, v1.x, v0.x, v1.z),
          DifferenceOfProducts(v0.x, v1.y, v0.y, v1.x)};
}
// clang-format on

} // namespace Yoth

#endif // YOTH_VECTOR_IPP