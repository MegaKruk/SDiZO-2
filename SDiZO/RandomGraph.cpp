#include "RandomGraph.h"

RandomGraph::RandomGraph()
{
}

RandomGraph::RandomGraph(int x)
{
	srand(time(NULL));
	int numbOfVertices = 0;
	float density = 0;
	int weight;
	int help;
	bool exist = false;

	do
	{
		cout << "Enter number of vertices you'd want:";
		cin >> numbOfVertices;
	} while (numbOfVertices < 2);

	this->vertices = numbOfVertices;
	maxWeight = 9;
	minEdges = vertices - 1;
	maxEdges = ((vertices - 1) * vertices) / 2;
	int minDensity = ceil((minEdges / maxEdges) * 100);

	do {
		cout << "Enter density (minimal dnesity is :" << minDensity << "%) :";
		cin >> density;
	} while (density < minDensity || density >= 100);

	edges = ceil(maxEdges * (density / 100));

	result = new int *[2 * edges];

	vector<int> vec;

	for (int i = 0; i < vertices; i++)
	{
		vec.push_back(i);
	}

	int next, prev;
	prev = rand() % vertices;
	vec[prev] = -1;
	for (int i = 1; i < minEdges + 1; i++)
	{
		while (true)
		{
			next = rand() % vertices;
			if (vec[next] >= 0)
			{
				break;
			}
		}

		result[i - 1] = new int[3];
		result[i - 1][0] = prev;
		result[i - 1][1] = next;
		weight = (rand() % maxWeight) + 1;
		result[i - 1][2] = weight;
		vec[next] = -1;
		prev = next;
	}

	for (int i = minEdges; i < edges; i++)
	{
		while (true)
		{
			exist = false;
			prev = rand() % vertices;
			next = rand() % vertices;

			for (int j = 0; j < i; j++)
			{
				if ((result[j][0] == prev && result[j][1] == next) || (result[j][0] == next && result[j][1] == prev) ||
					(next == prev))
				{
					exist = true;
					break;
				}
			}
			if (exist == false)
			{
				result[i] = new int[3];
				result[i][0] = prev;
				result[i][1] = next;
				weight = rand() % maxWeight + 1;
				result[i][2] = weight;
				break;
			}
		}
	}

	for (int i = edges; i < 2 * edges; i++)
	{
		while (true)
		{
			exist = false;
			prev = rand() % vertices;
			next = rand() % vertices;

			for (int j = 0; j < i; j++)
			{
				if ((result[j][0] == prev && result[j][1] == next) || (next == prev))
				{
					exist = true;
					break;
				}
			}
			if (exist == false)
			{
				result[i] = new int[3];
				result[i][0] = prev;
				result[i][1] = next;
				weight = rand() % maxWeight + 1;
				result[i][2] = weight;
				break;
			}
		}
	}

	fstream plik("file.txt", ios::out);
	if (plik.good()) {
		plik << 2 * edges << " " << vertices << " " << result[0][0] << " " << result[vertices - 1][0] << "\n";
		for (int i = 0; i < 2 * edges; i++)	plik << result[i][0] << " " << result[i][1] << " " << result[i][2] << "\n";
		plik.close();
	}

}

RandomGraph::~RandomGraph()
{
	for (int i = 0; i < 2 * edges; i++)
	{
		delete result[i];
	}
	result = NULL;
}
