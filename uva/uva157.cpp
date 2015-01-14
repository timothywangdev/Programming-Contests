#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "string.h"
#include <iomanip>s
#define MAXIMUM 168430090;
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("uva157.in");
ofstream fout("uva157.out");
#endif
map<char,int> toRouteInt;
map<int,char> toRouteChar;

int NR;
string route[26];
int maxSize[26];
map<char,int> toStaInt[26];
map<char,int> toStaRealPos[26];
map<int,char> toStaChar[26];
string s;

struct IntTri{
	int a;
	int b;
	int dist;
};
class Adj{
private:
	int thea;
	int theb;
	int last;
	int routeIndex;
	int staPos;
	vector<IntTri> tris;
	IntTri invalid;
public:
	void prepareTris(){
		// Find before
		int index=toStaInt[routeIndex][(char)(theb+'a')];
		// If previous node exists
		if(index>0){
			char before=toStaChar[routeIndex][index-1];
			IntTri it;
			it.a=thea;
			it.b=before-'a';
			it.dist=1;
			tris.push_back(it);
		}
		// Find after
		int pos=staPos+1;
		while(pos<route[routeIndex].length()&&route[routeIndex][pos]=='='){
			IntTri it;
			it.a=route[routeIndex][pos+1]-'A';
			it.b=route[routeIndex][pos+2]-'a';
			it.dist=3;
			tris.push_back(it);
			pos+=3;
		}
		if(pos<route[routeIndex].length()){
			IntTri it;
			it.a=thea;
			it.b=route[routeIndex][pos]-'a';
			it.dist=1;
			tris.push_back(it);
		}

	}
	Adj(int thea,int theb):thea(thea),theb(theb){
		last=-1;
		routeIndex=toRouteInt[(char)(thea+'A')];
		staPos=toStaRealPos[routeIndex][(char)(theb+'a')];
		invalid.a=-1;
		invalid.b=-1;
		invalid.dist=-1;

		prepareTris();
	}
	IntTri getIntPair(){
		if(last+1<tris.size()){
			last++;
			return tris[last];
		}
		else
			return invalid;
	}

};
void insert(int target,int pos,string content){
	route[target].insert(pos,content);
}
void checkConnection(int from,char fromCh,int target,char targetCh){
	string s;
	for(unsigned int i=0;i<route[target].length();i++)
		if(route[target][i]==targetCh){
			int k=i+1;
			while(route[target][k]=='='){
				// if found then return
				if(route[target][k+1]==toRouteChar[from]&&
					route[target][k+2]==fromCh)
					return;
				k+=3;
			}
			// Not found
			char routeChar=toRouteChar[from];
			s=s+"="+routeChar+fromCh;
			insert(target,k,s);
			return;
		}
}

void generalize(){
	for(int i=0;i<NR;i++)
		for(unsigned int j=0;j<route[i].length();j++)
			if(route[i][j]=='=')
				checkConnection(i,route[i][j-1],toRouteInt[route[i][j+1]],route[i][j+2]);

	for(int i=0;i<NR;i++){
		int counter=0;
		//if('a'<=route[i][j]&&route[i][j]<='z'&&
		//	  (((j-1>=0)&&('A'<=route[i][j-1]&&route[i][j-1]<='Z'))||j-1<0))
		for(int j=0;j<(int)route[i].length();j++)
			if('a'<=route[i][j]&&route[i][j]<='z'&&
				((j>=2&&route[i][j-2]!='=')||j-2<0)){
					toStaInt[i][route[i][j]]=counter;
					toStaChar[i][counter]=route[i][j];
					toStaRealPos[i][route[i][j]]=j;
					counter++;
			}
			maxSize[i]=counter;
	}

}

void calShortestPath(string s){
	int startRoute=toRouteInt[s[0]],
		endRoute=toRouteInt[s[2]],
		startSta=toStaInt[startRoute][s[1]],
		endSta=toStaInt[endRoute][s[3]];

	int dist[26][26],shortest,thea,theb;
	int pa[26][26],pb[26][26],steps[26][26];
	int a,b;
	bool used[26][26];
	memset(dist,10,sizeof(dist));
	memset(used,false,sizeof(used));
	memset(steps,0,sizeof(steps));
	dist[s[0]-'A'][s[1]-'a']=0;

	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			pa[i][j]=pb[i][j]=-1;
	//used[startRoute][startSta]=true;
	while(true){
		shortest=MAXIMUM;
		thea=-1;
		theb=-1;
		for(int i=0;i<NR;i++){
			a=toRouteChar[i]-'A';
			for(int j=0;j<maxSize[i];j++){
				b=toStaChar[i][j]-'a';
				if(!used[a][b])
					if(dist[a][b]<shortest){
						shortest=dist[a][b];
						thea=a;
						theb=b;
					}
			}
		}
		if(thea==-1)
			break;

		used[thea][theb]=true;

		Adj adj(thea,theb);
		IntTri ip=adj.getIntPair();
		while(ip.a!=-1){
			if(!used[ip.a][ip.b]){
				if(ip.dist==3){
					int ppa=pa[thea][theb],
						ppb=pb[thea][theb];
					if(ppa!=-1&&ppb!=-1){
						int previousDist=dist[ppa][ppb];
						int currentDist=dist[thea][theb];
						int deltaDist=currentDist-previousDist;
					    if(deltaDist==3)
							ip.dist=0;
					}
				}
				if(dist[thea][theb]+ip.dist<dist[ip.a][ip.b]){
					steps[ip.a][ip.b]=steps[thea][theb]+1;
					dist[ip.a][ip.b]=dist[thea][theb]+ip.dist;
					if(ip.dist!=0){
					 pa[ip.a][ip.b]=thea;
					 pb[ip.a][ip.b]=theb;
					}
					else{
					 pa[ip.a][ip.b]=pa[thea][theb];
					 pb[ip.a][ip.b]=pb[thea][theb];
					}
				}
				
			}
			ip=adj.getIntPair();
		}
	} 
	int currA=pa[s[2]-'A'][s[3]-'a'],
		currB=pb[s[2]-'A'][s[3]-'a'];
	int nextA=s[2]-'A';
	string path="";
	if(dist[s[2]-'A'][s[3]-'a']!=0){
		path=path+s[3];
		while(!(currA==-1&&currB==-1)){
			if(currA==nextA)
				path=path+(char)(currB+'a');
			else{
				path=path+(char)(nextA+'A')+'='+(char)(currB+'a');
				nextA=currA;
			}
			int oA=currA,oB=currB;
			currA=pa[oA][oB];
			currB=pb[oA][oB];
		}

	}
	else
		path=path+s[1];
	path=path+s[0];
#ifdef DEBUG
	fout<<setw(3)<<dist[s[2]-'A'][s[3]-'a']<<": ";
	for(int i=(int)path.length()-1;i>=0;i--)
		fout<<path[i];
	fout<<endl;
#else
	cout<<setw(3)<<dist[s[2]-'A'][s[3]-'a']<<": ";
	for(int i=(int)path.length()-1;i>=0;i--)
		cout<<path[i];
	cout<<endl;
#endif

}

int main(){
#ifdef DEBUG
	fin>>NR;
	for(int i=0;i<NR;i++){
		fin>>s;
#else
	cin>>NR;
	for(int i=0;i<NR;i++){
		cin>>s;
#endif

		route[i]=s.substr(2,s.length()-2);
		toRouteInt[s[0]]=i;
		toRouteChar[i]=s[0];
	}
	generalize();
#ifdef DEBUG
	while(fin>>s){
#else
	while(cin>>s){
#endif
		if(s[0]=='#')
			break;
		calShortestPath(s);
	}

	return 0;
}