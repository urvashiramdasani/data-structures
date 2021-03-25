// Practical 4 : Write a program to find minimum cut-edges and vertices of the given graph.

// Name : Urvashi Ramdasani
// Roll Number : 18BCE247

// Import all libraries
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int G[10][10];

// Function to insert an edge
void insertEdge(int G[][10]) {

	while(1) {
		int u, v; cin >> u >> v;
		if(u == -1 || v == -1) break;
		G[u][v] = 1;
		G[v][u] = 1;
	}

}

// Function to print the graph
void printGraph(int G[][10], int V) {

	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) cout << G[i][j] << " ";
		cout << endl;
	}

}

// Utility function to check if graph is disconnected
bool isConnected(int G[][10], int V, int node) {

	int flag = 0;
	for(int i = 0; i < V; i++) {
		if(i == node) continue;
		for(int j = 0; j < V; j++) {
			if(j == node) continue;
			if(!G[i][j] && !G[j][i]) flag = 1;
			else {
				flag = 0;
				break;
			}
		}
		if(flag) return true;
	}

	return false;

}

// Utility function to check if graph is disconnected
bool isConnected2(int G[][10], int V, int node) {

	int sum = 0;
	for(int i = 0; i < V; i++) {
		if(i == node) continue;
		for(int j = 0; j < V; j++) {
			if(j == node) continue;
			sum += G[i][j];
		}
	}

	if(sum < V) return false;
	return true;

}

// Function to find cut vertices of the graph
void cutVertices(int G[][10], int V, int node) {

	int tmp[10][10];
	copy(&G[0][0], &G[0][0] + 10 * 10, &tmp[0][0]);

	for(int i = 0; i < V; i++) {
		tmp[node][i] = 0;
		tmp[i][node] = 0;
	}

	if(!isConnected2(tmp, V, node) || isConnected(tmp, V, node)) cout << node << " "; 
}

// Function to find cut edges of the graph
void cutEdges(int G[][10], int V) {

	int tmp[10][10];
	copy(&G[0][0], &G[0][0] + 10 * 10, &tmp[0][0]);

	for(int i = 0; i < V; i++) {
		for(int j = i + 1; j < V; j++) {
			if(tmp[i][j]){
				tmp[i][j] = 0;
				tmp[j][i] = 0;
				if(isConnected(tmp, V, -1)) cout << i << " -> " << j <<endl;
				copy(&G[0][0], &G[0][0] + 10 * 10, &tmp[0][0]);
			}
		}
	}
}

int main() {

	cout << "Enter the number of vertices in graph : "; 
	int V; cin >> V;

	// Initialize all the matrix values as 0
	memset(G, 0, sizeof(G[0][0]) * V * V);

	// Insert Graph
	cout << "\nEnter the edges (u, v) in graph [Enter -1 -1 to end] : ";
	insertEdge(G);

	// Print Graph
	cout << "\nGraph G is \n";
	printGraph(G, V);

	cout << "\nThe cut-vertices of the graph are : ";
	for(int i = 0; i < V; i++) cutVertices(G, V, i);

	cout << "\nThe cut-edges of the graph are : ";
	cutEdges(G, V);
}

/*

Enter the number of vertices in graph : 5

Enter the edges (u, v) in graph [Enter -1 -1 to end] : 0 1
0 2
0 3
1 2
3 4
-1 -1

Graph G is 
0 1 1 1 0 
1 0 1 0 0 
1 1 0 0 0 
1 0 0 0 1 
0 0 0 1 0 

The cut-vertices of the graph are : 0 3 
The cut-edges of the graph are : 3 -> 4

*/
