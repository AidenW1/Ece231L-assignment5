
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
		p.r = std::stoi(line.substr(start, comma - start));
		start = comma + 1;
		
		comma = line.find(',', start);
		p.g = std::stoi(line.substr(start, comma - start));
		start = comma + 1;
		
		p.b = std::stof(line.substr(start));
		
		pixel_list.push_back(p);
		counter++;
	}
	infile.close();
	std::cout << "There are: " << counter << "lines in" << argv[1] << std::endl;

	std::cout << "Vector size:" << pixel_list.size() << std::endl;
	return 0;
}

void average_colors(std::vector<Pixel> &pixel_list)
{
}

void flip_vertically(std::vector<Pixel> &pixel_list)
{
}
