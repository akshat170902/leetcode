class Solution {
public:
    void dfs(vector<vector<int>>&image,int i,int j,int color,int src){
        int m=image.size(),n=image[0].size();
        if(i<0||i>=m||j<0||j>=n||image[i][j]!=src){
            return;
        }
        vector<pair<int,int>>p={{1,0},{-1,0},{0,1},{0,-1}};
        image[i][j]=color;
        for(int k=0;k<p.size();k++){
            dfs(image,i+p[k].first,j+p[k].second,color,src);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color)
            dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};