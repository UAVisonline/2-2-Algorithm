//2016025069_Hwang_Hui_Su_11802

#include <iostream>

using namespace std;

typedef struct node
{
	int num;
	struct node* next;
}node;

typedef struct graph_node
{
	int vertex_num;
	int visit;
	node* next;
}graph_node;

void add_node(graph_node* vertex, int arg_num)
{
	node* temp = new node;
	temp->num = arg_num;
	temp->next = NULL;

	node* last = vertex->next;
	if (last == NULL)
	{
		vertex->next = temp;
	}
	else
	{
		while (1)
		{
			if (last->next == NULL)
			{
				last->next = temp;
				break;
			}
			else
			{
				last = last->next;
			}
		}
	}
}

void visit_node(graph_node* vertex, graph_node** graph)
{
	vertex->visit = 1;
	node* temp = vertex->next;
	while (temp != NULL)
	{
		int num = temp->num;
		if (graph[num - 1]->visit == 0)
		{
			visit_node(graph[num - 1], graph);
		}
		temp = temp->next;
	}
}

int main()
{
	int vertex, edge, result;
	graph_node** graph_vertex;
	cin >> vertex >> edge;
	graph_vertex = new graph_node*[vertex];
	for (int i = 0; i < vertex; i++)
	{
		graph_vertex[i] = new graph_node;
		graph_vertex[i]->vertex_num = i + 1;
		graph_vertex[i]->visit = 0;
		graph_vertex[i]->next = NULL;
	}
	for (int i = 0; i < edge; i++)
	{
		int connect_1, connect_2;
		cin >> connect_1 >> connect_2;
		add_node(graph_vertex[connect_1 - 1], connect_2);
		add_node(graph_vertex[connect_2 - 1], connect_1);
	}

	result = 0;
	for (int i = 0; i < vertex; i++)
	{
		if (graph_vertex[i]->visit == 0)
		{
			result++;
			visit_node(graph_vertex[i],graph_vertex);
		}
	}

	cout << result;

	return 0;
}