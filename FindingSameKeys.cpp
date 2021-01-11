//2016025069_Hwang Hui Su_11802

#include <iostream>

using namespace std;

void quick_sort(int* arr, int p, int q)
{
	if (p < q)
	{
		int pivot_small = p, pivot_big  = p;
		int pivot = arr[q];
		for (int i = p; i < q; i++)
		{
			if (pivot <= arr[i])
			{
				pivot_big++;
			}
			else
			{
				int temp = arr[pivot_small];
				arr[pivot_small] = arr[i];
				arr[i] = temp;
				pivot_small++;
				pivot_big++;
			}
		}
		int temp = arr[pivot_small];
		arr[pivot_small] = arr[q];
		arr[q] = temp;

		quick_sort(arr, p, pivot_small - 1);
		quick_sort(arr, pivot_small + 1, q);
	}
}

int main()
{
	int first_num, second_num;
	cin >> first_num >> second_num;
	int* first_arr = new int[first_num];
	int* second_arr = new int[second_num];

	for (int i = 0; i < first_num; i++)
	{
		cin >> first_arr[i];
	}
	quick_sort(first_arr, 0, first_num - 1);

	for (int i = 0; i < second_num; i++)
	{
		cin >> second_arr[i];
	}
	quick_sort(second_arr, 0, second_num - 1);

	int first = 0, second = 0, ans = 0;
	while (first < first_num && second < second_num)
	{
		if (first_arr[first] == second_arr[second])
		{
			ans++;
			first++;
			while (first_arr[first - 1] == first_arr[first] && first < first_num)
			{
				first++;
			}
		}
		else if (first_arr[first] < second_arr[second])
		{
			first++;
			while (first_arr[first - 1] == first_arr[first] && first < first_num)
			{
				first++;
			}
		}
		else
		{
			second++;
			while (second_arr[second - 1] == second_arr[second] && second < second_num)
			{
				second++;
			}
		}
	}
	cout << ans << "\n";

	delete[] first_arr;
	delete[] second_arr;

	return 0;
}