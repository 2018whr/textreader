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
				
				d.f_setspid(5, line);
			}
			else if (idx2 != string::npos)
			{
				d.f_setsx(2, line);
			}
			else if (idx3 != string::npos)
			{
				d.f_setsy(2, line);
			}
			else if (idx4 != string::npos)
			{
				d.f_setsz(2, line);
			}
			else
			{
				d.f_setid(3, line);
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

