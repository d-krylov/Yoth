#include "yoth/common/yoth.h"
#include "gtest/gtest.h"

using namespace Yoth;

void ExpectMatrixNear(const Matrix4f &actual, const Matrix4f &expected, float epsilon = 1e-5f) {
  for (int row = 0; row < 4; ++row) {
    for (int col = 0; col < 4; ++col) {
      EXPECT_NEAR(actual.At(row, col), expected.At(row, col), epsilon);
    }
  }
}

TEST(Matrix4f, Determinant) {
  Matrix4f m1{1.5f, 2.3f, 3.7f, 4.1f, 0.5f, 1.9f, 2.8f, 3.0f, 1.2f, 0.4f, 0.9f, 2.2f, 3.3f, 1.1f, 2.6f, 0.8f};
  Matrix4f m2{2.0f, 1.0f, 3.0f, 4.0f, 0.0f, 1.0f, 2.0f, 3.0f, 1.0f, 0.0f, 4.0f, 2.0f, 5.0f, 2.0f, 1.0f, 0.0f};
  Matrix4f m3{3.1f, 0.2f, 1.5f, 4.2f, 2.3f, 3.4f, 0.1f, 1.0f, 1.1f, 0.5f, 2.2f, 3.3f, 4.0f, 1.1f, 1.2f, 0.3f};
  Matrix4f m4{1.0f, 2.0f, 3.0f, 4.0f, 2.0f, 4.0f, 6.0f, 8.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f};
  Matrix4f m5{0.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 0.01f, 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f};
  Matrix4f m6{1.5f, 2.7f, 4.3f, 6.9f, 5.1f, 3.3f, 2.9f, 5.7f, 1.1f, 2.7f, 9.9f, 9.3f, 2.3f, 5.5f, 6.7f, 1.9f};
  Matrix4f m7{12.345f, 67.89f, 0.123f, 4.567f, 8.910f, 1.112f, 3.141f, 2.718f,
              6.283f,  5.555f, 4.444f, 3.333f, 2.222f, 1.111f, 0.999f, 8.888f};

  EXPECT_NEAR(Determinant(m1), 0.408f, 1e-4f);
  EXPECT_NEAR(Determinant(m2), -43.0f, 1e-4f);
  EXPECT_NEAR(Determinant(m3), -73.044f, 1e-3f);
  EXPECT_NEAR(Determinant(m4), 0.0f, 1e-4f);
  EXPECT_NEAR(Determinant(m5), 0.0242f, 1e-4f);
  EXPECT_NEAR(Determinant(m7), -12064.0336f, 1e-3f);
  EXPECT_FLOAT_EQ(Determinant(m6), 551.6448f);
}

TEST(Matrix4f, Inverse) {
  Matrix4f m1{0.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 0.01f, 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f};
  Matrix4f m2{12.345f, 67.89f, 0.123f, 4.567f, 8.910f, 1.112f, 3.141f, 2.718f,
              6.283f,  5.555f, 4.444f, 3.333f, 2.222f, 1.111f, 0.999f, 8.888f};

  auto i1 = Inverse(m1);
  EXPECT_EQ(i1.has_value(), true);
  ExpectMatrixNear(m1 * i1.value(), Identity<float, 4>(), 1e-2f);

  auto i2 = Inverse(m2);
  EXPECT_EQ(i2.has_value(), true);
  ExpectMatrixNear(m2 * i2.value(), Identity<float, 4>(), 1e-2f);

  Matrix4f m3{1.5f, 2.7f, 4.3f, 6.9f, 5.1f, 3.3f, 2.9f, 5.7f, 1.1f, 2.7f, 9.9f, 9.3f, 2.3f, 5.5f, 6.7f, 1.9f};
  Matrix4f e3{-0.39399266f, +0.30898143f, +0.11259419f, -0.04724779f, +0.45982487f, -0.16046557f, -0.28176827f, +0.19068792f,
              -0.31165707f, +0.0326732f,  +0.20445765f, +0.03302125f, +0.24486771f, -0.02474056f, -0.04163549f, -0.08492421f};

  auto i3 = Inverse(m3);

  EXPECT_EQ(i3.has_value(), true);

  ExpectMatrixNear(i3.value(), e3, 1e-7f);
}

TEST(Matrix4f, Multiplication) {
  Matrix4f m1{1.5f, 2.7f, 4.3f, 6.9f, 5.1f, 3.3f, 2.9f, 5.7f, 1.1f, 2.7f, 9.9f, 9.3f, 2.3f, 5.5f, 6.7f, 1.9f};
  Matrix4f e1{36.62f, 62.52f, 103.08f, 78.84f,  40.78f, 63.84f, 98.4f,  91.8f,
              47.7f,  89.76f, 172.88f, 132.72f, 43.24f, 52.9f,  104.9f, 113.14f};

  Matrix4f a{1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 0.1f, 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f};
  Matrix4f b{7.1f, 6.2f, 5.3f, 4.4f, 3.5f, 2.6f, 1.7f, 0.8f, 9.9f, 8.0f, 7.1f, 6.2f, 5.3f, 4.4f, 3.5f, 2.6f};
  Matrix4f e2{71.5, 58.3, 48.4, 38.5, 185.02, 151.58, 125.84, 100.1, 94.71, 81.36, 69.21, 57.06, 130.84, 107.06, 88.88, 70.7};

  ExpectMatrixNear(m1 * m1, e1, 1e-3f);
  ExpectMatrixNear(a * b, e2, 1e-4f);
}

TEST(MatrixTransformTests, CompositeTransformOrderMatters) {

  Vector4f point(1.0f, 0.0f, 0.0f, 1.0f);

  Matrix4f scale = Scale(2.0f, 2.0f, 2.0f);
  Matrix4f rotate = RotateX(90.0f);
  Matrix4f translate = Translate(Vector3f(0.0f, 1.0f, 0.0f));

  Matrix4f transform = translate * rotate * scale;
  Vector4f result = Multiply(transform, point);

  EXPECT_NEAR(result.x, 2.0f, 1e-5f);
  EXPECT_NEAR(result.y, 1.0f, 1e-5f);
  EXPECT_NEAR(result.z, 0.0f, 1e-5f);
  EXPECT_NEAR(result.w, 1.0f, 1e-5f);
}

TEST(Matrix, Operators) {

  Matrix<int32_t, 2, 3> m{1, 2, 3, 4, 5, 6};
  Matrix<int32_t, 3, 2> t{1, 4, 2, 5, 3, 6};

  EXPECT_EQ(Transpose(m), t);
}

TEST(Matrix4, Operators) {
  Matrix4i m1{1, 2, 4, 3, 6, 8, 5, 4, 1, 7, 2, 5, 4, 9, 8, 6};
  Matrix4i m2{1, 2, 4, 3, 6, 8, 5, 4, 1, 7, 2, 5, 4, 9, 8, 6};

  Matrix4i m3 = m1 * m2;

  Matrix4i m4{29, 73, 46, 49, 75, 147, 106, 99, 65, 117, 83, 71, 90, 190, 125, 124};

  EXPECT_EQ(m1, m2);
  EXPECT_EQ(m3, m4);

  EXPECT_EQ(Determinant(m1), -188);
}