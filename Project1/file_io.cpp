#include"file_io.h";
using namespace std;
int main()
{
	ifstream infile;
	infile.open("Text.txt");
	std::string line;
	Data d;
	while (std::getline(infile, line))
	{
		
		//判断数据开头
			string::size_type idx1 = line.find("spid");
			string::size_type idx2 = line.find("x");
			string::size_type idx3 = line.find("y");
			string::size_type idx4 = line.find("z");

			if (idx1 != string::npos)
			{
				line = line.substr(5);//清除数据开头的字符“spid”
				std::istringstream iss(line);
				
				while (!iss.eof())
				{
					string a;
					iss >> a;
					d.getspid.push_back(a);

				}
			}
			else if (idx2 != string::npos)
			{
				line = line.substr(2);//清除“sx”
				std::istringstream iss(line);
				while (!iss.eof())
				{
					string a;
					iss >> a;
					d.getsx.push_back(a);
				}
			}
			else if (idx3 != string::npos)
			{
				line = line.substr(2);
				std::istringstream iss(line);
				while (!iss.eof())
				{
					string a;
					iss >> a;
					d.getsy.push_back(a);
				}
			}
			else if (idx4 != string::npos)
			{
				line = line.substr(2);
				std::istringstream iss(line);
				while (!iss.eof())
				{
					string a;
					iss >> a;
					d.getsz.push_back(a);
				}
			}
			else
			{
				line = line.substr(3);
				std::istringstream iss(line);
				while (!iss.eof())
				{
					string a;
					iss >> a;
					d.getid.push_back(a);
				}
			}
			//赋值给二维向量
			d.setid.push_back(d.getid);
			d.setspid.push_back(d.getspid);
			d.setsx.push_back(d.getsx);
			d.setsy.push_back(d.getsy);
			d.setsz.push_back(d.getsz);
			
		}
	for (int i=0;i<8;i++)//输出x的值检查
       cout << d.getsx[i] << endl;
	
	system("pause");
	return 0;
}

