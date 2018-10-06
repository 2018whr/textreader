#include<iostream>
using namespace std;

void sample(char c, int a)
{
	for ( a; a > 0; a--)
		cout << c;
}

int main()
{
	cout << "enter a word:";
	char w;
	cin>>w;
	while (w != 'q')
	{
		cout << "enter a number:";
		int n;
		cin >> n;
		cout << "your times is:" << n << endl;
		cout << "now:  ";
		sample(w, n);
		cout << endl;
		cout << "enter a word:";
		cin>>w;
	}
	cout << "bybe" << endl;
	system("pause");
	return 0;
}