//2016025069_Hwang Hui Su_11802

#include <iostream>

using namespace std;

void UP_HEAPIFY(int* arr, int i)
{
	while (i > 1)
	{
		int temp = arr[i - 1];
		if (temp > arr[(i / 2) - 1])
		{
			arr[i - 1] = arr[(i / 2) - 1];
			arr[(i / 2) - 1] = temp;
			i = i / 2;
		}
		else
		{
			break;
		}
	}
}

void DOWN_HEAPIFY(int* arr, int i, int size)
{
	while (i <= size)
	{
		int temp = arr[i - 1];
		if (i * 2 > size) break;
		else if (i * 2 == size && i * 2 + 1 > size)
		{
			if (temp <= arr[(2 * i) - 1])
			{
				arr[i - 1] = arr[(2 * i) - 1];
				arr[(2 * i) - 1] = temp;
				i = i * 2;
			}
			else if (temp > arr[(2 * i) - 1]) break;
		}
		else
		{
			if (arr[(2 * i) - 1] > arr[(2 * i)])
			{
				if (temp > arr[(2 * i) - 1]) break;
				else
				{
					arr[i - 1] = arr[(2 * i) - 1];
					arr[(2 * i) - 1] = temp;
					i = i * 2;
				}
			}
			else if (arr[(2 * i) - 1] <= arr[(2 * i)])
			{
				if (temp > arr[(2 * i)]) break;
				else
				{
					arr[i - 1] = arr[(2 * i)];
					arr[(2 * i)] = temp;
					i = i * 2 + 1;
				}
			}
		}
	}

}

int main()
{
	int* arr = new int[100001];
	for (int i = 0; i < 100001; i++) arr[i] = 0;
	int* extract = new int[100001];
	int cmd, size,ext_size;
	size = 0;
	ext_size = 0;
	cin >> cmd;

	while (cmd != 0)
	{
		switch (cmd)
		{
		case 1:
			int num;
			cin >> num;
			arr[size] = num;
			size = size + 1;
			UP_HEAPIFY(arr, size);
			break;
		case 2:
			if (size > 0)
			{
				extract[ext_size++] = arr[0];
				arr[0] = arr[size-1];
				size = size - 1;
				DOWN_HEAPIFY(arr, 1, size);
			}
			break;
		case 3:
			int index, modified_num, temp;
			cin >> index >> modified_num;
			temp = arr[index-1];
			arr[index-1] = modified_num;
			if (temp < modified_num)
			{
				UP_HEAPIFY(arr, index);
			}
			else if (temp > modified_num)
			{
				DOWN_HEAPIFY(arr, index, size);
			}
			break;
		default:
			break;
		}
		cin >> cmd;
	}

	
	for (int i = 0; i < ext_size; i++)
	{
		cout << extract[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	delete[] extract;
	delete[] arr;
	
	return 0;
}