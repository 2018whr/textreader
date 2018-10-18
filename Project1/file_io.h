#ifndef FILE_IO_H
#define FILE_IO_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "pugixml\pugixml.hpp"
#include "pugixml\pugiconfig.hpp"
#include "ini_parser\ini.hpp"
using namespace std;
class Data_txt
{
public:
	vector<double> point;
	vector<vector<double>> line;
	////最终储存的位置 二维向量
	//std::vector<std::vector<int>> setid;
	//std::vector<std::vector<int>> setspid;
	//std::vector<std::vector<double>> setsx;
	//std::vector<std::vector<double>> setsy;
	//std::vector<std::vector<double>> setsz;
	//  
	////暂时储存的位置 一维向量
	//std::vector<int> getid;
	//std::vector<int> getspid;
	//std::vector<double> getsx;
	//std::vector<double> getsy;
	//std::vector<double> getsz;

	//设计的函数
	//void f_setid(int num, string line)
	//{
	//	line = line.substr(num);
	//	std::istringstream iss(line);
	//	while (!iss.eof())
	//	{
	//		string a;
	//		iss >> a;
	//		const char* p = a.data();
	//		int b;
	//		b = atoi(p);
	//		getid.push_back(b);
	//	}
	//}

	//void f_setspid(int num, string line)
	//{
	//	line = line.substr(num);
	//	std::istringstream iss(line);
	//	while (!iss.eof())
	//	{
	//		string a;
	//		iss >> a;
	//		const char* p = a.data();
	//		int b;
	//		b = atoi(p);
	//		getspid.push_back(b);
	//	}
	//}

	//void f_setsx(int num, string line)
	//{
	//	line = line.substr(num);
	//	std::istringstream iss(line);
	//	while (!iss.eof())
	//	{
	//		string a;
	//		iss >> a;
	//		const char* p = a.data();
	//		double b;
	//		b = atof(p);
	//		getsx.push_back(b);
	//	}
	//}

	//void f_setsy(int num, string line)
	//{
	//	line = line.substr(num);
	//	std::istringstream iss(line);
	//	while (!iss.eof())
	//	{
	//		string a;
	//		iss >> a;
	//		const char* p = a.data();
	//		double b;
	//		b = atof(p);
	//		getsy.push_back(b);
	//	}
	//}

	//void f_setsz(int num, string line)
	//{
	//	line = line.substr(num);
	//	std::istringstream iss(line);
	//	while (!iss.eof())
	//	{
	//		string a;
	//		iss >> a;
	//		const char* p = a.data();
	//		double b;
	//		b = atof(p);
	//		getsz.push_back(b);
	//	}
	//}
};

class Data_xml
{
public:
	vector<int> setid;
	vector<int> setspid;
	vector<string> isclosed;
	vector<string> isdeformed;
	vector<int> section_p;//统计每个section有多少个点
	vector<int> section_e;

	vector<vector<string>> cs_pts;
	vector<vector<string>> emb_cs_pts;


	//将坐标数组按照不同的section划分开
	vector<vector<vector<string>>> sec_num_p;
	vector<vector<vector<string>>> sec_num_e;
	
	vector<double> def;//储存一条边上点的变形。
	vector<vector<double>> def_l;// def_l储存的是截面边的信息，每一条边是顺时针编号0 1 2 3，每条边内含0~25号点的变形。
	void Def_p(double a,double b,double c,Data_xml *x)
	{
			for (int i = 0; i < 26; i++)
			{
				if (i <= 6)
				{
					double m = (a / 6)*i;
					x->def.push_back(m);
				}
				else if (i > 6 && i <= 12)
				{
					double m = a - ((a - b) / 6)*(i - 6);
					x->def.push_back(m);
				}
				else if (i > 12 && i <= 18)
				{
					double m = b - ((b - c) / 6)*(i - 12);
					x->def.push_back(m);
				}
				else if (i > 18 && i <= 25)
				{
					double m = c - (c / 7)*(i - 18);
					x->def.push_back(m);
				}
		}
			x->def_l.push_back(x->def);
			x->def.clear();
	}

};


	

	























#endif // !FILE.IO.H

