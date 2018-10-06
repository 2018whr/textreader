#include<iostream>
using namespace std;
const int max = 5;

int fill_m(double ar[], int limit)
{
	int temp;
	int i = 0;
	for ( i = 0; i < limit; i++)
	{
		cout << i+1<<" enter yours:";
		cin >> temp;
		if (!temp)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "bad input" << endl;
		}
		else if (temp< 0)
				break;
		ar[i] = temp;
		}
	return i;
	}

void show_m(const double ar[], int limit)
{
	for (int i = 0; i < limit; i++)
	{
		cout << i + 1 << " the number is: " << ar[i] << endl;
	}
}

int main()
{
	double ma[max];
	int size = fill_m(ma, max);
	show_m(ma,size);
	system("pause");
	return 0;
}





