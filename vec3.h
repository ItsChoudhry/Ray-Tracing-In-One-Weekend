#ifndef VEC3_H
#define VEC3_H

#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <ostream>

class vec3
{
  private:
    std::array<double, 3> e;

  public:
    constexpr vec3() noexcept : e{.0, .0, .0} {}
    constexpr vec3(double e0, double e1, double e2) noexcept : e{e0, e1, e2} {}

    [[nodiscard]] constexpr double x() const noexcept { return e[0]; }
    [[nodiscard]] constexpr double y() const noexcept { return e[1]; }
    [[nodiscard]] constexpr double z() const noexcept { return e[2]; }

    constexpr vec3 operator-() const noexcept { return vec3(-e[0], -e[1], -e[2]); }

    constexpr vec3& operator+=(const vec3& v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    constexpr vec3& operator-=(const vec3& v)
    {
        e[0] -= v.e[0];
        e[1] -= v.e[1];
        e[2] -= v.e[2];
        return *this;
    }

    constexpr vec3& operator*=(double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    constexpr vec3& operator/=(double t)
    {
        assert(t != 0.0 && "Division by zero");
        return *this *= 1 / t;
    }

    [[nodiscard]] constexpr double length_squared() const noexcept { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

    [[nodiscard]] constexpr double length() const noexcept { return std::sqrt(length_squared()); }

#ifdef NDEBUG
    constexpr double  operator[](std::size_t i) const noexcept { return e[i]; }
    constexpr double& operator[](std::size_t i) noexcept { return e[i]; }
#else
    double operator[](std::size_t i) const noexcept
    {
        assert(i < 3 && "Index out of bounds");
        return e[i];
    }
    double& operator[](std::size_t i) noexcept
    {
        assert(i < 3 && "Index out of bounds");
        return e[i];
    }
#endif
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) noexcept
{
    return out << v.x() << " " << v.y() << " " << v.z();
}

inline constexpr vec3 operator+(const vec3& u, const vec3& v) noexcept
{
    return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline constexpr vec3 operator-(const vec3& u, const vec3& v) noexcept
{
    return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline constexpr vec3 operator*(const vec3& u, const vec3& v) noexcept
{
    return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline constexpr vec3 operator*(double t, const vec3& v) noexcept
{
    return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline constexpr vec3 operator*(const vec3& v, double t) noexcept
{
    return t * v;
}

inline constexpr vec3 operator/(const vec3& v, double t) noexcept
{
    assert(t != 0.0 && "Division by zero");
    return (1 / t) * v;
}

inline constexpr double dot(const vec3& u, const vec3& v) noexcept
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}
// clang-format off
inline constexpr  vec3 cross(const vec3& u, const vec3& v) noexcept
{
    return vec3(
        u.y() * v.z() - u.z() * v.y(),
        u.z() * v.x() - u.x() * v.z(),
        u.x() * v.y() - u.y() * v.x());
}
// clang-format on

inline constexpr vec3 unit_vector(const vec3& v) noexcept
{
    auto len = v.length();
    assert(len != 0.0 && "Zero-length vector");
    return v / v.length();
}

inline constexpr bool operator==(const vec3& u, const vec3& v) noexcept
{
    constexpr double epsilon = 1e-10;
    return std::abs(u.x() - v.x()) < epsilon && std::abs(u.y() - v.y()) < epsilon && std::abs(u.z() - v.z()) < epsilon;
}
inline constexpr bool operator!=(const vec3& u, const vec3& v) noexcept
{
    return !(u == v);
}
#endif

