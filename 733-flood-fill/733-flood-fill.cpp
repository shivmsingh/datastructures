class Solution {
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, int m, int n){
        queue<pair<int,int>> q;
        int initial = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr,sc});
        
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            if(row - 1 >= 0 and image[row - 1][col] == initial){
                image[row - 1][col] = color;
                q.push({row-1,col});
            }
            if(row + 1 < n and image[row + 1][col] == initial){
                image[row + 1][col] = color;
                q.push({row+1,col});
            }
            if(col + 1 < m and image[row][col + 1] == initial){
                image[row][col + 1] = color;
                q.push({row,col + 1});
            }
            if(col - 1 >= 0 and image[row][col - 1] == initial){
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
        bfs(image,sr,sc,color,m,n);
        
        return image;
    }
};