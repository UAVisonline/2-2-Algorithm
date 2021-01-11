//2016025069_Hwang Hui Su_11802

#include <iostream>

using namespace std;

int count_result(int* arr, int left, int right)
{
	if (left > right) return 0;
	else
	{
		if (left == 0) return arr[right];
		else return arr[right] - arr[left - 1];
	}
}

int main()
{
	int num_of_input, range_of_input, num_of_query;
	cin >> num_of_input >> range_of_input >> num_of_query;
	int* arr = new int[num_of_input];
	int* left = new int[num_of_query];
	int* right = new int[num_of_query];
	int* ans = new int[range_of_input+1];

	for (int i = 0; i < num_of_query; i++)
	{
		int left_num, right_num;
		cin >> left_num >> right_num;
		left[i] = left_num;
		right[i] = right_num;
	}
	for (int i = 0; i < num_of_input; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
	}

	for (int i = 0; i < range_of_input + 1; i++)
	{
		ans[i] = 0;
	}
	for (int i = 0; i < num_of_input; i++)
	{
		ans[arr[i]] += 1;
	}
	for (int i = 1; i < range_of_input + 1; i++)
	{
		ans[i] = ans[i] + ans[i-1];
	}

	for (int i = 0; i < num_of_query; i++)
	{
		cout << count_result(ans, left[i], right[i]) << "\n";
	}
	
	delete[] arr;
	delete[] left;
	delete[] right;
	delete[] ans;

	return 0;
}