#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define vertices 5

int findmin(int key[],bool mstSet[]) {
	int minKey = INT_MAX,min_index;
	for(int i=0;i<vertices;i++) {
		if(mstSet[i]==false && minKey>key[i]) {
			minKey = key[i];
			min_index = i;
		}
	}
	return min_index;
}

void printMST(int graph[vertices][vertices],int parent[]) {
	for(int i=1;i<vertices;i++) {
		printf("%d - %d : %d\n",parent[i],i,graph[i][parent[i]]);
	}
}

void primMST(int graph[vertices][vertices]) {
	int distance[vertices],parent[vertices];
	bool mstSet[vertices];
	for(int i=1;i<vertices;i++) {
		distance[i] = INT_MAX;
		mstSet[i] = false;
	}
	distance[0] = 0;
	parent[0] = -1;
	for(int i=0;i<vertices-1;i++) {
		int u = findmin(distance,mstSet);
		mstSet[u] = true;
			for(int j=0;j<vertices;j++) {
				if(graph[u][j]!=0 && mstSet[j]==false && graph[u][j]<distance[j]){
					parent[j] = u;
					distance[j] = graph[u][j];
				}
			}
	}
	printMST(graph,parent);
}

void main() {
	int graph[vertices][vertices];
	for(int i=0;i<vertices;i++) {
		for(int j=0;j<vertices;j++) {
			printf("\nEnter edge %d-%d : ",i,j);
			scanf("%d",&graph[i][j]);
		}
	}
	primMST(graph);
}