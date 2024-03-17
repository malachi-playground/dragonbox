#pragma once

// NOTE: Having some issues with c++20 mode

#if __cpp_lib_bit_cast

#include <bit>

namespace jkj::dragonbox::detail::stdr {

using std::bit_cast;

}

#endif

// Temporary