#include "MainMenu.h"
#include "Algorithms.h"
#include "RandomGraph.h"

MainMenu::MainMenu()
{
}

int MainMenu::menuFunction()
{
	while (atBeginning)
	{
		int choice;
		cout << "Graph Algorithms\n1. Randomly Generate \n2. Build from File \n0. Quit \n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1://Randomly generated
		{
			cout << "Random Generation\n";
			RandomGraph generator(5);
			Algorithms graph;
			graph.buildDirGraph();
			graph.buildUnDirGraph();
			graph.buildDirMatrix();
			graph.buildUnDirMatrix();
			graph.buildDirList();
			graph.buildUnDirList();

			atBeginning = false;
			while (atBeginning == false)
			{
				cout << "\nRandomly generated graph \n1.List \n2.Matrix \n3.Prim \n4.Dijkstra \n0.Main menu\n";
				cin >> choice;

				switch (choice)
				{
				case 1: //List
				{
					cout << "Directed List\n";
					graph.dispDirList();
					cout << "\n";
					cout << "Undirected List\n";
					graph.dispUnDirList();
					cout << "\n";
				}
				break;
				case 2: //Matrix
				{

					cout << "Directed Matrix\n";
					graph.dispDirMatrix();
					cout << "\n";
					cout << "Undirected Matrix\n";
					graph.dispUnDirMatrix();
					cout << "\n";

				}
				break;
				case 3:
				{
					cout << "Prim's Algorithm Matrix for:\n";
					graph.PrimM();
					cout << "Prim's Algorithm List for:\n";
					graph.PrimL();
				}
				break;
				case 4:
				{
					cout << "Dijkstra's Algorithm for Matrix:\n";
					graph.DijkstraM(graph.begVertex);
					cout << "Dijkstra's Algorithm for List:\n";
					graph.DijkstraL(graph.begVertex);

				}
				break;
				case 0:
				{
					system("cls");
					atBeginning = true;
					break;
				}
				default:
				{
					cout << "Wrong choice! \n";
					atBeginning = false;
				}
				}
			}
		}
		break;
		case 2://Built from file
		{
			cout << "Building Graph from file\n";
			Algorithms graph;
			int c;

			atBeginning = false;
			while (atBeginning == false)
			{
				cout << "Graph built from file \n1.Load \n2.List \n3.Matrix \n4.Prim \n5.Dijkstra \n0.Main menu\n";
				cin >> choice;

				switch (choice)
				{
				case 1:
				{
					cout << "1.MST \n2.ST \n";
					cin >> c;
					switch (c)
					{
					case 1:
					{
						graph.buildFromFileMST();
						graph.buildUnDirGraph();
						graph.buildDirMatrix();
						graph.buildUnDirMatrix();
						graph.buildDirList();
						graph.buildUnDirList();
					}
					break;
					case 2:
					{
						graph.buildFromFileSP();
						graph.buildUnDirGraph();
						graph.buildDirMatrix();
						graph.buildUnDirMatrix();
						graph.buildDirList();
						graph.buildUnDirList();
					}
					break;
					}

				}break;

				case 2:
				{
					if (c == 1)
					{
						cout << "Undirected List\n";
						graph.dispUnDirList();
						cout << "\n";
					}
					else
					{
						cout << "Directed List\n";
						graph.dispDirList();
						cout << "\n";
					}
				}
				break;
				case 3:
				{
					if (c == 1)
					{
						cout << "Undirected Matrix\n";
						graph.dispUnDirMatrix();
						cout << "\n";
					}
					else
					{
						cout << "Directed Matrix\n";
						graph.dispDirMatrix();
						cout << "\n";
					}


				}
				break;

				case 4:
				{
					if (c == 1)
					{
						cout << "Prim's Algorithm Matrix for:\n";
						graph.PrimM();
						cout << "Prim's Algorithm List for:\n";
						graph.PrimL();
					}
					else cout << "\nLoaded data doesn't fit for this algorithm!\n";
				}
				break;
				case 5:
				{
					if (c == 2)
					{
						cout << "Dijkstra's Algorithm for Matrix:\n";
						graph.DijkstraM(graph.begVertex);
						cout << "Dijkstra's Algorithm for List:\n";
						graph.DijkstraL(graph.begVertex);
					}
					else cout << "\nLoaded data doesn't fit for this algorithm!\n";
				}
				break;
				case 0:
				{
					system("cls");
					atBeginning = true;
					break;
				}
				default:
				{
					cout << "Wrong choice! \n";
					atBeginning = false;
				}
				}
			}
		}
		break;
		case 0:
		{
			return 0;
		}
		}
	}
}

MainMenu::~MainMenu()
{
}
