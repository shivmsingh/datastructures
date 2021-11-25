#include <iostream>
using namespace std;

void generateBrackets(int pair , int opening , int closing, int idx,char* out){
    
    if(idx == 2*pair){
        out[idx] = '\0';
        cout<<out<<'\n';
        return;
    }
    
    if(opening < pair){
        out[idx] = '(';
        generateBrackets(pair,opening+1,closing,idx+1,out); 
    }
    
    if(closing < opening ){
        out[idx] = ')';
        generateBrackets(pair,opening,closing+1,idx+1,out);
    }
    
}

int main(){
    int n;
    cin>>n;
    char out[100];
    generateBrackets(n,0,0,0,out);
    cout<<"\n";
}
