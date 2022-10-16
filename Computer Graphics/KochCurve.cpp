//Assignment : Generate Koch Curve
#include <GL/glut.h>
#include <math.h>

float prevx=100;
float prevy=400;

void koch_curve(float dir,float l,GLint cnt) {
	GLdouble dirRad = 0.0174533 * dir;  
	float X = prevx + l * cos(dirRad);
	float Y = prevy + l * sin(dirRad);
	if (cnt==0) {
		glVertex2f(prevx, prevy);
		glVertex2f(X, Y);
		prevx = X;
		prevy = Y;
	}
	else {
		cnt--;
		koch_curve(dir, l, cnt);
		dir += 60.0;
		koch_curve(dir, l, cnt);
		dir -= 120.0;
		koch_curve(dir, l, cnt);
		dir += 60.0;
		koch_curve(dir, l, cnt);
	}
}

void display(){
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINES);
	 glColor3f(1.0, 0.0, 0.0); 
	 koch_curve(0.0,10,5);
	 glEnd();
	 glFlush(); 
}

void init(void){
 glClearColor(1.0,1.0,1.0,0.0);
 glClear(GL_COLOR_BUFFER_BIT);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,700,0,700);
 glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);      
	glutInitWindowSize(1000,1000);    	
	glutInitWindowPosition(0,0); 
	glutCreateWindow("Koch Curve");   
	init();  
	glutDisplayFunc(display);  
	glutMainLoop();
}
