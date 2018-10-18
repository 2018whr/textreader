#include<iostream>
#include<fstream>
#include <vector>
#include <string>
#include <sstream>      // std::istringstream
#include "pugixml\pugixml.hpp"
#include "pugixml\pugiconfig.hpp"
using namespace std;
void writexmlt();
void readxml();
void writexml();
int main()
{
	//build struct
	/*struct data
	{
		int id;
		int spid;
		float x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4;
	};*/
	/*int a, b, c, d, e = 0;*/
	//read txt
	ifstream infile;
	infile.open("Text.txt");
	std::string line;
	
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		//判断开头
		string::size_type idx1 = line.find("spid");
		string::size_type idx2 = line.find("x");
		string::size_type idx3 = line.find("y");
		string::size_type idx4 = line.find("z");

		//定义对应向量
		std::vector<int> spid;
		std::vector<int> id;
		std::vector<float> x;
		std::vector<float> y;
		std::vector<float> z;

		//写入向量
		if (idx1 != string::npos)
		{
			int s;
			iss >> s;
			spid.push_back(s);

		}
		else if (idx2 != string::npos)
		{
			int s;
			iss >> s;
			x.push_back(s);
		}
		else if (idx3 != string::npos)
		{
			int s;
			iss >> s;
			y.push_back(s);
		}
		else if (idx4 != string::npos)
		{
			int s;
			iss >> s;
			z.push_back(s);
		}
		else
		{
			int s;
			iss >> s;
			id.push_back(s);
		}

	}
}
	void writexmlt()
{
	pugi::xml_document doc;
	pugi::xml_node decl = doc.prepend_child(pugi::node_declaration);
	// heading
	decl.append_attribute("version") = "1.0";
	decl.append_attribute("encoding") = "UTF-8";
	// root node
	pugi::xml_node r_n = doc.append_child("DUT_AutoMorpher");

	/*project body*/
	pugi::xml_node tmp_cs = r_n.append_child("Section");
	tmp_cs.append_attribute("ID").set_value(csid);
	tmp_cs.append_attribute("SPID").set_value(sid);

}

	void readxml()
	{
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file("prac.xml");//假设文件名
		if (!result)
		{
			std::cerr << "Error at CFileIO::xml_read_sections()" << std::endl;
			exit;
		}

		pugi::xml_node cs_node = doc.child("DUT_AutoMorpher").child("Section");
		for (cs_node; cs_node; cs_node = cs_node.next_sibling())//去下一个section并循环
		{

			std::vector<double[3]> cs_pts, emb_cs_pts;//
			int csid, spid;
			bool is_closed, is_deformed;

			std::string str_id_value = cs_node.attribute("ID").value();
			csid = atoi(str_id_value.c_str());//将string转换为char再转换为int
			std::string str_rid_value = cs_node.attribute("SPID").value();
			spid = atoi(str_rid_value.c_str());//同上

			//判断1
			if (strcmp(cs_node.attribute("IsClosed").value(), "T") == 0)
				is_closed = true;
			else
				is_closed = false;
			if (strcmp(cs_node.attribute("IsDeformed").value(), "T") == 0)
				is_deformed = true;
			else
				is_deformed = false;
			std::cout << "deformed CS ID: " << csid << ", SPID: " << spid << ", IsClosed: " << is_closed << std::endl;

			pugi::xml_node pt_node = cs_node.first_child();//section下的第一个子节点
			for (; pt_node; pt_node = pt_node.next_sibling())//循环处理其余子节点
			{
				double pt[3] = { 0.0, 0.0, 0.0 };//
				std::istringstream sx(pt_node.attribute("X").value());
				sx >> pt[0];
				std::istringstream sy(pt_node.attribute("Y").value());
				sy >> pt[1];
				std::istringstream sz(pt_node.attribute("Z").value());
				sz >> pt[2];
				if (strcmp(pt_node.name(), "Point") == 0)
					cs_pts.push_back(pt);
				else if (strcmp(pt_node.name(), "EmbPoint") == 0)
					emb_cs_pts.push_back(pt);
			}

		}

	}




		
//int main()
//{
//	/*std::vector<std::vector<float>> data;
//	
//	ifstream infile;
//	infile.open("Text.txt");
//
//	std::string line;
//	while (std::getline(infile, line)) 
//	{
//		std::vector<float> tmpData;
		std::istringstream iss(line);
//		while (!iss.eof())
//		{
//			float a;
//			iss >> a;
//			tmpData.push_back(a);
//		}
//	data.push_back(tmpData);
//	  for (int i = 0; i < tmpData.size(); i++)
//	  {
//		std::cout << tmpData[i] << ", ";
//	  }
//	std::cout << std::endl;
//	}*/
//
//	// write xml from txt
//
//
//	// read xml from xml
//	
//
//
//
//	// std::cout xml read
//	 read_txt();
//	system("pause");
//	return 0;
//
//
//	//float data[6][2] = { 0 };
//	//ifstream infile;
//	//infile.open("Text.txt");
//	//for (int i = 0; i <=5; ++i)
//	//{
//	//	for (int j = 0; j <=1; ++j)
//	//	{
//	//		infile >> data[i][j];
//	//	}
//	//}
//	//cout << data[0][0] << "," << data[5][1];
//	//	system("pause");
//	//return 0;
//}
