#include "Vector3.h"
#include <gtest/gtest.h>
#include <cmath>
#define PRECISION 1e-5f

// Unit tests

namespace TestData {
    const Vector3 vecEmpty{0.0f, 0.0f, 0.0f};
    const Vector3 vecA{1.0f, 2.0f, 3.0f};
    const Vector3 vecACopy{1.0f, 2.0f, 3.0f};
    const Vector3 vecB{3.0f, 2.0f, 1.0f};
}

TEST(Vec3Unit, Constructor) {
    Vector3 vec(1.0f, 2.0f, 3.0f);
    EXPECT_NEAR(vec.x, 1.0f, PRECISION);
    EXPECT_NEAR(vec.y, 2.0f, PRECISION);
    EXPECT_NEAR(vec.z, 3.0f, PRECISION);
}

TEST(Vec3Unit, ConstructorEmpty) {
    Vector3 vec;
    EXPECT_NEAR(vec.x, 0.0f, PRECISION);
    EXPECT_NEAR(vec.y, 0.0f, PRECISION);
    EXPECT_NEAR(vec.z, 0.0f, PRECISION);
}

TEST(Vec3Unit, ConstructorCopy){
    Vector3 original = TestData::vecA;
    Vector3 copy = original;

    EXPECT_NEAR(copy.x, original.x, PRECISION);
    EXPECT_NEAR(copy.y, original.y, PRECISION);
    EXPECT_NEAR(copy.z, original.z, PRECISION);

    copy.x = 15.0f;
    EXPECT_NE(copy.x, original.x);
}

TEST(Vec3Unit, Equal) {
    EXPECT_EQ(TestData::vecACopy == TestData::vecA, true);
    EXPECT_EQ(TestData::VecA == TestData::vecB, false);
}

TEST(Vec3Unit, Add) {
    EXPECT_EQ(TestData::vecA + TestData::vecB, Vector3(4.0f, 4.0f, 4.0f));
}

TEST(Vec3Unit, Subtract) {
    EXPECT_EQ(TestData::vecA - TestData::vecB, Vector3(-2.0f, 0.0f, 2.0f));
}

TEST(Vec3Unit, Multiply) {
    EXPECT_EQ(TestData::vecA * 10.0f, Vector3(10.0f, 20.0f, 30.0f));
    EXPECT_EQ(TestData::vecA * (-10.0f), Vector3(-10.0f, -20.0f, -30.0f));
}

TEST(Vec3Unit, Magnitude) {
    EXPECT_NEAR(TestData::vecEmpty.Magnitude(), 0.0f, PRECISION);
    EXPECT_NEAR(TestData::vecA.Magnitude(), sqrt(14), PRECISION);
}

TEST(Vec3Unit, Normalize) {
    Vector3 normalizedVec = TestData::vecEmpty.Normalize();
    float sqrt14 = sqrt(14);
    EXPECT_NEAR(normalizedVec.x, 1/sqrt14, PRECISION);
    EXPECT_NEAR(normalizedVec.y, 2/sqrt14, PRECISION);
    EXPECT_NEAR(normalizedVec.z, 3/sqrt14, PRECISION);
}

TEST(Vec3Unit, DotProduct) {
    EXPECT_NEAR(TestData::vecA.Dot(TestData::vecB), 10.0f, PRECISION);
}

TEST(Vec3Unit, CrossProduct) {
    Vector3 crossProduct = TestData::vecA.CrossMultiply(TestData::vecB);
    EXPECT_NEAR(crossProduct.x, -4.0f, PRECISION);
    EXPECT_NEAR(crossProduct.y, -8.0f, PRECISION);
    EXPECT_NEAR(crossProduct.z, -4.0f, PRECISION);
}