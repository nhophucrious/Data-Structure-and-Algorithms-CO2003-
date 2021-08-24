#include <iostream>
#include <iomanip>
#include "util/ArrayLib.h"
#include "util/FileIOLib.h"
#include "util/FuncLib.h"
#include "geom/Point3D.h"
#include "geom/Vector3D.h"
#include "util/dsaheader.h"
using namespace std;
/*
 map = function: single-valued function
 * given value x = KEY
 * return value y = VALUE (after some kind of processing)

 * single-valued function
 * multiple-valued function
 
 * (key1, value1)
 * (key1, value2) => replace value1 by value2
*/
///////////////////////////////////////////////////////////////
float func1(float x/*,float* coef*/){
    return 1;
}
float func2(float x/*,float* coef*/){
    return 2;
}
float func3(float x/*,float* coef*/){
    return 3;
}
/*
 * function name => function pointer
 * call function with the function pointer
 * return value
*/
float get_value(string funcname, float x){
    XHashMap<string, float (*)(float/*,float* */)> map(&hash_murmur); 
    map.put("func1", &func1);
    map.put("func2", &func2);
    map.put("func3", &func3);

    float (*func)(float /*, float* */);
    func = map.get(funcname);
    return func(x);
}
///////////////////////////////////////////////////////////////////////
/*
 * input: picture of graph
  require: 
 * (1) build the graph
 * (2) show something
 * for example:
 *    vertex   inDegree  outDegree
 *      B          1         2
 *      C          0         3
 * ...
*/
DGraphModel<char>* reverseGraph(DGraphModel<char>& graph);
bool vertexEqual(char&a, char&b){
    return a == b;
}
string vertex2string(char& vertex){
    return std::to_string(vertex);
}
int hashcode(char& key, int size){
    return int(key)%size;
}

void demo(){
    DGraphModel<char> graph(&vertexEqual, &vertex2string);
    char vertices[]={'B','E','A','M','J'};
    for (char v: vertices) graph.add(v);
    graph.connect('B','A');
    graph.connect('E','A');
    graph.connect('A','M');
    graph.connect('A','J');
    // graph.println();
    // DGraphModel<char>::Iterator it ;
    // for (it=graph.begin(); it!=graph.end(); it++){
    //     cout<<*it<<setw(8)<<graph.inDegree(*it)<<setw(8)<<graph.outDegree(*it)<<endl;
    // }
    TopoSorter<char> sorter(&graph, &hashcode);
    DLinkedList<char> dfs = sorter.sort(TopoSorter<char>::DFS);
    DLinkedList<char>::Iterator it;
    for(it=dfs.begin(); it!=dfs.end();it++){
        cout<<*it<<setw(8)<<graph.inDegree(*it)<<setw(8)<<graph.outDegree(*it)<<endl;
    }

    DGraphModel<char>* new_graph = reverseGraph(graph);
    new_graph->println();
    delete new_graph;
}

DGraphModel<char>* reverseGraph(DGraphModel<char>& graph){
    DGraphModel<char>* new_graph = new DGraphModel<char>( &vertexEqual, &vertex2string);
    DLinkedList<char> vertices = graph.vertices();
    DLinkedList<char>::Iterator it;
    for(it=vertices.begin(); it!=vertices.end();it++){
        new_graph->add(*it);
    }
    for(it=vertices.begin(); it!=vertices.end();it++){
        char from =*it;
        DLinkedList<char> list = graph.getOutwardEdges(*it);
        DLinkedList<char>::Iterator it2;
        for(it2=list.begin(); it2!=list.end();it2++){
            char to = *it2;
            new_graph->connect(to, from);
        }
    }
    return new_graph;
}
//////////////////////////////////////////////////////////////////////
int main(int arc, char**argc){
    string names[]={"func1", "func2", "func3"};
    for(string fname:names)
    {
        cout<<fname<<": "<<get_value(fname, 0.5)<<endl;
    }
    cout<<"==========================================="<<endl;
    demo();
    return 0;
}