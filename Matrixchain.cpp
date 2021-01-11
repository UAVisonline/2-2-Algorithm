//2016025069_Hwang_Hui_Su_11802

#include <iostream>

using namespace std;

int GET_MIN(int j, int i, int** table, int* p_arr, int** print_table)
{
	int min = 0;
	for (int k = j; k < i; k++)
	{
		int temp = table[j][k] + table[k+1][i] + p_arr[j] * p_arr[k+1] * p_arr[i+1];
		if (min == 0)
		{
			min = temp;
			print_table[j][i] = k + 1;
		}
		else if(min>temp)
		{
			min = temp;
			print_table[j][i] = k + 1;
		}
	}
	return min;
}


void print_order(int** print_table, int i, int j)
{
	if (i == j)
	{
		cout << i+1 << " ";
	}
	else
	{
		cout << "( ";
		print_order(print_table, i, print_table[i][j]-1);
		print_order(print_table, print_table[i][j], j);
		cout << ") ";
	}
}


int main()
{
	int size;
	cin >> size;
	
	int* p_arr = new int[size+1];
	int** table = new int*[size];
	int** print_table = new int* [size];
	for (int i = 0; i < size; i++)
	{
		table[i] = new int[size];
		print_table[i] = new int[size];
	}

	for (int i = 0; i < size + 1; i++)
	{
		cin >> p_arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			table[i][j] = 0;
			print_table[i][j] = 0;
		}
	}

	for (int i = 1; i < size; i++)
	{
		int i_copy = i;
		for (int j = 0; i_copy < size; i_copy++, j++)
		{
			int min_number = GET_MIN(j,i_copy,table,p_arr,print_table);
			table[j][i_copy] = min_number;
		}
	}

	cout << table[0][size - 1] << "\n";
	print_order(print_table, 0, size - 1);

	delete[] p_arr;
	for (int i = 0; i < size; i++)
	{
		delete[] table[i];	
		delete[] print_table[i];
	}
	delete[] table;
	delete[] print_table;

	return 0;
}