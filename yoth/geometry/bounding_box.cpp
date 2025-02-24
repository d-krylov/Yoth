#include "bounding_box.h"

namespace Yoth {

BoundingBox::BoundingBox() {
  auto min = std::numeric_limits<FloatType>::lowest();
  auto max = std::numeric_limits<FloatType>::max();
  min_ = Point3F(max);
  max_ = Point3F(min);
}

void BoundingBox::Expand(const Point3F &p) {
  min_ = Min(min_, p);
  max_ = Max(max_, p);
}

void BoundingBox::Expand(const BoundingBox &b) {
  min_ = Min(min_, b.min_);
  max_ = Max(max_, b.max_);
}

} // namespace Yoth
