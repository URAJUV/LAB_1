// Prim's Algorithm of finding minimum spanning tree (MST)

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

/* Define the infinity for the nodes */
#define INFINITY 99999

// number of vertices in graph
#define V 5

// Create a 2d array for adjacency matrix to represent graph
int G[V][V] = {
  {0, 10, 7,  0, 0},
  {10, 0, 95, 11, 42},
  {7, 95, 0,21, 76},
  {0, 11, 21, 0, 31},
  {0, 42, 76, 31, 0}};

int main() {
  int no_edge = 0;  // number of edge in the graph

  // create a array to track selected verticies
  // if nodes is selected value will be true otherwise false
  int selected[V];

  // set selected to all verticies as  false initially
  memset(selected, false, sizeof(selected));

  // the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph

  // choose 0th vertex and make it true
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  // print for edge and weight
  printf("Edge : Weight\n");

  while (no_edge < V - 1) {
    // For every vertex in the set S, find the all adjacent vertices
    // calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    // choose another vertex nearest to selected vertex  at step 1.

    int min = INFINITY;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }

  return 0;
}
