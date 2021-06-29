Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@minhdang2803 
minhdang2803
/
Data-Structure-and-Algorithms-CO2003-
1
00
Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
Settings
Data-Structure-and-Algorithms-CO2003-/StacknQueue/isBipartite_DFS.cpp
@minhdang2803
minhdang2803 DSA 203 isBipartite using DFS
Latest commit 3e40a91 12 days ago
 History
 1 contributor
55 lines (51 sloc)  1.22 KB
  
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
  return 0;
}
