//2016025069_È²Èñ¼ö(Hwang Hui Su)_11802

#include<iostream>

using namespace std;

void merge(int* arr, int first, int half, int end)
{
	if (end - first > 0)
	{
		merge(arr, first, (first + half) / 2, half);
		merge(arr, half + 1, (half + end + 1) / 2, end);
	}
	if (first != end)
	{
		int* tmp_arr = new int[end - first + 1];
		for (int i = first; i <= end; i++)
		{
			tmp_arr[i-first] = arr[i];
		}
		int tmp_first = 0;
		int tmp_half = half + 1 - first;
		int temp_1 = tmp_arr[tmp_first];
		int temp_2 = tmp_arr[tmp_half];
		int i = first;
		while (tmp_first <= half-first && tmp_half <= end-first)
		{
			if (temp_1 >= temp_2)
			{
				arr[i++] = temp_1;
				temp_1 = tmp_arr[++tmp_first];
			}
			else if (temp_2 > temp_1)
			{
				arr[i++] = temp_2;
				temp_2 = tmp_arr[++tmp_half];
			}
		}
		while (tmp_half <= end-first)
		{
			arr[i++] = tmp_arr[tmp_half++];
		}
		while (tmp_first <= half-first)
		{
			arr[i++] = tmp_arr[tmp_first++];
		}
		delete[] tmp_arr;
	}
}

int main()
{
	int size;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	int half = (size - 1) / 2;
	merge(arr, 0, half, size - 1);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\n";
	}
	delete[] arr;
	return 0;
}