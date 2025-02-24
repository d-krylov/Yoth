#ifndef YOTH_BOUNDING_BOX_H
#define YOTH_BOUNDING_BOX_H

#include "ray.h"
#include <limits>

namespace Yoth {

class BoundingBox {
public:
  BoundingBox();
  BoundingBox(const Point3F &p1, const Point3F &p2) : min_(Min(p1, p2)), max_(Max(p1, p2)) {}

  void Expand(const Point3F &p);
  void Expand(const BoundingBox &b);

  const Point3F &GetMin() const { return min_; }
  const Point3F &GetMax() const { return max_; }

private:
  Point3F min_;
  Point3F max_;
};

} // namespace Yoth

#endif // YOTH_BOUNDING_BOX_H