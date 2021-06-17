#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//BFS method
  bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);                   //0->uncolored;1,-1 are the two colors used
        for(int i=0;i<n;i++)
        {
            if(color[i]!=0)continue;            //If the node is already colored continue to the next node
            color[i]=1;                         //If not colored we color it with 1
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int t=q.front();
                q.pop();
                for(auto &x:graph[t])          //Exploring its neighbors
                {
                    if(color[x]==0)
                    {
                        color[x]=-color[t];      //Making the neighbor have the opposite coloe
                        q.push(x);
                    }
                    else if(color[x]==color[t])return false;           //If we reach a condition where the neighbor and the node have the same color the graph osnt bipartite
                }
            }
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
