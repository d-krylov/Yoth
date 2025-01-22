#include "yoth.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace Yoth;

TEST(Vector2d, Constructors) {
  Vector2d v;

  EXPECT_EQ(v.x, 0.0);
  EXPECT_EQ(v.y, 0.0);
  EXPECT_EQ(v.r, 0.0);
  EXPECT_EQ(v.g, 0.0);
  EXPECT_EQ(v.data[0], 0.0);
  EXPECT_EQ(v.data[1], 0.0);

  Vector2d w(1.0);

  EXPECT_EQ(w.x, 1.0);
  EXPECT_EQ(w.y, 1.0);

  Vector2d q(1.0, 2.0);

  EXPECT_EQ(q.x, 1.0);
  EXPECT_EQ(q.y, 2.0);

  Vector2d r(1.0, 2.0);

  EXPECT_EQ(q, r);
  EXPECT_NE(q, w);
}

TEST(Vector2f, Constructors) {
  Vector2f v;

  EXPECT_EQ(v.x, 0.0f);
  EXPECT_EQ(v.y, 0.0f);
  EXPECT_EQ(v.r, 0.0f);
  EXPECT_EQ(v.g, 0.0f);
  EXPECT_EQ(v.data[0], 0.0f);
  EXPECT_EQ(v.data[1], 0.0f);

  Vector2f w(1.0f);

  EXPECT_EQ(w.x, 1.0f);
  EXPECT_EQ(w.y, 1.0f);

  Vector2f q(1.0f, 2.0f);

  EXPECT_EQ(q.x, 1.0f);
  EXPECT_EQ(q.y, 2.0f);

  Vector2f r(1.0f, 2.0f);

  EXPECT_EQ(q, r);
  EXPECT_NE(q, w);
}

TEST(Vector2f, Operators) {
  Vector2f v1(13.1f, 12.5f);
  Vector2f v2(14.2f, 15.3f);

  EXPECT_EQ(v1 + v2, Vector2f(27.3f, 27.8f));
  EXPECT_EQ(v1 * v2, Vector2f(186.02f, 191.25f));

  Vector2f sub = v1 - v2;

  EXPECT_NEAR(sub.x, -1.1f, 1.0e-5);
  EXPECT_NEAR(sub.y, -2.8f, 1.0e-5);

  EXPECT_EQ(Dot(v1, v2), 377.27f);

  EXPECT_EQ(Min(v1, v2), v1);
  EXPECT_EQ(Max(v1, v2), v2);
  EXPECT_EQ(Floor(v1), Vector2f(13.0f, 12.0f));
  EXPECT_EQ(Ceil(v1), Vector2f(14.0f, 13.0f));
}

TEST(Vector2d, Operators) {
  Vector2d v1(13.0, 12.0);
  Vector2d v2(14.0, 15.0);
  Vector2f v3(3.0f, 4.0f);

  ASSERT_EQ(LengthSquared(v3), 25.0f);

  ASSERT_EQ(Length(v3), 5.0f);

  EXPECT_EQ(v1 + v2, Vector2d(27.0));
  EXPECT_EQ(v1 - v2, Vector2d(-1.0, -3.0));
  EXPECT_EQ(v1 * v2, Vector2d(182.0, 180.0));
}

TEST(Vector3f, Operators) {
  Vector3f v1(11.712f, 12.737f, 123.567f);
  Vector3f v2(69.829f, 25.621f, 831.412f);

  Vector3f I(-1.0f, -1.0f, -1.0f);
  Vector3f N(0.0f, 1.0f, 0.0f);

  ASSERT_EQ(Dot(I, N), -1.0f);

  auto reflected = Reflect(I, N);

  ASSERT_EQ(reflected.x, -1.0f);
  ASSERT_EQ(reflected.y, 1.0f);
  ASSERT_EQ(reflected.z, -1.0f);
}

TEST(Vector4f, Operators) {}

TEST(Matrix4, Operators) {
  Matrix4i m1{1, 2, 4, 3, 6, 8, 5, 4, 1, 7, 2, 5, 4, 9, 8, 6};
  Matrix4i m2{1, 2, 4, 3, 6, 8, 5, 4, 1, 7, 2, 5, 4, 9, 8, 6};

  Matrix4i m3 = m1 * m2;

  Matrix4i m4{29, 73, 46, 49, 75, 147, 106, 99, 65, 117, 83, 71, 90, 190, 125, 124};

  ASSERT_EQ(m1, m2);
  ASSERT_EQ(m3, m4);

  ASSERT_EQ(m1.Determinant(), -188);
}