#include<iostream>
using namespace std;
int main()
{
	const int size = 6;
	float matr[size];
	cout << "enter your first number:"<<endl;
	cout << "first value:";
	int temp;
	cin >> temp;
	int i = 0;
	int count = 0;
	while (i < size&&temp >= 0)
	{
		matr[i] = temp;
		i++;
		if (i >= size)
			cout << "sorry" << endl;
		else
		{
			cout << "next value:";
			cin >> temp;
		}
	};
			cout << "enter a number2:";
			cin >> temp;
			for (int a = 0; a < i; ++a)
			if (matr[a] < temp)
			{
				++count;
			};
		cout << count << endl;
		system("pause");
		return 0;

	}