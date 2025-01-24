#ifndef YOTH_BOUNDING_BOX_IPP
#define YOTH_BOUNDING_BOX_IPP

namespace Yoth {

template <typename T> BoundingBox<T>::BoundingBox() {
  auto min = std::numeric_limits<T>::lowest();
  auto max = std::numeric_limits<T>::max();
  min_ = Point3<T>(max);
  max_ = Point3<T>(min);
}

template <typename T> void BoundingBox<T>::Expand(const Point3<T> &p) {
  min_ = Min(min_, p);
  max_ = Max(max_, p);
}

template <typename T> void BoundingBox<T>::Expand(const BoundingBox<T> &b) {
  min_ = Min(min_, b.min_);
  max_ = Max(max_, b.max_);
}

} // namespace Yoth

#endif // YOTH_BOUNDING_BOX_IPP