//==========================================================================
//  INTXTYPES.H - part of
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2008 Andras Varga
  Copyright (C) 2006-2008 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#ifndef __INTXTYPES_H
#define __INTXTYPES_H

#include <limits.h>   // __WORDSIZE

// All systems except Visual C++ are expected to have <stdint.h>
#if defined SWIG || defined _MSC_VER
#define HAVE_STDINT_H 0
#else
#define HAVE_STDINT_H 1
#endif

//
// Make intX_t and uintX_t types available
//
#if HAVE_STDINT_H
  // include C99 header
  #include <stdint.h>
#elif defined _MSC_VER
  typedef __int8              int8_t;
  typedef __int16             int16_t;
  typedef __int32             int32_t;
  typedef __int64             int64_t;
  typedef unsigned __int8     uint8_t;
  typedef unsigned __int16    uint16_t;
  typedef unsigned __int32    uint32_t;
  typedef unsigned __int64    uint64_t;
#else
  // the following should work on most systems (and in envir we check
  // the correctness of these definitions)
  typedef signed char         int8_t;
  typedef short               int16_t;
  typedef int                 int32_t;
  typedef long long           int64_t;
  typedef unsigned char       uint8_t;
  typedef unsigned short      uint16_t;
  typedef unsigned int        uint32_t;
  typedef unsigned long long  uint64_t;
#endif

//
// MIN/MAX macros for integral types, copied from <stdint.h>.
// Note that we need to define them ourselves, because if
// <stdint.h> gets included before us, it's too late
// to turn on __STDC_LIMIT_MACROS.
//

// Minimum of signed integral types.
#ifndef INT8_MIN
#define INT8_MIN      (-128)
#endif

#ifndef INT16_MIN
#define INT16_MIN     (-32767-1)
#endif

#ifndef INT32_MIN
#define INT32_MIN     (-2147483647-1)
#endif

#ifndef INT64_MIN
#define INT64_MIN     (-9223372036854775807LL-1)
#endif

// Maximum of signed integral types.
#ifndef INT8_MAX
#define INT8_MAX      (127)
#endif

#ifndef INT16_MAX
#define INT16_MAX     (32767)
#endif

#ifndef INT32_MAX
#define INT32_MAX     (2147483647)
#endif

#ifndef INT64_MAX
#define INT64_MAX     (9223372036854775807LL)
#endif

// Maximum of unsigned integral types.
#ifndef UINT8_MAX
#define UINT8_MAX     (255)
#endif

#ifndef UINT16_MAX
#define UINT16_MAX    (65535)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX    (4294967295U)
#endif

#ifndef UINT64_MAX
#define UINT64_MAX    (18446744073709551615ULL)
#endif


//
// We prefer shorter names for ints. If they collide with other headers,
// #undef them after #including omnetpp.h.
//
#ifndef int8
#define int8     int8_t
#endif

#ifndef int16
#define int16    int16_t
#endif

#ifndef int32
#define int32    int32_t
#endif

#ifndef int64
#define int64    int64_t
#endif

#ifndef uint8
#define uint8    uint8_t
#endif

#ifndef uint16
#define uint16   uint16_t
#endif

#ifndef uint32
#define uint32   uint32_t
#endif

#ifndef uint64
#define uint64   uint64_t
#endif


//
// printf type specifier for int64.
//
// Note: %I64d is only used with VC++ 7.1 and MinGW gcc 3.4.x; once we
// drop support for these compilers, this macro can be dropped altogether
//
// Note2: on 64-bit platforms, gcc defines int64_t to be long, so
// we need to use %ld (%lld generates warnings). We recognize 64-bit
// platforms by __WORDSIZE (from <bits/wordsize.h>, #included by <limits.h>)
//
#if defined(_MSC_VER) || defined(__MINGW32__)
#   define INT64_PRINTF_FORMAT   "I64"
#elif __WORDSIZE == 64 && !defined(__APPLE__)
#   define INT64_PRINTF_FORMAT   "l"
#else
#   define INT64_PRINTF_FORMAT   "ll"
#endif

//
// cCommBuffer and cHasher need to process long long and unsigned long long
// (which should be a different type from long, and at least 64 bits in size).
// However, earlier versions of MSVC (7.1 and before) don't understand
// long long but have __int64 instead. MSVC 8.0 and above are OK.
// The following typedefs can be removed when we drop support for MVSC 7.1.
//
// These types are NOT part of the OMNeT++ public API. Do not use them
// except in cCommBuffer implementations.
//
#ifdef _MSC_VER
typedef __int64            opp_long_long;
typedef unsigned __int64   opp_unsigned_long_long;
#else
typedef long long          opp_long_long;
typedef unsigned long long opp_unsigned_long_long;
#endif

#if defined(_MSC_VER) || defined(__MINGW32__)
#define LONGLONG_PRINTF_FORMAT  "I64"
#else
#define LONGLONG_PRINTF_FORMAT  "ll"
#endif


//
// string-to-int64 conversion
//
#ifdef _MSC_VER
#define strtoll   _strtoi64
#define strtoull  _strtoui64
#endif

#endif

