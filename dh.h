/*
 * File Name: mul_mod.h
 * Author: Stan.Lch
 * Mail: fn.stanc@gmail.com
 * Created Time: 2018/4/25 0:12:39
 */

#ifndef _mul_mod_H
#define _mul_mod_H

#include <cassert>
#include <cstdint>
#include <random>

// a * b % n
inline uint64_t _mul_mod(uint64_t a, uint64_t b, uint64_t n) {
    assert(a < n);
    uint64_t res = 0;
    while (b) {
        if (b & 1) {
            uint64_t t = n - a;
            if (res >= t) {
                res -= t;
            } else {
                res += a;
            }
        }

        if (a >= n - a) {
            a = a - (n - a);
        } else {
            a += a;
        }
        b >>= 1;
    }
    return res;
}

inline uint64_t _pow_mod(uint64_t a, uint64_t b, uint64_t n) {
    assert(a < n);
    if (b == 1) return a;
    uint64_t r = _pow_mod(a, b >> 1, n);
    r = _mul_mod(r, r, n);
    if (b & 1) {
        r = _mul_mod(r, a, n);
    }
    return r;
}

// (a ^ b) % n
inline uint64_t pow_mod(uint64_t a, uint64_t b, uint64_t n) {
    if (a > n) a %= n;
    return _pow_mod(a, b, n);
}

#define G 5
#define P 0xffffffffffffffc5ull

inline uint64_t rand_uint64() {
    static thread_local std::mt19937 rg(std::random_device{}());
    static thread_local std::uniform_int_distribution<uint64_t> dist(0, P);
    return dist(rg);
}

inline void dh_gen_keypair(uint64_t *private_key, uint64_t *public_key) {
    *private_key = rand_uint64();
    *public_key = pow_mod(G, *private_key, P);
}

inline uint64_t dh_gen_secret(uint64_t my_private_key,
                              uint64_t another_public_key) {
    return pow_mod(another_public_key, my_private_key, P);
}

#undef G
#undef P

#endif
