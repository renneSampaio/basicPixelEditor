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
#include "FillTool.hpp"

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

void changeTool(Tool* newTool) {
    delete currentTool;
    currentTool = newTool;
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
            changeTool(new PenTool(image, mainColor, secondaryColor));
            break;
        case 'l':
            changeTool(new LineTool(image, mainColor, secondaryColor));
            break;
        case 's':
            changeTool(new CircleTool(image, mainColor, secondaryColor));
            break;
        case 'y':
            changeTool(new PolyTool(image, mainColor, secondaryColor));
            break;
        case 'r':
            changeTool(new RectTool(image, mainColor, secondaryColor));
            break;
        case 'f':
            changeTool(new FillTool(image, mainColor, secondaryColor));
            break;
	case 'h':
            std::cout << "Instructions:\n";
            std::cout << "-> 'c' - Clear image\n";
            std::cout << "-> 'p' - Pen Tool\n";
            std::cout << "         Left Click to set pixel with main color\n";
            std::cout << "         Right Click to set pixel with secondary color\n";
            std::cout << "-> 'l' - Line Tool\n";
            std::cout << "         Left Click to set start position\n";
            std::cout << "         Left Click again to set end position and draw line\n";
            std::cout << "         Right Click again to finish drawing lines\n";
            std::cout << "-> 'r' - Rect Tool\n";
            std::cout << "         Left Click to set first position\n";
            std::cout << "         Left Click again to set second position and draw circle\n";
            std::cout << "-> 'y' - Poly Tool\n";
            std::cout << "         Left Click to add positions to polygon\n";
            std::cout << "         Right Click to draw polygon (Only draws if there are more than 2 positions set)\n";
            std::cout << "-> 's' - Circle Tool\n";
            std::cout << "         Left Click to set center\n";
            std::cout << "         Left Click again to set radius and draw circle\n";
            std::cout << "-> 'f' - Fill Tool\n";
            std::cout << "         Left Click to fill area\n";
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
    x /= PIXEL_SIZE;
    y /= PIXEL_SIZE;
    
    currentTool->getMouseMotionInput(x,y);
}
