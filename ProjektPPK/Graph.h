#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <queue>
/** Typ wyliczeniowy "enum" zawierający kolory*/
enum Color :int { NoColor = 0, Red = 1, Blue = -1 };

/** Funkjca, w której wykonywany jest najważniejszy algorytm, którt sprawdza czy graf jest dwudzielny czy nie
@param graph mapa z grafem
@param colors mapa z wierzchołkami grafu i przypisanym kolorem za pomocą enum
*/
bool isBipartite(std::map<int, std::vector<int> >& graph, std::map<int, Color>& colors);

/** Funckja wypisująca mape z grafem na konsole
@param graph mapa z grafem*/
void showMap(std::map<int, std::vector<int> >& graph);