#ifndef YOTH_MATRIX_H
#define YOTH_MATRIX_H

#include "vector.h"

namespace Yoth {

template <typename T, int ROWS, int COLUMNS> class Matrix {
public:
};

template <typename T> class Matrix<T, 4, 4> {
public:
  // clang-format off
  Matrix(T m00, T m01, T m02, T m03, 
         T m10, T m11, T m12, T m13, 
         T m20, T m21, T m22, T m23, 
         T m30, T m31, T m32, T m33): // clang-format on
      m{m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33} {}

  float Determinant() const;

public:
  // m[0]  m[1]  m[2]  m[3]
  // m[4]  m[5]  m[6]  m[7]
  // m[8]  m[9]  m[10] m[11]
  // m[12] m[13] m[14] m[15]
  // clang-format off
  union {
    struct { Vector4<T> rows[4]; };
    struct { T m[16]; };
  };
  // clang-format on
};

} // namespace Yoth

#include "matrix.ipp"

#endif // YOTH_MATRIX_H