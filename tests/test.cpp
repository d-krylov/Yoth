#include "yoth/common/yoth.h"
#include "gtest/gtest.h"

using namespace Yoth;

// Vector3f

TEST(Vector3f, Basic) {
  Vector3f v1(1.234567f, 2.345678f, 3.456789f);
  Vector3f v2(4.321098f, 5.432109f, 6.543210f);

  Vector3f sum = v1 + v2;
  EXPECT_FLOAT_EQ(sum.x, 1.234567f + 4.321098f);
  EXPECT_FLOAT_EQ(sum.y, 2.345678f + 5.432109f);
  EXPECT_FLOAT_EQ(sum.z, 3.456789f + 6.543210f);

  Vector3f diff = v1 - v2;
  EXPECT_FLOAT_EQ(diff.x, 1.234567f - 4.321098f);
  EXPECT_FLOAT_EQ(diff.y, 2.345678f - 5.432109f);
  EXPECT_FLOAT_EQ(diff.z, 3.456789f - 6.543210f);

  Vector3f neg = -v1;
  EXPECT_FLOAT_EQ(neg.x, -1.234567f);
  EXPECT_FLOAT_EQ(neg.y, -2.345678f);
  EXPECT_FLOAT_EQ(neg.z, -3.456789f);

  Vector3f scaled = v1 * 2.0f;
  EXPECT_FLOAT_EQ(scaled.x, 1.234567f * 2.0f);
  EXPECT_FLOAT_EQ(scaled.y, 2.345678f * 2.0f);
  EXPECT_FLOAT_EQ(scaled.z, 3.456789f * 2.0f);

  Vector3f divided = v1 / 2.0f;
  EXPECT_FLOAT_EQ(divided.x, 1.234567f / 2.0f);
  EXPECT_FLOAT_EQ(divided.y, 2.345678f / 2.0f);
  EXPECT_FLOAT_EQ(divided.z, 3.456789f / 2.0f);

  Vector3f v3 = v1;

  v3 += v2;
  EXPECT_FLOAT_EQ(v3.x, 1.234567f + 4.321098f);
  EXPECT_FLOAT_EQ(v3.y, 2.345678f + 5.432109f);
  EXPECT_FLOAT_EQ(v3.z, 3.456789f + 6.543210f);

  v3 = v1;
  v3 -= v2;

  EXPECT_FLOAT_EQ(v3.x, 1.234567f - 4.321098f);
  EXPECT_FLOAT_EQ(v3.y, 2.345678f - 5.432109f);
  EXPECT_FLOAT_EQ(v3.z, 3.456789f - 6.543210f);

  v3 = v1;
  v3 *= 2.0f;
  EXPECT_FLOAT_EQ(v3.x, 1.234567f * 2.0f);
  EXPECT_FLOAT_EQ(v3.y, 2.345678f * 2.0f);
  EXPECT_FLOAT_EQ(v3.z, 3.456789f * 2.0f);

  v3 = v1;
  v3 /= 2.0f;
  EXPECT_FLOAT_EQ(v3.x, 1.234567f / 2.0f);
  EXPECT_FLOAT_EQ(v3.y, 2.345678f / 2.0f);
  EXPECT_FLOAT_EQ(v3.z, 3.456789f / 2.0f);

  Vector3f v4(1.234567f, 2.345678f, 3.456789f);
  EXPECT_TRUE(v1 == v4);
  EXPECT_TRUE(v1 != v2);
  EXPECT_FALSE(v1 == v2);
}

TEST(Vector3f, ComponentAccess) {
  Vector3f v(1.234567f, 2.345678f, 3.456789f);

  Vector2f expected_xy(1.234567f, 2.345678f);
  Vector2f expected_yz(2.345678f, 3.456789f);
  Vector2f expected_xz(1.234567f, 3.456789f);

  EXPECT_EQ(v.xy(), expected_xy);
  EXPECT_EQ(v.yz(), expected_yz);
  EXPECT_EQ(v.xz(), expected_xz);
}

TEST(Vector3, MathFunctions) {
  Vector3f a(1.25f, -2.75f, 3.5f);
  Vector3f b(-4.125f, 5.625f, -6.875f);

  // Min
  Vector3f min = Min(a, b);
  EXPECT_FLOAT_EQ(min.x, std::fmin(a.x, b.x));
  EXPECT_FLOAT_EQ(min.y, std::fmin(a.y, b.y));
  EXPECT_FLOAT_EQ(min.z, std::fmin(a.z, b.z));

  // Max
  Vector3f max = Max(a, b);
  EXPECT_FLOAT_EQ(max.x, std::fmax(a.x, b.x));
  EXPECT_FLOAT_EQ(max.y, std::fmax(a.y, b.y));
  EXPECT_FLOAT_EQ(max.z, std::fmax(a.z, b.z));

  // Clamp
  Vector3f low(-1.0f, -1.0f, -1.0f);
  Vector3f high(2.0f, 2.0f, 2.0f);

  Vector3f clamped = Clamp(a, low, high);

  EXPECT_FLOAT_EQ(clamped.x, std::fmax(low.x, std::fmin(a.x, high.x)));
  EXPECT_FLOAT_EQ(clamped.y, std::fmax(low.y, std::fmin(a.y, high.y)));
  EXPECT_FLOAT_EQ(clamped.z, std::fmax(low.z, std::fmin(a.z, high.z)));

  // Ceil
  Vector3f ceil = Ceil(a);

  EXPECT_FLOAT_EQ(ceil.x, std::ceil(a.x));
  EXPECT_FLOAT_EQ(ceil.y, std::ceil(a.y));
  EXPECT_FLOAT_EQ(ceil.z, std::ceil(a.z));

  // Floor
  Vector3f floor = Floor(a);
  EXPECT_FLOAT_EQ(floor.x, std::floor(a.x));
  EXPECT_FLOAT_EQ(floor.y, std::floor(a.y));
  EXPECT_FLOAT_EQ(floor.z, std::floor(a.z));

  // Abs
  Vector3f abs = Abs(b);
  EXPECT_FLOAT_EQ(abs.x, std::fabs(b.x));
  EXPECT_FLOAT_EQ(abs.y, std::fabs(b.y));
  EXPECT_FLOAT_EQ(abs.z, std::fabs(b.z));

  // LengthSquared
  float expected_length2 = a.x * a.x + a.y * a.y + a.z * a.z;

  EXPECT_FLOAT_EQ(LengthSquared(a), expected_length2);

  // Dot
  float expected_dot = a.x * b.x + a.y * b.y + a.z * b.z;

  EXPECT_FLOAT_EQ(Dot(a, b), expected_dot);

  // Cross
  Vector3f cross = Cross(a, b);
  EXPECT_FLOAT_EQ(cross.x, a.y * b.z - a.z * b.y);
  EXPECT_FLOAT_EQ(cross.y, a.z * b.x - a.x * b.z);
  EXPECT_FLOAT_EQ(cross.z, a.x * b.y - a.y * b.x);
}

TEST(Point3, AllOperators) {
  Point3f p(1.25f, -2.75f, 3.5f);
  Vector3f v(0.5f, -1.5f, 2.25f);

  // Copy for += and -= tests
  Point3f p_add = p;
  Point3f p_sub = p;

  // Point + Vector = Point
  Point3f p1 = p + v;
  EXPECT_FLOAT_EQ(p1.x, p.x + v.x);
  EXPECT_FLOAT_EQ(p1.y, p.y + v.y);
  EXPECT_FLOAT_EQ(p1.z, p.z + v.z);

  // Point - Vector = Point
  Point3f p2 = p - v;
  EXPECT_FLOAT_EQ(p2.x, p.x - v.x);
  EXPECT_FLOAT_EQ(p2.y, p.y - v.y);
  EXPECT_FLOAT_EQ(p2.z, p.z - v.z);

  // Point - Point = Vector
  Point3f p3(4.75f, 0.0f, -1.25f);

  Vector3f d = p3 - p;
  EXPECT_FLOAT_EQ(d.x, p3.x - p.x);
  EXPECT_FLOAT_EQ(d.y, p3.y - p.y);
  EXPECT_FLOAT_EQ(d.z, p3.z - p.z);

  // Compound +=
  p_add += v;
  EXPECT_FLOAT_EQ(p_add.x, p.x + v.x);
  EXPECT_FLOAT_EQ(p_add.y, p.y + v.y);
  EXPECT_FLOAT_EQ(p_add.z, p.z + v.z);

  // Compound -=
  p_sub -= v;
  EXPECT_FLOAT_EQ(p_sub.x, p.x - v.x);
  EXPECT_FLOAT_EQ(p_sub.y, p.y - v.y);
  EXPECT_FLOAT_EQ(p_sub.z, p.z - v.z);

  Point3f a(1.25f, -3.75f, 0.5f);
  Point3f b(-2.5f, 4.125f, 1.75f);
  Point3f c(3.0f, 0.625f, -2.25f);

  Point3f sum = a + b + c;

  EXPECT_FLOAT_EQ(sum.x, a.x + b.x + c.x);
  EXPECT_FLOAT_EQ(sum.y, a.y + b.y + c.y);
  EXPECT_FLOAT_EQ(sum.z, a.z + b.z + c.z);

  Point3f p4 = p;

  EXPECT_TRUE(p == p4);
  EXPECT_TRUE(p != p3);
  EXPECT_FALSE(p != p4);
}

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

  r += q;

  EXPECT_EQ(r.x, 2.0);
  EXPECT_EQ(r.y, 4.0);
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

  Vector2f v3(-1.0f, -4.0f);

  EXPECT_EQ(Abs(v3), Vector2f(1.0f, 4.0f));

  EXPECT_EQ(Floor(v1), Vector2f(13.0f, 12.0f));
  EXPECT_EQ(Ceil(v1), Vector2f(14.0f, 13.0f));
}

TEST(Vector2d, Operators) {
  Vector2d v1(13.0, 12.0);
  Vector2d v2(14.0, 15.0);
  Vector2f v3(3.0f, 4.0f);

  EXPECT_EQ(LengthSquared(v3), 25.0f);

  EXPECT_EQ(Length(v3), 5.0f);

  EXPECT_EQ(v1 + v2, Vector2d(27.0));
  EXPECT_EQ(v1 - v2, Vector2d(-1.0, -3.0));
  EXPECT_EQ(v1 * v2, Vector2d(182.0, 180.0));
}

TEST(Vector3f, Operators) {
  Vector3f v1(11.712f, 12.737f, 123.567f);
  Vector3f v2(69.829f, 25.621f, 831.412f);

  Vector3f I(-1.0f, -1.0f, -1.0f);
  Vector3f N(0.0f, 1.0f, 0.0f);

  EXPECT_EQ(Dot(I, N), -1.0f);

  auto reflected = Reflect(I, N);

  EXPECT_EQ(reflected.x, -1.0f);
  EXPECT_EQ(reflected.y, 1.0f);
  EXPECT_EQ(reflected.z, -1.0f);
}

TEST(Vector4, BasicOperations) {
  Vector4f v1(1.234567f, 2.345678f, 3.456789f, 4.567890f);
  Vector4f v2(0.111111f, 0.222222f, 0.333333f, 0.444444f);

  Vector4f sum = v1 + v2;

  EXPECT_FLOAT_EQ(sum.x, v1.x + v2.x);
  EXPECT_FLOAT_EQ(sum.y, v1.y + v2.y);
  EXPECT_FLOAT_EQ(sum.z, v1.z + v2.z);
  EXPECT_FLOAT_EQ(sum.w, v1.w + v2.w);

  Vector4f diff = v1 - v2;

  EXPECT_FLOAT_EQ(diff.x, v1.x - v2.x);
  EXPECT_FLOAT_EQ(diff.y, v1.y - v2.y);
  EXPECT_FLOAT_EQ(diff.z, v1.z - v2.z);
  EXPECT_FLOAT_EQ(diff.w, v1.w - v2.w);

  Vector4f neg = -v1;

  EXPECT_FLOAT_EQ(neg.x, -v1.x);
  EXPECT_FLOAT_EQ(neg.y, -v1.y);
  EXPECT_FLOAT_EQ(neg.z, -v1.z);
  EXPECT_FLOAT_EQ(neg.w, -v1.w);

  float scalar = 2.0f;

  Vector4f mul = v1 * scalar;

  EXPECT_FLOAT_EQ(mul.x, v1.x * scalar);
  EXPECT_FLOAT_EQ(mul.y, v1.y * scalar);
  EXPECT_FLOAT_EQ(mul.z, v1.z * scalar);
  EXPECT_FLOAT_EQ(mul.w, v1.w * scalar);

  Vector4f div = v1 / scalar;

  EXPECT_FLOAT_EQ(div.x, v1.x / scalar);
  EXPECT_FLOAT_EQ(div.y, v1.y / scalar);
  EXPECT_FLOAT_EQ(div.z, v1.z / scalar);
  EXPECT_FLOAT_EQ(div.w, v1.w / scalar);

  Vector4f v3 = v1;

  v3 += v2;

  EXPECT_FLOAT_EQ(v3.x, v1.x + v2.x);
  EXPECT_FLOAT_EQ(v3.y, v1.y + v2.y);
  EXPECT_FLOAT_EQ(v3.z, v1.z + v2.z);
  EXPECT_FLOAT_EQ(v3.w, v1.w + v2.w);

  v3 = v1;
  v3 -= v2;

  EXPECT_FLOAT_EQ(v3.x, v1.x - v2.x);
  EXPECT_FLOAT_EQ(v3.y, v1.y - v2.y);
  EXPECT_FLOAT_EQ(v3.z, v1.z - v2.z);
  EXPECT_FLOAT_EQ(v3.w, v1.w - v2.w);

  v3 = v1;
  v3 *= scalar;

  EXPECT_FLOAT_EQ(v3.x, v1.x * scalar);
  EXPECT_FLOAT_EQ(v3.y, v1.y * scalar);
  EXPECT_FLOAT_EQ(v3.z, v1.z * scalar);
  EXPECT_FLOAT_EQ(v3.w, v1.w * scalar);

  v3 = v1;
  v3 /= scalar;

  EXPECT_FLOAT_EQ(v3.x, v1.x / scalar);
  EXPECT_FLOAT_EQ(v3.y, v1.y / scalar);
  EXPECT_FLOAT_EQ(v3.z, v1.z / scalar);
  EXPECT_FLOAT_EQ(v3.w, v1.w / scalar);

  Vector4f v4(1.234567f, 2.345678f, 3.456789f, 4.567890f);

  EXPECT_TRUE(v1 == v4);
  EXPECT_TRUE(v1 != v2);
  EXPECT_FALSE(v1 == v2);
}

TEST(Core, Operators) {
  EXPECT_FLOAT_EQ((float)InnerProduct(1.1f, 2.2f, 3.3f, 4.4f), 16.94f);
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

TEST(Matrix, Operators) {

  Matrix<int32_t, 2, 3> m{1, 2, 3, 4, 5, 6};
  Matrix<int32_t, 3, 2> t{1, 4, 2, 5, 3, 6};

  EXPECT_EQ(Transpose(m), t);
}
