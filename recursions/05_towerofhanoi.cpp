#include<iostream>
using namespace std;

void towerofHanoi(int n, char src, char helper, char dest){
       if(n==0) return;
       
    towerofHanoi(n-1,src, dest , helper);
    cout << "Moved " << n <<' ' <<src << " -> " << dest <<'\n';
    towerofHanoi(n-1, helper , src , dest);    
}

int main(){

int n{};
cin >> n;

towerofHanoi(n,'A','B','C');

}
