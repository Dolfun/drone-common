#pragma once
#include "Serialization.hpp"
#include <cstdint>

enum class CommandType : std::uint8_t {
  ping = 0,
};

using IDType = std::uint32_t;
using ArgType = std::uint8_t;

struct Command {
  IDType id;
  CommandType type;
  ArgType arg;
};