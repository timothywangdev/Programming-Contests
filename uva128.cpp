//#define DEBUG

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#ifdef DEBUG
ifstream fin("uva128.in");
ofstream fout("uva128.out");
#endif

string message;

long long getCons(){
   long long remainder=0;
   for(unsigned long long  i=0;i<=message.length()-2;i=i+2){
       remainder+=((unsigned short)message[i])*256+((unsigned short)message[i+1]);
       remainder=remainder%34943;
	   if(i!=message.length()-2)
	     remainder=remainder<<16;

   }
   return remainder;
}

void outPutCRC(long long crc){
     long long high,low;
	 high=crc>>8;
	 low=crc-(high<<8);
	 #ifdef DEBUG
     fout<<uppercase<<setfill('0')<<setw(2)<<hex<<high<<" "<<setw(2)<<low<<endl;
     #else
	 cout<<uppercase<<setfill('0')<<setw(2)<<hex<<high<<" "<<setw(2)<<low<<endl;
     #endif
}
int main(){
	while(true){
		 message.clear();
		 #ifdef DEBUG
         getline(fin,message);
		 #else
		 getline(cin,message);
		 #endif

		 if(message.length()!=0&&message[0]=='#')
			 return 0;
		 if(message.size()%2==1)
			 message='\0'+message;
		 message=message+'\0'+'\0';
		 long long crc=34943-getCons();
		 outPutCRC((crc!=34943)?crc:0);
	}
	return 0;
}

