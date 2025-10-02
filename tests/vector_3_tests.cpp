#include "tests_common.h"

using namespace Yoth;

TYPED_TEST(FloatingTypesTest, MathFunctions) {
  Vector3<TypeParam> a(1.25, -2.75, 3.5);
  Vector3<TypeParam> b(-4.125, 5.625, -6.875);

  EXPECT_VECTOR3_NEAR(Min(a, b), Vector3<TypeParam>(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z)));
  EXPECT_VECTOR3_NEAR(Max(a, b), Vector3<TypeParam>(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z)));

  // Clamp
  Vector3<TypeParam> L(-1.0, -1.0, -1.0);
  Vector3<TypeParam> H(2.0, 2.0, 2.0);

  EXPECT_VECTOR3_NEAR(Clamp(a, L, H), Vector3<TypeParam>(std::clamp(a.x, L.x, H.x), std::clamp(a.y, L.y, H.y), std::clamp(a.z, L.z, H.z)));
  EXPECT_VECTOR3_NEAR(Ceil(a), Vector3<TypeParam>(std::ceil(a.x), std::ceil(a.y), std::ceil(a.z)));

  // Floor
  auto floor = Floor(a);
  EXPECT_FLOAT_EQ(floor.x, std::floor(a.x));
  EXPECT_FLOAT_EQ(floor.y, std::floor(a.y));
  EXPECT_FLOAT_EQ(floor.z, std::floor(a.z));

  // Abs
  auto abs = Abs(b);
  EXPECT_FLOAT_EQ(abs.x, std::fabs(b.x));
  EXPECT_FLOAT_EQ(abs.y, std::fabs(b.y));
  EXPECT_FLOAT_EQ(abs.z, std::fabs(b.z));

  // LengthSquared
  auto expected_length2 = a.x * a.x + a.y * a.y + a.z * a.z;

  EXPECT_FLOAT_EQ(LengthSquared(a), expected_length2);

  // Dot
  float expected_dot = a.x * b.x + a.y * b.y + a.z * b.z;

  EXPECT_FLOAT_EQ(Dot(a, b), expected_dot);

  // Cross
  auto cross = Cross(a, b);
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

TEST(Core, Operators) {
  EXPECT_FLOAT_EQ((float)InnerProduct(1.1f, 2.2f, 3.3f, 4.4f), 16.94f);
}

TEST(Vector3f, DotAndCross) {

  Vector3f v0(1.1f, 2.2f, 3.3f);
  Vector3f v1(4.4f, 5.5f, 6.6f);
  Vector3f v2(-2.7f, 3.8f, -1.5f);
  Vector3f v3(0.6f, -4.2f, 2.3f);
  Vector3f v4(0.123f, 4.567f, 8.910f);
  Vector3f v5(1.314f, 2.718f, 3.141f);

  EXPECT_NEAR(Dot(v0, v1), 1.1f * 4.4f + 2.2f * 5.5f + 3.3f * 6.6f, 1e-5f);
  EXPECT_NEAR(Dot(v2, v3), -2.7f * 0.6f + 3.8f * -4.2f + -1.5f * 2.3f, 1e-5f);
  EXPECT_NEAR(Dot(v4, v5), 0.123f * 1.314f + 4.567f * 2.718f + 8.910f * 3.141f, 1e-5f);

  Vector3f r1 = Cross(v0, v1);
  EXPECT_NEAR(r1.x, 2.2f * 6.6f - 3.3f * 5.5f, 1e-5f);
  EXPECT_NEAR(r1.y, 3.3f * 4.4f - 1.1f * 6.6f, 1e-5f);
  EXPECT_NEAR(r1.z, 1.1f * 5.5f - 2.2f * 4.4f, 1e-5f);

  Vector3f r2 = Cross(v2, v3);
  EXPECT_NEAR(r2.x, 3.8f * 2.3f - (-1.5f) * -4.2f, 1e-5f);
  EXPECT_NEAR(r2.y, -1.5f * 0.6f - (-2.7f) * 2.3f, 1e-5f);
  EXPECT_NEAR(r2.z, -2.7f * -4.2f - 3.8f * 0.6f, 1e-5f);

  Vector3f r3 = Cross(v4, v5);
  EXPECT_NEAR(r3.x, 4.567f * 3.141f - 8.910f * 2.718f, 1e-5f);
  EXPECT_NEAR(r3.y, 8.910f * 1.314f - 0.123f * 3.141f, 1e-5f);
  EXPECT_NEAR(r3.z, 0.123f * 2.718f - 4.567f * 1.314f, 1e-5f);
}
