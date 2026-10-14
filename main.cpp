
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
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

	std::ifstream infile(argv[1]);
	if (!infile) 
	{
		std::cout << "Could not open" << argv[1] << std::endl;
		return 1;
	}

	int counter = 0;
	std::string line;
	while (std::getline(infile, line))
	{
		Pixel p;
		std::string::size_type start = 0, comma;
		
		comma = line.find(',', start);
		p.x = std::stoi(line.substr(start, comma - start));
		start = comma + 1;


		comma = line.find(',', start);
		p.y = std::stoi(line.substr(start, comma - start));
		start = comma + 1;

		
		comma = line.find(',', start);
		p.r = std::stof(line.substr(start, comma - start));
		start = comma + 1;
		
		comma = line.find(',', start);
		p.g = std::stof(line.substr(start, comma - start));
		start = comma + 1;
		
		p.b = std::stof(line.substr(start));
		
		pixel_list.push_back(p);
		counter++;
	}
	infile.close();
	std::cout << "There are: " << counter << "lines in" << argv[1] << std::endl;

	std::cout << "Vector size:" << pixel_list.size() << std::endl;
	
	average_colors(pixel_list);
	
	std::cout << "Before: " << pixel_list[0].r << " " << pixel_list[255].r <<  std::endl;
	flip_vertically(pixel_list);
	std::cout << "After: " << pixel_list[0].r << " " << pixel_list[255].r <<  std::endl;
	return 0;
}

void average_colors(std::vector<Pixel> &pixel_list)
{
	double addR = 0;
	double addG = 0;
	double addB = 0;
	for(Pixel &px : pixel_list)
	{
		addR += px.r;
		addG += px.g;
		addB += px.b;
	}
	std::cout << "Average R: " << addR / pixel_list.size() << std::endl;
	std::cout << "Average G: " << addG / pixel_list.size() << std::endl;
	std::cout << "Average B: " << addB / pixel_list.size() << std::endl;
}

void flip_vertically(std::vector<Pixel> &pixel_list)
{
	for(int x = 0; x < 512; x++)
	{
		for(int y = 0; y < 128; y++)
		{
			int top = x * 256 + y;
			int bottom = x * 256 + (255 - y);
			std::swap(pixel_list[top].r, pixel_list[bottom].r);
			std::swap(pixel_list[top].g, pixel_list[bottom].g);
			std::swap(pixel_list[top].b, pixel_list[bottom].b);
		}
	}
}
