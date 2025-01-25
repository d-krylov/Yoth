#ifndef YOTH_MATRIX_H
#define YOTH_MATRIX_H

#include "vector.h"

namespace Yoth {

template <typename T, int ROWS, int COLUMNS> class Matrix {
public:
  using value_type = T;
  using type = Matrix<T, ROWS, COLUMNS>;

  static constexpr const int SIZE = ROWS * COLUMNS;

  type &operator+=(const type &other) {
    std::ranges::transform(m, other.m, m.begin(), std::plus<>{});
    return *this;
  }

  type &operator-=(const type &other) {
    std::ranges::transform(m, other.m, m.begin(), std::minus<>{});
    return *this;
  }

  type &operator/=(T value) {
    std::ranges::transform(m, m.begin(), [value](T element) { return element / value; });
    return *this;
  }

  type operator+(const type &other) const {
    type r = *this;
    return r += other;
  }

  type operator-(const type &other) const {
    type r = *this;
    return r -= other;
  }

  bool operator==(const type &other) const { return std::ranges::equal(m, other.m); }

  T At(int32_t i, int32_t j) const { return m[COLUMNS * i + j]; }

  T &At(int32_t i, int32_t j) { return m[COLUMNS * i + j]; }

  T Determinant() const
    requires(ROWS == 4 && COLUMNS == 4);

  T Determinant() const
    requires(ROWS == 2 && COLUMNS == 2);

  Matrix<T, COLUMNS, ROWS> Transpose() const;

public:
  std::array<T, SIZE> m;
};

} // namespace Yoth

#include "matrix.ipp"

#endif // YOTH_MATRIX_H