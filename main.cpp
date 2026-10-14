
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "pixel.h"

void average_colors(std::vector<Pixel> &pixel_list);
void flip_vertically(std::vector<Pixel> &pixel_list);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "type out ./main <file>" << std::endl;
		return 1;
	}

	std::vector<Pixel> pixel_list;

	std::cout << "File to read:" << argv[1] << std::endl;

	return 0;
}

void average_colors(std::vector<Pixel> &pixel_list)
{
}

void flip_vertically(std::vector<Pixel> &pixel_list)
{
}
