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
must contain the edge "PARIS —> SAINT GEORGES"
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 10000
#define degreesToRadians(Degrees) (Degrees * M_PI / 180.0)


// A structure to represent the Graph Nodes
typedef struct Node{

char title;
double latitude;
double longitude;
int numberOfTheCity;
}Node;


// A structure to represent the Graph Edges
typedef struct Edge{
    double weight;
    char city1;
    char city2;
    int number_city1;
    int number_city2;
}Edge;

typedef struct Graph{
    Edge* edge;
}Graph;




/*

A function to create the nodes weight where
Omega is latitude, lambda is longitude, R is earth radius (mean radius = 6,371km);
Coordinates are in degrees and are converted to radians in order for this formula to work

Using the Pythagorean theorem, the program finds distances between nodes to extrapolate
the edges weight for the graph

Formula

*/

void createWeight(Node* node1, Node* node2, Edge* edge)
{


 double lambda1 = degreesToRadians(node1->longitude);
 double lambda2 = degreesToRadians(node2->longitude);
 double omega1 = degreesToRadians(node1->latitude);
 double omega2 = degreesToRadians(node2->latitude);
 double R = 6371e3;

 double x = (lambda1 - lambda2) * cos((omega1 + omega2)/2);
 double y = (omega2 - omega1);
 double d = sqrt(x*x + y*y) * R;

 edge->city1 = node1->title;
 edge->city2 = node2->title;
 edge->weight = d;
 edge->city_number1 = node1->numberOfTheCity;
 edge->city_number2 = node2->numberOfTheCity;
}


// A function to open and read the csv file
Node* void displayFile(const char *file_name)
{
    FILE *f = fopen(file_name, "r");  // open the specified
    Node* tabPoint[MAX_SIZE];
    char c[1000];
    int i=0;
      char title;
        double latitude, longitude;
    if (f != NULL)
    {


        while (getline(f, c)))     // read character from file until EOF
        {

            printf("%s",c);
           // printf("sizeof(intArr)=%u", sizeof(c)):

            scanf(c, "%s[^;]|%lf[^;]|%lf",title,latitude,longitude);
            tabPoint[i]->title=title;
            tabPoint[i]->latitude=latitude;
            tabPoint[i]->longitude=longitude;
            tabPoint[i]->numberOfTheCity;
            ++i;

            }
        }
        fclose(f);
    return tabPoint;
}

//function to add to the matrix the weight between each city
//false, to review
double** createAndMatrixNode(Graph graph, double** matrix){
    while(graph->edge != NULL){
        matrix[graph->edge->number_city1][graph->edge->number_city2]=graph->edge->weight;
    }
    return matrix;
}



// Main function
int main()
{
    displayFile("Cites.csv");


    return 0;
}

