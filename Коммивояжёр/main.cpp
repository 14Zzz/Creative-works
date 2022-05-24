#include "Header.h"
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	glutInit(&argc, argv);
	graph = graph_implementation();
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Задача коммивояжера");
	Win_W = glutGet(GLUT_WINDOW_WIDTH);
	Win_H = glutGet(GLUT_WINDOW_HEIGHT);
	glutDisplayFunc(watch_display);
	glutReshapeFunc(reshape);
	glutMouseFunc(button_click);
	glutMainLoop();
	return 0;
}
