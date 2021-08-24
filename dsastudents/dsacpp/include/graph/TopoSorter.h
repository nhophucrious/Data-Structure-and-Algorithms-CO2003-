/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TopoSorter.h
 * Author: ltsach
 *
 * Created on July 11, 2021, 10:21 PM
 */

#ifndef TOPOSORTER_H
#define TOPOSORTER_H
#include "graph/DGraphModel.h"

template<class T>
class TopoSorter{
public:
    static int DFS;
    static int BFS; 
    
protected:
    DGraphModel<T>* graph;
    int (*hash_code)(T&, int);
    
public:
    TopoSorter(DGraphModel<T>* graph, int (*hash_code)(T&, int) = &XHashMap<char,int>::simpleHash){
        this->graph = graph;
        this->hash_code = hash_code;
    }   
    DLinkedList<T> sort(int mode=0){
        if(mode == DFS) return dfsSort();
        else return bfsSort();
    }
    DLinkedList<T> bfsSort(){
        DLinkedList<T> topoOrder;
        //YOUR CODE HERE
        XHashMap<T, int> indegreeMap = vertex2inDegree();
        DLinkedListSE<T> list;
        list.copyFrom(listOfZeroInDegrees());
        list.sort();
        Queue<T> open;
        for (typename DLinkedListSE<T>::Iterator it = list.begin(); it != list.end(); it++)
        {
            open.push(*it);
        }
        while (open.empty() == false)
        {
            T vertex = open.pop();
            topoOrder.add(vertex);
            // DLinkedList<T> outWard = this->graph->getInwardEdges(vertex);
            DLinkedListSE<T> children;
            children.copyFrom(this->graph->getOutwardEdges(vertex));
            children.sort();
            for (typename DLinkedListSE<T>::Iterator it = children.begin(); it != children.end(); it++)
            {
                T child = *it;
                if (open.contains(child) == true)
                    continue;
                if (topoOrder.contains(child) == true)
                    continue;

                int newIndegree = indegreeMap.get(child) - 1;
                indegreeMap.put(child, newIndegree);
                if (newIndegree == 0)
                    open.push(child);
            }
        }
        return topoOrder;
    }
    
    DLinkedList<T> dfsSort(){
        DLinkedList<T> topoOrder;
        //YOUR CODE HERE
        XHashMap<T, int> outDegreeMap = vertex2outDegree(); // get out degree
        DLinkedListSE<T> list;
        list.copyFrom(listOfZeroInDegrees()); // get all zero indegree
        list.sort();

        Stack<T> open;
        for (typename DLinkedListSE<T>::Iterator it = list.begin(); it != list.end(); it++)
        {
            open.push(*it); // push the zero degree into stack with alphabet order
        }
        while (open.empty() == false)
        {
            T vertex = open.peek(); // get the top
            int outDegree = outDegreeMap.get(vertex); // check outdegree
            if (outDegree == 0) 
            {
                open.pop(); // if outdegree = 0 -> pop and addfirst  to the result
                topoOrder.add(0, vertex);
            }
            else
            {   //if the outwardEdge is not zero
                DLinkedListSE<T> children;
                children.copyFrom(this->graph->getOutwardEdges(vertex)); // get outward edge;
                children.sort();
                for (typename DLinkedListSE<T>::Iterator it = children.begin(); it != children.end(); it++)
                {
                    T child = *it;
                    if (open.contains(child))
                    {
                        open.remove(child);
                        open.push(child);
                    }
                    if (open.contains(child) == false && topoOrder.contains(child) == false)
                    {
                        open.push(child);
                    }
                    outDegreeMap.put(vertex, outDegree - 1);
                }
            }
        }
        return topoOrder;
    }
protected:
    XHashMap<T, int> vertex2inDegree(){
        XHashMap<T, int> map(this->hash_code);
        typename AbstractGraph<T>::Iterator vertexIt = this->graph->begin();
        while(vertexIt != this->graph->end()){
            T vertex = *vertexIt;
            int inDegree = this->graph->inDegree(vertex);
            map.put(vertex, inDegree);
            
            vertexIt++;
        }
        return map;
    }
    XHashMap<T, int> vertex2outDegree(){
        XHashMap<T, int> map(this->hash_code);
        typename AbstractGraph<T>::Iterator vertexIt = this->graph->begin();
        while(vertexIt != this->graph->end()){
            T vertex = *vertexIt;
            int outDegree = this->graph->outDegree(vertex);
            map.put(vertex, outDegree);
            
            vertexIt++;
        }
        return map;
    }
    
    DLinkedListSE<T> listOfZeroInDegrees(){
        DLinkedListSE<T> list;
        typename AbstractGraph<T>::Iterator vertexIt = this->graph->begin();
        while(vertexIt != this->graph->end()){
            T vertex = *vertexIt;
            int inDegree = this->graph->inDegree(vertex);
            if(inDegree == 0) list.add(vertex);
            
            vertexIt++;
        }
        return list;
    }
}; //TopoSorter
template<class T>
int TopoSorter<T>::DFS = 0;
template<class T>
int TopoSorter<T>::BFS = 1;

/////////////////////////////End of TopoSorter//////////////////////////////////


#endif /* TOPOSORTER_H */

