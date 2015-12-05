/*
 * Copyright (c) 2015 Andrew Kelley
 *
 * This file is part of libsoundio, which is MIT licensed.
 * See http://opensource.org/licenses/MIT
 */

#ifndef SOUNDIO_ATOMICS_H
#define SOUNDIO_ATOMICS_H

// Simple wrappers around atomic values so that the compiler will catch it if
// I accidentally use operators such as +, -, += on them.

#ifdef __cplusplus

#include <atomic>

struct SoundIoAtomicLong {
    std::atomic<long> x;
};

struct SoundIoAtomicInt {
    std::atomic<int> x;
};

struct SoundIoAtomicBool {
    std::atomic<bool> x;
};

#define SOUNDIO_ATOMIC_LOAD(a) (a.x.load())
#define SOUNDIO_ATOMIC_FETCH_ADD(a, delta) (a.x.fetch_add(delta))
#define SOUNDIO_ATOMIC_STORE(a, value) (a.x.store(value))
#define SOUNDIO_ATOMIC_EXCHANGE(a, value) (a.x.exchange(value))

#else

#include <stdatomic.h>

struct SoundIoAtomicLong {
    atomic_long x;
};

struct SoundIoAtomicInt {
    atomic_int x;
};

struct SoundIoAtomicBool {
    atomic_bool x;
};

#define SOUNDIO_ATOMIC_LOAD(a) atomic_load(&a.x)
#define SOUNDIO_ATOMIC_FETCH_ADD(a, delta) atomic_fetch_add(&a.x, delta)
#define SOUNDIO_ATOMIC_STORE(a, value) atomic_store(&a.x, value)
#define SOUNDIO_ATOMIC_EXCHANGE(a, value) atomic_exchange(&a.x, value)

#endif

#endif
