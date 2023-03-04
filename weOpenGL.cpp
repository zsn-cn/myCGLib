#include "weOpenGL.h"

int mouseX = 0, mouseY = 0;

float viewpointX = 0, viewpointY = 0;

void weDraw()
{
	int viewportArg[4];

	int viewportWidth = 0, viewportHeight = 0;

	glGetIntegerv(GL_VIEWPORT, viewportArg);
	viewportWidth = viewportArg[2];
	viewportHeight = viewportArg[3];

	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (viewportWidth > viewportHeight)
	{
		glOrtho(-(double)viewportWidth / (double)viewportHeight, (double)viewportWidth / (double)viewportHeight, -1.0, 1.0, -1.0, 1.0);
	}
	else
	{
		glOrtho(-1.0, 1.0, -(double)viewportWidth / (double)viewportHeight, (double)viewportWidth / (double)viewportHeight, -1.0, 1.0);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(viewpointX, 1.f, 0.f, 0.f);
	glRotatef(viewpointY, 0.f, 1.f, 0.f);

	//绘制坐标系
	drawCoordinate();

	//清理该帧绘制，准备绘制下一帧
	glFlush();
	glutSwapBuffers();
}

void drawCoordinate()
{
	glLineWidth(3.0f);
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_LINES);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(1.f, 0.f, 0.f);
	glEnd();
	glLineWidth(3.0f);
	glColor3f(0.f, 1.f, 0.f);
	glBegin(GL_LINES);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 1.f, 0.f);
	glEnd();
	glLineWidth(3.0f);
	glColor3f(0.f, 0.f, 1.f);
	glBegin(GL_LINES);
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 1.f);
	glEnd();
}

void weReshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

void weMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseX = x;
		mouseY = y;
	}
}

void weMotion(int x, int y)
{
	int offsetX = 0, offsetY = 0;

	offsetX = x - mouseX;
	offsetY = y - mouseY;

	viewpointX += offsetX * 0.05f;
	viewpointY += offsetY * 0.05f;

	mouseX = x;
	mouseY = y;

	glutPostRedisplay();
}
