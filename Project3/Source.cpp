#include <iostream>
#include "Figure.h"
#include <math.h>
#include "windows.h"

using namespace std;

//���������� ��� ��������, ������ �� �������
bool zPressed = false;
bool xPressed = false;
bool spacePressed = false;
double dy = 0.0;
double height = 16.0;


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	//��� OX
	glColor3f(0, 0.2, 1);
	glVertex2f(-600, 0);
	glVertex2f(600, 0);
	//OY
	glColor3f(0, 1, 0);
	glVertex2f(0, -400);
	glVertex2f(0, 400);
	//OZ
	glColor3f(1, 0, 0);
	float vector[4] = { 0.0, 0.0, 600.0, 1.0 };
	float* projection = Matrices::multiply(vector, Matrices::proj);
	glVertex2f(0, 0);
	glVertex4f(projection[0], projection[1], projection[2], projection[3]);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	Figure::draw();
	glFlush();
	projection = nullptr;
}

void initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-350.0, 350.0, -300.0, 300.0, -10.0, 10.0);
}

//������
void timerFunc(int value) {
	float dir[3];
	dir[2] = 0.0;
	dir[0] = 1.0;
	dir[1] = height - dy;
	Figure::translate(dir);
	glutPostRedisplay();
	dy += 0.8;
	//���� ������ �� �������, ������ ��������� ������
	if (dy < height*2 + 0.8)
		glutTimerFunc(100, timerFunc, 1);
	//���� �������� � ������ ������ ���� ����� 0.2, ��������� ��������
	else if (height < 0.2) {
		height = 16.0;
		dy = 0;
	}
	//����� �������� ������ ������ � ����������
	else { 
		dy = 0; 
		height /= 1.7;
		glutTimerFunc(100, timerFunc, 1);
		}
}

void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_UP:
		//���� ������ ������� ����� x, ������������
		if (xPressed) Figure::scale(1 / 1.01f);
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
		break;
	case ' ':
		spacePressed = true;
		glutTimerFunc(100, timerFunc, 1);
		break;
	case 'w':
		if (zPressed) {
			dir[1] = dir[0] = 0;
			dir[2] = 0.3f;
		}
		else {
			//�������� �����
			dir[2] = dir[0] = 0;
			dir[1] = 0.3f;
		}
		Figure::translate(dir);
		break;
	case 'a':
		//�����
		dir[2] = dir[1] = 0;
		dir[0] = -0.3f;
		Figure::translate(dir);
		break;
	case 's':
		if (zPressed) {
			dir[1] = dir[0] = 0;
			dir[2] = -0.3f;
		}
		else {
			//����
			dir[2] = dir[0] = 0;
			dir[1] = -0.3f;
		}
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
		break;
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