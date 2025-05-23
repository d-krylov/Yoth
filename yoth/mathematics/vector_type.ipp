#ifndef YOTH_VECTOR_TYPE_IPP
#define YOTH_VECTOR_TYPE_IPP

#include <algorithm>

namespace Yoth {

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType2<T>>
inline R<T> Abs(const R<T> &t) {
  using std::abs;
  return {abs(t.x), abs(t.y)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType3<T>>
inline R<T> Abs(const R<T> &t) {
  using std::abs;
  return {abs(t.x), abs(t.y), abs(t.z)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType4<T>>
inline R<T> Abs(const R<T> &t) {
  using std::abs;
  return {abs(t.x), abs(t.y), abs(t.z), abs(t.w)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType2<T>>
inline R<T> Max(const R<T> &t1, const R<T> &t2) {
  using std::max;
  return {max(t1.x, t2.x), max(t1.y, t2.y)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType3<T>>
inline R<T> Max(const R<T> &t1, const R<T> &t2) {
  using std::max;
  return {max(t1.x, t2.x), max(t1.y, t2.y), max(t1.z, t2.z)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType4<T>>
inline R<T> Max(const R<T> &t1, const R<T> &t2) {
  using std::max;
  return {max(t1.x, t2.x), max(t1.y, t2.y), max(t1.z, t2.z), max(t1.w, t2.w)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType2<T>>
inline R<T> Min(const R<T> &t1, const R<T> &t2) {
  using std::min;
  return {min(t1.x, t2.x), min(t1.y, t2.y)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType3<T>>
inline R<T> Min(const R<T> &t1, const R<T> &t2) {
  using std::min;
  return {min(t1.x, t2.x), min(t1.y, t2.y), min(t1.z, t2.z)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType4<T>>
inline R<T> Min(const R<T> &t1, const R<T> &t2) {
  using std::min;
  return {min(t1.x, t2.x), min(t1.y, t2.y), min(t1.z, t2.z), min(t1.w, t2.w)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType2<T>>
inline R<T> Ceil(const R<T> &t) {
  using std::ceil;
  return {ceil(t.x), ceil(t.y)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType3<T>>
inline R<T> Ceil(const R<T> &t) {
  using std::ceil;
  return {ceil(t.x), ceil(t.y), ceil(t.z)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType4<T>>
inline R<T> Ceil(const R<T> &t) {
  using std::ceil;
  return {ceil(t.x), ceil(t.y), ceil(t.z), ceil(t.w)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType2<T>>
inline R<T> Floor(const R<T> &t) {
  using std::floor;
  return {floor(t.x), floor(t.y)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType3<T>>
inline R<T> Floor(const R<T> &t) {
  using std::floor;
  return {floor(t.x), floor(t.y), floor(t.z)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType4<T>>
inline R<T> Floor(const R<T> &t) {
  using std::floor;
  return {floor(t.x), floor(t.y), floor(t.z), floor(t.w)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType2<T>>
inline R<T> Clamp(const R<T> &t, const R<T> &low, const R<T> &high) {
  using std::clamp;
  return {clamp(t.x, low.x, high.x), clamp(t.y, low.y, high.y)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType3<T>>
inline R<T> Clamp(const R<T> &t, const R<T> &low, const R<T> &high) {
  using std::clamp;
  return {clamp(t.x, low.x, high.x), clamp(t.y, low.y, high.y), clamp(t.z, low.z, high.z)};
}

template <typename T, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType4<T>>
inline R<T> Clamp(const R<T> &t, const R<T> &low, const R<T> &high) {
  using std::clamp;
  return {clamp(t.x, low.x, high.x), clamp(t.y, low.y, high.y), clamp(t.z, low.z, high.z), clamp(t.w, low.w, high.w)};
}

template <typename T> inline auto Lerp(T t, const VectorType2<T> &t0, const VectorType2<T> &t1) {
  return (1 - t) * t0 + t * t1;
}

template <typename T> inline auto Lerp(T t, const VectorType3<T> &t0, const VectorType3<T> &t1) {
  return (1 - t) * t0 + t * t1;
}

template <typename T> inline auto Lerp(T t, const VectorType4<T> &t0, const VectorType4<T> &t1) {
  return (1 - t) * t0 + t * t1;
}

template <Arithmetic T, Arithmetic U, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType2<T>>
inline auto operator*(U s, const R<T> &t) {
  return t * s;
}

template <Arithmetic T, Arithmetic U, template <typename> typename R>
  requires std::derived_from<R<T>, VectorType3<T>>
inline auto operator*(U s, const R<T> &t) {
  return t * s;
}

} // namespace Yoth

#endif // YOTH_VECTOR_TYPE_IPP