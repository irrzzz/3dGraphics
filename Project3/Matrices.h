#pragma once
#include <math.h>

class Matrices {
public:
	static float rotationX[4][4];
	static float rotationY[4][4];
	static float rotationZ[4][4];
	static float translation[4][4];
	static float scaling[4][4];
	static float proj[4][4];

	static float* multiply(float vec[], float matrix[][4]);
	static void changeAngleX(float angle);
	static void changeAngleY(float angle);
	static void changeAngleZ(float angle);
	static void setDirection(float direction[]);
	static void setScaling(float amount);
};



