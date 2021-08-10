/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UGraphModel.h
 * Author: LTSACH
 *
 * Created on 24 August 2020, 15:16
 */

#ifndef UGRAPHMODEL_H
#define UGRAPHMODEL_H

#include "graph/AbstractGraph.h"
#include "stacknqueue/PriorityQueue.h"

//////////////////////////////////////////////////////////////////////
///////////// UGraphModel: Undirected Graph Model ////////////////////
//////////////////////////////////////////////////////////////////////

template <class T>
class UGraphModel : public AbstractGraph<T>
{
private:
public:
    //class UGraphAlgorithm;
    //friend class UGraphAlgorithm;

    UGraphModel(
        bool (*vertexEQ)(T &, T &),
        string (*vertex2str)(T &)) : AbstractGraph<T>(vertexEQ, vertex2str)
    {
    }

    void connect(T from, T to, float weight = 0)
    {
        //YOUR CODE HERE
        typename AbstractGraph<T>::VertexNode *NodeF = this->getVertexNode(from);
        typename AbstractGraph<T>::VertexNode *NodeT = this->getVertexNode(to);
        if (NodeF == NULL)
            throw VertexNotFoundException(this->vertex2Str(*NodeF));
        if (NodeT == NULL)
            throw VertexNotFoundException(this->vertex2Str(*NodeT));

        if (NodeF->equals(NodeT))
        {
            NodeF->connect(NodeT, weight);
        }
        else
        {
            NodeF->connect(NodeT, weight);
            NodeT->connect(NodeF, weight);
        }
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

        if (NodeF->equals(NodeT))
        {
            NodeF->removeTo(NodeT);
        }
        else
        {
            NodeF->removeTo(NodeT);
            NodeT->removeTo(NodeF);
        }
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
            {
                NodeF->removeTo(NodeT);
                NodeT->removeTo(NodeF);
            }
            it++;
        }
        this->nodeList.removeItem(NodeF);
    }
    static UGraphModel<T>* create(T* Vertices, int nvertices, Edge<T>* edges, int nedges,
                                bool (*vertexEQ)(T&,T&),
                                string (*vertex2str)(T&))
    {
        UGraphModel<T> *model = new UGraphModel<T>(vertexEQ, vertex2str);
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

#endif /* UGRAPHMODEL_H */
