#ifndef YOTH_CONSTANTS_H
#define YOTH_CONSTANTS_H

#include "core/concepts.h"

namespace Yoth {

template <std::floating_point T> inline constexpr T Pi() {
  return T(3.1415926535897932384626433832795028841971);
}
template <std::floating_point T> inline constexpr T S2() {
  return T(1.4142135623730950488016887242096980785696);
}
template <std::floating_point T> inline constexpr T S3() {
  return T(1.7320508075688772935274463415058723669428);
}
template <std::floating_point T> inline constexpr T S5() {
  return T(2.2360679774997896964091736687312762354406);
}

} // namespace Yoth

#endif // YOTH_CONSTANTS_H