#ifndef YOTH_MATRIX_IPP
#define YOTH_MATRIX_IPP

#include <optional>

namespace Yoth {

template <typename T>
using Matrix4 = Matrix<T, 4, 4>;
template <typename T>
using Matrix2 = Matrix<T, 2, 2>;

template <typename T>
YOTH_HOST_DEVICE inline Matrix4<T> operator*(const Matrix4<T> &m1, const Matrix4<T> &m2) {
  Matrix4<T> out;
  for (auto i = 0; i < 4; ++i) {
    for (auto j = 0; j < 4; ++j) {
      out[i, j] = InnerProduct(m1[i, 0], m2[0, j], m1[i, 1], m2[1, j], m1[i, 2], m2[2, j], m1[i, 3], m2[3, j]);
    }
  }
  return out;
}

template <typename T, int ROWS, int COLUMNS>
YOTH_HOST_DEVICE auto Transpose(const Matrix<T, ROWS, COLUMNS> &m) {
  Matrix<T, COLUMNS, ROWS> out;
  for (int i = 0; i < COLUMNS; ++i) {
    for (int j = 0; j < ROWS; ++j) {
      out[i, j] = m[j, i];
    }
  }
  return out;
}

template <typename T, int N>
YOTH_HOST_DEVICE auto Identity() {
  Matrix<T, N, N> matrix;
  for (auto i = 0; i < N; ++i) {
    matrix[i, i] = T{1};
  }
  return matrix;
}

template <typename T, int ROWS, int COLUMNS, IsVectorType V>
YOTH_HOST_DEVICE inline auto Multiply(const Matrix<T, ROWS, COLUMNS> &m, const V &v) {
  static_assert(COLUMNS == V::size, "Matrix/vector size mismatch in Multiply");
  V out;
  for (auto i = 0; i < ROWS; ++i) {
    out[i] = 0;
    for (auto j = 0; j < COLUMNS; ++j)
      out[i] += m[i, j] * v[j];
  }
  return out;
}

template <typename T>
YOTH_HOST_DEVICE inline T Determinant(const Matrix2<T> &m) {
  return DifferenceOfProducts(m[0, 0], m[1, 1], m[1, 0], m[0, 1]);
}

template <typename T>
YOTH_HOST_DEVICE inline T Determinant(const Matrix4<T> &m) {
  auto s0 = DifferenceOfProducts(m[0, 0], m[1, 1], m[0, 1], m[1, 0]);
  auto s1 = DifferenceOfProducts(m[2, 2], m[3, 3], m[2, 3], m[3, 2]);
  auto p0 = DifferenceOfProducts(m[0, 0], m[1, 2], m[0, 2], m[1, 0]);
  auto p1 = DifferenceOfProducts(m[2, 1], m[3, 3], m[2, 3], m[3, 1]);
  auto s2 = DifferenceOfProducts(m[0, 0], m[1, 3], m[0, 3], m[1, 0]);
  auto s3 = DifferenceOfProducts(m[2, 1], m[3, 2], m[2, 2], m[3, 1]);
  auto p2 = DifferenceOfProducts(m[0, 1], m[1, 2], m[0, 2], m[1, 1]);
  auto p3 = DifferenceOfProducts(m[2, 0], m[3, 3], m[2, 3], m[3, 0]);
  auto s4 = DifferenceOfProducts(m[0, 2], m[1, 3], m[0, 3], m[1, 2]);
  auto s5 = DifferenceOfProducts(m[2, 0], m[3, 1], m[2, 1], m[3, 0]);
  auto p4 = DifferenceOfProducts(m[0, 1], m[1, 3], m[0, 3], m[1, 1]);
  auto p5 = DifferenceOfProducts(m[2, 0], m[3, 2], m[2, 2], m[3, 0]);

  return DifferenceOfProducts(s0, s1, p0, p1) + SumOfProducts(s2, s3, p2, p3) + DifferenceOfProducts(s4, s5, p4, p5);
}

template <typename T>
inline std::optional<Matrix4<T>> Inverse(const Matrix4<T> &m) {
  auto s0 = DifferenceOfProducts(m[0, 0], m[1, 1], m[0, 1], m[1, 0]);
  auto s1 = DifferenceOfProducts(m[2, 2], m[3, 3], m[2, 3], m[3, 2]);
  auto p0 = DifferenceOfProducts(m[0, 0], m[1, 2], m[0, 2], m[1, 0]);
  auto p1 = DifferenceOfProducts(m[2, 1], m[3, 3], m[2, 3], m[3, 1]);
  auto s2 = DifferenceOfProducts(m[0, 0], m[1, 3], m[0, 3], m[1, 0]);
  auto s3 = DifferenceOfProducts(m[2, 1], m[3, 2], m[2, 2], m[3, 1]);
  auto p2 = DifferenceOfProducts(m[0, 1], m[1, 2], m[0, 2], m[1, 1]);
  auto p3 = DifferenceOfProducts(m[2, 0], m[3, 3], m[2, 3], m[3, 0]);
  auto s4 = DifferenceOfProducts(m[0, 2], m[1, 3], m[0, 3], m[1, 2]);
  auto s5 = DifferenceOfProducts(m[2, 0], m[3, 1], m[2, 1], m[3, 0]);
  auto p4 = DifferenceOfProducts(m[0, 1], m[1, 3], m[0, 3], m[1, 1]);
  auto p5 = DifferenceOfProducts(m[2, 0], m[3, 2], m[2, 2], m[3, 0]);

  auto D = DifferenceOfProducts(s0, s1, p0, p1) + SumOfProducts(s2, s3, p2, p3) + DifferenceOfProducts(s4, s5, p4, p5);

  if (D == 0) {
    return std::nullopt;
  }

  auto s = 1 / D;

  return Matrix4<T>{
    s * InnerProduct(+m[1, 1], s1, m[1, 3], s3, -m[1, 2], p1), //
    s * InnerProduct(-m[0, 1], s1, m[0, 2], p1, -m[0, 3], s3), //
    s * InnerProduct(+m[3, 1], s4, m[3, 3], p2, -m[3, 2], p4), //
    s * InnerProduct(-m[2, 1], s4, m[2, 2], p4, -m[2, 3], p2), //

    s * InnerProduct(-m[1, 0], s1, m[1, 2], p3, -m[1, 3], p5), //
    s * InnerProduct(+m[0, 0], s1, m[0, 3], p5, -m[0, 2], p3), //
    s * InnerProduct(-m[3, 0], s4, m[3, 2], s2, -m[3, 3], p0), //
    s * InnerProduct(+m[2, 0], s4, m[2, 3], p0, -m[2, 2], s2), //

    s * InnerProduct(+m[1, 0], p1, m[1, 3], s5, -m[1, 1], p3), //
    s * InnerProduct(-m[0, 0], p1, m[0, 1], p3, -m[0, 3], s5), //
    s * InnerProduct(+m[3, 0], p4, m[3, 3], s0, -m[3, 1], s2), //
    s * InnerProduct(-m[2, 0], p4, m[2, 1], s2, -m[2, 3], s0), //

    s * InnerProduct(-m[1, 0], s3, m[1, 1], p5, -m[1, 2], s5), //
    s * InnerProduct(+m[0, 0], s3, m[0, 2], s5, -m[0, 1], p5), //
    s * InnerProduct(-m[3, 0], p2, m[3, 1], p0, -m[3, 2], s0), //
    s * InnerProduct(+m[2, 0], p2, m[2, 2], s0, -m[2, 1], p0)  //
  };
}

} // namespace Yoth

#endif // YOTH_MATRIX_IPP