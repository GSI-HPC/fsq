/*
 * LTSM API stub implementation for static analysis (clang-tidy)
 * This provides minimal function implementations to allow parsing without the
 * full LTSM library.
 */

#include "ltsmapi.h"

/* Convert off64_t to dsStruct64_t */
static inline dsStruct64_t to_dsStruct64_t(off64_t size)
{
    dsStruct64_t ds;
    ds.hi = (dsUint32_t)(size >> 32);
    ds.lo = (dsUint32_t)(size & 0xFFFFFFFF);
    return ds;
}

/* Convert dsStruct64_t to off64_t */
static inline off64_t to_off64_t(dsStruct64_t ds)
{
    return ((off64_t)ds.hi << 32) | (off64_t)ds.lo;
}
