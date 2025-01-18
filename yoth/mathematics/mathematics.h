#ifndef YOTH_MATHEMATICS_H
#define YOTH_MATHEMATICS_H

#include "matrix.h"
#include "normal.h"
#include "point.h"
#include "quaternion.h"
#include "vector.h"
#include <cstdint>

namespace Yoth {

using Point2i = Point2<int32_t>;
using Point3i = Point3<int32_t>;
using Point2u = Point2<uint32_t>;
using Point3u = Point3<uint32_t>;
using Point2f = Point2<float>;
using Point3f = Point3<float>;
using Point2d = Point2<double>;
using Point3d = Point3<double>;
using Vector2i = Vector2<int32_t>;
using Vector3i = Vector3<int32_t>;
using Vector4i = Vector4<int32_t>;
using Vector2u = Vector2<uint32_t>;
using Vector3u = Vector3<uint32_t>;
using Vector4u = Vector4<uint32_t>;
using Vector2f = Vector2<float>;
using Vector3f = Vector3<float>;
using Vector4f = Vector4<float>;
using Vector2d = Vector2<double>;
using Vector3d = Vector3<double>;
using Vector4d = Vector4<double>;
using Matrix4i = Matrix<int32_t, 4, 4>;
using Matrix4f = Matrix<float, 4, 4>;

} // namespace Yoth

#endif // YOTH_MATHEMATICS_H