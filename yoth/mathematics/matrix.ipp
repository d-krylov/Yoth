#ifndef YOTH_MATRIX_IPP
#define YOTH_MATRIX_IPP

namespace Yoth {

template <typename T, int ROWS, int COLUMNS>
T Matrix<T, ROWS, COLUMNS>::Determinant() const
  requires(ROWS == 4 && COLUMNS == 4)
{
  auto s0 = DifferenceOfProducts(m[0], m[5], m[1], m[4]);
  auto s1 = DifferenceOfProducts(m[10], m[15], m[11], m[14]);
  auto p0 = DifferenceOfProducts(m[0], m[6], m[2], m[4]);
  auto p1 = DifferenceOfProducts(m[9], m[15], m[11], m[13]);
  auto s2 = DifferenceOfProducts(m[0], m[7], m[3], m[4]);
  auto s3 = DifferenceOfProducts(m[9], m[14], m[10], m[13]);
  auto p2 = DifferenceOfProducts(m[1], m[6], m[2], m[5]);
  auto p3 = DifferenceOfProducts(m[8], m[15], m[11], m[12]);
  auto s4 = DifferenceOfProducts(m[2], m[7], m[3], m[6]);
  auto s5 = DifferenceOfProducts(m[8], m[13], m[9], m[12]);
  auto p4 = DifferenceOfProducts(m[1], m[7], m[3], m[5]);
  auto p5 = DifferenceOfProducts(m[8], m[14], m[10], m[12]);

  return DifferenceOfProducts(s0, s1, p0, p1) + SumOfProducts(s2, s3, p2, p3) +
         DifferenceOfProducts(s4, s5, p4, p5);
}

template <typename T, int ROWS, int COLUMNS>
T Matrix<T, ROWS, COLUMNS>::Determinant() const
  requires(ROWS == 2 && COLUMNS == 2)
{
  return DifferenceOfProducts(m[0], m[3], m[1], m[2]);
}

} // namespace Yoth

#endif // YOTH_MATRIX_IPP