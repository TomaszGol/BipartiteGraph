#include "Console.h"

void instructions()
{
	std::cout << "-----------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "\t\t\t\t\tINSTRUCTION" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------\n" << std::endl;
	std::cout << "Switches available: \n" << std::endl;
	std::cout << "\t'-i' - Input file with graph" << std::endl;
	std::cout << "\t'-o' - Graph output file" << std::endl;
	std::cout << "\t'-h' - Help\n" << std::endl;
	std::cout << "Open project: name.exe -i <File with graph to check> -o <Output of program> " << std::endl;
}