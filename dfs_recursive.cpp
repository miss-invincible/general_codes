//this is a recursive code for depth first traversal
//in recursive traversal we dont need stack as recursive function itself acts like a stack

#include<iostream>
#include<vector>
#define max_vertices 100

using namespace std;

vector<vector<int> > adjacecy_list(max_vertices); //allocating space for ajacency list
bool visited[max_vertices] = {0};	//if there are multiple test cases then you would have to re-initialse it for everytest case
									//and do same with adjacecny list.

void call_dfs(int val)
{	int curr;
	curr = val;  //fetching the top-most element of the stack

	cout << curr << " "; //display the dfs


	for (int i = 0; i < adjacecy_list[curr].size(); i++)
	{
		if (visited[adjacecy_list[curr][i]] == 0)
		{
			visited[adjacecy_list[curr][i]] = 1;
			call_dfs(adjacecy_list[curr][i]);
		}
	}

}

int main()
{
	int number_of_vertices;
	int number_of_edges;
	int u, v;

	cin >> number_of_vertices;
	cin >> number_of_edges;

	//creating adjacency list for graph
	for (int i = 0; i < number_of_edges; i++)
	{
		cin >> u >> v;

		//do this when graph is undirected
		adjacecy_list[u].push_back(v);
		adjacecy_list[v].push_back(u);

		//do this when graph is directed
		// adjacecy_list[u].push_back(v);
	}

	//this is done when there are multiple connected components in a graph otherwise single starting point is enough to traverse whole graph .
	//simply put i=staing_of_the_graph.no need for loop
	// i m assuming that my vertices are (0 to N-1)
	for (int i = 0; i < number_of_vertices; i++)
	{
		if (visited[i] == 0) //if the vertex is unvisited then visit it
		{
			visited[i] = 1;
			call_dfs(i);
			cout << endl;
		}

	}



	return 0;


}
