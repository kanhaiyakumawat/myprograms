#include <iostream>
#include <list>

using namespace std;


class Graph
{
	public:
		Graph(int v)
		{
			V = v;
			vertices = new list<int>[V];
			vertices[0].push_back(1);
			vertices[1].push_back(2);
			vertices[1].push_back(3);
		}
		void build_graph()
		{
			int opt = -1;
			for(int i = 0; i < V; i++)
			{
				while(1)
				{
					cout<<"Enter the vertex to which the current vertex "<<i<<" has directed edge or enter -1 to stop"<<endl;
					cin>>opt;
					if(opt <= -1 || opt >= V)
					{
						break;
					}
					else
					{
						vertices[i].push_back(opt);
					}
				}
			}
		}
		bool is_connected(int source, int dest)
		{
			bool *visited = new bool[V];
			for(int i = 0; i < V; i++)
			{
				visited[i] = false;
			}
			return is_connected(source, dest, visited);
		}
	private:
		bool is_connected(int curr, int dest, bool visited[])
		{
			if(visited[curr] == true)
			{
				return false;
			}
			else
			{
				visited[curr] = true;
			}
			for(list<int>::iterator iter = vertices[curr].begin(); iter != vertices[curr].end(); iter++)
			{
				if(*iter == dest)
				{
					return true;
				}
				else
				{
					return is_connected(*iter, dest, visited);
				}
			}
			return false;
		}
		list<int> *vertices;
		int V;
};

int main()
{
	Graph g(4);
	
	//g.build_graph();
	cout<<g.is_connected(0, 3)<<endl;
	return 0;
}
