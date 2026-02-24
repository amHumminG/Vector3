#pragma once
#include <stdexcept>

class Vector3 {
public:
    float x, y, z;

    Vector3();
    Vector3(float x, float y, float z);

    // Operations
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(float scalar) const;

    Vector3 Normalize() const;
    float Magnitude() const;
    float Dot(const Vector3& other) const;
    Vector3 CrossMultiply(const Vector3& other) const;
};