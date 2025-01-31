// Algoritmer, Datastrukturer & Design patterns, INL.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Graph.h"

int main()
{
	int val0 = 5;
	int val1 = 4;
	int val2 = 6;
	int val3 = 7;
	int val4 = 10;

	std::vector<int> vals;

	Graph graph1;
	graph1.createEmptyGraph();

	int id0 = graph1.addVertex(val0);
	int id1 = graph1.addVertex(val1);
	int id2 = graph1.addVertex(val2);
	int id3 = graph1.addVertex(val3);
	int id4 = graph1.addVertex(val4);

	//graph1.addDirectedEdge(1, 3);
	//graph1.addDirectedEdge(4, 3);
	//graph1.addDirectedEdge(1, 4);
	//graph1.addEdge(1,3);
	//graph1.addEdge(4,3);
	//graph1.addEdge(1,4);


	//graph1.addEdge(0, 4);
	//graph1.addEdge(1, 2);
	//graph1.addEdge(1, 3);
	//graph1.addEdge(1, 4);
	//graph1.addEdge(2, 3);
	//graph1.addEdge(3, 4);

	graph1.addEdge(0, 3);
	graph1.addEdge(0, 1);
	graph1.addEdge(1, 2);
	graph1.addEdge(2, 0);
	graph1.addEdge(2, 4);

	// start 0
	// Go to 2
	// then to 4
	// backtrack to 2
	// then to 1
	// end with 3

	std::cout << "By ID" << std::endl;
	graph1.printGraphByID();
	std::cout << "\n";

	std::cout << "DFS" << std::endl;
	graph1.printGraphDFS(id1);
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "BFS" << std::endl;
	graph1.printGraphBFS(id1);
	std::cout << "\n";


}
