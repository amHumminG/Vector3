#include "Vector3.h"
#include <gtest/gtest.h>
#include <cmath>
#define PRECISION 1e-5f

TEST(Vec3Integration, ProjRefl) {
    // Setup
    Vector3 vecA(-7.0f, 4.0f, 1.0f);
    Vector3 vecB(3.0f, 2.0f, -1.0f);

    // Exercise
    float nominator = vecA.Dot(vecB);
    float denominator = pow(vecA.Magnitude(), 2);
    float scale = nominator / denominator;
    
    Vector3 projection = vecA * scale;
    Vector3 reflection = (projection * 2) - vecB;

    // Verify projection
    EXPECT_NEAR(projection.x, 1.48484848f, PRECISION);
    EXPECT_NEAR(projection.y, -0.84848484f, PRECISION);
    EXPECT_NEAR(projection.z, -0.21212121f, PRECISION);

    // Verify reflection
    EXPECT_NEAR(reflection.x, -0.03030303f, PRECISION);
    EXPECT_NEAR(reflection.y, -3.69696969f, PRECISION);
    EXPECT_NEAR(reflection.z, 0.57575757f, PRECISION);
}