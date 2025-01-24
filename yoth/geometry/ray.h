#ifndef YOTH_RAY_H
#define YOTH_RAY_H

#include "mathematics/mathematics.h"

namespace Yoth {

template <typename T = float> class Ray {
public:
  Ray(const Point3<T> &origin, const Vector3<T> &direction) : origin_(origin), direction_(direction) {}

  Point3<T> operator()(T t) const { return origin_ + direction_ * t; }

public:
  Point3<T> origin_;
  Vector3<T> direction_;
};

} // namespace Yoth

#endif // YOTH_RAY_H