#include <iostream>
#include <math.h>
#include <sys/stat.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include "include/Square.h"
#include "include/Vector.h"
#include "include/Button.h"

static const int FPS = 60;
static int width;
static int height;

void reshape(int, int);
void display(void);
void updateFrame(int);
void init(void);
void mouseClick(int button, int state, int x, int y);
void mouseMovement(int x, int y);
GLuint texture;
static const Square* board[8][8];
Button<void, void>* button;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 900);
    glutCreateWindow("chess");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(mouseMovement);
    init();
    glutTimerFunc(100, updateFrame, 0);
    glutMainLoop();
    return 0;
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    ::width = width;
    ::height = height;
    float aspect = (float)width / (float)height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width <= height)
        glOrtho(-50.0, 50.0, -50.0/aspect, 50.0/aspect, -1.0, 1.0);
    else
        glOrtho(-50.0*aspect, 50.0*aspect, -50.0, 50.0, -1.0, 1.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.1f,0.1f,0.1f, 1.f);
    glLoadIdentity();
    // for (int i = 0; i < 8; i++)
    //     for (int j = 0; j < 8; j++)
    //         board[i][j]->render();

    // glColor4f(0.5, 0.3, 0.2, 0.5f);

    // glPushMatrix();
	//   glEnable(GL_TEXTURE_2D);
	//   glBindTexture(GL_TEXTURE_2D, texture);

	//   glBegin(GL_QUADS);
	    // glTexCoord2f(0.01, 0.5); glVertex3f(0, -32, 0);
	    // glTexCoord2f(0.15, 0.5); glVertex3f(8, -32, 0);  
	    // glTexCoord2f(0.15, 0);	 glVertex3f(8, -24, 0);
	    // glTexCoord2f(0.01, 0);	 glVertex3f(0, -24, 0);
	//   glEnd();
    //   

	//   glDisable(GL_TEXTURE_2D);
	// glPopMatrix();
    button->render();
    glFlush();
    glutSwapBuffers();
}

void mouseClick(int button, int state, int x, int y) {
    if (button != GLUT_LEFT_BUTTON) return;
    ::button->onClick(NULL);
}

void mouseMovement(int x, int y) {
    float aspect = (float)width / (float)height;
    float x1, y1;
    if (width <= height) {
        x1 = ((float)x/width)*100 - 50;
        y1 = (-((float)y/height)*100 + 50)/aspect;
    }
    else {
        x1 = (((float)x/width)*100 - 50)*aspect;
        y1 = (-((float)y/height)*100 + 50);
    }
    button->isMouseOn(x1, y1);
}

void updateFrame(int ) {
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, updateFrame, 0);
}

void init(void) {
    button = new Button<void, void>(0.f, 0.f, 14.f, 9.f, [](void*){std::cout<<"hello"<<std::endl;}, Vector4f({1, 0, 0, 1}), std::string("x"));
    texture = SOIL_load_OGL_texture("pieces.png", SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB);
    bool invertColor = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(8.f, -32.f + i * 8.f, -32.f + j * 8.f, invertColor? Vector4f({0, 0, 0, 1}) : Vector4f({0.5, 0.3, 0.2, 1}));
            invertColor = !invertColor;
        }
        invertColor = !invertColor;
    }
}