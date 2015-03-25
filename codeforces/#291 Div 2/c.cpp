#include <bits/stdc++.h>

using namespace std;

string s;
int n,m;
char t;
bool found;

#define M 10000
#define tr(c,i) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
class Trie;
class Trie {
    public:
        Trie* edge[4];
  Trie(){
    for(int i=0;i<4;i++){
      edge[i]=NULL;
    }
  }
        void addWord(int idx){
	  if(idx==s.length())return;
	  int k=(int)(s[idx]-'a');
	  if(edge[k]==NULL){
	    edge[k]=new Trie();
	  }
	  edge[k]->addWord(idx+1);
	}
  bool searchWord(int idx,bool changed){
    if(idx==s.length()&&changed)return true;
    if(changed||idx==s.length()-1){
      if(edge[s[idx]-'a']){
	return edge[s[idx]-'a']->searchWord(idx+1,changed);
      }
    }
    else{
      for(int p=0;p<3;p++){
	if(p==(int)(s[idx]-'a')){
	  if(edge[p]&&edge[p]->searchWord(idx+1,false))return true;
	}
	else{
	  if(edge[p]&&edge[p]->searchWord(idx+1,true))return true;
	}
      }
    }
    return false;
  }
};



int main(){
  Trie *root=new Trie();
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>s;
    s=s+'d';
    root->addWord(0);
  }
  for(int j=0;j<m;j++){
    cin>>s;
    s=s+'d';
    found=root->searchWord(0,false);
    if(found){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
