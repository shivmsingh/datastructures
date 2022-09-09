class Solution {
    void bfs(int row, int col ,const vector<vector<char>>& grid, int m, int n, vector<vector<bool>> &visited){
        queue<pair<int,int>> q;
        q.push(make_pair(row,col));
        visited[row][col] = 1;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();   
            
            if(row - 1 >= 0 and !visited[row-1][col] and grid[row - 1][col] == '1'){
                visited[row - 1][col] = 1;
                q.push({row-1,col});
            }
            if(row + 1 < n and !visited[row+1][col] and grid[row + 1][col] == '1'){
                visited[row + 1][col] = 1;
                q.push({row+1,col});
            }
            if(col + 1 < m and !visited[row][col + 1] and grid[row][col + 1] == '1'){
                visited[row][col + 1] = 1;
                q.push({row,col + 1});
            }
            if(col - 1 >= 0 and !visited[row][col - 1] and grid[row][col - 1] == '1'){
                visited[row][col - 1] = 1;
                q.push({row,col - 1});
            }
        }
        }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(!visited[row][col] and grid[row][col] == '1'){
                   count++;
                    bfs(row,col,grid,m,n,visited);
                   
                }
            }
        }
        
        return count;
    }
};