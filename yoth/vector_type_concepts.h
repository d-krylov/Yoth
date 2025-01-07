#ifndef YOTH_VECTOR_TYPE_CONCEPTS_H
#define YOTH_VECTOR_TYPE_CONCEPTS_H

#include <concepts>

namespace Yoth {

// clang-format off

template <typename T, typename Derived>
concept IsVectorType2 = requires(Derived d) {
  { d.x } -> std::same_as<T&>;
  { d.y } -> std::same_as<T&>;
} && !requires(Derived d) {
  { d.z };
  { d.w };
};

template <typename T, typename Derived>
concept IsVectorType3 = requires(Derived d) {
  { d.x } -> std::same_as<T&>;
  { d.y } -> std::same_as<T&>;
  { d.z } -> std::same_as<T&>;
} && !requires(Derived d) {
  { d.w };
};

template <typename T, typename Derived>
concept IsVectorType4 = requires(Derived d) {
  { d.x } -> std::same_as<T&>;
  { d.y } -> std::same_as<T&>;
  { d.z } -> std::same_as<T&>;
  { d.w } -> std::same_as<T&>;
};

// clang-format on

} // namespace Yoth

#endif // YOTH_VECTOR_TYPE_CONCEPTS_H