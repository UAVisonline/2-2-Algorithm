//2016025069_Hwang_Hui_Su_11802

#include <iostream>

typedef struct num_node
{
	int num;
	struct num_node* prev;
	struct num_node* next;
}num_node;

typedef struct node
{
	int vertex;
	int visit; //0 = white, 1 = gray, 2 = black
	//num_node* in_degree;
	num_node* out_degree;
	int in_degree_num;
	int out_degree_num;
}node;

int number_of_node;
int* arr;

/*void add_in_degree(int in_num, node* node)
{
	num_node* temp = node->in_degree;
	if (temp == NULL)
	{
		num_node* new_node = new num_node;
		new_node->num = in_num;
		new_node->next = NULL;
		new_node->prev = NULL;
		node->in_degree = new_node;
	}
	else
	{
		while (1)
		{
			if (temp->prev == NULL && temp->next == NULL)
			{
				if (temp->num < in_num)
				{
					num_node* new_node = new num_node;
					new_node->num = in_num;
					new_node->next = NULL;
					new_node->prev = temp;
					temp->next = new_node;
				}
				else if (temp->num > in_num)
				{
					num_node* new_node = new num_node;
					new_node->num = in_num;
					new_node->next = temp;
					new_node->prev = NULL;
					temp->prev = new_node;
					node->in_degree = new_node;
				}
				break;
			}
			else if(temp->prev==NULL && temp->next!=NULL)
			{
				if (temp->num > in_num)
				{
					num_node* new_node = new num_node;
					new_node->num = in_num;
					new_node->next = temp;
					new_node->prev = NULL;
					temp->prev = new_node;
					node->in_degree = new_node;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			else if (temp->prev != NULL && temp->next != NULL)
			{
				if (temp->num > in_num)
				{
					num_node* new_node = new num_node;
					new_node->num = in_num;
					new_node->next = temp;
					new_node->prev = temp->prev;
					temp->prev->next = new_node;
					temp->prev = new_node;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			else if (temp->prev != NULL && temp->next == NULL)
			{
				if (temp->num < in_num)
				{
					num_node* new_node = new num_node;
					new_node->num = in_num;
					new_node->next = NULL;
					new_node->prev = temp;
					temp->next = new_node;
				}
				else if (temp->num > in_num)
				{
					num_node* new_node = new num_node;
					new_node->num = in_num;
					new_node->next = temp;
					new_node->prev = temp->prev;
					temp->prev->next = new_node;
					temp->prev = new_node;
				}
				break;
			}
		}
	}
	node->in_degree_num++;
}
*/

void add_out_degree(int out_num, node* node)
{
	num_node* temp = node->out_degree;
	if (temp == NULL)
	{
		num_node* new_node = new num_node;
		new_node->num = out_num;
		new_node->next = NULL;
		new_node->prev = NULL;
		node->out_degree = new_node;
	}
	else
	{
		while (1)
		{
			if (temp->prev == NULL && temp->next == NULL)
			{
				if (temp->num < out_num)
				{
					num_node* new_node = new num_node;
					new_node->num = out_num;
					new_node->next = NULL;
					new_node->prev = temp;
					temp->next = new_node;
				}
				else if (temp->num > out_num)
				{
					num_node* new_node = new num_node;
					new_node->num = out_num;
					new_node->next = temp;
					new_node->prev = NULL;
					temp->prev = new_node;
					node->out_degree = new_node;
				}
				break;
			}
			else if (temp->prev == NULL && temp->next != NULL)
			{
				if (temp->num > out_num)
				{
					num_node* new_node = new num_node;
					new_node->num = out_num;
					new_node->next = temp;
					new_node->prev = NULL;
					temp->prev = new_node;
					node->out_degree = new_node;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			else if (temp->prev != NULL && temp->next != NULL)
			{
				if (temp->num > out_num)
				{
					num_node* new_node = new num_node;
					new_node->num = out_num;
					new_node->next = temp;
					new_node->prev = temp->prev;
					temp->prev->next = new_node;
					temp->prev = new_node;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
			else if (temp->prev != NULL && temp->next == NULL)
			{
				if (temp->num < out_num)
				{
					num_node* new_node = new num_node;
					new_node->num = out_num;
					new_node->next = NULL;
					new_node->prev = temp;
					temp->next = new_node;
				}
				else if (temp->num > out_num)
				{
					num_node* new_node = new num_node;
					new_node->num = out_num;
					new_node->next = temp;
					new_node->prev = temp->prev;
					temp->prev->next = new_node;
					temp->prev = new_node;
				}
				break;
			}
		}
	}
	node->out_degree_num++;
}

int DFS(node* graph_node, node** graph)
{
	if (graph_node->visit == 0)
	{
		graph_node->visit = 1;
	}
	else if (graph_node->visit == 1)
	{
		return 1;
	}
	else if (graph_node->visit == 2)
	{
		return 0;
	}

	num_node* temp = graph_node->out_degree;
	while (temp != NULL)
	{
		graph[temp->num]->in_degree_num--;
		int value = DFS(graph[temp->num], graph);
		if (value == 1)
		{
			return 1;
		}
		temp = temp->next;
		graph_node->out_degree_num--;
	}
	arr[number_of_node - 1] = graph_node->vertex;
	graph_node->visit = 2;
	number_of_node--;

	return 0;
}

int main()
{
	int vertex, edge;
	std::cin >> vertex >> edge;
	number_of_node = vertex;
	node** graph = new node*[vertex];
	arr = new int[vertex];
	for (int i = 0; i < vertex; i++)
	{
		graph[i] = new node;
		graph[i]->vertex = i;
		graph[i]->visit = 0;
		graph[i]->in_degree_num = 0;
		graph[i]->out_degree_num = 0;
		//graph[i]->in_degree = NULL;
		graph[i]->out_degree = NULL;
	}

	for (int i = 0; i < edge; i++)
	{
		int out, in;
		std::cin >> out >> in;
		add_out_degree(in-1,graph[out-1]);
		//add_in_degree(out-1,graph[in-1]);
	}

	for (int i = 0; i < vertex; i++)
	{
		if (graph[i]->visit == 0)
		{
			if (DFS(graph[i], graph) == 1)
			{
				std::cout << 0;
				return 0;
			}
		}
	}

	std::cout << 1 << "\n";
	for (int i = 0; i < vertex; i++)
	{
		std::cout << arr[i] + 1 << " ";
	}

	return 0;
}
