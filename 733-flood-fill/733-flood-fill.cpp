class Solution {
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, int m, int n, vector<vector<bool>> &visited){
        queue<pair<int,int>> q;
        int initial = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr,sc});
        visited[sr][sc] = true;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            if(row - 1 >= 0 and !visited[row-1][col] and image[row - 1][col] == initial){
                visited[row - 1][col] = 1;
                image[row - 1][col] = color;
                q.push({row-1,col});
            }
            if(row + 1 < n and !visited[row+1][col] and image[row + 1][col] == initial){
                visited[row + 1][col] = 1;
                image[row + 1][col] = color;
                q.push({row+1,col});
            }
            if(col + 1 < m and !visited[row][col + 1] and image[row][col + 1] == initial){
                visited[row][col + 1] = 1;
                image[row][col + 1] = color;
                q.push({row,col + 1});
            }
            if(col - 1 >= 0 and !visited[row][col - 1] and image[row][col - 1] == initial){
                visited[row][col - 1] = 1;
                image[row][col - 1] = color;
                q.push({row,col - 1});
            }
            
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        bfs(image,sr,sc,color,m,n, visited);
        
        return image;
    }
};