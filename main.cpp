#include <GL/glut.h>
#include <math.h>
#include <iostream.h>
#include <stdlib.h>
#include "mundo.h"

void dibujarMundo();

void techo();
void piso();
void escaleras();
void escaleras2();
void escalerasB();
void escalerasPrincipales();
void escalerasEscalones();
void escalerasBanosYSotano();
void cafe();
void patio();
void patio2();
void muros();
void maquinaBrown();
void maquinaBlack();
void murosL();
void muros2();
void puertas();
void escaleraPrinArriba();
void cartel();
void patioLyBordesArriba();
mundo c(true);

static float angle=3.52, ratio;
static float x=-4.73922f, y=13.0f, z=-18.8773f;
static float lx=-0.369441f, ly=0.0f, lz=0.929254f;
static GLint snowman_display_list;

void changeSize(int w, int h) {
	if(h == 0) h = 1;
	ratio = 1.0f * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glViewport(0, 0, w, h);
	gluPerspective(45,ratio,1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z,
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}

void drawMierda(){
    glPushMatrix();
    glColor3f(0.0f, 0.5f , 0.5f);
    glTranslatef(0.0,190.0,0.0);
    glutSolidTeapot(2);
    glPopMatrix();
}

GLfloat position[] = {120.0, 0.0, 10.0, 0.3f};// x, y, z, 1:directional 0:point
GLfloat position1[] = {-120.0, 10.0, 400.0, 1.0f};// x, y, z, 1:directional 0:point

void init(void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    dibujarMundo();
    glLightfv(GL_LIGHT0, GL_POSITION, position1);
    glShadeModel(GL_FLAT);
    glutSwapBuffers();
}

void orientMe(float ang) {
	lx = sin(ang); // copiada
	lz = -cos(ang); // copiada
	glLoadIdentity();
	gluLookAt(x, y, z,
		      x + lx, y + ly ,z + lz,
			  0.0f,1.0f,0.0f);
}

void moveMeFlat(int i) {
    float cx=x, cz=z;
    int cz2=z, cz3, cx2=x, cx3;
	x = x + i*(lx)*0.8; // copiada
	z = z + i*(lz)*0.8; // copiada
	glLoadIdentity();
    if( c.detectar( x , z ) == 1 ){ x=cx; z=cz; }
    else if( c.detectar( x , z )== 2 ){
        cz3=z;
        if( cz3>cz2 ) y=y-2;
        else if( cz3<cz2 ) y=y+2;
    }else if( c.detectar( x , z )== 3 ){
        cx3=x;
        if( cx3<cx2 ) y=y-2;
        else if( cx3>cx2 ) y=y+2;
    }else if(  c.detectar( x , z )== 4 ){
        cx3=x;
        if( cx3<cx2 ) y=y-0.44;
        else if( cx3>cx2 ) y=y+0.45;
    }else if(  c.detectar( x , z )== 5 ){
        cz3=z;
        if( cz3<cz2 ) y=y-0.8;
        else if( cz3>cz2 ) y=y+0.8;
    }
	gluLookAt(x, y, z,
		      x + lx,y + ly,z + lz,
			  0.0f,1.0f,0.0f);
}

void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27) exit(0);
}

void inputKey(int
 key, int x, int y) {
	switch (key) {
		case GLUT_KEY_LEFT : angle -= 0.08f; orientMe(angle);break;
		case GLUT_KEY_RIGHT : angle +=0.08f; orientMe(angle);break;
		case GLUT_KEY_UP : moveMeFlat(3); break;
		case GLUT_KEY_DOWN : moveMeFlat(-3); break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,360);
	glutCreateWindow(" U-niversia ");
    init();
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(inputKey);

	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);

	glutReshapeFunc(changeSize); // es copiado
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

	return(0);
}









void dibujarMundo(){

    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_ambient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
    GLfloat mat_gray[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat mat_gray1[] = {0.4, 0.4, 0.4, 1.0};
    GLfloat mat_gray2[] = {0.6, 0.6, 0.6, 0.0};
    GLfloat mat_blue[] = {0.0, 0.5, 10.5, 1.0};
    GLfloat mat_green[] = {0.1, 0.9, 0.1, 1.0};
    GLfloat mat_brown[] = {1.0, 0.6, 0.1, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat no_shininess[] = {0.0};
    GLfloat low_shininess[] = {5.0};
    GLfloat high_shininess[] = {100.0};

glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_gray);
muros2();
patio2();
/////////////////////////////////  maquina atras  //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -35.0f, -4.0f, 79.0f);
    glVertex3f( -35.0f, 8.5f, 79.0f);
    glVertex3f( -45.0f, 8.5f, 79.0f);
    glVertex3f( -45.0f, -4.0f, 79.0f);
glEnd();

glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_gray1);
escaleraPrinArriba();
cartel();
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_gray2);
techo();
piso();
patioLyBordesArriba();

/////////////////////////////   cartel 1 /////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -71.0f, 2.0f, 200.0f);
    glVertex3f( -71.0f, 12.0f, 200.0f);
    glVertex3f( -71.0f, 12.0f, 220.0f);
    glVertex3f( -71.0f, 2.0f, 220.0f);
glEnd();
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_brown);
puertas();
maquinaBrown();
escalerasBanosYSotano();
//  columna 1 en muros2
/////////////////////////////////  columna 2 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -71.0f, -5.0f, 182.0f);
    glVertex3f( -71.0f, 21.0f, 182.0f);
    glVertex3f( -70.0f, 21.0f, 182.0f);
    glVertex3f( -70.0f, -5.0f, 182.0f);
glEnd();
/////////////////////////////////  columna 3 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -71.0f, -5.0f, 184.0f);
    glVertex3f( -71.0f, 21.0f, 184.0f);
    glVertex3f( -71.0f, 21.0f, 182.0f);
    glVertex3f( -71.0f, -5.0f, 182.0f);
glEnd();
/////////////////////////////////  columna 4 //////////////////////////////
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_gray);
muros();
patio();
cafe();
escaleras();
escalerasPrincipales();
    glBegin(GL_QUADS);
    glVertex3f( -71.0f, -5.0f, 184.0f);
    glVertex3f( -71.0f, 21.0f, 184.0f);
    glVertex3f( -73.5f, 21.0f, 184.0f);
    glVertex3f( -73.5f, -5.0f, 184.0f);
glEnd();

glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_blue);
escaleras2();

glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_green);
drawMierda();
/////////////////////////////////  maquina sub piso 2//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -35.5f, -4.f, 75.0f);
    glVertex3f( -35.5f, 0.0f, 76.0f);
    glVertex3f( -43.0f, 0.0f, 76.0f);
    glVertex3f( -43.0f, -4.0f, 75.0f);
glEnd();
/////////////////////////////////  maquina sub piso//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -35.5f, 0.0f, 76.0f);
    glVertex3f( -35.5f, 0.0f, 79.0f);
    glVertex3f( -43.0f, 0.0f, 79.0f);
    glVertex3f( -43.0f, 0.0f, 76.0f);
glEnd();

glMaterialfv(GL_FRONT, GL_DIFFUSE, no_mat);
escalerasB();
maquinaBlack();
escalerasEscalones();
murosL();
/////////////////////////////////  Lpiso L patio 1//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -32.0f, -2.5f, 127.0f);
    glVertex3f( -32.0f, -2.5f, 163.0f);
    glVertex3f( -53.0f, -2.5f, 163.0f);
    glVertex3f( -53.0f, -2.5f, 127.0f);
glEnd();
/////////////////////////////////  Lpiso L patio 2//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -32.0f, -2.5f, 142.0f);
    glVertex3f( -32.0f, -2.5f, 163.0f);
    glVertex3f( -7.0f, -2.5f, 163.0f);
    glVertex3f( -7.0f, -2.5f, 142.0f);
glEnd();

}




void patioLyBordesArriba(){
    /////////////////////////////////  murito patio  arriba 1//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -66.0f, 1.0f, 110.0f);
		glVertex3f( -66.0f, 1.0f, 114.0f);
        glVertex3f( -64.0f, 1.0f, 112.0f);
		glVertex3f( -64.0f, 1.0f, 110.0f);
	glEnd();
/////////////////////////////////  murito patio  arriba 2//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -66.0f, 1.0f, 114.0f);
        glVertex3f( -64.0f, 1.0f, 112.0f);
        glVertex3f(   3.0f, 1.0f, 112.0f);
		glVertex3f(   1.0f, 1.0f, 114.0f);
	glEnd();

/////////////////////////////////  murito patio  arriba 3//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 3.0f, 1.0f, 112.0f);
        glVertex3f( 8.0f, 1.0f, 180.0f);
        glVertex3f( 6.0f, 1.0f, 180.0f);
		glVertex3f( 1.0f, 1.0f, 114.0f);
	glEnd();
/////////////////////////////////  L lat sup 6-1//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -55.0f, 1.0f, 165.0f);
		glVertex3f( -53.0f, 1.0f, 165.0f);
        glVertex3f( -53.0f, 1.0f, 125.0f);
		glVertex3f( -55.0f, 1.0f, 125.0f);
	glEnd();
/////////////////////////////////  L lat sup 1-2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -53.0f, 1.0f, 165.0f);
		glVertex3f( -53.0f, 1.0f, 163.0f);
        glVertex3f( -7.0f,  1.0f, 163.0f);
		glVertex3f( -7.0f,  1.0f, 165.0f);
	glEnd();
/////////////////////////////////  L lat sup 2-4//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 1.0f, 165.0f);
		glVertex3f( -7.0f, 1.0f, 165.0f);
        glVertex3f( -7.0f, 1.0f, 140.0f);
		glVertex3f( -5.0f, 1.0f, 140.0f);
	glEnd();
/////////////////////////////////  L lat sup 4-5//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -7.0f, 1.0f, 142.0f);
		glVertex3f( -7.0f, 1.0f, 140.0f);
        glVertex3f( -30.0f, 1.0f, 140.0f);
		glVertex3f( -30.0f, 1.0f, 142.0f);
	glEnd();
/////////////////////////////////  L lat sup 5-6//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -30.0f, 1.0f, 142.0f);
		glVertex3f( -32.0f, 1.0f, 142.0f);
        glVertex3f( -32.0f, 1.0f, 125.0f);
		glVertex3f( -30.0f, 1.0f, 125.0f);
	glEnd();
/////////////////////////////////  L lat sup 6-1//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -32.0f, 1.0f, 125.0f);
		glVertex3f( -32.0f, 1.0f, 127.0f);
        glVertex3f( -53.0f, 1.0f, 127.0f);
		glVertex3f( -53.0f, 1.0f, 125.0f);
	glEnd();

    }

void cartel (){
	 /////////////////////////////   cartel 2.1 /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, 2.0f, 200.0f);
		glVertex3f( -70.0f, 12.0f, 200.0f);
		glVertex3f( -72.0f, 12.0f, 200.0f);
		glVertex3f( -72.0f, 2.0f, 200.0f);
	glEnd();
	 /////////////////////////////   cartel 2.2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, 2.0f, 220.0f);
		glVertex3f( -70.0f, 12.0f, 220.0f);
		glVertex3f( -72.0f, 12.0f, 220.0f);
		glVertex3f( -72.0f, 2.0f, 220.0f);
	glEnd();
 /////////////////////////////   cartel 2.1 /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, 2.0f, 200.0f);
		glVertex3f( -70.0f, 2.0f, 220.0f);
		glVertex3f( -72.0f, 2.0f, 220.0f);
		glVertex3f( -72.0f, 2.0f, 200.0f);
	glEnd();
	 /////////////////////////////   cartel 2.2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, 12.0f, 200.0f);
		glVertex3f( -70.0f, 12.0f, 220.0f);
		glVertex3f( -72.0f, 12.0f, 220.0f);
		glVertex3f( -72.0f, 12.0f, 200.0f);
	glEnd();

}


void techo(){
/////////////////////////////   techo 1 /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 21.0f, -20.0f);
		glVertex3f( 10.0f, 21.0f, 40.0f);
		glVertex3f( -80.0f, 21.0f, 40.0f);
		glVertex3f( -80.0f, 21.0f, -20.0f);
	glEnd();
/////////////////////////////   techo 2 /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, 21.0f, 120.0f);
		glVertex3f( -70.0f, 21.0f, 280.0f);
		glVertex3f( -120.0f, 21.0f, 280.0f);
		glVertex3f( -120.0f, 21.0f, 120.0f);
	glEnd();
/////////////////////////////   techo 3 /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 21.0f, 180.0f);
		glVertex3f( 10.0f, 21.0f, 280.0f);
		glVertex3f( -70.0f, 21.0f, 280.0f);
		glVertex3f( -70.0f, 21.0f, 180.0f);
	glEnd();
/////////////////////////////   techo 3.1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 21.0f, 292.0f);
		glVertex3f( -20.0f, 21.0f, 280.0f);
		glVertex3f( 12.0f, 21.0f, 280.0f);
		glVertex3f( 12.0f, 21.0f, 292.0f);
	glEnd();
/////////////////////////////   techo 3.2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 12.0f, 21.0f, 270.0f);
		glVertex3f( 12.0f, 21.0f, 280.0f);
		glVertex3f( 10.0f, 21.0f, 280.0f);
		glVertex3f( 10.0f, 21.0f, 270.0f);
	glEnd();
/////////////////////////////   techo 3.3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -10.0f, 21.0f, 292.0f);
		glVertex3f( -10.0f, 21.0f, 304.0f);
		glVertex3f( -22.0f, 21.0f, 304.0f);
		glVertex3f( -22.0f, 21.0f, 292.0f);
	glEnd();
/////////////////////////////////  techo 4 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -70.0f, 21.0f, 40.0f);
    glVertex3f( -120.0f, 21.0f, 40.0f);
    glVertex3f( -120.0f, 21.0f, 120.0f);
    glVertex3f( -70.0f, 21.0f, 120.0f);
glEnd();
}

void piso(){
/////////////////////////////  e.sa piso puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 10.0f, 300.0f);
		glVertex3f( -21.0f, 10.0f, 300.0f);
		glVertex3f( -21.0f, 10.0f, 294.0f);
		glVertex3f( -20.0f, 10.0f, 294.0f);
	glEnd();

/////////////////////////////////  piso antes sotano //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -20.0f, 0.0f, 270.0f);
    glVertex3f( -5.0f, 0.0f, 270.0f);
    glVertex3f( -5.0f, 0.0f, 285.0f);
    glVertex3f( -20.0f, 0.0f, 285.0f);
glEnd();
/////////////////////////////////  muro escaleras piso rampa bajo  //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -20.0f, 0.0f, 265.0f);
    glVertex3f( -20.0f, 0.0f, 280.0f);
    glVertex3f( -50.0f, -2.5f, 280.0f);
    glVertex3f( -50.0f, -2.5f, 265.0f);
glEnd();
/////////////////////////////////  muro rampita piso  //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -50.0f, -2.5f, 265.0f);
    glVertex3f( -70.0f, -2.5f, 265.0f);
    glVertex3f( -70.0f, -2.5f, 280.0f);
    glVertex3f( -50.0f, -2.5f, 280.0f);
glEnd();
/////////////////////////////  piso sotano/////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 15.0f, -20.0f, 280.0f);
    glVertex3f( 15.0f, -20.0f, 270.0f);
    glVertex3f( 135.0f, -20.0f, 270.0f);
    glVertex3f( 135.0f, -20.0f, 280.0f);
glEnd();
/////////////////////////////   piso  3 /////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 10.0f, 0.0f, 180.0f);
    glVertex3f( 10.0f, 0.0f, 270.0f);
    glVertex3f( -20.0f, 0.0f, 270.0f);
    glVertex3f( -20.0f, 0.0f, 180.0f);
glEnd();
/////////////////////////////   piso 2.1  /////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 5.0f, 0.0f, -22.0f);
    glVertex3f( 5.0f, 0.0f,  40.0f);
    glVertex3f( -70.0f, 0.0f,  40.0f);
    glVertex3f( -70.0f, 0.0f, -22.0f);
glEnd();
/////////////////////////////   piso 2.2  /////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -70.0f, 0.0f, -20.0f);
    glVertex3f( -70.0f, 0.0f,  20.0f);
    glVertex3f( -80.0f, 0.0f,  20.0f);
    glVertex3f( -80.0f, 0.0f, -20.0f);
glEnd();
/////////////////////////////   piso  1.2 /////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -70.0f, -5.0f, 280.0f);
    glVertex3f( -70.0f, -5.0f, 265.0f);
    glVertex3f( -122.0f, -5.0f, 265.0f);
    glVertex3f( -122.0f, -5.0f, 280.0f);
glEnd();
/////////////////////////////   piso  1 /////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 10.0f, -5.0f, -20.0f);
    glVertex3f( 10.0f, -5.0f, 265.0f);
    glVertex3f( -122.0f, -5.0f, 265.0f);
    glVertex3f( -122.0f, -5.0f, -20.0f);
glEnd();
/////////////////////////////  e.sa piso 1/////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 12.0f, 10.0f, 267.0f);
    glVertex3f( 12.0f, 10.0f, 292.0f);
    glVertex3f( -5.0f, 10.0f, 292.0f);
    glVertex3f( -5.0f, 10.0f, 267.0f);
glEnd();
/////////////////////////////  e.sa piso 2/////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 10.0f, 8.0f, 267.0f);
    glVertex3f( 10.0f, 8.0f, 280.0f);
    glVertex3f( -5.0f, 8.0f, 280.0f);
    glVertex3f( -5.0f, 8.0f, 267.0f);
glEnd();
/////////////////////////////  e.sa  piso 4.3  /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -12.0f, 10.0f, 302.0f);
		glVertex3f( -12.0f, 10.0f, 303.0f);
		glVertex3f( -18.0f, 10.0f, 303.0f);
		glVertex3f( -18.0f, 10.0f, 302.0f);
	glEnd();
}

void escaleraPrinArriba(){
////////////////////piso 1 ////////////////////////////////
/////////////////////////////////  pasamanos e.inf bajo 1.1//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 5.3f, 5.0f, 40.5f);
    glVertex3f( 5.3f, 15.0f, 80.0f);
    glVertex3f( 1.7f, 15.0f, 80.0f);
    glVertex3f( 1.7f, 5.0f, 40.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf  bajo 1.2  //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 5.3f, 5.7f,  40.5f);
    glVertex3f( 5.3f, 15.7f, 80.0f);
    glVertex3f( 1.7f, 15.7f, 80.0f);
    glVertex3f( 1.7f, 5.7f,  40.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf  bajo 2.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.0f, 5.0f, 40.5f);
    glVertex3f( -12.0f, 15.0f, 80.0f);
    glVertex3f( -15.5f, 15.0f, 80.0f);
    glVertex3f( -15.5f, 5.0f, 40.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf  bajo 2.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.0f, 5.7f, 40.5f);
    glVertex3f( -12.0f, 15.7f, 80.0f);
    glVertex3f( -15.5f, 15.7f, 80.0f);
    glVertex3f( -15.5f, 5.7f, 40.5f);
glEnd();

/////////////////////////////////  pasamanos e.inf del 1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 5.3f, 5.7f, 40.5f);
    glVertex3f( 5.3f, 5.0f, 40.5f);
    glVertex3f( 1.7f, 5.0f, 40.5f);
    glVertex3f( 1.7f, 5.7f, 40.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf del 2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.0f, 5.7f, 40.5f);
    glVertex3f( -12.0f, 5.0f, 40.5f);
    glVertex3f( -15.3f, 5.0f, 40.5f);
    glVertex3f( -15.3f, 5.7f, 40.5f);
glEnd();



/////////////////////////////////  pasamanos e.inf lat 1.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 5.3f, 5.0f, 40.5f);
    glVertex3f( 5.3f, 5.7f, 40.5f);
    glVertex3f( 5.3f, 15.7f, 79.5f);
    glVertex3f( 5.3f, 15.0f, 79.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf lat 1.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 1.7f, 5.0f, 40.5f);
    glVertex3f( 1.7f, 5.7f, 40.5f);
    glVertex3f( 1.7f, 15.7f, 79.5f);
    glVertex3f( 1.7f, 15.0f, 79.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf lat 2.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.0f, 5.0f, 40.5f);
    glVertex3f( -12.0f, 5.7f, 40.5f);
    glVertex3f( -12.0f, 15.7f, 79.5f);
    glVertex3f( -12.0f, 15.0f, 79.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf lat 2.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -15.5f, 5.0f, 40.5f);
    glVertex3f( -15.5f, 5.7f, 40.5f);
    glVertex3f( -15.5f, 15.7f, 79.5f);
    glVertex3f( -15.5f, 15.0f, 79.5f);
glEnd();


/////////////////////////////////  pasamanos e.med ext 1.1//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(   5.3f, 15.0f, 110.5f);
    glVertex3f(   5.3f, 15.7f, 110.5f);
    glVertex3f( -70.5f, 15.7f, 110.5f);
    glVertex3f( -70.5f, 15.0f, 110.5f);
glEnd();
/////////////////////////////////  pasamanos e.med tras 1.2//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 1.7f, 15.0f, 107.0f);
    glVertex3f( 1.7f, 15.7f, 107.0f);
    glVertex3f( -56.7f, 15.7f, 107.0f);
    glVertex3f( -56.7f, 15.0f, 107.0f);
glEnd();


/////////////////////////////////  pasamanos e.med del 1.1//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.0f, 15.0f, 83.0f);
    glVertex3f( -12.0f, 15.7f, 83.0f);
    glVertex3f( -57.7f, 15.7f, 83.0f);
    glVertex3f( -57.7f, 15.0f, 83.0f);
glEnd();
/////////////////////////////////  pasamanos e.med del 1.2//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.0f, 15.0f, 79.5f);
    glVertex3f( -12.0f, 15.7f, 79.5f);
    glVertex3f( -57.7f, 15.7f, 79.5f);
    glVertex3f( -57.7f, 15.0f, 79.5f);
glEnd();


/////////////////////////////////  pasamanos e.med lat 1.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 5.3f, 15.0f, 79.5f);
    glVertex3f( 5.3f, 15.7f, 79.5f);
    glVertex3f( 5.3f, 15.7f, 110.5f);
    glVertex3f( 5.3f, 15.0f, 110.5f);
glEnd();
/////////////////////////////////  pasamanos e.med lat 1.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 1.7f, 15.0f, 79.5f);
    glVertex3f( 1.7f, 15.7f, 79.5f);
    glVertex3f( 1.7f, 15.7f, 107.5f);
    glVertex3f( 1.7f, 15.0f, 107.5f);
glEnd();
/////////////////////////////////  pasamanos e.med lat 2.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.0f, 15.0f, 79.5f);
    glVertex3f( -12.0f, 15.7f, 79.5f);
    glVertex3f( -12.0f, 15.7f, 83.0f);
    glVertex3f( -12.0f, 15.0f, 83.0f);
glEnd();
/////////////////////////////////  pasamanos e.med lat 2.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.7f, 15.0f, 83.0f);
    glVertex3f( -57.7f, 15.7f, 83.0f);
    glVertex3f( -57.7f, 15.7f, 79.5f);
    glVertex3f( -57.7f, 15.0f, 79.5f);
glEnd();
/////////////////////////////////  pasamanos e.med lat 3.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -70.5f, 15.0f, 79.5f);
    glVertex3f( -70.5f, 15.7f, 79.5f);
    glVertex3f( -70.5f, 15.7f, 110.5f);
    glVertex3f( -70.5f, 15.0f, 110.5f);
glEnd();
/////////////////////////////////  pasamanos e.med lat 3.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -67.7f, 15.0f, 79.5f);
    glVertex3f( -67.7f, 15.7f, 79.5f);
    glVertex3f( -67.7f, 15.7f, 107.5f);
    glVertex3f( -67.7f, 15.0f, 107.5f);
glEnd();

/////////////////////////////////  pasamanos e.med sup 1//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(   5.3f, 15.7f, 110.5f);
    glVertex3f(   5.3f, 15.7f, 107.0f);
    glVertex3f( -70.5f, 15.7f, 107.0f);
    glVertex3f( -70.5f, 15.7f, 110.5f);
glEnd();
/////////////////////////////////  pasamanos e.med sup 2//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 5.3f, 15.7f, 79.5f);
    glVertex3f( 5.3f, 15.7f, 107.0f);
    glVertex3f( 1.7f, 15.7f, 107.0f);
    glVertex3f( 1.7f, 15.7f, 79.5f);
glEnd();
/////////////////////////////////  pasamanos e.med sup 3//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.0f, 15.7f, 79.5f);
    glVertex3f( -12.0f, 15.7f, 83.0f);
    glVertex3f( -57.7f, 15.7f, 83.0f);
    glVertex3f( -57.7f, 15.7f, 79.5f);
glEnd();
/////////////////////////////////  pasamanos e.med sup 4//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -67.0f, 15.7f, 79.5f);
    glVertex3f( -67.0f, 15.7f, 107.0f);
    glVertex3f( -70.5f, 15.7f, 107.0f);
    glVertex3f( -70.5f, 15.7f, 79.5f);
glEnd();

/////////////////////////////////  pasamanos e.med inf 1//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(   5.3f, 15.0f, 110.5f);
    glVertex3f(   5.3f, 15.0f, 107.0f);
    glVertex3f( -70.5f, 15.0f, 107.0f);
    glVertex3f( -70.5f, 15.0f, 110.5f);
glEnd();
/////////////////////////////////  pasamanos e.med inf 2//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 5.3f, 15.0f, 79.5f);
    glVertex3f( 5.3f, 15.0f, 107.0f);
    glVertex3f( 1.7f, 15.0f, 107.0f);
    glVertex3f( 1.7f, 15.0f, 79.5f);
glEnd();
/////////////////////////////////  pasamanos e.med inf 3//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.0f, 15.0f, 79.5f);
    glVertex3f( -12.0f, 15.0f, 83.0f);
    glVertex3f( -57.7f, 15.0f, 83.0f);
    glVertex3f( -57.7f, 15.0f, 79.5f);
glEnd();
/////////////////////////////////  pasamanos e.med inf 4//////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -67.0f, 15.0f, 79.5f);
    glVertex3f( -67.0f, 15.0f, 107.0f);
    glVertex3f( -70.5f, 15.0f, 107.0f);
    glVertex3f( -70.5f, 15.0f, 79.5f);
glEnd();




///////////////////////////////////////////piso 2/////////////////////////////
/////////////////////////////////  pasamanos e.sup bajo 1.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -54.2f, 15.0f, 80.0f);
    glVertex3f( -54.2f, 25.0f, 34.5f);
    glVertex3f( -57.7f, 25.0f, 34.5f);
    glVertex3f( -57.7f, 15.0f, 80.0f);
glEnd();
/////////////////////////////////  pasamanos e.sup bajo 1.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -54.2f, 15.7f, 80.0f);
    glVertex3f( -54.2f, 25.7f, 34.5f);
    glVertex3f( -57.7f, 25.7f, 34.5f);
    glVertex3f( -57.7f, 15.7f, 80.0f);
glEnd();
/////////////////////////////////  pasamanos e.sup bajo 2.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -67.0f, 15.0f, 80.0f);
    glVertex3f( -67.0f, 25.0f, 34.5f);
    glVertex3f( -70.5f, 25.0f, 34.5f);
    glVertex3f( -70.5f, 15.0f, 80.0f);
glEnd();
/////////////////////////////////  pasamanos e.sup bajo 2.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -67.0f, 15.7f, 80.0f);
    glVertex3f( -67.0f, 25.7f, 34.5f);
    glVertex3f( -70.5f, 25.7f, 34.5f);
    glVertex3f( -70.5f, 15.7f, 80.0f);
glEnd();

/////////////////////////////////  pasamanos e.sup lat 1.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -54.2f, 15.0f, 80.0f);
    glVertex3f( -54.2f, 15.7f, 80.0f);
    glVertex3f( -54.2f, 25.7f, 34.5f);
    glVertex3f( -54.2f, 25.0f, 34.5f);
glEnd();
/////////////////////////////////  pasamanos e.sup lat 1.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.7f, 15.0f, 80.0f);
    glVertex3f( -57.7f, 15.7f, 80.0f);
    glVertex3f( -57.7f, 25.7f, 34.5f);
    glVertex3f( -57.7f, 25.0f, 34.5f);
glEnd();
/////////////////////////////////  pasamanos e.sup lat 2.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -67.0f, 15.0f, 80.0f);
    glVertex3f( -67.0f, 15.7f, 80.0f);
    glVertex3f( -67.0f, 25.7f, 34.5f);
    glVertex3f( -67.0f, 25.0f, 34.5f);
glEnd();
/////////////////////////////////  pasamanos e.sup lat 2.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -70.5f, 15.0f, 80.0f);
    glVertex3f( -70.5f, 15.7f, 80.0f);
    glVertex3f( -70.5f, 25.7f, 34.5f);
    glVertex3f( -70.5f, 25.0f, 34.5f);
glEnd();

/////////////////////////////////  pasamanos e.sup lat 2.3 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -67.0f, 25.0f, 34.5f);
    glVertex3f( -67.0f, 25.7f, 34.5f);
    glVertex3f( -70.5f, 25.7f, 34.5f);
    glVertex3f( -70.5f, 25.0f, 34.5f);
glEnd();
/////////////////////////////////  pasamanos e.sup lat 1.3 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -54.2f, 25.0f, 34.5f);
    glVertex3f( -54.2f, 25.7f, 34.5f);
    glVertex3f( -57.7f, 25.7f, 34.5f);
    glVertex3f( -57.7f, 25.0f, 34.5f);
glEnd();



}

void escalerasPrincipales(){
/////////////////////////////////  pasamanos e.inf.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 4.8f, 10.0f, 80.0f);
    glVertex3f( 4.8f, 15.0f, 80.0f);
    glVertex3f( 4.8f, 15.0f, 110.0f);
    glVertex3f( 4.8f, 10.0f, 110.0f);
glEnd();
/////////////////////////////////  pasamanos e.inf.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 2.2f, 10.0f, 80.0f);
    glVertex3f( 2.2f, 15.0f, 80.0f);
    glVertex3f( 2.2f, 15.0f, 107.5f);
    glVertex3f( 2.2f, 10.0f, 107.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf.3 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.5f, 10.0f, 80.0f);
    glVertex3f( -12.5f, 15.0f, 80.0f);
    glVertex3f( -12.5f, 15.0f, 82.5f);
    glVertex3f( -12.5f, 10.0f, 82.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf.5 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -12.5f, 10.0f, 82.5f);
    glVertex3f( -12.5f, 15.0f, 82.5f);
    glVertex3f( -57.2f, 15.0f, 82.5f);
    glVertex3f( -57.2f, 10.0f, 82.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf.6 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 2.2f, 10.0f, 107.5f);
    glVertex3f( 2.2f, 15.0f, 107.5f);
    glVertex3f( -67.5f, 15.0f, 107.5f);
    glVertex3f( -67.5f, 10.0f, 107.5f);
glEnd();
/////////////////////////////////  pasamanos e.inf.7 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -15.0f, 10.0f, 80.0f);
    glVertex3f( -15.0f, 15.0f, 80.0f);
    glVertex3f( -54.7f, 15.0f, 80.0f);
    glVertex3f( -54.7f, 10.0f, 80.0f);
glEnd();
/////////////////////////////////  pasamanos e.inf.8 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 10.0f, 82.5f);
    glVertex3f( -57.2f, 15.0f, 82.5f);
    glVertex3f( -57.2f, 15.0f, 80.0f);
    glVertex3f( -57.2f, 10.0f, 80.0f);
glEnd();
/////////////////////////////////  pasamanos e.inf.9 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -67.5f, 10.0f, 107.5f);
    glVertex3f( -67.5f, 15.0f, 107.5f);
    glVertex3f( -67.5f, 15.0f, 80.0f);
    glVertex3f( -67.5f, 10.0f, 80.0f);
glEnd();
/////////////////////////////////  pasamanos e.sup.1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 8.3f, 80.0f);
    glVertex3f( -57.2f, 15.0f, 80.0f);
    glVertex3f( -57.2f, 25.0f, 35.0f);
    glVertex3f( -57.2f, 20.0f, 35.0f);
glEnd();
/////////////////////////////////  pasamanos e.sup.2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -54.7f, 8.3f, 80.0f);
    glVertex3f( -54.7f, 15.0f, 80.0f);
    glVertex3f( -54.7f, 25.0f, 35.0f);
    glVertex3f( -54.7f, 21.0f, 35.0f);
glEnd();
/////////////////////////////////  pasamanos e.sup.3 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -70.0f, 21.0f, 35.0f);
    glVertex3f( -70.0f, 25.0f, 35.0f);
    glVertex3f( -70.0f, 15.0f, 80.0f);
    glVertex3f( -70.0f, 8.3f, 80.0f);
glEnd();
/////////////////////////////////  pasamanos e.sup.4 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -67.5f, 21.0f, 35.0f);
    glVertex3f( -67.5f, 25.0f, 35.0f);
    glVertex3f( -67.5f, 15.0f, 80.0f);
    glVertex3f( -67.5f, 8.3f, 80.0f);
glEnd();
/////////////////////////////////  pasamanos e.sup parte de abajo //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -54.7f,  8.3f, 80.0f);
    glVertex3f( -54.7f, 21.0f, 35.0f);
    glVertex3f( -70.0f, 21.0f, 35.0f);
    glVertex3f( -70.0f,  8.3f, 80.0f);
glEnd();

}

void escaleras(){
////////////////////////////////// escaleras  ////////////////////////////
/////////////////////////////////  e.muro 1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -15.0f, -5.0f, 40.0f);
		glVertex3f( -15.0f, 5.0f, 40.0f);
        glVertex3f( -15.0f, 15.0f, 80.0f);
		glVertex3f( -15.0f, -5.0f, 80.0f);
	glEnd();
/////////////////////////////////  e.muro 2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -12.5f, -5.0f, 40.0f);
		glVertex3f( -12.5f, 5.0f, 40.0f);
        glVertex3f( -12.5f, 15.0f, 80.0f);
		glVertex3f( -12.5f, -5.0f, 80.0f);
	glEnd();
/////////////////////////////////  e.muro 3 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 2.2f, -5.0f, 40.0f);
		glVertex3f( 2.2f, 5.0f, 40.0f);
        glVertex3f( 2.2f, 15.0f, 80.0f);
		glVertex3f( 2.2f, -5.0f, 80.0f);
	glEnd();
/////////////////////////////////  e.muro 4 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 4.7f, -5.0f, 40.0f);
		glVertex3f( 4.7f, 5.0f, 40.0f);
        glVertex3f( 4.7f, 15.0f, 80.0f);
		glVertex3f( 4.7f, -5.0f, 80.0f);
	glEnd();
/////////////////////////////////  e.muro 5 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 4.7f, 0.0f, 40.0f);
		glVertex3f( 4.7f, 3.6f, 40.0f);
        glVertex3f( 5.0f, 3.6f, 40.0f);
		glVertex3f( 5.0f, 0.0f, 40.0f);
	glEnd();
/////////////////////////////////  e.muro 6 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 2.2f, 0.0f, 40.0f);
		glVertex3f( 2.2f, 4.0f, 40.0f);
        glVertex3f( 4.7f, 4.0f, 40.0f);
		glVertex3f( 4.7f, 0.0f, 40.0f);
	glEnd();
/////////////////////////////////  e.muro 7 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -15.0f, 0.0f, 40.0f);
		glVertex3f( -15.0f, 5.0f, 40.0f);
        glVertex3f( -12.5f, 5.0f, 40.0f);
		glVertex3f( -12.5f, 0.0f, 40.0f);
	glEnd();
/////////////////////////////////  e.muro 6 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 2.2f, 0.0f, 40.0f);
		glVertex3f( 2.2f, 5.0f, 40.0f);
        glVertex3f( 4.8f, 5.0f, 40.0f);
		glVertex3f( 4.8f, 0.0f, 40.0f);
	glEnd();
}

void escaleras2 (){
/////////////////////////////////  piso 2.1 escalera 1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -15.0f, -1.6f, 40.0f);
		glVertex3f( -15.0f, -1.6f, 41.6f);
        glVertex3f( -71.6f, -1.6f, 41.6f);
		glVertex3f( -70.0f, -1.6f, 40.0f);
	glEnd();
/////////////////////////////////  piso 2.1 escalera 2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -15.0f, -3.2f, 41.6f);
		glVertex3f( -15.0f, -3.2f, 43.2f);
        glVertex3f( -73.2f, -3.2f, 43.2f);
		glVertex3f( -71.6f, -3.2f, 41.6f);
	glEnd();
/////////////////////////////////  piso 2.2 escalera 1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, -1.6f, 20.0f);
		glVertex3f( -71.6f, -1.6f, 21.6f);
        glVertex3f( -80.0f, -1.6f, 21.6f);
		glVertex3f( -80.0f, -1.6f, 20.0f);
	glEnd();
/////////////////////////////////  piso 2.2 escalera 2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -71.6f, -3.2f, 21.6f);
		glVertex3f( -73.2f, -3.2f, 23.2f);
        glVertex3f( -80.0f, -3.2f, 23.2f);
		glVertex3f( -80.0f, -3.2f, 21.6f);
	glEnd();
//////////////////////////////////////// piso 2.2 escalera 1  ///////////////////////
   glBegin(GL_QUADS);
	    glVertex3f( -70.0f, -1.6f, 20.0f);
		glVertex3f( -70.0f, -1.6f, 40.0f);
        glVertex3f( -71.6f, -1.6f, 41.6f);
		glVertex3f( -71.6f, -1.6f, 21.6f);
	glEnd();
//////////////////////////////////////// piso 2.2 escalera 2 ////////////////////////
   glBegin(GL_QUADS);
	    glVertex3f( -71.6f, -3.2f, 21.6f);
		glVertex3f( -71.6f, -3.2f, 41.6f);
        glVertex3f( -73.2f, -3.2f, 43.2f);
		glVertex3f( -73.2f, -3.2f, 23.2f);
	glEnd();
}

void escalerasB (){
/////////////////////////////////  ENTRADA ///////////////////////////////////
/////////////////////////////////  piso 2.1 escalera 1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -15.0f, -1.6f, 40.0f);
		glVertex3f( -15.0f, 0.0f, 40.0f);
        glVertex3f( -70.0f, 0.0f, 40.0f);
		glVertex3f( -70.0f, -1.6f, 40.0f);
	glEnd();
/////////////////////////////////  piso 2.1 escalera 2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -15.0f, -1.6f, 41.6f);
		glVertex3f( -15.0f, -3.2f, 41.6f);
        glVertex3f( -71.6f, -3.2f, 41.6f);
		glVertex3f( -71.6f, -1.6f, 41.6f);
	glEnd();
/////////////////////////////////  piso 2.1 escalera 3 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -15.0f, -5.0f, 43.2f);
		glVertex3f( -15.0f, -3.2f, 43.2f);
        glVertex3f( -73.2f, -3.2f, 43.2f);
		glVertex3f( -73.2f, -5.0f, 43.2f);
	glEnd();
/////////////////////////////////  piso 2.2 escalera 1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, -1.6f, 20.0f);
		glVertex3f( -70.0f, 0.0f, 20.0f);
        glVertex3f( -80.0f, 0.0f, 20.0f);
		glVertex3f( -80.0f, -1.6f, 20.0f);
	glEnd();
/////////////////////////////////  piso 2.2 escalera 2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -71.6f, -1.6f, 21.6f);
		glVertex3f( -71.6f, -3.2f, 21.6f);
        glVertex3f( -80.0f, -3.2f, 21.6f);
		glVertex3f( -80.0f, -1.6f, 21.6f);
	glEnd();
/////////////////////////////////  piso 2.2 escalera 3 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -73.2f, -5.0f, 23.2f);
		glVertex3f( -73.2f, -3.2f, 23.2f);
        glVertex3f( -80.0f, -3.2f, 23.2f);
		glVertex3f( -80.0f, -5.0f, 23.2f);
	glEnd();
/////////////////////////////////  piso 2 escalera muro hueco 1 /////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, -1.6f, 20.0f);
		glVertex3f( -70.0f, 0.0f, 20.0f);
        glVertex3f( -70.0f, 0.0f, 40.0f);
		glVertex3f( -70.0f, -1.6f, 40.0f);
	glEnd();
/////////////////////////////////  piso 2 escalera muro hueco 2 /////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -71.6f, -3.2f, 21.6f);
		glVertex3f( -71.6f, -1.6f, 21.6f);
        glVertex3f( -71.6f, -1.6f, 41.6f);
		glVertex3f( -71.6f, -3.2f, 41.6f);
	glEnd();
/////////////////////////////////  piso 2 escalera muro hueco 3 //////////////////////
    glBegin(GL_QUADS);
	    glVertex3f( -73.2f, -5.0f, 23.2f);
		glVertex3f( -73.2f, -3.2f, 23.2f);
        glVertex3f( -73.2f, -3.2f, 43.2f);
		glVertex3f( -73.2f, -5.0f, 43.2f);
	glEnd();
////////////////////////////////// BAÑOS ////////////////////////////////////////
/////////////////////////////  e.b peldaño lado 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -24.0f, -5.0f, 245.0f);
		glVertex3f( -24.0f, -3.2f, 245.0f);
		glVertex3f( -24.0f, -3.2f, 265.0f);
		glVertex3f( -24.0f, -5.0f, 265.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -22.0f, -1.6f, 245.0f);
		glVertex3f( -22.0f, -3.2f, 245.0f);
		glVertex3f( -22.0f, -3.2f, 265.0f);
		glVertex3f( -22.0f, -1.6f, 265.0f);
	glEnd();
///////////////////////////// e.b  peldaño lado 3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, -1.6f, 245.0f);
		glVertex3f( -20.0f, 0.0f, 245.0f);
		glVertex3f( -20.0f, 0.0f, 265.0f);
		glVertex3f( -20.0f, -1.6f, 265.0f);
	glEnd();
///////////////////////////// e.b  muro hueco 1.1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, -1.6f, 245.0f);
		glVertex3f( -20.0f, -3.2f, 245.0f);
		glVertex3f( -22.0f, -3.2f, 245.0f);
		glVertex3f( -22.0f, -1.6f, 245.0f);
	glEnd();
///////////////////////////// e.b  muro hueco 1.2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, -1.6f, 265.0f);
		glVertex3f( -20.0f, -3.2f, 265.0f);
		glVertex3f( -22.0f, -3.2f, 265.0f);
		glVertex3f( -22.0f, -1.6f, 265.0f);
	glEnd();
///////////////////////////// e.b  muro hueco 2.1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -24.0f, -3.2f, 245.0f);
		glVertex3f( -24.0f, -5.0f, 245.0f);
		glVertex3f( -20.0f, -5.0f, 245.0f);
		glVertex3f( -20.0f, -3.2f, 245.0f);
	glEnd();
///////////////////////////// e.b  muro hueco 2.1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -24.0f, -3.2f, 265.0f);
		glVertex3f( -24.0f, -5.0f, 265.0f);
		glVertex3f( -20.0f, -5.0f, 265.0f);
		glVertex3f( -20.0f, -3.2f, 265.0f);
	glEnd();
////////////////////////////////////// escaleras sobre el sotano /////////////
/////////////////////////////  e.sa peldaño lat 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 8.0f, 267.0f);
		glVertex3f( -5.0f, 10.0f, 267.0f);
		glVertex3f( 10.0f, 10.0f, 267.0f);
		glVertex3f( 10.0f, 8.0f, 267.0f);
	glEnd();
/////////////////////////////  e.sa peldaño lat 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 8.0f, 264.0f);
		glVertex3f( -5.0f, 6.0f, 264.0f);
		glVertex3f( 10.0f, 6.0f, 264.0f);
		glVertex3f( 10.0f, 8.0f, 264.0f);
	glEnd();
/////////////////////////////  e.sa peldaño lat 3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 4.0f, 261.0f);
		glVertex3f( -5.0f, 6.0f, 261.0f);
		glVertex3f( 10.0f, 6.0f, 261.0f);
		glVertex3f( 10.0f, 4.0f, 261.0f);
	glEnd();
/////////////////////////////  e.sa peldaño lat 4/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 2.0f, 258.0f);
		glVertex3f( 10.0f, 4.0f, 258.0f);
		glVertex3f( -5.0f, 4.0f, 258.0f);
		glVertex3f( -5.0f, 2.0f, 258.0f);
	glEnd();
/////////////////////////////  e.sa peldaño lat 5/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 0.0f, 255.0f);
		glVertex3f( 10.0f, 2.0f, 255.0f);
		glVertex3f( -5.0f, 2.0f, 255.0f);
		glVertex3f( -5.0f, 0.0f, 255.0f);
	glEnd();
}

void escalerasBanosYSotano(){
/////////////////////////////  e.b peldaño 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, -1.6f, 245.0f);
		glVertex3f( -20.0f, -1.6f, 265.0f);
		glVertex3f( -22.0f, -1.6f, 265.0f);
		glVertex3f( -22.0f, -1.6f, 245.0f);
	glEnd();
/////////////////////////////  e.ba peldaño 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -24.0f, -3.2f, 245.0f);
		glVertex3f( -24.0f, -3.2f, 265.0f);
		glVertex3f( -22.0f, -3.2f, 265.0f);
		glVertex3f( -22.0f, -3.2f, 245.0f);
	glEnd();

/////////////////////////////  e.s peldaño 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 0.0f, 280.0f);
		glVertex3f( -5.0f, 0.0f, 270.0f);
		glVertex3f( -3.0f, 0.0f, 270.0f);
		glVertex3f( -3.0f, 0.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s peldaño 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -3.0f, -2.0f, 280.0f);
		glVertex3f( -3.0f, -2.0f, 270.0f);
		glVertex3f( -1.0f, -2.0f, 270.0f);
		glVertex3f( -1.0f, -2.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s peldaño 3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 1.0f, -4.0f, 280.0f);
		glVertex3f( 1.0f, -4.0f, 270.0f);
		glVertex3f( -1.0f, -4.0f, 270.0f);
		glVertex3f( -1.0f, -4.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s peldaño 4/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 3.0f, -6.0f, 280.0f);
		glVertex3f( 3.0f, -6.0f, 270.0f);
		glVertex3f( 1.0f, -6.0f, 270.0f);
		glVertex3f( 1.0f, -6.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s peldaño 5/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 5.0f, -8.0f, 280.0f);
		glVertex3f( 5.0f, -8.0f, 270.0f);
		glVertex3f( 3.0f, -8.0f, 270.0f);
		glVertex3f( 3.0f, -8.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s peldaño 6/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 5.0f, -10.0f, 280.0f);
		glVertex3f( 5.0f, -10.0f, 270.0f);
		glVertex3f( 7.0f, -10.0f, 270.0f);
		glVertex3f( 7.0f, -10.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s peldaño 7/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 9.0f, -12.0f, 280.0f);
		glVertex3f( 9.0f, -12.0f, 270.0f);
		glVertex3f( 7.0f, -12.0f, 270.0f);
		glVertex3f( 7.0f, -12.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s peldaño 8/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 11.0f, -14.0f, 280.0f);
		glVertex3f( 11.0f, -14.0f, 270.0f);
		glVertex3f( 9.0f, -14.0f, 270.0f);
		glVertex3f( 9.0f, -14.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s peldaño 9/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 13.0f, -16.0f, 280.0f);
		glVertex3f( 13.0f, -16.0f, 270.0f);
		glVertex3f( 11.0f, -16.0f, 270.0f);
		glVertex3f( 11.0f, -16.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s peldaño 10/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 13.0f, -18.0f, 280.0f);
		glVertex3f( 13.0f, -18.0f, 270.0f);
		glVertex3f( 15.0f, -18.0f, 270.0f);
		glVertex3f( 15.0f, -18.0f, 280.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -3.0f, 0.0f, 280.0f);
		glVertex3f( -3.0f, -2.0f, 280.0f);
		glVertex3f( -3.0f, -2.0f, 270.0f);
		glVertex3f( -3.0f, 0.0f, 270.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -1.0f, -4.0f, 280.0f);
		glVertex3f( -1.0f, -2.0f, 280.0f);
		glVertex3f( -1.0f, -2.0f, 270.0f);
		glVertex3f( -1.0f, -4.0f, 270.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 1.0f, -4.0f, 280.0f);
		glVertex3f( 1.0f, -6.0f, 280.0f);
		glVertex3f( 1.0f, -6.0f, 270.0f);
		glVertex3f( 1.0f, -4.0f, 270.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 4/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 3.0f, -8.0f, 280.0f);
		glVertex3f( 3.0f, -6.0f, 280.0f);
		glVertex3f( 3.0f, -6.0f, 270.0f);
		glVertex3f( 3.0f, -8.0f, 270.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 5/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 5.0f, -8.0f, 280.0f);
		glVertex3f( 5.0f, -10.0f, 280.0f);
		glVertex3f( 5.0f, -10.0f, 270.0f);
		glVertex3f( 5.0f, -8.0f, 270.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 6/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 7.0f, -12.0f, 280.0f);
		glVertex3f( 7.0f, -10.0f, 280.0f);
		glVertex3f( 7.0f, -10.0f, 270.0f);
		glVertex3f( 7.0f, -12.0f, 270.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 7/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 9.0f, -12.0f, 280.0f);
		glVertex3f( 9.0f, -14.0f, 280.0f);
		glVertex3f( 9.0f, -14.0f, 270.0f);
		glVertex3f( 9.0f, -12.0f, 270.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 8/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 11.0f, -16.0f, 280.0f);
		glVertex3f( 11.0f, -14.0f, 280.0f);
		glVertex3f( 11.0f, -14.0f, 270.0f);
		glVertex3f( 11.0f, -16.0f, 270.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 8/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 13.0f, -18.0f, 280.0f);
		glVertex3f( 13.0f, -16.0f, 280.0f);
		glVertex3f( 13.0f, -16.0f, 270.0f);
		glVertex3f( 13.0f, -18.0f, 270.0f);
	glEnd();
/////////////////////////////  e.b peldaño lado 9/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 15.0f, -18.0f, 280.0f);
		glVertex3f( 15.0f, -20.0f, 280.0f);
		glVertex3f( 15.0f, -20.0f, 270.0f);
		glVertex3f( 15.0f, -18.0f, 270.0f);
	glEnd();
/////////////////////////////////  muro escaleras rampa bajo  //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -20.0f, -5.0f, 265.0f);
    glVertex3f( -20.0f, 0.0f, 265.0f);
    glVertex3f( -50.0f, -2.5f, 265.0f);
    glVertex3f( -50.0f, -5.0f, 265.0f);
glEnd();
/////////////////////////////////  muro rampita bajo  //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -50.0f, -2.5f, 265.0f);
    glVertex3f( -70.0f, -2.5f, 265.0f);
    glVertex3f( -70.0f, -5.0f, 255.0f);
    glVertex3f( -50.0f, -5.0f, 255.0f);
glEnd();
/////////////////////////////////  muro rampita bajo lateral //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -50.0f, -2.5f, 265.0f);
    glVertex3f( -50.0f, -5.0f, 255.0f);
    glVertex3f( -50.0f, -5.0f, 265.0f);
    glVertex3f( -50.0f, -5.0f, 265.1f);
glEnd();
////////////////////////////////////////// escaleras arriba sotano /////////////////////////
/////////////////////////////  e.sa peldaño 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 8.0f, 267.0f);
		glVertex3f( -5.0f, 8.0f, 264.0f);
		glVertex3f( 10.0f, 8.0f, 264.0f);
		glVertex3f( 10.0f, 8.0f, 267.0f);
	glEnd();
/////////////////////////////  e.sa peldaño 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 6.0f, 261.0f);
		glVertex3f( -5.0f, 6.0f, 264.0f);
		glVertex3f( 10.0f, 6.0f, 264.0f);
		glVertex3f( 10.0f, 6.0f, 261.0f);
	glEnd();
/////////////////////////////  e.sa peldaño 3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 4.0f, 261.0f);
		glVertex3f( -5.0f, 4.0f, 258.0f);
		glVertex3f( 10.0f, 4.0f, 258.0f);
		glVertex3f( 10.0f, 4.0f, 261.0f);
	glEnd();
/////////////////////////////  e.sa peldaño 4/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 2.0f, 258.0f);
		glVertex3f( 10.0f, 2.0f, 255.0f);
		glVertex3f( -5.0f, 2.0f, 255.0f);
		glVertex3f( -5.0f, 2.0f, 258.0f);
	glEnd();
////////////////////////////// piso sobre el sotano ////////////////////
/////////////////////////////  e.sa piso del/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 8.0f, 267.0f);
		glVertex3f( -5.0f, 10.0f, 267.0f);
		glVertex3f( -5.0f, 10.0f, 280.0f);
		glVertex3f( -5.0f, 8.0f, 280.0f);
	glEnd();
/////////////////////////////  e.sa esc del 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 8.0f, 270.0f);
		glVertex3f( -5.0f, 6.0f, 270.0f);
		glVertex3f( -5.0f, 6.0f, 264.0f);
		glVertex3f( -5.0f, 8.0f, 264.0f);
	glEnd();
/////////////////////////////  e.sa esc del 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 4.0f, 261.0f);
		glVertex3f( -5.0f, 6.0f, 261.0f);
		glVertex3f( -5.0f, 6.0f, 270.0f);
		glVertex3f( -5.0f, 4.0f, 270.0f);
	glEnd();
/////////////////////////////  e.sa esc del 3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 4.0f, 270.0f);
		glVertex3f( -5.0f, 2.0f, 270.0f);
		glVertex3f( -5.0f, 2.0f, 258.0f);
		glVertex3f( -5.0f, 4.0f, 258.0f);
	glEnd();
/////////////////////////////  e.sa esc del 4/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 0.0f, 270.0f);
		glVertex3f( -5.0f, 2.0f, 270.0f);
		glVertex3f( -5.0f, 2.0f, 255.0f);
		glVertex3f( -5.0f, 0.0f, 255.0f);
	glEnd();
//////////////////////////////// e.antes del sotano ///////////////////////
/////////////////////////////  e.ant.s peldaño 5/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 10.0f, 292.0f);
		glVertex3f( -20.0f, 10.0f, 302.0f);
		glVertex3f( -10.0f, 10.0f, 302.0f);
		glVertex3f( -10.0f, 10.0f, 292.0f);
	glEnd();
/////////////////////////////  e.ant.speldaño 4/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 8.0f, 292.0f);
		glVertex3f( -20.0f, 8.0f, 289.0f);
		glVertex3f( -10.0f, 8.0f, 289.0f);
		glVertex3f( -10.0f, 8.0f, 292.0f);
	glEnd();
/////////////////////////////  e.ant.s peldaño 3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 6.0f, 289.0f);
		glVertex3f( -20.0f, 6.0f, 286.0f);
		glVertex3f( -10.0f, 6.0f, 286.0f);
		glVertex3f( -10.0f, 6.0f, 289.0f);
	glEnd();
/////////////////////////////  e.ant.s peldaño 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 4.0f, 286.0f);
		glVertex3f( -20.0f, 4.0f, 283.0f);
		glVertex3f( -10.0f, 4.0f, 283.0f);
		glVertex3f( -10.0f, 4.0f, 286.0f);
	glEnd();
/////////////////////////////  e.ant.s peldaño 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 2.0f, 283.0f);
		glVertex3f( -20.0f, 2.0f, 280.0f);
		glVertex3f( -10.0f, 2.0f, 280.0f);
		glVertex3f( -10.0f, 2.0f, 283.0f);
	glEnd();
}

void escalerasEscalones(){
///////////////////////////////// primer piso ////////////////////////////
/////////////////////////////////  escalon 1-2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(   2.2f, 1.2f, 40.0f);
    glVertex3f(   2.2f, 0.0f, 40.0f);
    glVertex3f( -12.5f, 0.0f, 40.0f);
    glVertex3f( -12.5f, 1.2f, 40.0f);
glEnd();
/////////////////////////////////  escalon 2-3 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  2.4f, 45.0f);
    glVertex3f(  2.2f,  1.2f, 45.0f);
    glVertex3f( -12.5f, 1.2f, 45.0f);
    glVertex3f( -12.5f, 2.4f, 45.0f);
glEnd();
/////////////////////////////////  escalon 3-4 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  3.6f, 50.0f);
    glVertex3f(  2.2f,  2.4f, 50.0f);
    glVertex3f( -12.5f, 2.4f, 50.0f);
    glVertex3f( -12.5f, 3.6f, 50.0f);
glEnd();
/////////////////////////////////  escalon 4-5 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  3.6f, 55.0f);
    glVertex3f(  2.2f,  4.8f, 55.0f);
    glVertex3f( -12.5f, 4.8f, 55.0f);
    glVertex3f( -12.5f, 3.6f, 55.0f);
glEnd();
/////////////////////////  escalon 5-6 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  6.0f, 60.0f);
    glVertex3f(  2.2f,  4.8f, 60.0f);
    glVertex3f( -12.5f, 4.8f, 60.0f);
    glVertex3f( -12.5f, 6.0f, 60.0f);
glEnd();
/////////////////////////////////  escalon 6-7 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  7.3f, 65.0f);
    glVertex3f(  2.2f,  6.0f, 65.0f);
    glVertex3f( -12.5f, 6.0f, 65.0f);
    glVertex3f( -12.5f, 7.3f, 65.0f);
glEnd();
//////////////////  escalon 7-8 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  7.3f, 70.0f);
    glVertex3f(  2.2f,  8.5f, 70.0f);
    glVertex3f( -12.5f, 8.5f, 70.0f);
    glVertex3f( -12.5f, 7.3f, 70.0f);
glEnd();
/////////////////////////////////  escalon 8-9 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  10.0f, 75.0f);
    glVertex3f(  2.2f,  8.5f, 75.0f);
    glVertex3f( -12.5f, 8.5f, 75.0f);
    glVertex3f( -12.5f, 10.0f, 75.0f);
glEnd();
/////////////////////////////////  escalon 1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( 2.2f,  1.2f, 40.0f);
    glVertex3f( 2.2f,  1.2f, 45.0f);
    glVertex3f( -12.5f, 1.2f, 45.0f);
    glVertex3f( -12.5f, 1.2f, 40.0f);
glEnd();
/////////////////////////////////  escalon 2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  2.4f, 50.0f);
    glVertex3f(  2.2f,  2.4f, 45.0f);
    glVertex3f( -12.5f, 2.4f, 45.0f);
    glVertex3f( -12.5f, 2.4f, 50.0f);
glEnd();
/////////////////////////////////  escalon 3 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  3.6f, 50.0f);
    glVertex3f(  2.2f,  3.6f, 55.0f);
    glVertex3f( -12.5f, 3.6f, 55.0f);
    glVertex3f( -12.5f, 3.6f, 50.0f);
glEnd();
/////////////////////////////////  escalon 4 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  4.8f, 55.0f);
    glVertex3f(  2.2f,  4.8f, 60.0f);
    glVertex3f( -12.5f, 4.8f, 60.0f);
    glVertex3f( -12.5f, 4.8f, 55.0f);
glEnd();
/////////////////////////////////  escalon 5 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  6.0f, 60.0f);
    glVertex3f(  2.2f,  6.0f, 65.0f);
    glVertex3f( -12.5f, 6.0f, 65.0f);
    glVertex3f( -12.5f, 6.0f, 60.0f);
glEnd();
/////////////////////////////////  escalon 6 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  7.3f, 65.0f);
    glVertex3f(  2.2f,  7.3f, 70.0f);
    glVertex3f( -12.5f, 7.3f, 70.0f);
    glVertex3f( -12.5f, 7.3f, 65.0f);
glEnd();
/////////////////////////////////  escalon 7 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  8.5f, 70.0f);
    glVertex3f(  2.2f,  8.5f, 75.0f);
    glVertex3f( -12.5f, 8.5f, 75.0f);
    glVertex3f( -12.5f, 8.5f, 70.0f);
glEnd();
/////////////////////////////////  escalon 8 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f(  2.2f,  10.0f, 80.0f);
    glVertex3f(  2.2f,  10.0f, 75.0f);
    glVertex3f( -12.5f, 10.0f, 75.0f);
    glVertex3f( -12.5f, 10.0f, 80.0f);
glEnd();
////////////////////////////////  segundo piso ////////////////////////////

/////////////////////////////////  escalon 2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 19.7f, 45.0f);
    glVertex3f( -57.2f, 19.7f, 40.0f);
    glVertex3f( -67.5f, 19.7f, 40.0f);
    glVertex3f( -67.5f, 19.7f, 45.0f);
glEnd();
/////////////////////////////////  escalon 3 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 18.5f, 50.0f);
    glVertex3f( -57.2f, 18.5f, 45.0f);
    glVertex3f( -67.5f, 18.5f, 45.0f);
    glVertex3f( -67.5f, 18.5f, 50.0f);
glEnd();
/////////////////////////////////  escalon 3 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 17.3f, 55.0f);
    glVertex3f( -57.2f, 17.3f, 50.0f);
    glVertex3f( -67.5f, 17.3f, 50.0f);
    glVertex3f( -67.5f, 17.3f, 55.0f);
glEnd();
/////////////////////////////////  escalon 4 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 16.0f, 60.0f);
    glVertex3f( -57.2f, 16.0f, 55.0f);
    glVertex3f( -67.5f, 16.0f, 55.0f);
    glVertex3f( -67.5f, 16.0f, 60.0f);
glEnd();
/////////////////////////////////  escalon 5 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 14.8f, 60.0f);
    glVertex3f( -57.2f, 14.8f, 65.0f);
    glVertex3f( -67.5f, 14.8f, 65.0f);
    glVertex3f( -67.5f, 14.8f, 60.0f);
glEnd();
/////////////////////////////////  escalon 6 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 13.6f, 65.0f);
    glVertex3f( -57.2f, 13.6f, 70.0f);
    glVertex3f( -67.5f, 13.6f, 70.0f);
    glVertex3f( -67.5f, 13.6f, 65.0f);
glEnd();
/////////////////////////////////  escalon 7 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 12.4f, 75.0f);
    glVertex3f( -57.2f, 12.4f, 70.0f);
    glVertex3f( -67.5f, 12.4f, 70.0f);
    glVertex3f( -67.5f, 12.4f, 75.0f);
glEnd();
/////////////////////////////////  escalon 8 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 11.2f, 80.0f);
    glVertex3f( -57.2f, 11.2f, 75.0f);
    glVertex3f( -67.5f, 11.2f, 75.0f);
    glVertex3f( -67.5f, 11.2f, 80.0f);
glEnd();

/////////////////////////////////  escalon 0-techo //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 21.0f, 40.0f);
    glVertex3f( -57.2f, 19.7f, 40.0f);
    glVertex3f( -67.5f, 19.7f, 40.0f);
    glVertex3f( -67.5f, 21.0f, 40.0f);
glEnd();
/////////////////////////////////  escalon 0-1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 18.5f, 45.0f);
    glVertex3f( -57.2f, 19.7f, 45.0f);
    glVertex3f( -67.5f, 19.7f, 45.0f);
    glVertex3f( -67.5f, 18.5f, 45.0f);
glEnd();
/////////////////////////////////  escalon 2-1 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 18.5f, 50.0f);
    glVertex3f( -57.2f, 17.3f, 50.0f);
    glVertex3f( -67.5f, 17.3f, 50.0f);
    glVertex3f( -67.5f, 18.5f, 50.0f);
glEnd();
/////////////////////////////////  escalon 3-2 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 16.0f, 55.0f);
    glVertex3f( -57.2f, 17.3f, 55.0f);
    glVertex3f( -67.5f, 17.3f, 55.0f);
    glVertex3f( -67.5f, 16.0f, 55.0f);
glEnd();
/////////////////////////////////  escalon 4-3 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 16.0f, 60.0f);
    glVertex3f( -57.2f, 14.8f, 60.0f);
    glVertex3f( -67.5f, 14.8f, 60.0f);
    glVertex3f( -67.5f, 16.0f, 60.0f);
glEnd();
/////////////////////////////////  escalon 5-4 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 13.6f, 65.0f);
    glVertex3f( -57.2f, 14.8f, 65.0f);
    glVertex3f( -67.5f, 14.8f, 65.0f);
    glVertex3f( -67.5f, 13.6f, 65.0f);
glEnd();
/////////////////////////////////  escalon 6-5 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 13.6f, 70.0f);
    glVertex3f( -57.2f, 12.4f, 70.0f);
    glVertex3f( -67.5f, 12.4f, 70.0f);
    glVertex3f( -67.5f, 13.6f, 70.0f);
glEnd();
/////////////////////////////////  escalon 6-7 //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 11.2f, 75.0f);
    glVertex3f( -57.2f, 12.4f, 75.0f);
    glVertex3f( -67.5f, 12.4f, 75.0f);
    glVertex3f( -67.5f, 11.2f, 75.0f);
glEnd();
/////////////////////////////////  escalon 8-cafe //////////////////////////////
glBegin(GL_QUADS);
    glVertex3f( -57.2f, 10.0f, 80.0f);
    glVertex3f( -57.2f, 11.2f, 80.0f);
    glVertex3f( -67.5f, 11.2f, 80.0f);
    glVertex3f( -67.5f, 10.0f, 80.0f);
glEnd();
//////////////////////////////////// escaleras antes del sotano ///////////////
/////////////////////////////  e.ant.s l.5////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 8.0f, 292.0f);
		glVertex3f( -20.0f, 10.0f, 292.0f);
		glVertex3f( -10.0f, 10.0f, 292.0f);
		glVertex3f( -10.0f, 8.0f, 292.0f);
	glEnd();
/////////////////////////////  e.sa peldaño l.4/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 6.0f, 289.0f);
		glVertex3f( -20.0f, 8.0f, 289.0f);
		glVertex3f( -10.0f, 8.0f, 289.0f);
		glVertex3f( -10.0f, 6.0f, 289.0f);
	glEnd();
/////////////////////////////  e.sa peldaño l.3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 4.0f, 286.0f);
		glVertex3f( -20.0f, 6.0f, 286.0f);
		glVertex3f( -10.0f, 6.0f, 286.0f);
		glVertex3f( -10.0f, 4.0f, 286.0f);
	glEnd();
/////////////////////////////  e.sa peldaño l.2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 2.0f, 283.0f);
		glVertex3f( -20.0f, 4.0f, 283.0f);
		glVertex3f( -10.0f, 4.0f, 283.0f);
		glVertex3f( -10.0f, 2.0f, 283.0f);
	glEnd();
/////////////////////////////  e.sa peldaño l.1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 0.0f, 280.0f);
		glVertex3f( -20.0f, 2.0f, 280.0f);
		glVertex3f( -10.0f, 2.0f, 280.0f);
		glVertex3f( -10.0f, 0.0f, 280.0f);
	glEnd();
}

void cafe(){
/////////////////////////////////  cafe 1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, -5.0f, 80.0f);
		glVertex3f( -70.0f, 10.0f, 80.0f);
        glVertex3f( -27.0f, 10.0f, 80.0f);
		glVertex3f( -27.0f, -5.0f, 80.0f);
	glEnd();
/////////////////////////////////  cafe 1 interno //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, -5.0f, 81.0f);
		glVertex3f( -70.0f, 10.0f, 81.0f);
        glVertex3f( -27.0f, 10.0f, 81.0f);
		glVertex3f( -27.0f, -5.0f, 81.0f);
	glEnd();
/////////////////////////////////  cafe puerta 1  //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 8.5f, 80.0f);
		glVertex3f( -20.0f, 10.0f, 80.0f);
        glVertex3f( -27.0f, 10.0f, 80.0f);
		glVertex3f( -27.0f, 8.5f, 80.0f);
	glEnd();
/////////////////////////////////  cafe puerta 2  //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 8.5f, 81.0f);
		glVertex3f( -20.0f, 10.0f, 81.0f);
        glVertex3f( -27.0f, 10.0f, 81.0f);
		glVertex3f( -27.0f, 8.5f, 81.0f);
	glEnd();
/////////////////////////////////  cafe puerta 3  //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 8.5f, 80.0f);
		glVertex3f( -27.0f, 8.5f, 80.0f);
        glVertex3f( -27.0f, 8.5f, 81.0f);
		glVertex3f( -20.0f, 8.5f, 81.0f);
	glEnd();
/////////////////////////////////  cafe 2 esxterno //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, -5.0f, 80.0f);
		glVertex3f( -20.0f, 10.0f, 80.0f);
        glVertex3f( 5.0f, 10.0f, 80.0f);
		glVertex3f( 5.0f, -5.0f, 80.0f);
	glEnd();
/////////////////////////////////  cafe 2 interno //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, -5.0f, 81.0f);
		glVertex3f( -20.0f, 10.0f, 81.0f);
        glVertex3f( 5.0f, 10.0f, 81.0f);
		glVertex3f( 5.0f, -5.0f, 81.0f);
	glEnd();
/////////////////////////////////  cafe 3 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, -5.0f, 80.0f);
		glVertex3f( -20.0f, 10.0f, 80.0f);
        glVertex3f( -20.0f, 10.0f, 81.0f);
		glVertex3f( -20.0f, -5.0f, 81.0f);
	glEnd();
/////////////////////////////////  cafe 4 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -27.0f, -5.0f, 80.0f);
		glVertex3f( -27.0f, 10.0f, 80.0f);
        glVertex3f( -27.0f, 10.0f, 81.0f);
		glVertex3f( -27.0f, -5.0f, 81.0f);
	glEnd();
/////////////////////////////////  techo cafe //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 5.0f, 10.0f, 80.0f);
		glVertex3f( 5.0f, 10.0f, 110.0f);
        glVertex3f( -70.0f, 10.0f, 110.0f);
		glVertex3f( -70.0f, 10.0f, 80.0f);
	glEnd();
/////////////////////////////////  pasillo //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -70.0f, -5.0f, 110.0f);
		glVertex3f( -70.0f, 15.0f, 110.0f);
        glVertex3f( -70.0f, 15.0f, 80.0f);
		glVertex3f( -70.0f, -5.0f, 80.0f);
	glEnd();
}

void murosL(){
/////////////////////////////////  p1-p2 arriba //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -1.0f, 16.0f, -20.0f);
		glVertex3f( -1.0f, 16.0f, -22.0f);
        glVertex3f( -20.0f, 16.0f, -22.0f);
		glVertex3f( -20.0f, 16.0f, -20.0f);
	glEnd();
/////////////////////////////////  p1-p2 l.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -1.0f, -5.0f, -20.0f);
		glVertex3f( -1.0f, 16.0f, -20.0f);
        glVertex3f( -1.0f, 16.0f, -22.0f);
		glVertex3f( -1.0f, -5.0f, -22.0f);
	glEnd();
/////////////////////////////////  p1-p2 l.2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, -5.0f, -20.0f);
		glVertex3f( -20.0f, 16.0f, -20.0f);
        glVertex3f( -20.0f, 16.0f, -22.0f);
		glVertex3f( -20.0f, -5.0f, -22.0f);
	glEnd();
/////////////////////////////////  p5-p10 arriba //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -80.0f, 16.0f, 270.0f);
		glVertex3f( -80.0f, 16.0f, 272.0f);
        glVertex3f( -110.0f, 16.0f, 272.0f);
		glVertex3f( -110.0f, 16.0f, 270.0f);
	glEnd();
/////////////////////////////////  p5-p10 l.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -80.0f, -5.0f, 270.0f);
		glVertex3f( -80.0f, 16.0f, 270.0f);
        glVertex3f( -80.0f, 16.0f, 272.0f);
		glVertex3f( -80.0f, -5.0f, 272.0f);
	glEnd();
/////////////////////////////////  p5-p10 l.2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -110.0f, -5.0f, 270.0f);
		glVertex3f( -110.0f, 16.0f, 270.0f);
        glVertex3f( -110.0f, 16.0f, 272.0f);
		glVertex3f( -110.0f, -5.0f, 272.0f);
	glEnd();
/////////////////////////////////  p8-p9 arriba //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, 16.5f, 170.0f);
		glVertex3f( -122.0f, 16.5f, 170.0f);
        glVertex3f( -122.0f, 16.5f, 200.0f);
		glVertex3f( -120.0f, 16.5f, 200.0f);
	glEnd();
/////////////////////////////////  p8-p9 l.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, -5.0f, 170.0f);
		glVertex3f( -120.0f, 16.5f, 170.0f);
        glVertex3f( -122.0f, 16.5f, 170.0f);
		glVertex3f( -122.0f, -5.0f, 170.0f);
	glEnd();
/////////////////////////////////  p8-p9 l.2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, -5.0f, 200.0f);
		glVertex3f( -120.0f, 16.5f, 200.0f);
        glVertex3f( -122.0f, 16.5f, 200.0f);
		glVertex3f( -122.0f, -5.0f, 200.0f);
	glEnd();
	/////////////////////////////////  p7-p8 arriba //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, 16.5f, 50.0f);
		glVertex3f( -122.0f, 16.5f, 50.0f);
        glVertex3f( -122.0f, 16.5f, 80.0f);
		glVertex3f( -120.0f, 16.5f, 80.0f);
	glEnd();
/////////////////////////////////  p7-p8 l.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, -5.0f, 50.0f);
		glVertex3f( -120.0f, 16.5f, 50.0f);
        glVertex3f( -122.0f, 16.5f, 50.0f);
		glVertex3f( -122.0f, -5.0f, 50.0f);
	glEnd();
/////////////////////////////////  p7-p8 l.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, -5.0f, 80.0f);
		glVertex3f( -120.0f, 16.5f, 80.0f);
        glVertex3f( -122.0f, 16.5f, 80.0f);
		glVertex3f( -122.0f, -5.0f, 80.0f);
	glEnd();
/////////////////////////////////  muro baños arriba baño 1 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -60.0f, 8.5f, 229.0f);
    glVertex3f( -60.0f, 8.5f, 230.0f);
    glVertex3f( -53.0f, 8.5f, 230.0f);
    glVertex3f( -53.0f, 8.5f, 229.0f);
glEnd();
/////////////////////////////////  muro baños arriba baño 1 l.1//////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -60.0f, -5.0f, 230.0f);
    glVertex3f( -60.0f, 8.5f, 230.0f);
    glVertex3f( -60.0f, 8.5f, 229.0f);
    glVertex3f( -60.0f, -5.0f, 229.0f);
glEnd();
/////////////////////////////////  muro baños arriba baño 1 l.2//////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -53.0f, -5.0f, 230.0f);
    glVertex3f( -53.0f, 8.5f, 230.0f);
    glVertex3f( -53.0f, 8.5f, 229.0f);
    glVertex3f( -53.0f, -5.0f, 229.0f);
glEnd();
/////////////////////////////////  muro baños arriba baño 2 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -43.0f, 8.5f, 229.0f);
    glVertex3f( -43.0f, 8.5f, 230.0f);
    glVertex3f( -50.0f, 8.5f, 230.0f);
    glVertex3f( -50.0f, 8.5f, 229.0f);
glEnd();
/////////////////////////////////  muro baños arriba baño 2 l.1//////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -43.0f, -5.0f, 230.0f);
    glVertex3f( -43.0f, 8.5f, 230.0f);
    glVertex3f( -43.0f, 8.5f, 229.0f);
    glVertex3f( -43.0f, -5.0f, 229.0f);
glEnd();
/////////////////////////////////  muro baños arriba baño 2 l.2//////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -50.0f, -5.0f, 230.0f);
    glVertex3f( -50.0f, 8.5f, 230.0f);
    glVertex3f( -50.0f, 8.5f, 229.0f);
    glVertex3f( -50.0f, -5.0f, 229.0f);
glEnd();
/////////////////////////////  e.sa muro 5.1.2 muro puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 10.0f, 300.0f);
		glVertex3f( -20.0f, 18.5f, 300.0f);
		glVertex3f( -21.0f, 18.5f, 300.0f);
		glVertex3f( -21.0f, 10.0f, 300.0f);
	glEnd();
/////////////////////////////  e.sa muro 5.1.3 muro puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 10.0f, 294.0f);
		glVertex3f( -20.0f, 18.5f, 294.0f);
		glVertex3f( -21.0f, 18.5f, 294.0f);
		glVertex3f( -21.0f, 10.0f, 294.0f);
	glEnd();
/////////////////////////////  e.sa muro 5.1.4 muro puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 18.5f, 300.0f);
		glVertex3f( -21.0f, 18.5f, 300.0f);
		glVertex3f( -21.0f, 18.5f, 294.0f);
		glVertex3f( -20.0f, 18.5f, 294.0f);
	glEnd();
/////////////////////////////  e.sa muro 4.3.2 muro sobre la puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -18.0f, 18.5f, 302.0f);
		glVertex3f( -18.0f, 10.0f, 302.0f);
		glVertex3f( -18.0f, 10.0f, 303.0f);
		glVertex3f( -18.0f, 18.5f, 303.0f);
	glEnd();
/////////////////////////////  e.sa muro 4.3.3 muro sobre la puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -12.0f, 18.5f, 302.0f);
		glVertex3f( -12.0f, 10.0f, 302.0f);
		glVertex3f( -12.0f, 10.0f, 303.0f);
		glVertex3f( -12.0f, 18.5f, 303.0f);
	glEnd();
/////////////////////////////  e.sa muro 4.3.4 muro sobre la puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -12.0f, 18.5f, 302.0f);
		glVertex3f( -12.0f, 18.5f, 303.0f);
		glVertex3f( -18.0f, 18.5f, 303.0f);
		glVertex3f( -18.0f, 18.5f, 302.0f);
	glEnd();


}

void muros(){
/////////////////////////////////  p1 interior//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 5.0f, 0.0f, -20.0f);
		glVertex3f( 5.0f, 21.0f, -20.0f);
        glVertex3f( -1.0f, 21.0f, -20.0f);
		glVertex3f( -1.0f, 0.0f, -20.0f);
	glEnd();
/////////////////////////////////  p1 exterior//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 5.0f, -5.0f, -22.0f);
		glVertex3f( 5.0f, 21.0f, -22.0f);
        glVertex3f( -1.0f, 21.0f, -22.0f);
		glVertex3f( -1.0f, -5.0f, -22.0f);
	glEnd();
/////////////////////////////////  p2 interior //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 0.0f, -20.0f);
		glVertex3f( -20.0f, 21.0f, -20.0f);
        glVertex3f( -80.0f, 21.0f, -20.0f);
		glVertex3f( -80.0f, 0.0f, -20.0f);
	glEnd();
/////////////////////////////////  p2 exterior //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, -5.0f, -22.0f);
		glVertex3f( -20.0f, 21.0f, -22.0f);
        glVertex3f( -80.0f, 21.0f, -22.0f);
		glVertex3f( -80.0f, -5.0f, -22.0f);
	glEnd();
/////////////////////////////////  p1-p2 interior //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -1.0f, 16.0f, -20.0f);
		glVertex3f( -1.0f, 21.0f, -20.0f);
        glVertex3f( -20.0f, 21.0f, -20.0f);
		glVertex3f( -20.0f, 16.0f, -20.0f);
	glEnd();
/////////////////////////////////  p1-p2 exterior //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -1.0f, 16.0f, -22.0f);
		glVertex3f( -1.0f, 21.0f, -22.0f);
        glVertex3f( -20.0f, 21.0f, -22.0f);
		glVertex3f( -20.0f, 16.0f, -22.0f);
	glEnd();
/////////////////////////////////  p1-p2 exterior bajo //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -1.0f, -5.0f, -22.0f);
		glVertex3f( -1.0f, 0.0f, -22.0f);
        glVertex3f( -20.0f, 0.0f, -22.0f);
		glVertex3f( -20.0f, -5.0f, -22.0f);
	glEnd();

//////////////////////////////////  p3//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -80.0f, -5.0f, 40.0f);
		glVertex3f( -80.0f, 21.0f, 40.0f);
        glVertex3f( -122.0f, 21.0f, 40.0f);
		glVertex3f( -122.0f, -5.0f, 40.0f);
	glEnd();

//////////////////////////////////  p4//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -80.0f, -5.0f, -22.0f);
		glVertex3f( -80.0f, 21.0f, -22.0f);
        glVertex3f( -80.0f, 21.0f, 40.0f);
		glVertex3f( -80.0f, -5.0f, 40.0f);
	glEnd();

/////////////////////////////////  p5 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -80.0f, -5.0f, 270.0f);
		glVertex3f( -80.0f, 21.0f, 270.0f);
        glVertex3f( -70.0f, 21.0f, 270.0f);
		glVertex3f( -70.0f, -5.0f, 270.0f);
	glEnd();
/////////////////////////////////  p5 externo //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -80.0f, -5.0f, 272.0f);
		glVertex3f( -80.0f, 21.0f, 272.0f);
        glVertex3f( -70.0f, 21.0f, 272.0f);
		glVertex3f( -70.0f, -5.0f, 272.0f);
	glEnd();
/////////////////////////////////  p6 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 5.0f, -5.0f, -20.0f);
		glVertex3f( 5.0f, 40.0f, -20.0f);
        glVertex3f( 5.0f, 40.0f, 110.0f);
		glVertex3f( 5.0f, -5.0f, 110.0f);
	glEnd();
/////////////////////////////////  p7.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, -5.0f, 40.0f);
		glVertex3f( -120.0f, 21.0f, 40.0f);
        glVertex3f( -120.0f, 21.0f, 50.0f);
		glVertex3f( -120.0f, -5.0f, 50.0f);
	glEnd();
/////////////////////////////////  p7.2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -122.0f, -5.0f, 40.0f);
		glVertex3f( -122.0f, 21.0f, 40.0f);
        glVertex3f( -122.0f, 21.0f, 50.0f);
		glVertex3f( -122.0f, -5.0f, 50.0f);
	glEnd();
/////////////////////////////////  p7-p8.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, 16.5f, 50.0f);
		glVertex3f( -120.0f, 21.0f, 50.0f);
        glVertex3f( -120.0f, 21.0f, 80.0f);
		glVertex3f( -120.0f, 16.5f, 80.0f);
	glEnd();
/////////////////////////////////  p7-p8.2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -122.0f, 16.5f, 50.0f);
		glVertex3f( -122.0f, 21.0f, 50.0f);
        glVertex3f( -122.0f, 21.0f, 80.0f);
		glVertex3f( -122.0f, 16.5f, 80.0f);
	glEnd();
/////////////////////////////////  p8.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, -5.0f, 80.0f);
		glVertex3f( -120.0f, 21.0f, 80.0f);
        glVertex3f( -120.0f, 21.0f, 170.0f);
		glVertex3f( -120.0f, -5.0f, 170.0f);
	glEnd();
/////////////////////////////////  p8.2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -122.0f, -5.0f, 80.0f);
		glVertex3f( -122.0f, 21.0f, 80.0f);
        glVertex3f( -122.0f, 21.0f, 170.0f);
		glVertex3f( -122.0f, -5.0f, 170.0f);
	glEnd();
/////////////////////////////////  p8-p9.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, 16.5f, 170.0f);
		glVertex3f( -120.0f, 21.0f, 170.0f);
        glVertex3f( -120.0f, 21.0f, 200.0f);
		glVertex3f( -120.0f, 16.5f, 200.0f);
	glEnd();
/////////////////////////////////  p8-p9.2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -122.0f, 16.5f, 170.0f);
		glVertex3f( -122.0f, 21.0f, 170.0f);
        glVertex3f( -122.0f, 21.0f, 200.0f);
		glVertex3f( -122.0f, 16.5f, 200.0f);
	glEnd();
/////////////////////////////////  p9.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, -5.0f, 200.0f);
		glVertex3f( -120.0f, 21.0f, 200.0f);
        glVertex3f( -120.0f, 21.0f, 270.0f);
		glVertex3f( -120.0f, -5.0f, 270.0f);
	glEnd();
/////////////////////////////////  p9.2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -122.0f, -5.0f, 200.0f);
		glVertex3f( -122.0f, 21.0f, 200.0f);
        glVertex3f( -122.0f, 21.0f, 272.0f);
		glVertex3f( -122.0f, -5.0f, 272.0f);
	glEnd();
/////////////////////////////////  p10 interno//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -120.0f, -5.0f, 270.0f);
		glVertex3f( -120.0f, 21.0f, 270.0f);
        glVertex3f( -110.0f, 21.0f, 270.0f);
		glVertex3f( -110.0f, -5.0f, 270.0f);
	glEnd();
/////////////////////////////////  p10 esxterno //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -122.0f, -5.0f, 272.0f);
		glVertex3f( -122.0f, 21.0f, 272.0f);
        glVertex3f( -110.0f, 21.0f, 272.0f);
		glVertex3f( -110.0f, -5.0f, 272.0f);
	glEnd();
/////////////////////////////////  p5-p10 interno//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -80.0f, 16.0f, 270.0f);
		glVertex3f( -80.0f, 21.0f, 270.0f);
        glVertex3f( -110.0f, 21.0f, 270.0f);
		glVertex3f( -110.0f, 16.0f, 270.0f);
	glEnd();
/////////////////////////////////  p5-p10 externo //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -80.0f, 16.0f, 272.0f);
		glVertex3f( -80.0f, 21.0f, 272.0f);
        glVertex3f( -110.0f, 21.0f, 272.0f);
		glVertex3f( -110.0f, 16.0f, 272.0f);
	glEnd();

}

void maquinaBrown(){
/////////////////////////////////  maquina adelante 1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.0f, -4.0f, 75.0f);
		glVertex3f( -35.0f, 0.0f, 75.0f);
        glVertex3f( -45.0f, 0.0f, 75.0f);
		glVertex3f( -45.0f, -4.0f, 75.0f);
	glEnd();
/////////////////////////////////  maquina adelante 1.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -43.0f, 0.0f, 75.0f);
		glVertex3f( -43.0f, 7.5f, 75.0f);
        glVertex3f( -45.0f, 7.5f, 75.0f);
		glVertex3f( -45.0f, 0.0f, 75.0f);
	glEnd();
/////////////////////////////////  maquina adelante 2  //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.0f, 8.5f, 75.0f);
		glVertex3f( -35.0f, 7.5f, 75.0f);
        glVertex3f( -45.0f, 7.5f, 75.0f);
		glVertex3f( -45.0f, 8.5f, 75.0f);
	glEnd();
/////////////////////////////////  maquina adelante 2.1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.0f, 0.0f, 75.0f);
		glVertex3f( -35.0f, 7.5f, 75.0f);
        glVertex3f( -35.5f, 7.5f, 75.0f);
		glVertex3f( -35.5f, 0.0f, 75.0f);
	glEnd();

/////////////////////////////////  maquina estantes 1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.5f, 6.0f, 76.0f);
		glVertex3f( -35.5f, 6.0f, 79.0f);
        glVertex3f( -43.0f, 6.0f, 79.0f);
		glVertex3f( -43.0f, 6.0f, 76.0f);
	glEnd();
/////////////////////////////////  maquina estantes 2//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.5f, 5.0f, 76.0f);
		glVertex3f( -35.5f, 5.0f, 79.0f);
        glVertex3f( -43.0f, 5.0f, 79.0f);
		glVertex3f( -43.0f, 5.0f, 76.0f);
	glEnd();
/////////////////////////////////  maquina estantes 3//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.5f, 4.0f, 76.0f);
		glVertex3f( -35.5f, 4.0f, 79.0f);
        glVertex3f( -43.0f, 4.0f, 79.0f);
		glVertex3f( -43.0f, 4.0f, 76.0f);
	glEnd();

/////////////////////////////////  maquina estantes 4//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.5f, 3.0f, 76.0f);
		glVertex3f( -35.5f, 3.0f, 79.0f);
        glVertex3f( -43.0f, 3.0f, 79.0f);
		glVertex3f( -43.0f, 3.0f, 76.0f);
	glEnd();
/////////////////////////////////  maquina estantes 5//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.5f, 2.0f, 76.0f);
		glVertex3f( -35.5f, 2.0f, 79.0f);
        glVertex3f( -43.0f, 2.0f, 79.0f);
		glVertex3f( -43.0f, 2.0f, 76.0f);
	glEnd();
/////////////////////////////////  maquina estantes 6//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.5f, 1.0f, 76.0f);
		glVertex3f( -35.5f, 1.0f, 79.0f);
        glVertex3f( -43.0f, 1.0f, 79.0f);
		glVertex3f( -43.0f, 1.0f, 76.0f);
	glEnd();
/////////////////////////////////  maquina estantes 7//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.5f, 0.0f, 76.0f);
		glVertex3f( -35.5f, 0.0f, 79.0f);
        glVertex3f( -43.0f, 0.0f, 79.0f);
		glVertex3f( -43.0f, 0.0f, 76.0f);
	glEnd();

}

void maquinaBlack(){
/////////////////////////////////  maquina lado 1  //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.0f, -4.0f, 79.0f);
		glVertex3f( -35.0f, 8.5f, 79.0f);
        glVertex3f( -35.0f, 8.5f, 75.0f);
		glVertex3f( -35.0f, -4.0f, 75.0f);
	glEnd();
/////////////////////////////////  maquina lado 1.1  //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.5f, -4.0f, 79.0f);
		glVertex3f( -35.5f, 8.5f, 79.0f);
        glVertex3f( -35.5f, 8.5f, 75.0f);
		glVertex3f( -35.5f, -4.0f, 75.0f);
	glEnd();
/////////////////////////////////  maquina lado 2  //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -45.0f, -4.0f, 79.0f);
		glVertex3f( -45.0f, 8.5f, 79.0f);
        glVertex3f( -45.0f, 8.5f, 75.0f);
		glVertex3f( -45.0f, -4.0f, 75.0f);
	glEnd();
/////////////////////////////////  maquina lado 2.1  //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -43.0f, -4.0f, 79.0f);
		glVertex3f( -43.0f, 8.5f, 79.0f);
        glVertex3f( -43.0f, 8.5f, 75.0f);
		glVertex3f( -43.0f, -4.0f, 75.0f);
	glEnd();
/////////////////////////////////  maquina piso  //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.0f, -4.0f, 75.0f);
		glVertex3f( -35.0f, -4.0f, 79.0f);
        glVertex3f( -45.0f, -4.0f, 79.0f);
		glVertex3f( -45.0f, -4.0f, 75.0f);
	glEnd();
/////////////////////////////////  maquina techo  1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.0f, 8.5f, 75.0f);
		glVertex3f( -35.0f, 8.5f, 79.0f);
        glVertex3f( -45.0f, 8.5f, 79.0f);
		glVertex3f( -45.0f, 8.5f, 75.0f);
	glEnd();
/////////////////////////////////  maquina techo  2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -35.0f, 7.5f, 75.0f);
		glVertex3f( -35.0f, 7.5f, 79.0f);
        glVertex3f( -45.0f, 7.5f, 79.0f);
		glVertex3f( -45.0f, 7.5f, 75.0f);
	glEnd();
}

void patio(){
/////////////////////////////////  muro patio 1 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 5.0f, -5.0f, 110.0f);
		glVertex3f( 5.0f, 15.0f, 110.0f);
        glVertex3f( -70.0f, 15.0f, 110.0f);
		glVertex3f( -70.0f, -5.0f, 110.0f);
	glEnd();
/////////////////////////////////  muro patio 2 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, -5.0f, 180.0f);
		glVertex3f( 10.0f, 45.0f, 180.0f);
        glVertex3f( -73.5f, 45.0f, 180.0f);
		glVertex3f( -73.5f, -5.0f, 180.0f);
	glEnd();
/////////////////////////////////  muro patio 3 //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 5.0f, -5.0f, 110.0f);
		glVertex3f( 5.0f, 45.0f, 110.0f);
        glVertex3f( 10.0f, 45.0f, 180.0f);
		glVertex3f( 10.0f, -5.0f, 180.0f);
	glEnd();
}

void patio2(){
/////////////////////////////////  murito patio exterior //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -66.0f, -5.0f, 110.0f);
		glVertex3f( -66.0f, 1.0f, 110.0f);
        glVertex3f( -66.0f, 1.0f, 114.0f);
		glVertex3f( -66.0f, -5.0f, 114.0f);
	glEnd();
/////////////////////////////////  murito patio  interior//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -64.0f, -5.0f, 110.0f);
		glVertex3f( -64.0f, 1.0f, 110.0f);
        glVertex3f( -64.0f, 1.0f, 112.0f);
		glVertex3f( -64.0f, -5.0f, 112.0f);
	glEnd();
/////////////////////////////////  murito patio 1 exterior//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 1.0f, -5.0f, 114.0f);
		glVertex3f( 1.0f, 1.0f, 114.0f);
        glVertex3f( -66.0f, 1.0f, 114.0f);
		glVertex3f( -66.0f, -5.0f, 114.0f);
	glEnd();
/////////////////////////////////  murito patio 1 interior //////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 3.0f, -5.0f, 112.0f);
		glVertex3f( 3.0f, 1.0f, 112.0f);
        glVertex3f( -64.0f, 1.0f, 112.0f);
		glVertex3f( -64.0f, -5.0f, 112.0f);
	glEnd();
/////////////////////////////////  murito patio 2 exterior//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 1.0f, -5.0f, 114.0f);
		glVertex3f( 1.0f, 1.0f, 114.0f);
        glVertex3f( 6.0f, 1.0f, 180.0f);
		glVertex3f( 6.0f, -5.0f, 180.0f);
	glEnd();
/////////////////////////////////  murito patio 2 interior//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 3.0f, -5.0f, 112.0f);
		glVertex3f( 3.0f, 1.0f, 112.0f);
        glVertex3f( 8.0f, 1.0f, 180.0f);
		glVertex3f( 8.0f, -5.0f, 180.0f);
	glEnd();

////////////////////////// L ///////////////////////////////////
/////////////////////////////////  L lat 1.1//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -55.0f, -5.0f, 165.0f);
		glVertex3f( -55.0f,  1.0f, 165.0f);
        glVertex3f( -55.0f,  1.0f, 125.0f);
		glVertex3f( -55.0f, -5.0f, 125.0f);
	glEnd();
/////////////////////////////////  L lat 1.2//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -53.0f, -5.0f, 163.0f);
		glVertex3f( -53.0f,  1.0f, 163.0f);
        glVertex3f( -53.0f,  1.0f, 127.0f);
		glVertex3f( -53.0f, -5.0f, 127.0f);
	glEnd();

/////////////////////////////////  L lat 2.1//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -55.0f, -5.0f, 165.0f);
		glVertex3f( -55.0f,  1.0f, 165.0f);
        glVertex3f( -5.0f,  1.0f, 165.0f);
		glVertex3f( -5.0f, -5.0f, 165.0f);
	glEnd();
/////////////////////////////////  L lat 2.2//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -53.0f, -5.0f, 163.0f);
		glVertex3f( -53.0f,  1.0f, 163.0f);
        glVertex3f(  -7.0f,  1.0f, 163.0f);
		glVertex3f(  -7.0f, -5.0f, 163.0f);
	glEnd();
/////////////////////////////////  L lat 3.1//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, -5.0f, 165.0f);
		glVertex3f( -5.0f,  1.0f, 165.0f);
        glVertex3f( -5.0f,  1.0f, 140.0f);
		glVertex3f( -5.0f, -5.0f, 140.0f);
	glEnd();
/////////////////////////////////  L lat 3.2//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -7.0f, -5.0f, 163.0f);
		glVertex3f( -7.0f,  1.0f, 163.0f);
        glVertex3f( -7.0f,  1.0f, 142.0f);
		glVertex3f( -7.0f,  -5.0f, 142.0f);
	glEnd();
/////////////////////////////////  L lat 4.1//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, -5.0f,  140.0f);
		glVertex3f( -5.0f,  1.0f,  140.0f);
        glVertex3f( -30.0f, 1.0f,  140.0f);
		glVertex3f( -30.0f, -5.0f, 140.0f);
	glEnd();
/////////////////////////////////  L lat 4.2//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -7.0f, -5.0f, 142.0f);
		glVertex3f( -7.0f,  1.0f, 142.0f);
        glVertex3f( -32.0f,  1.0f, 142.0f);
		glVertex3f( -32.0f,  -5.0f, 142.0f);
	glEnd();
/////////////////////////////////  L lat 5.1//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -30.0f, -5.0f, 140.0f);
		glVertex3f( -30.0f, 1.0f,  140.0f);
        glVertex3f( -30.0f, 1.0f,  125.0f);
		glVertex3f( -30.0f, -5.0f, 125.0f);
	glEnd();
/////////////////////////////////  L lat 5.2//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -32.0f, -5.0f, 142.0f);
		glVertex3f( -32.0f,  1.0f, 142.0f);
        glVertex3f( -32.0f, 1.0f, 127.0f);
		glVertex3f( -32.0f, -5.0f, 127.0f);
	glEnd();
/////////////////////////////////  L lat 6.1//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -30.0f, -5.0f, 125.0f);
		glVertex3f( -30.0f, 1.0f,  125.0f);
        glVertex3f( -55.0f, 1.0f,  125.0f);
		glVertex3f( -55.0f, -5.0f, 125.0f);
	glEnd();
/////////////////////////////////  L lat 6.2//////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -32.0f, -5.0f, 127.0f);
		glVertex3f( -32.0f,  1.0f, 127.0f);
        glVertex3f( -53.0f,  1.0f, 127.0f);
		glVertex3f( -53.0f, -5.0f, 127.0f);
	glEnd();
}

void muros2(){
/////////////////////////////////  columna 1 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -73.5f, -5.0f, 180.0f);
    glVertex3f( -73.5f, 21.0f, 180.0f);
    glVertex3f( -73.5f, 21.0f, 184.0f);
    glVertex3f( -73.5f, -5.0f, 184.0f);
glEnd();
/////////////////////////////////  pasillo 1//////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -70.0f, -5.0f, 180.0f);
    glVertex3f( -70.0f, 21.0f, 180.0f);
    glVertex3f( -70.0f, 21.0f, 230.0f);
    glVertex3f( -70.0f, -5.0f, 230.0f);
glEnd();
/////////////////////////////////  pasillo baño//////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -70.0f, -5.0f, 230.0f);
    glVertex3f( -70.0f, 21.0f, 230.0f);
    glVertex3f( -60.0f, 21.0f, 230.0f);
    glVertex3f( -60.0f, -5.0f, 230.0f);
glEnd();
/////////////////////////////////  pasillo salida.1 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -70.0f, -5.0f, 255.0f);
    glVertex3f( -70.0f, 21.0f, 255.0f);
    glVertex3f( -70.0f, 21.0f, 280.0f);
    glVertex3f( -70.0f, -5.0f, 280.0f);
glEnd();
/////////////////////////////////  pasillo salida.2 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -68.0f, -5.0f, 255.0f);
    glVertex3f( -68.0f, 21.0f, 255.0f);
    glVertex3f( -68.0f, 21.0f, 280.0f);
    glVertex3f( -68.0f, -5.0f, 280.0f);
glEnd();
/////////////////////////////////  pasillo salida frente //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -68.0f, -5.0f, 255.0f);
    glVertex3f( -68.0f, 21.0f, 255.0f);
    glVertex3f( -70.0f, 21.0f, 255.0f);
    glVertex3f( -70.0f, -5.0f, 255.0f);
glEnd();
/////////////////////////////////  muro fondo //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -70.0f, -5.0f, 280.0f);
    glVertex3f( -70.0f, 21.0f, 280.0f);
    glVertex3f( -20.0f, 21.0f, 280.0f);
    glVertex3f( -20.0f, -5.0f, 280.0f);
glEnd();
/////////////////////////////////  muro baños arriba //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -60.0f, 8.5f, 230.0f);
    glVertex3f( -60.0f, 21.0f, 230.0f);
    glVertex3f( -20.0f, 21.0f, 230.0f);
    glVertex3f( -20.0f, 8.5f, 230.0f);
glEnd();
/////////////////////////////////  muro baños en b1 y b2 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -53.0f, -5.0f, 230.0f);
    glVertex3f( -53.0f, 8.5f, 230.0f);
    glVertex3f( -50.0f, 8.5f, 230.0f);
    glVertex3f( -50.0f, -5.0f, 230.0f);
glEnd();
/////////////////////////////////  muro baños  //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -43.0f, -5.0f, 230.0f);
    glVertex3f( -43.0f, 8.5f, 230.0f);
    glVertex3f( -20.0f, 8.5f, 230.0f);
    glVertex3f( -20.0f, -5.0f, 230.0f);
glEnd();
/////////////////////////////////  muro baños-escaleras   //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -20.0f, -5.0f, 230.0f);
    glVertex3f( -20.0f, 0.0f, 230.0f);
    glVertex3f( -20.0f, 0.0f, 245.0f);
    glVertex3f( -20.0f, -5.0f, 245.0f);
glEnd();
/////////////////////////////////  muro fondo puerta teatro.1 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( 10.0f, -5.0f, 180.0f);
    glVertex3f( 10.0f, 21.0f, 180.0f);
    glVertex3f( 10.0f, 21.0f, 190.0f);
    glVertex3f( 10.0f, -5.0f, 190.0f);
glEnd();
/////////////////////////////////  muro fondo puerta teatro.2 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( 10.0f, 0.0f, 215.0f);
    glVertex3f( 10.0f, 21.0f, 215.0f);
    glVertex3f( 10.0f, 21.0f, 270.0f);
    glVertex3f( 10.0f, 0.0f, 270.0f);
glEnd();
/////////////////////////////  muro  sotano 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 8.0f, 270.0f);
		glVertex3f( -5.0f, -20.0f, 270.0f);
		glVertex3f( 10.0f, -20.0f, 270.0f);
		glVertex3f( 10.0f, 8.0f, 270.0f);
	glEnd();
/////////////////////////////////  muro fondo puerta teatro arriba//////////////////////////////
glBegin(GL_QUADS);
		glVertex3f( 10.0f, 16.5f, 190.0f);
		glVertex3f( 10.0f, 21.0f,  190.0f);
        glVertex3f( 10.0f, 21.0f, 215.0f);
        glVertex3f( 10.0f, 16.5f, 215.0f);
glEnd();
/////////////////////////////////  muro fondo esquina.1 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -20.0f, -5.0f, 230.0f);
    glVertex3f( -20.0f, 21.0f, 230.0f);
    glVertex3f( -5.0f, 21.0f, 230.0f);
    glVertex3f( -5.0f, -5.0f, 230.0f);
glEnd();
/////////////////////////////////  muro fondo esquina.2 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -20.0f, -5.0f, 200.0f);
    glVertex3f( -20.0f, 21.0f, 200.0f);
    glVertex3f( -5.0f, 21.0f, 200.0f);
    glVertex3f( -5.0f, -5.0f, 200.0f);
glEnd();
/////////////////////////////////  muro fondo esquina.3 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -20.0f, -5.0f, 180.0f);
    glVertex3f( -20.0f, 21.0f, 180.0f);
    glVertex3f( -20.0f, 21.0f, 200.0f);
    glVertex3f( -20.0f, -5.0f, 200.0f);
glEnd();
/////////////////////////////////  muro fondo esquina.4 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -5.0f, -5.0f, 230.0f);
    glVertex3f( -5.0f, 21.0f, 230.0f);
    glVertex3f( -5.0f, 21.0f, 200.0f);
    glVertex3f( -5.0f, -5.0f, 200.0f);
glEnd();
/////////////////////////////  e.sa muro 1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 0.0f, 280.0f);
		glVertex3f( -20.0f, 21.0f, 280.0f);
		glVertex3f( -20.0f, 21.0f, 292.0f);
		glVertex3f( -20.0f, 0.0f, 292.0f);
	glEnd();
/////////////////////////////  e.sa muro 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -10.0f, 0.0f, 280.0f);
		glVertex3f( -10.0f, 21.0f, 280.0f);
		glVertex3f( -10.0f, 21.0f, 292.0f);
		glVertex3f( -10.0f, 0.0f, 292.0f);
	glEnd();
/////////////////////////////  e.sa muro 3/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -10.0f, 10.0f, 292.0f);
		glVertex3f( -10.0f, 21.0f, 292.0f);
		glVertex3f( 10.0f, 21.0f, 292.0f);
		glVertex3f( 10.0f, 10.0f, 292.0f);
	glEnd();
/////////////////////////////  e.sa muro 4.1 muro puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -12.0f, 10.0f, 302.0f);
		glVertex3f( -12.0f, 21.0f, 302.0f);
		glVertex3f( -10.0f, 21.0f, 302.0f);
		glVertex3f( -10.0f, 10.0f, 302.0f);
	glEnd();
/////////////////////////////  e.sa muro 4.2 muro puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 10.0f, 302.0f);
		glVertex3f( -20.0f, 21.0f, 302.0f);
		glVertex3f( -18.0f, 21.0f, 302.0f);
		glVertex3f( -18.0f, 10.0f, 302.0f);
	glEnd();
/////////////////////////////  e.sa muro 4.3 muro sobre la puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -12.0f, 18.5f, 302.0f);
		glVertex3f( -12.0f, 21.0f, 302.0f);
		glVertex3f( -18.0f, 21.0f, 302.0f);
		glVertex3f( -18.0f, 18.5f, 302.0f);
	glEnd();





/////////////////////////////  e.sa muro 5.1 muro puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 10.0f, 302.0f);
		glVertex3f( -20.0f, 21.0f, 302.0f);
		glVertex3f( -20.0f, 21.0f, 300.0f);
		glVertex3f( -20.0f, 10.0f, 300.0f);
	glEnd();
/////////////////////////////  e.sa muro 5.2 muro puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 10.0f, 294.0f);
		glVertex3f( -20.0f, 21.0f, 294.0f);
		glVertex3f( -20.0f, 21.0f, 292.0f);
		glVertex3f( -20.0f, 10.0f, 292.0f);
	glEnd();
/////////////////////////////  e.sa muro 5.3 muro sobre la puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -20.0f, 18.5f, 300.0f);
		glVertex3f( -20.0f, 21.0f, 300.0f);
		glVertex3f( -20.0f, 21.0f, 294.0f);
		glVertex3f( -20.0f, 18.5f, 294.0f);
	glEnd();
/////////////////////////////  e.sa esquina muro/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -10.0f, -20.0f, 280.0f);
		glVertex3f( -10.0f, 21.0f, 280.0f);
		glVertex3f( -3.0f, 21.0f, 280.0f);
		glVertex3f( -3.0f, -20.0f, 280.0f);
	glEnd();
/////////////////////////////  e.sot muro/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -10.0f, -20.0f, 280.0f);
		glVertex3f( -10.0f, 10.0f, 280.0f);
		glVertex3f( 12.0f,  10.0f, 280.0f);
		glVertex3f( 12.0f, -20.0f, 280.0f);
	glEnd();
/////////////////////////////  e.sa esquina muro 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 12.0f, -20.0f, 280.0f);
		glVertex3f( 12.0f, 21.0f, 280.0f);
		glVertex3f( 7.0f, 21.0f, 280.0f);
		glVertex3f( 7.0f, -20.0f, 280.0f);
	glEnd();
/////////////////////////////  e.s muro al frente de esc sot/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 10.0f, 280.0f);
		glVertex3f( 10.0f, 0.0f, 280.0f);
		glVertex3f( 10.0f, 0.0f, 270.0f);
		glVertex3f( 10.0f, 10.0f, 270.0f);
	glEnd();
/////////////////////////////  e.as muro puerta 2.1 /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 10.0f, 272.0f);
		glVertex3f( 10.0f, 18.5f, 272.0f);
		glVertex3f( 11.0f, 18.5f, 272.0f);
		glVertex3f( 11.0f, 10.0f, 272.0f);
	glEnd();
/////////////////////////////  e.as muro puerta 2.2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 10.0f, 278.0f);
		glVertex3f( 10.0f, 18.5f, 278.0f);
		glVertex3f( 11.0f, 18.5f, 278.0f);
		glVertex3f( 11.0f, 10.0f, 278.0f);
	glEnd();
/////////////////////////////  e.as muro puerta 2.3 muro arriba de la puerta/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 21.0f, 278.0f);
		glVertex3f( 10.0f, 18.5f, 278.0f);
		glVertex3f( 10.0f, 18.5f, 272.0f);
		glVertex3f( 10.0f, 21.0f, 272.0f);
	glEnd();
/////////////////////////////  e.as muro puerta 2.4 muro arriba de la puerta/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 18.5f, 278.0f);
		glVertex3f( 11.0f, 18.5f, 278.0f);
		glVertex3f( 11.0f, 18.5f, 272.0f);
		glVertex3f( 10.0f, 18.5f, 272.0f);
	glEnd();
/////////////////////////////  e.as muro puerta 2.5 /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 10.0f, 270.0f);
		glVertex3f( 10.0f, 21.0f, 270.0f);
		glVertex3f( 10.0f, 21.0f, 272.0f);
		glVertex3f( 10.0f, 10.0f, 272.0f);
	glEnd();
/////////////////////////////  e.as muro puerta 2.6 /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 10.0f, 278.0f);
		glVertex3f( 10.0f, 21.0f, 278.0f);
		glVertex3f( 10.0f, 21.0f, 292.0f);
		glVertex3f( 10.0f, 10.0f, 292.0f);
	glEnd();
/////////////////////////////  e.as muro puerta l.1/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 1.0f, 10.0f, 280.0f);
		glVertex3f( 1.0f, 18.5f, 280.0f);
		glVertex3f( 1.0f, 18.5f, 281.0f);
		glVertex3f( 1.0f, 10.0f, 281.0f);
	glEnd();
/////////////////////////////  e.as muro puerta l.2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 7.0f, 10.0f, 280.0f);
		glVertex3f( 7.0f, 18.5f, 280.0f);
		glVertex3f( 7.0f, 18.5f, 281.0f);
		glVertex3f( 7.0f, 10.0f, 281.0f);
	glEnd();
/////////////////////////////  e.as muro puerta l.3.1 sobre la puerta/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 1.0f, 21.0f, 280.0f);
		glVertex3f( 1.0f, 18.5f, 280.0f);
		glVertex3f( 7.0f, 18.5f, 280.0f);
		glVertex3f( 7.0f, 21.0f, 280.0f);
	glEnd();
/////////////////////////////  e.as muro puerta l.3.2 sobre la puerta/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 1.0f, 21.0f, 281.0f);
		glVertex3f( 1.0f, 18.5f, 281.0f);
		glVertex3f( 7.0f, 18.5f, 281.0f);
		glVertex3f( 7.0f, 21.0f, 281.0f);
	glEnd();
/////////////////////////////  e.as muro puerta l.4 sobre la puerta/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 1.0f, 18.5f, 280.0f);
		glVertex3f( 1.0f, 18.5f, 281.0f);
		glVertex3f( 7.0f, 18.5f, 281.0f);
		glVertex3f( 7.0f, 18.5f, 280.0f);
	glEnd();
///////////pedasito muro al lado de la puesta sobre las escaleras sobre el sotano.1////////
glBegin(GL_QUADS);
    glVertex3f( 1.0f, 10.0f, 280.0f);
    glVertex3f( 1.0f, 21.0f, 280.0f);
    glVertex3f( -3.0f, 21.0f, 280.0f);
    glVertex3f( -3.0f, 10.0f, 280.0f);
glEnd();
///////////pedasito muro al lado de la puesta sobre las escaleras sobre el sotano.2////////
glBegin(GL_QUADS);
    glVertex3f( 1.0f, 10.0f, 281.0f);
    glVertex3f( 1.0f, 21.0f, 281.0f);
    glVertex3f( -5.0f, 21.0f, 281.0f);
    glVertex3f( -5.0f, 10.0f, 281.0f);
glEnd();
/////////////////////////////  e.as muro interno cuarto servicio/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 10.0f, 21.0f, 281.0f);
		glVertex3f( 10.0f, 10.0f, 281.0f);
		glVertex3f( 7.0f, 10.0f, 281.0f);
		glVertex3f( 7.0f, 21.0f, 281.0f);
	glEnd();
/////////////////////////////  e.as muro interno cuarto servicio/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -5.0f, 21.0f, 281.0f);
		glVertex3f( -5.0f, 10.0f, 281.0f);
		glVertex3f( -5.0f, 10.0f, 292.0f);
		glVertex3f( -5.0f, 21.0f, 292.0f);
	glEnd();
}

void puertas(){
/////////////////////////////  e.sa  piso puerta  /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -12.0f, 10.0f, 303.0f);
		glVertex3f( -12.0f, 18.5f, 303.0f);
		glVertex3f( -18.0f, 18.5f, 303.0f);
		glVertex3f( -18.0f, 10.0f, 303.0f);
	glEnd();
/////////////////////////////  e.sa  puerta /////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( -21.0f, 10.0f, 300.0f);
		glVertex3f( -21.0f, 18.5f, 300.0f);
		glVertex3f( -21.0f, 18.5f, 294.0f);
		glVertex3f( -21.0f, 10.0f, 294.0f);
	glEnd();
/////////////////////////////  e.as puerta 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 1.0f, 10.0f, 280.0f);
		glVertex3f( 1.0f, 18.5f, 280.0f);
		glVertex3f( -3.0f, 18.5f, 274.0f);
		glVertex3f( -3.0f, 10.0f, 274.0f);
	glEnd();
/////////////////////////////  e.as puerta 2/////////////////////////////
    glBegin(GL_QUADS);
		glVertex3f( 11.0f, 10.0f, 278.0f);
		glVertex3f( 11.0f, 18.5f, 278.0f);
		glVertex3f( 11.0f, 18.5f, 272.0f);
		glVertex3f( 11.0f, 10.0f, 272.0f);
	glEnd();
/////////////////////////////////  puesta cafe  //////////////////////////////
/////////////////////////////////  cafe puerta 1  //////////////////////////////
glBegin(GL_QUADS);
		glVertex3f( -20.0f, 8.5f, 81.0f);
		glVertex3f( -20.0f, -5.0f, 81.0f);
        glVertex3f( -27.0f, -5.0f, 83.0f);
        glVertex3f( -27.0f, 8.5f, 83.0f);
glEnd();
/////////////////////////////////  puerta oficinas 1  //////////////////////////////
glBegin(GL_QUADS);
		glVertex3f( -122.0f, 16.5f, 50.0f);
		glVertex3f( -122.0f, -5.0f, 50.0f);
        glVertex3f( -122.0f, -5.0f, 80.0f);
        glVertex3f( -122.0f, 16.5f, 80.0f);
glEnd();
/////////////////////////////////  puerta oficinas 2  //////////////////////////////
glBegin(GL_QUADS);
		glVertex3f( -122.0f, 16.5f, 170.0f);
		glVertex3f( -122.0f, -5.0f, 170.0f);
        glVertex3f( -122.0f, -5.0f, 200.0f);
        glVertex3f( -122.0f, 16.5f, 200.0f);
glEnd();
/////////////////////////////////  puerta entrada  //////////////////////////////
glBegin(GL_QUADS);
		glVertex3f( -1.0f, 16.5f, -22.0f);
		glVertex3f( -1.0f, 0.0f, -22.0f);
        glVertex3f( -20.0f, 0.0f, -22.0f);
        glVertex3f( -20.0f, 16.5f, -22.0f);
glEnd();
/////////////////////////////////  puerta salida  //////////////////////////////
glBegin(GL_QUADS);
		glVertex3f( -80.0f, 16.5f, 272.0f);
		glVertex3f( -80.0f, -5.0f,  272.0f);
        glVertex3f( -110.0f, -5.0f, 272.0f);
        glVertex3f( -110.0f, 16.5f, 272.0f);
glEnd();
/////////////////////////////////  puerta teatro //////////////////////////////
glBegin(GL_QUADS);
		glVertex3f( 10.0f, 16.5f, 190.0f);
		glVertex3f( 10.0f, 0.0f,  190.0f);
        glVertex3f( 10.0f, 0.0f, 215.0f);
        glVertex3f( 10.0f, 16.5f, 215.0f);
glEnd();
/////////////////////////////////  puerta baño 1 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -60.0f, 8.5f, 229.0f);
    glVertex3f( -60.0f, -5.0f, 229.0f);
    glVertex3f( -53.0f, -5.0f, 229.0f);
    glVertex3f( -53.0f, 8.5f, 229.0f);
glEnd();
/////////////////////////////////  puerta baño 2 //////////////////////////////
    glBegin(GL_QUADS);
    glVertex3f( -43.0f, 8.5f, 229.0f);
    glVertex3f( -43.0f, -5.0f, 229.0f);
    glVertex3f( -50.0f, -5.0f, 229.0f);
    glVertex3f( -50.0f, 8.5f, 229.0f);
glEnd();

}
