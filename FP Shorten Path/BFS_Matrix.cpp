#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

class Graph{
	int V;
	int adjM[21][21] ={
          {0, 0},
          {0, 0}
    };
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}

	void addVertex(string str, int u, int v){
	    adjM[u][v] = v;
	    places[v] = str;
	}

	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	        for(int j = 1; j<=V;j++){
	            if(adjM[i][j] == 0) cout << ".  ";
	            else if (adjM[i][j] < 10) cout << adjM[i][j] << "  ";
	            else cout << adjM[i][j] << " ";
	        }
	        cout <<  endl;
	    }
	}

	bool shortest_path(int src, int dest, int pred[], int dist[]){
	queue<int> q;
	bool visited[V] = {false};
	dist[21] = {0};
	pred[21] = {-1};
	visited[src] = true;
	dist[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 1; i<=V; i++){
			if(visited[i] == false && adjM[u][i] != 0){
				visited[i] = true;
				dist[i] = dist[u] + 1;
				pred[i] = u;
				cout << u << " " << i << endl;
				q.push(i);
				if(i == dest) return true;
			}
		}
	}
	return false;
    }

    void shortestDistance(int src, int dest){
		int pred[V], dist[V];
		shortest_path(src, dest, pred, dist);
		vector<int> path;
		int c = dest;
		path.push_back(c);
		while(pred[c] != 0){
			path.push_back(pred[c]);
			c = pred[c];
		}
		for(int i = path.size() - 1; i >= 0; i--){
			cout << path[i] << " " << places[path[i]] << endl;
		}
}
};
int main(){
	Graph graph(20);
	graph.addVertex("rumah", 1, 1);
	graph.addVertex("globalexindo", 1, 2);
	graph.addVertex("ss rent car", 1, 10);
	graph.addVertex("pos skk blok t", 1, 11);
	graph.addVertex("mestilo rent", 2, 3);
	graph.addVertex("warkop cakher", 3, 4);
	graph.addVertex("rtech comp", 4, 5);
	graph.addVertex("nasi goreng cak yud", 5, 7);
	graph.addVertex("kos putri bu budi", 7, 8);
	graph.addVertex("dokter gigi", 8, 9);
	graph.addVertex("dokter gigi", 9, 9);
	graph.addVertex("ss rent car", 10, 10);
	graph.addVertex("p-6", 11, 12);
	graph.addVertex("p-6", 12, 12);
	graph.addVertex("wisma flamboyan", 11, 13);
	graph.addVertex("nasi goreng flamboyan", 13, 14);
	graph.addVertex("desember cake", 13, 15);
	graph.addVertex("pos satpam blok t", 14, 20);
	graph.addVertex("alpu service", 20, 18);
	graph.addVertex("kost putri biyuti", 18, 19);
	graph.addVertex("kos putri biyuti", 19, 19);
	graph.addVertex("ariesta", 15, 16);
	graph.addVertex("bkk korea", 16, 6);
	graph.addVertex("bkk korea", 6, 6);

	graph.showAllVertex();
	int source, dest;
	cin >> source >> dest;
    graph.shortestDistance(source,dest);
}
