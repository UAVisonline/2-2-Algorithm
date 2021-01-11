//2016025069_Hwang Hui Su_11802

#include <iostream>

using namespace std;

void MAX_HEAP(int* arr, int i, int size)
{
	while (i < size)
	{
		int temp = arr[i];
		if (i * 2 + 1 >= size)
		{
			break;
		}
		else if (i * 2 + 1 < size && (i + 1) * 2 >= size)
		{
			if (temp >= arr[i * 2 + 1]) break;
			arr[i] = arr[i * 2 + 1];
			arr[i * 2 + 1] = temp;
			i = i * 2 + 1;
		}
		else
		{
			if (arr[2 * i + 1] >= arr[(i + 1) * 2])
			{
				if (temp >= arr[i * 2 + 1]) break;
				arr[i] = arr[i * 2 + 1];
				arr[i * 2 + 1] = temp;
				i = i * 2 + 1;
			}
			else if (arr[2 * i + 1] < arr[(i + 1) * 2])
			{
				if (temp >= arr[(i + 1) * 2]) break;
				arr[i] = arr[(i + 1) * 2];
				arr[(i + 1) * 2] = temp;
				i = (i + 1) * 2;
			}
		}
	}
}

int main()
{
	int size, extract;
	cin >> size >> extract;
	int* arr = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	for (int i = (size/2) - 1; i >= 0; i--)
	{
		MAX_HEAP(arr, i, size);
	}

	int original_size = size;
	for (int i = 0 ; i < original_size; i++)
	{
		cout << arr[0] << " ";
		int temp = arr[0];
		arr[0] = arr[size-1];
		arr[size-1] = temp;
		size -= 1;
		MAX_HEAP(arr, 0, size);
		if (i == extract - 1)
		{
			cout << "\n";
			for (int j = 0; j < size; j++)
			{
				cout << arr[j] << " ";
			}
			break;
		}
	}

	delete[] arr;

	return 0;
}