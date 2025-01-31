#include "Graph.h"
#include "queue.h"

Graph::Graph() : edges(nullptr), nodeSize(0) {
}

Graph::~Graph(){
	clearGraph();
}

std::vector<Data> Graph::createEmptyGraph() {
	clearGraph();
	return {};
};

int Graph::isGraphEmpty() {
	return nodeSize == 0; 
}

// Allocate memory  to handle the new vertex
// Copies the old edges list to the new with a bigger size
// Free the old one
int Graph::addVertex(Data value) {
	int newID = values.size();  
	values.push_back(value);  

	List* tempEdges = new List[newID + 1];  

	for (int i = 0; i < nodeSize; ++i) {
		tempEdges[i] = edges[i];
	}
	tempEdges[newID] = createEmptyList();

	delete[] edges; 
	edges = tempEdges;

	nodeSize++;  
	return newID; 
};

void Graph::addDirectedEdge(ID startVertexID, ID endVertexID) {
	if (startVertexID < 0 || startVertexID >= nodeSize || endVertexID < 0 || endVertexID >= nodeSize) {
		return; 
	}
	addFirst(&edges[startVertexID], endVertexID);
};

void Graph::addEdge(ID vertexID1, ID vertexID2) {
	addDirectedEdge(vertexID1, vertexID2);
	addDirectedEdge(vertexID2, vertexID1);
};

void Graph::printGraphByID() {
	for (int i = 0; i < nodeSize; i++)
	{
		std::cout << "Node " << i << " (Value: " << values[i] << "): ";
		printList(edges[i], stdout);
		std::cout << std::endl;
	}
};

// Finds the current
// Checks if visited
// Move to connected
void Graph::dfsHelper(ID currID, std::vector<bool>& visited) {
	visited[currID] = true;
	std::cout << currID << " ";
	List curr = edges[currID];
	
	while(!isEmpty(curr)){
	//while(curr != NULL){
		int dest = curr->d;
		//printf("dest %d\n", curr->d);
		if (!visited[dest]) {
			dfsHelper(dest, visited);
		}
		curr = curr->rest;
	}
}

void Graph::printGraphDFS(ID currID) {
	std::vector<bool> visited(nodeSize, false); 
	dfsHelper(currID, visited);
}; 

// Checks the incoming nodes vertices
void Graph::bfsHelper(std::vector<bool>& visited, Queue& q){
	if(!isQueueEmpty(q)){
		int id = dequeue(&q);
		
		if (visited[id] == false) {
			visited[id] = true;
			std::cout << id << std::endl;
		}
		List node =	edges[id];
		
		while (node != NULL) {
			if (!visited[node->d]) {
				enqueue(&q, node->d);
			}
				node = node->rest;
		}
			bfsHelper(visited, q);
	}
}

void Graph::printGraphBFS(ID currID) {
	std::vector<bool> visited(nodeSize, false);
	Queue q = createQueue();

	enqueue(&q, currID);
	bfsHelper(visited, q);
}; // Recursive

void Graph::clearGraph() {
	for (int i = 0; i < nodeSize; i++)
	{
		clearList(&edges[i]);
	}
	values.clear();
	nodeSize = 0;	
};



