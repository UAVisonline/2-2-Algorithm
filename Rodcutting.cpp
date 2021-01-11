//2016025069_Hwang_Hui_Su_11802

#include <iostream>

using namespace std;

int main()
{
	int size, max_print, max_pos;
	cin >> size;
	int* value = new int[size+1];
	int* maximum_value = new int[size+1];
	int* pos_value = new int[size+1];

	value[0] = 0;
	maximum_value[0] = 0;
	pos_value[0] = 0;
	max_print = 0;

	for (int i = 1; i < size+1; i++)
	{
		cin >> value[i];
	}

	for (int i = 1; i < size + 1; i++)
	{
		int max = -1;
		for (int j = 1; j <= i; j++)
		{
			if (max < value[j] + maximum_value[i - j])
			{
				max = value[j] + maximum_value[i - j];
				pos_value[i] = j;
			}
		}
		maximum_value[i] = max;
		if (max_print < maximum_value[i])
		{
			max_print = maximum_value[i];
			max_pos = i;
		}
	}

	cout << max_print << "\n";
	while (size > 0)
	{
		cout << pos_value[size] << " ";
		size -= pos_value[size];
	}

	delete[] value;
	delete[] maximum_value;
	delete[] pos_value;

	return 0;
}