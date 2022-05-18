#include"init.h"

#include "touches/actions.h"

#include "fonctions/texture.h"
#include "fonctions/ppm.h"

#include "rendu/rendu.h"
#include "rendu/decor.h"


GLuint texture[1];
int window = 0;
GLfloat ambiente[4] = {0.7, 0.7, 0.7, 1};

GLfloat r[50][3]; // tableau de coordonnées aléatoires pour les astéroides
GLfloat angle_ast[50]; // tableau d'angle aléatoires qui vont permettre de créer une direction d'un asteroide

struct objmtl vaisseauObj;
struct objmtl asteroideObj;
struct objmtl asteroide2Obj;
struct objmtl asteroide3Obj;
struct objmtl ennemiobj;
struct objmtl heartObj;

Vaisseau * vaisseau = new Vaisseau(10);
Vaisseau * ennemi = new Vaisseau(5);
std::vector<Asteroide *> asteroides;
GLfloat score = 0;

int argc;
char** argv;


GLvoid Redimensionne(GLsizei width, GLsizei height){
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, (GLfloat)width / (GLfloat)height, 0.1, 3000.0);
	glMatrixMode(GL_MODELVIEW);
}

int notre_init(int argc1, char** argv1, void (*Modelisation)()){
	argc = argc1;
	argv = argv1;

	glutInit(&argc1, argv1);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1280, 960);
	glutInitWindowPosition(0, 0);
	window = glutCreateWindow("Aster.IA.ds");
	
	glutFullScreen();
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

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	renduVaisseau(1,vaisseauObj);
	renduVaisseau(2,vaisseauObj);
	renduAsteroide(1, asteroideObj);
	renduAsteroide(2, asteroide2Obj);
	renduAsteroide(3, asteroide3Obj);
	renduEnnemi(ennemiobj);
	renduCoeur(heartObj);
	decorPlanetes();
		
	//implementation des fichiers de textures
	TEXTURE_STRUCT * night = readPpm((char *)"./pic/night.ppm");
	Parametres_texture(0, night, texture[0]);

	glutMainLoop();
	return 1;
}

void initialise(){

	vaisseauObj = loadObj("models/vaisseau");
	asteroideObj = loadObj("models/asteroides1");
	asteroide2Obj = loadObj("models/asteroides2");
	asteroide3Obj = loadObj("models/asteroides3");
	ennemiobj = loadObj("models/ennemi");
	heartObj = loadObj("models/heart");

	remplissageTableauR();
	creationAsteroides();

	ennemi->setVie(30);
	ennemi->setPos(Rand(-100,100),Rand(-100,100),Rand(-100,100));
}

void reinitialisation(){
	initialise();

	vaisseau = new Vaisseau(10);
	ennemi = new Vaisseau(5);
	score = 0;
}


int Rand( int a, int b) // fonction rand
{
       int nRand ;
       nRand= a + (int)((float)rand() * (b-a+1) / (RAND_MAX-1)) ;
       return nRand;
}

void remplissageTableauR(){
	for(int i=0;i<30;++i){ 
  	 	r[i][0] = Rand(-399,399);
  	 	r[i][1] = Rand(-399,399);
  	 	r[i][2] = Rand(-399,399);
	 	angle_ast[i] = Rand(0,360);;
	} 
}

void creationAsteroides(){
	//creation des asteroides de grande tailles ( le jeu commence avec 4 grands 
	for( int i=0;i<4;++i){
       Asteroide * a = new AsteroideGrand(i);
	   a->setX(r[i][0]);
	   a->setY(r[i][1]);
	   a->setZ(r[i][2]);
	   a->setAngle(angle_ast[i]); 
	   asteroides.push_back(a) ;  
	}
}