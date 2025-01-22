#ifndef YOTH_VECTOR_TYPE_H
#define YOTH_VECTOR_TYPE_H

#include "core/core.h"

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

template <typename T, int N, template <typename> typename Derived> class VectorType {
public:
  T v[N];
};

// VectorType 2

template <typename T, template <typename> typename Derived> class VectorType<T, 2, Derived> {
public:
  using value_type = T;

  VectorType() : x{}, y{} {}
  VectorType(T v0, T v1) : x(v0), y(v1) {}
  explicit VectorType(T v) : x(v), y(v) {}

  template <Arithmetic U> auto &operator+=(const Derived<U> &other) {
    x += other.x;
    y += other.y;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator-=(const Derived<U> &other) {
    x -= other.x;
    y -= other.y;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator*=(const Derived<U> &other) {
    x *= other.x;
    y *= other.y;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator/=(const Derived<U> &other) {
    x /= other.x;
    y /= other.y;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator*=(U v) {
    x *= v;
    y *= v;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator/=(U v) {
    x /= v;
    y /= v;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto operator+(const Derived<U> &other) const -> Derived<decltype(T{} + U{})> {
    return {x + other.x, y + other.y};
  }

  template <Arithmetic U> auto operator-(const Derived<U> &other) const -> Derived<decltype(T{} - U{})> {
    return {x - other.x, y - other.y};
  }

  template <Arithmetic U> auto operator*(const Derived<U> &other) const -> Derived<decltype(T{} * U{})> {
    return {x * other.x, y * other.y};
  }

  template <Arithmetic U> auto operator/(U d) const -> Derived<decltype(T{} / U{})> {
    return {x / d, y / d};
  }

  bool operator==(const Derived<T> &other) const { return x == other.x && y == other.y; }

  bool operator!=(const Derived<T> &other) const { return x != other.x || y != other.y; }

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

template <typename T, template <typename> typename Derived> class VectorType<T, 3, Derived> {
public:
  using value_type = T;

  VectorType() : x{}, y{}, z{} {}
  VectorType(T v0, T v1, T v2) : x(v0), y(v1), z(v2) {}
  explicit VectorType(T v) : x(v), y(v), z(v) {}

  template <Arithmetic U> auto &operator+=(const Derived<U> &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator-=(Derived<U> other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator*=(const Derived<U> &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator/=(const Derived<U> &other) {
    x /= other.x;
    y /= other.y;
    z *= other.z;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator*=(U v) {
    x *= v;
    y *= v;
    z *= v;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto &operator/=(U v) {
    x /= v;
    y /= v;
    z /= v;
    return static_cast<Derived<T> &>(*this);
  }

  template <Arithmetic U> auto operator+(const Derived<U> &other) const -> Derived<decltype(T{} + U{})> {
    return {x + other.x, y + other.y, z + other.z};
  }

  template <Arithmetic U> auto operator-(const Derived<U> &other) const -> Derived<decltype(T{} - U{})> {
    return {x - other.x, y - other.y, z - other.z};
  }

  template <Arithmetic U> auto operator*(const Derived<U> &other) const -> Derived<decltype(T{} * U{})> {
    return {x * other.x, y * other.y, z * other.z};
  }

  template <Arithmetic U> auto operator*(U d) const -> Derived<decltype(T{} * U{})> {
    return {x * d, y * d, z * d};
  }

  template <typename U> auto operator/(U d) const -> Derived<decltype(T{} / U{})> {
    return {x / d, y / d, z / d};
  }

  bool operator==(const Derived<T> &other) const { return x == other.x && y == other.y && z == other.z; }

  bool operator!=(const Derived<T> &other) const { return x != other.x || y != other.y || z != other.z; }

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

template <typename T, template <typename> typename Derived> class VectorType<T, 4, Derived> {
public:
  using value_type = T;

  VectorType() : x{}, y{}, z{}, w{} {}
  VectorType(T v0, T v1, T v2, T v3) : x(v0), y(v1), z(v2), w(v3) {}
  explicit VectorType(T v) : x(v), y(v), z(v), w(v) {}

  template <Arithmetic U> auto &operator+=(const Derived<U> &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }

  template <Arithmetic U> auto &operator*=(U v) {
    x *= v;
    y *= v;
    z *= v;
    w *= v;
    return *this;
  }

  template <Arithmetic U> auto &operator/=(U v) {
    x /= v;
    y /= v;
    z /= v;
    w /= v;
    return *this;
  }

  template <Arithmetic U> auto operator+(const Derived<U> &other) const -> Derived<decltype(T{} + U{})> {
    return {x + other.x, y + other.y, z + other.z, w + other.w};
  }

  template <Arithmetic U> auto operator-(const Derived<U> &other) const -> Derived<decltype(T{} - U{})> {
    return {x - other.x, y - other.y, z - other.z, w + other.w};
  }

  template <Arithmetic U> auto operator*(const Derived<U> &other) const -> Derived<decltype(T{} - U{})> {
    return {x * other.x, y * other.y, z - other.z, w + other.w};
  }

  template <Arithmetic U> auto operator/(U d) const -> Derived<decltype(T{} / U{})> {
    return {x / d, y / d, z / d, w / d};
  }

  bool operator==(const Derived<T> &other) const {
    return x == other.x && y == other.y && z == other.z && w == other.w;
  }

  bool operator!=(const Derived<T> &other) const {
    return x != other.x || y != other.y || z != other.z || w != other.w;
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