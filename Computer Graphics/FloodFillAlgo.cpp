#include <iostream>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
using namespace std;

struct Point {
	GLint x;
	GLint y;
};

int n,x,y;

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

Color getPixelColor(GLint x, GLint y) {
  
	Color c;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &c);
	return c; 
}

void setPixelColor(GLint x, GLint y, Color c) {
  
	glColor3f(c.r, c.g, c.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void FloodFill(GLint x, GLint y, Color prevColor, Color color) {
	Color c;
	c = getPixelColor(x, y);

	if(c.r == prevColor.r && c.g == prevColor.g && c.b == prevColor.b){
		setPixelColor(x, y, color);
		FloodFill(x+1, y, prevColor, color);
		FloodFill(x-2, y, prevColor, color);
		FloodFill(x, y+2, prevColor, color);
		FloodFill(x, y-2, prevColor, color);
  }  
}

void on_mouse_click(int b, int st, int x, int y){ 
  
  y=480-y;
	Color color = {1.0f, 0.0f, 0.0f};
	Color prevColor = {1.0f, 1.0f, 1.0f};   
    if(b==GLUT_LEFT_BUTTON){
        if(st==GLUT_DOWN){
            floodFill(x, y, prevColor, color);
        }
    }
}

void ff(){
  
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    cout<<" Enter the value of n : ";
    cin>>n;
    cout<<" enter n coordinates of the shape : \n";
    glBegin(GL_LINE_LOOP);
     for(int i=0;i<n;i++){
        cin>>x>>y;
        glVertex2i(x,y);        
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("FloodFill");
	init();
	glutDisplayFunc(ff);
	glutMouseFunc(on_mouse_click);
	glutMainLoop();
	return 0;
}
