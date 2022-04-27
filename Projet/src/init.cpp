#include"init.h"
#include "fonctions/texture.h"
#include "actions.h"
#include "rendu/rendu.h"

GLuint texture[5];
int window = 0;
GLfloat ambiente[4] = {0.7, 0.7, 0.7, 1};

GLfloat r[50][3]; // tableau de coordonnées aléatoires pour les astéroides
GLfloat angle_ast[50]; // tableau d'angle aléatoires qui vont permettre de créer une direction d'un asteroide
std::vector< Asteroide > asteroides;

struct objmtl v;
struct objmtl ast;


GLvoid Redimensionne(GLsizei width, GLsizei height){
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 3000.0);
	glMatrixMode(GL_MODELVIEW);
}

int notre_init(int argc, char** argv, void (*Modelisation)()){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("Aster.IA.ds");
	glutDisplayFunc(Modelisation);
	glutIdleFunc(Modelisation);
	glutReshapeFunc(&Redimensionne);
	glutKeyboardFunc(&touche);
	glutKeyboardUpFunc(&releaseTouche);
	glutSpecialFunc(&toucheSpeciale);
	glutSpecialUpFunc(&releaseToucheSpeciale);
	glClearColor(0.0 , 0.0 , 0.0 , 0.0);

	glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHT0);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambiente);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	v = loadObj("models/vaisseau");
	ast = loadObj("models/test2");

   // remplissage du tableau r pour les coordonnées aléatoires des astéroides
     for(int i=0;i<50;++i){ 
		
  	 	r[i][0] = (-200) + (float)((float)rand() * (200-(-200)+1) / (RAND_MAX-1));
  	 	r[i][1] = (-200) + (float)((float)rand() * (200-(-200)+1) / (RAND_MAX-1));
  	 	r[i][2] = (-200) + (float)((float)rand() * (200-(-200)+1) / (RAND_MAX-1));
	 	angle_ast[i] = (float)((float)rand() * (360+1) / (RAND_MAX-1));
  		   
	} 

	//creation du tableau d'asteroides
	for(int i=0;i<30;++i){
       Asteroide  a =  Asteroide(i);
	   a.setX(r[i][0]);
	   a.setY(r[i][1]);
	   a.setZ(r[i][2]);
	   a.setAngle(angle_ast[i]);
	   asteroides.push_back(a) ;	   
	}
	
	//implementation des fichiers de textures
	TEXTURE_STRUCT * night = readPpm((char *)"./pic/night.ppm");
    Parametres_texture(0,night);

	TEXTURE_STRUCT * damier = readPpm((char *)"./pic/Damier.ppm"); //test
    Parametres_texture(1,damier);

	glutMainLoop();
	return 1;
}