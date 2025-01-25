#ifndef YOTH_VECTOR_TYPE_IPP
#define YOTH_VECTOR_TYPE_IPP

namespace Yoth {

template <template <typename> typename Derived, typename T>
inline Derived<T> Abs(const VectorType2<T, Derived> &t) {
  using std::abs;
  return {abs(t.x), abs(t.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Abs(const VectorType3<T, Derived> &t) {
  using std::abs;
  return {abs(t.x), abs(t.y), abs(t.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Abs(const VectorType4<T, Derived> &t) {
  using std::abs;
  return {abs(t.x), abs(t.y), abs(t.z), abs(t.w)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Max(const VectorType2<T, Derived> &t1, const VectorType2<T, Derived> &t2) {
  using std::max;
  return {max(t1.x, t2.x), max(t1.y, t2.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Max(const VectorType3<T, Derived> &t1, const VectorType3<T, Derived> &t2) {
  using std::max;
  return {max(t1.x, t2.x), max(t1.y, t2.y), max(t1.z, t2.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Max(const VectorType4<T, Derived> &t1, const VectorType4<T, Derived> &t2) {
  using std::max;
  return {max(t1.x, t2.x), max(t1.y, t2.y), max(t1.z, t2.z), max(t1.w, t2.w)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Min(const VectorType2<T, Derived> &t1, const VectorType2<T, Derived> &t2) {
  using std::min;
  return {min(t1.x, t2.x), min(t1.y, t2.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Min(const VectorType3<T, Derived> &t1, const VectorType3<T, Derived> &t2) {
  using std::min;
  return {min(t1.x, t2.x), min(t1.y, t2.y), min(t1.z, t2.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Min(const VectorType4<T, Derived> &t1, const VectorType4<T, Derived> &t2) {
  using std::min;
  return {min(t1.x, t2.x), min(t1.y, t2.y), min(t1.z, t2.z), min(t1.w, t2.w)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Ceil(const VectorType2<T, Derived> &t) {
  using std::ceil;
  return {ceil(t.x), ceil(t.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Ceil(const VectorType3<T, Derived> &t) {
  using std::ceil;
  return {ceil(t.x), ceil(t.y), ceil(t.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Ceil(const VectorType4<T, Derived> &t) {
  using std::ceil;
  return {ceil(t.x), ceil(t.y), ceil(t.z), ceil(t.w)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Floor(const VectorType2<T, Derived> &t) {
  using std::floor;
  return {floor(t.x), floor(t.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Floor(const VectorType3<T, Derived> &t) {
  using std::floor;
  return {floor(t.x), floor(t.y), floor(t.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> Floor(const VectorType4<T, Derived> &t) {
  using std::floor;
  return {floor(t.x), floor(t.y), floor(t.z), floor(t.w)};
}

template <template <typename> class Derived, Arithmetic T, Arithmetic U>
inline auto operator*(U s, const VectorType2<T, Derived> &t) -> Derived<decltype(T{} * U{})> {
  return t * s;
}

template <template <typename> class Derived, Arithmetic T, Arithmetic U>
inline auto operator*(U s, const VectorType3<T, Derived> &t) -> Derived<decltype(T{} * U{})> {
  return t * s;
}

} // namespace Yoth

#endif // YOTH_VECTOR_TYPE_IPP