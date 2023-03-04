#pragma once
#include <iostream>
#include <GL/freeglut.h>

using namespace std;

void weDraw();

void drawCoordinate();

void weReshape(int w, int h);

void weMouse(int button, int state, int x, int y);

void weMotion(int x, int y);

void weKeyboard();