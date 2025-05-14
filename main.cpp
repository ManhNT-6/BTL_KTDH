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

	if (!triangle.IsTriangle())  
	{
		cout << "Triangle Invalid" << endl;
		return 0;
	}
	
	int typeRotate;    
	cout << "Quay quanh goc toa do (0) | Quay quanh 1 diem bat ky (1) " ;
	cin >> typeRotate;
	
	float xq = 0;
	float yq = 0;
	
	if (typeRotate)	
	{
		cout << "Nhap toa do tam quay: " ;
		cin >> xq >> yq;
	}
	
	float angle;
	cout << "Nhap goc quay: " ;
	cin >> angle;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Draw Triangle");
	initPanel();
	
	triangle.RotateAroundAPoint(xq,yq,angle);
	triangle.DrawTriangle(); 
		
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
