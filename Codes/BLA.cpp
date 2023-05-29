#include<GL/glut.h>
#include<iostream>
#include<unistd.h>

int width=800, height=800;

void drawPoint(int x, int y){
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	usleep(1200);
	glFlush();
}

void DDA(int x1, int y1, int x2, int y2){
	int dx = x2-x1;
	int dy = y2-y1;
	
	int k;
	if(abs(dx)>abs(dy)){
		k = abs(dx);
	}
	else{
		k = abs(dy);
	}
	
	double Dx = double(dx)/k;
	double Dy = double(dy)/k;
	double x = x1, y=y1;
	
	drawPoint(x,y);
	
	for(int i=0; i<k; i++){
		x += Dx;
		y += Dy;
		drawPoint(x,y);
	}
}

void Init(){
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(width/2, -width/2, height/2, -height/2);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(-width/2,0);
	glVertex2i(width/2,0);
	glVertex2i(0,-height/2);
	glVertex2i(0,height/2);
	glEnd();
	DDA(-100,-100,100,100);
	glFlush();
}

int main(int argc,char** argv){
	glutInit(&argc, argv);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(0,0);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutCreateWindow("DDA");
	Init();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}
