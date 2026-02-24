#pragma once 

// Testing CI pipeline

class Vector3 {
public:
    float x, y, z;

    Vector3();
    Vector3(float x, float y, float z);

    Vector3(const Vector3& other);
    Vector3& operator=(const Vector3& other);

    // Operations
    bool operator==(const Vector3& other) const;
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(float scalar) const;

    float Magnitude() const;
    Vector3 Normalize() const;
    float Dot(const Vector3& other) const;
    Vector3 CrossMultiply(const Vector3& other) const;
};