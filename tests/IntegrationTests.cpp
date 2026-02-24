#include "Vector3.h"
#include <gtest/gtest.h>
#include <cmath>
#define PRECISION 1e-5f

TEST(Vec3Integration, ProjRefl) {
    Vector3 vecA(-7.0f, 4.0f, 1.0f);
    Vector3 vecB(3.0f, 2.0f, -1.0f);

    float nominator = vecA.Dot(vecB);
    float denominator = pow(vecA.Magnitude(), 2);
    float scale = nominator / denominator;
    
    Vector3 projection = vecA * scale;
    Vector3 reflection = (projection * 2) - vecB;

    EXPECT_NEAR(projection.x, 1.48484848f, PRECISION);
    EXPECT_NEAR(projection.y, -0.84848484f, PRECISION);
    EXPECT_NEAR(projection.z, -0.21212121f, PRECISION);

    EXPECT_NEAR(reflection.x, -0.03030303f, PRECISION);
    EXPECT_NEAR(reflection.y, -3.69696969f, PRECISION);
    EXPECT_NEAR(reflection.z, 0.57575757f, PRECISION);
}

TEST(Vec3Integration, RaySphereIntersection) {
    struct Ray {
        Vector3 origin;
        Vector3 direction;
    };

    struct Sphere {
        Vector3 centerPoint;
        float radius;

        bool Intersection(const Ray &ray, float &t) {
            Vector3 originToCenter = this->centerPoint - ray.origin; //Ray origin to sphere center
            bool originInsideSphere = false;
            float lSquare = originToCenter.Dot(originToCenter); // Length of l squared
            float rSquare = pow(this->radius, 2);

            if (lSquare < rSquare)
            {
                originInsideSphere = true; // Ray origin is inside the sphere
            }

            float s = originToCenter.Dot(ray.direction); // Length from ray origin to the point between the hit points.

            if (s < 0 && !originInsideSphere) // Whole sphere is behind ray origin
            {
                return false;
            }

            // m is line from centerPoint to the point between the hit points.
            float mSquare = lSquare - pow(s, 2);
            // If mSquare > rSquare: No intersetion
            // If mSquare = rSquare: One intersection
            // If mSquare < rSquare: Two intersections

            if (mSquare > rSquare)
            {
                return false;
            }

            float q = sqrt(rSquare - mSquare); // Half the length between the hitpoints.

            if (!originInsideSphere)
            {
                t = s - q; // First hit point
            }
            else
            {
                t = s + q; // Second hit point
            }

            return true;
        }
    };

    Ray ray;
    ray.origin = Vector3(0.0f, 0.0f, 0.0f);
    ray.direction = Vector3(1.0f, 0.0f, 0.0f).Normalize();

    Sphere sphereA;
    sphereA.centerPoint = (5.0f, 0.0f, 0.0f);
    sphereA.radius = 1.0f;

    Sphere sphereB;
    sphereB.centerPoint = (5.0f, 2.0f, 0.0f);
    sphereB.radius = 2.0f;

    Sphere sphereC;
    sphereC.centerPoint = (5.0f, 10.0f, 0.0f);
    sphereC.radius = 1.0f;

    float t = 0.0f;
    EXPECT_EQ(sphereA.Intersection(ray, t), true); // Intersect center
    EXPECT_EQ(sphereB.Intersection(ray, t), true); // Intersect edge
    EXPECT_EQ(sphereC.Intersection(ray, t), false); // Miss
}

TEST(Vec3Integration, TriangleNormal) {
    Vector3 A(0,0,0);
    Vector3 B(2,0,0);
    Vector3 C(0,2,0);

    Vector3 edge1(B - A);
    Vector3 edge2(C - A);

    Vector3 normal = edge1.CrossMultiply(edge2).Normalize();

    EXPECT_EQ(normal == Vector3(0.0f, 0.0f, 1.0f), true);
}
