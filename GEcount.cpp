#include<iostream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
int main()
{
	ifstream in;
	ofstream out;
	in.open("104下加簽.csv");
	out.open("1042加簽統計_GE.csv");
	int ans=0;
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
		int tmp=0;
		for(int i=0;i<cnb.length()-1;i++)
		{
			if(cnb[i]=='G'&&cnb[i+1]=='E'){tmp=1;break;}
		}
		if(tmp>0){ans++;}
		if(stat.find(cnm)==stat.end()){stat[cnm]=1;}
		else{stat[cnm]++;}
		sid.clear();dpt.clear();cnb.clear();cnm.clear();
	}
	out<<"GE類別加簽數量,"<<ans<<endl;
	/*for(auto i=stat.begin();i!=stat.end();i++)
	{
		out<<i->first<<","<<i->second<<endl;
	}*/
}
