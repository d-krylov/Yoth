#ifndef YOTH_MATHEMATICS_H
#define YOTH_MATHEMATICS_H

#include "constants.h"
#include "matrix.h"
#include "normal.h"
#include "point.h"
#include "quaternion.h"
#include <cstdint>

namespace Yoth {

using FloatType = float;

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
using Matrix4i = Matrix4<int32_t>;
using Matrix4f = Matrix4<float>;

using Point2F = Point2<FloatType>;
using Point3F = Point3<FloatType>;
using Vector2F = Vector2<FloatType>;
using Vector3F = Vector3<FloatType>;
using Vector4F = Vector4<FloatType>;
using Matrix4F = Matrix4<FloatType>;
using Normal3F = Normal3<FloatType>;

} // namespace Yoth

#endif // YOTH_MATHEMATICS_H