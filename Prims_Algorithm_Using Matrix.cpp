#include <iostream>
# define V 9
using namespace std;

int find_min_edge(int key[V], bool visited[V]) {
  int min = 65535; int index = -1;
  
  for(int i=0; i<V; i++) {
    if(visited[i] == false && key[i] < min) {
      index = i;
      min = key[i];
    }
  }
  return index;
}

void prims(int graph[V][V]) {
  int parent[V]; int key[V]; bool visited[V];

  key[0] = 0;
  parent[0] = -1;
  visited[0] = false;

  for(int i=1; i<V; i++) {
    key[i] = 65535;
    visited[i] = false;
  }

  for(int i=0; i<V-1; i++) {
    int min_index = find_min_edge(key, visited);
    visited[min_index] = true;
    
    for(int j=0; j<V; j++) {
      if(graph[min_index][j] != 0 && visited[j] == false && graph[min_index][j] < key[j]) {
        parent[j] = min_index;
        key[j] = graph[min_index][j];
      }
    }
  }

  for(int i=1; i<V; i++) {
    cout<<parent[i]<<" - "<<i<<"\tWeight : "<<graph[i][parent[i]]<<endl;
  }
}

int main() {
  int graph[V][V] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0},
  };

  prims(graph);
}
