#include"file_io.h"

using namespace std;
void read_txt(Data_txt *d);
void read_xml(Data_xml *d);
void write_xml( Data_xml d);
void write_defc_xml(Data_xml d);
void write_defp_xml(Data_xml d);
void write_defp_xml(Data_xml d)
{
	pugi::xml_document def_doc;
	pugi::xml_node decl = def_doc.prepend_child(pugi::node_declaration);
	decl.append_attribute("version") = "1.0";
	decl.append_attribute("encoding") = "UTF-8";
	def_doc.append_child("DUT_AutoMorpher");
	pugi::xml_node def_ss = def_doc.child("DUT_AutoMorpher");
	int m = d.setid.size();
	for (int i = 0; i < m; i++)
	{
		pugi::xml_node tmp_cs = def_ss.append_child("Section");
		tmp_cs.append_attribute("ID").set_value(d.setid[i]);
		tmp_cs.append_attribute("SPID").set_value(d.setspid[i]);

		if ((d.isclosed[i] == "T") == 1)
		{
			tmp_cs.append_attribute("IsDeformed").set_value("T");
		}
		else
			tmp_cs.append_attribute("IsDeformed").set_value("F");

		if ((d.isdeformed[i] == "T") == 1)
		{
			tmp_cs.append_attribute("IsClosed").set_value("T");
		}
		else
			tmp_cs.append_attribute("IsClosed").set_value("F");

		for (int j = 0; j < 100; j++)
		{
			pugi::xml_node vertex = tmp_cs.append_child("EmbPoint");
			vertex.append_attribute("X").set_value(atof(d.sec_num_e[i][0][0].c_str()));

			if (j <= 25)
			{
				vertex.append_attribute("Y").set_value(30 - 2.4*j);
				vertex.append_attribute("Z").set_value(40);
			}
			else if (25<j&&j <= 50)
			{
				vertex.append_attribute("Y").set_value(-30);
				vertex.append_attribute("Z").set_value(40 - 3.2*(j - 25));
			}
			else if (50<j&&j <= 75)
			{
				vertex.append_attribute("Y").set_value(-30 + 2.4*(j - 50));
				vertex.append_attribute("Z").set_value(-40);
			}
			else if (j>75)
			{
				vertex.append_attribute("Y").set_value(30);
				vertex.append_attribute("Z").set_value(-40 + 3.2*(j - 75));
			}

			vertex.prepend_attribute("ID").set_value(j);
		}
	}
	std::cout << "Saving Cross-sections: " << def_doc.save_file("prac.xml") << std::endl;
}
void write_defc_xml(Data_xml d)
{
	pugi::xml_document def_doc;
	pugi::xml_node decl = def_doc.prepend_child(pugi::node_declaration);
	decl.append_attribute("version") = "1.0";
	decl.append_attribute("encoding") = "UTF-8";
	def_doc.append_child("DUT_AutoMorpher");
	pugi::xml_node def_ss = def_doc.child("DUT_AutoMorpher");
	
		int m = d.setid.size();
		for (int i = 0; i < m; i++)
		{
			pugi::xml_node tmp_cs = def_ss.append_child("Section");
			tmp_cs.append_attribute("ID").set_value(d.setid[i]);
			tmp_cs.append_attribute("SPID").set_value(d.setspid[i]);

			if ((d.isclosed[i] == "T") == 1)
			{
				tmp_cs.append_attribute("IsDeformed").set_value("T");
			}
			else
				tmp_cs.append_attribute("IsDeformed").set_value("F");

			if ((d.isdeformed[i] == "T") == 1)
			{
				tmp_cs.append_attribute("IsClosed").set_value("T");
			}
			else
				tmp_cs.append_attribute("IsClosed").set_value("F");

			for (int j = 0; j < 100; j++)
			{
				pugi::xml_node vertex = tmp_cs.append_child("EmbPoint");
				vertex.append_attribute("X").set_value(atof(d.sec_num_e[i][0][0].c_str()));

				if (j <= 25)
				{
					vertex.append_attribute("Y").set_value(30 - 2.4*j);
					vertex.append_attribute("Z").set_value(40+d.def_l[0][j]);
				}
				else if (25 < j&&j <= 50)
				{
					vertex.append_attribute("Y").set_value(-30-d.def_l[1][j-25]);
					vertex.append_attribute("Z").set_value(40 - 3.2*(j - 25));
				}
				else if (50 < j&&j <= 75)
				{
					vertex.append_attribute("Y").set_value(-30 + 2.4*(j - 50));
					vertex.append_attribute("Z").set_value(-40-d.def_l[2][j-50]);
				}
				else if (j > 75)
				{
					vertex.append_attribute("Y").set_value(30+d.def_l[3][j-75]);
					vertex.append_attribute("Z").set_value(-40 + 3.2*(j - 75));
				}


				vertex.prepend_attribute("ID").set_value(j);
			}
		}
		std::cout << "Saving Cross-sections: " << def_doc.save_file("prac_d.xml") << std::endl;
}
void write_xml(Data_xml d)
{
	pugi::xml_document dst_doc;
	pugi::xml_node decl = dst_doc.prepend_child(pugi::node_declaration);
	decl.append_attribute("version") = "1.0";
	decl.append_attribute("encoding") = "UTF-8";
	dst_doc.append_child("DUT_AutoMorpher");
	pugi::xml_node dst_ss = dst_doc.child("DUT_AutoMorpher");
	int m = d.setid.size();
	for (int i = 0; i < m; i++)
	{
		pugi::xml_node tmp_cs = dst_ss.append_child("Section");
tmp_cs.append_attribute("ID").set_value(d.setid[i]);
tmp_cs.append_attribute("SPID").set_value(d.setspid[i]);

if ((d.isclosed[i] == "T") == 1)
{
	tmp_cs.append_attribute("IsDeformed").set_value("T");
}
else
tmp_cs.append_attribute("IsDeformed").set_value("F");

if ((d.isdeformed[i] == "T") == 1)
{
	tmp_cs.append_attribute("IsClosed").set_value("T");
}
else
tmp_cs.append_attribute("IsClosed").set_value("F");

//i代表的是section的序号，a代表的是不同section里的点的序号
if (d.section_p[i] > 0)//判断point是否为空
{
	cout << d.sec_num_p.size() << endl;
	cout << "d" << endl;
	for (int a = 0; a <= d.section_p[i]; a++)
	{
		pugi::xml_node vertex = tmp_cs.append_child("Point");
		vertex.append_attribute("X").set_value(atof(d.sec_num_p[i][a][0].c_str()));
		vertex.append_attribute("Y").set_value(atof(d.sec_num_p[i][a][1].c_str()));
		vertex.append_attribute("Z").set_value(atof(d.sec_num_p[i][a][2].c_str()));
		vertex.prepend_attribute("ID").set_value(a);

	}
}

if (d.section_e[i] > 0)//判断embpoint是否为空
{
	for (int a = 0; a < d.section_e[i]; a++)
	{
		pugi::xml_node vertex = tmp_cs.append_child("EmbPoint");
		vertex.append_attribute("X").set_value(atof(d.sec_num_e[i][a][0].c_str()));
		vertex.append_attribute("Y").set_value(atof(d.sec_num_e[i][a][1].c_str()));
		vertex.append_attribute("Z").set_value(atof(d.sec_num_e[i][a][2].c_str()));
		vertex.prepend_attribute("ID").set_value(a);

	}
}
	}
	std::cout << "Saving Cross-sections: " << dst_doc.save_file("prac.xml") << std::endl;
};
void read_txt(Data_txt *d)
{
	ifstream infile;
	infile.open("Text.txt");
	std::string line;
	while (getline(infile, line))
	{
		std::istringstream iss(line);
		while (!iss.eof())
		{
			string a;
			iss >> a;
		const char* p = a.data();
	        double b;
			b = atof(p);
			d->point.push_back(b);
		}
		d->line.push_back(d->point);
		d->point.clear();
	}
		//判断数据开头
	//	string::size_type idx1 = line.find("spid");
	//	string::size_type idx2 = line.find("x");
	//	string::size_type idx3 = line.find("y");
	//	string::size_type idx4 = line.find("z");

	//	if (idx1 != string::npos)
	//	{

	//		d.f_setspid(5, line);
	//	}
	//	else if (idx2 != string::npos)
	//	{
	//		d.f_setsx(2, line);
	//	}
	//	else if (idx3 != string::npos)
	//	{
	//		d.f_setsy(2, line);
	//	}
	//	else if (idx4 != string::npos)
	//	{
	//		d.f_setsz(2, line);
	//	}
	//	else
	//	{
	//		d.f_setid(3, line);
	//	}
	//	//赋值给二维向量
	//	d.setid.push_back(d.getid);
	//	d.setspid.push_back(d.getspid);
	//	d.setsx.push_back(d.getsx);
	//	d.setsy.push_back(d.getsy);
	//	d.setsz.push_back(d.getsz);

	//}
	//for (int i = 0; i < 8; i++)//输出x的值检查
	//	cout << d.getsx[i] << endl;
	
};
void read_xml(Data_xml* d)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("DesSection.xml");
	if(!result)
	{
	cout << "no file" << endl;
	exit;
    }
	pugi::xml_node cs_node = doc.child("DUT_AutoMorpher").child("Section");
	
	for (cs_node; cs_node; cs_node = cs_node.next_sibling())
	{
		int sec_p = 0;
		int sec_e = 0;
		string id;//id
		id = cs_node.attribute("ID").value();
		int i = atoi(id.c_str());
		d->setid.push_back(i);

		string spid;//spid
		spid = cs_node.attribute("SPID").value();
		int	s = atoi(spid.c_str());
		d->setspid.push_back(s);

		string closed;//closed状态
		closed = cs_node.attribute("IsClosed").value();
		d->isclosed.push_back(closed);
		

		string deformed;//deformed状态
		deformed = cs_node.attribute("IsDeformed").value();
		d->isdeformed.push_back(deformed);
		

		
		//读取坐标点
		pugi::xml_node pt_node = cs_node.first_child();
		for (pt_node; pt_node; pt_node = pt_node.next_sibling())
		{

			vector<string> pt;
			std::istringstream sx(pt_node.attribute("X").value());
			string x;
			sx >> x;
			pt.push_back(x);
			std::istringstream sy(pt_node.attribute("Y").value());
			string y;
			sy >> y;
			pt.push_back(y);
			std::istringstream sz(pt_node.attribute("Z").value());
			string z;
			sz >> z;
			pt.push_back(z);

			if (strcmp(pt_node.name(), "Point") == 0)
			{
				sec_p++;
				d->cs_pts.push_back(pt);
			}
			else if (strcmp(pt_node.name(), "EmbPoint") == 0)
			{
				sec_e++;
				d->emb_cs_pts.push_back(pt);
			}
			

		}

		d->sec_num_p.push_back(d->cs_pts);
		d->sec_num_e.push_back(d->emb_cs_pts);
		d->cs_pts.clear();
		d->emb_cs_pts.clear();
		d->section_p.push_back(sec_p);
		d->section_e.push_back(sec_e);
	}
	
	}


int main()
{
	Data_txt t;
	Data_xml d;
	//read_xml(&d);//传递对象用地址传递
	////write_xml(d);
	//write_defc_xml(d);
	read_xml(&d);
	read_txt(&t);
	for (int i = 0; i < 4; i++)
	{
		d.Def_p(t.line[i][0], t.line[i][1], t.line[i][2],&d);
	}
	write_defc_xml(d);
	system("pause");
	return 0;
}

