// Implement Union, Intersection, Complement, Subtraction of two graphs.

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
	}
}

// Function to print a graph - Complexity = O(V * E)
void printGraph(vector <int> G[], int V) {
	for(int v = 0; v < V; v++) {
		cout << "\n Adjacency list of vertex "<< v<< "\n head";
		for (auto i : G[v]) cout << " -> " << i;
		cout<<endl;
	}
}

// Function to find Union of two graphs - Complexity = O(V * E)
void graphUnion(vector <int> G1[], vector <int> G2[], vector <int> G3[], int V) {
	for(int v = 0; v < V; v++) {
		for(int i = 0; i < G1[v].size(); i++) G3[v].push_back(G1[v][i]);
	}

	for(int v = 0; v < V; v++) {
		for(int i = 0; i < G2[v].size(); i++) {
			vector<int>::iterator it;
			it = find(G3[v].begin(), G3[v].end(), G2[v][i]);
			if(it == G3[v].end()) G3[v].push_back(G2[v][i]);
		}
	}
}

// Function to find Union of two graphs - Complexity = O(V ^ 2)
void graphIntersection(vector <int> G1[], vector <int> G2[], vector <int> G4[], int V) {
	for(int v = 0; v < V; v++) {
		for(int i = 0; i < V; i++) {
			vector<int>::iterator it1, it2;
			it1 = find(G1[v].begin(), G1[v].end(), i);
			it2 = find(G2[v].begin(), G2[v].end(), i);
			if(it1 != G1[v].end() && it2 != G2[v].end()) G4[v].push_back(i);
		}
	}
}

// Function to find Union of two graphs - Complexity = O(V ^ 3)
void graphComplement(vector <int> G1[], vector <int> G5[], int V) {
	for(int v = 0; v < V; v++) {
		vector<int>::iterator it;
		for(int i = 0; i < V; i++) {
			if(i != v) {
				it = find(G1[v].begin(), G1[v].end(), i);
				if(it == G1[v].end()) G5[v].push_back(i);
			}
		}
	}
}

// Function to find Union of two graphs - Complexity = O(V ^ 2)
void graphSubtraction(vector <int> G1[], vector <int> G2[], vector <int> G6[], int V) {
	for(int v = 0; v < V; v++) {
		for(int i = 0; i < V; i++) {
			vector<int>::iterator it1, it2;
			it1 = find(G1[v].begin(), G1[v].end(), i);
			it2 = find(G2[v].begin(), G2[v].end(), i);
			if(it1 != G1[v].end() && it2 == G2[v].end()) G6[v].push_back(i);
		}
	}
}

int main() {
	int V;
	cout<<"Enter the number of vertices in graphs : ";
	cin>>V;

	vector <int> G1[V], G2[V], G3[V], G4[V], G5[V], G6[V];

	cout<<"\nEnter the edges in G1 (u, v) [Enter (-1, -1) to terminate]: ";
	insertEdge(G1);

	cout<<"\nEnter the edges in G2 (u, v) [Enter (-1, -1) to terminate]: ";
	insertEdge(G2);

	cout<<"\nThe Graph G1 is : \n";
	printGraph(G1, V);

	cout<<"\nThe Graph G2 is : \n";
	printGraph(G2, V);

	graphUnion(G1, G2, G3, V);
	cout<<"\nThe Union of G1 and G2 is : ";
	printGraph(G3, V);

	graphIntersection(G1, G2, G4, V);
	cout<<"\nThe Intersection of G1 and G2 is : ";
	printGraph(G4, V);

	graphComplement(G1, G5, V);
	cout<<"\nThe Complement of G1 is : ";
	printGraph(G5, V);

	graphSubtraction(G1, G2, G6, V);
	cout<<"\nThe Subtraction of G2 from G1 is : ";
	printGraph(G6, V);
}
