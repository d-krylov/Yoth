#ifndef YOTH_VECTOR_TYPE_H
#define YOTH_VECTOR_TYPE_H

#include "yoth/core/core.h"

namespace Yoth {

template <typename T>
using VectorTypeLength =
  std::conditional_t<std::same_as<T, double>, double, std::conditional_t<std::same_as<T, long double>, long double, float>>;

// VectorType 2

template <Arithmetic T>
class VectorType2 {
public:
  using value_type = T;

  static constexpr auto size = 2;

  VectorType2() : x{}, y{} {
  }

  YOTH_HOST_DEVICE VectorType2(T v0, T v1) : x(v0), y(v1) {
  }

  YOTH_HOST_DEVICE explicit VectorType2(T v) : x(v), y(v) {
  }

  bool HasNaN() const {
    return IsNaN(x) || IsNaN(y);
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator+=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x += other.x, self.y += other.y;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator-=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x -= other.x, self.y -= other.y;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator*=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x *= other.x, self.y *= other.y;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator/=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x /= other.x, self.y /= other.y;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator*=(this Self<T> &self, U v) {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    self.x *= v, self.y *= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator/=(this Self<T> &self, U v) {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    self.x /= v, self.y /= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator+(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x + other.x, self.y + other.y};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator-(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x - other.x, self.y - other.y};
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto operator-(this const Self &self) {
    return Self{-self.x, -self.y};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator*(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x * other.x, self.y * other.y};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator*(this const Self<T> &self, U v) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    return {self.x * v, self.y * v};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator/(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x / other.x, self.y / other.y};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator/(this const Self<T> &self, U v) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    return {self.x / v, self.y / v};
  }

  template <typename Self>
  YOTH_HOST_DEVICE bool operator==(this const Self &self, const Self &other) {
    return self.x == other.x && self.y == other.y;
  }

  template <typename Self>
  YOTH_HOST_DEVICE bool operator!=(this const Self &self, const Self &other) {
    return self.x != other.x || self.y != other.y;
  }

  YOTH_HOST_DEVICE T operator[](int i) const {
    return data[i];
  }

  YOTH_HOST_DEVICE T &operator[](int i) {
    return data[i];
  }

public:
  // clang-format off
  union {
    struct { T x, y; };
    struct { T r, g; };
    struct { T data[2]; };
  };
  // clang-format on
};

// VectorType 3

template <Arithmetic T>
class VectorType3 {
public:
  using value_type = T;

  static constexpr auto size = 3;

  YOTH_HOST_DEVICE VectorType3() : x{}, y{}, z{} {
  }

  YOTH_HOST_DEVICE VectorType3(T v0, T v1, T v2) : x(v0), y(v1), z(v2) {
  }

  YOTH_HOST_DEVICE explicit VectorType3(T v) : x(v), y(v), z(v) {
  }

  bool HasNaN() const {
    return IsNaN(x) || IsNaN(y) || IsNaN(z);
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator+=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x += other.x, self.y += other.y, self.z += other.z;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator-=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x -= other.x, self.y -= other.y, self.z -= other.z;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator*=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x *= other.x, self.y *= other.y, self.z *= other.z;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator/=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x /= other.x, self.y /= other.y, self.z /= other.z;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator*=(this Self<T> &self, U v) {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    self.x *= v, self.y *= v, self.z *= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator/=(this Self<T> &self, U v) {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    self.x /= v, self.y /= v, self.z /= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator+(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x + other.x, self.y + other.y, self.z + other.z};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator-(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x - other.x, self.y - other.y, self.z - other.z};
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto operator-(this const Self &self) {
    return Self{-self.x, -self.y, -self.z};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator*(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x * other.x, self.y * other.y, self.z * other.z};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator/(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x / other.x, self.y / other.y, self.z / other.z};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator*(this const Self<T> &self, U v) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    return {self.x * v, self.y * v, self.z * v};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator/(this const Self<T> &self, U v) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    return {self.x / v, self.y / v, self.z / v};
  }

  template <typename Self>
  YOTH_HOST_DEVICE bool operator==(this const Self &self, const Self &other) {
    return self.x == other.x && self.y == other.y && self.z == other.z;
  }

  template <typename Self>
  YOTH_HOST_DEVICE bool operator!=(this const Self &self, const Self &other) {
    return self.x != other.x || self.y != other.y && self.z != other.z;
  }

  YOTH_HOST_DEVICE T operator[](int i) const {
    return data[i];
  }

  YOTH_HOST_DEVICE T &operator[](int i) {
    return data[i];
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto xy(this const Self &self) -> typename Self::minus_dimension_type {
    return typename Self::minus_dimension_type{self.x, self.y};
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto yz(this const Self &self) -> typename Self::minus_dimension_type {
    return typename Self::minus_dimension_type{self.y, self.z};
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto xz(this const Self &self) -> typename Self::minus_dimension_type {
    return typename Self::minus_dimension_type{self.x, self.z};
  }

public:
  // clang-format off
  union {
    struct { T x, y, z; };
    struct { T r, g, b; };
    struct { T data[3]; };
  };
  // clang-format on
};

// VectorType 4

template <Arithmetic T>
class VectorType4 {
public:
  using value_type = T;

  static constexpr auto size = 4;

  VectorType4() : x{}, y{}, z{}, w{} {
  }

  YOTH_HOST_DEVICE VectorType4(T v0, T v1, T v2, T v3) : x(v0), y(v1), z(v2), w(v3) {
  }

  YOTH_HOST_DEVICE explicit VectorType4(T v) : x(v), y(v), z(v), w(v) {
  }

  bool HasNaN() const {
    return IsNaN(x) || IsNaN(y) || IsNaN(z) || IsNaN(w);
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator+=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x += other.x, self.y += other.y, self.z += other.z, self.w += other.w;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator-=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x -= other.x, self.y -= other.y, self.z -= other.z, self.w -= other.w;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator*=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x *= other.x, self.y *= other.y, self.z *= other.z, self.w *= other.w;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator/=(this Self<T> &self, const Self<U> &other) {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    self.x /= other.x, self.y /= other.y, self.z /= other.z, self.w /= other.w;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator*=(this Self<T> &self, U v) {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    self.x *= v, self.y *= v, self.z *= v, self.w *= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto &operator/=(this Self<T> &self, U v) {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    self.x /= v, self.y /= v, self.z /= v, self.w /= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator+(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x + other.x, self.y + other.y, self.z + other.z, self.w + other.w};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator-(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x - other.x, self.y - other.y, self.z - other.z, self.w - other.w};
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto operator-(this const Self &self) {
    return Self{-self.x, -self.y, -self.z, -self.w};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator*(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x * other.x, self.y * other.y, self.z * other.z, self.w * other.w};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator/(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(other.HasNaN() == false, "Other has NaN");
    return {self.x / other.x, self.y / other.y, self.z / other.z, self.w / other.w};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator*(this const Self<T> &self, U v) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    return {self.x * v, self.y * v, self.z * v, self.w * v};
  }

  template <Arithmetic U, template <typename> typename Self>
  YOTH_HOST_DEVICE auto operator/(this const Self<T> &self, U v) -> Self<std::common_type_t<T, U>> {
    CORE_ASSERT(IsNaN(v) == false, "value is NaN");
    return {self.x / v, self.y / v, self.z / v, self.w / v};
  }

  template <typename Self>
  YOTH_HOST_DEVICE bool operator==(this const Self &self, const Self &other) {
    return self.x == other.x && self.y == other.y && self.z == other.z && self.w == other.w;
  }

  template <typename Self>
  YOTH_HOST_DEVICE bool operator!=(this const Self &self, const Self &other) {
    return self.x != other.x || self.y != other.y && self.z != other.z && self.w != other.w;
  }

  YOTH_HOST_DEVICE T operator[](int i) const {
    return data[i];
  }

  YOTH_HOST_DEVICE T &operator[](int i) {
    return data[i];
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto xyz(this const Self &self) -> typename Self::minus_dimension_type {
    return typename Self::minus_dimension_type{self.x, self.y, self.z};
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto yzw(this const Self &self) -> typename Self::minus_dimension_type {
    return typename Self::minus_dimension_type{self.y, self.z, self.w};
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto xyw(this const Self &self) -> typename Self::minus_dimension_type {
    return typename Self::minus_dimension_type{self.x, self.y, self.w};
  }

  template <typename Self>
  YOTH_HOST_DEVICE auto xzw(this const Self &self) -> typename Self::minus_dimension_type {
    return typename Self::minus_dimension_type{self.x, self.z, self.w};
  }

public:
  // clang-format off
  union {
    struct { T x, y, z, w; };
    struct { T r, g, b, a; };
    struct { T data[4]; };
  };
  // clang-format on
};

} // namespace Yoth

#include "vector_type.ipp"

#endif // YOTH_VECTOR_TYPE_H