#include <iostream>
#include <climits>
using namespace std;

int knapsack(int capacity , int *price, int *weight , int size){
	if(size < 0 || capacity == 0) return 0;
	
	int ans = 0;
	int inc{INT_MIN};
	int exc{INT_MIN};
	if(capacity >= weight[size]){
	   inc = price[size] + knapsack(capacity - weight[size], price, weight, size-1);
	}

	exc = knapsack(capacity,price,weight,size-1);
	ans = max(inc,exc);
	return ans;
}

int main(){
	int n{};
	cin >> n;
	
	int price[100] = {};
	int weight[100] = {};	

	for(int i = 0 ; i < n ; i++){
		cin >> price[i];
		cin >> weight[i];
	}
	
	int capacity{};
	cin >> capacity;
	
	cout << knapsack(capacity,price,weight,n-1) << '\n' ;


}
