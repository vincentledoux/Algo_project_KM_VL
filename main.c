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
#include <errno.h>
#include <conio.h>
#include <windows.h>
/*#define _GNU_SOURCE
#define _POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700*/
#define MAX_SIZE 60
#define M_PI 6400
#define degreesToRadians(Degrees) (Degrees * M_PI / 180.0)



//using namespace std;



// A structure to represent the Graph Nodes
typedef struct Node {
	char* title;
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
	/*Edge* before;
	Edge current;
	Edge* edgeList;*/

	Edge matrice[MAX_SIZE][MAX_SIZE];
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
Edge createEdge(Node node1, Node node2, double weight) {
	Edge edge;
	edge.weight = weight;
	edge.node1 = node1;
	edge.node2 = node2;
	return edge;
}


ssize_t getdelim(char **linep, size_t *n, int delim, FILE *fp){
    int ch;
    size_t i = 0;
    if(!linep || !n || !fp){
        errno = EINVAL;
        return -1;
    }
    if(*linep == NULL){
        if(NULL==(*linep = malloc(*n=128))){
            *n = 0;
            errno = ENOMEM;
            return -1;
        }
    }
    while((ch = fgetc(fp)) != EOF){
        if(i + 1 >= *n){
            char *temp = realloc(*linep, *n + 128);
            if(!temp){
                errno = ENOMEM;
                return -1;
            }
            *n += 128;
            *linep = temp;
        }
        (*linep)[i++] = ch;
        if(ch == delim)
            break;
    }
    (*linep)[i] = '\0';
    return !i && ch == EOF ? -1 : i;
}
ssize_t getline(char **linep, size_t *n, FILE *fp){
    return getdelim(linep, n, '\n', fp);
}

// A function to open and read the csv file
Node* displayFile(const char *file_name)
{
    size_t *thesize = 0;
	FILE *f = fopen(file_name, "r+");  // open the specified
	Node *tabPoint;
	tabPoint=malloc(sizeof(Node)*MAX_SIZE);
	char *c;
	int i = 0;
	char* titles = "a";
	double latitudes = 0;
	double longitudes = 0;
	if (f != NULL)
	{
		while (getline(&c,&thesize, f) != EOF)   // read character from file until EOF
		{
               printf("%s", c);
            char *str=c;
            if(i != 0){
            int j = 0;
            char *pt;
            pt = strtok (str,",");
            while (pt != NULL) {
               if(j==0){
               titles=pt;}
               else if(j==1){
               longitudes=atof(pt);
               printf("%f \n", longitudes);}
               else if(j==2){
               latitudes=atof(pt);
            }
               pt = strtok (NULL, ",");
               if(j==2)
               {
                   Node nodeadd;
                   nodeadd.latitude=latitudes;
                   nodeadd.longitude=longitudes;
                   nodeadd.numberOfTheCity=i;
                   nodeadd.visited=0;
                   nodeadd.title=titles;
                   tabPoint[i-1]=nodeadd;
                   printf("%f\n",tabPoint[i-1].latitude);
               }
               j++;
              }
            }
			i=i+1;

		}
	}
	fclose(f);
	return tabPoint;
}




// A function to display the graph in the console
void displayGraph(Graph graph) {
	int i = 0;
	int j = 0;
    printf("%f \n",graph.matrice[2][1].weight);
	//for in the matrix
	for(i=0; i<MAX_SIZE; ++i)
	{
		for (j = 0;j < MAX_SIZE;j++)
		{

			printf(" %f", graph.matrice[i][j].weight);
		}

		printf("\n");


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

		for (i = 0; i<MAX_SIZE; ++i) {
			for (j = 0; j<MAX_SIZE; ++j) {
                    //printf("%f \n", nodeList[j].latitude);
				Edge* edge =(Edge*)malloc(sizeof(Edge));
				*edge = createEdge(nodeList[i], nodeList[j], createWeight(nodeList[i], nodeList[j]));
                 printf("");
				//printf("%f \n", edge->node1.latitude);
				//printf("%f \n", nodeList[j].latitude);
				graph.matrice[i][j] = *edge;
			}
		}

	return graph;


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

	int vis[MAX_SIZE][MAX_SIZE]; // is_visited
	int val[MAX_SIZE][MAX_SIZE]; // cost at particular state
	int weight[MAX_SIZE][MAX_SIZE]; // given weight

	if (mask = (1 << n) - 1) { // all visited
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
	//		cost = dp(i, mask | (1 << i)) + weight[at][i]; //dp?
		//	if (ans > cost) ans = cost;
		}
	}

	return val[at][mask] = ans;
}





// Main function
int main()
{


menu();



	return 0;
}


int menu(void)
{
    int fin;



   fin = 0;
   while(!fin)
   {
      int c;

      /* menu */


      SetColor(35);

      printf("|================================================|\n"
             "|1.Display cities list and graph                 |\n"
             "|2.TSP 1 : exact method to find an exact solution|\n"
             "|3.TSP 2 : Lin-Kernighan heuristic               |\n"
             "|4.TSP 3 : Local search heuristic                |\n"
             "|5.Quit                                          |\n"
             "|================================================|\n\n");
   getch();
      c = getchar();


      if(c != '\n' && c != EOF)
      {
         int d;
         while((d = getchar()) != '\n' && d != EOF);
      }

      switch(c)
      {
         case '1':
            printf("Display cities list and graph\n");
            choice1();
            //system('PAUSE');
         // clrscr();
            break;

         case '2':
            printf("TSP 1\n");
            choice2();
            break;

         case '3':
            printf("TSP 2\n");
            choice3();
            break;

         case '4':
            printf("TSP 3\n");
            choice4();
            break;

         case '5':
            fin = 1;
            break;


         default:
            printf("Not a valid choice\n");
      }
   }

//choice1();
 system("PAUSE");
}


int choice1(void)
{
    	Node *n=displayFile("Cites.csv");
    	printf("%f \n",n[2].latitude);
	Graph graph=EdgeandGraph(n);
	displayGraph(graph);
	int vis[MAX_SIZE][MAX_SIZE]; // is_visited
	int val[MAX_SIZE][MAX_SIZE]; // cost at particular state
	int weight[MAX_SIZE][MAX_SIZE]; // given weight
	/*memset(vis, 0, sizeof(vis));
	memset(weight, -1, sizeof(weight));
	printf("Cost : %d\n", dp(0, 1));-*/
}



int choice2()
{

}

int choice3()
{


}

int choice4()
{

}
//Clear screen function if need be
void clrscr()
{
    system("@cls||clear");
}




// This world needs a little bit of color sometimes
void SetColor(int ForgC)
{
     WORD wColor;


     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
