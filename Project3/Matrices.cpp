#include "Matrices.h"

float Matrices::rotationX[4][4] = {
	1,     0,         0,     0,
	0, cos(0.05f), sin(0.05f), 0,
	0,-sin(0.05f), cos(0.05f), 0,
	0,     0,         0,     1
};

float Matrices::rotationY[4][4] = {
	cos(0.05f), 0,-sin(0.05f), 0,
		0,     1,     0,     0,
	sin(0.05f), 0, cos(0.05f), 0,
		0,     0,     0,     1
};

float Matrices::rotationZ[4][4] = {
	cos(0.05f), sin(0.05f),0, 0,
   -sin(0.05f), cos(0.05f),0, 0,
		0,           0,    1, 0,
		0,           0,    0, 1
};

float Matrices::translation[4][4] = {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
};

float Matrices::scaling[4][4] = {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
};

float Matrices::proj[4][4] = {
	1, 0, 0,   0,
	0, 1, 0,   0,
	0, 0, 0, 0.004,
	0, 0, 0,   1
};

float* Matrices::multiply(float vec[], float matrix[][4]) {
	float res[4];
	for (int i = 0; i < 4; i++) {
		res[i] = 0;
		for (int j = 0; j < 4; j++) {
			res[i] += matrix[j][i] * vec[j];
		}
	}
	//нормализуем вектор (для n=1)
	for (int i = 0; i < 4; i++) {
		res[i] /= res[3];
	}
	return res;
}

void Matrices::changeAngleX(float angle) {
	rotationX[1][1] = cos(angle);
	rotationX[1][2] = sin(angle);
	rotationX[2][1] = -sin(angle);
	rotationX[2][2] = cos(angle);
}

void Matrices::changeAngleY(float angle) {
	rotationY[0][0] = cos(angle);
	rotationY[0][2] = -sin(angle);
	rotationY[2][0] = sin(angle);
	rotationY[2][2] = cos(angle);
}

void Matrices::changeAngleZ(float angle) {
	rotationZ[0][0] = cos(angle);
	rotationZ[0][1] = sin(angle);
	rotationZ[1][0] = -sin(angle);
	rotationZ[1][1] = cos(angle);
}

void Matrices::setDirection(float direction[]) {
	translation[3][0] = direction[0];
	translation[3][1] = direction[1];
	translation[3][2] = direction[2];
}

void Matrices::setScaling(float amount) {
	scaling[0][0] = scaling[1][1] = scaling[2][2] = amount;
}
