#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

string dir[5]={"a","b","c","d","e"};
vector<string> headers;
string s;
void writeHeaders(ofstream &fout){
   for(auto i:headers){
      fout<<i<<endl;
   }
}
int main(){
   ifstream fin("headers.cpp");
   while(getline(fin,s)){
      headers.push_back(s);
   }
   fin.close();
   for(int i=0;i<5;i++){
      mkdir(dir[i].c_str(),0777);
      ofstream fout(dir[i]+"/"+dir[i]+".cpp");
      writeHeaders(fout);
      fout.close();
   }
   return 0;
}
