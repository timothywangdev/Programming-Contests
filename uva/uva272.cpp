#include <string>
#include <stdio.h>
using namespace std;

int main(){
	char ch;
	bool shit=true;
	while(scanf("%c",&ch)!=EOF){
		if(ch=='"'){
			if(shit)
				printf("``");
			else
				printf("''");
			shit=1-shit;
		}
		else
			printf("%c",ch);
	}
	return 0;
}