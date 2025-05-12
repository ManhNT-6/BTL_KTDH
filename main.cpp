#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "Triangle.h" 
using namespace std;


Triangle triangle;

void initPanel() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // triangle.DrawSolidTriangle();
    triangle.DrawTriangle();
    glFlush();
}

int main(int argc, char** argv) {
    triangle.input();

	if (triangle.IsTriangle()) {
	    glutInit(&argc, argv);
	    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	    glutInitWindowSize(500, 500);
	    glutCreateWindow("Draw Triangle");
	
	    initPanel();
	    
	    cout << "Nhap goc quay: ";
		float angle;
		cin >> angle;
		triangle.RotateAroundOrigin(angle);
		triangle.DrawTriangle(); 
		
		glutDisplayFunc(display);
	    glutMainLoop();
	}
	else cout << "Khong the tao thanh tam giac"; 
	
	return 0;
}
