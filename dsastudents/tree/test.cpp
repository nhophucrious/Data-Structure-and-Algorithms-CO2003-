#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include "util/ArrayLib.h"
#include "sorting/DLinkedListSE.h"
#include "sorting/SLinkedListSE.h"
#include "sorting/XArrayListSE.h"
#include "tree/AVL.h"
#include "tree/BST.h"
#include "list/DLinkedList.h"
#include "geom/Vector3D.h"
#include "geom/Point3D.h"
#include "heap/Heap.h"
#include "stacknqueue/Queue.h"
#include "stacknqueue/Stack.h"
#include "graph/IGraph.h"
#include "graph/UGraphModel.h"
#include "graph/DGraphModel.h"
#include "graph/AbstractGraph.h"
#include "stacknqueue/PriorityQueue.h"
#include "hash/XHashMap.h"
using namespace std;

char A = 'A', B = 'B', C = 'C', D = 'D', E = 'E',
     F = 'F', G = 'G', H = 'H', I = 'I', J = 'J',
     K = 'K', L = 'L', M = 'M', N = 'N', O = 'O',
     P = 'P', Q = 'Q', R = 'R', S = 'S', T = 'T',
     U = 'U', V = 'V', X = 'X', Y = 'Y', Z = 'Z';

bool vertexEQ(char &a, char &b)
{
    return a == b;
}
bool comparator(char &lhs, char &rhs)
{
    return lhs == rhs;
}
string vertex2str(char &v)
{
    return std::to_string(v);
}
void demo()
{
    char vertices[] = {B, E, A, M, J};
    Edge<char> edges[] = {
        Edge<char>(B, A),
        Edge<char>(E, A),
        Edge<char>(A, M),
        Edge<char>(A, J)};
    DGraphModel<char> model(&comparator, &vertex2str);
    for (char v : vertices)
        model.add(v);
    for (Edge<char> e : edges)
        model.connect(e.from, e.to, e.weight);
    model.println();
}

void demo1()
{
    char vertices[] = {B, E, A, M, J};
    Edge<char> edges[] = {
        Edge<char>(B, A),
        Edge<char>(E, A),
        Edge<char>(A, M),
        Edge<char>(A, J)};
    DGraphModel<char> *model = DGraphModel<char>::create(vertices, 5, edges, 4, &vertexEQ, &vertex2str);
    model->println();
    delete model;
}

void demo2()
{
    char vertices[] = {B, E, A, M, J};
    Edge<char> edges[] = {
        Edge<char>(B, A),
        Edge<char>(E, A),
        Edge<char>(A, M),
        Edge<char>(A, J)};
    UGraphModel<char> *model = UGraphModel<char>::create(vertices, 5, edges, 4, &vertexEQ, &vertex2str);
    model->println();
    delete model;
}

int main(int arc, char **argv)
{
    demo();
    demo1();
    demo2();
    return 0;
}