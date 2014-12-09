#include <stdio.h>
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

class Graph
{
public:
	/*
	Adds an edge between given vertices. Third argument is a weight of an edge (1 by default).
	If the edge already exists or we try to add a loop, no edge is added.
	
	Error handling:
	throw std::invalid_argument with appropriate message if:
	- we try to create a loop
	- there are no such vertices
	- if the edge already exists
	*/
	 virtual void addEdge(int u,int v,int weight=1) =0;

	 /*	
	 Removes an edge between given vertices. 
	 If the edge does not exist, nothing is changed.

	 Error handling:
	 throw std::invalid_argument with appropriate message if:
	 - an edge does not exist
	 - vertices do not exist
	 */
	 virtual void removeEdge(int, int) =0;
	
	/*
	Returns:
	1 if given vertices are connected by an egde
	0 if the vertices are not connected
	
	Error handling:
	throw std::invalid_argument with appropriate message if:
    - vertices do not exist
	*/
	 virtual int areConnected(int,int) =0;

	 /*
	Returns:
	the weight of an edge between given vertices.
	
	Error handling:
	throw std::invalid_argument with appropriate message if:
	- an edge does not exist
    - vertices do not exist
	*/
	 virtual int getWeight(int,int) =0;

	 /*
	 Prints the representation of a graph.
	 */
	virtual void show() =0;	  


	/*
	Returns the number of vertices in a graph.
	*/
	 virtual int getVerticesCount() =0;

	 /*
	Returns the number of edges in a graph.
	*/
	 virtual int getEdgesCount() =0;	
	 
	 /*
	 Returns:
	 degree of the given vertex
	 
	 Error handling:
	 throw std::invalid_argument with appropriate message if:
    - vertex does not exist
	 */
	virtual int getDegree(int) =0;	

	/* Return a pointer to the clone of the graph (with the same representation) */
	virtual Graph* clone() =0;

	/* Return a pointer to the empty graph with n vertices and the same representation */
	virtual Graph* empty(int) =0;

/*************************************************************/

	/*
	Adds new isolated vertex to a graph.
	*/
	 virtual void addVertex() =0;

	/*
	Removes given vertex from the graph and all the edges containing it.
	The remaining vertices change their numbers - e.g. if we delete vertex 3, the vertex 4 becomes vertex 3, vertex 7 becomes vertex 6 and so on.
	
	Error handling:
	 throw std::invalid_argument with appropriate message if:
    - vertex does not exist
	*/
	 virtual void removeVertex(int) =0;

    /*
	Returns:
	a vector of neighbors of a given vertex (for isolated vertex this vector is empty)
	
	Error handling:
	 throw std::invalid_argument with appropriate message if:
    - vertex does not exist
	*/
	virtual vector<int> getNeighbors(int) =0;
		
	/*
	Returns the maximum (minimum) degree in a graph.
	If the graph is empty, returned value is not specified.
	*/
	virtual int getMaxDeg() =0;
	virtual int getMinDeg() =0;
	
	/*
	Returns the number of the vertex with maximum (minimum) degree in a graph.
	If the graph is empty, returned value is not specified.
	*/
	virtual int getMaxDegVert() =0;
	virtual int getMinDegVert() =0;

	/*********************************************************************
	Task 05a
	*********************************************************************/

	Graph* closure();
	bool arePathConnected(int u, int v);
	bool isTree();


	/*********************************************************************
	Task 06
	*********************************************************************/

	vector<int> findCycle();
	vector<int> findShortestPath(int from, int to);

	vector<int> getHamPath(int start);

};