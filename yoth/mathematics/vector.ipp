#ifndef YOTH_VECTOR_IPP
#define YOTH_VECTOR_IPP

namespace Yoth {

// clang-format off
template <typename T>
concept IsVector =
  std::same_as<T, Vector2<typename T::value_type>> || 
  std::same_as<T, Vector3<typename T::value_type>>;
// clang-format on

template <typename T> inline T Dot(const Vector2<T> &v0, const Vector2<T> &v1) {
  return SumOfProducts(v0.x, v1.x, v0.y, v1.y);
}

template <typename T> inline T Dot(const Vector3<T> &v0, const Vector3<T> &v1) {
  return FMA(v0.x, v1.x, SumOfProducts(v0.y, v1.y, v0.z, v1.z));
}

template <typename T> inline T Dot(const Vector4<T> &v0, const Vector4<T> &v1) {
  auto s0 = SumOfProducts(v0.x, v1.x, v0.y, v1.y);
  auto s1 = SumOfProducts(v0.z, v1.z, v0.w, v1.w);
  return s0 + s1;
}

// clang-format off
template <typename T> inline T Cross(const Vector3<T> &v0, const Vector3<T> &v1) {
  return {DifferenceOfProducts(v0.y, v1.z, v0.z, v1.y), 
          DifferenceOfProducts(v0.z, v1.x, v0.x, v1.z),
          DifferenceOfProducts(v0.x, v1.y, v0.y, v1.x)};
}
// clang-format on

template <typename T> inline T LengthSquared(const Vector2<T> &v) { return v.x * v.x + v.y * v.y; }

template <typename T> inline T LengthSquared(const Vector3<T> &v) { return v.x * v.x + v.y * v.y + v.z * v.z; }

template <IsVector T> inline auto Length(const T &v) -> typename VectorTypeLength<typename T::value_type>::type {
  using std::sqrt;
  return sqrt(LengthSquared(v));
}

template <IsVector T> inline auto Normalize(const T &v) { return v / Length(v); }

} // namespace Yoth

#endif // YOTH_VECTOR_IPP