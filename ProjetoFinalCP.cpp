// Trabalho_Final.cpp :
// ALUNOS: GABRIELA EMANUELE DE ARAUJO AMORIM - 2020012960
//         PEDRO HENRIQUE DE LIMA DUQUE       - 2020027480

#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>

#include "texture.h"

using namespace std;

unsigned int g_Texture = 0;
unsigned int g_TextureAbajur = 0;
unsigned int g_TextureTapete = 0;
unsigned int g_TextureLivro = 0;
GLfloat roll = 0, pitch = 0, yaw = 0;


void display();
void textura(void);
void iluminacao(void);
void materiais(void);
void reshapeFunc(int w, int h);
void keyboard(unsigned char key, int x, int y);
void special_keys(int key, int x, int y);
void abajur();
void livro();
void Puff();
void draw_clock();
void draw_janela(void);
void draw_walls(void);
void draw_estante(void);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow(" Cantinho de leitura ");
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(900, 900);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special_keys);
	glutReshapeFunc(reshapeFunc);
	glutMainLoop();
	return 0;
}

void reshapeFunc(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-4, 4, -4 * (GLfloat)h / (GLfloat)w, 4 * (GLfloat)h / (GLfloat)w, -4.0, 4.0);
	else
		glOrtho(-4 * (GLfloat)w / (GLfloat)h, 4 * (GLfloat)w / (GLfloat)h, -4, 4, -4, 4.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:  pitch -= 5;  break;
	case GLUT_KEY_RIGHT:  pitch += 5;  break;
	case GLUT_KEY_UP:  roll -= 5;  break;
	case GLUT_KEY_DOWN:  roll += 5;  break;
	case 'q': roll += 5;  break;
	case 'w': roll -= 5;  break;
	default: std::cout << "Keyboard " << key << std::endl;
	}
	glutPostRedisplay();
}

void special_keys(int key, int x, int y)
{
	switch (key) {

	case GLUT_KEY_LEFT:  pitch -= 5;  break;
	case GLUT_KEY_RIGHT:  pitch += 5;  break;
	case GLUT_KEY_UP:  roll -= 5;  break;
	case GLUT_KEY_DOWN:  roll += 5;  break;
	default: std::cout << "Special key " << key << std::endl;
	}

	glutPostRedisplay();
}

void abajur() {

	//pé
	glPushMatrix();
	glTranslated(0, -9.5, 0);
	glRotatef(180, 0, -1, -1);
	glColor3f(1.0f, 0.98f, 0.80f);
	glutSolidCone(2.5, 0.01, 10, 10);
	glPopMatrix();

	//Cilindro
	glPushMatrix();
	glScalef(0.15, 4.5, 0.6);
	glColor3f(1.0f, 0.98f, 0.98f);
	glutSolidCube(4.0);
	glPopMatrix();

	//Cone
	glPushMatrix();
	textura();
	glBindTexture(GL_TEXTURE_2D, g_TextureAbajur);
	glTranslated(0,7, 0);
	glRotatef(180, 0, -1, -1);
	glColor3f(1.0f, 1.f, 1.0f); 
	glutSolidCone(2.5, 3, 6, 6); 
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
}

void Puff() {
	glPushMatrix();
	textura();
	glBindTexture(GL_TEXTURE_2D, g_Texture);
	glTranslated(10.0, -3.8, -1.0);
	glRotatef(180, 1.0, 0.0, 0.0);
	glColor3f(3.0f, 0.8f, 0.8f);
	glutSolidTorus(3.4, 3.5, 50, 50);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void livro() {
	glPushMatrix();
	textura();
	glBindTexture(GL_TEXTURE_2D, g_TextureLivro);
	glTranslated(10.0, 6.1, -15.0);
	glRotatef(180, 2, 0.0, 0.0);
	glScalef(-0.2, 1.8, 0.7);
	glColor3f(0.1f, 0.0f, 0.7f);
	glutSolidCube(3.0); //livro
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	textura();
	glBindTexture(GL_TEXTURE_2D, g_TextureLivro);
	glTranslated(9.0, 6.1, -15.0);
	glRotatef(180, 2, 0.0, 0.0);
	glScalef(0.3, 1.8, 0.7);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidCube(3.0); //livro
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	textura();
	glBindTexture(GL_TEXTURE_2D, g_TextureLivro);
	glTranslated(5.7, 4.8, -15.0);
	glRotatef(180, 2.0, 2.0, 0.0);
	glScalef(-0.2, 1.5, 0.7);
	glColor3f(0.0f, 1.0f, 0.9f);
	glutSolidCube(3.0); //livro
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	textura();
	glBindTexture(GL_TEXTURE_2D, g_TextureLivro);
	glTranslated(5.7, 3.7, -15.0);
	glRotatef(180, 2.0, 2.0, 0.0);
	glScalef(-0.2, 1.5, 0.7);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidCube(3.0); //livro
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void draw_walls(void) // PAREDES
{
	glPushMatrix();
	glBegin(GL_QUADS);

	// PISO
	glColor3f(0.01f, 0.01f, 0.01f);
	glVertex3f(50.0f, 0.0f, 600.0f);
	glVertex3f(-15.0f, 0.0f, 10.0f);
	glVertex3f(-15.0f, 0.0f, -20.0f); //SUPERIOR.ESQUERDA
	glVertex3f(200.0f, 0.0f, -600.0f);

	// PAREDE ESQUERDA
	glColor3f(0.8f, 0.99f, 1.0f);
	glVertex3f(-15.0f, 20.0f, 15.0f);
	glVertex3f(-15.0f, 20.0f, -500.0f);
	glVertex3f(-15.0f, 0.0f, -20.0f);
	glVertex3f(-7.5f, 0.0f, 15.0f);

	// PAREDE DE TRÁS
	glColor3f(0.0f, 0.4f, 0.5f);
	glVertex3f(1600.0f, 10.0f, 20.0f);
	glVertex3f(-16.0f, -10.0f, -20.0f); // INFERIOR.ESQUERDA
	glVertex3f(35.0f, 400.0f, -20.0f); // SUPERIOR.ESQUERDA
	glVertex3f(15.0f, 1.0f, 5.0f);

	glEnd();
	glPopMatrix();
}

void draw_janela(void) //JANELA
{
	glColor3f(0.9f, 9.0f, 9.0f);
	glPushMatrix();
	glTranslated(-13.0, 3.5, 3.0);
	glRotatef(235.0, -1.6, 1.6, -1.1);
	glRotatef(180.0, 2.8, 0.0, -3.5);
	glScalef(2.4, 0.01, 3.5);
	glutSolidCube(5.0);
	glPopMatrix();
}

void draw_tapete()
{
	glPushMatrix();
	textura();
	glBindTexture(GL_TEXTURE_2D, g_TextureTapete);
	glScalef(2.5, 0.00, 2.0);
	glTranslated(1.0, -10.0, 5.0);
	glRotatef(360, 1.0, 0.0, 0.0);
	glColor3f(1.00f, 0.69f, 0.58f);
	glutSolidCube(6.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void draw_clock()
{

	glColor3f(0.3f, 0.5f, 0.6f);
	glPushMatrix();
	glTranslated(-16.0, 1.5, -20.0);
	glRotatef(180.0, 1.0, 0.0, 0.0);
	glutSolidTorus(0.25, 3.0, 50, 50); //RELÓGIO
	glPopMatrix();

	glPushMatrix();
	glTranslated(-16.0, 2.5, -20.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.2, 0.01, 2.9);
	glColor3f(9.0f, 9.0f, 9.0f);
	glutSolidCube(1.0); //MINUTOS
	glPopMatrix();

	glPushMatrix();
	glTranslated(-15.8, 1.8, -20.0);
	glRotatef(25.0, 1.0, 0.0, 0.0);
	glScalef(0.2, 0.01, 2.9);
	glColor3f(9.0f, 9.0f, 9.0f);
	glutSolidCube(1.0); //HORAS
	glPopMatrix();
}

void draw_estante(void) { //ESTANTE

	glPushMatrix();
	glScalef(2.5, 0.1, 2.0);
	glTranslated(1.0, 95.0, -1.0);
	glRotatef(360, 1.0, 0.0, 0.0);
	glColor3f(0.80f, 0.69f, 0.58f); //Burlywood
	glutSolidCube(5); //PARTE SUPERIOR 1
	glPopMatrix();

	glPushMatrix();
	glScalef(2.5, 0.1, 2.0);
	glTranslated(1.0, 60.0, -1.0);
	glRotatef(360, 1.0, 0.0, 0.0);
	glColor3f(0.80f, 0.69f, 0.58f); //Burlywood
	glutSolidCube(5); //PARTE 2
	glPopMatrix();

}

void display() {
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT || GL_DEPTH_BUFFER_BIT);

	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, 1.0f, 0.1f, 200.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 10.0, 25.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	materiais();

	glShadeModel(GL_FLAT);
	glPushMatrix();
	draw_walls();
	glPopMatrix();

	glShadeModel(GL_SMOOTH);
	glPushMatrix();
	draw_tapete();
	draw_estante();
	livro();
	draw_janela();
	glPopMatrix();
	abajur();
	Puff();

	glPushMatrix();
	glTranslated(3.5, 9.0, -10.0);
	draw_clock();
	glPopMatrix();

	glPushMatrix();
	// texture();
	glBindTexture(GL_TEXTURE_2D, g_Texture);
	// draw_teapot();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glRotatef(roll, 1, 0, 0);  // Up and down arrow keys
	glRotatef(pitch, 0, 1, 0);  // Right/left arrow keys
	glRotatef(yaw, 0, 0, 1);  // q/w
	iluminacao();
	glPopMatrix();
	glutSwapBuffers();
}


void textura(void) {
	// enable texturing
	glEnable(GL_TEXTURE_2D);

	// tell openGL to generate the texture coords for a sphere map
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

	// enable automatic texture coordinate generation
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);

	g_Texture = LoadTexture("Puff.bmp");
	g_TextureAbajur = LoadTexture("abajur.bmp");
	g_TextureTapete = LoadTexture("Tapete.bmp");
	g_TextureLivro = LoadTexture("Livro.bmp");
}

void materiais(void) {

	glPushMatrix();
	GLfloat mat_diff[] = { 100.0, 100.0, 100.0, 0.0 };
	GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat shininess[] = { 2.0 };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glPopMatrix();
}

void iluminacao(void) {

	//2) Criar de Luz Ambiente
	GLfloat ambient_color[] = { 0.55, 0.47, 0.37, 1.0 };

	GLfloat directional_pos1[] = { -130.0f, 40.0f, -100.0f, 1.0 }; //p=(x,y,z,w) onde w = 0
	GLfloat directional_pos2[] = { 130.0f, 40.0f, -100.0f, 1.0 }; //p=(x,y,z,w) onde w = 0

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color);
	glLightfv(GL_LIGHT0, GL_POSITION, directional_pos1);
	glLightfv(GL_LIGHT0, GL_POSITION, directional_pos2);

	glPopMatrix();
}


