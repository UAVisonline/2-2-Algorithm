//2016025069_Hwang_Hui_Su_11802

#include <iostream>

using namespace std;

typedef struct edge
{
	int src;
	int dest;
	int weight;
}edge;

typedef struct node
{
	edge adj;
	struct node* next;
	struct node* prev;
}node;

node* head = NULL;
node* tail = NULL;


void Insert_Min_Heap(edge* heap, int size, edge node)
{
	heap[size].src = node.src;
	heap[size].dest = node.dest;
	heap[size].weight = node.weight;

	while (size > 0)
	{
		int prev = (size - 1) / 2;
		if (heap[prev].weight > heap[size].weight)
		{
			edge temp;
			temp.src = heap[prev].src;
			temp.dest = heap[prev].dest;
			temp.weight = heap[prev].weight;

			heap[prev].src = heap[size].src;
			heap[prev].dest = heap[size].dest;
			heap[prev].weight = heap[size].weight;

			heap[size].src = temp.src;
			heap[size].dest = temp.dest;
			heap[size].weight = temp.weight;

			size = prev;
		}
		/*else if (heap[prev].weight == heap[size].weight)
		{
			if (heap[prev].src > heap[size].src)
			{
				edge temp;
				temp.src = heap[prev].src;
				temp.dest = heap[prev].dest;
				temp.weight = heap[prev].weight;

				heap[prev].src = heap[size].src;
				heap[prev].dest = heap[size].dest;
				heap[prev].weight = heap[size].weight;

				heap[size].src = temp.src;
				heap[size].dest = temp.dest;
				heap[size].weight = temp.weight;

				size = prev;
			}
			else if (heap[prev].src == heap[size].src)
			{
				if (heap[prev].dest > heap[size].dest)
				{
					edge temp;
					temp.src = heap[prev].src;
					temp.dest = heap[prev].dest;
					temp.weight = heap[prev].weight;

					heap[prev].src = heap[size].src;
					heap[prev].dest = heap[size].dest;
					heap[prev].weight = heap[size].weight;

					heap[size].src = temp.src;
					heap[size].dest = temp.dest;
					heap[size].weight = temp.weight;

					size = prev;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}*/
		else
		{
			break;
		}
	}
}

void delete_heap(edge* heap, int size)
{
	if (size == 0)
	{
		return;
	}
	
	heap[0].dest = heap[size - 1].dest;
	heap[0].src = heap[size - 1].src;
	heap[0].weight = heap[size - 1].weight;

	int pos = 0;
	while (pos < size - 1)
	{
		edge temp; 
		if (size - 1 >= (pos + 1) * 2)
		{
			int tmp_pos;
			if (heap[2 * pos + 1].weight > heap[2 * (pos + 1)].weight)
			{
				tmp_pos = 2 * (pos + 1);
			}
			else if (heap[2 * pos + 1].weight < heap[2 * (pos + 1)].weight)
			{
				tmp_pos = 2 * pos + 1;
			}
			else
			{
				if (heap[2 * pos + 1].src > heap[2 * (pos + 1)].src)
				{
					tmp_pos = 2 * (pos + 1);
				}
				else if (heap[2 * pos + 1].src < heap[2 * (pos + 1)].src)
				{
					tmp_pos = 2 * pos + 1;
				}
				else
				{
					if (heap[2 * pos + 1].dest > heap[2 * (pos + 1)].dest)
					{
						tmp_pos = 2 * (pos + 1);
					}
					else
					{
						tmp_pos = 2 * pos + 1;
					}
				}
			}

			if (heap[pos].weight > heap[tmp_pos].weight)
			{
				temp.src = heap[tmp_pos].src;
				temp.dest = heap[tmp_pos].dest;
				temp.weight = heap[tmp_pos].weight;

				heap[tmp_pos].src = heap[pos].src;
				heap[tmp_pos].dest = heap[pos].dest;
				heap[tmp_pos].weight = heap[pos].weight;

				heap[pos].src = temp.src;
				heap[pos].dest = temp.dest;
				heap[pos].weight = temp.weight;

				pos = tmp_pos;
			}
			else if (heap[pos].weight < heap[tmp_pos].weight)
			{
				break;
			}
			else
			{
				if (heap[pos].src > heap[tmp_pos].src)
				{
					temp.src = heap[tmp_pos].src;
					temp.dest = heap[tmp_pos].dest;
					temp.weight = heap[tmp_pos].weight;

					heap[tmp_pos].src = heap[pos].src;
					heap[tmp_pos].dest = heap[pos].dest;
					heap[tmp_pos].weight = heap[pos].weight;

					heap[pos].src = temp.src;
					heap[pos].dest = temp.dest;
					heap[pos].weight = temp.weight;

					pos = tmp_pos;
				}
				else if (heap[pos].src < heap[tmp_pos].src)
				{
					break;
				}
				else
				{
					if (heap[pos].dest > heap[tmp_pos].dest)
					{
						temp.src = heap[tmp_pos].src;
						temp.dest = heap[tmp_pos].dest;
						temp.weight = heap[tmp_pos].weight;

						heap[tmp_pos].src = heap[pos].src;
						heap[tmp_pos].dest = heap[pos].dest;
						heap[tmp_pos].weight = heap[pos].weight;

						heap[pos].src = temp.src;
						heap[pos].dest = temp.dest;
						heap[pos].weight = temp.weight;

						pos = tmp_pos;
					}
					else
					{
						break;
					}
				}
			}
		}
		else if (size - 1 == (pos * 2) + 1)
		{
			if (heap[pos].weight >= heap[2 * pos + 1].weight)
			{
				if (heap[pos].weight > heap[2 * pos + 1].weight)
				{
					temp.src = heap[2 * pos + 1].src;
					temp.dest = heap[2 * pos + 1].dest;
					temp.weight = heap[2 * pos + 1].weight;

					heap[2 * pos + 1].src = heap[pos].src;
					heap[2 * pos + 1].dest = heap[pos].dest;
					heap[2 * pos + 1].weight = heap[pos].weight;

					heap[pos].src = temp.src;
					heap[pos].dest = temp.dest;
					heap[pos].weight = temp.weight;

					pos = 2 * pos + 1;
				}
				else
				{
					if (heap[pos].src > heap[2 * pos + 1].src)
					{
						temp.src = heap[2 * pos + 1].src;
						temp.dest = heap[2 * pos + 1].dest;
						temp.weight = heap[2 * pos + 1].weight;

						heap[2 * pos + 1].src = heap[pos].src;
						heap[2 * pos + 1].dest = heap[pos].dest;
						heap[2 * pos + 1].weight = heap[pos].weight;

						heap[pos].src = temp.src;
						heap[pos].dest = temp.dest;
						heap[pos].weight = temp.weight;

						pos = 2 * pos + 1;
					}
					else if (heap[pos].src < heap[2 * pos + 1].src)
					{
						break;
					}
					else
					{
						if (heap[pos].dest > heap[2 * pos + 1].dest)
						{
							temp.src = heap[2 * pos + 1].src;
							temp.dest = heap[2 * pos + 1].dest;
							temp.weight = heap[2 * pos + 1].weight;

							heap[2 * pos + 1].src = heap[pos].src;
							heap[2 * pos + 1].dest = heap[pos].dest;
							heap[2 * pos + 1].weight = heap[pos].weight;

							heap[pos].src = temp.src;
							heap[pos].dest = temp.dest;
							heap[pos].weight = temp.weight;

							pos = 2 * pos + 1;
						}
						else
						{
							break;
						}
					}
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}

void Add_list(node* temp)
{
	if (head == NULL)
	{
		head = tail = temp;
	}
	else if(head==tail)
	{
		if (tail->adj.weight < temp->adj.weight)
		{
			tail = temp;
			temp->prev = head;
			head->next = temp;
		}
		else if (tail->adj.weight > temp->adj.weight)
		{
			head = temp;
			temp->next = tail;
			tail->prev = temp;
		}
		else
		{
			if (tail->adj.src < temp->adj.src)
			{
				tail = temp;
				temp->prev = head;
				head->next = temp;
			}
			else if (tail->adj.src > temp->adj.src)
			{
				head = temp;
				temp->next = tail;
				tail->prev = temp;
			}
			else
			{
				if (tail->adj.dest <= temp->adj.dest)
				{
					tail = temp;
					temp->prev = head;
					head->next = temp;
				}
				else
				{
					head = temp;
					temp->next = tail;
					tail->prev = temp;
				}
			}
		}
	}
	else
	{
		node* pos = tail;
		while (pos != NULL)
		{
			if (pos->adj.weight < temp->adj.weight)
			{
				if (pos == tail)
				{
					tail = temp;
					temp->prev = pos;
					pos->next = temp;
				}
				else
				{
					temp->next = pos->next;
					temp->prev = pos;
					pos->next->prev = temp;
					pos->next = temp;
				}
				break;
			}
			else if(pos->adj.weight > temp->adj.weight)
			{
				if (pos == head)
				{
					head = temp;
					temp->next = pos;
					pos->prev = temp;
					break;
				}
				else
				{
					pos = pos->prev;
				}
			}
			else
			{
				if (pos->adj.src < temp->adj.src)
				{
					if (pos == tail)
					{
						tail = temp;
						temp->prev = pos;
						pos->next = temp;
					}
					else
					{
						temp->next = pos->next;
						temp->prev = pos;
						pos->next->prev = temp;
						pos->next = temp;
					}
					break;
				}
				else if (pos->adj.src > temp->adj.src)
				{
					if (pos == head)
					{
						head = temp;
						temp->next = pos;
						pos->prev = temp;
						break;
					}
					else
					{
						pos = pos->prev;
					}
				}
				else
				{
					if (pos->adj.dest <= temp->adj.dest)
					{
						if (pos == tail)
						{
							tail = temp;
							temp->prev = pos;
							pos->next = temp;
						}
						else
						{
							temp->next = pos->next;
							temp->prev = pos;
							pos->next->prev = temp;
							pos->next = temp;
						}
						break;
					}
					else
					{
						if (pos == head)
						{
							head = temp;
							temp->next = pos;
							pos->prev = temp;
							break;
						}
						else
						{
							pos = pos->prev;
						}
					}
				}
			}
		}
	}
}

int FIND_SET(int* point, int x)
{
	if (x != point[x])
	{
		point[x] = FIND_SET(point,point[x]);
	}
	return point[x];
}

void Union(int* point, int* rank, int x, int y)
{
	//int x = FIND_SET(point, x_src);
	//int y = FIND_SET(point, y_src);

	if (rank[x] > rank[y])
	{
		point[y] = x;
	}
	else
	{
		point[x] = y;
		if (rank[x] == rank[y])
		{
			rank[y] += 1;
		}
	}

}

int main()
{
	int vertices, edges, heap_size, _count, print_count;
	cin >> vertices >> edges;
	int* rank = new int[vertices];
	int* point = new int[vertices];
	edge* heap = new edge[edges];
	heap_size = 0;
	_count = 0;
	for (int i = 0; i < vertices; i++)
	{
		rank[i] = 0;
		point[i] = i;
	}

	for (int i = 0; i < edges; i++)
	{
		edge node;
		int _src, _dest, _weight;
		cin >> _src >> _dest >> _weight;
		if (_src > _dest)
		{
			int temp = _dest;
			_dest = _src;
			_src = temp;
		}
		node.src = _src - 1;
		node.dest = _dest - 1;
		node.weight = _weight;
		Insert_Min_Heap(heap, heap_size, node);
		heap_size++;
	}

	for (int i = 0; i < edges; i++)
	{
		int _src, _dest, point_src,point_dest;
		_src = heap[0].src;
		_dest = heap[0].dest;
		//cout << _src << " " << _dest << " " << heap[0].weight << "\n";
		point_src = FIND_SET(point, _src);
		point_dest = FIND_SET(point, _dest);
		if (point_src != point_dest)
		{
			node* temp = new node;
			temp->prev = NULL;
			temp->next = NULL;
			temp->adj.src = _src;
			temp->adj.dest = _dest;
			//temp->adj.src = heap[0].src;
			//temp->adj.dest = heap[0].dest;
			temp->adj.weight = heap[0].weight;
			_count++;
			Add_list(temp);
			Union(point, rank, point_src, point_dest);
		}
		delete_heap(heap, heap_size);
		heap_size--;
		if (_count == vertices - 1)
		{
			break;
		}
	}

	cout << _count << "\n";
	node* temp = head;
	print_count = 0;
	while (temp != NULL)
	{
		cout << temp->adj.src + 1 << " " << temp->adj.dest + 1 << " " << temp->adj.weight << "\n";
		temp = temp->next;
		print_count++;
		if (print_count == _count)
		{
			break;
		}
	}

	return 0;
}