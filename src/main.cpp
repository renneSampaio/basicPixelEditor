#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Bitmap.hpp"
#include "Tool.hpp"
#include "PenTool.hpp"
#include "LineTool.hpp"
#include "RectTool.hpp"
#include "CircleTool.hpp"
#include "PolyTool.hpp"

Bitmap image(32,32);
Tool* currentTool;

const int PIXEL_SIZE = 10;

Pixel mainColor = 0x000000FF;
Pixel secondaryColor = 0xFFFFFFFF;

void draw();
void keyboardInput(unsigned char key, int x, int y);
void mouseInput(int button, int state, int x, int y);
void mouseMotionInput(int x, int y);

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(image.getWidth() * PIXEL_SIZE, image.getHeight() * PIXEL_SIZE);
    glutCreateWindow("Image Editor");

    glewInit();

    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboardInput);
    glutMouseFunc(mouseInput);
    glutMotionFunc(mouseMotionInput);

    image.clear(0xFFFFFFFF);

    currentTool = new PolyTool(image, mainColor, secondaryColor);

    glClearColor(0,0,0,1);
    glutMainLoop();
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    image.draw();

    glutSwapBuffers();
    glutPostRedisplay();
}

void keyboardInput(unsigned char key, int x, int y)
{
    x /= PIXEL_SIZE;
    y /= PIXEL_SIZE;

    switch(key) 
    {
        case 'c':
        case 'C':
            image.clear(0xFFFFFFFF);
            break;
        case 'p':
            delete currentTool;
            currentTool = new PenTool(image, mainColor, secondaryColor);
            break;
        case 'l':
            delete currentTool;
            currentTool = new LineTool(image, mainColor, secondaryColor);
            break;
        case 's':
            delete currentTool;
            currentTool = new CircleTool(image, mainColor, secondaryColor);
            break;
        case 'y':
            delete currentTool;
            currentTool = new PolyTool(image, mainColor, secondaryColor);
            break;
        case 'r':
            delete currentTool;
            currentTool = new RectTool(image, mainColor, secondaryColor);
            break;
        default:
            currentTool->getKeyboardInput(key, x, y);
    }
}

void mouseInput(int button, int state, int x, int y)
{
    x /= PIXEL_SIZE;
    y /= PIXEL_SIZE;

    currentTool->getMouseInput(button, state, x, y);
}

void mouseMotionInput(int x, int y)
{
    currentTool->getMouseMotionInput(x,y);
}
