#include <iostream>
#include "Figure.h"

using namespace std;

float Figure::figure[34][4] = {
	-40,  50,  0, 1,
	  0,  50,  0, 1,
	 10,  40,  0, 1,
	 10,  10,  0, 1,
	  0,   0,  0, 1,
	 10, -10,  0, 1,
	 10, -40,  0, 1,
	  0, -50,  0, 1,
	-40, -50,  0, 1,
	-40, -30,  0, 1,
	-10, -30,  0, 1,
	-10, -10,  0, 1,
	-40, -10,  0, 1,
	-40,  10,  0, 1,
	-10,  10,  0, 1,
	-10,  30,  0, 1,
	-40,  30,  0, 1,

	-40,  50, 20, 1,
	  0,  50, 20, 1,
	 10,  40, 20, 1,
	 10,  10, 20, 1,
	  0,   0, 20, 1,
	 10, -10, 20, 1,
	 10, -40, 20, 1,
	  0, -50, 20, 1,
	-40, -50, 20, 1,
	-40, -30, 20, 1,
	-10, -30, 20, 1,
	-10, -10, 20, 1,
	-40, -10, 20, 1,
	-40,  10, 20, 1,
	-10,  10, 20, 1,
	-10,  30, 20, 1,
	-40,  30, 20, 1,
};

void Figure::draw() {
	float* projection = nullptr;
	glPointSize(2);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 17; i++) {
		projection = Matrices::multiply(figure[i], Matrices::proj);
		glVertex3f(projection[0], projection[1], projection[2]);
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	for (int i = 17; i < 34; i++) {
		projection = Matrices::multiply(figure[i], Matrices::proj);
		glVertex3f(projection[0], projection[1], projection[2]);
	}
	glEnd();

	glBegin(GL_LINES);
	for (int i = 0; i < 17; i++) {
		projection = Matrices::multiply(figure[i], Matrices::proj);
		glVertex3f(projection[0], projection[1], projection[2]);
		projection = Matrices::multiply(figure[i + 17], Matrices::proj);
		glVertex3f(projection[0], projection[1], projection[2]);
	}
	glEnd();
}

void Figure::rotateX(float angle) {
	for (int i = 0; i < 34; i++) {
		Matrices::changeAngleX(angle);
		float* res = Matrices::multiply(figure[i], Matrices::rotationX);
		for (int j = 0; j < 4; j++) {
			figure[i][j] = res[j];
		}
	}
}

void Figure::rotateY(float angle) {
	for (int i = 0; i < 34; i++) {
		Matrices::changeAngleY(angle);
		float* res = Matrices::multiply(figure[i], Matrices::rotationY);
		for (int j = 0; j < 4; j++) {
			figure[i][j] = res[j];
		}
	}
}

void Figure::rotateZ(float angle) {
	for (int i = 0; i < 34; i++) {
		Matrices::changeAngleZ(angle);
		float* res = Matrices::multiply(figure[i], Matrices::rotationZ);
		for (int j = 0; j < 4; j++) {
			figure[i][j] = res[j];
		}
	}
}

void Figure::translate(float direction[]) {
	for (int i = 0; i < 34; i++) {
		Matrices::setDirection(direction);		
		float* res = Matrices::multiply(figure[i], Matrices::translation);
		for (int j = 0; j < 4; j++) {
			figure[i][j] = res[j];
		}
	}
}

void Figure::scale(float amount) {
	for (int i = 0; i < 34; i++) {
		Matrices::setScaling(amount);
		float* res = Matrices::multiply(figure[i], Matrices::scaling);
		for (int j = 0; j < 4; j++) {
			figure[i][j] = res[j];
		}
	}
}