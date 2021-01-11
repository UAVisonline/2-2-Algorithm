//2016025069_Hwang_Hui_Su_11802

#include <iostream>

using namespace std;

int main()
{
	int size, stay;
	int enter_1, enter_2, outer_1, outer_2;

	cin >> size;
	cin >> enter_1 >> enter_2;
	cin >> outer_1 >> outer_2;

	int* first_line = new int[size];
	int* second_line = new int[size];
	int* go_to_second = new int[size-1];
	int* go_to_first = new int[size-1];

	for (int i = 0; i < size; i++)
	{
		cin >> first_line[i];
	}
	for (int i = 0; i < size; i++)
	{
		cin >> second_line[i];
	}
	for (int i = 0; i < size-1; i++)
	{
		cin >> go_to_second[i];
	}
	for (int i = 0; i < size-1; i++)
	{
		cin >> go_to_first[i];
	}

	int* first_result = new int[size + 1];
	int* second_result = new int[size + 1];
	int* first_station = new int[size-1];
	int* second_station = new int[size-1];
	int* result_station = new int[size];

	first_result[0] = enter_1 + first_line[0];
	second_result[0] = enter_2 + second_line[0];


	for (int i = 1; i < size; i++)
	{
		if (first_result[i - 1] + first_line[i] <= second_result[i - 1] + first_line[i] + go_to_first[i - 1])
		{
			first_result[i] = first_result[i - 1] + first_line[i];
			first_station[i - 1] = 1;
		}
		else
		{
			first_result[i] = second_result[i - 1] + first_line[i] + go_to_first[i - 1];
			first_station[i - 1] = 2;
		}

		if (second_result[i - 1] + second_line[i] <= first_result[i - 1] + second_line[i] + go_to_second[i - 1])
		{
			second_result[i] = second_result[i - 1] + second_line[i];
			second_station[i - 1] = 2;
		}
		else
		{
			second_result[i] = first_result[i - 1] + second_line[i] + go_to_second[i - 1];
			second_station[i - 1] = 1;
		}
	}
	first_result[size] = first_result[size - 1] + outer_1;
	second_result[size] = second_result[size - 1] + outer_2;

	if (first_result[size] <= second_result[size])
	{
		cout << first_result[size] << "\n";
		stay = 1;
	}
	else
	{
		cout << second_result[size] << "\n";
		stay = 2;
	}

	result_station[size - 1] = stay;
	for (int i = size - 2; i >= 0; i--)
	{
		if (stay == 1)
		{
			stay = first_station[i];
		}
		else if (stay == 2)
		{
			stay = second_station[i];
		}
		result_station[i] = stay;
	}

	for (int i = 0; i < size; i++)
	{
		cout << result_station[i] << " " << i + 1 << "\n";
	}

	delete[] first_result;
	delete[] second_result;
	delete[] first_station;
	delete[] second_station;
	delete[] result_station;
	delete[] first_line;
	delete[] second_line;
	delete[] go_to_first;
	delete[] go_to_second;

	return 0;
}