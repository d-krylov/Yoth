#ifndef YOTH_SHAPES_H
#define YOTH_SHAPES_H

#include "ray.h"

namespace Yoth {

struct Hit {
  Point3F position_;
  Normal3F normal_;
};

bool IntersectSphere(const Ray &ray, const Point3F &origin, FloatType radius, FloatType &t1, FloatType &t2);

} // namespace Yoth

#endif // YOTH_SHAPES_H