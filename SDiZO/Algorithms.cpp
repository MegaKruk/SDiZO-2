#include "Algorithms.h"

Algorithms::Algorithms()
{

}

Algorithms::~Algorithms()
{
	for (int i = 0; i < edges; i++) {
		delete[] directedGraph[i];
		delete[] undirectedGraph[i];
	}
	directedGraph = NULL;
	undirectedGraph = NULL;

	for (int i = 0; i < vertices; i++) {
		delete[] directedMatrix[i];
		delete[] undirectedMatrix[i];
	}

	directedMatrix = NULL;
	undirectedMatrix = NULL;
}

//===============Directed Graph==================================
void Algorithms::buildDirGraph()
{
	fstream file("file.txt", ios::in);
	if (file.is_open())
	{
		file >> edges;
		file >> vertices;
		file >> begVertex;
		file >> endVertex;
		directedGraph = new int *[edges];

		if (file.fail())
		{
			cout << "Error!\n";
		}
		else
		{
			int src, dest, weight;
			for (int i = 0; i < edges; i++)
			{
				file >> src;
				file >> dest;
				file >> weight;

				if (file.fail())
				{
					cout << "Error! \n";
					break;
				}
				else
				{
					directedGraph[i] = new int[3];
					directedGraph[i][0] = src;
					directedGraph[i][1] = dest;
					directedGraph[i][2] = weight;
				}
			}
		}
		file.close();
	}
	else
	{
		cout << "Error! \n";
	}
}

//====Dir-Graph-File===========================================

bool Algorithms::buildFromFileMST()
{
	bool success = false;
	string filename;
	cout << "Enter name of file:";
	cin >> filename;
	filename = filename + ".txt";

	fstream file(filename, ios::in);
	if (file.is_open())
	{
		file >> edges;
		file >> vertices;
		directedGraph = new int *[edges];
		if (file.fail())
			cout << "blad" << endl;
		else {
			int source, destination, localWeight;
			for (int i = 0; i < edges; i++)
			{
				file >> source;
				file >> destination;
				file >> localWeight;

				if (file.fail())
				{
					cout << "blad" << endl;
					break;
				}
				else
				{
					directedGraph[i] = new int[3];
					directedGraph[i][0] = source;
					directedGraph[i][1] = destination;
					directedGraph[i][2] = localWeight;
				}
			}
		}

		file.close();
		success = true;
	}
	else
	{
		cout << "blad" << endl;
		success = false;
	}
	return success;
}
bool Algorithms::buildFromFileSP()
{
	bool success = false;
	string filename;
	cout << "Enter name of file:";
	cin >> filename;
	filename = filename + ".txt";

	fstream file(filename, ios::in);
	if (file.is_open())
	{
		file >> edges;
		file >> vertices;
		file >> begVertex;
		//file >> endVertex;
		directedGraph = new int *[edges];
		if (file.fail())
			cout << "blad" << endl;
		else {
			int source, destination, localWeight;
			for (int i = 0; i < edges; i++)
			{
				file >> source;
				file >> destination;
				file >> localWeight;

				if (file.fail())
				{
					cout << "blad" << endl;
					break;
				}
				else
				{
					directedGraph[i] = new int[3];
					directedGraph[i][0] = source;
					directedGraph[i][1] = destination;
					directedGraph[i][2] = localWeight;
				}
			}
		}

		file.close();
		success = true;
	}
	else
	{
		cout << "blad" << endl;
		success = false;
	}
	return success;
}

//======================Undirected Graph==============================

void Algorithms::buildUnDirGraph()
{
	bool * doppel;
	doppel = new bool[edges];

	for (int i = 0; i < edges; i++)
	{
		doppel[i] = false;
		undirectedGraph = new int *[edges];
	}
	for (int i = 0; i < edges; i++)
	{
		undirectedGraph[i] = NULL;
	}

	for (int i = 0; i < edges; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((directedGraph[i][0] == directedGraph[j][0] && directedGraph[i][1] == directedGraph[j][1]) || (directedGraph[i][1] == directedGraph[j][0] && directedGraph[i][0] == directedGraph[j][1]))
			{
				doppel[i] = false;
				break;
			}
			doppel[i] = true;
		}
	}
	doppel[0] = true;
	edg = 0;

	for (int i = 0; i < edges; i++)
	{
		if (doppel[i] == true)
		{
			undirectedGraph[edg] = new int[3];
			undirectedGraph[edg][0] = directedGraph[i][0];
			undirectedGraph[edg][1] = directedGraph[i][1];
			undirectedGraph[edg][2] = directedGraph[i][2];
			edg++;
		}
	}
	delete[] doppel;
}

//===============Directed Matrix==================================

void Algorithms::buildDirMatrix()
{
	directedMatrix = new int *[vertices];
	for (int i = 0; i < vertices; i++)
	{
		directedMatrix[i] = new int[vertices];
	}
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			directedMatrix[i][j] = 0;
		}
	}
	for (int i = 0; i < edges; i++)
	{
		directedMatrix[directedGraph[i][0]][directedGraph[i][1]] = directedGraph[i][2];
	}
}

void Algorithms::dispDirMatrix()
{
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			cout << directedMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

//===============Undirected Matrix==================================

void Algorithms::buildUnDirMatrix()
{
	undirectedMatrix = new int *[vertices];
	for (int i = 0; i < vertices; i++)
	{
		undirectedMatrix[i] = new int[vertices];
	}
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			undirectedMatrix[i][j] = 0;
		}
	}
	for (int i = 0; i < edg; i++)
	{
		undirectedMatrix[undirectedGraph[i][0]][undirectedGraph[i][1]] = undirectedGraph[i][2];
		undirectedMatrix[undirectedGraph[i][1]][undirectedGraph[i][0]] = undirectedGraph[i][2];
	}
}

void Algorithms::dispUnDirMatrix()
{
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			cout << undirectedMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

//======================Directed List===================================

void Algorithms::buildDirList()
{
	neighboursList = new ListElement *[vertices];
	for (int i = 0; i < vertices; i++)
	{
		neighboursList[i] = NULL;
	}

	for (int i = 0; i < edges; i++)
	{
		tmp = new ListElement;
		tmp->n = directedGraph[i][1];
		tmp->weight = directedGraph[i][2];
		tmp->next = neighboursList[directedGraph[i][0]];
		neighboursList[directedGraph[i][0]] = tmp;
	}
}

void Algorithms::dispDirList()
{
	for (int i = 0; i < vertices; i++)
	{
		cout << "A[" << i << "] =";
		tmp = neighboursList[i];
		while (tmp)
		{
			cout << setw(6) << tmp->n << "(" << tmp->weight << ")";
			tmp = tmp->next;
		}
		cout << endl;
	}

}

//======================Undirected List===================================

void Algorithms::buildUnDirList()
{
	undirectedList = new ListElement *[vertices];

	for (int i = 0; i < vertices; i++)
	{
		undirectedList[i] = NULL;
	}

	for (int i = 0; i < edg; i++)
	{
		tmp = new ListElement;
		tmp->n = undirectedGraph[i][1];
		tmp->weight = undirectedGraph[i][2];
		tmp->next = undirectedList[undirectedGraph[i][0]];
		undirectedList[undirectedGraph[i][0]] = tmp;


		tmp = new ListElement;
		tmp->n = undirectedGraph[i][0];
		tmp->weight = undirectedGraph[i][2];
		tmp->next = undirectedList[undirectedGraph[i][1]];
		undirectedList[undirectedGraph[i][1]] = tmp;

	}

}

void Algorithms::dispUnDirList()
{
	for (int i = 0; i < vertices; i++)
	{
		cout << "A[" << i << "] =";
		tmp = undirectedList[i];
		while (tmp)
		{
			cout << setw(6) << tmp->n << "(" << tmp->weight << ")";
			tmp = tmp->next;
		}
		cout << endl;
	}
}

//================================Prim=====================================================
void Algorithms::PrimL()
{
	listResults = new int*[vertices - 1];

	int currVertex = directedGraph[0][0];
	vector <int> TreeVertices;
	TreeVertices.push_back(currVertex);
	int help;
	bool *visitedVertices;
	visitedVertices = new bool[vertices];
	for (int i = 0; i < vertices; i++) {
		visitedVertices[i] = false;
	}
	int fromHere, there, nweight;
	fromHere = currVertex;
	there = currVertex;
	visitedVertices[currVertex] = true;

	for (int i = 0; i < vertices; i++) {
		currVertex = TreeVertices[0];
		nweight = 11;
		for (int j = 0; j < TreeVertices.size(); j++) {

			currVertex = TreeVertices[j];
			tmp = undirectedList[currVertex];
			while (tmp) {
				if (tmp->weight != 0 && tmp->weight < nweight && visitedVertices[tmp->n] == false) {
					fromHere = currVertex;
					there = tmp->n;
					nweight = tmp->weight;

				}
				tmp = tmp->next;
			}
		}
		listResults[i] = new int[3];
		listResults[i][0] = fromHere;
		listResults[i][1] = there;
		listResults[i][2] = nweight;


		visitedVertices[there] = true;
		TreeVertices.push_back(there);
	}

	int MST = 0;
	for (int i = 0; i < vertices - 1; i++) {
		cout << "(" << listResults[i][0] << "," << listResults[i][1] << ")   " << listResults[i][2] << endl;
		MST += listResults[i][2];
	}
	cout << "MST: " << MST << endl;

}

void Algorithms::PrimM()
{
	matrixResults = new int*[vertices - 1];
	int currVertex = undirectedGraph[0][0];
	vector <int> TreeVertices;
	TreeVertices.push_back(currVertex);
	int help;
	bool *visitedVertices;
	visitedVertices = new bool[vertices];
	for (int i = 0; i < vertices; i++)
		visitedVertices[i] = false;

	int idx, idy, nweight;
	idy = currVertex;
	idx = currVertex;

	visitedVertices[currVertex] = true;

	for (int i = 0; i < vertices; i++)
	{
		currVertex = TreeVertices[0];
		nweight = 11;
		for (int j = 0; j < TreeVertices.size(); j++)
		{
			currVertex = TreeVertices[j];
			for (int k = 0; k < vertices; k++)
			{

				if (undirectedMatrix[currVertex][k] != 0 && undirectedMatrix[currVertex][k] < nweight && visitedVertices[k] == false)
				{
					idx = k;
					idy = currVertex;
					nweight = undirectedMatrix[currVertex][k];

				}
			}
		}
		matrixResults[i] = new int[3];
		matrixResults[i][0] = idy;
		matrixResults[i][1] = idx;
		matrixResults[i][2] = nweight;

		visitedVertices[idx] = true;
		TreeVertices.push_back(idx);
	}
	int MST = 0;
	for (int i = 0; i < vertices - 1; i++)
	{
		cout << "(" << matrixResults[i][0] << "," << matrixResults[i][1] << ")   " << matrixResults[i][2] << endl;
		MST += matrixResults[i][2];
	}
	cout << "MST: " << MST << endl;
};

//==================================Dijkstra===============================================

void Algorithms::DijkstraL(int beg)
{
	int *cost, *path, *Stack, stackPointer;
	int i, j, u;
	bool *visited;

	cost = new int[vertices];
	path = new int[vertices];
	visited = new bool[vertices];
	Stack = new int[vertices];
	stackPointer = 0;

	for (int i = 0; i<vertices; i++) {
		cost[i] = MAXi;
		path[i] = -1;
		visited[i] = false;
	}

	cout << endl;
	cost[beg] = 0;

	for (int i = 0; i < vertices; i++) {
		for (j = 0; visited[j]; j++);
		for (u = j++; j < vertices; j++)
			if (!visited[j] && (cost[j] < cost[u]))
				u = j;

		visited[u] = true;


		for (tmp = neighboursList[u]; tmp; tmp = tmp->next)
			if (!visited[tmp->n] && (cost[tmp->n] > cost[u] + tmp->weight)) {
				cost[tmp->n] = cost[u] + tmp->weight;
				path[tmp->n] = u;
			}
	}


	cout << "Start " << begVertex << endl;
	cout << "End    Dist    Path" << endl;
	for (i = 0; i < vertices; i++) {
		cout << i << ": ";
		for (j = i; j > -1; j = path[j]) Stack[stackPointer++] = j;
		cout << "   | " << cost[i] << " |   ";
		while (stackPointer) cout << Stack[--stackPointer] << " ";
		cout << endl;
	}


	delete[] cost;
	delete[] path;
	delete[] Stack;
	delete[] visited;
}

void Algorithms::DijkstraM(int beg)
{
	int *cost, *path, *Stack, stackPointer;
	int i, j, u;
	bool *visited;

	cost = new int[vertices];
	path = new int[vertices];
	visited = new bool[vertices];
	Stack = new int[vertices];
	stackPointer = 0;

	for (int i = 0; i<vertices; i++)
	{
		cost[i] = MAXi;
		path[i] = -1;
		visited[i] = false;
	}

	cout << endl;
	cost[beg] = 0;

	for (int i = 0; i<vertices; i++)
	{
		for (j = 0; visited[j]; j++);
		for (u = j++; j<vertices; j++)
			if (!visited[j] && (cost[j]<cost[u])) u = j;

		visited[u] = true;


		for (int g = 0; g < vertices; g++)
		{
			if (directedMatrix[u][g] != 0)
			{
				if (!visited[g] && (cost[g] > cost[u] + directedMatrix[u][g]))
				{
					cost[g] = cost[u] + directedMatrix[u][g];
					path[g] = u;
				}
			}
		}

	}
	cout << "Start " << begVertex << endl;
	cout << "End    Dist    Path" << endl;
	for (i = 0; i < vertices; i++)
	{
		cout << i << ": ";
		for (j = i; j > -1; j = path[j]) Stack[stackPointer++] = j;
		cout << "   | " << cost[i] << " |   ";
		while (stackPointer) cout << Stack[--stackPointer] << " ";
		cout << endl;
	}

	delete[] cost;
	delete[] path;
	delete[] Stack;
	delete[] visited;
};
