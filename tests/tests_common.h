#ifndef TESTS_COMMON_H
#define TESTS_COMMON_H

#include "yoth/common/yoth.h"
#include "gtest/gtest.h"

template <typename T>
class AllTypesTest : public ::testing::Test {};
using AllTypes = ::testing::Types<float, double, int32_t, uint32_t>;

template <typename T>
class FloatingTypesTest : public ::testing::Test {};
using FloatingTypes = ::testing::Types<float, double>;

TYPED_TEST_SUITE(AllTypesTest, AllTypes);
TYPED_TEST_SUITE(FloatingTypesTest, FloatingTypes);

template <typename T>
void EXPECT_TYPE_NEAR(const T &a, const T &b) {
  if constexpr (std::same_as<T, float>) {
    EXPECT_NEAR(a, b, 1e-4f);
  } else if constexpr (std::same_as<T, double>) {
    EXPECT_NEAR(a, b, 1e-13f);
  } else {
    EXPECT_EQ(a, b);
  }
}

template <typename T>
void EXPECT_VECTOR2_NEAR(const Yoth::Vector2<T> &a, const Yoth::Vector2<T> &b) {
  if constexpr (std::same_as<T, float>) {
    EXPECT_NEAR(a.x, b.x, 1e-6f);
    EXPECT_NEAR(a.y, b.y, 1e-6f);
  } else if constexpr (std::same_as<T, double>) {
    EXPECT_NEAR(a.x, b.x, 1e-13);
    EXPECT_NEAR(a.y, b.y, 1e-13);
  } else {
    EXPECT_EQ(a.x, b.x);
    EXPECT_EQ(a.y, b.y);
  }
}

template <typename T>
void EXPECT_VECTOR3_NEAR(const Yoth::Vector3<T> &a, const Yoth::Vector3<T> &b) {
  if constexpr (std::same_as<T, float>) {
    EXPECT_NEAR(a.x, b.x, 1e-6f);
    EXPECT_NEAR(a.y, b.y, 1e-6f);
    EXPECT_NEAR(a.z, b.z, 1e-6f);
  } else if constexpr (std::same_as<T, double>) {
    EXPECT_NEAR(a.x, b.x, 1e-13);
    EXPECT_NEAR(a.y, b.y, 1e-13);
    EXPECT_NEAR(a.z, b.z, 1e-13f);
  } else {
    EXPECT_EQ(a.x, b.x);
    EXPECT_EQ(a.y, b.y);
    EXPECT_EQ(a.z, b.z);
  }
}

template <typename T>
void EXPECT_VECTOR4_NEAR(const Yoth::Vector4<T> &a, const Yoth::Vector4<T> &b) {
  if constexpr (std::same_as<T, float>) {
    EXPECT_NEAR(a.x, b.x, 1e-6f);
    EXPECT_NEAR(a.y, b.y, 1e-6f);
    EXPECT_NEAR(a.z, b.z, 1e-6f);
    EXPECT_NEAR(a.w, b.w, 1e-6f);
  } else if constexpr (std::same_as<T, double>) {
    EXPECT_NEAR(a.x, b.x, 1e-13);
    EXPECT_NEAR(a.y, b.y, 1e-13);
    EXPECT_NEAR(a.z, b.z, 1e-13);
    EXPECT_NEAR(a.w, b.w, 1e-13);
  } else {
    EXPECT_EQ(a.x, b.x);
    EXPECT_EQ(a.y, b.y);
    EXPECT_EQ(a.z, b.z);
    EXPECT_EQ(a.w, b.w);
  }
}

#endif // TESTS_COMMON_H