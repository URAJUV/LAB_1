// Kruskal's MST (Minimum Spanning Tree) algorithm

#include <stdio.h>

#define MAX 30

/* Initialize the functions and variables*/
void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort_edges();
void print_data();

/* Structure to Store edges */
typedef struct edge {
  int u, v, w;
} edge;

/* Structure to Store edge list */
typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;

int n;
edge_list spanlist;

int Graph[MAX][MAX] = {
	{ 0,4,4,0,0,0,0},
	{ 4,0,2,0,0,0,0},
	{ 4,2,0,3,4,0,0},
	{ 0,0,3,0,3,0,0},
	{ 0,0,4,3,0,0,0},
	{ 0,0,2,0,3,0,0}};


/* Krushkal Algorith */
void kruskalAlgo() {
  int belongs[MAX], i, j, colno1, colno2;
  elist.n = 0;

  /* Traverse throught graph */
  for (i = 0; i < n; i++)
    for (j = 0; j < i; j++) {
      if (Graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }

  /* Sort the edges for greedy process */
  sort_edges();

  /* Here we have to first see if by adding an edge creates a cycle */
  /* every node initially belongs to itself */
  for (i = 0; i < n; i++) {
    belongs[i] = i;
  }

  /* Initialize the spanning tree size as 0 */
  spanlist.n = 0;

  for (i = 0; i < elist.n; i++) {
    colno1 = find(belongs, elist.data[i].u);
    colno2 = find(belongs, elist.data[i].v);

    if (colno1 != colno2) {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, colno1, colno2);
    }
  }
}

int find(int belongs[], int vertexno) {
  return (belongs[vertexno]);
}

/* To detect cycles */
void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

/* Sort the edges we are doing a normal selection sort here */
void sort_edges() {
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

/* Printing the result */
void print_data() {
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\n The minimum Spanning tree cost: %d\n", cost);
}

int main() {
  int i, j, total_cost;

  /* Number of verticies */
  n = 6;
  kruskalAlgo();
  print_data();
}
