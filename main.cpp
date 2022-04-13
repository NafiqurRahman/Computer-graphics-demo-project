#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <windows.h>
#include <mmsystem.h>
#include <iostream>

using namespace std;

float run = 0.0;
float run1 = 0.0;
float run2 = 0.0;
float run3 = 0.0;
float tri = 0.0;
float rain = 0.0;
float _nt = 0.0;


bool onOff;
bool frd = false;
bool bck = false;

bool rainday = false;
bool night = false;
//bool sun=false;



void carbackward (int value){

    if(bck) {

        tri -= 2.2f;

        if (tri < -350)
            {
            tri = 1100;
            }

        glutPostRedisplay();
        glutTimerFunc(25, carbackward, 0);

            }
}


void carforward (int value ) {

    if (frd) {

        tri += 2.2f;

        if(tri > 1000)
        {

            tri -= 1400;
        }

        glutPostRedisplay();
        glutTimerFunc(25, carforward, 0);

    }

}


void Rain(int value){

if(rainday){

    rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1300; y%=650;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

    }
}

void Night(int value){

if(night){


    glClearColor(0.0,0.0,0.0,0.0);
	glutPostRedisplay();
    glutTimerFunc(5, Night, 0);
    glFlush();

    }
}



void update (int value)
{

    run += 1.5f;
    if (run > 1300)
    {
        run -= 1700;
    }


    run1 += 1.0f;

    if (run1 > 600)
    {

        run1 -= 1300;
    }

        run2 += 1.0f;

    if (run2 > 800)
    {

        run2 -= 1300;
    }

        run3 += 1.0f;

    if (run3 > 1000)
    {

        run3 -= 1300;
    }




    if (onOff)
    {
        tri += 2.5f;

        if (tri > 1600)
        {

            tri = 1300;
        }

    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);

}


void myKeyboard (unsigned char key, int x, int y) {

    switch (key)
    {
    case 'a':
        frd = false;
        bck = true;
        carbackward (tri);
        break;


    case 'd':
        frd = true;
        bck = false;
        carforward (tri);
        break;

    case 's':
        frd = false;
        bck = false;
        break;

    case 'r':
        rainday = true;
        Rain(rain);
        sndPlaySound("River.way",SND_ASYNC|SND_LOOP);
        break;

    case 't':
        rainday = false;
        sndPlaySound(NULL,SND_ASYNC);
        break;

    case 'n':
        night = true;
        Night(_nt);
        break;

    case 'b':
        night = false;
        glClearColor(0.0,0.5,0.8,1.0);
        break;


    case 27:
        exit(0);
        break;

    default:
    break;

    }

}


void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(5.0);


glBegin(GL_QUADS);
glColor3ub (186, 164, 123);
glVertex2i(0, 250);
glVertex2i(1300, 250);          //basepart
glColor3ub (156, 126, 72);
glVertex2i(1300, 550);
glVertex2i(0, 550);
glEnd();



glBegin(GL_POLYGON);

glColor3ub(64,64,64);          //hill-1

glVertex2i(0,550);
glVertex2i(350,550);
glVertex2i(320,615);
glVertex2i(290,625);
glVertex2i(260,595);
glVertex2i(210,615);
glVertex2i(170,595);
glVertex2i(140,625);
glVertex2i(110,635);
glVertex2i(90,555);
glVertex2i(40,595);
glVertex2i(10,555);
glEnd();

glBegin(GL_POLYGON);        //hill-2

glColor3ub(70,80,90);
glVertex2i(350,550);
glVertex2i(700,550);
glVertex2i(670,615);
glVertex2i(640,625);
glVertex2i(610,595);
glVertex2i(580,615);
glVertex2i(550,595);
glVertex2i(520,625);
glVertex2i(490,635);
glVertex2i(460,615);
glVertex2i(430,595);
glVertex2i(400,590);
glVertex2i(370,615);
glVertex2i(360,605);
glVertex2i(330,580);
glEnd();

glBegin(GL_POLYGON);

glColor3ub(64,64,64);       //hill-3
glVertex2i(700,550);
glVertex2i(1050,550);
glVertex2i(1020,615);
glVertex2i(990,615);
glVertex2i(960,595);
glVertex2i(930,625);
glVertex2i(900,635);
glVertex2i(870,615);
glVertex2i(860,595);
glVertex2i(830,590);
glVertex2i(800,615);
glVertex2i(770,605);
glVertex2i(740,580);
glVertex2i(710,590);
glVertex2i(690,570);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(70,80,90);
//glColor3ub(64,64,64);       //hill-4
glVertex2i(1050,550);
glVertex2i(1300,550);
glVertex2i(1370,615);
glVertex2i(1340,625);
glVertex2i(1310,595);
glVertex2i(1280,615);
glVertex2i(1250,605);
glVertex2i(1220,625);
glVertex2i(1190,635);
glVertex2i(1160,615);
glVertex2i(1130,595);
glVertex2i(1100,590);
glVertex2i(1070,615);
glVertex2i(1040,605);
glVertex2i(1010,580);
//glVertex2i(980,590);
glEnd();

glBegin(GL_QUADS);

glColor3ub(0, 153, 51);

glVertex2i(0,550);
glVertex2i(0,500);          //Grass Part
glVertex2i(1300,500);
glVertex2i(1300,550);
glEnd();

glBegin(GL_TRIANGLES);          //Tree 1 Part

glColor3ub(13, 163, 63);

glVertex2i(50,570);
glVertex2i(80,570);
glVertex2i(65,600);
glEnd();

glBegin(GL_QUADS);             //Tree 1 Part

glColor3ub(0,67,0);

glVertex2i(55,570);
glVertex2i(40,545);
glVertex2i(90,545);
glVertex2i(75,570);

glColor3ub(0,0,85);

glVertex2i(45,545);
glVertex2i(30,520);
glVertex2i(100,520);
glVertex2i(85,545);

glColor3ub(0,56,0);

glVertex2i(62,508);
glVertex2i(68,508);
glVertex2i(68,520);
glVertex2i(62,520);
glEnd();

glBegin(GL_TRIANGLES);          //Tree 2 Part

glColor3ub(13, 163, 63);

glVertex2i(145,570);
glVertex2i(175,570);
glVertex2i(160,600);
glEnd();

glBegin(GL_QUADS);            //Tree 2 Part

glColor3ub(0,67,0);

glVertex2i(150,570);
glVertex2i(135,545);
glVertex2i(185,545);
glVertex2i(170,570);

glColor3ub(0,0,85);

glVertex2i(140,545);
glVertex2i(125,520);
glVertex2i(195,520);
glVertex2i(180,545);

glColor3ub(0,56,0);

glVertex2i(158,508);
glVertex2i(163,508);
glVertex2i(163,520);
glVertex2i(158,520);
glEnd();

glBegin(GL_TRIANGLES);          //Tree 3 Part

glColor3ub(13, 163, 63);

glVertex2i(240,570);
glVertex2i(270,570);
glVertex2i(255,600);
glEnd();

glBegin(GL_QUADS);          //Tree 3 Part

glColor3ub(0,67,0);

glVertex2i(245,570);
glVertex2i(230,545);
glVertex2i(280,545);
glVertex2i(265,570);

glColor3ub(0,0,85);

glVertex2i(235,545);
glVertex2i(220,520);
glVertex2i(290,520);
glVertex2i(275,545);

glColor3ub(0,56,0);

glVertex2i(253,508);
glVertex2i(258,508);
glVertex2i(258,520);
glVertex2i(253,520);
glEnd();

glBegin(GL_QUADS);

glColor3ub(133,120,101);        //WatchTower 1

glVertex2i(340,570);
glVertex2i(340,565);      //base
glVertex2i(420,565);
glVertex2i(420,570);

glColor3ub(58,65,4);

glVertex2i(365,585);
glVertex2i(365,570);        //big quad
glVertex2i(395,570);
glVertex2i(395,585);

glColor3ub(58,65,4);     //border Right

glVertex2i(395,585);
glVertex2i(395,584);
glVertex2i(420,584);
glVertex2i(420,585);

glVertex2i(419,584);
glVertex2i(419,565);
glVertex2i(420,565);
glVertex2i(420,584);

glVertex2i(395,576);
glVertex2i(395,577);
glVertex2i(420,577);
glVertex2i(420,576);

glVertex2i(414,585);
glVertex2i(414,570);
glVertex2i(415,570);
glVertex2i(414,585);

glVertex2i(414,585);
glVertex2i(414,577);
glVertex2i(415,577);
glVertex2i(415,585);

glColor3ub(58,65,4);

glVertex2i(403,595);     //Big border
glVertex2i(403,570);
glVertex2i(406,570);
glVertex2i(406,595);

glVertex2i(392,595);
glVertex2i(392,585);
glVertex2i(395,585);
glVertex2i(395,595);

glColor3ub(58,65,4);     //border Left

glVertex2i(340,585);
glVertex2i(340,584);
glVertex2i(365,584);
glVertex2i(365,585);

glVertex2i(339,584);
glVertex2i(339,565);
glVertex2i(340,565);
glVertex2i(340,584);

glVertex2i(340,576);
glVertex2i(340,577);
glVertex2i(365,577);
glVertex2i(365,576);

glVertex2i(345,585);
glVertex2i(345,570);
glVertex2i(346,570);
glVertex2i(346,585);

glVertex2i(414,585);
glVertex2i(414,577);
glVertex2i(415,577);
glVertex2i(415,585);  //useless border

glColor3ub(58,65,4);

glVertex2i(354,595);
glVertex2i(354,570);   //big border
glVertex2i(357,570);
glVertex2i(357,595);

glVertex2i(365,595);
glVertex2i(365,585);
glVertex2i(369,585);
glVertex2i(369,595);
glEnd();

glBegin(GL_TRIANGLES);

glColor3ub(125,88,42);

glVertex2i(344,595);       //Triangle
glVertex2i(416,595);
glVertex2i(380,620);
glEnd();

glBegin(GL_QUADS);

glVertex2i(354,565);
glVertex2i(354,500);
glVertex2i(359,500);    //pillar
glVertex2i(359,565);

glVertex2i(401,565);
glVertex2i(401,500);
glVertex2i(406,500);
glVertex2i(406,565);
glEnd();

glBegin(GL_QUADS);      //Ladder

glColor3ub(0,0,0);

glVertex2i(375,565);
glVertex2i(375,500);
glVertex2i(377,500);
glVertex2i(377,565);

glVertex2i(385,565);
glVertex2i(385,500);
glVertex2i(387,500);
glVertex2i(387,565);

glVertex2i(377,562);
glVertex2i(377,561);
glVertex2i(385,561);
glVertex2i(385,562);

glVertex2i(377,557);
glVertex2i(377,556);
glVertex2i(385,556);
glVertex2i(385,557);

glVertex2i(377,552);
glVertex2i(377,551);
glVertex2i(385,551);
glVertex2i(385,552);

glVertex2i(377,547);
glVertex2i(377,546);
glVertex2i(385,546);
glVertex2i(385,547);

glVertex2i(377,542);
glVertex2i(377,541);
glVertex2i(385,541);
glVertex2i(385,542);

glVertex2i(377,537);
glVertex2i(377,536);
glVertex2i(385,536);
glVertex2i(385,537);

glVertex2i(377,532);
glVertex2i(377,531);
glVertex2i(385,532);
glVertex2i(385,531);

glVertex2i(377,527);
glVertex2i(377,526);
glVertex2i(385,526);
glVertex2i(385,527);

glVertex2i(377,522);
glVertex2i(377,521);
glVertex2i(385,521);
glVertex2i(385,522);

glVertex2i(377,517);
glVertex2i(377,516);
glVertex2i(385,516);
glVertex2i(385,517);

glVertex2i(377,512);
glVertex2i(377,511);
glVertex2i(385,511);
glVertex2i(385,512);

glVertex2i(377,507);
glVertex2i(377,506);
glVertex2i(385,506);
glVertex2i(385,507);

glVertex2i(377,502);
glVertex2i(377,501);
glVertex2i(385,501);
glVertex2i(385,502);
glEnd();

glBegin(GL_QUADS);

glColor3ub(133,120,101);        //WatchTower 2

glVertex2i(1140,570);
glVertex2i(1140,565);      //base
glVertex2i(1220,565);
glVertex2i(1220,570);

glColor3ub(58,65,4);

glVertex2i(1165,585);
glVertex2i(1165,570);        //big quad
glVertex2i(1195,570);
glVertex2i(1195,585);

glColor3ub(58,65,4);     //border Right

glVertex2i(1195,585);
glVertex2i(1195,584);
glVertex2i(1220,584);
glVertex2i(1220,585);

glVertex2i(1219,584);
glVertex2i(1219,565);
glVertex2i(1220,565);
glVertex2i(1220,584);

glVertex2i(1195,576);
glVertex2i(1195,577);
glVertex2i(1220,577);
glVertex2i(1220,576);

glVertex2i(1214,585);
glVertex2i(1214,570);
glVertex2i(1215,570);
glVertex2i(1214,585);

glVertex2i(1214,585);
glVertex2i(1214,577);
glVertex2i(1215,577);
glVertex2i(1215,585);

glColor3ub(58,65,4);

glVertex2i(1203,595);     //Big border
glVertex2i(1203,570);
glVertex2i(1206,570);
glVertex2i(1206,595);

glVertex2i(1192,595);
glVertex2i(1192,585);
glVertex2i(1195,585);
glVertex2i(1195,595);

glColor3ub(58,65,4);     //border Left

glVertex2i(1140,585);
glVertex2i(1140,584);
glVertex2i(1165,584);
glVertex2i(1165,585);

glVertex2i(1139,584);
glVertex2i(1139,565);
glVertex2i(1140,565);
glVertex2i(1140,584);

glVertex2i(1140,576);
glVertex2i(1140,577);
glVertex2i(1165,577);
glVertex2i(1165,576);

glVertex2i(1145,585);
glVertex2i(1145,570);
glVertex2i(1146,570);
glVertex2i(1146,585);

glVertex2i(1214,585);
glVertex2i(1214,577);
glVertex2i(1215,577);
glVertex2i(1215,585);  //useless border

glColor3ub(58,65,4);

glVertex2i(1154,595);
glVertex2i(1154,570);   //big border
glVertex2i(1157,570);
glVertex2i(1157,595);

glVertex2i(1165,595);
glVertex2i(1165,585);
glVertex2i(1169,585);
glVertex2i(1169,595);

//Ladder
glColor3ub(0,0,0);

glVertex2i(1175,565);
glVertex2i(1175,500);
glVertex2i(1177,500);
glVertex2i(1177,565);

glVertex2i(1185,565);
glVertex2i(1185,500);
glVertex2i(1187,500);
glVertex2i(1187,565);

glVertex2i(1177,562);
glVertex2i(1177,561);
glVertex2i(1185,561);
glVertex2i(1185,562);

glVertex2i(1177,557);
glVertex2i(1177,556);
glVertex2i(1185,556);
glVertex2i(1185,557);

glVertex2i(1177,552);
glVertex2i(1177,551);
glVertex2i(1185,551);
glVertex2i(1185,552);

glVertex2i(1177,547);
glVertex2i(1177,546);
glVertex2i(1185,546);
glVertex2i(1185,547);

glVertex2i(1177,542);
glVertex2i(1177,541);
glVertex2i(1185,541);
glVertex2i(1185,542);

glVertex2i(1177,537);
glVertex2i(1177,536);
glVertex2i(1185,536);
glVertex2i(1185,537);

glVertex2i(1177,532);
glVertex2i(1177,531);
glVertex2i(1185,532);
glVertex2i(1185,531);

glVertex2i(1177,527);
glVertex2i(1177,526);
glVertex2i(1185,526);
glVertex2i(1185,527);

glVertex2i(1177,522);
glVertex2i(1177,521);
glVertex2i(1185,521);
glVertex2i(1185,522);

glVertex2i(1177,517);
glVertex2i(1177,516);
glVertex2i(1185,516);
glVertex2i(1185,517);

glVertex2i(1177,512);
glVertex2i(1177,511);
glVertex2i(1185,511);
glVertex2i(1185,512);

glVertex2i(1177,507);
glVertex2i(1177,506);
glVertex2i(1185,506);
glVertex2i(1185,507);

glVertex2i(1177,502);
glVertex2i(1177,501);
glVertex2i(1185,501);
glVertex2i(1185,502);
glEnd();

glBegin(GL_TRIANGLES);

glColor3ub(125,88,42);

glVertex2i(1144,595);       //Triangle
glVertex2i(1216,595);
glVertex2i(1180,620);
glEnd();

glBegin(GL_QUADS);

glVertex2i(1154,565);
glVertex2i(1154,500);
glVertex2i(1159,500);    //pillar
glVertex2i(1159,565);

glVertex2i(1201,565);
glVertex2i(1201,500);
glVertex2i(1206,500);
glVertex2i(1206,565);

glEnd();





glBegin(GL_QUADS);      //Tent 1

glColor3ub(45,89,67);

glVertex2i(700,490);
glVertex2i(700,540);
glVertex2i(620,540);
glVertex2i(620,490);

glEnd();

glBegin(GL_TRIANGLES);

glVertex2i(710,540);
glVertex2i(660,565);
glVertex2i(610,540);
glEnd();

glBegin(GL_LINES);
glVertex2i(610,540);
glVertex2i(620,520);

glVertex2i(610,540);
glVertex2i(600,480);

glVertex2i(710,540);
glVertex2i(690,500);

glVertex2i(710,540);
glVertex2i(720,480);
glEnd();


glBegin(GL_QUADS);      //Tent 1 Door
glColor3ub(0,0,0);
glVertex2i(675,490);
glVertex2i(675,525);
glVertex2i(645,525);
glVertex2i(645,490);
glEnd();



glBegin(GL_QUADS);          //Tent 2

glColor3ub(85,89,67);

glVertex2i(820,490);
glVertex2i(820,540);
glVertex2i(740,540);
glVertex2i(740,490);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(830,540);
glVertex2i(780,565);
glVertex2i(730,540);
glEnd();

glBegin(GL_LINES);
glVertex2i(830,540);
glVertex2i(810,500);

glVertex2i(830,540);
glVertex2i(840,480);

glVertex2i(730,540);
glVertex2i(750,500);

glVertex2i(730,540);
glVertex2i(720,480);
glEnd();



glBegin(GL_QUADS);          //Tent 2 Door
glColor3ub(0,0,0);
glVertex2i(795,490);
glVertex2i(795,525);
glVertex2i(765,525);
glVertex2i(765,490);
glEnd();


glBegin(GL_QUADS);      //Tent 3
glColor3ub(45,89,67);
glVertex2i(940,490);
glVertex2i(940,540);
glVertex2i(860,540);
glVertex2i(860,490);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2i(950,540);
glVertex2i(900,565);
glVertex2i(850,540);
glEnd();

glBegin(GL_LINES);
glVertex2i(950,540);
glVertex2i(940,520);

glVertex2i(950,540);
glVertex2i(960,480);

glVertex2i(850,540);
glVertex2i(860,520);

glVertex2i(850,540);
glVertex2i(840,480);
glEnd();


glBegin(GL_QUADS);      //Tent 3 Door
glColor3ub(0,0,0);
glVertex2i(915,490);
glVertex2i(915,525);
glVertex2i(885,525);
glVertex2i(885,490);
glEnd();



    glBegin(GL_QUADS);
    glColor3ub(196,185,147);
    glVertex2i(1000,485);  //hospital
    glVertex2i(1120,485);
    glVertex2i(1120,585);
    glVertex2i(1000,585);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(202, 222, 209);
    glVertex2i(990,585);                 //hospitalborder
    glVertex2i(1130,585);
    glVertex2i(1130,600);
    glVertex2i(990,600);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232, 25, 12);       //cross-sign
    glVertex2i(1055,545);
    glVertex2i(1070,545);
    glVertex2i(1070,575);
    glVertex2i(1055,575);

    glVertex2i(1044,553);
    glVertex2i(1082,553);
    glVertex2i(1082,567);
    glVertex2i(1044,567);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(69, 66, 66);
    glVertex2i(1045,530);
    glVertex2i(1045,485);
    glVertex2i(1080,485);
    glVertex2i(1080,530);

    glColor3ub(69, 66, 66);
    glVertex2i(1010,535);
    glVertex2i(1010,515);
    glVertex2i(1030,515);
    glVertex2i(1030,535);

    glColor3ub(69, 66, 66);
    glVertex2i(1110,515);
    glVertex2i(1110,535);
    glVertex2i(1090,535);
    glVertex2i(1090,515);
    glEnd();




 //tank-start

    //tankbody1

   glBegin(GL_POLYGON);
    glColor3ub(50,56,6);
    glVertex2i(525,325);
    glVertex2i(535,325);
    glVertex2i(715,325);
    glVertex2i(725,325);
    glVertex2i(715,360);
    glVertex2i(535,360);

    glEnd();

    //tankbody2

    glBegin(GL_QUADS);
    glVertex2i(565,350);
    glVertex2i(675,350);
    glVertex2i(675,390);
    glVertex2i(565,390);
    //tankhead

    glColor3ub(34,36,34);
    glVertex2i(600,390);
    glVertex2i(640,390);
    glVertex2i(640,400);
    glVertex2i(600,400);

     //tankgun
     glColor3ub(34, 36, 34);
    glVertex2i(675,365);
    glVertex2i(755,370);
    glVertex2i(755,380);
    glVertex2i(675,385);

    glEnd();



    //tankbase

    glBegin(GL_POLYGON);
  glColor3ub(79,68,31);
  for(int i=180;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(625+cos(angle)*90,325+sin(angle)*35);
    }
    glEnd();

    //wheel-1

      glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(555+cos(angle)*10,315+sin(angle)*10);
    }
    glEnd();


//wheel-2
  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(690+cos(angle)*10,315+sin(angle)*10);

    }
    glEnd();

//whell3
      glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(583+cos(angle)*10,310+sin(angle)*10);

    }
    glEnd();


//wheel-4
  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(611+cos(angle)*10,305+sin(angle)*10);

    }

    glEnd();

    //wheel-5

  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(639+cos(angle)*10,305+sin(angle)*10);

    }

    glEnd();
    //whell-6

  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(667+cos(angle)*10,306+sin(angle)*10);
    }

    glEnd();               //tank-end




glBegin(GL_QUADS);
glColor3ub (158, 191, 247);
glVertex2i(0, 200);
glVertex2i(0, 0);          //river Part
glColor3ub (116, 162, 242);
glVertex2i(1300, 0);
glVertex2i(1300, 200);
//second river
glVertex2i(0, 230);
glVertex2i(1300, 230);
glVertex2i(1300, 250);
glVertex2i(0, 250);

glEnd();



                               //building-start

    glBegin(GL_QUADS);        //building-2
    glColor3ub(82,82,82);
    glVertex2i(440,450);
    glVertex2i(550,450);
    glVertex2i(550,510);
    glVertex2i(440,510);


    glColor3ub(63,105,56);        //buildingside-1
    glVertex2i(420,450);
    glVertex2i(440,450);
    glVertex2i(440,525);
    glVertex2i(420,525);
                                   //buildingside-2
    glVertex2i(550,450);
    glVertex2i(570,450);
    glVertex2i(570,525);
    glVertex2i(550,525);
                                //buildingup
    glVertex2i(440,510);
    glVertex2i(550,510);
    glVertex2i(550,525);
    glVertex2i(440,525);


     glColor3ub(89, 125, 96);
     glVertex2i(410,445);      //buildingbase
     glVertex2i(580,445);
     glVertex2i(580,450);
     glVertex2i(410,450);


     glColor3ub(89, 125, 96);
     glVertex2i(440,515);      //buildingw
     glVertex2i(550,515);
     glVertex2i(550,530);
     glVertex2i(440,530);



     glColor3ub(0, 0, 0);
     glVertex2i(450,515);      //border-1
     glVertex2i(453,515);
     glVertex2i(453,530);
     glVertex2i(450,530);


      glColor3ub(0, 0, 0);
     glVertex2i(463,515);      //border-2
     glVertex2i(466,515);
     glVertex2i(466,530);
     glVertex2i(463,530);

      glColor3ub(0, 0, 0);
     glVertex2i(476,515);      //border-3
     glVertex2i(479,515);
     glVertex2i(479,530);
     glVertex2i(476,530);


      glColor3ub(0, 0, 0);
     glVertex2i(489,515);      //border-4
     glVertex2i(492,515);
     glVertex2i(492,530);
     glVertex2i(489,530);



      glColor3ub(0, 0, 0);
     glVertex2i(502,515);      //border-5
     glVertex2i(505,515);
     glVertex2i(505,530);
     glVertex2i(502,530);



      glColor3ub(0, 0, 0);
     glVertex2i(515,515);      //border-6
     glVertex2i(518,515);
     glVertex2i(518,530);
     glVertex2i(515,530);


       glColor3ub(0, 0, 0);
     glVertex2i(528,515);      //border-7
     glVertex2i(531,515);
     glVertex2i(531,530);
     glVertex2i(528,530);


       glColor3ub(0, 0, 0);
     glVertex2i(541,515);      //border-8
     glVertex2i(544,515);
     glVertex2i(544,530);
     glVertex2i(541,530);



     glColor3ub(0, 0, 0);
     glVertex2i(494,560);      //flag-l
     glVertex2i(496,560);
     glVertex2i(496,600);
     glVertex2i(494,600);

     glColor3ub(7, 171, 15);
     glVertex2i(496,580);      //flag-green
     glVertex2i(530,580);
     glVertex2i(530,600);
     glVertex2i(496,600);




    glEnd();

  glBegin(GL_POLYGON);            //flag-cir
    glColor3ub(245, 25, 10);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(513+cos(angle)*7,590+sin(angle)*7);

    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(63,105,56);

    glVertex2i(410,525);
    glVertex2i(495,560);
    glVertex2i(580,525);


    glEnd();             //building-end

//helipad

    glBegin(GL_POLYGON);            //helipad
    glColor3ub(0, 0, 0);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1100+cos(angle)*150,375+sin(angle)*30);

    }
    glEnd();

    glBegin(GL_QUADS);              // Helipad
    glColor3ub(152, 154, 156);
    glVertex2i(1130,370);
    glVertex2i(1140,370);
    glVertex2i(1140,410);
    glVertex2i(1130,410);

    glVertex2i(1070,370);
    glVertex2i(1080,370);
    glVertex2i(1080,410);
    glVertex2i(1070,410);

    glVertex2i(1080,385);
    glVertex2i(1140,385);
    glVertex2i(1140,395);
    glVertex2i(1080,395);



    glEnd();




glBegin(GL_QUADS);

glColor3ub(0,0,0);
                            //bridge
glVertex2i(0,230);
glVertex2i(1300,230);
glVertex2i(1300,100);
glVertex2i(0,100);

glColor3ub(152, 154, 156);

glVertex2i(60,165);          //roadline-1
glVertex2i(160,165);
glVertex2i(160,175);
glVertex2i(60,175);

glVertex2i(190,165);          //roadline-2
glVertex2i(290,165);
glVertex2i(290,175);
glVertex2i(190,175);

glVertex2i(320,165);          //roadline-3
glVertex2i(420,165);
glVertex2i(420,175);
glVertex2i(320,175);

glVertex2i(450,165);          //roadline-4
glVertex2i(550,165);
glVertex2i(550,175);
glVertex2i(450,175);

glVertex2i(580,165);          //roadline-5
glVertex2i(680,165);
glVertex2i(680,175);
glVertex2i(580,175);

glVertex2i(710,165);          //roadline-5
glVertex2i(810,165);
glVertex2i(810,175);
glVertex2i(710,175);

glVertex2i(840,165);          //roadline-6
glVertex2i(940,165);
glVertex2i(940,175);
glVertex2i(840,175);

glVertex2i(970,165);          //roadline-7
glVertex2i(1070,165);
glVertex2i(1070,175);
glVertex2i(970,175);

glVertex2i(1100,165);          //roadline-8
glVertex2i(1200,165);
glVertex2i(1200,175);
glVertex2i(1100,175);

glVertex2i(1230,165);          //roadline-9
glVertex2i(1270,165);
glVertex2i(1270,175);
glVertex2i(1230,175);



glEnd();



glPushMatrix();

glTranslatef(tri, 0.0, 0.0);

glColor3ub(210,180,140);    //Jeep

    glBegin(GL_TRIANGLES);      //Jeep

    glVertex2i(290,170);
    glVertex2i(270,220);
    glVertex2i(270,175);

    glEnd();

    glBegin(GL_QUADS);



    glVertex2i(100,130);
    glVertex2i(130,130);
    glVertex2i(130,220);
    glVertex2i(100,220);

    glVertex2i(130,130);        //Tire Cut 1
    glVertex2i(150,150);
    glVertex2i(150,220);
    glVertex2i(130,220);

    glVertex2i(150,150);
    glVertex2i(180,150);
    glVertex2i(180,220);
    glVertex2i(150,220);

    glVertex2i(180,150);
    glVertex2i(200,130);       //Tire Cut 1
    glVertex2i(200,220);
    glVertex2i(180,220);


    glVertex2i(200,130);
    glVertex2i(270,130);
    glVertex2i(270,220);
    glVertex2i(200,220);

    glVertex2i(270,130);       //Tire Cut 2
    glVertex2i(290,150);
    glVertex2i(290,185);
    glVertex2i(270,190);

    glVertex2i(290,150);
    glVertex2i(320,150);
    glVertex2i(320,180);
    glVertex2i(290,185);

    glVertex2i(320,150);       //Tire Cut 2
    glVertex2i(340,130);
    glVertex2i(340,175);
    glVertex2i(320,180);


    glVertex2i(340,130);
    glVertex2i(360,130);
    glVertex2i(360,170);
    glVertex2i(340,175);


    glColor3ub(229,203,144);

    glVertex2i(210,135);           // Door
    glVertex2i(265,135);
    glVertex2i(265,215);
    glVertex2i(210,215);

    glColor3ub(8, 69, 112);
    glVertex2i(215,180);           // Door Window
    glVertex2i(260,180);
    glVertex2i(260,210);
    glVertex2i(215,210);




    glVertex2i(140,180);
    glVertex2i(190,180);
    glVertex2i(190,210);
    glVertex2i(140,210);




    glEnd();


    glPushMatrix();

    glTranslatef(0,0,0.0);

    glBegin(GL_POLYGON);
    glColor3ub(104, 110, 105);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(165+cos(angle)*30,135+sin(angle)*25);
    }

    glEnd();

    glPopMatrix();


    glPushMatrix();

    glTranslatef(0,0,0.0);

    glBegin(GL_POLYGON);
    glColor3ub(31, 36, 32);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(165+cos(angle)*19,135+sin(angle)*17);
    }

    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0,0.0);

    glBegin(GL_POLYGON);
    glColor3ub(153, 144, 95);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(165+cos(angle)*9,135+sin(angle)*9);
    }

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0.0);

    glBegin(GL_POLYGON);
    glColor3ub(104, 110, 105);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*30,135+sin(angle)*25);
    }

    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0,0.0);


    glBegin(GL_POLYGON);
    glColor3ub(31, 36, 32);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*19,135+sin(angle)*17);
    }

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0.0);

    glBegin(GL_POLYGON);
    glColor3ub(153, 144, 95);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*9,135+sin(angle)*9);
    }

    glEnd();

    glPopMatrix();


    glBegin(GL_QUADS);

    glVertex2i(205,170);
    glVertex2i(220,170);
    glVertex2i(220,175);
    glVertex2i(205,175);

    glEnd();


    glBegin(GL_QUADS);

    glVertex2i(100,175);
    glVertex2i(110,175);
    glVertex2i(110,220);
    glVertex2i(100,220);

    glEnd();



    glBegin(GL_QUADS);

    glVertex2i(122,155);
    glVertex2i(132,155);
    glVertex2i(132,165);
    glVertex2i(122,165);


    glEnd();


    glPopMatrix();



glBegin(GL_QUADS);
glColor3ub(99,91,91);  //border from tower to fence
glVertex2i(330,500);
glVertex2i(300,250);
glVertex2i(310,250);
glVertex2i(340,500);
glEnd();


glBegin(GL_QUADS);
glColor3ub(5,179,20);  //playground

glVertex2i(0,250);
glVertex2i(300,250);
glVertex2i(330,500);
glVertex2i(0,500);
glEnd();

glBegin(GL_QUADS);
glColor3ub(99,91,91);
glVertex2i(0,500);
glVertex2i(0,490);
glVertex2i(330,490);
glVertex2i(330,500);
glEnd();

glBegin(GL_LINES);

glColor3ub(99,91,91);

glVertex2i(165,490);
glVertex2i(130,250);


glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(181,181,181);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(148+cos(angle)*40,380+sin(angle)*20);
    }

    glEnd();


glBegin(GL_QUADS);      //fence     fence
glColor3ub(0,0,0);
glVertex2i(0,250);
glVertex2i(1300,250);
glVertex2i(1300,257);
glVertex2i(0,257);

glVertex2i(0,290);
glVertex2i(1300,290);
glVertex2i(1300,295);
glVertex2i(0,295);

glVertex2i(25,310);
glVertex2i(25,250);
glVertex2i(30,250);
glVertex2i(30,310);

glVertex2i(40,310);
glVertex2i(40,250);
glVertex2i(45,250);
glVertex2i(45,310);

glVertex2i(55,310);
glVertex2i(55,250);
glVertex2i(60,250);
glVertex2i(60,310);

glVertex2i(70,310);
glVertex2i(70,250);
glVertex2i(75,250);
glVertex2i(75,310);

glVertex2i(85,310);
glVertex2i(85,250);
glVertex2i(90,250);
glVertex2i(90,310);

glVertex2i(100,310);
glVertex2i(100,250);
glVertex2i(105,250);
glVertex2i(105,310);

glVertex2i(115,310);
glVertex2i(115,250);
glVertex2i(120,250);
glVertex2i(120,310);

glVertex2i(130,310);
glVertex2i(130,250);
glVertex2i(135,250);
glVertex2i(135,310);

glVertex2i(145,310);
glVertex2i(145,250);
glVertex2i(150,250);
glVertex2i(150,310);

glVertex2i(160,310);
glVertex2i(160,250);
glVertex2i(165,250);
glVertex2i(165,310);

glVertex2i(175,310);
glVertex2i(175,250);
glVertex2i(180,250);
glVertex2i(180,310);

glVertex2i(190,310);
glVertex2i(190,250);
glVertex2i(195,250);
glVertex2i(195,310);

glVertex2i(205,310);
glVertex2i(205,250);
glVertex2i(210,250);
glVertex2i(210,310);

glVertex2i(220,310);
glVertex2i(220,250);
glVertex2i(225,250);
glVertex2i(225,310);

glVertex2i(235,310);
glVertex2i(235,250);
glVertex2i(240,250);
glVertex2i(240,310);

glVertex2i(250,310);
glVertex2i(250,250);
glVertex2i(255,250);
glVertex2i(255,310);

glVertex2i(265,310);
glVertex2i(265,250);
glVertex2i(270,250);
glVertex2i(270,310);

glVertex2i(280,310);
glVertex2i(280,250);
glVertex2i(285,250);
glVertex2i(285,310);

glVertex2i(295,310);
glVertex2i(295,250);
glVertex2i(300,250);
glVertex2i(300,310);

glVertex2i(310,310);
glVertex2i(310,250);
glVertex2i(315,250);
glVertex2i(315,310);

glVertex2i(325,310);
glVertex2i(325,250);
glVertex2i(330,250);
glVertex2i(330,310);

glVertex2i(340,310);
glVertex2i(340,250);
glVertex2i(345,250);
glVertex2i(345,310);

glVertex2i(355,310);
glVertex2i(355,250);
glVertex2i(360,250);
glVertex2i(360,310);

glVertex2i(370,310);
glVertex2i(370,250);
glVertex2i(375,250);
glVertex2i(375,310);

glVertex2i(385,310);
glVertex2i(385,250);
glVertex2i(390,250);
glVertex2i(390,310);

glVertex2i(400,310);
glVertex2i(400,250);
glVertex2i(405,250);
glVertex2i(405,310);

glVertex2i(415,310);
glVertex2i(415,250);
glVertex2i(420,250);
glVertex2i(420,310);

glVertex2i(430,310);
glVertex2i(430,250);
glVertex2i(435,250);
glVertex2i(435,310);

glVertex2i(445,310);
glVertex2i(445,250);
glVertex2i(450,250);
glVertex2i(450,310);

glVertex2i(460,310);
glVertex2i(460,250);
glVertex2i(465,250);
glVertex2i(465,310);

glVertex2i(475,310);
glVertex2i(475,250);
glVertex2i(480,250);
glVertex2i(480,310);

glVertex2i(490,310);
glVertex2i(490,250);
glVertex2i(495,250);
glVertex2i(495,310);

glVertex2i(505,310);
glVertex2i(505,250);
glVertex2i(510,250);
glVertex2i(510,310);

glVertex2i(520,310);
glVertex2i(520,250);
glVertex2i(525,250);
glVertex2i(525,310);

glVertex2i(535,310);
glVertex2i(535,250);
glVertex2i(540,250);
glVertex2i(540,310);

glVertex2i(550,310);
glVertex2i(550,250);
glVertex2i(555,250);
glVertex2i(555,310);

glVertex2i(565,310);
glVertex2i(565,250);
glVertex2i(570,250);
glVertex2i(570,310);

glVertex2i(580,310);
glVertex2i(580,250);
glVertex2i(585,250);
glVertex2i(585,310);

glVertex2i(595,310);
glVertex2i(595,250);
glVertex2i(600,250);
glVertex2i(600,310);

glVertex2i(610,310);
glVertex2i(610,250);
glVertex2i(615,250);
glVertex2i(615,310);

glVertex2i(625,310);
glVertex2i(625,250);
glVertex2i(630,250);
glVertex2i(630,310);

glVertex2i(640,310);
glVertex2i(640,250);
glVertex2i(645,250);
glVertex2i(645,310);

glVertex2i(655,310);
glVertex2i(655,250);
glVertex2i(660,250);
glVertex2i(660,310);

glVertex2i(670,310);
glVertex2i(670,250);
glVertex2i(675,250);
glVertex2i(675,310);

glVertex2i(685,310);
glVertex2i(685,250);
glVertex2i(690,250);
glVertex2i(690,310);

glVertex2i(700,310);
glVertex2i(700,250);
glVertex2i(705,250);
glVertex2i(705,310);

glVertex2i(715,310);
glVertex2i(715,250);
glVertex2i(720,250);
glVertex2i(720,310);

glVertex2i(730,310);
glVertex2i(730,250);
glVertex2i(735,250);
glVertex2i(735,310);

glVertex2i(745,310);
glVertex2i(745,250);
glVertex2i(750,250);
glVertex2i(750,310);

glVertex2i(760,310);
glVertex2i(760,250);
glVertex2i(765,250);
glVertex2i(765,310);

glVertex2i(775,310);
glVertex2i(775,250);
glVertex2i(780,250);
glVertex2i(780,310);

glVertex2i(790,310);
glVertex2i(790,250);
glVertex2i(795,250);
glVertex2i(795,310);

glVertex2i(805,310);
glVertex2i(805,250);
glVertex2i(810,250);
glVertex2i(810,310);

glVertex2i(820,310);
glVertex2i(820,250);
glVertex2i(825,250);
glVertex2i(825,310);

glVertex2i(835,310);
glVertex2i(835,250);
glVertex2i(840,250);
glVertex2i(840,310);

glVertex2i(850,310);
glVertex2i(850,250);
glVertex2i(855,250);
glVertex2i(855,310);

glVertex2i(865,310);
glVertex2i(865,250);
glVertex2i(870,250);
glVertex2i(870,310);

glVertex2i(880,310);
glVertex2i(880,250);
glVertex2i(885,250);
glVertex2i(885,310);

glVertex2i(895,310);
glVertex2i(895,250);
glVertex2i(900,250);
glVertex2i(900,310);

glVertex2i(910,310);
glVertex2i(910,250);
glVertex2i(915,250);
glVertex2i(915,310);

glVertex2i(925,310);
glVertex2i(925,250);
glVertex2i(930,250);
glVertex2i(930,310);

glVertex2i(940,310);
glVertex2i(940,250);
glVertex2i(945,250);
glVertex2i(945,310);

glVertex2i(955,310);
glVertex2i(955,250);
glVertex2i(960,250);
glVertex2i(960,310);

glVertex2i(970,310);
glVertex2i(970,250);
glVertex2i(975,250);
glVertex2i(975,310);

glVertex2i(985,310);
glVertex2i(985,250);
glVertex2i(990,250);
glVertex2i(990,310);

glVertex2i(1000,310);
glVertex2i(1000,250);
glVertex2i(1005,250);
glVertex2i(1005,310);

glVertex2i(1015,310);
glVertex2i(1015,250);
glVertex2i(1020,250);
glVertex2i(1020,310);

glVertex2i(1030,310);
glVertex2i(1030,250);
glVertex2i(1035,250);
glVertex2i(1035,310);

glVertex2i(1045,310);
glVertex2i(1045,250);
glVertex2i(1050,250);
glVertex2i(1050,310);

glVertex2i(1060,310);
glVertex2i(1060,250);
glVertex2i(1065,250);
glVertex2i(1065,310);

glVertex2i(1075,310);
glVertex2i(1075,250);
glVertex2i(1080,250);
glVertex2i(1080,310);

glVertex2i(1090,310);
glVertex2i(1090,250);
glVertex2i(1095,250);
glVertex2i(1095,310);

glVertex2i(1105,310);
glVertex2i(1105,250);
glVertex2i(1110,250);
glVertex2i(1110,310);

glVertex2i(1120,310);
glVertex2i(1120,250);
glVertex2i(1125,250);
glVertex2i(1125,310);

glVertex2i(1135,310);
glVertex2i(1135,250);
glVertex2i(1140,250);
glVertex2i(1140,310);

glVertex2i(1150,310);
glVertex2i(1150,250);
glVertex2i(1155,250);
glVertex2i(1155,310);

glVertex2i(1165,310);
glVertex2i(1165,250);
glVertex2i(1170,250);
glVertex2i(1170,310);

glVertex2i(1185,310);
glVertex2i(1185,250);
glVertex2i(1190,250);
glVertex2i(1190,310);

glVertex2i(1200,310);
glVertex2i(1200,250);
glVertex2i(1205,250);
glVertex2i(1205,310);

glVertex2i(1215,310);
glVertex2i(1215,250);
glVertex2i(1220,250);
glVertex2i(1220,310);

glVertex2i(1230,310);
glVertex2i(1230,250);
glVertex2i(1235,250);
glVertex2i(1235,310);

glVertex2i(1245,310);
glVertex2i(1245,250);
glVertex2i(1250,250);
glVertex2i(1250,310);

glVertex2i(1260,310);
glVertex2i(1260,250);
glVertex2i(1265,250);
glVertex2i(1265,310);

glVertex2i(1275,310);
glVertex2i(1275,250);
glVertex2i(1280,250);
glVertex2i(1280,310);

glVertex2i(1290,310);
glVertex2i(1290,250);
glVertex2i(1295,250);
glVertex2i(1295,310);

glEnd();

glBegin(GL_QUADS);

glColor3ub(176,31,2);
glVertex2i(0,0);                   //bridgep
glVertex2i(20,0);
glVertex2i(20,350);
glVertex2i(0,350);

glVertex2i(1280,0);               //bridgep
glVertex2i(1300,0);
glVertex2i(1300,350);
glVertex2i(1280,350);

glVertex2i(670,410);
glVertex2i(670,230);              //midp-1
glVertex2i(685,230);
glVertex2i(685,410);

glVertex2i(580,360);
glVertex2i(580,100);             //midp-2
glVertex2i(595,100);
glVertex2i(595,360);

glVertex2i(580,360);
glVertex2i(670,410);             //midjoint
glVertex2i(685,410);
glVertex2i(595,360);
glEnd();

glBegin(GL_LINES);
glColor3ub(78, 153, 103);
glVertex2i(20,100);
glVertex2i(580,360);    //line
glVertex2i(670,410);
glVertex2i(20,230);

glBegin(GL_LINES);
glVertex2i(1280,230);
glVertex2i(685,410);      //line
glVertex2i(1280,100);
glVertex2i(595,360);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(224, 11, 22);         //b-head
glVertex2i(0,370);
glVertex2i(20,370);
glVertex2i(10,400);

glVertex2i(1280,370);
glVertex2i(1300,370);
glVertex2i(1290,400);
glEnd();

//b-head2

glBegin(GL_QUADS);
glColor3ub(43, 27, 28);
//glVertex2i(20,370);
glVertex2i(5,350);
glVertex2i(15,350);
glVertex2i(20,370);
glVertex2i(0,370);

glVertex2i(1285,350);
glVertex2i(1295,350);
glVertex2i(1300,370);
glVertex2i(1280,370);
glEnd();


glPushMatrix();

glTranslatef(run, 0.0, 0.0);

glBegin(GL_QUADS);   //gun boat lower part
glColor3ub (56,56,52);
glVertex2i(350,10);
glVertex2i(410,60);
glVertex2i(40,35);
glVertex2i(50,10);
glEnd();


glBegin(GL_QUADS);   //lower upper part
glColor3ub(132,132,130);
glVertex2i(60,35);
glVertex2i(257,47);
glVertex2i(250,70);
glVertex2i(65,55);
glEnd();

glBegin(GL_QUADS);    //middle upper part
glColor3ub(92,92,88);
glVertex2i(250,47);
glVertex2i(275,50);
glVertex2i(270,62);
glVertex2i(250,60);
glEnd();

glBegin(GL_QUADS);   //upper part
glColor3ub(69,69,68);
glVertex2i(90,55);
glVertex2i(200,60);
glVertex2i(180,90);
glVertex2i(95,80);
glEnd();

glBegin(GL_QUADS);   //bridge covering part
glColor3ub(69,69,68);
glVertex2i(110,80);
glVertex2i(180,75);
glVertex2i(160,110);
glVertex2i(115,100);
glEnd();


glBegin(GL_QUADS);    //gun
glColor3ub(54,54,54);
glVertex2i(187,80);
glVertex2i(240,100);
glVertex2i(235,105);
glVertex2i(183,85);
glEnd();



glPopMatrix();

//sun

glBegin(GL_POLYGON);
glColor3ub(230, 219, 18);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(700+cos(angle)*25,615+sin(angle)*25);

    }
    glEnd();


    //extrapart

    glPushMatrix();
    glTranslatef(run1, 0.0, 0.0);

    glBegin(GL_POLYGON);        //Cloud 1
    glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(500+cos(angle)*15,615+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(510+cos(angle)*15,625+sin(angle)*10);
    }

    for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(520+cos(angle)*15,605+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(532+cos(angle)*15,630+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
         glVertex2f(545+cos(angle)*15,615+sin(angle)*10);
    }

    glEnd();

    glPopMatrix();


glPushMatrix();

glTranslatef(run2, 0.0, 0.0);                                //cloud-2

glBegin(GL_POLYGON);
glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(100+cos(angle)*15,615+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(110+cos(angle)*15,625+sin(angle)*10);
    }



     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(120+cos(angle)*15,605+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(132+cos(angle)*15,630+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(142+cos(angle)*15,615+sin(angle)*10);
    }

    glEnd();

    glPopMatrix();


    //cloud-3

glPushMatrix();

glTranslatef(run3, 0.0, 0.0);

glBegin(GL_POLYGON);
glColor3ub(232, 230, 225);

  for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1000+cos(angle)*15,615+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1010+cos(angle)*15,625+sin(angle)*10);
    }



     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1020+cos(angle)*15,605+sin(angle)*10);
    }

     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1032+cos(angle)*15,630+sin(angle)*10);
    }


     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1042+cos(angle)*15,615+sin(angle)*10);
    }

    glEnd();


    //cloud-3
glPopMatrix();





    glBegin(GL_QUADS);      //Helicopter

    glColor3ub(181,181,181);        //base quad

    glVertex2i(1040,380);
    glVertex2i(1090,380);
    glVertex2i(1090,400);
    glVertex2i(1030,400);

    glVertex2i(1080,400);
    glVertex2i(1090,400);
    glVertex2i(1090,425);
    glVertex2i(1080,425);


    glVertex2i(1045,425);
    glVertex2i(1090,425);
    glVertex2i(1090,435);
    glVertex2i(1065,435);

    glColor3ub(128,166,163);     //Front

    glVertex2i(1030,400);
    glVertex2i(1080,400);
    glVertex2i(1080,425);
    glVertex2i(1045,425);


    glColor3ub(190,0,0);

    glVertex2i(1090,380);
    glVertex2i(1150,380);
    glVertex2i(1150,415);
    glVertex2i(1090,435);


    glColor3ub(128,166,163);      //Door

    glVertex2i(1088,385);
    glVertex2i(1115,385);
    glVertex2i(1115,420);
    glVertex2i(1088,420);

    glVertex2i(1122,395);       //Window
    glVertex2i(1132,395);
    glVertex2i(1132,410);
    glVertex2i(1122,410);

    glVertex2i(1137,395);       //Window
    glVertex2i(1147,395);
    glVertex2i(1147,410);
    glVertex2i(1137,410);



    glColor3ub(181,181,181);


    glVertex2i(1150,415);
    glVertex2i(1150,380);
    glVertex2i(1190,390);
    glVertex2i(1190,400);


    glColor3ub(181,181,181);      //Rear Blade

    glVertex2i(1188,390);
    glVertex2i(1198,390);
    glVertex2i(1208,420);
    glVertex2i(1190,420);

    glColor3ub(181,181,181);     //Top

    glVertex2i(1070,435);
    glVertex2i(1085,435);
    glVertex2i(1082,440);
    glVertex2i(1073,440);


    glVertex2i(1075,440);
    glVertex2i(1079,440);
    glVertex2i(1079,450);
    glVertex2i(1075,450);

    glEnd();



    glBegin(GL_QUADS);      //Top Blades

    glColor3ub(99,96,96);     //Top

    glVertex2i(1077,450);
    glVertex2i(1170,435);
    glVertex2i(1165,450);
    glVertex2i(1077,452);


    glVertex2i(1077,452);
    glVertex2i(1077,450);
    glVertex2i(989,435);
    glVertex2i(984,450);


    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(1077+cos(angle)*5,450+sin(angle)*5);
    }

    glEnd();



    glBegin(GL_QUADS);      //Landing Stand

    glColor3ub(99,96,96);

    glVertex2i(1065,365);       //1
    glVertex2i(1070,365);
    glVertex2i(1070,380);
    glVertex2i(1065,380);


    glVertex2i(1125,365);
    glVertex2i(1130,365);
    glVertex2i(1130,380);
    glVertex2i(1125,380);


    glVertex2i(1055,360);
    glVertex2i(1140,360);
    glVertex2i(1140,365);
    glVertex2i(1055,365);


    glVertex2i(1075,355);        //2
    glVertex2i(1080,355);
    glVertex2i(1080,380);
    glVertex2i(1075,380);


    glVertex2i(1135,355);
    glVertex2i(1140,355);
    glVertex2i(1140,380);
    glVertex2i(1135,380);


    glVertex2i(1065,350);
    glVertex2i(1150,350);
    glVertex2i(1150,355);
    glVertex2i(1065,355);


    glEnd();





glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 0.5, 0.8, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1300.0, 0.0, 650.0);

}




int main(int argc, char** argv)
{

    /*         COMPUTER GRAPHICS [J]
        Project Submission [ Summer 2020-2021 ]

         Submitted To : ANEEM AL AHSAN RUPAI

         Submitted By : MD. SIBBIR HOSSAIN
                ID    : 18-38828-3
    */


    cout << endl << "*********** Military Base Camp ********************" << endl << endl;

    cout << "Press D : To Forward the Jeep" << endl << endl;
    cout << "Press A : To Backward the Jeep" << endl << endl;
    cout << "Press S : To Stop the Jeep" << endl << endl;

    cout << "Press R : For Rain" << endl << endl;
    cout << "Press T : To Stop The Rain" << endl << endl;

    cout << "Press N : For Night Mode" << endl << endl;
    cout << "Press B : For Day Mode" << endl << endl<<endl;



    cout << "          COMPUTER GRAPHICS [J]           " << endl ;
    cout << "  Project Submission [ Summer 2020-2021 ]" << endl << endl;
    cout << "Submitted To : ANEEM AL AHSAN RUPAI" << endl << endl;
    cout << "Submitted By : MD. SIBBIR HOSSAIN" << endl ;
    cout << "ID           : 18-38828-3" << endl << endl<< endl;
    cout << "        Thank you!" << endl << endl;



glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize (1300, 650);
glutInitWindowPosition (10, 10);
glutCreateWindow ("Military Base Camp");
glutDisplayFunc(myDisplay);
glutKeyboardFunc(myKeyboard);
glutTimerFunc(25, update, 0);
myInit ();
glutMainLoop();
return 0;
}
