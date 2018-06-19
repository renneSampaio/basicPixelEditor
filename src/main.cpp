#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Bitmap.hpp"

Bitmap image(32,32);

const int PIXEL_SIZE = 10;

void draw();

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(image.getWidth() * PIXEL_SIZE, image.getHeight() * PIXEL_SIZE);
    glutCreateWindow("Image Editor");

    glewInit();

    glutDisplayFunc(draw);

    glClearColor(0,0,0,1);

    image.clear(0x0000FFFF);

    glutMainLoop();
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    image.draw();

    glutSwapBuffers();
    glutPostRedisplay();
}
