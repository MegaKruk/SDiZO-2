#pragma once

#ifndef PROJEKTY_GRAPH_H
#define PROJEKTY_GRAPH_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

class RandomGraph
{
public:

	int maxWeight, minEdges, edges, vertices;
	double maxEdges;
	int **result;

	RandomGraph();
	RandomGraph(int);
	~RandomGraph();
};


#endif //PROJEKTY_GRAPH_H
