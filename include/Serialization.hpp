#pragma once
#include <type_traits>
#include <cstring>
#include <array>

template <typename T>
concept Serializable = 
  std::is_standard_layout_v<T> &&
  std::is_trivial_v<T>;

template <Serializable T>
using bytes = std::array<std::byte, sizeof(T)>;

template <Serializable T>
auto serialize(const T& val) -> bytes<T> {
  bytes<T> serialized {};
  std::memcpy(static_cast<void*>(serialized.data()), static_cast<const void*>(&val), sizeof(T));
  return serialized;
}

template <Serializable T>
auto unserialize(bytes<T> serialized) -> T {
  T val;
  std::memcpy(static_cast<void*>(&val), static_cast<const void*>(serialized.data()), sizeof(T));
  return val;
}