// Practical 3: Write a program to check whether two graphs are isomorphic are not.

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int G1[10][10], G2[10][10];

// Function to insert an edge
void insertEdge(int G[][10]) {
	while(1) {
		int u, v; cin>>u>>v;
		if(u == -1 || v == -1) break;
		G[u][v] = 1;
		G[v][u] = 1;
	}
}

// Function to print the graph
void printGraph(int G[][10], int V) {
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) cout<<G[i][j]<<" ";
		cout<<endl;
	}
}

// Utility function to find number of edges in a graph
int numEdges(int G[][10], int V) {
	int sum = 0;
	for(int i = 0; i < V; i++) {
		for(int j = 0; j < V; j++) sum += G[i][j];
	}
	return sum / 2;
}

// Utility function to find out the degree sequence of a graph
vector<int> degreeSequence(int G[][10], int V) {
	vector<int> degrees;
	for(int i = 0; i < V; i++) {
		int sum = 0;
		for(int j = 0; j < V; j++) sum += G[i][j];
		degrees.push_back(sum);
	}
	sort(degrees.begin(), degrees.end(), greater<int>());
	return degrees;
}

// Function to check Isomorphism
int checkIsomorphism(int G1[][10], int G2[][10], int V1, int V2) {

	// Check for number of vertices
	if(V1 != V2) return 0;

	// Check for number of edges
	if(numEdges(G1, V1) != numEdges(G2, V2)) return 0;

	vector<int> ds1 = degreeSequence(G1, V1);
	vector<int> ds2 = degreeSequence(G2, V2);

	// Check if degree sequence of G1 is equal to degree sequence of G2
	if(ds1 != ds2) return 0;
	return 1;
}

int main() {
	cout<<"Enter the number of vertices in G1 and G2 : "; 
	int V1, V2; cin>>V1>>V2;

	// Initialize all the matrix values as 0
	memset(G1, 0, sizeof(G1[0][0]) * V1 * V1);
	memset(G2, 0, sizeof(G2[0][0]) * V2 * V2);

	// Insert Graph
	cout<<"\nEnter the edges (u, v) in G1 [Enter -1 -1 to end]: ";
	insertEdge(G1);

	cout<<"\nEnter the edges (u, v) in G2 [Enter -1 -1 to end]: ";
	insertEdge(G2);

	// Print Graph
	cout<<"\nGraph G1 is \n";
	printGraph(G1, V1);

	cout<<"\nGraph G2 is \n";
	printGraph(G2, V2);

	int check = checkIsomorphism(G1, G2, V1, V2);
	if(check == 0) cout<<"\nG1 and G2 are not isomorphic";
	else cout<<"\nG1 and G2 are isomorphic";
}
