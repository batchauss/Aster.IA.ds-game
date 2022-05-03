#include"init.h"

#include "touches/actions.h"

#include "fonctions/texture.h"
#include "fonctions/ppm.h"

#include "rendu/rendu.h"

GLuint texture[5];
int window = 0;
GLfloat ambiente[4] = {0.7, 0.7, 0.7, 1};

GLfloat r[50][3]; // tableau de coordonnées aléatoires pour les astéroides
GLfloat angle_ast[50]; // tableau d'angle aléatoires qui vont permettre de créer une direction d'un asteroide

struct objmtl vaisseauObj;
struct objmtl asteroideObj;

Vaisseau * vaisseau = new Vaisseau();
std::vector<Asteroide *> asteroides;

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

	renduVaisseau(vaisseauObj);

	renduAsteroide(1, asteroideObj);
	renduAsteroide(2, asteroideObj);
	renduAsteroide(3, asteroideObj);
		
	//implementation des fichiers de textures
	TEXTURE_STRUCT * night = readPpm((char *)"./pic/night.ppm");
	Parametres_texture(0, night, texture[0]);

	glutMainLoop();
	return 1;
}

void initialise(){

	vaisseauObj = loadObj("models/vaisseau");
	asteroideObj = loadObj("models/test2");

	remplissageTableauR();
	creationAsteroides();
}

int Rand( int a, int b) // fonction rand
{
       int nRand ;
       nRand= a + (int)((float)rand() * (b-a+1) / (RAND_MAX-1)) ;
       return nRand;
}

void remplissageTableauR(){
	for(int i=0;i<30;++i){ 
  	 	r[i][0] = Rand(-199,199);
  	 	r[i][1] = Rand(-199,199);
  	 	r[i][2] = Rand(-199,199);
	 	angle_ast[i] = Rand(0,360);;
	} 
}

void creationAsteroides(){
	//creation des asteroides de grande tailles ( le jeu commence avec 4 grands )
	for(unsigned int i=0;i<4;++i){
       Asteroide * a = new AsteroideGrand(asteroides.size());
	   a->setX(r[i][0]);
	   a->setY(r[i][1]);
	   a->setZ(r[i][2]);
	   a->setAngle(angle_ast[i]); 
	   asteroides.push_back(a) ;  
	}
}