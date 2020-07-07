#include<windows.h>
#include<gl/glut.h>


void init(void);
void tampil(void);
void mouse(int button, int state, int a, int b);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int a, int b);

float arot=0.0f;
float brot=0.0f;
float adiff=0.0f;
float bdiff=0.0f;
bool mouseDown=false;
int is_depth;

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Agista Nindy Yuliarina-672018171");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
}

void rumah()
{
        //tembok rumah
        //depan
        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3f(0.75, 0.75, 0.75);
        glVertex3f(-46,-25,24);
        glVertex3f(-46,35,24);
        glVertex3f(46,35,24);
        glVertex3f(46,-25,24);
        glEnd();

            //belakang
        glBegin(GL_QUADS);
        glColor3f(0.75, 0.75, 0.75);
        glVertex3f(-46,-25,-24);
        glVertex3f(-46,36,-24);
        glVertex3f(46,36,-24);
        glVertex3f(46,-25,-24);
        glEnd();

        //kanan
        glBegin(GL_QUADS);
        glColor3f(3.0, 3.0, 3.0);
        glVertex3f(46,35,24);
        glVertex3f(46,-25,24);
        glVertex3f(46,-25,-24);
        glVertex3f(46,35,-24);
        glEnd();

        //kiri
        glBegin(GL_QUADS);
        glColor3f(3.0, 3.0, 3.0);
        glVertex3f(-46,35,24);
        glVertex3f(-46,-25,24);
        glVertex3f(-46,-25,-24);
        glVertex3f(-46,35,-24);
        glEnd();

        //bawah
        glBegin(GL_QUADS);
        glColor3f(4.0, 4.0, 4.0);
        glVertex3f(-46,-18,24);
        glVertex3f(46,-18,24);
        glVertex3f(46,-18,-24);
        glVertex3f(-46,-18,-24);
        glEnd();

        //garis 1
        glPushMatrix ();
        glColor3f (0.75 , 0.75, 0.75);
        glTranslatef (-4 , 8, 25);
        glScalef (-11, 0.8, 0.5);
        glutSolidCube(2);
        glPopMatrix ();

       //garis 2
        glPushMatrix ();
        glColor3f (0.90 , 0.90, 0.90);
        glTranslatef (25 , 8, 25);
        glScalef (6, 0.8, 0.5);
        glutSolidCube(2);
        glPopMatrix ();

       //garis 3
        glPushMatrix ();
        glColor3f (8.0 , 4.0, 4.0);
        glTranslatef (-24 , -10, 25);
        glScalef (19, 0.5, 0);
        glutSolidCube(2);
        glPopMatrix ();

       //garis4
        glPushMatrix ();
        glColor3f (8.0 , 4.0, 4.0);
        glTranslatef (24.5 , -10, 25);
        glScalef (18, 0.5, 0);
        glutSolidCube(2);
        glPopMatrix ();

        //tembok bawah 1
        glPushMatrix ();
        glColor3f(0.30,0.30,0.30);
        glTranslatef (-24 , -15, 26);
        glRotatef (90, 0, 1, 0);
        glScalef (2 ,9 , 38.5);
        glutSolidCube(1);
        glPopMatrix ();

        //tembok bawah 2
        glPushMatrix ();
        glColor3f(0.30,0.30,0.30);
        glTranslatef (25 , -15, 26);
        glRotatef (90, 0, 1, 0);
        glScalef (2 ,9 , 36);
        glutSolidCube(1);
        glPopMatrix ();

       //atap depan
        glPushMatrix ();
        glColor3f (4 , 4, 4);
        glTranslatef (0 , 20, 17);
        glScalef (-18, 0.8, 16);
        glutSolidCube(5);
        glPopMatrix ();
}

void atap()
{
    //atap rumah
        glPushMatrix ();
        glColor3f (8.0,4.0,5.0);
        glTranslatef (0 , 39, 0);
        glRotatef (50, 1, 0, 0);
        glScalef (19, 7, 6);
        glutSolidCube(5);
        glPopMatrix ();

        glPushMatrix ();
        glColor3f (1.0 , 1.0, 1.0);
        glTranslatef (0 , 40, 0);
        glRotatef (50, 1, 0, 0);
        glScalef (18, 7, 6);
        glutSolidCube(5);
        glPopMatrix ();
}

void pintujendela()
{
        //pintu depan
        glPushMatrix ();
        glColor3f(1.0,1.0,1.0);
        glTranslatef (1 , -10, 25);
        glRotatef (90, 0, 1, 0);
        glScalef (1, 30, 12);
        glutSolidCube(1);
        glPopMatrix ();

       //angin-angin
        glPushMatrix ();
        glColor3f(0.0,0.0,0.0);
        glTranslatef (1 , 3, 26);
        glRotatef (90, 0, 1, 0);
        glScalef (1 ,2 , 10);
        glutSolidCube(1);
        glPopMatrix ();

       //jendela 1
        glPushMatrix ();
        glColor3f(1.0,1.0,1.0);
        glTranslatef (-10.5 , -2.5, 26);
        glRotatef (90, 0, 1, 0);
        glScalef (1 ,15 , 9);
        glutSolidCube(1);
        glPopMatrix ();

       //kaca 1
        glPushMatrix ();
        glColor3f(0.0,0.0,0.0);
        glTranslatef (-10.5 , -4, 26);
        glRotatef (90, 0, 1, 0);
        glScalef (2 ,10 , 7);
        glutSolidCube(1);
        glPopMatrix ();

       //angin-angin 1
        glPushMatrix ();
        glColor3f(0.0,0.0,0.0);
        glTranslatef (-10.5 , 3, 26);
        glRotatef (90, 0, 1, 0);
        glScalef (2 ,2 , 7);
        glutSolidCube(1);
        glPopMatrix ();

       //jendela 2
        glPushMatrix ();
        glColor3f(1.0,1.0,1.0);
        glTranslatef (25 , -2.5, 26);
        glRotatef (90, 0, 1, 0);
        glScalef (1 ,15 , 9);
        glutSolidCube(1);
        glPopMatrix ();

       //kaca 2
        glPushMatrix ();
        glColor3f(0.0,0.0,0.0);
        glTranslatef (25 , -4, 26);
        glRotatef (90, 0, 1, 0);
        glScalef (2 ,10 , 7);
        glutSolidCube(1);
        glPopMatrix ();

       //angin-angin 2
        glPushMatrix ();
        glColor3f(0.0,0.0,0.0);
        glTranslatef (25 , 3, 26);
        glRotatef (90, 0, 1, 0);
        glScalef (2 ,2 , 7);
        glutSolidCube(1);
        glPopMatrix ();
}

void tiang()
{
    //tiang kanan
        glPushMatrix ();
        glColor3f(8.0,4.0,4.0);
        glTranslatef (45 , -1, 40);
        glRotatef (90, 1, 0, 0);
        glScalef (-2, 5, -45);
        glutWireCube(1);
        glPopMatrix ();

       //tiang kiri
        glPushMatrix ();
        glColor3f (8.0,4.0,4.0);
        glTranslatef (-44 , -1, 45);
        glRotatef (90, 1, 0, 0);
        glScalef (-2, 5, -45);
        glutWireCube(1);
        glPopMatrix ();

       //tiang tengah
        glPushMatrix ();
        glColor3f (8.0,4.0,4.0);
        glTranslatef (1 , -1, 45);
        glRotatef (90, 1, 0, 0);
        glScalef (4, 5, 45);
        glutWireCube(1);
        glPopMatrix ();
}

void tembokbatas()
{
    //tembok kanan
        glPushMatrix ();
        glColor3f(2.0,2.0,2.0);
        glTranslatef (45 , -15, 36);
        glScalef (-3.5, 20, -23);
        glutSolidCube(1);
        glPopMatrix ();

       //tembok kiri
        glPushMatrix ();
        glColor3f (2.0,2.0,2.0);
        glTranslatef (-45 , 0, 42);
        glScalef (-3.5, 48, -35.9);
        glutSolidCube(1);
        glPopMatrix ();
}

void rumputlantai()
{
        //rumput
        glPushMatrix ();
        glColor3f (1.0, 3.0, 0.5);
        glTranslatef (-9 , -22, 29);
        glRotatef (90, 0, 0, 1);
        glScalef (-2.5 ,34 , 30.5);
        glutSolidCube(2);
        glPopMatrix ();

        //lantai rumah
        glPushMatrix ();
        glColor3f (4.0, 4.0, 4.0);
        glTranslatef (0 , -22, 0);
        glRotatef (90, 0, 0, 1);
        glScalef (3 ,45 , 23.5);
        glutSolidCube(2);
        glPopMatrix ();

        //lantai
        glPushMatrix ();
        glColor3f (2.0, 2.0, 2.0);
        glTranslatef (24 , -22, 42);
        glScalef (13, 1.8, 12);
        glutSolidCube(3);
        glPopMatrix ();

       //alas lantai
        glPushMatrix ();
        glColor3f (8.0,4.0,4.0);
        glTranslatef (1 , -19, 27);
        glScalef (12, 1, 10);
        glutSolidCube(1);
        glPopMatrix ();

       //jalan depan
        glPushMatrix ();
        glColor3f(1.0,1.0,1.0);
        glTranslatef (1 , -22, 102);
        glRotatef (90, 0, 0, 1);
        glScalef (2, 9500, 65);
        glutSolidCube(1.2);
}

void objek()
{
        //objek
        glColor3f (4.0, 1.0, 2.0);
        glTranslatef (41 , -12, -18);
        glRotatef (90, 0, 0, 1);
        glScalef (-6, 2, 4);
        glutSolidCube(2);
        glPopMatrix ();

        //kasur
        glPushMatrix ();
        glColor3f (4.0, 1.0, 2.0);
        glTranslatef (30 , -16, -18);
        glRotatef (90, 0, 1, 0);
        glScalef (3, 2, 8);
        glutSolidCube(3);
        glPopMatrix ();

        //selimut
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(18,-11,-23);
        glVertex3f(33,-11,-23);
        glVertex3f(33,-11,-13);
        glVertex3f(18,-11,-13);
        glEnd();

        //bantal
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(35,-11,-23);
        glVertex3f(42,-11,-23);
        glVertex3f(42,-11,-13);
        glVertex3f(35,-11,-13);
        glEnd();

        //meja
        glPushMatrix ();
        glColor3f (8.0, 5.0, 2.0);
        glTranslatef (40 , -15, -2);
        glRotatef (90, 0, 1, 0);
        glScalef (4, 2, 2);
        glutSolidCube(3);
        glPopMatrix ();

        //teko
        glPushMatrix ();
        glColor3f (1.0, 6.0, 2.0);
        glTranslatef (40 , -10, -2);
        glRotatef (90, 0, 1, 0);
        glScalef (2, 2, 2);
        glutSolidTeapot(1);
        glPopMatrix ();

        //gelas
        glPushMatrix ();
        glColor3f (8.0, 6.0, 2.0);
        glTranslatef (40 , -11, -6);
        glRotatef (90, 0, 1, 0);
        glScalef (1, 2, 2);
        glutWireCube(1);
        glPopMatrix ();

        //kursi
        glPushMatrix ();
        glColor3f (2.0, 1.0, 2.0);
        glTranslatef (-15 , -15, -17);
        glRotatef (90, 0, 1, 0);
        glScalef (3, 2, 6);
        glutSolidCube(3);
        glPopMatrix ();

        glPushMatrix ();
        glColor3f (2.0, 1.0, 2.0);
        glTranslatef (-15 , -12, -21);
        glRotatef (90, 1, 0, 0);
        glScalef (5.5, 1, 4);
        glutSolidCube(3);
        glPopMatrix ();

        //meja r.tamu
        glPushMatrix ();
        glColor3f (8.0, 5.0, 2.0);
        glTranslatef (-15 , -15, 1);
        glRotatef (90, 0, 1, 0);
        glScalef (3, 2, 4);
        glutSolidCube(3);
        glPopMatrix ();

        //tv
        glPushMatrix ();
        glColor3f (1.0, 1.0, 1.0);
        glTranslatef (-19 , 0, 22.5);
        glRotatef (90, 1, 0, 0);
        glScalef (10, 1, 8);
        glutSolidCube(2);
        glPopMatrix ();

        //lemari
        glPushMatrix ();
        glColor3f (1.0, 4.0, 4.0);
        glTranslatef (28 , -5, 19.5);
        glRotatef (90, 1, 0, 0);
        glScalef (8, 4, 15);
        glutSolidCube(2);
        glPopMatrix ();

        glPushMatrix ();
        glColor3f (4.0, 4.0, 4.0);
        glTranslatef (24 , -5, 15);
        glRotatef (90, 1, 0, 0);
        glScalef (4, 1, 15);
        glutSolidCube(2);
        glPopMatrix ();

        glPushMatrix ();
        glColor3f (4.0, 4.0, 4.0);
        glTranslatef (33 , -5, 15);
        glRotatef (90, 1, 0, 0);
        glScalef (3.5, 0.9, 15);
        glutSolidCube(2);
        glPopMatrix ();
}

void tampil()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(arot, 1, 0, 0);
    glRotatef(brot, 0, 1, 0);

    glPushMatrix();
    rumah();
    atap();
    pintujendela();
    tiang();
    tembokbatas();
    rumputlantai();
    objek();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int a, int b)
{
    switch(key)
    {
        case '5':
            if(is_depth)
            {
                is_depth=0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth=1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}

void idle(){
    if(!mouseDown){
        arot += 0.3f;
        brot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int a, int b){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        adiff = a - brot;
        bdiff = -b + arot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int a, int b){
    if(mouseDown){
        brot = a - adiff;
        arot = b + bdiff;

        glutPostRedisplay();
    }
}


void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, lebar / tinggi, 5, 500);
    glTranslatef(0, -5, -250);
    glMatrixMode(GL_MODELVIEW);
}
