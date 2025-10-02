#ifndef YOTH_VECTOR_TYPE_CONCEPTS_H
#define YOTH_VECTOR_TYPE_CONCEPTS_H

#include <concepts>

namespace Yoth {

template <typename U, typename... T>
concept SameTypes = (std::same_as<U, T> && ...);

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <typename... T>
struct HeadType;

template <typename U, typename... T>
struct HeadType<U, T...> {
  using type = U;
};

} // namespace Yoth

#endif // YOTH_VECTOR_TYPE_CONCEPTS_H