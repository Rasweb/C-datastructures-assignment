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

	//undersöker om grafen är tom
	int isGraphEmpty();

	//lägg till en nod till grafen med värdet value
	//noden ska få ett ID automatiskt
	//ID:t returneras
	int addVertex(Data value);

	//lägger till en riktad båge i grafen
	void addDirectedEdge(ID startVertexID, ID endVertexID);
	
	//lägger till en oriktad båge i grafen
	//tips: gör med hjälp av addDirectedEdge()
	void addEdge(ID vertexID1, ID vertexID2);

	//skriver ut alla noder i ID-ordning, och deras värden
	//skriver också ut alla utgående bågar
	void printGraphByID();

	//skriv ut alla noder+bågar i DFS-ordning, startar i en specifik nod
	//tar nodens ID
	void printGraphDFS(ID currID);

	//skriv ut alla noder+bågar i BFS-ordning, startar i en specifik nod
	//tar nodens ID
	void printGraphBFS(ID currID);


};

#endif