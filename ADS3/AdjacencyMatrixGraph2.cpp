#include "AdjacencyMatrixGraph.h"

/*
Adds new isolated vertex to a graph.
*/

void AdjacencyMatrixGraph::addVertex()
{
	vector<int> nvertex;
	for (int i = 0; i <= n; i++) {
		nvertex.push_back(0);
	}
	this->matrix.push_back(nvertex);
	for (int j = 0; j <= n; j++) {
		this->matrix.at(j).push_back(0);
	}	
	this->n++;
}


/*
Removes given vertex from the graph and all the edges containing it.
The remaining vertices change their numbers - e.g. if we delete vertex 3, the vertex 4 becomes vertex 3, vertex 7 becomes vertex 6 and so on.

Error handling:
throw std::invalid_argument with appropriate message if:
- vertex does not exist
*/

void AdjacencyMatrixGraph::removeVertex(int v)
{
	if (v<0 || v >= n) {
		throw invalid_argument("no such vertex");
	}
	this->matrix.erase(matrix.begin() + v);
	this->n--;
	for (int i = 0; i < n; i++) {
		this->matrix.at(i).erase(matrix.at(i).begin() + v);
	}
}

/*
Returns:
a vector of neighbors of a given vertex (for isolated vertex this vector is empty)

Error handling:
throw std::invalid_argument with appropriate message if:
- vertex does not exist
*/

vector<int> AdjacencyMatrixGraph::getNeighbors(int v)
{
	if (v<0 || v >= n) {
		throw invalid_argument("no such vertex");
	}
	vector<int> x;
	for (int i = 0; i < n; i++) {
		if (matrix[v][i] != 0) {
			x.push_back(i);
		}
	}
	return x;
}


/*
Returns the maximum (minimum) degree in a graph.
If the graph is empty, returned value is not specified.
*/
int AdjacencyMatrixGraph::getMaxDeg()
{
	if (n == 0) {
		return -1; // not specified result?
	}
	int maxDeg = 0;
	for (int i = 0; i < n; i++) {
		if (this->getDegree(i) > maxDeg) {
			maxDeg = this->getDegree(i);
		}
	}
	return maxDeg;
}
int AdjacencyMatrixGraph::getMinDeg()
{
	if (n == 0) {
		return -1; // not specified result?
	}
	int minDeg = this->getMaxDeg();
	for (int i = 0; i < n; i++) {
		if (this->getDegree(i) < minDeg) {
			minDeg = this->getDegree(i);
		}
	}
	return minDeg;
}

/*
Returns the number of the vertex with maximum (minimum) degree in a graph.
If the graph is empty, returned value is not specified.
*/
int AdjacencyMatrixGraph::getMaxDegVert()
{
	if (n == 0) {
		return -1; // not specified result?
	}
	for (int i = 0; i < n; i++) {
		if (this->getDegree(i) == this->getMaxDeg()) {
			return i;
		}
	}
}
int AdjacencyMatrixGraph::getMinDegVert()
{
	if (n == 0) {
		return -1; // not specified result?
	}
	for (int i = 0; i < n; i++) {
		if (this->getDegree(i) == this->getMinDeg()) {
			return i;
		}
	}
}