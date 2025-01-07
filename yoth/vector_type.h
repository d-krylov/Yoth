#ifndef YOTH_VECTOR_TYPE_H
#define YOTH_VECTOR_TYPE_H

#include "vector_type_concepts.h"

namespace Yoth {

template <typename T, int N, template <typename> typename Derived> class VectorType {
public:
  T v[N];
};

// VectorType 2

template <typename T, template <typename> typename Derived> class VectorType<T, 2, Derived> {
public:
  VectorType() : x{}, y{} {}
  VectorType(T v) : x(v), y(v) {}
  VectorType(T v0, T v1) : x(v0), y(v1) {}

  template <typename U> auto &operator+=(const Derived<U> &other) {
    x += other.x;
    y += other.y;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator-=(const Derived<U> &other) {
    x -= other.x;
    y -= other.y;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator*=(const Derived<U> &other) {
    x *= other.x;
    y *= other.y;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator/=(const Derived<U> &other) {
    x /= other.x;
    y /= other.y;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator*=(U v) {
    x *= v;
    y *= v;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator/=(U v) {
    x /= v;
    y /= v;
    return static_cast<Derived<T> &>(*this);
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

template <typename T, template <typename> typename Derived> class VectorType<T, 3, Derived> {
public:
  VectorType() : x{}, y{}, z{} {}
  VectorType(T v) : x(v), y(v), z(v) {}
  VectorType(T v0, T v1, T v2) : x(v0), y(v1), z(v2) {}

  template <typename U> auto &operator+=(const Derived<U> &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator-=(Derived<U> other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator*=(const Derived<U> &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator/=(const Derived<U> &other) {
    x /= other.x;
    y /= other.y;
    z *= other.z;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator*=(U v) {
    x *= v;
    y *= v;
    z *= v;
    return static_cast<Derived<T> &>(*this);
  }

  template <typename U> auto &operator/=(U v) {
    x /= v;
    y /= v;
    z /= v;
    return static_cast<Derived<T> &>(*this);
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

template <typename T, template <typename> typename Derived> class VectorType<T, 4, Derived> {
public:
  VectorType() : x{}, y{}, z{}, w{} {}
  VectorType(T v) : x(v), y(v), z(v), w(v) {}
  VectorType(T v0, T v1, T v2, T v3) : x(v0), y(v1), z(v2), w(v3) {}

  template <typename U> auto &operator+=(const Derived<U> &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }

  template <typename U> auto &operator*=(U v) {
    x *= v;
    y *= v;
    z *= v;
    w *= v;
    return *this;
  }

  template <typename U> auto &operator/=(U v) {
    x /= v;
    y /= v;
    z /= v;
    w /= v;
    return *this;
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