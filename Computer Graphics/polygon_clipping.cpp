#include<bits/stdc++.h>
#include<GL/glut.h>
#define MAX 100
using namespace std;
int width=480;
int height=640;
float bx,by,tx,ty;
int n;
float ar[MAX][2];
float ans[MAX][2];

void draw(){
	glBegin(GL_LINE_LOOP);
     for(int i=0;i<n;i++){
     	glVertex2f(ar[i][0],ar[i][1]);
     }  
    glEnd();
    glFlush();
}

void init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
}

float x_intersect(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4){
  float x=((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4 - y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
  return x;
}

float y_intersect(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4){
  float y=((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4 - y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
  return y;
}


void clip(float x1,float y1,float x2,float y2){
	
	float new_points[MAX][2];
	int new_poly=0;

	for(int i=0;i<n;i++){
		int k=(i+1)%n;
		float ix=ar[i][0],iy=ar[i][1];
		float kx=ar[k][0],ky=ar[k][1];

		int i_pos=(x2-x1)*(iy-y1)-(y2-y1)*(ix-x1);
		int k_pos=(x2-x1)*(ky-y1)-(y2-y1)*(kx-x1);
        
        if(i_pos <0 && k_pos<0){
           new_points[new_poly][0]=kx;
           new_points[new_poly][1]=ky;
           new_poly++;
        }
        else if(i_pos >=0 && k_pos<0){
        	new_points[new_poly][0]=x_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
        	new_points[new_poly][1]=y_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
        	new_poly++;
        	
          new_points[new_poly][0]=kx;
        	new_points[new_poly][1]=ky;
        	new_poly++;
        }
        else if(i_pos <0 && k_pos>=0){
        	new_points[new_poly][0]=x_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
        	new_points[new_poly][1]=y_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
        	new_poly++;
        }
        else{

        }

	}
  
  n=new_poly;
  for(int i=0;i<new_poly;i++){
  	ar[i][0]=new_points[i][0];
  	ar[i][1]=new_points[i][1];
  }

}


void SuthHodgClip(){

		clip(bx,by,bx,ty);
		clip(bx,ty,tx,ty);
		clip(tx,ty,tx,by);
		clip(tx,by,bx,by);
    
    glColor3f(1.0,0,0);
  draw();
}


void window(){
  cout<<"Enter the windows coordinates:";
  cin>>bx>>by>>tx>>ty;
  glBegin(GL_LINE_LOOP);
   glVertex2f(bx,by);
   glVertex2f(tx,by);
   glVertex2f(tx,ty);
   glVertex2f(bx,ty);
  glEnd();
  glFlush();
}




void figure(){
	cout<<"Enter number of vertices: ";
	cin>>n;
    cout<<"\nEnter the coordinates of the vertices:";
    for(int i=0;i<n;i++){
    	cin>>ar[i][0]>>ar[i][1];
    }
    draw();
    SuthHodgClip();
}




void display(void){
glClear(GL_COLOR_BUFFER_BIT);
window();
figure();
}

int main(int argc,char **argv){
	glutInit(&argc,argv);
    glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("POLYGON CLIPPING");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
