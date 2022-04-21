#include"init.h"
#include "fonctions/texture.h"
#include "actions.h"
#include "rendu/rendu.h"

GLuint texture[5];
Asteroide* tabAsteroides[50];
int window = 0;

GLfloat r[50][3]; // tableau de coordonnées aléatoires pour les astéroides
GLfloat angle_ast[50]; // tableau d'angle aléatoires qui vont permettre de créer une direction d'un asteroide


struct obj v;

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

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	v = loadObj("models/vaisseau.obj");

   // remplissage du tableau r pour les coordonnées aléatoires des astéroides
     for(int i=0;i<50;++i){ 
		
  	 	r[i][0] = (-50) + (float)((float)rand() * (50-(-50)+1) / (RAND_MAX-1));
  	 	r[i][1] = (-50) + (float)((float)rand() * (50-(-50)+1) / (RAND_MAX-1));
  	 	r[i][2] = (-50) + (float)((float)rand() * (50-(-50)+1) / (RAND_MAX-1));
	 	angle_ast[i] = (float)((float)rand() * (360+1) / (RAND_MAX-1)); 
  		   
	} 
	
	//implementation des fichiers de textures
	TEXTURE_STRUCT * galaxy = readPpm((char *)"./pic/night.ppm");
   Parametres_texture(0,galaxy);


	glutMainLoop();
	return 1;
}

GLvoid spawn_asteroid(){

 for(int i=0;i<50;++i){
  
       Asteroide  *a = new Asteroide(i,1,10,10);
	  // déplacement unique en fonction de l'angle aléatoire 
      r[i][0]+= 0.2  * sin(a->getAng() *3.14 /180);
      r[i][1]+= 0.2  * cos(a->getAng() *3.14 /180);
      r[i][2]+= -0.2  * cos(a->getAng() *3.14 /180);



    // si la frontiere est franchie, l'asteroide réapparait à l'opposé de la map
       if (r[i][0] >=100) r[i][0] -= 200;
       else if (r[i][1] >=100) r[i][1] -= 200;
       else if (r[i][2] >=100) r[i][2] -= 200;

       else if (r[i][0] <=-100) r[i][0] += 200;
       else if (r[i][1] <=-100) r[i][1] += 200;
       else if (r[i][2] <=-100) r[i][2] += 200;  

       renduAsteroide(a);
	   tabAsteroides[i]=a;
       delete a;
       
 }
}