#include "Graph.h"
#include <queue>
#include <stack>

bool isSafe(int v, Graph *g, vector<int> ham, int pos) {
	if (!g->areConnected(ham[pos-1], v)) {
		return false;
	}

	for (int i = 0; i < pos; i++) {
		if (ham[i] == v) {
			return false;
		}
	}

	return true;
}

bool hamCycleUtil(Graph *g, vector<int> &ham, int pos) {
	if (pos == g->getVerticesCount()) {
		if (g->areConnected(ham[pos-1], ham[0])) {
			return true;
		}
		else {
			return false;
		}
	}

	for (int v = 0; v < g->getVerticesCount(); v++) {
		if (isSafe(v, g, ham, pos)) {
			ham[pos] = v;

			if (hamCycleUtil(g, ham, pos+1) == true) {
				return true;
			}

			ham[pos] = -1;
		}
	}

	return false; 
}

vector<int> Graph::getHamPath(int start)
{
	Graph* gc = this->clone();
	vector<int> hamilton;

	for (int i = 0; i < getVerticesCount(); i++) {
		hamilton.push_back(-1);
	}
	hamilton[0] = start;

	if (hamCycleUtil(gc, hamilton, 1) == false) {
		cout<<"Nope."<<endl;
	}
	else {
		cout << "FOUND IT! Hamiltonian path:" << endl;
		for (int i = 0; i < getVerticesCount(); i++) {
			cout << hamilton[i] << ", ";
		}
		cout << hamilton[0] << endl;
	}
	
	return hamilton;
}