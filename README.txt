To compile the code run
	make

RUN the Kruskal Algo
	./kruskal

Input Graph
Graph[MAX][MAX] = {
A { 0,4,4,0,0,0,0},
B { 4,0,2,0,0,0,0},
C { 4,2,0,3,4,0,0},
D { 0,0,3,0,3,0,0},
E { 0,0,4,3,0,0,0},
F { 0,0,2,0,3,0,0}};

Sample Output
0,1,2,3,4,5 map to A,B,C,D,E,F respectively

2 - 1 : 2
5 - 2 : 2
3 - 2 : 3
4 - 3 : 3
1 - 0 : 4

RUN the prim Algo
	./prim
Input Graph
G[V][V] = {
A {0, 10, 7,  0, 0},
B {10, 0, 95, 11, 42},
C {7, 95, 0,21, 76},
D {0, 11, 21, 0, 31},
E {0, 42, 76, 31, 0}};

Sample Output
0,1,2,3,4  map to A,B,C,D,E respectively
Edge : Weight
0 - 2 : 7
0 - 1 : 10
1 - 3 : 11
3 - 4 : 31

The algorithms will print the minimum spanning tree of a particular graph.
