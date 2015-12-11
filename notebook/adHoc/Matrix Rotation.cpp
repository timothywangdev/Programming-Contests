#include <iostream>
#include <cmath>
using namespace std;


// shift by one element clockwise
void rotate(int A[][3],int N){
  for(int i=0;i<=ceil(N/2)-1;i++){
    	int r=i;
    	int c=i;
    	int L=N-2*i;
    	int tmp=A[r][c];
    	if(L==1)continue;
    	// Left
    	for(int j=r;j<r+L-1;j++){
        	A[j][c]=A[j+1][c];
    }
    // Lower
    for(int j=c;j<c+L-1;j++){
      A[r+L-1][j]=A[r+L-1][j+1];
    }
    // Right
    for(int j=r+L-1;j>r;j--){
      A[j][r+L-1]=A[j-1][r+L-1];
    }
    // Upper
    for(int j=c+L-1;j>c;j--){
      A[r][j]=A[r][j-1];
    }
    A[r][c+1]=tmp;
  }
}

// Rotate 90 degree clockwise
void rotate_entire(int A[][4],int N){
   for(int i=0;i<=ceil(N/2)-1;i++){
 	int r=i;
 	int c=i;
 	int L=N-2*i;
 	int tmp;
 	for(int i=c;i<c+L-1;i++){
   	tmp=A[r][i];
   	int offset=i-c;
   	// upper
   	A[r][i]=A[r+L-1-offset][c];
   	// left
   	A[r+L-1-offset][c]=A[r+L-1][c+L-1-offset];
   	// lower
   	A[r+L-1][c+L-1-offset]=A[r+offset][c+L-1];
   	// right
   	A[r+offset][c+L-1]=tmp;
 	}
   }
}
int A[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

int main(){
  int N=4;
  //rotate(A,3);
  //rotate(A,3);
  rotate_entire(A,4);
  for(int i=0;i<N;i++){
	for(int j=0;j<N;j++){
  	cout<<A[i][j]<<" ";
	}
	cout<<endl;
  }
  return 0;
}



