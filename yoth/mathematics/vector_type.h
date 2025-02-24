#ifndef YOTH_VECTOR_TYPE_H
#define YOTH_VECTOR_TYPE_H

#include "core/core.h"
#include <algorithm>
#include <functional>

namespace Yoth {

template <typename T> struct VectorTypeLength {
  using type = float;
};

template <> struct VectorTypeLength<double> {
  using type = double;
};

template <> struct VectorTypeLength<long double> {
  using type = long double;
};

template <typename T, int N> class VectorType {
public:
  template <Arithmetic U, template <typename, int> typename Self>
  auto &operator+=(this Self<T, N> &&self, const Self<U, N> &other) {
    std::ranges::transform(self.v, other.v, self.v.begin(), std::plus<>{});
    return self;
  }

  template <Arithmetic U, template <typename, int> typename Self>
  auto &operator-=(this Self<T, N> &&self, const Self<U, N> &other) {
    std::ranges::transform(self.v, other.v, self.v.begin(), std::minus<>{});
    return self;
  }

  template <Arithmetic U, template <typename, int> typename Self>
  auto &operator*=(this Self<T, N> &&self, const Self<U, N> &other) {
    std::ranges::transform(self.v, other.v, self.v.begin(), std::multiplies<>{});
    return self;
  }

  template <Arithmetic U, template <typename, int> typename Self>
  auto &operator/=(this Self<T, N> &&self, const Self<U, N> &other) {
    std::ranges::transform(self.v, other.v, self.v.begin(), std::divides<>{});
    return self;
  }

public:
  std::array<T, N> v;
};

// VectorType 2

template <Arithmetic T> class VectorType2 {
public:
  using value_type = T;

  VectorType2() : x{}, y{} {}
  VectorType2(T v0, T v1) : x(v0), y(v1) {}
  explicit VectorType2(T v) : x(v), y(v) {}

  template <Arithmetic U, template <typename> typename Self>
  auto &operator+=(this Self<T> &&self, const Self<U> &other) {
    self.x += other.x;
    self.y += other.y;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto &operator-=(this Self<T> &&self, const Self<U> &other) {
    self.x -= other.x;
    self.y -= other.y;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto &operator*=(this Self<T> &&self, const Self<U> &other) {
    self.x *= other.x;
    self.y *= other.y;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto &operator/=(this Self<T> &&self, const Self<U> &other) {
    self.x /= other.x;
    self.y /= other.y;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self> auto &operator*=(this Self<T> &&self, U v) {
    self.x *= v;
    self.y *= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self> auto &operator/=(this Self<T> &&self, U v) {
    self.x /= v;
    self.y /= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator+(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x + other.x, self.y + other.y};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator-(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x - other.x, self.y - other.y};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator*(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x * other.x, self.y * other.y};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator/(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x / other.x, self.y / other.y};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator/(this const Self<T> &self, U d) -> Self<std::common_type_t<T, U>> {
    return {self.x / d, self.y / d};
  }

  template <typename Self> bool operator==(this const Self &self, const Self &other) {
    return self.x == other.x && self.y == other.y;
  }

  template <typename Self> bool operator!=(this const Self &self, const Self &other) {
    return self.x != other.x || self.y != other.y;
  }

  T operator[](int i) const { return data[i]; }

  T &operator[](int i) { return data[i]; }

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

template <Arithmetic T> class VectorType3 {
public:
  using value_type = T;

  VectorType3() : x{}, y{}, z{} {}
  VectorType3(T v0, T v1, T v2) : x(v0), y(v1), z(v2) {}
  explicit VectorType3(T v) : x(v), y(v), z(v) {}

  template <Arithmetic U, template <typename> typename Self>
  auto &operator+=(this Self<T> &&self, const Self<U> &other) {
    self.x += other.x;
    self.y += other.y;
    self.z += other.z;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto &operator-=(this Self<T> &&self, const Self<U> &other) {
    self.x -= other.x;
    self.y -= other.y;
    self.z -= other.z;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto &operator*=(this Self<T> &&self, const Self<U> &other) {
    self.x *= other.x;
    self.y *= other.y;
    self.z *= other.z;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto &operator/=(this Self<T> &&self, const Self<U> &other) {
    self.x /= other.x;
    self.y /= other.y;
    self.z /= other.z;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self> auto &operator*=(this Self<T> &&self, U v) {
    self.x *= v;
    self.y *= v;
    self.z *= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self> auto &operator/=(this Self<T> &&self, U v) {
    self.x /= v;
    self.y /= v;
    self.z /= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator+(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x + other.x, self.y + other.y, self.z + other.z};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator-(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x - other.x, self.y - other.y, self.z - other.z};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator*(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x * other.x, self.y * other.y, self.z * other.z};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator/(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x / other.x, self.y / other.y, self.z / other.z};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator*(this const Self<T> &self, U d) -> Self<std::common_type_t<T, U>> {
    return {self.x * d, self.y * d, self.z * d};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator/(this const Self<T> &self, U d) -> Self<std::common_type_t<T, U>> {
    return {self.x / d, self.y / d, self.z / d};
  }

  template <typename Self> bool operator==(this const Self &self, const Self &other) {
    return self.x == other.x && self.y == other.y && self.z == other.z;
  }

  template <typename Self> bool operator!=(this const Self &self, const Self &other) {
    return self.x != other.x || self.y != other.y && self.z != other.z;
  }

  T operator[](int i) const { return data[i]; }

  T &operator[](int i) { return data[i]; }

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

template <Arithmetic T> class VectorType4 {
public:
  using value_type = T;

  VectorType4() : x{}, y{}, z{}, w{} {}
  VectorType4(T v0, T v1, T v2, T v3) : x(v0), y(v1), z(v2), w(v3) {}
  explicit VectorType4(T v) : x(v), y(v), z(v), w(v) {}

  template <Arithmetic U, template <typename> typename Self>
  auto &operator+=(this Self<T> &&self, const Self<U> &other) {
    self.x += other.x;
    self.y += other.y;
    self.z += other.z;
    self.w += other.w;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto &operator-=(this Self<T> &&self, const Self<U> &other) {
    self.x -= other.x;
    self.y -= other.y;
    self.z -= other.z;
    self.w -= other.w;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto &operator*=(this Self<T> &&self, const Self<U> &other) {
    self.x *= other.x;
    self.y *= other.y;
    self.z *= other.z;
    self.w *= other.w;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto &operator/=(this Self<T> &&self, const Self<U> &other) {
    self.x /= other.x;
    self.y /= other.y;
    self.z /= other.z;
    self.w /= other.w;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self> auto &operator*=(this Self<T> &&self, U v) {
    self.x *= v;
    self.y *= v;
    self.z *= v;
    self.w *= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self> auto &operator/=(this Self<T> &&self, U v) {
    self.x /= v;
    self.y /= v;
    self.z /= v;
    self.w /= v;
    return self;
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator+(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x + other.x, self.y + other.y, self.z + other.z, self.w + other.w};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator-(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x - other.x, self.y - other.y, self.z - other.z, self.w - other.w};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator*(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x * other.x, self.y * other.y, self.z * other.z, self.w * other.w};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator/(this const Self<T> &self, const Self<U> &other) -> Self<std::common_type_t<T, U>> {
    return {self.x / other.x, self.y / other.y, self.z / other.z, self.w / other.w};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator*(this const Self<T> &self, U d) -> Self<std::common_type_t<T, U>> {
    return {self.x * d, self.y * d, self.z * d, self.w * d};
  }

  template <Arithmetic U, template <typename> typename Self>
  auto operator/(this const Self<T> &self, U d) -> Self<std::common_type_t<T, U>> {
    return {self.x / d, self.y / d, self.z / d, self.w / d};
  }

  template <typename Self> bool operator==(this const Self &self, const Self &other) {
    return self.x == other.x && self.y == other.y && self.z == other.z && self.w == other.w;
  }

  template <typename Self> bool operator!=(this const Self &self, const Self &other) {
    return self.x != other.x || self.y != other.y && self.z != other.z && self.w != other.w;
  }

  T operator[](int i) const { return data[i]; }

  T &operator[](int i) { return data[i]; }

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