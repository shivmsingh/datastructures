class Solution {
    void dfs(unordered_map<int,vector<int>> &g, unordered_set<int>& visited, int node){
        visited.insert(node);
        for(auto nbr : g[node]){
            if(!visited.count(nbr)){
                dfs(g,visited,nbr);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        unordered_set<int> visited;
        
        unordered_map<int,vector<int>> g;
        
        for(int i = 0 ; i < isConnected.size() ; i++){
            for(int j = 0 ; j < isConnected[i].size() ; j++){
                if(isConnected[i][j] == 1 and i != j){
                    g[i].push_back(j);
                }
            }
        }
        
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(!visited.count(i)){
                count++;
                dfs(g,visited,i);
            }
        }
        
        return count;
    }
};