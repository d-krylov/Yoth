#ifndef YOTH_VECTOR_TYPE_CONCEPTS_H
#define YOTH_VECTOR_TYPE_CONCEPTS_H

#include <concepts>

namespace Yoth {

template <typename T>
concept IsFloating = std::is_floating_point_v<T>;

template <typename T>
concept IsIntegral = std::is_integral_v<T>;

template <typename U, typename... T>
concept SameTypes = (std::same_as<U, T> && ...);

} // namespace Yoth

#endif // YOTH_VECTOR_TYPE_CONCEPTS_H