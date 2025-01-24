#ifndef YOTH_BOUNDING_BOX_H
#define YOTH_BOUNDING_BOX_H

#include "ray.h"
#include <limits>

namespace Yoth {

template <typename T = float> class BoundingBox {
public:
  BoundingBox();
  BoundingBox(const Point3<T> &p1, const Point3<T> &p2) : min_(Min(p1, p2)), max_(Max(p1, p2)) {}

  void Expand(const Point3<T> &p);
  void Expand(const BoundingBox<T> &b);

  const Point3<T> &GetMin() const { return min_; }
  const Point3<T> &GetMax() const { return max_; }

private:
  Point3<T> min_;
  Point3<T> max_;
};

} // namespace Yoth

#include "bounding_box.ipp"

#endif // YOTH_BOUNDING_BOX_H