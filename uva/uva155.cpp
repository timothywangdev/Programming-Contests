#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
#ifdef DEBUG
ifstream fin("uva155.in");
ofstream fout("uva155.out");
#endif
int K,X,Y,counter;
class Square{
public:
    int x;
	int y;
	int k;
	Square(int x,int y,int k):x(x),y(y),k(k){}
};

vector<Square*> squares;
bool checkBorders(int x,int y,int k){
    if(x-k>=1&&
	   x+k<=2049&&
	   y-k>=1&&
	   y+k<=2049)
    return true;

    return false;
}
void createSquare(int x,int y,int k){

	if(k>=1&&checkBorders(x,y,k))
	  squares.push_back(new Square(x,y,k));
	else
	  return;

	createSquare(x-k,y-k,k/2);
    createSquare(x-k,y+k,k/2);
	createSquare(x+k,y-k,k/2);
	createSquare(x+k,y+k,k/2);
}

bool inSquare(int i){
	int sx=squares[i]->x,
		sy=squares[i]->y,
		sk=squares[i]->k;

	if(sx-sk<=X&&X<=sx+sk&&
	   sy-sk<=Y&&Y<=sy+sk)
	   return true;
	return false;
}


int main(){
	while(cin>>K>>X>>Y){
       if(K==0&&X==0&&Y==0)
		   break;
	   X++;
	   Y++;
	   squares.clear();
	   counter=0;
	   createSquare(1025,1025,K);
	   for(unsigned int i=0;i<squares.size();i++)
		   if(inSquare(i))
			   counter++;
	   cout<<setw(3)<<counter<<endl;
	}
}