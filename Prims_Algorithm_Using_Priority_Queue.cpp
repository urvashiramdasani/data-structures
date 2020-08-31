#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> iPair;
int V;

void prims(vector <iPair> graph[]) {
  
  vector <int> key(V, 65535);
  vector <int> parent(V, -1);
  vector <bool> visited(V, false);
  priority_queue < iPair, vector<iPair>, greater<iPair> > q;

  q.push(make_pair(0, 0));
  key[0] = 0;
  parent[0] = 0;

  while(!q.empty()) {
    int min_vertex = q.top().second;
    q.pop();
    visited[min_vertex] = true;

    for(auto i: graph[min_vertex]) {
      int adj_vertex = i.first;
      int weight = i.second;

      if(visited[adj_vertex] == false && weight < key[adj_vertex] && weight != 0) {
        key[adj_vertex] = weight;
        parent[adj_vertex] = min_vertex;
        q.push(make_pair(weight, adj_vertex));
      }
    }
  }

  cout<<"Minimum Spanning Tree is \n";
  for(int i=1; i<V; i++) {
    cout<<parent[i]<<" - "<<i<<endl;
  }
}

int main() {
  cout<<"\nEnter the number of vertices : "; cin>>V;
  vector <iPair> graph[V];

  int weight;
  for(int i=0; i<V; i++) {
    for(int j=0; j<V; j++) {
      cout<<"\nEnter weight of edge between "<<i<<" and "<<j<<" : ";
      cin>>weight;
      graph[i].push_back(make_pair(j, weight));
    }
  }

  prims(graph); 
}
