// 733. Flood Fill
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int a, int b, int n, int m, int c,vector<vector<int>>& image,vector<vector<bool>> &visited)
    {
        if(a>=0 && a<m && b>=0 && b<n && image[a][b] == c && !visited[a][b])
        {
            visited[a][b] = true;
            return true;
        }
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int st_color = image[sr][sc];
        image[sr][sc] = color;
        queue<pair<int,int>> q;

        q.push(make_pair(sr,sc));
        visited[sr][sc] = true;

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int a = p.first;
            int b = p.second;

            if(check(a+1,b,n,m,st_color,image,visited))
            {
                image[a+1][b] = color;
                q.push(make_pair(a+1,b));
            }

            if(check(a-1,b,n,m,st_color,image,visited))
            {
                image[a-1][b] = color;
                q.push(make_pair(a-1,b));
            }

            if(check(a,b+1,n,m,st_color,image,visited))
            {
                image[a][b+1] = color;
                q.push(make_pair(a,b+1));
            }

            if(check(a,b-1,n,m,st_color,image,visited))
            {
                image[a][b-1] = color;
                q.push(make_pair(a,b-1));
            }
        }

        return image;
    }
};