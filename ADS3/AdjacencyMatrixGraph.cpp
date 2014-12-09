#include "AdjacencyMatrixGraph.h"

/*
 implement all the methods in this file
 
 Points: 
 1. constructors, destructor, show
 1. addEdge, removeEdge
 1. getDegree, getEdgesCount
 1. getVerticesCount, areConnected, getWeight 
*/


/*
 creates a graph with given number of vertices and no edges
*/
AdjacencyMatrixGraph::AdjacencyMatrixGraph(int n)
{
	// add your constructor here
	this->n = n;
	for(int i = 0; i<n;i++) {
		vector<int> row;
		for (int j = 0; j<n; j++) {
			row.push_back(0);
		}
		this->matrix.push_back(row);
	}
}
	
/*
 creates a copy of a given graph
*/
AdjacencyMatrixGraph::AdjacencyMatrixGraph(const AdjacencyMatrixGraph& other)
{
	// add your constructor here
	this->matrix = other.matrix;
	this->n = other.n;
}

/* destructor */
AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
	// add the destructor here
	this->matrix.clear();
	this->n = 0;
}

////////////////////////////////////////////////////////

/*
 Prints the representation of a graph, e.g.

0 1 0 1
1 0 1 1 
0 1 0 0
1 1 0 0 

 Complexity O(n^2)
*/
void AdjacencyMatrixGraph::show()
{
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*
Returns the number of vertices in a graph.

Complexity O(1)
*/
int AdjacencyMatrixGraph::getVerticesCount()
{
	//place your code here
	return this->n;
}

///////////////////////////////////////////////////////

	/*
	Adds an edge between given vertices. Third argument is a weight of an edge (1 by default).
	If the edge already exists or we try to add a loop, no edge is added.
	
	Error handling:
	throw std::invalid_argument with appropriate message if:
	- we try to create a loop
	- there are no such vertices
	- if the edge already exists

	Complexity O(1)
	*/
void AdjacencyMatrixGraph::addEdge(int u,int v, int weight)
{
	//place your code here
	//throw invalid_argument("this is the way you throw exception with a given message");	

	if (u == v) {
		throw invalid_argument("ERROR 401: Trying to create a loop.");
	}
	else if (u<0 || v<0 || u>=n || v>=n) {
		throw invalid_argument("ERROR 404: Vertices not found.");
	}
	else if (matrix[u][v] != 0 || matrix[v][u] != 0) {
		throw invalid_argument("ERROR 409: Edge already exists.");
	}
	else {
		matrix[u][v] = weight;
		matrix[v][u] = weight;
	}
}

	 /*	
	 Removes an edge between given vertices. 
	 If the edge does not exist, nothing is changed.

	 Error handling:
	 throw std::invalid_argument with appropriate message if:
	 - an edge does not exist
	 - vertices do not exist

	 Complexity O(1)
	 */
void AdjacencyMatrixGraph::removeEdge(int u, int v)
{
	//place your code here
	if (u<0 || v<0 || u>=n || v>=n) {
		throw invalid_argument("ERROR 404: Vertices not found.");
	}
	else if (matrix[u][v] == 0 || matrix[v][u] == 0) {
		throw invalid_argument("ERROR 4042: Edge not found.");
	}
	else {
		matrix[u][v] = 0;
		matrix[v][u] = 0;
	}
}
	 
/*
	Returns the number of edges in a graph.

	Complexity O(n^2)
*/
int AdjacencyMatrixGraph::getEdgesCount()
{
	//place your code here
	unsigned int counter = 0;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(matrix[i][j] != 0) {
				counter++;
			}
		}
	}
	counter /= 2;
	return counter;
}
	 
	 /*
	 Returns:
	 degree of the given vertex
	 
	 Error handling:
	 throw std::invalid_argument with appropriate message if:
    - vertex does not exist

	Complexity O(n)
	 */
int AdjacencyMatrixGraph::getDegree(int v)
{
	if (v<0 || v>=n) {
		throw invalid_argument("ERROR 4041: Vertex not found.");
	}
	else {
		unsigned int vdeg = 0;
		for(int i = 0; i<n; i++) {
			if(matrix[v][i] != 0) {
				vdeg++;
			}
		}
		return vdeg;
	}
}

	/*
	Returns:
	1 if given vertices are connected by an egde
	0 if the vertices are not connected
	
	Error handling:
	throw std::invalid_argument with appropriate message if:
    - vertices do not exist

	Complexity O(1)
	*/
int AdjacencyMatrixGraph::areConnected(int v,int w)
{
	//place your code here
	if (w<0 || v<0 || w>=n || v>=n) {
		throw invalid_argument("ERROR 404: Vertices not found.");
	}
	else {
		if (matrix[w][v] != 0 || matrix[v][w] != 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
	 
	 /*
	Returns:
	the weight of an edge between given vertices.
	
	Error handling:
	throw std::invalid_argument with appropriate message if:
	- an edge does not exist
    - vertices do not exist

	Complexity O(1)
	*/
int AdjacencyMatrixGraph::getWeight(int u, int v)
{
	//place your code here
	if (u<0 || v<0 || u>=n || v>=n) {
		throw invalid_argument("ERROR 404: Vertices not found.");
	}
	else if (matrix[u][v] == 0 || matrix[v][u] == 0) {
		throw invalid_argument("ERROR 4042: Edge not found.");
	}
	else {
		return matrix[u][v];
	}
}

//////////////////////////////////////////////////////////////////////////////////
///////////  do not change those functions ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

Graph* AdjacencyMatrixGraph::clone()
{
	Graph *c = new AdjacencyMatrixGraph(*this); 		
	return c;
}
	
Graph* AdjacencyMatrixGraph::empty(int n=0)
{
	Graph *c = new AdjacencyMatrixGraph(n); 
	return c;
}