#include <iostream>
#include "Figure.h"
#include <math.h>

using namespace std;

//���������� ��� ��������, ������ �� �������
bool zPressed = false;
bool xPressed = false;


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	Figure::draw();
	glFlush();
}

void initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-400.0, 400.0, -400.0, 400.0, -5.0, 5.0);
}

void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_UP:
		//���� ������ ������� ����� x, ������������
		if (xPressed) Figure::scale(1/1.01f);
		//����� ������������ ������ ��� �
		else Figure::rotateX(0.05f);
		break;
	case GLUT_KEY_DOWN:
		//�� ��, �� �� ������� �������
		if (xPressed) Figure::scale(1.01f);
		else Figure::rotateX(-0.05f);
		break;
	case GLUT_KEY_LEFT:
		//���� ������ z, ������������ ������ ��� Z
		if (zPressed) Figure::rotateZ(0.05);
		//����� - ������ Y
		else Figure::rotateY(0.05f);
		break;
	case GLUT_KEY_RIGHT:
		//�� ��, �� �� ������� �������
		if (zPressed) Figure::rotateZ(-0.05);
		else Figure::rotateY(-0.05f);
		break;
	}
}

void processNormalKeys(unsigned char key, int x, int y) {
	float dir[3];
	switch (key) {
	case 'z':
		zPressed = true;
		break;
	case 'x':
		xPressed = true;

	case 'w':
		//�������� �����
		dir[2] = dir[0] = 0;
		dir[1] = 0.3f;
		Figure::translate(dir);
		break;
	case 'a':
		//�����
		dir[2] = dir[1] = 0;
		dir[0] = -0.3f;
		Figure::translate(dir);
		break;
	case 's':
		//����
		dir[2] = dir[0] = 0;
		dir[1] = -0.3f;
		Figure::translate(dir);
		break;
	case 'd':
		//������
		dir[2] = dir[1] = 0;
		dir[0] = 0.3f;
		Figure::translate(dir);
		break;
	}
}

void keyUp(unsigned char key, int x, int y) {
	//���� ������ �� ������ �������
	switch (key) {
	case 'z':
		zPressed = false;
		break;	
	case 'x':
		xPressed = false;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 750);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("WebWindow");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(processNormalKeys);
	glutKeyboardUpFunc(keyUp);
	glutSpecialFunc(processSpecialKeys);
	initialize();
	glutMainLoop();
	return 0;
}