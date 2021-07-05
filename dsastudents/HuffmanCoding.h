#ifndef HUFFMANCODING_H
#define HUFFMANCODING_H
#include "hash/XHashMap.h"
#include "heap/Heap.h"
#include "string.h"

typedef unsigned char usc;
template <class T>
class Node
{
    public:
        T symbols;
        float frequency;
        Node<T> *left ,*right;
        Node(T symbols, float freq, Node<T> *left = NULL, Node<T> *right = NULL)
        {
            this->symbols = symbols;
            this->frequency = frequency;
            this->left = left;
            this->right = right;
        }
};

template<typename T>
int node_comparator(Node<T> *&a, Node<T> *&b)
{
    if(a->frequency < b->frequency)
        return -1;
    else if(a->frequency < b->frequency)
        return 1;
    else
        return 0;
}

template<typename T>
Node<T>* Huffman_Tree(T *symbols, float *freg, int size)
{
    Heap<Node<T> *> minHeap(&node_comparator, Heap<Node<T> *>::free());
    for (int i = 0; i < size; i++)
    {
        T symbol = symbols[i];
        float freq = freg[i];
        minHeap.push(new Node(symbol, freq, NULL, NULL));
    }

    while(heap.size>1)
    {
        Node<T> *left = minHeap.pop();
        Node<T> *right = minHeap.pop();
        minheap.push(new Node(left->symbols, left->frequency + right->frequency, left, right));
    }
    return minHeap.pop();
}

template <typename T> 
void gen_huffman_table(Node<T>* root, string bits, XHashMap<T,string> &map)
{
    if(root->left == NULL && root->right == NULL)
    {
        map.put(root->symbols, bits);
    }
    else
    {
        string left_path = bits;
        left_path.push_back('0');
        string right_path = bits;
        right_path.push_back('1');
        gen_huffman_table(root->left, left_path, map);
        gen_huffman_table(root->right, right_path, map);
    }
}

void generate_table(Node<usc>* root, string bits, string *map)
{
    if(root->left == NULL && root->right == NULL)
    {
        map[root->symbols] = bits;
    }
    else
    {
        string left_path = bits;
        left_path.push_back('0');
        string right_path = bits;
        right_path.push_back('1');
        generate_table(root->left, left_path, map);
        generate_table(root->right, right_path, map);
    }
}
float averaged_nbits(string * const huffman_table, float* freqs, int size){
    //YOUR CODE HERE
    int all = 0;
    for(int i = 0; i < size; i++)
    {
        all+= freqs[i];
    }
    float averageBit = 0;
    for(int i = 0; i < size; i++)
    {
        averageBit+=((freqs[i]/all)*huffman_table[symbols[i]].length());
    }
    return averageBit;
}
#endif HUFFMANCODING_H