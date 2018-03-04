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
		cout << "====Graph Algorithms==== \n 1. Random Generate \n 2. Build from File \n 0. Quit \n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1://Randomly generated
		{
			cout << "===Random Generation===\n";
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
				cout << "\n====Randomly generated graph==== \n1.List \n2.Matrix \n3.Prim \n4.Dijkstra \n";
				cin >> choice;

				switch (choice)
				{
				case 1: //List
				{
					cout << "====Directed List====\n";
					graph.dispDirList();
					cout << "\n";
					cout << "====UnDirected List====\n";
					graph.dispUnDirList();
					cout << "\n";
				}
				break;
				case 2: //Matrix
				{

					cout << "====Directed Matrix====\n";
					graph.dispDirMatrix();
					cout << "\n";
					cout << "====UnDirected Matrix====\n";
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
				case 5:
				{
					system("cls");
					atBeginning = true;
				}
				break;
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
			cout << "Building Graph from file===";
			Algorithms graph;
			int c;

			atBeginning = false;
			while (atBeginning == false)
			{
				cout << "====Graph built from file==== \n0.Load \n1.List \n2.Matrix \n3.Prim \n4.Dijkstra \n";
				cin >> choice;

				switch (choice)
				{
				case 0:
				{
					cout << "1. MST \n 2.ST \n";
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

				case 1:
				{
					if (c == 1)
					{
						cout << "====UnDirected List====\n";
						graph.dispUnDirList();
						cout << "\n";
					}
					else
					{
						cout << "====Directed List====\n";
						graph.dispDirList();
						cout << "\n";
					}
				}
				break;
				case 2:
				{
					if (c == 1)
					{
						cout << "====UnDirected Matrix====\n";
						graph.dispUnDirMatrix();
						cout << "\n";
					}
					else
					{
						cout << "====Directed Matrix====\n";
						graph.dispDirMatrix();
						cout << "\n";
					}


				}
				break;

				case 3:
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
				case 4:
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
				case 5:
				{
					system("cls");
					atBeginning = true;
				}
				break;
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
