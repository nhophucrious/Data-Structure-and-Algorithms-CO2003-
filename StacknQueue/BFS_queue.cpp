#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> graph, int start)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (q.empty() == false)
    {
        int value = q.front();
        cout << value << " ";
        q.pop();
        for (int i = 0; i < graph[value].size(); i++)
        {
            if (visited[graph[value][i]] == false)
            {
                int node = graph[value][i];
                visited[node] = true;
                q.push(node);
            }
        }
    }
}
int main()
{
    int init_graph[10][10] = { {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
                              {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
                              {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
                              {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                              {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                              {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
                              {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
                              {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                              {1, 0, 1, 0, 1, 0, 0, 0, 1, 0} };
    int n = 10;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (init_graph[i][j])
                graph[i].push_back(j);
        }
    }

    bfs(graph, 0);
}
