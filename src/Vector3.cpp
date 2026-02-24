#include "Vector3.h"
#include <cmath>
#define EPSILON 1e-5f

// All the vector functionality has now been defined!

Vector3::Vector3()
    : x(0.0f), y(0.0f), z(0.0f) {}

Vector3::Vector3(float x, float y, float z) 
    : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector3& other) 
    : x(other.x), y(other.y), z(other.z) {}

bool Vector3::operator==(const Vector3& other) const {
    return std::abs(x - other.x) < EPSILON && 
            std::abs(y - other.y) < EPSILON && 
            std::abs(z - other.z) < EPSILON;
}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

float Vector3::Magnitude() const {
    return sqrt((x * x) + (y * y) + (z * z));
}

Vector3 Vector3::Normalize() const {
    float magnitude = this->Magnitude();
    if (magnitude < EPSILON) {
        return Vector3(0.0f, 0.0f, 0.0f);
    }
     return Vector3(x / magnitude, y / magnitude, z / magnitude);
}

float Vector3::Dot(const Vector3& other) const {
    return (x * other.x) + (y * other.y) + (z * other.z);
}

Vector3 Vector3::CrossMultiply(const Vector3& other) const {
    return Vector3(
        (y * other.z) - (z * other.y),
        (z * other.x) - (x * other.z),
        (x * other.y) - (y * other.x)
    );
}
