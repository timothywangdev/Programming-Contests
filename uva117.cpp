//#define DEBUG
#include <iostream>
#include <fstream>
#include <string>
#include "string.h"

using namespace std;

#define MAXIMUM 2021161080
#ifdef DEBUG
ifstream fin("uva117.in");
ofstream fout("uva117.out");
#endif
int oddDegree[2];
int degree[26];
int p[26][26];
int oddDegreeCount,sumLength;
string road;
int shortest(int source,int dest){
     int dist[26],minimum,themin;
	 bool used[26];
	 memset(used,false,sizeof(used));
	 memset(dist,120,sizeof(dist));
     for(int i=0;i<26;i++)
		 dist[i]=p[source][i];

	 dist[source]=0;
	 used[source]=true;

	 while(true){
         minimum=MAXIMUM;
         for(int i=0;i<26;i++)
			 if(!used[i]&&dist[i]<minimum){
                 minimum=dist[i];
				 themin=i;
			 }
		 used[themin]=true;

		 if(minimum==MAXIMUM){
			 break;
		 }
		 for(int i=0;i<26;i++)
		   if(!used[i])
			 if(dist[themin]+p[themin][i]<dist[i])
				 dist[i]=dist[themin]+p[themin][i];
	 }
	 return dist[dest];
}
void setRoad(string name){
    int intersection_1=(int)(name[0]-'a');
	int intersection_2=(int)(name[name.length()-1]-'a');
	p[intersection_1][intersection_2]=p[intersection_2][intersection_1]=name.length();
    degree[intersection_1]++;
	degree[intersection_2]++;
	sumLength+=name.length();
}
int main(){
	while(cin>>road){
		sumLength=0;
		memset(degree,0,sizeof(degree));
		memset(p,120,sizeof(p));
		while(true){
		   if(road!="deadend")
			   setRoad(road);
		   else
			   break;
		   cin>>road;
		}
        oddDegreeCount=0;
        for(int i=0;i<26;i++)
			if(degree[i]%2!=0){
			   oddDegree[oddDegreeCount]=i;
               oddDegreeCount++;
			}
#ifdef DEBUG
		if(oddDegreeCount==0)
            fout<<sumLength<<endl;
		else
			fout<<sumLength+shortest(oddDegree[0],oddDegree[1])<<endl;
		if(fin.eof())
			break;
#else
		if(oddDegreeCount==0){
            cout<<sumLength<<endl;
		}
		else{
			cout<<sumLength+shortest(oddDegree[0],oddDegree[1])<<endl;
		}
#endif
	    
	}

  return 0;
}