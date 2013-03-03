#include <iostream>

using namespace std;

class Graph
{
public:
Graph(int n)
{
N = n;
nodes = new list<int>[N];
}
int N;
void fill_graph();
std::list<int> *nodes;
}
void dijkstra(const Graph &G, const int source, const int destination, int min)
{
}
