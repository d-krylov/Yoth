#include "yoth/common/yoth.h"
#include "gtest/gtest.h"

using namespace Yoth;

template <typename Vec, typename T> void ExpectVec2Equal(const Vec &v, T x, T y) {
  if constexpr (std::same_as<T, float>) {
    EXPECT_FLOAT_EQ(v.x, x);
    EXPECT_FLOAT_EQ(v.y, y);
  } else if constexpr (std::same_as<T, double>) {
    EXPECT_DOUBLE_EQ(v.x, x);
    EXPECT_DOUBLE_EQ(v.y, y);
  } else {
    EXPECT_EQ(v.x, x);
    EXPECT_EQ(v.y, y);
  }
}

template <typename Vec, typename T> void ExpectVec3Equal(const Vec &v, T x, T y, T z) {
  if constexpr (std::same_as<T, float>) {
    EXPECT_FLOAT_EQ(v.x, x);
    EXPECT_FLOAT_EQ(v.y, y);
    EXPECT_FLOAT_EQ(v.z, z);
  } else if constexpr (std::same_as<T, double>) {
    EXPECT_DOUBLE_EQ(v.x, x);
    EXPECT_DOUBLE_EQ(v.y, y);
    EXPECT_DOUBLE_EQ(v.z, z);
  } else {
    EXPECT_EQ(v.x, x);
    EXPECT_EQ(v.y, y);
    EXPECT_EQ(v.z, z);
  }
}

template <typename Vec, typename T> void ExpectVec4Equal(const Vec &v, T x, T y, T z, T w) {
  if constexpr (std::same_as<T, float>) {
    EXPECT_FLOAT_EQ(v.x, x);
    EXPECT_FLOAT_EQ(v.y, y);
    EXPECT_FLOAT_EQ(v.z, z);
    EXPECT_FLOAT_EQ(v.w, w);
  } else if constexpr (std::same_as<T, double>) {
    EXPECT_DOUBLE_EQ(v.x, x);
    EXPECT_DOUBLE_EQ(v.y, y);
    EXPECT_DOUBLE_EQ(v.z, z);
    EXPECT_DOUBLE_EQ(v.w, w);
  } else {
    EXPECT_EQ(v.x, x);
    EXPECT_EQ(v.y, y);
    EXPECT_EQ(v.z, z);
    EXPECT_EQ(v.w, z);
  }
}

TEST(Vector3Test, Constructors) {
  Vector3f v1, q1(1.1f), r1(1.1f, 2.2f, 3.3f);
  ExpectVec3Equal(v1, 0.0f, 0.0f, 0.0f);
  ExpectVec3Equal(q1, 1.1f, 1.1f, 1.1f);
  ExpectVec3Equal(r1, 1.1f, 2.2f, 3.3f);
  Vector4f v2(r1, 4.4f), q2(4.4f, r1);
  ExpectVec4Equal(v2, 1.1f, 2.2f, 3.3f, 4.4f);
  ExpectVec4Equal(q2, 4.4f, 1.1f, 2.2f, 3.3f);
}

TEST(VectorSwizzleTest, SwizzleAccessors) {
  Vector3f v3(1.0f, 2.0f, 3.0f);
  Vector4f v4(4.0f, 5.0f, 6.0f, 7.0f);

  ExpectVec2Equal(v3.xy(), 1.0f, 2.0f);
  ExpectVec2Equal(v3.yz(), 2.0f, 3.0f);
  ExpectVec2Equal(v3.xz(), 1.0f, 3.0f);

  ExpectVec3Equal(v4.xyz(), 4.0f, 5.0f, 6.0f);
  ExpectVec3Equal(v4.yzw(), 5.0f, 6.0f, 7.0f);
  ExpectVec3Equal(v4.xyw(), 4.0f, 5.0f, 7.0f);
  ExpectVec3Equal(v4.xzw(), 4.0f, 6.0f, 7.0f);
}

TEST(Vector3f, Basic) {
  Vector3f v1(1.234567f, 2.345678f, 3.456789f);
  Vector3f v2(4.321098f, 5.432109f, 6.543210f);

  Vector3f sum = v1 + v2;
  Vector3f diff = v1 - v2;
  Vector3f neg = -v1;
  Vector3f scaled = v1 * 2.0f;
  Vector3f divided = v1 / 2.0f;
  ExpectVec3Equal(sum, 1.234567f + 4.321098f, 2.345678f + 5.432109f, 3.456789f + 6.543210f);
  ExpectVec3Equal(diff, 1.234567f - 4.321098f, 2.345678f - 5.432109f, 3.456789f - 6.543210f);
  ExpectVec3Equal(neg, -1.234567f, -2.345678f, -3.456789f);
  ExpectVec3Equal(scaled, 1.234567f * 2.0f, 2.345678f * 2.0f, 3.456789f * 2.0f);
  ExpectVec3Equal(divided, 1.234567f / 2.0f, 2.345678f / 2.0f, 3.456789f / 2.0f);

  Vector3f v3 = v1;
  v3 += v2;
  ExpectVec3Equal(v3, 1.234567f + 4.321098f, 2.345678f + 5.432109f, 3.456789f + 6.543210f);

  v3 = v1, v3 -= v2;
  ExpectVec3Equal(v3, 1.234567f - 4.321098f, 2.345678f - 5.432109f, 3.456789f - 6.543210f);

  v3 = v1, v3 *= 2.0f;
  ExpectVec3Equal(v3, 1.234567f * 2.0f, 2.345678f * 2.0f, 3.456789f * 2.0f);

  v3 = v1, v3 /= 2.0f;
  ExpectVec3Equal(v3, 1.234567f / 2.0f, 2.345678f / 2.0f, 3.456789f / 2.0f);

  Vector3f v4(1.234567f, 2.345678f, 3.456789f);

  EXPECT_TRUE(v1 == v4);
  EXPECT_TRUE(v1 != v2);
  EXPECT_FALSE(v1 == v2);
}