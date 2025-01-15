#ifndef YOTH_RAY_H
#define YOTH_RAY_H

#include "mathematics/mathematics.h"

namespace Yoth {

class Ray {
public:
  Ray(const Point3f &origin, const Vector3f &direction) : origin_(origin), direction_(direction) {}

  Point3f operator()(float t) const { return origin_ + direction_ * t; }

public:
  Point3f origin_;
  Vector3f direction_;
};

} // namespace Yoth

#endif // YOTH_RAY_H