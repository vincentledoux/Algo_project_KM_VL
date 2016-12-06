/* A C Program to solve the traveling salesman problem

Program :

Read data from the file.
Load it in data structure representing the graph


1. Find the maximum length path of the trip of traveling salesman problem starting
from "PARIS" and visits each city exactly once and returning to "PARIS.
(a) using an exact method to find an exact solution
(b) using Lin Kernighan heuristic
(c) using Local search heuristic.

2. Estimate the complexity of those algorithms.

3. Implement an algorithm to find the minimum spanning tree. This spanning tree
must contain the edge "PARIS �> SAINT GEORGES"
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 10000
#define M_PI 6400
#define degreesToRadians(Degrees) (Degrees * M_PI / 180.0)


//using namespace std;

// A structure to represent the Graph Nodes
typedef struct Node {
	char title;
	double latitude;
	double longitude;
	int numberOfTheCity;
	int visited;
}Node;


// A structure to represent the Graph Edges
typedef struct Edge {
	double weight;
	Node node1;
	Node node2;
}Edge;


typedef struct Graph {
    Edge* before;
    Edge current;
	Edge* edgeList;
}Graph;




/*

A function to create the nodes weight where
Omega is latitude, lambda is longitude, R is earth radius (mean radius = 6,371km);
Coordinates are in degrees and are converted to radians in order for this formula to work

Using the Pythagorean theorem, the program finds distances between nodes to extrapolate
the edges weight for the graph

Formula

*/

double createWeight(Node node1, Node node2)
{
	double lambda1 = degreesToRadians(node1.longitude);
	double lambda2 = degreesToRadians(node2.longitude);
	double omega1 = degreesToRadians(node1.latitude);
	double omega2 = degreesToRadians(node2.latitude);
	double R = 6371e3;

	double x = (lambda1 - lambda2) * cos((omega1 + omega2) / 2);
	double y = (omega2 - omega1);
	double d = sqrt(x*x + y*y) * R;

	return d;
}



// A utility to create an edge for two nodes into the graph
Edge createEdge(Node node1, Node node2, double weight, Graph graph) {
	Edge edge;
	edge.weight = weight;
	edge.node1 = node1;
	edge.node2 = node2;
	return edge;
}


// A function to open and read the csv file
Node[1000] displayFile(const char *file_name)
{
	FILE *f = fopen(file_name, "r");  // open the specified
	Node tabPoint[MAX_SIZE];
	char c[1000];
	int i = 0;
	char title = "";
	double latitude = 0;
	double longitude = 0;
	if (f != NULL)
	{


		while (getline(f, c))   // read character from file until EOF
		{

			printf("%s", c);
			// printf("sizeof(intArr)=%u", sizeof(c)):

			sscanf_s(c, "%s[^;]|%lf[^;]|%lf", title, latitude, longitude);
			tabPoint[i]->title = title;
			tabPoint[i]->latitude = latitude;
			tabPoint[i]->longitude = longitude;
			tabPoint[i]->numberOfTheCity;
			++i;

		}
	}
	fclose(f);
	return tabPoint;
}



// A utility to create the graph
Graph createGraph(int n) {
	Graph graph;
	graph.edgeList=malloc(sizeof(edge)*n);
    return graph;
}


// A utility to add an edge to the graph
Graph addEdge(Node* nodeList, Graph graph,int n) {
	return graph;
	int i=0
	While(nodeList!=NULL)
	{
	    if(graph.current==NULL)
         {
             graph.edgeList=graph.current;
             graph.current=nodeList[i]

         }
        else{
	    while(graph.edgeList!=null)
        {
            graph.current=graph.edgeList;
        }
        graph.current=nodeList[i];
      }
         ++i;
	}

}

// A function to display the graph in the console
void displayGraph(Graph graph, Node* nodeList) {
	int i = 0;
	int n = Length(nodeList);
	double **matrix = (float **)malloc(sizeof(double *) * n);
	for (i = 0; i < n; ++i) {
		matrix[i] = (double *)malloc(sizeof(double) * n);
	}


	while (graph.edge != NULL) {
		matrix[graph.edge->node1.numberOfTheCity][graph.edge->node1.numberOfTheCity] = graph.edge->weight;
		printf("weight of the edge is: %s from: %s to: %s", matrix[graph.edge->node1.numberOfTheCity][graph.edge->node1.numberOfTheCity]);

	}


	for (i = 0; i<n; ++i) {
		//for (i
	}
}

int Length(Node* node) {
	int l = sizeof(node) / sizeof(node[0]);
	return l;
}


// A function to create every edges from the .csv file
Graph EdgeandGraph(Node* nodeList) {
	Graph graph;
	int i = 0;
	int j = 0;

	Edge edge;
	while (nodeList != NULL) {
		for (i = 0; i<Length(nodeList); ++i) {
			for (j = 0; j<Length(nodeList); ++i) {
				edge = createEdge(nodeList[i], nodeList[j], createWeight(nodeList[i], nodeList[j]), graph);
			}
		}

		//point 1->2 in the graph
		//point 1->3 in the graph
		//point 2->3 ......
		//.. pour tout

	}



}


// A function that chooses the longest path
void longestPath() {

}

/*
bool vis[CITY][1 << CITY]; // is_visited
int val[CITY][1 << CITY]; // cost at particular state
int weight[CITY][CITY]; // given weight
*/

// A function that chooses the shortest path, resolving TSP
int TSP(int at, int mask, int n)
{

	int vis[1000][1000]; // is_visited
	int val[1000][1000]; // cost at particular state
	int weight[1000][1000]; // given weight
	if (mask == (1 << n) - 1) { // all visited
		vis[at][mask] = 1;
		return val[at][mask];
	}

	if (vis[at][mask]) return val[at][mask];
	vis[at][mask] = 1;//true

	int ans = -1;//inf
	int cost;
	int i = 0;
	for (i = 0; i < n; i++) {
		if (weight[at][i] != -1 && (mask & (1 << i)) == 0) {
			cost = dp(i, mask | (1 << i)) + weight[at][i];
			if (ans > cost) ans = cost;
		}
	}

	return val[at][mask] = ans;
}


// Main function
int main()
{
	displayFile("Cites.csv");
	/*
	memset(vis, 0, sizeof(vis));
	memset(weight, -1, sizeof(weight));
	printf("Cost : %d\n", dp(0, 1));
	*/

	return 0;
}

