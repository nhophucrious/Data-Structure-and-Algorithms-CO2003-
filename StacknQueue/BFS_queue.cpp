#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> graph, int start)
{
    // make an array to check which vertex is visited (hash)
    vector<bool> visited(graph.size(), false);
    // make a queue
    queue<int> q;
    // mark first vertex visited
    visited[start] = true;
    // push first vertex to a queue
    q.push(start);
    while (q.empty() == false)
    {
        // print the vertext in the queue (which we already visited) and pop it
        int value = q.front();
        cout << value << " ";
        q.pop();
        // traverse all the adjacency vertices of start vertext, if it already visited, continue to next adjacency
        //else mark it visited and push it to a queue
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
