Moore’s Voting Algorithm
Time Complexity: O(n)
Auxiliary Space : O(1)

1. Finding a Candidate:
The algorithm for first phase that works in O(n) is known as Moore’s Voting Algorithm. Basic idea of the algorithm is if we cancel out each occurrence of an element e with all the other elements that are different from e then e will exist till end if it is a majority element. 

2.Check the Candidate

#include <vector>
#include <iostream>
using namespace std;
 

template <class T>
bool majorityElement(vector<T> v, T &candidate){
	int index = 0, count = 1;
	for(int i = 1; i < (int)v.size(); i++)
	{
    	if(v[index] == v[i])
        	count++;
    	else
        	count--;
    	if(count == 0)
    	{
        	index = i;
        	count = 1;
    	}
	}
	// Check if v[index] is a real majority element
	count=0;
	candidate=v[index];
	for (int i = 0; i < (int)v.size(); i++)
  	if(v[i] == candidate)
    count++;
	if(count>(int)v.size()/2){
  	return true;
	}
	else{
  	return false;
	}
}

int main()
{
  int a[] = {1, 3, 3, 3, 2, 6, 3, 0, 3, 3};
	vector<int> v;
	v.assign(&a[0],&a[0]+10);
	int cand;
	if(majorityElement<int>(v,cand)){
  	cout<<cand<<endl;
	}
	else{
  	cout<<"Not Exist"<<endl;
	}
	return 0;
}

