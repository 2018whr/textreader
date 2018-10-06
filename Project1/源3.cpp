#include<iostream>
using namespace std;
long double prob(unsigned n, unsigned c)
{
	long double r = 1.0;
	for (n, c; c > 0; n--, c--)
		r = r*c / n;
	return r;
}

int main()
{
	double choice, number;
	cout << "your choice and your total number:";
	while ((cin >> choice >> number) && choice <= number)
	{
		cout << "your win probablity is " << prob(number, choice) << endl;
		cout << "next two number:";
	}
	cout << "bybe" << endl;
	system("pause");
	return 0;
}