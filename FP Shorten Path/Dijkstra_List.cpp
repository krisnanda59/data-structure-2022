#include <iostream>
#include <list>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> intPair;

class Graph{
	int V;
	list<pair<int,int>> adj[21];
	string places[21];
	public:
	Graph(int v){
	    V = v;
	}

	void addVertex(string str, int u, int v, int w){
	    adj[u].push_back(make_pair(v, w));
	    places[v] = str;
	}

	void showAllVertex(){
	    for(int i = 1; i<=V;i++){
	    	cout << i << " :";
	        for(auto const &j: adj[i]){
	            cout << " " << j.first << " ";
	        }
	        cout << endl;
	    }
	}

	void djikstra(int src){
		priority_queue<intPair, vector<intPair>, greater<intPair> >
        q;
		q.push(make_pair(1, src));
		int dist[V];
		for(int i = 1; i<=V; i++){
		    dist[i] = 1000;
		}
		dist[src] = 1;

		while(!q.empty()){
			int u = q.top().second;
			q.pop();

			list<pair<int,int>> :: iterator i;
			for(i = adj[u].begin(); i != adj[u].end(); i++){
				int v = (*i).first;
				int w = (*i).second;
				if(dist[v] > dist[u] + w){
					dist[v] = dist[u] + w;
					q.push(make_pair(dist[v], v));
				}
			}
		}
		printf("Vertex Distance from Source\n");
    for (int i = 1; i <= V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
	}

};
int main(){
	Graph graph(20);
    graph.addVertex("rumah", 1, 1, 1);
	graph.addVertex("globalexindo", 1, 2, 2);
	graph.addVertex("ss rent car", 1, 10, 10);
    graph.addVertex("pos skk blok t", 1, 11, 11);
	graph.addVertex("globalexindo", 2, 2, 2);
	graph.addVertex("mestilo rent", 2, 3, 3);
	graph.addVertex("mestilo rent", 3, 3, 3);
    graph.addVertex("warkop cakher", 3, 4 ,4);
	graph.addVertex("warkop cakher", 4, 4, 4);
	graph.addVertex("rtech comp", 4, 5, 5);
    graph.addVertex("rvtech comp", 5, 5, 5);
    graph.addVertex("nasi goreng cak yud", 5, 7, 7);
    graph.addVertex("nasi goreng cak yud", 7, 7, 7);
    graph.addVertex("kost putri bu budi", 7, 8, 8);
    graph.addVertex("kost putri bu budi", 8, 8, 8);
    graph.addVertex("dokter gigi", 8, 9, 9);
    graph.addVertex("dokter gigi", 9, 9 ,9);
	graph.addVertex("ss rent car", 10, 10, 10);
    graph.addVertex("pos skk blok t", 11, 11, 11);
    graph.addVertex("p-6", 11, 12, 12);
    graph.addVertex("wisma flamboyan", 11, 13, 13);
    graph.addVertex("p-6", 12, 12, 12);
    graph.addVertex("wisma flamboyan", 13, 13, 13);
    graph.addVertex("nasi goreng flamboyan", 13, 14, 14);
    graph.addVertex("desember cake", 13, 15, 15);
    graph.addVertex("nasi goreng flamboyan", 14, 14, 14);
    graph.addVertex("pos satpam blok t", 14, 20, 20);
    graph.addVertex("pos satpam blok t", 20, 20, 20);
    graph.addVertex("alpu service", 20, 18, 18);
    graph.addVertex("alpu service", 18, 18, 18);
    graph.addVertex("kos putri bi yuti", 18, 19, 19);
    graph.addVertex("kos putri bi yuti", 19, 19, 19);
    graph.addVertex("desember cake", 15, 15, 15);
    graph.addVertex("ariesta", 15, 16, 16);
    graph.addVertex("ariesta", 16, 16, 16);
    graph.addVertex("bkk korea", 16, 6, 6);
    graph.addVertex("bkk", 6, 6, 6);
	graph.showAllVertex();
	int src;
	cout << "insert src : ";
	cin >> src;
    graph.djikstra(src);
}
