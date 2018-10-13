//Hannah Posch
//Tech Foundations II
//Assignment 01

//Include statements
#include <cstdio>
#include <iostream>
#include <string>


#ifdef __APPLE__
#  pragma clang diagnostic ignored "-Wdeprecated-declarations"
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

using namespace std;

//Input variables from user
char plantLetter = 'D';
int recur = 1;

//Initial variables Plant A
float colorRp1 = 0.00;
float colorGp1 = 1.00;
float colorBp1 = 0.50;
int colorCountp1 = 0;
int berrySize = 2;

//Initial variables Plant B
float colorRp2 = 0.80;
float colorGp2 = 0.90;
float colorBp2 = 0.50;
int colorCountp2 = 0;
int cylCountp2 = 0;
float cylSizep2 = 2.00;
int coneSizep2 = 3;
int drawConeNum = 1;
int podCount = 0;
int heightCylp2 = 10;

//Initial variables Plant C
float colorRp3 = 0.70;
float colorGp3 = 0.50;
float colorBp3 = 1.00;
int colorCountp3 = 0;
float cylSizep3 = 4.0;
float cylSize2p3 = 2.0;

//Init function
void init()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    double aspect = (double)viewport[2] / (double)viewport[3];
    gluPerspective(60, aspect, 1, 500);
    gluLookAt(0, 0, 500, 0, 0, 0, 0, 1, 0);
    
    glMatrixMode(GL_MODELVIEW);
    
}

//Turn left
void turnLeft(){
    
    if(plantLetter=='A' || plantLetter == 'a'){
        glRotatef(25.7,0.0,1.0,0.0);
    }
    if(plantLetter=='B' || plantLetter == 'b'){
        glRotatef(22.5,0.0,1.0,0.0);
    }
    if(plantLetter=='C' || plantLetter == 'c'){
        glRotatef(22.5,0.0,1.0,0.0);
    }
    glTranslatef(-4.75,0,0);
    
}

//Turn right
void turnRight(){
    if(plantLetter=='A' || plantLetter == 'a'){
        glRotatef(-25.7,0.0,1.0,0.0);
    }
    if(plantLetter=='B' || plantLetter == 'b'){
        glRotatef(-22.5,0.0,1.0,0.0);
    }
    if(plantLetter=='C' || plantLetter == 'c'){
        glRotatef(-22.5,0.0,1.0,0.0);
    }
    glTranslatef(4.75,0,0);
    
}
//Save current position
void savePos(){
    glPushMatrix();
}

//Restore previous position
void restorePos(){
    glPopMatrix();
}

//Draw Plant A berries
void drawBerryp1(){
    glColor3f(1.0, 1.0, colorBp1);
    glutSolidSphere(berrySize,15,15);
    berrySize++;
    if(berrySize == 4){
        berrySize = 1;
    }
    
}
//Draw Plant B cones and spheres
void drawConep2(){
    glColor3f(colorRp2, colorGp2, colorBp2);
    if(podCount < 4){
        for(int i =0; i<10;i++){
            glRotatef(36,0.0,1.0,0.0);
            glutSolidSphere(2,15,15);
            glutSolidCone((coneSizep2+2), (coneSizep2+2),15, 15);
        }
    }
    coneSizep2++;
    podCount++;
    if(podCount == 8){
        podCount=0;
    }
    if(coneSizep2 ==6){
        coneSizep2 = 3;
    }
}

//Draw Plant C sphere tops
void drawTopsp3(){
    glColor3f(0.9,0.7,0.4);
    glutSolidSphere((cylSizep3),15,15);
}

//Draw Plant C flowers
void drawFlowerp3(){
    glColor3f(0.7,0.5,0.8);
    glutSolidSphere((cylSizep3),15,15);
    glTranslatef(0,0,(cylSizep3));
    glutSolidSphere((cylSizep3),15,15);
    glTranslatef(0,0,-(cylSizep3));
    glColor3f(0.5,0.5,1.0);
    for(int i =0; i < 10; i++){
        glRotatef(36,0.0,1.0,0.0);
        GLUquadricObj *r = gluNewQuadric();
        gluQuadricDrawStyle(r, GLU_FILL);
        gluCylinder(r, 2, 0.5, 8, 15, 15 );
    }
}

//Draw base of plant
void drawBase(){
    
    if (plantLetter =='A' || plantLetter == 'a'){
        glColor3f(colorRp1, colorGp2, colorBp1);
        glRotatef(90, 1.0, 0.0, 0.0);
        glTranslatef(0,0,100);
        GLUquadricObj *p = gluNewQuadric();
        gluQuadricDrawStyle(p, GLU_FILL);
        gluCylinder(p, 1, 1, 10, 15, 15 );
        glutSolidSphere(1,15,15);
    }
    if(plantLetter=='B' || plantLetter == 'b'){
        glColor3f(colorRp2, colorGp2, colorBp2);
        glRotatef(90, 1.0, 0.0, 0.0);
        glTranslatef(0,0,250);
        GLUquadricObj *p = gluNewQuadric();
        gluQuadricDrawStyle(p, GLU_FILL);
        gluCylinder(p, cylSizep2, cylSizep2, 10, 15, 15 );
        glutSolidSphere(cylSizep2,15,15);
    }
    if(plantLetter=='C' || plantLetter == 'c'){
        glColor3f(colorRp3, colorGp3, colorBp3);
        glRotatef(90, 1.0, 0.0, 0.0);
        glTranslatef(0,0,250);
        GLUquadricObj *p = gluNewQuadric();
        gluQuadricDrawStyle(p, GLU_FILL);
        gluCylinder(p, cylSizep3, cylSizep3, 10, 15, 15 );
        glutSolidSphere(cylSizep3,15,15);
    }
    glTranslatef(0,0,-9.5);
}

//Draw additional cylinders - Plant A
void drawForwardp1(){
    
    if (colorCountp1 < 150){
        colorRp1 += 0.001;
        colorGp1 -= 0.002;
        colorBp1 += 0.002;
        colorCountp1++;
    }
    if (colorCountp1 >= 150 && colorCountp1 < 350){
        colorRp1 -= 0.001;
        colorGp1 += 0.002;
        colorBp1 -= 0.002;
        colorCountp1++;
    }
    if (colorCountp1 >= 350 && colorCountp1 < 450){
        colorRp1 += 0.001;
        colorGp1 -= 0.002;
        colorBp1 += 0.002;
        colorCountp1++;
    }
    if (colorCountp1 > 449 && colorCountp1 < 1000){
        colorRp1 += 0.002;
        colorGp1 -= 0.001;
        colorBp1 += 0.002;
        colorCountp1++;
    }
    glColor3f(colorRp1, colorGp1, colorBp1);
    GLUquadricObj *p = gluNewQuadric();
    gluQuadricDrawStyle(p, GLU_FILL);
    gluCylinder(p, 1, 1, 10, 15, 15 );
    glutSolidSphere(1,15,15);
    glTranslatef(0,0,-9.5);
}

//Draw additional cylinders - Plant B
void drawForwardp2(){
    
    if(colorCountp2==3){
        colorRp2 -= 0.0001;
        colorGp2 -= 0.0001;
        colorBp2 += 0.0001;
        colorCountp2 = 0;
    }
    if(colorRp2 != 1.0){
        colorRp2 = colorRp2 + 0.000005;
    }
    if(colorGp2 != 1.0){
        colorGp2 = colorGp2 + 0.000005;
    }
    if(colorBp2 != 1.0){
        colorBp2 = colorBp2 + 0.000005;
    }
    
    glColor3f(colorRp2, colorGp2, colorBp2);
    GLUquadricObj *p = gluNewQuadric();
    gluQuadricDrawStyle(p, GLU_FILL);
    gluCylinder(p, cylSizep2, (cylSizep2 - 0.25), heightCylp2, 15, 15 );
    glutSolidSphere(cylSizep2,15,15);
    
    glTranslatef(0,0,-(heightCylp2 - 0.5));
    
    if(cylCountp2 == 5000){
        if (cylCountp2 != 0.5){
            cylSizep2 = cylSizep2 - 0.5;
            cylCountp2 = 0;
            heightCylp2 = heightCylp2 - 0.5;
        }
    }
    
    cylCountp2++;
    colorCountp2++;
    
}

//Draw additional cylinders - Plant C
void drawForwardp3(){
    
    
    colorGp3 += 0.001;
    colorBp3 += 0.001;
    
    glColor3f(colorRp3, colorGp3, colorBp3);
    GLUquadricObj *p = gluNewQuadric();
    gluQuadricDrawStyle(p, GLU_FILL);
    gluCylinder(p, cylSizep3, cylSize2p3, 10, 15, 15 );
    drawTopsp3();
    
    glTranslatef(0,0,-9.5);
    
    cylSizep3 = cylSizep3 - 0.004;
    cylSize2p3 = cylSize2p3 - 0.004;
    
}

//Plant A Grammar Rule
void grammarRulep1(){
    string current = "F";
    string next = "";
    int count = 0;
    
    while(count<recur){
        for(int i = 0; i<current.length(); i++){
            char c = current.at(i);
            if (c =='F'){
                next += "F[RF]F[LF][F]";
            }
            if (c != 'F'){
                next += c;
            }
        }
        current = next;
        count++;
        next = "";
    }
    for(int i=0; i<current.length(); i++){
        char c = current.at(i);
        if(c=='F'){
            if (i == 0){
                drawBase();
            }
            if (i > 0){
                drawForwardp1();
            }
        }
        else if(c=='R'){
            turnRight();
        }
        else if(c=='L'){
            turnLeft();
        }
        else if(c=='['){
            savePos();
            drawBerryp1();
        }
        else if(c==']'){
            restorePos();
        }
    }
    
}

//Plant B Grammar Rule
void grammarRulep2(){
    string current = "F";
    string next = "";
    int count = 0;
    
    while(count<recur){
        for(int i = 0; i<current.length(); i++){
            char c = current.at(i);
            if (c =='F'){
                next += "FFL[LFRFFRF]R[RFFLFLFF]";
            }
            if (c != 'F'){
                next += c;
            }
        }
        current = next;
        count++;
        next = "";
    }
    for(int i=0; i<current.length(); i++){
        char c = current.at(i);
        if(c=='F'){
            if (i == 0){
                drawBase();
            }
            if (i > 0){
                drawForwardp2();
            }
        }
        else if(c=='R'){
            turnRight();
        }
        else if(c=='L'){
            turnLeft();
        }
        else if(c=='['){
            savePos();
            if(drawConeNum ==5){
                drawConep2();
                drawConeNum=1;
            }
            drawConeNum++;
        }
        else if(c==']'){
            restorePos();
        }
    }
    
}

//Plant C Grammar Rule
void grammarRulep3(){
    string current = "X";
    string next = "";
    int count = 0;
    
    while(count<recur){
        for(int i = 0; i<current.length(); i++){
            char c = current.at(i);
            if (c =='X'){
                next += "F[RX][LX]FX";
            }
            if( c =='F'){
                next += "FF";
            }
            if (c != 'F' && c != 'X'){
                next += c;
            }
        }
        current = next;
        count++;
        next = "";
    }
    for(int i=0; i<current.length(); i++){
        char c = current.at(i);
        if(c=='F'){
            if (i == 0){
                drawBase();
            }
            if (i > 0){
                drawForwardp3();
            }
        }
        else if(c=='R'){
            turnRight();
        }
        else if(c=='L'){
            turnLeft();
        }
        else if(c=='['){
            savePos();
        }
        else if(c==']'){
            drawFlowerp3();
            restorePos();
        }
    }
    
}
//Display function
void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    if(plantLetter == 'A' || plantLetter == 'a'){
        grammarRulep1();
    }
    if(plantLetter == 'B' || plantLetter == 'b'){
        grammarRulep2();
    }
    if(plantLetter == 'C' || plantLetter == 'c'){
        grammarRulep3();
    }
    
    glutSwapBuffers();
}

//Keyboard input to quit
void handleKeys(unsigned char key, int x, int y){
    switch(key){
        case 'q':		// q - quit
        case 'Q':
        case 27:		// esc - quit
            exit(0);
            
        default:		// not a valid key -- just ignore it
            return;
    }
}

//Main function
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(840,680);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Assignment 1 - Hposch");

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeys);
    
    cout << "Which plant would you like to display? A, B, C" << endl;
    cin >> plantLetter;
    cout << "How many recursions? 1, 2, 3, 4, 5" << endl;
    cin>>recur;

    init();

    glutMainLoop();
    return 0;
}
