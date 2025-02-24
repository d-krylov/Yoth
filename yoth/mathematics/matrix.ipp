#ifndef YOTH_MATRIX_IPP
#define YOTH_MATRIX_IPP

#include <optional>

namespace Yoth {

template <typename T> using Matrix4 = Matrix<T, 4, 4>;
template <typename T> using Matrix2 = Matrix<T, 2, 2>;

// clang-format off
template <typename T> inline Matrix4<T> operator*(const Matrix4<T> &m1, const Matrix4<T> &m2) {
  Matrix4<T> result;
  std::ranges::generate(result.m, [&, index = 0]() mutable {
    auto i = index / 4;
    auto j = index % 4;
    ++index;
    return InnerProduct(m1[i, 0], m2[0, j],
                        m1[i, 1], m2[1, j],
                        m1[i, 2], m2[2, j],
                        m1[i, 3], m2[3, j]);
  });
  return result;
}
// clang-format on

template <typename T, int ROWS, int COLUMNS> auto Transpose(const Matrix<T, ROWS, COLUMNS> &m) {
  Matrix<T, COLUMNS, ROWS> result;
  std::ranges::generate(result.m, [&, index = 0]() mutable {
    auto i = index / ROWS;
    auto j = index % ROWS;
    ++index;
    return m[j, i];
  });
  return result;
}

template <typename T> inline T Determinant(const Matrix2<T> &m) {
  return DifferenceOfProducts(m[0, 0], m[1, 1], m[1, 0], m[0, 1]);
}

template <typename T> inline T Determinant(const Matrix4<T> &m) {
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

template <typename T> inline std::optional<Matrix4<T>> Inverse(const Matrix4<T> &m) {
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

  return Matrix4<T>{s * InnerProduct(+m[1, 1], s1, m[1, 3], s3, -m[1, 2], p1),
                    s * InnerProduct(-m[0, 1], s1, m[0, 2], p1, -m[0, 3], s3),
                    s * InnerProduct(+m[3, 1], s4, m[3, 3], p2, -m[3, 2], p4),
                    s * InnerProduct(-m[2, 1], s4, m[2, 2], p4, -m[2, 3], p2),

                    s * InnerProduct(-m[1, 0], s1, m[1, 2], p3, -m[1, 3], p5),
                    s * InnerProduct(+m[0, 0], s1, m[0, 3], p5, -m[0, 2], p3),
                    s * InnerProduct(-m[3, 0], s4, m[3, 2], s2, -m[3, 3], p0),
                    s * InnerProduct(+m[2, 0], s4, m[2, 3], p0, -m[2, 2], s2),

                    s * InnerProduct(+m[1, 0], p1, m[1, 3], s5, -m[1, 1], p3),
                    s * InnerProduct(-m[0, 0], p1, m[0, 1], p3, -m[0, 3], s5),
                    s * InnerProduct(+m[3, 0], p4, m[3, 3], s0, -m[3, 1], s2),
                    s * InnerProduct(-m[2, 0], p4, m[2, 1], s2, -m[2, 3], s0),

                    s * InnerProduct(-m[1, 0], s3, m[1, 1], p5, -m[1, 2], s5),
                    s * InnerProduct(+m[0, 0], s3, m[0, 2], s5, -m[0, 1], p5),
                    s * InnerProduct(-m[3, 0], p2, m[3, 1], p0, -m[3, 2], s0),
                    s * InnerProduct(+m[2, 0], p2, m[2, 2], s0, -m[2, 1], p0)};
}

} // namespace Yoth

#endif // YOTH_MATRIX_IPP