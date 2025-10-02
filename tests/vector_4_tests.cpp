#include "tests_common.h"

using namespace Yoth;

TYPED_TEST(FloatingTypesTest, BasicOperations) {
  Vector4<TypeParam> v1(1.234567, 2.345678, 3.456789, 4.567890);
  Vector4<TypeParam> v2(0.111111, 0.222222, 0.333333, 0.444444);

  EXPECT_VECTOR4_NEAR(v1 + v2, Vector4<TypeParam>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w));
  EXPECT_VECTOR4_NEAR(v1 - v2, Vector4<TypeParam>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w));

  EXPECT_VECTOR4_NEAR(-v1, Vector4<TypeParam>(-v1.x, -v1.y, -v1.z, -v1.w));

  auto s = TypeParam(2.0);

  EXPECT_VECTOR4_NEAR(v1 * s, Vector4<TypeParam>(v1.x * s, v1.y * s, v1.z * s, v1.w * s));
  EXPECT_VECTOR4_NEAR(v1 / s, Vector4<TypeParam>(v1.x / s, v1.y / s, v1.z / s, v1.w / s));

  auto v3 = v1;
  EXPECT_VECTOR4_NEAR(v3 += v2, Vector4<TypeParam>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w));

  v3 = v1;
  EXPECT_VECTOR4_NEAR(v3 -= v2, Vector4<TypeParam>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w));

  v3 = v1;
  EXPECT_VECTOR4_NEAR(v3 *= s, Vector4<TypeParam>(v1.x * s, v1.y * s, v1.z * s, v1.w * s));

  v3 = v1;
  EXPECT_VECTOR4_NEAR(v3 /= s, Vector4<TypeParam>(v1.x / s, v1.y / s, v1.z / s, v1.w / s));

  Vector4<TypeParam> v4(1.234567, 2.345678, 3.456789, 4.567890);

  EXPECT_VECTOR4_NEAR(v1, v4);
  EXPECT_TRUE(v1 != v2);
  EXPECT_FALSE(v1 == v2);
}