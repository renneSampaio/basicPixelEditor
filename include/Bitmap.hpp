#ifndef BITMAP_HEADER__
#define BITMAP_HEADER__

#include <vector>
#include "Pixel.hpp"

class Bitmap {
    public:
	Bitmap(int width, int height);
	~Bitmap();

	Bitmap(const Bitmap& other); //Copy constructor
//	Bitmap(Bitmap&& other); //Move constructor

	Bitmap& operator=(const Bitmap& other); //Copy assignment
//	Bitmap& operator=(Bitmap&& other); //Move assignment

	void clear(Pixel color);

	Pixel getPixelSafe(int x, int y) const;
	Pixel getPixel(int x, int y) const;

	void setPixelSafe(int x, int y, Pixel color);
	void setPixel(int x, int y, Pixel color);

	void drawHorizontalLine(int x, int y, int width, Pixel color);

	int getWidth() const;
	int getHeight() const;

	void setWidth(int newWidth);
	void setHeight(int newHeight);
	void resize(int newWidth, int newHeight);

	void draw() const;

    private:
	std::vector<Pixel> buffer;
	std::vector<Pixel*> rows;

	int width;
	int height;
};

#endif

