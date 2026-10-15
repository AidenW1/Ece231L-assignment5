/*OK header comment
 * Aiden W assignemnt 5
 * ece231L
 *
 * ok again with the whole java System.out.println(blablabl) into now c++ with the whold std::cout
 * along with the arrow stuff i can understand the argv code and how its simillar to the args from java
 *
 *the file read was a really weird one where im used to using temp variables read from the file at the point then passing that temp vaiable
 into the objects variable point. but similart for each loops to java so that is nice
 I think this is all for general comments about the code
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include "pixel.h"

//prottypes to keep it similart to java where i have the methods below the main code block
void average_colors(std::vector<Pixel> &pixel_list);
void flip_vertically(std::vector<Pixel> &pixel_list);

//main code block first if is to make sure you have the correct file out
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "type out ./main <file>" << std::endl;
		return 1;
	}

	std::vector<Pixel> pixel_list;

	std::cout << "File to read:" << argv[1] << std::endl;
//make sure the file was read and worked
	std::ifstream infile(argv[1]);
	if (!infile) 
	{
		std::cout << "Could not open" << argv[1] << std::endl;
		return 1;
	}
//populating while loop that takes the data from the file then outputs it into the p object
//feels wrong to to not have to have variables for all the objects
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
	//outputing strings here kind of like .out.print block at the bottom of the code
	std::cout << "There are: " << counter << "lines in" << argv[1] << std::endl;

	std::cout << "Vector size:" << pixel_list.size() << std::endl;
	
	average_colors(pixel_list);
	
	std::cout << "Before: " << pixel_list[0].r << " " << pixel_list[255].r <<  std::endl;
	flip_vertically(pixel_list);
	std::cout << "After: " << pixel_list[0].r << " " << pixel_list[255].r <<  std::endl;

	std::ofstream outfile("flipped.dat");
	for (Pixel &px: pixel_list)
	{
		outfile << px.x << "," << px.y << "," << px.r << "," << px.g << "," << px.b << "," << "\n";
	}

	return 0;
	//for writing the flipped file out to a file alot easier than java I must say
}
//averaging loop pretty easy to get just add them all up then divide by the size
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
//flips it vertically from x to y cycling thorugh the x's then into the y and then just inverting pretty simple maths
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
