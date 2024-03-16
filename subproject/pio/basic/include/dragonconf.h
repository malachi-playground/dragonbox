#pragma once

#define JKJ_STD_REPLACEMENT_NAMESPACE estd

//#include <estd/bitset.h>
#include <estd/cstdint.h>
#include <estd/string.h>
#include <estd/limits.h>
#include <estd/type_traits.h>

namespace estd {

using ::int_least32_t;
using ::int_least64_t;

using ::uint_least32_t;
using ::uint_least64_t;

using ::memcpy;

template <class T>
struct is_trivially_copyable;

template <class T>
using is_unsigned = bool_constant<numeric_limits<T>::is_signed>;

}

// Arduino annoyances
#undef min
#undef max

