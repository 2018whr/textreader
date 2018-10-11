#ifndef FILE_IO_H
#define FILE_IO_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Data
{
public:
	//最终储存的位置 二维向量
	std::vector<std::vector<int>> setid;
	std::vector<std::vector<int>> setspid;
	std::vector<std::vector<double>> setsx;
	std::vector<std::vector<double>> setsy;
	std::vector<std::vector<double>> setsz;
	  
	//暂时储存的位置 一维向量
	std::vector<int> getid;
	std::vector<int> getspid;
	std::vector<double> getsx;
	std::vector<double> getsy;
	std::vector<double> getsz;

	//设计的函数
	void f_setid(int num, string line)
	{
		line = line.substr(num);
		std::istringstream iss(line);
		while (!iss.eof())
		{
			string a;
			iss >> a;
			const char* p = a.data();
			int b;
			b = atoi(p);
			getid.push_back(b);
		}
	}

	void f_setspid(int num, string line)
	{
		line = line.substr(num);
		std::istringstream iss(line);
		while (!iss.eof())
		{
			string a;
			iss >> a;
			const char* p = a.data();
			int b;
			b = atoi(p);
			getspid.push_back(b);
		}
	}

	void f_setsx(int num, string line)
	{
		line = line.substr(num);
		std::istringstream iss(line);
		while (!iss.eof())
		{
			string a;
			iss >> a;
			const char* p = a.data();
			double b;
			b = atof(p);
			getsx.push_back(b);
		}
	}

	void f_setsy(int num, string line)
	{
		line = line.substr(num);
		std::istringstream iss(line);
		while (!iss.eof())
		{
			string a;
			iss >> a;
			const char* p = a.data();
			double b;
			b = atof(p);
			getsy.push_back(b);
		}
	}

	void f_setsz(int num, string line)
	{
		line = line.substr(num);
		std::istringstream iss(line);
		while (!iss.eof())
		{
			string a;
			iss >> a;
			const char* p = a.data();
			double b;
			b = atof(p);
			getsz.push_back(b);
		}
	}
};

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


	

	























#endif // !FILE.IO.H

