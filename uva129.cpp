//#define DEBUG
#include <iostream>
#include <fstream>
#include <string>
#include "stdio.h"
using namespace std;
#ifdef DEBUG
ifstream fin("uva129.in");
ofstream fout("uva129.out");
#endif
char ch[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char s[81];
int n,l,group,pos;
bool found;
bool repetitive(int sa,int ea,int sb,int eb){
       for(int i=0;i<=ea-sa;i++)
		   if(s[sa+i]!=s[sb+i])
			   return false;
	   return true;
}
bool hard(int j){
	pos++;
	s[pos]=ch[j];
    for(int L=1;L<=(pos+1)/2;L++)
		if(repetitive(pos-L+1,pos,pos-2*L+1,pos-L)){
			s[pos]='/0';
			pos--;
			return false;
		}
	s[pos]='/0';
	pos--;
	return true;
}
int main(){
	while(true){
		pos=-1;
        scanf("%d %d",&n,&l);
		if(n==0&&l==0)
			break;
		for(int i=1;i<=n;i++){
            found=false;
			for(int j=0;j<l;j++)
				if(hard(j)){
                  pos++;
				  s[pos]=ch[j];
				  found=true;
				  s[pos+1]='\0';
				  //fout<<i<<" "<<s<<endl;
				  //printf("%s\n",s);
				  break;
				}
			while(!found){
				pos--;
				for(int j=(s[pos+1]-'A')+1;j<l;j++)
				  if(hard(j)){
                    pos++;
				    s[pos]=ch[j];
				    found=true;
					s[pos+1]='\0';
					//fout<<i<<" "<<s<<endl;
					//printf("%s\n",s);
					break;	
				  }  
			    //if(!found)
			    // pos--;
			}
		}
		int group=0;
		for(int i=0;i<=pos;i++){
			if(i%4==0&&i!=0){
                group++;
				if(group%16==0)
					printf("\n%c",s[i]);
				else
					printf(" %c",s[i]);
			}
			else{
				printf("%c",s[i]);
			}
		}
		printf("\n%d\n",pos+1);
	}
return 0;
}