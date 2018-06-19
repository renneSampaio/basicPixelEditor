#include <iostream>
#include <algorithm>
#include <GL/gl.h>

#include "Bitmap.hpp"

Bitmap::Bitmap(int w, int h)
    :width(w), height(h)
{
    buffer.resize(width*height);
    rows.resize(height);

    //Initialize rows
    auto buffer_it = buffer.begin();
    for (int i = 0; i < height; ++i, buffer_it+=width)
    {
	rows[i] = &( *buffer_it );
    }
}

Bitmap::Bitmap(const Bitmap& other)
    :width(other.width), height(other.height)
{
    *this = other;
}

Bitmap& Bitmap::operator=(const Bitmap& other)
{
    if (this != &other)
    {
	height = other.height;
	width = other.width;

	buffer.resize(width * height);
	std::copy(other.buffer.begin(), other.buffer.end(), buffer.begin());

	auto buffer_it = buffer.begin();
	for (int i = 0; i < height; ++i, buffer_it += width)
	{
	    rows[i] = &( *buffer_it );
	}
    }
    return *this;
}

Bitmap::~Bitmap()
{
}

void Bitmap::clear(Pixel color)
{
    std::fill(buffer.begin(), buffer.end(), color);
}

Pixel Bitmap::getPixel(int x, int y) const
{
    return rows[y][x]; 
}

Pixel Bitmap::getPixelSafe(int x, int y) const
{
    if (x >= 0 && y >= 0 && x < width && y < height)
    {
	return getPixel(x, y);
    }

    return Pixel();
}

void Bitmap::setPixel(int x, int y, Pixel color)
{
    rows[y][x] = color;
}

void Bitmap::setPixelSafe(int x, int y, Pixel color)
{
    if (x >= 0 && y >= 0 && x < width && y < height)
    {
	setPixel(x, y, color);
    }
}

int Bitmap::getWidth() const
{
    return width;
}

int Bitmap::getHeight() const
{
    return height;
}

void Bitmap::setWidth(int newWidth)
{
    resize(newWidth, height);
}

void Bitmap::setHeight(int newHeight)
{
    resize(width, newHeight);
}

void Bitmap::resize(int newWidth, int newHeight)
{

}

void Bitmap::draw() const
{
    const float pw = 2.0/(float) width;
    const float ph = 2.0/(float) height;
    
    float py = 1.0 - ph;
    
    glBegin(GL_QUADS);
	for (int y = 0; y < height; y++, py -= ph)
	{
	    float px = -1.0;
	    for (int x = 0; x < width; x++, px += pw)
	    {
		Pixel color = getPixelSafe(x, y);
		glColor4ui(color.r, color.g, color.b, color.a);

		glVertex2f(px, py);
		glVertex2f(px+pw, py);
		glVertex2f(px+pw, py+ph);
		glVertex2f(px, py+ph);
	    }
	}
    glEnd();
}
