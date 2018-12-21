#include <pch.h>
#include <math.h>
#include <GL/glut.h>	

#ifndef M_PI
#define M_PI 3.141592
#endif

int width = 600;
int height = 600;
float sphere2Degree = 0;
float sphere3Degree = 0;
float sphereDegree = 0;
float redCubeDegree = 0;
float greenCubeDegree = 0;
float blueCubeDegree = 0;

void drawCircle(int r, int points)
{
	float iterator = 360 / points;
	float x;
	float z;

	glBegin(GL_LINE_STRIP);
	for (float i = 0; i <= 360; i += iterator){
		x = r * cos(i*M_PI / 180);
		z = r * sin(i*M_PI / 180);
		glVertex3f(x, 0, z);
	}
	glEnd();
}

void display(void)
{
	// Farb- und Tiefenbuffer leeren
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Teekanne rendern.
	glColor3f(1, 1, 0);
	glutSolidSphere(1, 360, 360);

	glPushMatrix();

	glColor3f(0, 0, 0);
	drawCircle(7, 360);
	drawCircle(12, 360);
	drawCircle(17,360);
	drawCircle(22, 360);
	
	glPushMatrix();
	glRotatef(sphere2Degree, 0, 1, 0);
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(22, 0, 0);
	glutSolidSphere(3.0, 360, 360);
	glPopMatrix();

	glPushMatrix();
	glRotatef(sphere2Degree, 0, 1, 0);
	glColor3f(0, 1, 1);
	glTranslatef(7, 0, 0);
	glutSolidSphere(0.5, 360, 360);
	glPopMatrix();

	glPushMatrix();
	glRotatef(sphere3Degree, 0, 1, 0);
	glColor3f(1, 0, 0);
	glTranslatef(17, 0, 0);
	glutSolidSphere(0.7, 360, 360);
	glPopMatrix();

	glRotatef(sphereDegree, 0, 1, 0);
	glColor3f(0,0,0);
	glTranslatef(12, 0, 0);
	
	glutSolidSphere(1.0, 360, 360);



	glPushMatrix();
	
	drawCircle(2, 360);
	
	glRotatef(90, 1.0, 0.0, 0.0);
	drawCircle(4, 360);
	
	glRotatef(90, 0.0, 0.0, 1.0);
	drawCircle(2, 360);

	glPopMatrix();
    glPushMatrix();

	glRotatef(redCubeDegree, 0, 1, 0);
	glColor3f(1, 0, 0);
	glTranslatef(2, 0, 0);
	glutSolidCube(0.5);
	
	glPopMatrix();
	glPushMatrix();

	glRotatef(greenCubeDegree, 0, 0, 1);
	glColor3f(0, 1, 0);
	glTranslatef(4, 0, 0);
	glutSolidCube(0.7);

	glPopMatrix();
		
	glRotatef(blueCubeDegree, 1, 0, 0);
	glColor3f(0, 0, 1);
	glTranslatef(0, 2, 0);
	glutSolidCube(1.0);

	glPopMatrix();

	sphereDegree++;
	redCubeDegree++;//???? redCubeDegee--; isnt moving to the left
	greenCubeDegree++;
	blueCubeDegree++;
	sphere2Degree = sphere2Degree + 5;
	sphere3Degree = sphere3Degree + 10;

	glutSwapBuffers();
}

void timer(int val)
{
	glutTimerFunc(val, timer, val);
	glutPostRedisplay();
}

void init()
{
	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-15.0, 15.0, -15.0, 15.0, 0.0, 200);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	gluLookAt(25.0, 11.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Transformationen");

	glutDisplayFunc(display);
	glutTimerFunc(10, timer, 10);

	init();
	glutMainLoop();
	return 0;
}
