#include "../init.h"

GLvoid barreVie(GLfloat vie);
GLvoid timer(int tempsRetenu);
GLvoid afficheScore(GLfloat score);
GLvoid decoHUD();
GLvoid vieSoucoupe(int vie, GLfloat angle);

void vBitmapOutput(GLfloat x, GLfloat y, std::string s, void *font);
std::string intPadding(int i);