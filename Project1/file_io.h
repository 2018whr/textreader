#ifndef FILE_IO_H
#define FILE_IO_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include<string>
#include<sstream>
using namespace std;
class Data
{
public:
	//最终储存的位置 二维向量
	std::vector<std::vector<string>> setid;
	std::vector<std::vector<string>> setspid;
	std::vector<std::vector<string>> setsx;
	std::vector<std::vector<string>> setsy;
	std::vector<std::vector<string>> setsz;
	  
	//暂时储存的位置 一维向量
	std::vector<string> getid;
	std::vector<string> getspid;
	std::vector<string> getsx;
	std::vector<string> getsy;
	std::vector<string> getsz;


	/*int getid(int id)
	{
		int s = id;
		return s;
	};

	int getspid(int spid)
	{
		int s = spid;
		return s;
	}
	double getsx(double sx[4])
	{
		double s[4] = { 0.0,0.0,0.0,0.0 };
		for (int i=0; i < 4; i++)
			s[i] = sx[i];
		return s[4];
	}
	double getsy(double sy[4])
	{
		double s[4] = { 0.0,0.0,0.0,0.0 };
		for (int i=0; i < 4; i++)
			s[i] = sy[i];
		return s[4];
	}
	double getsz(double sz[4])
	{
		double s[4] = { 0.0,0.0,0.0,0.0 };
		for (int i=0; i < 4; i++)
			s[i] = sz[i];
		return s[4];
	}


		
private:
*/


	

	
};






















#endif // !FILE.IO.H

