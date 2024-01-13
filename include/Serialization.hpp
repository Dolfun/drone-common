#pragma once
#include <type_traits>
#include <cstring>
#include <array>

template <typename T>
concept Serializable = 
  std::is_standard_layout_v<T> &&
  std::is_trivial_v<T>;

template <std::size_t N>
using bytes = std::array<std::byte, N>;

template <Serializable T>
auto serialize(const T& val) -> bytes<sizeof(T)> {
  bytes<sizeof(T)> serialized {};
  std::memcpy(static_cast<void*>(serialized.data()), static_cast<const void*>(&val), sizeof(T));
  return serialized;
}

template <Serializable T>
auto unserialize(bytes<sizeof(T)> serialized) -> T {
  T val;
  std::memcpy(static_cast<void*>(&val), static_cast<const void*>(serialized.data()), sizeof(T));
  return val;
}