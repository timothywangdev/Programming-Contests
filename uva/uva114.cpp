//#define DEBUG
#define MAXIMUM 2000000000
#include <iostream>
#include <fstream>

using namespace std;

#ifdef DEBUG
ifstream fin("uva114.in");
ofstream fout("uva114.out");
#endif

struct BUMP{
  int x;
  int y;
  int v;
  int c;
};

BUMP bump[2500];

int M,N,WC,X,Y,D,P,L,S,V=0,minimum,thei;
bool foundBump;
void change(int i){
   D=D-1;
   if(D==-1)
	   D=3;
   L-=bump[i].c;
   V+=bump[i].v;
}
int main(){
    #ifdef DEBUG
    fin>>M>>N>>WC>>P;
	for(int i=0;i<P;i++){
       fin>>bump[i].x>>bump[i].y>>bump[i].v>>bump[i].c;
	}
	while(fin>>X>>Y>>D>>L){
    #else
    cin>>M>>N>>WC>>P;
	for(int i=0;i<P;i++){
       cin>>bump[i].x>>bump[i].y>>bump[i].v>>bump[i].c;
	}
	while(cin>>X>>Y>>D>>L){
    #endif
      V=0;
	  while(L>=1){	
	    foundBump=false;
		minimum=MAXIMUM;
		thei=-1;
		if(D==0){
			for(int i=0;i<P;i++){
			   if(bump[i].y==Y&&bump[i].x>X&&(L>(bump[i].x-X)))
				   if(bump[i].x-X<minimum){
					   minimum=bump[i].x-X;
					   thei=i;
			           foundBump=true;
				   }
			}
			if(foundBump){	   
			 L-=bump[thei].x-X;
		     change(thei);
			 X=bump[thei].x-1;
			}
			   
		}
		else if(D==1){
           for(int i=0;i<P;i++)
			   if(bump[i].x==X&&bump[i].y>Y&&(L>(bump[i].y-Y))){
				   if(bump[i].y-Y<minimum){
					   minimum=bump[i].y-Y;
					   thei=i;
					   foundBump=true;
				   }
		   }
		   if(foundBump){	
		    L-=bump[thei].y-Y;
		    change(thei);
		    Y=bump[thei].y-1;
		   }
		}
		else if(D==2){
           for(int i=0;i<P;i++)
			   if(bump[i].y==Y&&bump[i].x<X&&(L>(X-bump[i].x))){
				   	if(X-bump[i].x<minimum){
					   minimum=X-bump[i].x;
					   thei=i;
					   foundBump=true;
				   }
		   }
            if(foundBump){	
			 L-=X-bump[thei].x;
			 change(thei);
			 X=bump[thei].x+1;
			}
			   
		}
		else if(D==3){
           for(int i=0;i<P;i++)
			   if(bump[i].x==X&&bump[i].y<Y&&L>(Y-bump[i].y)){
				   	if(Y-bump[i].y<minimum){
					   minimum=Y-bump[i].y;
					   thei=i;
					   foundBump=true;
				   }
		   }
            if(foundBump){	
			  L-=Y-bump[thei].y;
			  change(thei);
			  Y=bump[thei].y+1;
			}
			   
		}
        //HIT WALL
		if(!foundBump){
			if(D==0){
				L-=M-X;
                X=M-1;
			}
			else if(D==1){
				L-=N-Y;
                Y=N-1;
			}
			else if(D==2){
				L-=X-1;
                X=2;
			}
			else if(D==3){
				L-=Y-1;
                Y=2;
			}
		    D=D-1;
            if(D==-1)
	          D=3;
			L-=WC;
	    }
    #ifdef DEBUG
	  }
	  fout<<V<<endl;
	  S+=V;
	}
	fout<<S<<endl;
    #else
	  }
	  cout<<V<<endl;
	  S+=V;
	}
	cout<<S<<endl;
    #endif
	return 0;
}