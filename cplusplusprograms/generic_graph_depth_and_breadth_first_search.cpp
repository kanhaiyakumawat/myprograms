#include <list>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<typename T>
class Node
{
public:
	Node(){};
	~Node(){};
	void set_item(const T &t)
	{
		value = t;
	}
	T get_item() const
	{
		return value;
	}
private:
	T value;	
};

template<typename T>
class Graph
{
	public:
		Graph(vector<Node<T> > nodes)
		{
			this->nodes = nodes;
			this->V = nodes.size();
			cout<<"size of graph "<<V<<endl;
			vertices = new list<int>[V];
		}
		~Graph()
		{
		
		}
		void add_vertex(int s, int t)
		{
			if(s < 0 || t > V)
			{
				throw;
			}
			vertices[s].push_back(t);
		}
		bool breadth_first_search(int item)
		{
			cout<<"\n==== Starting Breadth First Search ===== "<<endl;
			queue<int> Q;
			Q.push(0);
			breadth_first_search(Q, item);
			//delete visited;
		}
		bool depth_first_search(int item)
		{
			cout<<"\n==== Starting Depth First Search ===== "<<endl;
			int *visited = new int(V);
			for (int i = 0; i < V; ++i)
			{
				visited[i] = false;
			}
			depth_first_search(visited, 0, item);
			//delete []visited;			
		}

	private:
		list<int> *vertices;
		vector<Node<T> > nodes;
		int V;
		bool depth_first_search(int visited[], int curr_vertex, T item)
		{
			cout<<"current vertex"<<curr_vertex<<endl;
			if(visited[curr_vertex] == true)
			{
				cout<<"didn't find any item"<<endl;
				return false;
			}
			else
			{
				visited[curr_vertex] = true;
			}
			if (nodes[curr_vertex].get_item() == item)
			{
				cout<<"found the item"<<endl;
				return true;
			}
			else
			{
				cout<<"size of the vertex "<<vertices[curr_vertex].size()<<endl;
				for (list<int>::iterator it = vertices[curr_vertex].begin(); it != vertices[curr_vertex].end(); it++)
				{
					cout<<"vertex value "<<*it<<endl;
					if(depth_first_search(visited, *it, item))
					{
						return true;
					}
					
				}
			}
			return false;
		}
		bool breadth_first_search(queue<int> Q, T item)
		{
			int curr_vertex;
			if(Q.empty() == true)
			{
				cout<<"didn't find any item"<<endl;
				return false;
			}
			else
			{
				curr_vertex = Q.front();
				Q.pop();
				cout<<"current vertex "<<curr_vertex<<endl; 
			}
			if (nodes[curr_vertex].get_item() == item)
			{
				cout<<"found the item"<<endl;
				return true;
			}
			else
			{
				cout<<"Number of children "<<vertices[curr_vertex].size()<<endl;
				for (list<int>::iterator it = vertices[curr_vertex].begin(); it != vertices[curr_vertex].end(); it++)
				{
					cout<<"Pushing to Q the vertex "<<*it<<endl;
					Q.push(*it);
					
					
				}
				breadth_first_search(Q, item);
			}
			return false;
		}
};


int main()
{
	vector<Node<int> > nodes;
	Node<int> node;
	node.set_item(2);
	nodes.push_back(node);
	node.set_item(5);
	nodes.push_back(node);
	node.set_item(7);
	nodes.push_back(node);
	node.set_item(9);
	nodes.push_back(node);
	node.set_item(4);
	nodes.push_back(node);
	
	Graph<int> g(nodes);
		g.add_vertex(0,1);
		g.add_vertex(0,2);
		g.add_vertex(1,4);
		g.add_vertex(2,3);
		/*g.add_vertex(1,6);
		g.add_vertex(2,7);
		g.add_vertex(2,8);
		g.add_vertex(3,9);
		g.add_vertex(3,10);*/
	//	g.depth_first_search(7);
	//	g.depth_first_search(12);
		g.breadth_first_search(9);
	//	g.breadth_first_search(15);
		return 0;
}
