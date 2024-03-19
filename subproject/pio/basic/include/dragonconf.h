#pragma once

#define JKJ_STD_REPLACEMENT_NAMESPACE estd

//#include <estd/bitset.h>
#include <estd/type_traits.h>
// FIX: estd/limits does NOT properly include type_traits on its own
// https://github.com/malachi-iot/estdlib/issues/36
#include <estd/limits.h>
#include <estd/string.h>

namespace estd {

// DEBT: Probably should do this in estd
using ::memcpy;

}

// DEBT: This will want to go at project file/cmake level
#define ESTD_BRINGUP_WORKAROUND 1
// TODO: Implement 'radix' on numeric_limits

#define JKJ_STATIC_DATA_SECTION PROGMEM

// Arduino annoyances
#undef min
#undef max

