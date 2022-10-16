//Assignment : generate snowflake curve

#include <GL/glut.h>
#include <math.h>

GLfloat prevx=-0.7;
GLfloat prevy=0.5;

void curve(GLfloat dir,GLfloat l,GLint cnt) {
	GLdouble dirRad = 0.0174533 * dir;  
	GLfloat X = prevx + l * cos(dirRad);
	GLfloat Y = prevy + l * sin(dirRad);
  
	if (cnt==0) {
		glVertex2f(prevx, prevy);
		glVertex2f(X, Y);
		prevx = X;
		prevy = Y;
	}
	else {
		cnt--;
		//draw the four parts of the side _/\_ 
		curve(dir, l, cnt);
		dir += 60.0;
		curve(dir, l, cnt);
		dir -= 120.0;
		curve(dir, l, cnt);
		dir += 60.0;
		curve(dir, l, cnt);
	}
}

void display(){
  
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINES);
	 glColor3f(1.0, 0.0, 0.0); // red color lines
	 
	 curve(0.0,0.05,3);
	 curve(-120.0, 0.05, 3);  //for snowflake
	 curve(120.0,0.05,3);     //for snowflake
	 glEnd();
	 glFlush(); 
  
}

int main(int argc, char** argv){
  
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);      
	glutInitWindowSize(500,500);    	
	glutInitWindowPosition(0,0); 
	glutCreateWindow("Snowflake curve");     
	glutDisplayFunc(display);  
	glutMainLoop();
  
  return 0;
}
