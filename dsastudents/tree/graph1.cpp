#include <iostream>
#include <iomanip>
#include <string>
#include "geom/Vector3D.h"
#include "graph/IGraph.h"
#include "graph/UGraphModel.h"
#include "graph/DGraphModel.h"
#include "list/DLinkedList.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "stacknqueue/PriorityQueue.h"
#include "hash/XHashMap.h"
#include "sorting/DLinkedListSE.h"
using namespace std;
void create_graph(DGraphModel<char> &graph);
DGraphModel<char> reverse(DGraphModel<char> Graph);

/*
*    Need to do with graph
    1. create a graph
    2. print indegree, out degree
    3. print outwardEdge, inwardEdge
    4. reverse a graph
*/
char A = 'A', B = 'B', C = 'C', D = 'D', E = 'E',
     F = 'F', G = 'G', H = 'H', I = 'I', J = 'J',
     K = 'K', L = 'L', M = 'M', N = 'N', O = 'O',
     P = 'P', Q = 'Q', R = 'R', S = 'S', T = 'T',
     U = 'U', V = 'V', X = 'X', Y = 'Y', Z = 'Z';

bool vertexEQ(char &a, char &b)
{
    return a == b;
}

string vertex2str(char &v)
{
    stringstream os;
    os << v;
    return os.str();
}
DGraphModel<char> create_graph()
{
    DGraphModel<char> graph(&vertexEQ, &vertex2str);
    char vertices[] = {A, B, C, D, E};
    Edge<char> edges[] = {
        Edge<char>(A, C),
        Edge<char>(B, C),
        Edge<char>(C, D),
        Edge<char>(C, E),
    };
    for (char c : vertices)
    {
        graph.add(c);
    }
    for (Edge<char> c : edges)
    {
        graph.connect(c.from, c.to, c.weight);
    }
    return graph;
}
void getOutWard_Inward(DGraphModel<char> graph)
{
    DGraphModel<char>::Iterator it2 = graph.begin();
    for (; it2 != graph.end(); it2++)
    {
        char vertex = *it2;
        DLinkedList<char> out = graph.getOutwardEdges(vertex);
        DLinkedList<char> in = graph.getInwardEdges(vertex);   
        cout << "Vertex: " << vertex << endl;
        cout << "OutwardEdges: " << out.toString() << " ";
        cout << "InwardEdges: " << in.toString() << " ";
        cout << endl;
    }
}
void getInOutDeg(DGraphModel<char> graph)
{
    DGraphModel<char>::Iterator it = graph.begin();
    for (; it != graph.end(); it++)
    {
        char vertex = *it;
        cout << "Vertex: " << vertex << " InDegree: " << graph.inDegree(vertex)
             << " OutDegree: " << graph.outDegree(vertex) << endl;
    }
}
DGraphModel<char> reverse(DGraphModel<char> graph)
{
    DGraphModel<char> newGraph(&vertexEQ, &vertex2str);
    for (DGraphModel<char>::Iterator it = graph.begin(); it != graph.end(); it++)
    {
        newGraph.add(*it);
    }

    for (DGraphModel<char>::Iterator it2 = graph.begin(); it2 != graph.end(); it2++)
    {
        char to = *it2;
        DLinkedList<char> out = graph.getOutwardEdges(to);
        for (DLinkedList<char>::Iterator it3 = out.begin(); it3 != out.end(); it3++)
        {
            char from = *it3;
            newGraph.connect(from, to, graph.weight(to,from));
        }
    }
    return newGraph;
}
int main()
{
    //task 1: create a graph
    DGraphModel<char> graph = create_graph();
    graph.println();
    //task 2: print indegree, out degree;
    getInOutDeg(graph);
    //task 3: print outwardEdge, inwardEdge
    getOutWard_Inward(graph);
    //task 4: reverse graph
    cout << endl;
    DGraphModel<char> newGraph = reverse(graph);
    newGraph.println();
}
