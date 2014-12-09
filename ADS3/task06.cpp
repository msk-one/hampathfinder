#include "Graph.h"
#include <queue>
#include <stack>


/*
Checks if a given graph contains a cycle.
If a cycle is found, you should return its vertices,
ordered according to their position on the cycle.

Note that a single cycle can be represented in many ways,
for example a trangle with vertices 1,2,3 can be represented as:
1,2,3 or
2,3,1 or
3,1,2 etc.
All of them are correct.

If the graph contains co cycle, an empty vector is returned.

Hint: perform a depth-first-search.
(2.5 points)	
*/
vector<int> Graph::findCycle()
{
	vector<int> cycle;
	int vertices = getVerticesCount();
	if (vertices == 0) {
		return cycle;
	}
	if (getEdgesCount() == 0) {
		return cycle;
	}
	
	int *lvisit = new int[vertices];
	bool *visited = new bool[vertices];

	for (int i = 0; i < vertices; i++) {
		lvisit[i] = false;
		visited[i] = false;
	}
		
	stack<int> tmp;
	vector<int> neigh;
	tmp.push(0);

	while (!tmp.empty()) {
		int frnt = tmp.top();
		tmp.pop();
		visited[frnt] = true;
		neigh = getNeighbors(frnt);
		int nsize = neigh.size();

		for (int j = 0; j < nsize; j++) {
			if (lvisit[frnt] != false && lvisit[frnt] != neigh[j] && visited[neigh[j]] == true) {
				int tmp = neigh[j];
				lvisit[neigh[j]] = frnt;
		
				cycle.push_back(tmp);
				tmp = lvisit[tmp];
				
				while (tmp != neigh[j]) {
					cycle.push_back(tmp);
					tmp = lvisit[tmp];
				}
				return cycle;
			}

			if (visited[neigh[j]] == false) {
				lvisit[neigh[j]] = frnt;
				tmp.push(neigh[j]);
			}
		}
	}

	return cycle;
}


/*
Finds the shortest path between given vertices.
Returns the vertices on this path, starting from 'from' and finishing on 'to'.
If from=to, then one-element vector (containing 'from') is returned.
If there is not path between the vertices, an empty vector is returned.

Note that there may be more than one shortest path.
All of them are correct.

Hint: perform a breadth-first-search.
(2.5 points)	
*/
vector<int> Graph::findShortestPath(int from, int to)
{
	vector<int> path;
	queue<int> Q;

	if (from < 0 || from > this->getVerticesCount() || to < 0 || to > this->getVerticesCount()) {
		throw invalid_argument("Error 404. Vertices not found");
	}

	if (from == to) {
		path.push_back(from);
		return path;
	}

	if (arePathConnected(from, to) == false) {
		return path;
	}

	int top = 0;
	int vertices = getVerticesCount();
	int *lvisit = new int[vertices];
	bool *visited = new bool[vertices];

	for (int i = 0; i < vertices; i++) {
		visited[i] = false;
	}

	Q.push(from);
	lvisit[from] = 0;
	visited[from] = true;

	while (!Q.empty()) {
		top = Q.front();
		if (top == to) {
			break;
		}

		vector<int> tmp = getNeighbors(top);
		Q.pop();
		
		for (int j = 0; j < tmp.size(); j++) {
			if (visited[tmp[j]] == false) {
				visited[tmp[j]] = true;
				lvisit[tmp[j]] = top;
				Q.push(tmp[j]);
			}
		}
	}
	
	int par = to;
	int swp = 0;

	vector<int> tmp2;
	while (true) {
		tmp2.push_back(par);
		if (par == from)
			break;
		par = lvisit[par];
	}

	for (int k = tmp2.size(); k > 0; k--) {
		swp = tmp2.back();
		tmp2.pop_back();
		path.push_back(swp);
	}

	return path;
}

