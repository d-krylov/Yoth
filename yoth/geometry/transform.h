#ifndef YOTH_TRANSFORM_H
#define YOTH_TRANSFORM_H

#include "ray.h"

namespace Yoth {

Matrix4F Translate(const Point3F p);
Matrix4F Scale(FloatType x, FloatType y, FloatType z);
Matrix4F RotateX(FloatType theta);
Matrix4F RotateY(FloatType theta);
Matrix4F RotateZ(FloatType theta);

} // namespace Yoth

#endif // YOTH_TRANSFORM_H