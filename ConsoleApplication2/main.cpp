#include "main.h"


static int theta = 0;
int table[4][4];
int firstSel = 0;
GLfloat mat_specular1[] = { 0.256777, 0.137622, 0.086014, 1.0 };
GLfloat mat_diffuse1[] = { 0.7083, 0.27048, 0.0828, 1.0 };
GLfloat mat_ambient1[] = { 0.79125, 0.6735, 0.6225, 1.0 };
GLfloat mat_shininess1[] = { 12.8 };
GLfloat mat_specular[] = { 1, 1, 1.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_shininess[] = { 12.8 };

void drawBoxes() {
	for (Box box : game.boxes) {
		glPushMatrix();
		glTranslatef(box.x, box.y, box.z);

		glColor3f(box.r, box.g, box.b);
		box.draw();
		glPopMatrix();
	}
}
void init(void)
{


	GLfloat light_position[] = { 5.0, -5.0, 5.0, 0.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);  //reset "empty" background colour
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			table[x][y] = y * 4 + x;
			cout << table[x][y] << ":" << x << ", " << y << endl;
		}

	}

}

void keyboardread(unsigned char key, int x, int y)
{
	switch (key) {
	case 'r':
		theta = (theta + 10) % 360;
		glutPostRedisplay();
		cout << theta << endl;
		break;
	case 'l':
		theta = (theta - 10) % 360;
		glutPostRedisplay();
		break;
	case ' ':
		firstSel = firstSel + 1;
		if (firstSel == 16) firstSel = 0;
		cout << "first sel is" << firstSel << endl;
		glutPostRedisplay();
		break;
	}
}

void drawHouse(void)
{
	//Description:
	//This routine draws the house from OGL primitives
	//Note all polygon windings are counter clockwise
	//If you look at the front of a polygon its vertices are
	//listed so that the polygon is drawn in counterclockwise manner.
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	//  glPolygonMode(GL_BACK,GL_FILL); //uses also GL_FRONT_AND_BACK; GL_FILL, GL_POINT, GL_LINE  
	//  glPolygonMode(GL_FRONT,GL_FILL);// to spec. whether poly's. front and back are drawn filled
	// as lines or points

	//  glCullFace(GL_BACK);//discards front or back facing polygons
	//  glEnable(GL_CULL_FACE);  

	glPushMatrix();
	glBegin(GL_QUADS);

	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);//front norm is (0,0,-1)
	glVertex3f(0.0, -2.0, 0.0);
	glVertex3f(1.0, -2.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);//right (1,0,0)
	glVertex3f(1.0, -2.0, 0.0);
	glVertex3f(1.0, -2.0, -1.0);
	glVertex3f(1.0, 0.0, -1.0);

	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);//left (-1,0,0)
	glVertex3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, -2.0, -1.0);
	glVertex3f(0.0, -2.0, 0.0);

	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(0.0, -2.0, 0.0); //bottom (0,-1,0)
	glVertex3f(0.0, -2.0, -1.0);
	glVertex3f(1.0, -2.0, -1.0);
	glVertex3f(1.0, -2.0, 0.0);

	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, 0.0, -1.0);//back (0,0,1)
	glVertex3f(1.0, 0.0, -1.0);
	glVertex3f(1.0, -2.0, -1.0);
	glVertex3f(0.0, -2.0, -1.0);
	glEnd();
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);//front gable (0,0,-1)
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, 1.25, 0.0);

	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, 0.0, -1.0);//back gable (0,0,1)
	glVertex3f(0.5, 1.25, -1.0);
	glVertex3f(1.0, 0.0, -1.0);
	glEnd();
	glBegin(GL_QUADS);
	glNormal3f(-0.9385, 0.3714, 0.0);
	glVertex3f(0.0, 0.0, 0.0);//left roof (-0.9385,0.3714,0.0) 
	glVertex3f(0.5, 1.25, 0.0);
	glVertex3f(0.5, 1.25, -1.0);
	glVertex3f(0.0, 0.0, -1.0);

	glNormal3f(0.9385, 0.3714, 0.0);
	glVertex3f(0.5, 1.25, 0.0);//right roof (0.9385,0.3714,0.0)
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, -1.0);
	glVertex3f(0.5, 1.25, -1.0);
	glEnd();
	glPopMatrix();
}
void display(void)
{
	//select clearing background colour
	//if you don't do this then OGL will display
	//whatever was last drawn in the buffer
	//make it black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glLoadIdentity();//reset transformation (of modelview matrix)

	gluLookAt(5.0*sin(float(theta)*0.0175), 5.0, 5.0*cos(float(theta)*0.0175), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//  place camera - it rotates about the origin, on y = 5.0 plane,
	// with a radius of 5.0; 0,0,0 - aim lens towards 0,0,0; 
	//  0,1,0 - the up vector defines an unique orientation
	/*
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			glPushMatrix();
			glTranslatef(1.0*x, 0.0, 1.0*y);
			if (firstSel == (y * 4 + x))
			{
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);

			}
			else {
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

			}

			drawBoxes();
			glPopMatrix();
		}

	}
	*/
	/////*drawHouse();
	////glPushMatrix();
	////glTranslatef(1.0, 0.0, 0.0);
	////drawHouse();
	////glPopMatrix();
	////glPushMatrix();
	////glTranslatef(3.0, 0.0, -1.0);
	////glRotatef(90.0, 0.0, 1.0, 0.0);
	////drawHouse();
	////glPopMatrix();*/
	//glutWireCube(1.0);
	//glFlush();
	glutSwapBuffers();
	drawBoxes();
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	//             l,r,bot,top,near,far

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D house");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardread);
	glutMainLoop();
	return 0;
}
