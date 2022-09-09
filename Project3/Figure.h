#pragma once
#include "glut.h"
#include "Matrices.h"

class Figure {
public:
	static float figure[34][4];

	static void draw();
	static void rotateX(float angle);
	static void rotateY(float angle);
	static void rotateZ(float angle);
	static void translate(float direction[]);
	static void scale(float amount);
};

