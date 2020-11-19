#include "File.h"

void readFile(std::map<int, std::vector<int> >& graph, std::string argv) 
{
	std::fstream file;
	int vertexFirst, vertexSecond;
	file.open(argv);
	if (!file)
	{
		std::cout << "Can't open file" << std::endl;
	}
	while (!file.eof())
	{
		file >> vertexFirst >> vertexSecond;
		if (graph.find(vertexFirst) == graph.end())
		{
			graph[vertexFirst].push_back(vertexSecond);

		}
		else 
		{
			graph[vertexFirst].push_back(vertexSecond);
		}
		if (graph.find(vertexSecond) == graph.end())
		{
			graph[vertexSecond].push_back(vertexFirst);
		}
		else 
		{
			graph[vertexSecond].push_back(vertexFirst);
		}
	}
	std::map<int, std::vector<int> >::iterator itr;
	for (itr = graph.begin(); itr != graph.end(); itr++)
	{
		itr->second.erase(std::unique(itr->second.begin(), itr->second.end()), itr->second.end());
	}
}

void saveIfBipart(std::map<int, std::vector<int> >& graph, std::map<int, Color>& colors, std::string argv)
{
	std::ofstream file;
	file.open(argv);
	if (!file)
	{
		std::cout << "Can't open file" << std::endl;
	}
	else 
	{
		file << "Graph is bipart" << std::endl;
		saveToFile(graph, file);
		std::map<int, Color>::iterator itr;
		file << "First group: ";
		for (itr = colors.begin(); itr != colors.end(); itr++)
		{
			if (itr->second == Color::Red)
			{
				file << itr->first << " ";
			}
		}
		file << "\nSecond group: ";
		for (itr = colors.begin(); itr != colors.end(); itr++)
		{
			if (itr->second == Color::Blue)
			{
				file << itr->first << " ";
			}
		}
	}
	file.close();
}
void saveIfNotBipart(std::map<int, std::vector<int> >& graph, std::string argv)
{
	std::ofstream file;
	file.open(argv);
	if (!file)
	{
		std::cout << "Can't open file" << std::endl;
	}
	else 
	{
		file << "Graph isn't bipart" << std::endl;
		saveToFile(graph, file);
	}
	file.close();
}
void saveToFile(std::map<int, std::vector<int> >& graph, std::ofstream& file)
{
	std::map<int, std::vector<int> >::iterator itr;
	for (itr = graph.begin(); itr != graph.end(); itr++)
	{
		file << itr->first << "=> {";
		for (auto it2 = itr->second.begin(); it2 != itr->second.end(); it2++)
		{
			if (it2 == itr->second.end() - 1)
			{
				file << *it2;
			}
			else
			{
				file << *it2 << ", ";
			}
		}
		file << "}" << std::endl;
	}
}

