class Solution {
    void bfs(queue<pair<pair<int,int>,int>> &q, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& minute, int& fresh){
        
        int m = grid.size();
        int n = grid[0].size();
        
        while(!q.empty()){
           
            int row = q.front().first.first;
            int col = q.front().first.second;
            minute = max(minute,q.front().second);
            q.pop();
            
            if(row - 1 >= 0 and !visited[row-1][col] and grid[row - 1][col] == 1){
                grid[row - 1][col] = 2;
                visited[row - 1][col] = 1;
                q.push(make_pair(make_pair(row-1,col),minute+1));
                fresh--;
            }
            if(col + 1 < n and !visited[row][col + 1] and grid[row][col + 1] == 1){
                grid[row][col + 1] = 2;
                visited[row][col + 1] = 1;
                q.push(make_pair(make_pair(row,col + 1),minute+1));
                fresh--;
            }
            if(row + 1 < m and !visited[row+1][col] and grid[row + 1][col] == 1){
                grid[row + 1][col] = 2;
                visited[row + 1][col] = 1;
                q.push(make_pair(make_pair(row+1,col),minute+1));
                fresh--;
            }
            if(col - 1 >= 0 and !visited[row][col - 1] and grid[row][col - 1] == 1){
                grid[row][col - 1] = 2;
                visited[row][col - 1] = 1;
                q.push(make_pair(make_pair(row,col - 1),minute+1));
                fresh--;
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minute = 0;
        int fresh = 0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == 2 and !visited[i][j]){
                   q.push(make_pair(make_pair(i,j),0));
                    visited[i][j] = 1;
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        bfs(q,grid,visited,minute,fresh);
            
        if(fresh) return -1;
        
        return minute;
    }
};