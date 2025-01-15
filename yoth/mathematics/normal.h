#ifndef YOTH_NORMAL_H
#define YOTH_NORMAL_H

#include "vector_type.h"

namespace Yoth {

template <typename T> class Normal3 : public VectorType<T, 3, Normal3> {
public:
  Normal3() = default;
  template <typename U> Normal3(U v) : VectorType<T, 3, Normal3>(T(v)) {}
  template <typename U> Normal3(U v0, U v1, U v2) : VectorType<T, 3, Normal3>(T(v0), T(v1), T(v2)) {}
};

} // namespace Yoth

#endif // YOTH_NORMAL_H