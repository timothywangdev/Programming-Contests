#include <iostream>

using namespace std;
#include <fstream>
using namespace std;
//#define DEBUG
#ifdef DEBUG
ifstream fin("test.in");
ofstream fout("test.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(fin.rdbuf());
	std::streambuf *coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(fout.rdbuf());
#endif
}

int N,tmp;
bool found;
int main(){
	redirect();
	while (cin >> N){
		if (!N){
			break;
		}
		found = false;
		for (int i = 0; i < N; i++){
			cin >> tmp;
			if (tmp){
				if (found){
					cout << " ";
				}
				cout << tmp;
				found = true;
			}
		}
		if (!found){
			cout << "0" << endl;
		}
		else{
			cout << endl;
		}

	}
	return 0;
}