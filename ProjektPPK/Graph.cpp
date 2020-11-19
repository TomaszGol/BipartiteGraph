#include "Graph.h"

void showMap(std::map<int, std::vector<int> >& graph)
{
	std::map<int, std::vector<int> >::iterator itr;
	for (itr = graph.begin(); itr != graph.end(); itr++)
	{
		std::cout << itr->first << "=> {";
		for (auto it2 = itr->second.begin(); it2 != itr->second.end(); it2++)
		{
			if (it2 == itr->second.end() - 1)
			{
				std::cout << *it2;
			}
			else
			{
				std::cout << *it2 << ", ";
			}
		}
		std::cout << "}" << std::endl;
	}
}

bool isBipartite(std::map<int, std::vector<int> >& graph, std::map<int, Color>& colors)
{
	if (graph.empty())
	{
		return false;
	}
	std::queue<int> graphQueue;
	auto first = (*graph.begin()).first;
	graphQueue.push(first);
	colors[first] = Color::Red;
	while (!graphQueue.empty())
	{
		int currentVerticies = graphQueue.front();
		graphQueue.pop();

		auto vertices = graph[currentVerticies];
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			int currentNeighbor = vertices[i];

			if (colors[currentNeighbor] == colors[currentVerticies])
			{
				return false;
			}
			if (colors[currentNeighbor] == Color::NoColor)
			{
				colors[currentNeighbor] = (Color)(-colors[currentVerticies]);
				graphQueue.push(currentNeighbor);
			}
		}
	}
	return true;
}
