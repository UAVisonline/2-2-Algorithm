//2016025069_Hwang_Hui_Su_11802

#include <iostream>

using namespace std;

typedef struct edge
{
	int dest;
	int weight;
	struct edge* next;
}edge;

typedef struct node
{
	int visit;
	int value;
	int vertex;
	edge* adj_head;
	edge* adg_tail;
}node;

int answer = 0;

void add_edge(node* graph_node, int dest, int weight)
{
	edge* temp = new edge;
	temp->dest = dest;
	temp->weight = weight;
	temp->next = NULL;
	if (graph_node->adj_head == NULL)
	{
		graph_node->adj_head = graph_node->adg_tail = temp;
	}
	else if(graph_node->adj_head == graph_node->adg_tail)
	{
		graph_node->adg_tail = temp;
		graph_node->adj_head->next = temp;
	}
	else
	{
		graph_node->adg_tail->next = temp;
		graph_node->adg_tail = temp;
	}
}

void shortest_set(node* dest_node, int weight)
{
	if (dest_node->value == -1)
	{
		dest_node->value = weight;
	}
	else
	{
		if (dest_node->value > weight)
		{
			dest_node->value = weight;
		}
	}
}

void relaxing(node* src_node,node** graph)
{
	if (answer < src_node->value)
	{
		answer = src_node->value;
	}
	
	edge* temp = src_node->adj_head;
	while (temp != NULL)
	{
		int destination = temp->dest;
		int weights = temp->weight;
		shortest_set(graph[destination], weights + src_node->value);
		temp = temp->next;
	}
	src_node->visit = 1;
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	node** graph = new node*[vertices];
	for (int i = 0; i < vertices; i++)
	{
		graph[i] = new node;
		graph[i]->vertex = i;
		graph[i]->visit = 0;
		if (i == 0)
		{
			graph[i]->value = 0;
		}
		else
		{
			graph[i]->value = -1;
		}
		graph[i]->adj_head = NULL;
		graph[i]->adg_tail = NULL;
	}
	for (int i = 0; i < edges; i++)
	{
		int src, dest, weight;
		cin >> src >> dest >> weight;
		add_edge(graph[src - 1], dest-1, weight);
	}

	while (1)
	{
		int visit_vertex = -1;
		int min = -1;
		for (int i = 0; i < vertices; i++)
		{
			if (min == -1)
			{
				if (graph[i]->value != -1 && graph[i]->visit == 0)
				{
					visit_vertex = i;
					min = graph[i]->value;
				}
			}
			else
			{
				if (graph[i]->value != -1 && graph[i]->visit == 0)
				{
					if (graph[i]->value < min)
					{
						visit_vertex = i;
						min = graph[i]->value;
					}
				}
			}
		}
		
		
		if (visit_vertex == -1)
		{
			break;
		}
		else
		{
			relaxing(graph[visit_vertex],graph);
		}
	}

	cout << answer;


	return 0;
}
