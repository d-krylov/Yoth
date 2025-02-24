#include "shapes.h"

namespace Yoth {

bool IntersectSphere(const Ray &ray, const Point3F &origin, FloatType radius, FloatType &t1, FloatType &t2) {
  auto origin_to_center = ray.origin_ - origin;
  auto b = Dot(origin_to_center, ray.direction_);
  auto c = Dot(origin_to_center, origin_to_center) - radius * radius;
  auto D = b * b - c;
  if (D < 0.0) {
    return false;
  }
  t1 = -b - std::sqrt(D);
  t2 = -b + std::sqrt(D);
  return true;
}

} // namespace Yoth