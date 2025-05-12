#ifndef YOTH_MACROS_H
#define YOTH_MACROS_H

#include "config.hpp"

namespace Yoth {

#if defined(__CUDACC__)
#define YOTH_HOST_DEVICE __host__ __device__
#else
#define YOTH_HOST_DEVICE
#endif

} // namespace Yoth

#endif // YOTH_MACROS_H