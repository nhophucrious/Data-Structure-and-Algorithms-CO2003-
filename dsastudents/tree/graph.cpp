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

////////////////
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
    return std::to_string(v);
}
void demo_1()
{
    UGraphModel<char> model(&vertexEQ, &vertex2str);
    char vertices[] = {A, B, C, D, F};
    Edge<char> edges[] = {
        Edge<char>(A, B, 100),
        Edge<char>(B, D, 200),
        Edge<char>(C, D, 400),
        Edge<char>(F, D, 500)};
    for (char v : vertices)
        model.add(v);
    for (Edge<char> e : edges)
        model.connect(e.from, e.to, e.weight);
    for (char v : vertices)
    {
        cout << v
             << ":" << model.inDegree(v)
             << "\t" << model.outDegree(v) << endl;
    }

    for (char v : vertices)
    {
        DLinkedList<char> inward = model.getInwardEdges(v);
        DLinkedList<char> outward = model.getOutwardEdges(v);
        cout << v << "\t" << inward.toString() << "\t" << outward.toString() << endl;
    }

    cout << model.weight(C, D) << endl;
    cout << ((model.connected(A, B)) ? "has a connection" : "no connection") << endl;

    model.remove(D);
    model.println();
}

IGraph<char> *create_graph_0()
{
    IGraph<char> *model = new DGraphModel<char>(&vertexEQ, &vertex2str);
    char vertices[] = {A, B, C, D, E, F, G, H};
    Edge<char> edges[] = {
        Edge<char>(A, B),
        Edge<char>(A, D),
        Edge<char>(B, D),
        Edge<char>(B, F),
        Edge<char>(C, D),
        Edge<char>(C, E),
        Edge<char>(D, F),
        Edge<char>(E, F),
        Edge<char>(F, H),
        Edge<char>(G, F),
        Edge<char>(G, H),
    };
    for (char v : vertices)
        model->add(v);
    for (Edge<char> e : edges)
        model->connect(e.from, e.to, e.weight);

    return model;
}

IGraph<char> *create_graph_1()
{
    char vertices[] = {'A', 'X', 'G', 'H', 'P', 'E', 'Y', 'M', 'J'};
    Edge<char> edges[] = {
        Edge<char>('A', 'X'),
        Edge<char>('X', 'G'),
        Edge<char>('X', 'H'),
        Edge<char>('G', 'H'),
        Edge<char>('G', 'P'),
        Edge<char>('H', 'P'),
        Edge<char>('H', 'E'),
        Edge<char>('E', 'M'),
        Edge<char>('E', 'Y'),
        Edge<char>('Y', 'M'),
        Edge<char>('M', 'J')};
    IGraph<char> *graph = new DGraphModel<char>(&vertexEQ, &vertex2str);
    for (char v : vertices)
        graph->add(v);
    for (Edge<char> edge : edges)
        graph->connect(edge.from, edge.to);
    return graph;
}

IGraph<char> *create_graph_2()
{
    char vertices[] = {S, A, B, C, D, E, F, T};
    Edge<char> edges[] = {
        Edge<char>(S, A, 2),
        Edge<char>(S, C, 4),
        Edge<char>(S, E, 1),
        Edge<char>(A, B, 5),
        Edge<char>(C, A, 2),
        Edge<char>(C, F, 3),
        Edge<char>(E, D, 2),
        Edge<char>(E, F, 3),
        Edge<char>(B, T, 3),
        Edge<char>(D, B, 5),
        Edge<char>(D, T, 2),
        Edge<char>(F, T, 1)};
    IGraph<char> *graph = new DGraphModel<char>(&vertexEQ, &vertex2str);
    for (char v : vertices)
        graph->add(v);
    for (Edge<char> edge : edges)
        graph->connect(edge.from, edge.to);
    return graph;
}

IGraph<char> *create_graph_3()
{
    char vertices[] = {A, B, C, D, E, F, G, H};
    Edge<char> edges[] = {
        Edge<char>(A, B),
        Edge<char>(A, D),
        Edge<char>(B, D),
        Edge<char>(B, F),
        Edge<char>(C, D),
        Edge<char>(C, E),
        Edge<char>(D, F),
        Edge<char>(E, F),
        Edge<char>(G, F),
        Edge<char>(G, H),
        Edge<char>(F, H)};
    IGraph<char> *graph = new DGraphModel<char>(&vertexEQ, &vertex2str);
    for (char v : vertices)
        graph->add(v);
    for (Edge<char> edge : edges)
        graph->connect(edge.from, edge.to);
    return graph;
}

IGraph<char> *create_graph_4()
{
    char vertices[] = {A, B, C, D, E, F, G, H, I, J, K};
    Edge<char> edges[] = {
        Edge<char>(B, A),
        Edge<char>(C, A),
        Edge<char>(D, A),
        Edge<char>(E, D),
        Edge<char>(F, D),
        Edge<char>(E, G),
        Edge<char>(F, G),
        Edge<char>(H, D),
        Edge<char>(I, D),
        Edge<char>(J, H),
        Edge<char>(J, I),
        Edge<char>(K, J)};
    IGraph<char> *graph = new DGraphModel<char>(&vertexEQ, &vertex2str);
    for (char v : vertices)
        graph->add(v);
    for (Edge<char> edge : edges)
        graph->connect(edge.from, edge.to);
    return graph;
}

//Why runtime error?
void demo_2()
{
    IGraph<char> *model = create_graph_0();
    cout << model->toString() << endl;

    DLinkedList<char> vertices = model->vertices();
    DLinkedList<char>::Iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        char v = *it;
        DLinkedList<char> inward = model->getInwardEdges(v);
        DLinkedList<char> outward = model->getOutwardEdges(v);
        cout << v << "\t" << inward.toString() << "\t" << outward.toString() << endl;
    }

    delete model;
}
//Why runtime error?
void demo_3()
{
    IGraph<char> *model = create_graph_1();
    cout << model->toString() << endl;

    DGraphModel<char> *dmodel = dynamic_cast<DGraphModel<char> *>(model);
    DGraphModel<char>::Iterator it;

    for (it = dmodel->begin(); it != dmodel->end(); it++)
    {
        char v = *it;
        DLinkedList<char> inward = dmodel->getInwardEdges(v);
        DLinkedList<char> outward = dmodel->getOutwardEdges(v);
        cout << v << "\t" << inward.toString() << "\t" << outward.toString() << endl;
    }

    delete model;
}

void demo_4()
{
    DGraphModel<char> model(&vertexEQ, &vertex2str);
    char vertices[] = {A, B, C, D, E, F, G, H};
    Edge<char> edges[] = {
        Edge<char>(A, B),
        Edge<char>(A, D),
        Edge<char>(B, D),
        Edge<char>(B, F),
        Edge<char>(C, D),
        Edge<char>(C, E),
        Edge<char>(D, F),
        Edge<char>(E, F),
        Edge<char>(F, H),
        Edge<char>(G, F),
        Edge<char>(G, H),
    };
    for (char v : vertices)
        model.add(v);
    for (Edge<char> e : edges)
        model.connect(e.from, e.to, e.weight);

    //
    DLinkedList<char> list = model.vertices();
    list.println();

    DGraphModel<char>::Iterator it;
    for (it = model.begin(); it != model.end(); it++)
    {
        cout << *it << endl;
    }
}

int hash_code(char &key, int size)
{
    return (int)key % size;
}

void dft(IGraph<char> *model, char start)
{
    DLinkedList<char> results;

    Stack<char> open; //contain nodes TO BE processed in future
    XHashMap<char, char> inopen(&hash_code);
    XHashMap<char, char> inclose(&hash_code); //contains vertices that have been processed

    open.push(start);
    inopen.put(start, start);

    while (!open.empty())
    {
        char vertex = open.pop();
        inopen.remove(vertex);
        //process
        results.add(vertex); //save it to results and then process later
        inclose.put(vertex, vertex);

        //generate children + push to open
        DLinkedListSE<char> children;
        children.copyFrom(model->getOutwardEdges(vertex));
        children.sort();
        DLinkedListSE<char>::Iterator it;
        for (it = children.begin(); it != children.end(); it++)
        {
            char child = *it;
            if (inclose.containsKey(child))
                continue;
            if (inopen.containsKey(child))
            {
                open.remove(child);
                open.push(child);
                continue;
            }

            open.push(child);
            inopen.put(child, child);
        }
    }

    //
    results.println();
}

void bft(IGraph<char> *model, char start)
{
    DLinkedList<char> results;

    Queue<char> open; //contain nodes TO BE processed in future
    XHashMap<char, char> inopen(&hash_code);
    XHashMap<char, char> inclose(&hash_code); //contains vertices that have been processed

    open.push(start);
    inopen.put(start, start);

    while (!open.empty())
    {
        char vertex = open.pop();
        inopen.remove(vertex);
        //process
        results.add(vertex); //save it to results and then process later
        inclose.put(vertex, vertex);

        //generate children + push to open
        DLinkedListSE<char> children;
        children.copyFrom(model->getOutwardEdges(vertex));
        children.sort();
        DLinkedListSE<char>::Iterator it;
        for (it = children.begin(); it != children.end(); it++)
        {
            char child = *it;
            if (inopen.containsKey(child))
                continue;
            if (inclose.containsKey(child))
                continue;

            open.push(child);
            inopen.put(child, child);
        }
    }

    //
    results.println();
}

void demo_dft()
{
    IGraph<char> *model = create_graph_1();
    dft(model, A);
    delete model;
}
void demo_bft()
{
    IGraph<char> *model = create_graph_4();
    bft(model, A);
    delete model;
}
int main(int arc, char **argv)
{
    demo_2();
    // demo_3();
    return 0;
}