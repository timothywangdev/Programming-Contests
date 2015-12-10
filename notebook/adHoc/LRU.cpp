#include <bits/stdc++.h>

using namespace std;
#define PII pair<int,int>
#define mp make_pair

class LRUCache{
    int capacity;
    list<PII> l;
    unordered_map<int,list<PII>::iterator> hash;
public:
    LRUCache(int capacity) {
        list<PII> l;
        this->capacity=capacity;
    }
    void moveToFront(list<PII>::iterator t){
        PII p = *t;
        l.erase(t);
        l.push_front(p);
        hash[p.first]=l.begin();
    }
    int get(int key) {
        if(hash.count(key)){
            list<PII>::iterator t=hash[key];
            PII rv=*t;
            moveToFront(t);
            return rv.second;
        }
        else{
            return -1;
        }
    }
    
    void set(int key, int value) {
        if(hash.count(key)){
            list<PII>::iterator it=hash[key];
            (*it).second=value;
            moveToFront(it);
        }
        else{
            if(l.size()==capacity){
                list<PII>::iterator last=l.end();
                last--;
                PII la=*(last);
                hash.erase(la.first);
                l.pop_back();
            }
            l.push_front(mp(key,value));
            hash[key]=l.begin();
        }
    }
};
