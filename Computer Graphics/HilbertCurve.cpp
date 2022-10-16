#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

class Hilbert{
private:
  float xp,yp;
public:
	Hilbert(){
		xp = INT_MIN;
		yp = INT_MIN;
	}	
	
	void LineTo(float x1,float y1){
		if(xp == INT_MIN){
			xp = x1;
			yp = y1;
			return;
		}
		glBegin(GL_LINES);
		glVertex2f(xp,yp);		
		glVertex2f(x1,y1);
		glEnd();
		glFlush();
		xp = x1;
		yp = y1;
	}

	void HilbertCurve(float x , float y ,float xi ,float yi ,float xj ,float yj , int order ){
		if(order <= 0){
			float x1 = x + (xi+yi)/2;
			float y1 = y + (xj+yj)/2;
			LineTo(x1,y1);		
		}else{
			HilbertCurve(x, y, yi/2, yj/2, xi/2, xj/2, order-1);
			HilbertCurve(x+xi/2, y+xj/2, xi/2, xj/2, yi/2, yj/2, order-1);
			HilbertCurve(x+xi/2+yi/2, y+xj/2+yj/2, xi/2, xj/2, yi/2, yj/2, order-1);
			HilbertCurve(x+xi/2+yi, y+xj/2+yj, -yi/2, -yj/2, -xi/2, -xj/2, order-1);		
		}
	}
};

void init(){
	glClearColor (0.0,0.0,0.0,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0,800.0, 0.0, 800.0);
}
void MYdisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glFlush();
	cout<<"Enter order of the curve : ";
  
	int order;
	cin>>order;
  
	Hilbert h;
	h.HilbertCurve(0,0,800,0,0,800,order);
}
int main(int argc,char *argv[]){
	glutInit(&argc,argv);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (00, 00);
	glutCreateWindow ("WINDOW");
	init();
	glutDisplayFunc(MYdisplay);
	glutMainLoop();
	return 0;
}
