
#include "tests_common.h"

using namespace Yoth;

TYPED_TEST(AllTypesTest, Constructors) {
  Vector2<TypeParam> v0;

  EXPECT_EQ(v0.x, TypeParam(0.0));
  EXPECT_EQ(v0.y, TypeParam(0.0));
  EXPECT_EQ(v0.r, TypeParam(0.0));
  EXPECT_EQ(v0.g, TypeParam(0.0));
  EXPECT_EQ(v0.data[0], TypeParam(0.0));
  EXPECT_EQ(v0.data[1], TypeParam(0.0));
  EXPECT_EQ(v0, Vector2<TypeParam>(0.0, 0.0));

  auto f = TypeParam(1.0);
  auto g = TypeParam(2.0);

  Vector2<TypeParam> v1(f);

  EXPECT_EQ(v1.x, f);
  EXPECT_EQ(v1.y, f);
  EXPECT_EQ(v1, Vector2<TypeParam>(f, f));

  Vector2<TypeParam> v2(f, g);

  EXPECT_EQ(v2.x, f);
  EXPECT_EQ(v2.y, g);

  Vector2<TypeParam> v3(f, g);

  EXPECT_EQ(v2, v3);
  EXPECT_NE(v2, v1);
}

TYPED_TEST(FloatingTypesTest, Operators) {
  Vector2<TypeParam> v1(13.1, 12.5);
  Vector2<TypeParam> v2(14.2, 15.3);

  EXPECT_VECTOR2_NEAR(v1 + v2, Vector2<TypeParam>(v1.x + v2.x, v1.y + v2.y));
  EXPECT_VECTOR2_NEAR(v1 * v2, Vector2<TypeParam>(v1.x * v2.x, v1.y * v2.y));
  EXPECT_VECTOR2_NEAR(v1 - v2, Vector2<TypeParam>(v1.x - v2.x, v1.y - v2.y));

  EXPECT_TYPE_NEAR(Dot(v1, v2), TypeParam(v1.x * v2.x + v1.y * v2.y));

  EXPECT_EQ(Min(v1, v2), v1);
  EXPECT_EQ(Max(v1, v2), v2);

  Vector2<TypeParam> v3(-1.0, -4.0);

  EXPECT_EQ(Abs(v3), Vector2<TypeParam>(1.0, 4.0));
  EXPECT_EQ(Floor(v1), Vector2<TypeParam>(13.0, 12.0));
  EXPECT_EQ(Ceil(v1), Vector2<TypeParam>(14.0, 13.0));
}