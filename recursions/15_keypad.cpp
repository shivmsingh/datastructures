#include <iostream>
using namespace std;

string digits[10] = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(string s,char* out,int idx){
	
	if(s[idx] == '\0'){
		out[idx] = '\0';
		cout << out <<'\n';
	}

	int digit = s[idx] - '0';
	if(digit == 0 || digit == 1) keypad(s,out,idx+1);

	for(int i = 0 ; i != digits[digit].size() ; i++){
		out[idx] = digits[digit][i];
		keypad(s,out,idx+1);
	}

}

int main(){
	string s;
	char out[300];
	getline(cin,s);
	keypad(s,out,0);
}
