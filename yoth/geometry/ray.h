#ifndef YOTH_RAY_H
#define YOTH_RAY_H

#include "mathematics/mathematics.h"

namespace Yoth {

class Ray {
public:
  Ray(const Point3F &origin, const Vector3F &direction) : origin_(origin), direction_(direction) {}

  auto operator()(FloatType t) const { return origin_ + direction_ * t; }

public:
  Point3F origin_;
  Vector3F direction_;
};

} // namespace Yoth

#endif // YOTH_RAY_H