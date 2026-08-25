#include <GL/glut.h>
#include <math.h>

float counter = 1800.0;
float counter2 = 1000.0;

float tcounter = 200.0;
float bcounter = 1200.0;

float birdMove = 0.0;
float birdMove2 = 0.0;

void initOpenGL()
{
    glClearColor(0.55, 0.82, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-100, 2500, -30, 1200);

    glMatrixMode(GL_MODELVIEW);
}

void grass()
{
    glLoadIdentity();

    glColor3ub(100, 220, 90);

    glBegin(GL_POLYGON);

    glVertex2i(-100, -30);
    glVertex2i(-100, 500);
    glVertex2i(2500, 500);
    glVertex2i(2500, -30);

    glEnd();
}

void road()
{
    glLoadIdentity();

    glColor3ub(66, 66, 66);

    glBegin(GL_POLYGON);

    glVertex2i(-100, 80);
    glVertex2i(-100, 210);
    glVertex2i(2500, 210);
    glVertex2i(2500, 80);

    glEnd();

    glColor3ub(255, 255, 255);

    glLineWidth(15);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(5, 0xAAAA);

    glBegin(GL_LINES);

    glVertex2i(-100, 145);
    glVertex2i(2500, 145);

    glEnd();

    glDisable(GL_LINE_STIPPLE);
}

void flower(float x, float y)
{
    glColor3ub(0, 130, 30);

    glLineWidth(2);

    glBegin(GL_LINES);

    glVertex2f(x, y);
    glVertex2f(x, y + 8);

    glEnd();

    glColor3ub(0, 170, 40);

    glBegin(GL_TRIANGLES);

    glVertex2f(x, y + 3);
    glVertex2f(x - 5, y + 6);
    glVertex2f(x - 1, y + 2);

    glEnd();

    glBegin(GL_TRIANGLES);

    glVertex2f(x, y + 4);
    glVertex2f(x + 5, y + 7);
    glVertex2f(x + 1, y + 3);

    glEnd();

    glColor3ub(255, 105, 180);

    glBegin(GL_POLYGON);

    glVertex2f(x - 4, y + 8);
    glVertex2f(x - 3, y + 15);
    glVertex2f(x, y + 11);
    glVertex2f(x + 3, y + 15);
    glVertex2f(x + 4, y + 8);
    glVertex2f(x + 2, y + 5);
    glVertex2f(x, y + 7);
    glVertex2f(x - 2, y + 5);

    glEnd();

    glColor3ub(255, 220, 0);

    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++)
    {
        float angle = i * 3.1416 / 180.0;

        glVertex2f(
            x + cos(angle),
            y + 9 + sin(angle)
        );
    }

    glEnd();
}

void manyFlowers()
{
    glLoadIdentity();

    flower(30,20);
    flower(55,35);
    flower(80,18);
    flower(110,45);
    flower(135,25);
    flower(160,55);
    flower(185,30);
    flower(210,20);
    flower(235,48);

    flower(45,65);
    flower(75,80);
    flower(105,60);
    flower(140,75);
    flower(175,65);
    flower(205,85);
    flower(240,70);

    flower(270,25);
    flower(290,45);
    flower(315,30);
    flower(340,55);
    flower(370,25);
    flower(395,45);
    flower(420,20);
    flower(450,60);
    flower(475,35);
    flower(500,50);
    flower(530,25);
    flower(555,70);
    flower(580,35);
    flower(610,55);
    flower(640,25);
    flower(670,45);
    flower(700,30);
    flower(730,65);
    flower(760,35);
    flower(790,55);

    flower(850,20);
    flower(880,50);
    flower(910,30);
    flower(940,70);
    flower(970,25);
    flower(1000,55);
    flower(1030,35);
    flower(1060,75);
    flower(1090,25);
    flower(1120,50);

    flower(1160,20);
    flower(1190,65);
    flower(1220,35);
    flower(1250,75);
    flower(1280,25);
    flower(1310,55);
    flower(1340,40);
    flower(1370,70);

    flower(1420,25);
    flower(1450,50);
    flower(1480,30);
    flower(1510,70);
    flower(1540,20);
    flower(1570,55);
    flower(1600,35);
    flower(1630,75);
    flower(1660,25);
    flower(1690,50);

    flower(1730,20);
    flower(1760,60);
    flower(1790,35);
    flower(1820,75);
    flower(1850,25);
    flower(1880,55);
    flower(1910,30);
    flower(1940,65);

    flower(1980,20);
    flower(2010,50);
    flower(2040,30);
    flower(2070,70);
    flower(2100,25);
    flower(2130,55);
    flower(2160,35);
    flower(2190,75);
    flower(2220,25);
    flower(2250,50);

    flower(100,110);
    flower(180,120);
    flower(260,105);
    flower(340,115);
    flower(430,100);
    flower(520,120);
    flower(610,105);
    flower(700,125);

    flower(900,110);
    flower(1000,125);
    flower(1100,105);
    flower(1200,120);
    flower(1300,100);
    flower(1400,125);
    flower(1500,105);
    flower(1600,120);
    flower(1700,100);
    flower(1800,125);
    flower(1900,105);
    flower(2000,120);
    flower(2100,100);
    flower(2200,120);
}

void bird(float x, float y)
{
    glColor3ub(40,40,40);

    glLineWidth(4);

    glBegin(GL_LINES);

    glVertex2f(x,y);
    glVertex2f(x+8,y+5);

    glVertex2f(x+8,y+5);
    glVertex2f(x+16,y);

    glEnd();
}

void birds()
{
    glLoadIdentity();

    bird(400 + birdMove,1000);
    bird(550 + birdMove2,1080);
    bird(700 + birdMove,950);
    bird(900 + birdMove2,1050);
    bird(1100 + birdMove,980);
    bird(1300 + birdMove2,1100);
    bird(1500 + birdMove,920);
    bird(1700 + birdMove2,1030);
    bird(1900 + birdMove,970);
    bird(2100 + birdMove2,1080);
}

void house()
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glTranslated(350.0,600.0,0.0);

    glScaled(50.0,30.0,1.0);

    glColor3ub(255,239,200);

    glBegin(GL_QUADS);

    glVertex2f(-8,-12);
    glVertex2f(8,-12);
    glVertex2f(8,6);
    glVertex2f(-8,6);

    glEnd();

    glColor3ub(90,45,25);

    glLineWidth(3);

    glBegin(GL_LINE_LOOP);

    glVertex2f(-8,-12);
    glVertex2f(8,-12);
    glVertex2f(8,6);
    glVertex2f(-8,6);

    glEnd();

    glColor3ub(110,55,30);

    glBegin(GL_TRIANGLES);

    glVertex2f(-9.3,6);
    glVertex2f(9.3,6);
    glVertex2f(0,14);

    glEnd();

    glColor3ub(70,35,20);

    glLineWidth(6);

    glBegin(GL_LINE_LOOP);

    glVertex2f(-9.3,6);
    glVertex2f(0,14);
    glVertex2f(9.3,6);

    glEnd();

    glColor3ub(95,45,25);

    glBegin(GL_QUADS);

    glVertex2f(-1.5,-5);
    glVertex2f(1.4,-5);
    glVertex2f(1.4,-11.8);
    glVertex2f(-1.5,-11.8);

    glEnd();

    glColor3ub(255,220,150);

    glLineWidth(3);

    glBegin(GL_LINES);

    glVertex2f(-0.05,-12);
    glVertex2f(-0.05,-5);

    glVertex2f(-1.5,-7.5);
    glVertex2f(1.4,-7.5);

    glVertex2f(-1.5,-10);
    glVertex2f(1.4,-10);

    glEnd();

    glColor3ub(120,70,40);

    glBegin(GL_QUADS);

    glVertex2f(-6.5,-5);
    glVertex2f(-3.5,-5);
    glVertex2f(-3.5,-10);
    glVertex2f(-6.5,-10);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(-6.5,5);
    glVertex2f(-3.5,5);
    glVertex2f(-3.5,0.5);
    glVertex2f(-6.5,0.5);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(3,-5);
    glVertex2f(7,-5);
    glVertex2f(7,-10);
    glVertex2f(3,-10);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(3,5);
    glVertex2f(7,5);
    glVertex2f(7,0.5);
    glVertex2f(3,0.5);

    glEnd();

    glColor3ub(120,220,240);

    glBegin(GL_QUADS);

    glVertex2f(-6.1,-5.4);
    glVertex2f(-3.9,-5.4);
    glVertex2f(-3.9,-9.6);
    glVertex2f(-6.1,-9.6);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(-6.1,4.6);
    glVertex2f(-3.9,4.6);
    glVertex2f(-3.9,0.9);
    glVertex2f(-6.1,0.9);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(3.5,-5.4);
    glVertex2f(6.5,-5.4);
    glVertex2f(6.5,-9.6);
    glVertex2f(3.5,-9.6);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(3.5,4.6);
    glVertex2f(6.5,4.6);
    glVertex2f(6.5,0.9);
    glVertex2f(3.5,0.9);

    glEnd();

    glColor3ub(90,45,25);

    glLineWidth(3);

    glBegin(GL_LINES);

    glVertex2f(-5,-10);
    glVertex2f(-5,-5);

    glVertex2f(-6.5,-7.5);
    glVertex2f(-3.5,-7.5);

    glVertex2f(-5,5);
    glVertex2f(-5,0.5);

    glVertex2f(-6.5,2.75);
    glVertex2f(-3.5,2.75);

    glVertex2f(4.3,-5);
    glVertex2f(4.3,-10);

    glVertex2f(5.5,-5);
    glVertex2f(5.5,-10);

    glVertex2f(3,-7.5);
    glVertex2f(7,-7.5);

    glVertex2f(4.3,5);
    glVertex2f(4.3,0.5);

    glVertex2f(5.5,5);
    glVertex2f(5.5,0.5);

    glVertex2f(3,2.75);
    glVertex2f(7,2.75);

    glEnd();

    glColor3ub(117,12,6);

    glLineWidth(20);

    glBegin(GL_LINES);

    glVertex2f(-14,-5);
    glVertex2f(-14,-12);

    glVertex2f(-11,-5);
    glVertex2f(-11,-12);

    glEnd();

    glColor3ub(33,171,73);

    glBegin(GL_TRIANGLES);

    glVertex2f(-13,-5);
    glVertex2f(-15,-5);
    glVertex2f(-14,1);

    glVertex2f(-10,-5);
    glVertex2f(-12,-5);
    glVertex2f(-11,1);

    glEnd();

    glColor3ub(117,12,6);

    glLineWidth(20);

    glBegin(GL_LINES);

    glVertex2f(14,-5);
    glVertex2f(14,-12);

    glVertex2f(11,-5);
    glVertex2f(11,-12);

    glEnd();

    glColor3ub(33,171,73);

    glBegin(GL_TRIANGLES);

    glVertex2f(13,-5);
    glVertex2f(15,-5);
    glVertex2f(14,1);

    glVertex2f(10,-5);
    glVertex2f(12,-5);
    glVertex2f(11,1);

    glEnd();

    glPopMatrix();
}

void human(float x,float y)
{
    glLoadIdentity();

    glColor3ub(255,204,153);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++)
    {
        float angle=i*3.1416/180.0;

        glVertex2f(
            x+8*cos(angle),
            y+30+8*sin(angle)
        );
    }

    glEnd();

    glColor3ub(0,80,200);

    glLineWidth(8);

    glBegin(GL_LINES);

    glVertex2f(x,y+22);
    glVertex2f(x,y);

    glEnd();

    glColor3ub(255,204,153);

    glLineWidth(5);

    glBegin(GL_LINES);

    glVertex2f(x,y+18);
    glVertex2f(x-12,y+8);

    glVertex2f(x,y+18);
    glVertex2f(x+12,y+8);

    glEnd();

    glColor3ub(30,30,100);

    glLineWidth(6);

    glBegin(GL_LINES);

    glVertex2f(x,y);
    glVertex2f(x-10,y-18);

    glVertex2f(x,y);
    glVertex2f(x+10,y-18);

    glEnd();
}

void standingHumans()
{
    human(850,280);
    human(1150,330);
    human(1500,280);
    human(1800,340);
}

void window(int w1,int w2)
{
    glColor3ub(0,0,0);

    glBegin(GL_POLYGON);

    glVertex2i(w1,160);
    glVertex2i(w1,185);
    glVertex2i(w2,185);
    glVertex2i(w2,160);

    glEnd();
}

void buswindow(int w1,int w2)
{
    glColor3ub(0,0,0);

    glBegin(GL_POLYGON);

    glVertex2i(w1,180);
    glVertex2i(w1,205);
    glVertex2i(w2,205);
    glVertex2i(w2,180);

    glEnd();
}

void wheel(int x,int y)
{
    float angle;

    glColor3ub(0,0,0);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++)
    {
        angle=i*3.1416/180.0;

        glVertex2i(
            x+20*cos(angle),
            y+20*sin(angle)
        );
    }

    glEnd();
}

void car()
{
    glLoadIdentity();

    counter-=2.0;

    if(counter<-500)
        counter=1800;

    glTranslated(counter,60,0);
    glScaled(0.5,0.5,1);

    glColor3ub(255,255,255);

    glBegin(GL_POLYGON);

    glVertex2i(80,100);
    glVertex2i(100,160);
    glVertex2i(450,160);
    glVertex2i(450,100);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2i(150,160);
    glVertex2i(200,200);
    glVertex2i(400,200);
    glVertex2i(450,160);

    glEnd();

    window(210,280);
    window(300,390);

    wheel(170,100);
    wheel(390,100);
}

void car2()
{
    glLoadIdentity();

    counter2-=1.5;

    if(counter2<-500)
        counter2=2200;

    glTranslated(counter2,70,0);
    glScaled(0.45,0.45,1);

    glColor3ub(230,50,60);

    glBegin(GL_POLYGON);

    glVertex2i(80,100);
    glVertex2i(100,160);
    glVertex2i(450,160);
    glVertex2i(450,100);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2i(150,160);
    glVertex2i(200,200);
    glVertex2i(400,200);
    glVertex2i(450,160);

    glEnd();

    window(210,280);
    window(300,390);

    wheel(170,100);
    wheel(390,100);
}

void truck()
{
    glLoadIdentity();

    tcounter+=1.2;

    if(tcounter>2500)
        tcounter=-100;

    glTranslated(tcounter,160,0);
    glScaled(0.4,0.4,1);

    glColor3ub(58,250,255);

    glBegin(GL_POLYGON);

    glVertex2i(100,100);
    glVertex2i(100,160);
    glVertex2i(450,160);
    glVertex2i(450,100);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2i(340,160);
    glVertex2i(340,200);
    glVertex2i(400,200);
    glVertex2i(450,160);

    glEnd();

    window(356,400);

    wheel(200,100);
    wheel(380,100);
}

void bus()
{
    glLoadIdentity();

    bcounter-=1.2;

    if(bcounter<-1000)
        bcounter=1800;

    glTranslated(bcounter,140,0);
    glScaled(0.4,0.4,1);

    glColor3ub(255,255,255);

    glBegin(GL_POLYGON);

    glVertex2i(100,100);
    glVertex2i(150,215);
    glVertex2i(470,215);
    glVertex2i(470,100);

    glEnd();

    buswindow(170,220);
    buswindow(230,270);
    buswindow(280,330);
    buswindow(340,390);
    buswindow(400,450);

    wheel(200,100);
    wheel(400,100);

    glColor3ub(0,255,0);

    glBegin(GL_POLYGON);

    glVertex2i(100,120);
    glVertex2i(120,170);
    glVertex2i(470,170);
    glVertex2i(470,120);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    grass();

    manyFlowers();

    birds();

    road();

    house();

    standingHumans();

    car();
    car2();
    truck();
    bus();

    glutSwapBuffers();
}

void update(int value)
{
    birdMove += 0.25;
    birdMove2 += 0.18;

    if(birdMove > 300)
        birdMove = -300;

    if(birdMove2 > 250)
        birdMove2 = -250;

    glutPostRedisplay();

    glutTimerFunc(16,update,0);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1000,600);

    glutInitWindowPosition(100,50);

    glutCreateWindow("2D Village Scene");

    initOpenGL();

    glutDisplayFunc(display);

    glutTimerFunc(0,update,0);

    glutMainLoop();

    return 0;
}
