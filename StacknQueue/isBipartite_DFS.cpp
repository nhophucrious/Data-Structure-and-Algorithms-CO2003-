#include<iostream>
#include<queue>
#include<stack>
using namesapce std;
//DFS method

     bool dfs(int i,vector<vector<int>>& graph,vector<int> &color,int c)
    {
        if(color[i]!=0)return color[i]==c;
        color[i]=c;
        for(auto x:graph[i])
        {
            if(!dfs(x,graph,color,-c))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==0 && !dfs(i,graph,color,1))
                return false;
        }
        return true;
    }



int main()
{
 int G[6][6] = { {0, 1, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 1, 0} };
int n = 6;

vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (G[i][j]) graph[i].push_back(j);
		}
	}

isBipartite(graph) ? cout << "Yes" : cout << "No";
  return 0;
}
