/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "geom/Point3D.h"
#include "geom/Vector3D.h"

using namespace std;

template <class T>
struct Node
{
    template <class E>
    friend ostream &operator<<(ostream &os, const Node<E> &node);
    T data;
    Node<T> *next;

    Node<T>(int data, Node<T> *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

template <class E>
ostream &operator<<(ostream &os, const Node<E> &node)
{
    os << node.data << " ";
    return os;
}

//10, 12, 15, 4
/*
 head->(10)->(12)->(15)->(4)->NULL
 */
Node<int> *int_data()
{
    Node<int> *head;
    head = new Node<int>(4);        //(4)->NULL
    head = new Node<int>(15, head); //(15)->(4)->NULL
    head = new Node<int>(12, head); //(12)->(15)->(4)->NULL
    head = new Node<int>(10, head); //(10)->(12)->(15)->(4)->NULL
    //
    return head;
    // Node<int>* cursor = head;
    // while(cursor != NULL){
    //     cout << *cursor << ", "; //cursor->(10)
    //     cursor = cursor->next; ////cursor->(12)
    // }
    // cout << endl;
}
// void vector3d_data(){
//     Node<Vector3D> * head; //char
//     head = new Node<Vector3D>(Vector3D(1,2,4) );
//     head = new Node<Vector3D>(Vector3D(2,3,4), head);
//     head = new Node<Vector3D>(Vector3D(4,5,6), head);
//     head = new Node<Vector3D>(Vector3D(7,8,9), head);
//     //

//     Node<Vector3D>* cursor = head;
//     while(cursor != NULL){
//         cout << *cursor << ", ";
//         cursor = cursor->next;
//     }
//     cout << endl;
// }
string toString(Node<int> *head)
{
    if (head == NULL)
    {
        return "[]";
    }
    else
    {
        stringstream os;
        Node<int> *temp = head;
        os << "[";
        os << temp->data;
        temp = temp->next;
        while (temp != NULL)
        {
            os << " " << temp->data;
            temp = temp->next;
        }
        os << "]" << endl;
        return os.str();
    }
}

void print(Node<int>*head)
{
    cout << toString(head);
}
void remove(Node<int> *&head)
{
    Node<int> *temp;
    while (head != NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
    delete temp;
}

/*
 Homeworks:
 * 1/ working with ints:
 *   > use genIntArray from util/ArrayLib.h to generate N (ex: 10) items
 *   > create a chain from the generated ints
 *   > print chain with elegant format: without "," at the end
 *      >> for example: [10, 12, 15, 4]
 *   > delete chain
 * 
 * 2/ working with Point3D:
 *   > generate N points randomly, using API (generate) in geom/Point3D.h 
 *   > create a chain of generated points
 *   > println
 *   > delete chain
 * 
 * 3/ define class Rectangle in "geom", see samples: Point3D and Vector3D 
 *   > provide as many as operators and method for Rectangle
 * 
 * 4/ PointCloud:
 *      > Generate point3D, create a boundingbox based on point.x and y;
 *          boundingbox = smallest rectangle containing all points in the generated point cloud
 *          >> Print rectangle
 *      > Compute the center of the point cloud
 * 
 *  5/ Triangle:
 *    * Define class Triangle
 *      > add method getArea: return area of the triangle
 *          >> Area S(ABC) = 0.5 length-of(AB x AC)
 *              >> operator x: cross-product
 *    * Generate lot of triangle randomly, stored to chain or array
 *      > Compute the total area of all the triangles.
 * 
 *  6/Modify all the classes above: Point3D, Vector3D, Rectangle, Triangle, PointCloud
 *      to support coordinates of any data type: int, float, double
 *      (hint: use template)
 * 
 */
void Triangle()
{
    Point3D A = Point3D(0, 0, 0);
    Point3D B = Point3D(2, 0, 0);
    Point3D C = Point3D(0, 2, 0);

    cout << "The vertices of the triangle:" << endl;
    A.println(); B.println(); C.println();

    Vector3D AB = B - A;
    Vector3D AC = C - A;
    Vector3D cross = AB.cross(AC);
    float sABC = 0.5 * cross.length();
    cout << "sABC = " << fixed << setw(6) << setprecision(2) << sABC << endl;
}
int main(int argc, char **argv)
{
    Node<int> *head = int_data();
    // vector3d_data();
    print(head);
    remove(head);
    print(head);
    cout << endl;
    // Triangle();
    return 0;
}
