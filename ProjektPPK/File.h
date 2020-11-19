#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>

#include "Graph.h"

/** Funkjca zczytuj¹ca graf z pliku do mapu
@param graph mapa z grafem
@param argv nazwa pliku z prze³¹cznika -i
*/
void readFile(std::map<int, std::vector<int> >& graph, std::string argv);

/** Funkjca zapisuj¹ca do pliku informacje o tym,¿e graf jest dwudzielny
@param graph mapa z grafem
@param colors mapa z wierzcho³kami grafu i przypisanym kolorem
@param argv nazwa pliku z prze³¹cznika -o
*/
void saveIfBipart(std::map<int, std::vector<int> >& graph, std::map<int, Color>& colors, std::string argv);

/** Funkjca zapisuj¹ca do pliku informacje o tym,¿e graf nie jest dwudzielny
@param graph mapa z grafem
@param argv nazwa pliku z prze³¹cznika -o
*/
void saveIfNotBipart(std::map<int, std::vector<int> >& graph, std::string argv);

/** Funkjca zapisuj¹ca do pliku mape grafu do pliku
@param graph mapa z grafem
@param file Ÿród³o pliku do którego przepisujemy graf
*/
void saveToFile(std::map<int, std::vector<int> >& graph, std::ofstream &file);