#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <queue>
/** Typ wyliczeniowy "enum" zawieraj�cy kolory*/
enum Color :int { NoColor = 0, Red = 1, Blue = -1 };

/** Funkjca, w kt�rej wykonywany jest najwa�niejszy algorytm, kt�rt sprawdza czy graf jest dwudzielny czy nie
@param graph mapa z grafem
@param colors mapa z wierzcho�kami grafu i przypisanym kolorem za pomoc� enum
*/
bool isBipartite(std::map<int, std::vector<int> >& graph, std::map<int, Color>& colors);

/** Funckja wypisuj�ca mape z grafem na konsole
@param graph mapa z grafem*/
void showMap(std::map<int, std::vector<int> >& graph);