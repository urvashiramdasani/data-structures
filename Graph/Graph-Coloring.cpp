// Practical 10 : Write a program to find the chromatic number of a given graph.

// Submitted By : 
// Name : Urvashi Ramdasani
// Roll Number : 18BCE247

// Import all libraries
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to insert an edge - Complexity = O(E)
void insertEdge(vector <int> G[]) {
	while(1) {
		int u, v; cin>>u>>v;
		if(u == -1 || v == -1) break;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

// Function to print a graph - Complexity = O(V * E)
void printGraph(vector <int> G[], int V) {
	for(int v = 0; v < V; v++) {
		cout << v;
		for (auto i : G[v]) cout << " -> " << i;
		cout << endl;
	}
}

// Function to find chromatic number of a graph
void chromatic_number(vector <int> G[], int V) {
	// vector to hold result of graph colors
	vector < int > result(V, -1);

	// Assign first color to first vertex
	result[0] = 0;

	// vector to view available colors
	vector < bool > taken(V, false);

	// For each vertex, remove colors of its adjacent and find the color left and color the 
	// vertex with that color
	for(int i = 1; i < V; i++) {
		vector < int >::iterator it;
		for(it = G[i].begin(); it != G[i].end(); it++) {
			if(result[*it] != -1) taken[result[*it]] = true;
		}

		for(int j = 0; j < V; j++) {
			if(!taken[j]) {
				result[i] = j;
				break;
			}
		}

		for(it = G[i].begin(); it != G[i].end(); it++) {
			if(result[*it] != -1) taken[result[*it]] = false;
		}
	}

	// Print colors
	cout << "\n Vertex -> Chromatic Number \n";
	for(int i = 0; i < V; i++) {
		cout << i << " -> " << result[i] << endl;
	}
}

int main() {
	// Input number vertices
	cout << "Enter the number of vertices in graph : ";
	int V; cin >> V;

	// Input the graph
	vector <int> G[V];
	cout << "\nEnter the edges in G1 (u, v) [Enter (-1, -1) to terminate]: ";
	insertEdge(G);

	// Print the graph
	cout << "\nThe entered graph is : \n";
	printGraph(G, V);

	// Find chromatic number
	chromatic_number(G, V);
}

/*

Enter the number of vertices in graph : 6

Enter the edges in G1 (u, v) [Enter (-1, -1) to terminate]: 0 1
0 3
0 5
1 2
1 4
2 5
2 3
3 4
-1 -1

The entered graph is : 
0 -> 1 -> 3 -> 5
1 -> 0 -> 2 -> 4
2 -> 1 -> 5 -> 3
3 -> 0 -> 2 -> 4
4 -> 1 -> 3
5 -> 0 -> 2

 Vertex -> Chromatic Number 
0 -> 0
1 -> 1
2 -> 0
3 -> 1
4 -> 0
5 -> 1

*/
