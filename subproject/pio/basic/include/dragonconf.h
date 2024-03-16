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
using is_unsigned = bool_constant<!numeric_limits<T>::is_signed>;

// DEBT: Concerningly, this collides with numeric_limits<unsigned long long> which itself
// cascades down to internal::numeric_limits<uint32_t> - this very much seems like
// a bug in estd itself
//template <>
//struct numeric_limits<uint_least64_t> : numeric_limits<uint64_t> {};

// TODO: Move estd internal limits to actualy internal/limits.h file

}

// DEBT: This will want to go at project file/cmake level
#define ESTD_BRINGUP_WORKAROUND 1
// TODO: Implement 'radix' on numeric_limits

// Arduino annoyances
#undef min
#undef max

