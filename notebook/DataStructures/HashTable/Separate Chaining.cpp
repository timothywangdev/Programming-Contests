#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;


template <class Key_Type, class Value_Type, class hashFunc>
class HashTable{
  vector<list<pair<Key_Type, Value_Type>>> table;
  hashFunc func;
public:
  HashTable(int size){
    table = vector<list<pair<Key_Type, Value_Type>>>(size, list<pair<Key_Type, Value_Type>>());
  }
  bool get(Key_Type key, Value_Type &value){
    int pos = func(key)%table.size();
    for(typename list<pair<Key_Type, Value_Type> >::iterator it=table[pos].begin();it!=table[pos].end();it++){
      if(it->first==key){
	value = it->second;
	return true;
      }
    }
    return false;
  }
  void insert(Key_Type key, Value_Type value){
     int pos = func(key)%table.size();
    for(typename list<pair<Key_Type, Value_Type>>::iterator it=table[pos].begin();it!=table[pos].end();it++){
      if(it->first==key){
	it->second = value;
	return;
      }
    }
    table[pos].push_front(make_pair(key,value));
  }
  void remove(Key_Type key){
    int pos = func(key)%table.size();
    for(typename list<pair<Key_Type, Value_Type>>::iterator it=table[pos].begin();it!=table[pos].end();it++){
      if(it->first==key){
	table[pos].erase(it);
	return;
      }
    }
  }
};

template<class Key_Type>
struct HashFunc {
  hash<Key_Type> h;
  int operator()(Key_Type key){return h(key);}
};

int main(){
  HashTable<string, string, HashFunc<string>> ht(31);
	ht.insert("abc", "123");
	ht.insert("def", "456");
	ht.insert("aaa", "789");
	ht.insert("bbb", "000");
	string s;
	bool rv;
	rv = ht.get("abc", s);
	cout << s << endl;
	rv = ht.get("def", s);
	cout << s << endl;
	rv = ht.get("aaa", s);
	cout << s << endl;
	rv = ht.get("bbb", s);
	cout << s << endl;
	rv = ht.get("ccc", s);
	cout << rv<<" "<<s << endl;
	ht.remove("def");
	rv = ht.get("DEF", s);
	cout << rv<<" "<<s << endl;
return 0;
}


