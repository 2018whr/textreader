#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	float data[6][2] = { 0 };
	ifstream infile;
	infile.open("Text.txt");
	for (int i = 0; i <=5; ++i)
	{
		for (int j = 0; j <=1; ++j)
		{
			infile >> data[i][j];
		}
	}
	cout << data[0][0] << "," << data[5][1];
		system("pause");
	return 0;
}
