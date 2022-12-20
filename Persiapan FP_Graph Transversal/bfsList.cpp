#include <iostream>
#include <list>
#include <iterator>
#include <queue>
using namespace std;

class Graph
{
protected:
    int vertex;
    list<int> adj[100];

public:
    Graph(int v)
    {
        vertex = v;
    }

    
    void addVertex(int v1, int v2)
    {
        adj[v1].push_back(v2);
    }

    void showVertex()
    {
        for (int i = 1; i <= vertex; i++)
        {
            cout << i << " --> ";
            list<int>::iterator it; // iterator for list
            for (it = adj[i].begin(); it != adj[i].end(); it++)
            {
                cout << *it << " "; // *it is the value of the node/ngeakses pointer nya
            }
            cout << endl;
        }
    }

    void BFS(int start)
    {
        bool visited[100];
        // initialize all nodes as not visited
        for (int i = 1; i <= vertex; i++)
        {
            visited[i] = false;
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int front = q.front(); // get the front element
            list<int>::iterator it;
            for (it = adj[q.front()].begin(); it != adj[q.front()].end(); it++) // iterate through the list
            {
                if (!visited[*it]) // if the node is not visited
                {
                    q.push(*it);         // push the node to the queue
                    visited[*it] = true; // mark the node as visited
                }
                q.pop(); // remove the front element
            }
        }

    }
};


 
int main()
{
    Graph graf(21);
graf.addVertex(1, 2);
graf.addVertex(2, 3);
graf.addVertex(3, 4);
graf.addVertex(4, 5);
graf.addVertex(5, 7);
graf.addVertex(7, 8);
graf.addVertex(8, 9);
graf.addVertex(1, 10);
graf.addVertex(1, 11);
graf.addVertex(11, 12);
graf.addVertex(11, 13);
graf.addVertex(13, 14);
graf.addVertex(15, 16);
graf.addVertex(16, 6);
graf.addVertex(14, 20);
graf.addVertex(14, 21);
graf.addVertex(14, 18);
graf.addVertex(18, 19);
graf.addVertex(6, 10);
graf.addVertex(6, 19);
graf.addVertex(6, 4);
graf.addVertex(9, 19);
graf.addVertex(20, 18);
graf.addVertex(20, 21);
graf.addVertex(21, 12);

graf.showVertex();
    graf.BFS(1);
}
