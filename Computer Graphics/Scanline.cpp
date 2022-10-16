#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int x[2],y[2],a;
	friend istream & operator >>(istream &in, Edge &e){
		cout<<"Enter Starting and Ending point : ";
		in>>e.x[0]>>e.y[0]>>e.x[1]>>e.y[1];
		e.a = 0;
		if (e.y[0] > e.y[1]){
			swap(e.x[0],e.x[1]);
			swap(e.y[0],e.y[1]);
		}
		return in;
	}
};

bool cmp(const Edge &a, const Edge &b){
		if (a.y[0]<b.y[0])
			return true;
		if (b.y[0] < a.y[0])
			return false;
		return a.y[1]<b.y[1];
}

class Polygon{
  
	private :
	vector<Edge> edges;
	int n;
  
	public :
	Polygon(){
		cout<<"Enter the number of edges : ";
		cin>>n;
    
		for (int i = 0; i<n; i++){
			Edge a;
			cin>>a;
			edges.push_back(a);
		}
    
		sort(edges.begin(), edges.end(),cmp);
    
	}
  
	void drawPolygon(){
    
		for (int i =0; i<n; i++){
			cout<<edges[i].x[0]<<" "<<edges[i].y[0]<<" "<<edges[i].x[1]<<" "<<edges[i].y[1]<<endl;
			glBegin(GL_LINES);
				glVertex2i(edges[i].x[0],edges[i].y[0]);
				glVertex2i(edges[i].x[1],edges[i].y[1]);
			glEnd();
		}
    
		glFlush();
		return;
	}
  
	void ScanFill(){
    
		int ymin=edges[0].y[0],ymax=0;
		vector<int> x_c,x_u,x_b,emp;
    
		for (int i = 0; i<n; i++){
			ymax = max(ymax,edges[i].y[1]);
		}
    
		for (int he = ymin; he<=ymax; he++){
			for (int i =0 ; i<n; i++){
				if (edges[i].a == 2)
					continue;
				if (edges[i].a == 1){
					if (edges[i].y[1]<h)
						edges[i].a = 2;
				}
				else if (edges[i].y[0] == h){
					edges[i].a = 1;
				}
				else
					break;
			}
			for (int i =0; i<n; i++){
        
				if (edges[i].a!= 1)
					continue;
        
				Edge e = edges[i];
				int x;
        
				if (e.x[0] == e.x[1])
					x = a.x[0];
				else
					x = (0.5+e.x[0] +  (0.0+e.x[1]-e.x[0]) / (e.y[1]-e.y[0]) * (he-e.y[0]) );
				if (he == e.y[1])
					x_b.push_back(x);
				else if (he == e.y[0])
					x_u.push_back(x);
				else
					x_c.push_back(x);
			}
      
			for (int i = 0; i<x_u.size(); i++){
				if ((i+1)<x_u.size() && x_u[i] == x_u[i+1])
					i++;
				else
					x_c.push_back(x_u[i]);
			}
      
			sort(x_c.begin(), x_c.end());
      
			for (int i = 1; i<x_c.size(); i+=2){
			  glBegin(GL_LINES);
				glVertex2i(x_c[i-1],he);
				glVertex2i(x_c[i],he);
			  glEnd();
			}
      
			glFlush();
			x_c = emp;
			x_u = emp;
			x_b = emp;
		}
	}
};

void init(){
	glClearColor (0.0,0.0,0.0,0.0);
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0,800.0, 0.0, 800.0);
}

void MYdisplay(void){
  
	Polygon p;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glFlush();
	a.drawPolygon();
	a.ScanFill();
  
}

int main(int argc,char *argv[]){
  
	glutInit(&argc,argv);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (00, 00);
	glutCreateWindow ("ScanLine");
	init();
	glutDisplayFunc(MYdisplay);
	glutMainLoop();
	return 0;
}
