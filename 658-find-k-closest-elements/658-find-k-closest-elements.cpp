class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        
        int j = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        int i = j-1;
        
        while(pq.size() < k){
            if(i < 0){
                pq.push(arr[j++]);
            }else if(j >= arr.size()){
                pq.push(arr[i--]);
            }else if(abs(arr[i] - x) <= abs(arr[j] - x)){
                pq.push(arr[i--]);
            }else{
                pq.push(arr[j++]);
            }
        }
        
        vector<int> result;
        
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};