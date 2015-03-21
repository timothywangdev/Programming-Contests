#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

vector<string> dir;
vector<string> headers;
string s;
void writeHeaders(ofstream &fout){
   for(auto i:headers){
      fout<<i<<endl;
   }
}
int main(int argc, char *argv[]){
   for(int i=1;i<argc;i++){
      dir.push_back(string(argv[i]));
   }
   ifstream fin("headers.cpp");
   while(getline(fin,s)){
      headers.push_back(s);
   }
   fin.close();
   for(int i=0;i<dir.size();i++){
      mkdir(dir[i].c_str(),0777);
      ofstream fout(dir[i]+"/"+dir[i]+".cpp");
      writeHeaders(fout);
      fout.close();
   }
   return 0;
}
