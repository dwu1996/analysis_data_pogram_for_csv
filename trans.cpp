#include<iostream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
int main()
{
	ifstream in;
	ofstream out;
	in.open("105上加簽.csv");
	out.open("105加簽統計.csv");
	string line;
	map<string,int> stat;
	string sid,dpt,cnb,cnm;
	while(getline(in,line))
	{
		int i=0;
		while(line[i]!=',')
		{
			sid+=line[i];
			i++;
		}
		i++;
		while(line[i]!=',')
		{
			dpt+=line[i];
			i++;
		}
		i++;
		while(line[i]!=',')
		{
			cnb+=line[i];
			i++;
		}
		i++;
		while(i<line.length())
		{
			cnm+=line[i];
			i++;
		}
		if(stat.find(cnm)==stat.end()){stat[cnm]=1;}
		else{stat[cnm]++;}
		sid.clear();dpt.clear();cnb.clear();cnm.clear();
	}
	for(auto i=stat.begin();i!=stat.end();i++)
	{
		out<<i->first<<","<<i->second<<endl;
	}
}
