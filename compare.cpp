#include<iostream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
int main()
{
	ifstream in,in2;
	ofstream out;
	in.open("105上加簽.csv");
	in2.open("104下加簽.csv");
	out.open("1051010420比較後_1051大於1042.csv");
	string line;
	map<string,int> stat,stat2;
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
	while(getline(in2,line))
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
		if(stat2.find(cnm)==stat2.end()){stat2[cnm]=1;}
		else{stat2[cnm]++;}
		sid.clear();dpt.clear();cnb.clear();cnm.clear();
	}
	for(auto i=stat.begin();i!=stat.end();i++)
	{
		for(auto j=stat2.begin();j!=stat2.end();j++)
		{
			if(i->first==j->first&&i->second>j->second)
			{out<<i->first<<","<<i->second<<","<<j->second<<endl;}
		}
		//out<<i->first<<","<<i->second<<endl;
	}
}
