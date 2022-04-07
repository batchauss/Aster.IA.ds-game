#include "init.h"
#include "actions.h"

int window = 0;

GLfloat r[50][3]; // tableau de coordonnées aléatoires pour les astéroides
GLfloat angle[50]; // tableau d'angle aléatoires qui vont permettre de créer une direction d'un asteroide



GLvoid Redimensionne(GLsizei width, GLsizei height){
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

int notre_init(int argc, char** argv, void (*Modelisation)()){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("Aster.AI.ds");
	glutDisplayFunc(Modelisation);
	glutIdleFunc(Modelisation);
	glutReshapeFunc(&Redimensionne);
	glutKeyboardFunc(&touche);
	glutSpecialFunc(&touche_speciale);
	glClearColor(0.0 , 0.0 , 0.0 , 0.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);



	

 for(int i=0;i<50;++i){ // remplissage du tableau r pour les coordonnées aléatoires des astéroides
		
  	 r[i][0] = (-50) + (float)((float)rand() * (50-(-50)+1) / (RAND_MAX-1));
  	 r[i][1] = (-50) + (float)((float)rand() * (50-(-50)+1) / (RAND_MAX-1));
  	 r[i][2] = (-50) + (float)((float)rand() * (50-(-50)+1) / (RAND_MAX-1));
	 angle[i] = (float)((float)rand() * (360+1) / (RAND_MAX-1));
	 
  		   
	}

	glutMainLoop();
	return 1;
}
