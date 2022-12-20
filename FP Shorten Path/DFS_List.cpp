#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
using namespace std;

class Graph {
    protected:
        int v;
        vector<string> place;
        vector<list<int>> adj;
        map<pair<int,int>, int> weight;
        vector<int> dfsResult;
        int dfsWeight;
        vector<int> dijkstraRes;

    public:
        Graph(int len) {
            v = len;
            place.assign(v+1, "");
            list<int> l;
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }

        void addVertex(string i, int u, int v, int w){
            adj[u].push_back(v);
            weight.insert({make_pair(u,v), w});
            place[v] = i;
        }

        void showGraph(){
            for (int i = 1; i <= v; i++)
            {
                list<int>::iterator it;
                cout << i << " => ";
                for (it = adj[i].begin(); it != adj[i].end(); it++)
                {
                    cout << *it << "(" << weight[make_pair(i, *it)] << ") ";
                }
                cout << endl;
            }
        }

        void DFS(int start, int end){
            cout << endl;
            cout << "## Shortest path using DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );

            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << dfsResult[i] << " ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout <<  path[i] << " ";
                }
                cout << endl;
            }
            visited[start] = true;
            path.push_back(start);
            list<int>::iterator it;
            for ( it = adj[start].begin(); it != adj[start].end(); it++)
            {
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
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
    graph.showGraph();

    int start, end;
    cin >> start >> end;
    graph.DFS(start, end);


}
