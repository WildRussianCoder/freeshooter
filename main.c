#include "../../include/GL/freeglut.h"
#include "../../include/GL/gl.h"
#include "../../include/GL/glu.h"

void init ();
void render ();

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition (0, 0);
	glutInitWindowSize (640, 480);
	glutCreateWindow ("Freeshooter");

	init ();

	glutDisplayFunc (render);

	glutMainLoop ();
}

void init ()
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0, 639, 0, 479);
	glMatrixMode (GL_MODELVIEW);
}

void render ()
{
	glClear (GL_COLOR_BUFFER_BIT);

	glutSwapBuffers ();
}
