//2016025069_È²Èñ¼ö_11802

#include <iostream>

using namespace std;

int main()
{
	int size;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
	}

	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && temp > arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;

	return 0;
}