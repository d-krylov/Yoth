#ifndef YOTH_VECTOR_TYPE_IPP
#define YOTH_VECTOR_TYPE_IPP

namespace Yoth {

template <typename T, template <typename> typename D> using VectorType2 = VectorType<T, 2, D>;
template <typename T, template <typename> typename D> using VectorType3 = VectorType<T, 3, D>;
template <typename T, template <typename> typename D> using VectorType4 = VectorType<T, 4, D>;

template <template <typename> typename Derived, typename T>
inline Derived<T> abs(VectorType2<T, Derived> t) {
  using std::abs;
  return {abs(t.x), abs(t.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> abs(VectorType3<T, Derived> t) {
  using std::abs;
  return {abs(t.x), abs(t.y), abs(t.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> abs(VectorType4<T, Derived> t) {
  using std::abs;
  return {abs(t.x), abs(t.y), abs(t.z), abs(t.w)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> max(VectorType2<T, Derived> t1, VectorType2<T, Derived> t2) {
  using std::max;
  return {max(t1.x, t2.x), abs(t1.y, t2.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> max(VectorType3<T, Derived> t1, VectorType3<T, Derived> t2) {
  using std::max;
  return {max(t1.x, t2.x), abs(t1.y, t2.y), abs(t1.z, t2.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> max(VectorType4<T, Derived> t1, VectorType4<T, Derived> t2) {
  using std::max;
  return {max(t1.x, t2.x), abs(t1.y, t2.y), abs(t1.z, t2.z), abs(t1.w, t2.w)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> min(VectorType2<T, Derived> t1, VectorType2<T, Derived> t2) {
  using std::min;
  return {max(t1.x, t2.x), abs(t1.y, t2.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> min(VectorType3<T, Derived> t1, VectorType3<T, Derived> t2) {
  using std::min;
  return {min(t1.x, t2.x), abs(t1.y, t2.y), abs(t1.z, t2.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> min(VectorType4<T, Derived> t1, VectorType4<T, Derived> t2) {
  using std::min;
  return {min(t1.x, t2.x), abs(t1.y, t2.y), abs(t1.z, t2.z), abs(t1.w, t2.w)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> ceil(VectorType2<T, Derived> t) {
  using std::ceil;
  return {ceil(t.x), ceil(t.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> ceil(VectorType3<T, Derived> t) {
  using std::ceil;
  return {ceil(t.x), ceil(t.y), ceil(t.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> ceil(VectorType4<T, Derived> t) {
  using std::ceil;
  return {ceil(t.x), ceil(t.y), ceil(t.z), ceil(t.w)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> floor(VectorType2<T, Derived> t) {
  using std::floor;
  return {floor(t.x), floor(t.y)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> floor(VectorType3<T, Derived> t) {
  using std::floor;
  return {floor(t.x), floor(t.y), floor(t.z)};
}

template <template <typename> typename Derived, typename T>
inline Derived<T> floor(VectorType4<T, Derived> t) {
  using std::floor;

  return {floor(t.x), floor(t.y), floor(t.z), floor(t.w)};
}

} // namespace Yoth

#endif // YOTH_VECTOR_TYPE_IPP