#include "File.h"
#include "Console.h"
#include "Graph.h"

int main(int argc, char* argv[])
{
	std::map<int, std::vector<int>> Graph;
	std::map<int, Color> colors;
	for (int i = 0; i < argc; i++)
	{
		std::string file = argv[i];
		if (file == "-i")
		{
			readFile(Graph, argv[i+1]);
			showMap(Graph);
		}
		else if (file == "-o")
		{

			std::map<int, std::vector<int> >::iterator itr;
			for (itr = Graph.begin(); itr != Graph.end(); itr++)
			{
				colors.insert(std::make_pair((*itr).first, Color::NoColor));
			}
			bool bipartiteGraph;
			bipartiteGraph = isBipartite(Graph, colors);
			if (bipartiteGraph)
			{
				saveIfBipart(Graph, colors, argv[i+1]);
			}
			else {
				saveIfNotBipart(Graph, argv[i+1]);
			}
		}
		else if (file == "-h" || argc == 1)
		{
			instructions();
		}
	}
}

