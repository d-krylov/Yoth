#ifndef YOTH_MATRIX_IPP
#define YOTH_MATRIX_IPP

namespace Yoth {

template <typename T, int ROWS, int COLUMNS>
T Matrix<T, ROWS, COLUMNS>::Determinant() const
  requires(ROWS == 4 && COLUMNS == 4)
{
  auto s0 = DifferenceOfProducts(At(0, 0), At(1, 1), At(0, 1), At(1, 0));
  auto s1 = DifferenceOfProducts(At(2, 2), At(3, 3), At(2, 3), At(3, 2));
  auto p0 = DifferenceOfProducts(At(0, 0), At(1, 2), At(0, 2), At(1, 0));
  auto p1 = DifferenceOfProducts(At(2, 1), At(3, 3), At(2, 3), At(3, 1));
  auto s2 = DifferenceOfProducts(At(0, 0), At(1, 3), At(0, 3), At(1, 0));
  auto s3 = DifferenceOfProducts(At(2, 1), At(3, 2), At(2, 2), At(3, 1));
  auto p2 = DifferenceOfProducts(At(0, 1), At(1, 2), At(0, 2), At(1, 1));
  auto p3 = DifferenceOfProducts(At(2, 0), At(3, 3), At(2, 3), At(3, 0));
  auto s4 = DifferenceOfProducts(At(0, 2), At(1, 3), At(0, 3), At(1, 2));
  auto s5 = DifferenceOfProducts(At(2, 0), At(3, 1), At(2, 1), At(3, 0));
  auto p4 = DifferenceOfProducts(At(0, 1), At(1, 3), At(0, 3), At(1, 1));
  auto p5 = DifferenceOfProducts(At(2, 0), At(3, 2), At(2, 2), At(3, 0));

  return DifferenceOfProducts(s0, s1, p0, p1) + SumOfProducts(s2, s3, p2, p3) +
         DifferenceOfProducts(s4, s5, p4, p5);
}

template <typename T, int ROWS, int COLUMNS>
T Matrix<T, ROWS, COLUMNS>::Determinant() const
  requires(ROWS == 2 && COLUMNS == 2)
{
  return DifferenceOfProducts(m[0], m[3], m[1], m[2]);
}

// clang-format off
template <typename T>
inline Matrix<T, 4, 4> operator*(const Matrix<T, 4, 4> &m1, const Matrix<T, 4, 4> &m2) {
  Matrix<T, 4, 4> result;
  for (auto i = 0; i < 4; ++i) {
    for (auto j = 0; j < 4; ++j) {
      result.At(i, j) = InnerProduct(m1.At(i, 0), m2.At(0, j), m1.At(i, 1), m2.At(1, j), 
                                     m1.At(i, 2), m2.At(2, j), m1.At(i, 3), m2.At(3, j));
    }
  }
  return result;
}
// clang-format on

} // namespace Yoth

#endif // YOTH_MATRIX_IPP