#include "Graph.h"
#include <vector>

using namespace std;

class AdjacencyMatrixGraph: 
	public Graph
{
public:
	 /*
	 creates a graph with given number of vertices and no edges
	 */
	 AdjacencyMatrixGraph(int n=0);
	 /*
	 creates a copy of a given graph
	 */
	 AdjacencyMatrixGraph(const AdjacencyMatrixGraph&);	
	 ~AdjacencyMatrixGraph();					

	 void show() override; 	 
	 int getVerticesCount() override;			
	 
	 void addEdge(int,int,int) override;
	 void removeEdge(int, int) override;
	 int getEdgesCount() override;	
	 int getDegree(int) override;
	 int areConnected(int,int) override;		
	 int getWeight(int,int) override; 

	 Graph* clone() override;
	 Graph* empty(int) override;

/**************************************/
	void addVertex() override;
	void removeVertex(int) override;
	vector<int> getNeighbors(int) override;	
	int getMaxDeg() override;
	int getMinDeg() override;	
	int getMaxDegVert() override;
	int getMinDegVert() override;
	 
private:
	/*adjacency matrix*/

	
	vector<vector<int>> matrix;
	int n;
};