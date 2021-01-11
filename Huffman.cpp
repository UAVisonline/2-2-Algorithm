//2016025069_Hwang_Hui_Su_11802

#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
	//string character;
	int frequency;
	int bit_length;
	struct node* next;
	struct node* prev;
}node;

void Insert_Heap(node** Heap, node* tmp, int size)
{
	Heap[size] = tmp;
	while (size > 0)
	{
		int prev = (size - 1) / 2;
		if (Heap[prev]->frequency > Heap[size]->frequency)
		{
			node* temp = Heap[prev];
			Heap[prev] = Heap[size];
			Heap[size] = temp;

			size = prev;
		}
		else
		{
			break;
		}
	}
}

void Delete_heap(node** Heap, int size)
{
	Heap[0] = Heap[size - 1];

	int pos = 0;
	while (pos < size - 1)
	{
		node* temp;
		if (size - 1 >= (pos + 1) * 2)
		{
			if (Heap[pos]->frequency > Heap[2 * pos + 1]->frequency && Heap[pos]->frequency > Heap[2 * (pos + 1)]->frequency)
			{
				if (Heap[2 * pos + 1]->frequency <= Heap[2 * (pos + 1)]->frequency)
				{
					temp = Heap[2 * pos + 1];
					Heap[2 * pos + 1] = Heap[pos];
					Heap[pos] = temp;

					pos = 2 * pos + 1;
				}
				else
				{
					temp = Heap[2 * (pos + 1)];
					Heap[2 * (pos + 1)] = Heap[pos];
					Heap[pos] = temp;

					pos = 2 * (pos + 1);
				}
			}
			else if (Heap[pos]->frequency > Heap[2 * pos + 1]->frequency && Heap[pos]->frequency <= Heap[2 * (pos + 1)]->frequency)
			{
				temp = Heap[2 * pos + 1];
				Heap[2 * pos + 1] = Heap[pos];
				Heap[pos] = temp;

				pos = 2 * pos + 1;
			}
			else if (Heap[pos]->frequency > Heap[2 * (pos + 1)]->frequency && Heap[pos]->frequency <= Heap[2 * pos + 1]->frequency)
			{
				temp = Heap[2 * (pos + 1)];
				Heap[2 * (pos + 1)] = Heap[pos];
				Heap[pos] = temp;

				pos = 2 * (pos + 1);
			}
			else
			{
				break;
			}
		}
		else if (size - 1 == (pos * 2) + 1)
		{
			if (Heap[pos]->frequency > Heap[2 * pos + 1]->frequency)
			{
				temp = Heap[2 * pos + 1];
				Heap[2 * pos + 1] = Heap[pos];
				Heap[pos] = temp;

				pos = 2 * pos + 1;
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

int result_Heap(node* root, int total)
{
	int loop, bit_level,next_loop,result;
	queue<node*> node_queue;
	next_loop = 0;
	loop = 1;
	bit_level = 0;
	result = 0;

	node_queue.push(root);
	while (!node_queue.empty())
	{
		if (node_queue.front()->bit_length == -1)
		{
			next_loop += 2;
			node_queue.push(node_queue.front()->prev);
			node_queue.push(node_queue.front()->next);
			//cout << "tree_node\n";
		}
		else if (node_queue.front()->bit_length != -1)
		{
			if (total <= node_queue.front()->frequency)
			{
				result += total * bit_level;
				total = 0;
				return result;
			}
			else
			{
				result += node_queue.front()->frequency * bit_level;
				total -= node_queue.front()->frequency;
			}
		}
		node_queue.pop();
		loop--;
		if (loop == 0)
		{
			loop = next_loop;
			next_loop = 0;
			bit_level++;
		}
	}
	return result;
}

void print_Tree(node* root)
{
	int loop, bit_level, next_loop, result;
	queue<node*> node_queue;
	next_loop = 0;
	loop = 1;
	bit_level = 0;
	result = 0;

	node_queue.push(root);
	while (!node_queue.empty())
	{
		if (node_queue.front()->bit_length == -1)
		{
			next_loop += 2;
			node_queue.push(node_queue.front()->prev);
			node_queue.push(node_queue.front()->next);
			cout << node_queue.front()->bit_length << " : " << node_queue.front()->frequency << "\n";
		}
		else if (node_queue.front()->bit_length != -1)
		{
			cout << node_queue.front()->bit_length << " : " << node_queue.front()->frequency << "\n";
		}
		node_queue.pop();
		loop--;
		if (loop == 0)
		{
			loop = next_loop;
			next_loop = 0;
			bit_level++;
		}
	}
}

int main()
{
	int number_of_node, total_number,size_of_heap;

	node** Heap;
	node* root;
	size_of_heap = 0;

	cin >> number_of_node;
	Heap = new node*[number_of_node];
	for (int i = 0; i < number_of_node; i++)
	{
		node* tmp = new node;
		string str;
		int frec;
		cin >> str;
		cin >> frec;
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->frequency = frec;
		tmp->bit_length = 0;
		Insert_Heap(Heap, tmp, size_of_heap);
		size_of_heap++;
	}
	cin >> total_number;

	while (size_of_heap != 1)
	{
		node* tmp = new node;
		node* temp;
		int frec = 0;
		
		temp = Heap[0];
		frec += temp->frequency;
		tmp->prev = temp;
		Delete_heap(Heap, size_of_heap);
		size_of_heap--;

		temp = Heap[0];
		frec += temp->frequency;
		tmp->next = temp;
		Delete_heap(Heap, size_of_heap);
		size_of_heap--;

		tmp->frequency = frec;
		tmp->bit_length = -1;
		Insert_Heap(Heap, tmp, size_of_heap);
		size_of_heap++;
	}

	if (number_of_node == 1)
	{
		cout << total_number << "\n";
		cout << total_number << "\n";
	}
	else
	{
		int bit_length = 1;
		for (int i = 2; i < number_of_node; i*=2)
		{
			bit_length++;
		}
		cout << bit_length * total_number << "\n";
		cout << result_Heap(Heap[0], total_number) << "\n";
		//print_Tree(Heap[0]);
	}

	return 0;
}