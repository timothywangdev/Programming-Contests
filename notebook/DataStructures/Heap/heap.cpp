#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

/*

a heap is a specialized tree-based data structure that satisfies the heap property: If A is a parent node of B then the key of node A is ordered with respect to the key of node B with the same ordering applying across the heap. A heap can be classified further as either a "max heap" or a "min heap". In a max heap, the keys of parent nodes are always greater than or equal to those of the children and the highest key is in the root node. In a min heap, the keys of parent nodes are less than or equal to those of the children and the lowest key is in the root node.

	Average	Worst case
Space	O(n)	O(n)
Search	O(n)	O(n)
Insert	O(1)	O(log n)
Delete	O(log n)O(log n)
Peek	O(1)	O(1)
*/

template <class ValueType, class compare = greater<ValueType> >
class Heap
{
private:
	compare compareFun;
	vector<pair<int, ValueType> > _vector;
	void BubbleDown(int index){
		int length = _vector.size();
		int leftChildIndex = 2 * index + 1;
		int rightChildIndex = 2 * index + 2;

		if (leftChildIndex >= length)
			return; //index is a leaf

		int minIndex = index;

		if (compareFun(_vector[index].first, _vector[leftChildIndex].first))
		{
			minIndex = leftChildIndex;
		}

		if ((rightChildIndex < length) && compareFun(_vector[minIndex].first, _vector[rightChildIndex].first))
		{
			minIndex = rightChildIndex;
		}

		if (minIndex != index)
		{
			//need to swap
			pair<int,ValueType> temp = _vector[index];
			_vector[index] = _vector[minIndex];
			_vector[minIndex] = temp;
			BubbleDown(minIndex);
		}
	}
	void BubbleUp(int index){
		if (index == 0)
			return;

		int parentIndex = (index - 1) / 2;

		if (compareFun(_vector[parentIndex], _vector[index]))
		{
			int temp = _vector[parentIndex];
			_vector[parentIndex] = _vector[index];
			_vector[index] = temp;
			BubbleUp(parentIndex);
		}
	}
	void Heapify(){
		int length = _vector.size();
		for (int i = length - 1; i >= 0; --i)
		{
			BubbleDown(i);
		}
	}

public:
	Heap(const vector<pair<int,ValueType> >& vector) : _vector(vector){
		Heapify();
	}
	Heap(){};

	void Insert(int key, ValueType value){
		int length = _vector.size();
		_vector[length] = make_pair(key,value);
		BubbleUp(length);
	}
	ValueType GetMin(){
		return _vector[0].second;
	}
	void DeleteMin(){
		int length = _vector.size();

		if (length == 0)
		{
			return;
		}

		_vector[0] = _vector[length - 1];
		_vector.pop_back();

		BubbleDown(0);
	}
	int size(){
		return _vector.size();
	}
};


int main(){

	vector<pair<int,int>> v;
	v.push_back(make_pair(130,130));
	v.push_back(make_pair(30,30));
	v.push_back(make_pair(140,140));
	v.push_back(make_pair(0,0));
	v.push_back(make_pair(5,5));
	v.push_back(make_pair(77,77));
	v.push_back(make_pair(-55,-55));
	// min heap
	// Heap<int, greater<int> > heap(v);
	// max heap
	Heap<int, less<int> > heap(v);
	while (heap.size()){
		cout << heap.GetMin() << endl;
		heap.DeleteMin();
	}
	return 0;
}

