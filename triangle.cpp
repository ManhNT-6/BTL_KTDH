#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
public:
    float point[3][2]; 

    void input() {
        cout << "Nhap toa do 3 dinh (x,y) cua tam giac trong pixel (x,y trong [0, 500])." << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Dinh " << i + 1 << ": ";
            cin >> point[i][0] >> point[i][1];
        }
    }
    
    bool IsTriangle(){
    	float x1 = point[0][0], y1 = point[0][1];
        float x2 = point[1][0], y2 = point[1][1];
        float x3 = point[2][0], y3 = point[2][1];

        float area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

        return abs(area) > 0;
	} 

    void drawPoint(int x, int y) {
        glPointSize(1.0f); 
        glBegin(GL_POINTS);
        glVertex2i(x, y); 
        glEnd();
    }

    void DrawLineBetween2Points(int x1, int y1, int x2, int y2) {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = (x1 < x2) ? 1 : -1;
        int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            drawPoint(x1, y1); 

            if (x1 == x2 && y1 == y2) break;

            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }

    void DrawTriangle() {
        glColor3f(1.0, 1.0, 1.0);
        DrawLineBetween2Points(point[0][0], point[0][1], point[1][0], point[1][1]);
        DrawLineBetween2Points(point[1][0], point[1][1], point[2][0], point[2][1]);
        DrawLineBetween2Points(point[2][0], point[2][1], point[0][0], point[0][1]);
    }

    void DrawSolidTriangle() {
        glColor3f(0.0, 0.5, 0.0); 
        glBegin(GL_TRIANGLES);
        glVertex2i(round(point[0][0]), round(point[0][1]));
        glVertex2i(round(point[1][0]), round(point[1][1]));
        glVertex2i(round(point[2][0]), round(point[2][1]));
        glEnd();
    }
};

Triangle triangle;

void init() {
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
	
	    init();
	    glutDisplayFunc(display);
	    glutMainLoop();
	}
	else cout << "Khong the tao thanh tam giac"; 
	return 0;
}
