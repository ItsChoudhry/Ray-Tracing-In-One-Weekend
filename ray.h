#ifndef RAY_H
#define RAY_H

#include "vec3.h"
class ray
{
  public:
    constexpr ray() = default;

    ray(const point3& origin, const vec3& direction) noexcept : orig(origin), dir(direction) {}

    [[nodiscard]] constexpr const point3& origin() const noexcept { return orig; }
    [[nodiscard]] constexpr const vec3&   direction() const noexcept { return dir; }

    [[nodiscard]] constexpr point3 at(double t) const noexcept { return orig + t * dir; }

    friend constexpr bool operator==(const ray& lhs, const ray& rhs) noexcept
    {
        return lhs.orig == rhs.orig && lhs.dir == rhs.dir;
    }

  private:
    point3 orig{0, 0, 0};
    vec3   dir{0, 0, 0};
};

#endif
