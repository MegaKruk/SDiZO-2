#pragma once

#ifndef PROJEKTY_ALGORITHMS_H
#define PROJEKTY_ALGORITHMS_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

class Algorithms
{
public:
	struct ListElement
	{
		ListElement *next;
		int n;
		int weight;
	};

	int vertices, edges;

	int **directedGraph, **undirectedGraph;
	int **directedMatrix, **undirectedMatrix;
	int **matrixResults, **listResults;

	int edg;

	ListElement **undirectedList;
	ListElement **neighboursList, *tmp, *tmpDel;
	const int MAXi = 2147483647;

	int begVertex, endVertex;

	Algorithms();
	~Algorithms();

	bool buildFromFileMST();
	bool buildFromFileSP();

	void buildDirGraph();
	void buildUnDirGraph();

	void buildDirMatrix();
	void dispDirMatrix();

	void buildUnDirMatrix();
	void dispUnDirMatrix();

	void buildDirList();
	void dispDirList();

	void buildUnDirList();
	void dispUnDirList();

	void PrimM();
	void PrimL();

	void DijkstraM(int);
	void DijkstraL(int);
};

#endif //PROJEKTY_ALGORITHMS_H