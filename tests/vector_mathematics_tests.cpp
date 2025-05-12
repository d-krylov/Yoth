#include "yoth/common/yoth.h"
#include "gtest/gtest.h"

using namespace Yoth;

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