#ifndef VEC3_H
#define VEC3_H

#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>

class vec3
{
  private:
    std::array<double, 3> e;

  public:
    constexpr vec3() noexcept : e{.0, .0, .0} {}
    constexpr vec3(double e0, double e1, double e2) noexcept : e{e0, e1, e2} {}

    [[nodiscard]] double x() const noexcept { return e[0]; }
    [[nodiscard]] double y() const noexcept { return e[1]; }
    [[nodiscard]] double z() const noexcept { return e[2]; }

    vec3 operator-() const noexcept { return vec3(-e[0], -e[1], -e[2]); }

    vec3 &operator+=(const vec3 &v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3 &operator*=(double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3 &operator/=(double t) { return *this *= 1 / t; }

    [[nodiscard]] double length_squared() const noexcept { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

    [[nodiscard]] double length() const noexcept { return std::sqrt(length_squared()); }

#ifdef NDEBUG
    double  operator[](std::size_t i) const noexcept { return e[i]; }
    double &operator[](std::size_t i) noexcept { return e[i]; }
#else
    double operator[](std::size_t i) const noexcept
    {
        assert(i < 3 && "Index out of bounds");
        return e[i];
    }
    double &operator[](std::size_t i) noexcept
    {
        assert(i < 3 && "Index out of bounds");
        return e[i];
    }
#endif
};

using point3 = vec3;

#endif

