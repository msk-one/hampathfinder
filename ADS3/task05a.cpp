#include "Graph.h"
#include<queue>

/*
	A closure CG of a graph G is a graph with the same vertex set as G.
	Every connected component of G is represented by a clique in CG.
	
	Return a closure of a given graph (2 points). Do not change the input graph.
	Expected running time: O(n^5) (but, to tell the truth,
	with some effort you should be able to do this in O(n^2)).
*/
Graph* Graph::closure()
{
	Graph* g = this->clone();

	for (int i = 0; i < g->getVerticesCount(); i++) {
		for (int j = 0; j < g->getVerticesCount(); j++) {
			for (int k = 0; k < g->getVerticesCount(); k++) {
				if (g->areConnected(j, k) && j != k) {
					for (int l = 0; l < g->getVerticesCount(); l++) {
						if (g->areConnected(k, l) && !g->areConnected(j, l) && j != l && k != l) {
							g->addEdge(j, l);
						}
					}
				}
			}
		}
	}
	return g;
}

/*
	Returns true if there exists a path connecting vertices u and v or false otherwise.
	If the indices of vertices are wrong, throw invalid_argument.
	Do not care about the case when u==v.
	(1 point)
*/
bool Graph::arePathConnected(int u, int v)
{
	if (u < 0 || v < 0 || u >= this->getVerticesCount() || v >= this->getVerticesCount()) {
		throw invalid_argument("Error 404. Vertices not found.");
	}

	Graph* closed = closure();

	if (closed->areConnected(u, v)) {
		return true;
	}
	else {
		return false;
	}
}


/*
	Returns true if the graph is a tree or false otherwise.	
	(1 point)
*/
bool Graph::isTree()
{
	Graph* closed = this->closure();

	for (int i = 0; i < this->getVerticesCount(); i++) {
		for (int j = 0; j < this->getVerticesCount(); j++) {
			if (this->areConnected(i, j) && this->arePathConnected(i, j)) {
				this->removeEdge(i, j);
				if (this->arePathConnected(i, j)) {
					return false;
				}
			}
			if (!closed->areConnected(i, j) && i != j) {
				return false;
			}
		}
	}
	return true;
}

