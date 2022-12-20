#include <iostream>
#include <list>

using namespace std;

class Graph
{
  int numVertices;
  list<int> *adjMatrix;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
    void showMatrix();
};

Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjMatrix = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
  adjMatrix[src].push_back(dest);
  adjMatrix[src].sort();
}

// BFS algorithm
void Graph::BFS(int startVertex)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty())
  {
    int currVertex = queue.front();
    // Fungsi memberhentikan BFS
    // if (currVertex == endVertex)
    // {
    //   break;
    // }
    //
    cout << "(V" << currVertex << ")";
    queue.pop_front();

    for (i = adjMatrix[currVertex].begin(); i != adjMatrix[currVertex].end(); ++i)
    {
      int adjVertex = *i;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

void Graph::showMatrix()
{
  for (int i = 0; i < numVertices; i++)
  {
    list<int>::iterator it;

    int track = 0;
    int through = 0;
    for (it = adjMatrix[i].begin(); it != adjMatrix[i].end(); ++it)
    {
      // int track = 0;
      int temp = *it;
      if (through == 0)
      {
        while (track < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      else
      {
        while ((track + 1) < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      cout << "1 ";
      through++;
    }
    while ((numVertices - through) > 0)
    {
      through++;
      cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{
Graph graf(22);
graf.addEdge(1, 2);
graf.addEdge(2, 3);
graf.addEdge(3, 4);
graf.addEdge(4, 5);
graf.addEdge(5, 7);
graf.addEdge(7, 8);
graf.addEdge(8, 9);
graf.addEdge(1, 10);
graf.addEdge(1, 11);
graf.addEdge(11, 12);
graf.addEdge(11, 13);
graf.addEdge(13, 14);
graf.addEdge(15, 16);
graf.addEdge(16, 6);
graf.addEdge(14, 20);
graf.addEdge(14, 21);
graf.addEdge(14, 18);
graf.addEdge(18, 19);
graf.addEdge(6, 10);
graf.addEdge(6, 19);
graf.addEdge(6, 4);
graf.addEdge(9, 19);
graf.addEdge(20, 18);
graf.addEdge(20, 21);
graf.addEdge(21, 12);

  graf.BFS(1);
  cout << endl;
  graf.showMatrix();

  return 0;
}