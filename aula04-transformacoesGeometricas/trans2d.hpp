#ifndef TRANS2D_H_INCLUDED
#define TRANS2D_H_INCLUDED
#include <Eigen/Dense>
#include <cmath>

using namespace Eigen;
#define __PI__ 3.14159265359

float degree2rad(float d)
{
    return ((d * __PI__ )/ 180.0f);
}


Matrix3f getTranslation(float tx, float ty)
{
    Matrix3f M = Matrix3f::Identity();
    M(0,2) = tx;
    M(1,2) = ty;

    return M;
}

Matrix3f getScale(float sx, float sy)
{
    Matrix3f M = Matrix3f::Identity();
    M(0,0) = sx;
    M(1,1) = sy;

    return M;
}

Matrix3f getRotation(float d)
{
    float s = sin(degree2rad(d));
    float c = cos(degree2rad(d));

    Matrix3f M = Matrix3f::Identity();
    M(0,0) = c;
    M(0,1) = -s;
    M(1,0) = s;
    M(1,1) = c;

    return M;
}

Matrix3f getShear(float s, char mode)
{
    Matrix3f M = Matrix3f::Identity();

    if (toupper(mode) == 'H')
        M(0,1) = s;
    else if (toupper(mode) == 'V')
        M(1,0) = s;
    else
        return Matrix3f::Zero();

    return M;
}

#endif