#include "AdjacencyMatrixGraph.h"
#include <stdexcept>

bool isCycle(Graph* g, vector<int> cycle)
{
	int len = cycle.size();
	if (len==0)
		return true;

	if (len==1 || len==2)
		return false;
	
	for (int i=0; i< len -1; ++i)
		if (!g->areConnected(cycle[i], cycle[i+1]))
			return false;
	if (!g->areConnected(cycle[len-1], cycle[0]))
		return false;
	return true;
}

int main()
{
	Graph* g;

	g = new AdjacencyMatrixGraph(5);

	g->addEdge(0,1,5);
	g->addEdge(0,3,3);
	g->addEdge(1,3,2);
	g->addEdge(1,4,1);
	g->addEdge(3,4,7);
	g->addEdge(1,2,5);
	g->addEdge(2,4,3);

	g->show();

	g->getHamPath(0);
	
	delete g;

   system("pause");
   return 0;
}