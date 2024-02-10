#pragma once
#include "Serialization.hpp"
#include <cstdint>

enum class CommandCategory_t : std::uint8_t {
  ping = 1,
};

using Id_t = std::uint32_t;
using Arg_t = std::uint8_t;

struct Command {
  Id_t id;
  CommandCategory_t type;
  Arg_t arg;
};