#include <iostream>
#include <climits>
using namespace std;

int rodcutting(int a,int b, int c, int size){
    
    if(size == 0 ) return 0;
    if(size < 0 ) return -1;
    
    int op1{INT_MIN};
    int op2{INT_MIN};
    int op3{INT_MIN};
    
    op1 = rodcutting(a,b,c,size-a);
    op2 = rodcutting(a,b,c,size-b);
    op3 = rodcutting(a,b,c,size-c);
    
    int ans = max(max(op1,op2),op3);
    if(ans == -1) return -1;
    return 1 + ans; 
}

int main(){
    
    int a{};
    int b{};
    int c{};
    
    cin>>a>>b>>c;
    
    int rope;
    
    cin>>rope;
    
    cout<<rodcutting(a,b,c,rope)<<'\0';
    
}
