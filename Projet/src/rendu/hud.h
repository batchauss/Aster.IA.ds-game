#include "../init.h"

GLvoid barreVie(GLfloat vie);
GLvoid boutonPause();
GLvoid timer(int tempsRetenu);
GLvoid afficheScore(GLfloat score);
GLvoid decoHUD();

void vBitmapOutput(GLfloat x, GLfloat y, std::string s, void *font);
std::string intPadding(int i);