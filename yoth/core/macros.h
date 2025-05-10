#ifndef YOTH_MACROS_H
#define YOTH_MACROS_H

#if defined(__CUDACC__)
#define YOTH_HOST_DEVICE __host__ __device__
#else
#define YOTH_HOST_DEVICE
#endif

#if defined(YOTH_FLOAT_TYPE_DOUBLE)
using FloatType = double;
#elif defined(YOTH_FLOAT_TYPE_FLOAT)
using FloatType = float;
#else
#error "No float type defined"
#endif

#endif // YOTH_MACROS_H