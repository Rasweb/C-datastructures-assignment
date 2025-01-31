#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include "list.h"
#include "queue.h"

// Directed graph using list
typedef int Data;
typedef int ID;

class Graph {
private:
	List* edges;
	std::vector<Data> values;
	int nodeSize;
	void dfsHelper(ID currID, std::vector<bool>& visited);
	void bfsHelper(std::vector<bool>& visited, Queue& q);
	void clearGraph();
public:
	Graph();
	~Graph();
	//skapar en tom graf
	std::vector<Data> createEmptyGraph();

	//unders�ker om grafen �r tom
	int isGraphEmpty();

	//l�gg till en nod till grafen med v�rdet value
	//noden ska f� ett ID automatiskt
	//ID:t returneras
	int addVertex(Data value);

	//l�gger till en riktad b�ge i grafen
	void addDirectedEdge(ID startVertexID, ID endVertexID);
	
	//l�gger till en oriktad b�ge i grafen
	//tips: g�r med hj�lp av addDirectedEdge()
	void addEdge(ID vertexID1, ID vertexID2);

	//skriver ut alla noder i ID-ordning, och deras v�rden
	//skriver ocks� ut alla utg�ende b�gar
	void printGraphByID();

	//skriv ut alla noder+b�gar i DFS-ordning, startar i en specifik nod
	//tar nodens ID
	void printGraphDFS(ID currID);

	//skriv ut alla noder+b�gar i BFS-ordning, startar i en specifik nod
	//tar nodens ID
	void printGraphBFS(ID currID);


};

#endif