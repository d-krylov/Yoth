#ifndef YOTH_VECTOR_IPP
#define YOTH_VECTOR_IPP

namespace Yoth {

template <typename T> inline T dot(const Vector2<T> &v0, const Vector2<T> &v1) {}

template <typename T> inline T dot(const Vector3<T> &v0, const Vector3<T> &v1) {}

template <typename T> inline T dot(const Vector4<T> &v0, const Vector4<T> &v1) {}

template <typename T> inline T cross(const Vector3<T> &v0, const Vector3<T> &v1) {}

} // namespace Yoth

#endif // YOTH_VECTOR_IPP