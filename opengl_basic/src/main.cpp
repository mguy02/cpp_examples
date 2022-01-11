#include <iostream>

#include <windows.h>

#ifdef __APPLE__
#include <OPENGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

// Taille de la fenêtre
int windowW = 640;
int windowH = 480;

GLvoid affichage();
GLvoid clavier(unsigned char touche, int x, int y);
GLvoid redimensionner(int w, int h);

GLvoid clavier(unsigned char touche, int x, int y) {
	switch (touche)
	{
	case 'q': // quitter
	case 27:
		exit(0);
		break;
	}

	glutPostRedisplay();
}

// Callback de redimensionnement de la fenêtre
GLvoid redimensionner(int w, int h) {
	// Garde les valeurs
	windowW = w;
	windowH = h;
	// eviter une division par 0
	if (windowH == 0)
		windowH = 1;

	float ratio = (float)windowW / (float)windowH;
	std::cout << "Ratio : " << ratio << std::endl;

	// Projection
	glMatrixMode(GL_PROJECTION);

	// Resetting matrix
	glLoadIdentity();

	glViewport(0, 0, windowW, windowH);
	// 1.0 = aspect ratio du frustum
	//gluPerspective(focale, 1.0, near_p, far_p);

	
	// Retourne a la pile modelview
	glMatrixMode(GL_MODELVIEW);
}


GLvoid affichage() {
	// Effacement du frame buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glFlush();
	glutSwapBuffers();

}

// entry point of the main project
int main(int argc, char** argv)
{
	// Initialisation de GLUT
	glutInit(&argc, argv);
	// Choix du mode d'affichage (ici RVB)
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	// Position initiale de la fenetre GLUT
	glutInitWindowPosition(200, 200);
	// Taille initiale de la fenetre GLUT
	glutInitWindowSize(windowW, windowH);
	// Creation de la fenetre GLUT
	glutCreateWindow("Fenetre GLUT");

	// Définition de la couleur d'effacement du framebuffer
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Initialement on active le Z-buffer
	glEnable(GL_DEPTH_TEST);

	// Shading model
	glShadeModel(GL_SMOOTH);




	// Définition des fonctions de callbacks
	glutDisplayFunc(affichage);
	glutKeyboardFunc(clavier);
	glutReshapeFunc(redimensionner);

	// Lancement de la boucle infinie GLUT
	glutMainLoop();

	return 0;

}
