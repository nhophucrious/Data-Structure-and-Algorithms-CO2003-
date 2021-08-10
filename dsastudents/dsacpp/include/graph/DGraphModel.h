/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DGraphModel.h
 * Author: LTSACH
 *
 * Created on 23 August 2020, 19:36
 */

#ifndef DGRAPHMODEL_H
#define DGRAPHMODEL_H
#include "graph/AbstractGraph.h"
#include "stacknqueue/Queue.h"
#include "stacknqueue/Stack.h"
#include "hash/XHashMap.h"
#include "stacknqueue/PriorityQueue.h"
#include "sorting/DLinkedListSE.h"

//////////////////////////////////////////////////////////////////////
///////////// GraphModel: Directed Graph Model    ////////////////////
//////////////////////////////////////////////////////////////////////

template <class T>
class DGraphModel : public AbstractGraph<T>
{
private:
public:
    DGraphModel(
        bool (*vertexEQ)(T &, T &),
        string (*vertex2str)(T &)) : AbstractGraph<T>(vertexEQ, vertex2str)
    {
    }

    void connect(T from, T to, float weight = 0)
    {
        //YOUR CODE HERE
        typename AbstractGraph<T>::VertexNode *NodeF = this->getVertexNode(from);
        if (NodeF == NULL)
            throw VertexNotFoundException(this->vertex2Str(*NodeF));
        typename AbstractGraph<T>::VertexNode *NodeT = this->getVertexNode(to);
        if (NodeT == NULL)
            throw VertexNotFoundException(this->vertex2Str(*NodeT));
        NodeF->connect(NodeT, weight);
    }
    void disconnect(T from, T to)
    {
        //YOUR CODE HERE
        typename AbstractGraph<T>::VertexNode *NodeF = this->getVertexNode(from);
        typename AbstractGraph<T>::VertexNode *NodeT = this->getVertexNode(to);
        if (NodeF == NULL)
            throw VertexNotFoundException(this->vertex2Str(*NodeF));
        if (NodeT == NULL)
            throw VertexNotFoundException(this->vertex2Str(*NodeT));
        typename AbstractGraph<T>::Edge *newEdge = NodeF->getEdge(NodeT);
        if (newEdge == NULL)
            throw EdgeNotFoundException(this->edge2Str(*newEdge));
        NodeF->removeTo(NodeT);
    }
    void remove(T vertex)
    {
        //YOUR CODE HERE
        typename AbstractGraph<T>::VertexNode *NodeF = this->getVertexNode(vertex);
        if (NodeF == NULL)
            throw VertexNotFoundException(this->vertex2Str(*NodeF));
        typename DLinkedList<typename AbstractGraph<T>::VertexNode *>::Iterator it = this->nodeList.begin();
        while (it != this->nodeList.end())
        {
            typename AbstractGraph<T>::VertexNode *NodeT = *it;
            typename AbstractGraph<T>::Edge *newEdge = NodeF->getEdge(NodeT);
            if (newEdge != NULL)
                NodeF->removeTo(NodeT);
            newEdge = NodeT->getEdge(NodeF);
            if (newEdge != NULL)
                NodeT->removeTo(NodeF);
            it++;
        }
        this->nodeList.removeItem(NodeF);
    }
    
    static DGraphModel<T>* create(T* Vertices, int nvertices, Edge<T>* edges, int nedges,
                                bool (*vertexEQ)(T&,T&),
                                string (*vertex2str)(T&))
    {
        DGraphModel<T> *model = new DGraphModel<T>(vertexEQ, vertex2str);
        for (int i = 0; i < nvertices; i++)
        {
            model->add(Vertices[i]);
        }
        for (int i = 0; i < nedges; i++)
        {
            model->connect(edges[i].from, edges[i].to, edges[i].weight);
        }
        return model;
    }
};

#endif /* DGRAPHMODEL_H */
