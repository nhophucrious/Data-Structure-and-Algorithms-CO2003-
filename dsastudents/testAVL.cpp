#include <iostream>
#include <iomanip>
#include "list/XArrayList.h"
#include "util/FileIOLib.h"
#include "geom/Point3D.h"
#include "geom/Vector3D.h"
#include "list/DLinkedList.h"
using namespace std;

/* 2 points */
XArrayList<Point3D> make_grid(float xmin, float xmax, float ymin, float ymax, int nitems=100){
    //YOUR CODE HERE
   XArrayList<Point3D> point;
    float deltaX = (xmax - xmin)/nitems;
    float deltaY = (ymax - ymin)/nitems ;
    for(int i = 0; i < nitems; i++)
    {
        for (int j = 0; j < nitems; j++)
        {
            point.add(Point3D(xmin + j * deltaX, ymin + i*deltaY, 0));
        }
    }
  return point;
}

/* 1 points */
XArrayList<Point3D> make_parabol(XArrayList<Point3D> xy){
    //YOUR CODE HERE
  XArrayList<Point3D> parabol;
    XArrayList<Point3D>::Iterator it = xy.begin();
    for (; it != xy.end(); it++)
    {
        Point3D point = *it;
        float z = pow(point.getX(), 2) + pow(point.getY(), 2);
        parabol.add( Point3D(point.getX(),point.getY(),z));
    }
    return parabol;
}

/* 2 points */
float distBetween(Point3D &center, Point3D& inputt)
{
    float a = inputt.getX() - center.getX();
    float b = inputt.getY() - center.getY();
    float c = inputt.getZ() - center.getZ();
    return (float)sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2));
}
void bbox(XArrayList<Point3D>& points, Point3D& lt, Point3D& rb){
    //YOUR CODE HERE
    XArrayList<float> x;
    XArrayList<float> y;
    float xmin = 99999;
    float xmax = -1;
    float ymin = 99999;
    float ymax = -1;
    for (XArrayList<Point3D>::Iterator it = points.begin(); it != points.end(); it++)
    {
        Point3D p = *it;
        x.add(p.getX());
        y.add(p.getY());
    }
    for(XArrayList<float>::Iterator it = x.begin(); it != x.end();it++)
    {
        float p = *it;
        if (xmax < p)
        {
            xmax = p;
        }
        if(xmin > p)
        {
            xmin = p;
        }
    }
    for(XArrayList<float>::Iterator it = y.begin(); it != y.end();it++)
    {
        float p = *it;
        if (ymax < p)
        {
            ymax = p;
        }
        if(ymin >p)
        {
            ymin = p;
        }
    }
    Point3D lefttop(xmin, ymax);
    Point3D rihtbottom(xmax, ymin);
    lt = lefttop;
    rb = rihtbottom;
}


/////////////////////////////////////////////////////////////////////////////////
// DO NOT CHANGE THE CODE FOLLOWING
/////////////////////////////////////////////////////////////////////////////////

XArrayList<Point3D> gen_points(int size = 100){
    XArrayList<Point3D> points;
    //Point3D *ptr = Point3D::genPoints(size, 5, 20, true, 2021);
    float mu[] = {2.0f, 2.0f, 0.0f};
    float sigma[] = {2.0f, 1.0f, 0.0f};
    Point3D *ptr = Point3D::genPointsNormal(size, mu, sigma, true, 2021);
    for(int idx=0; idx < size; idx++) points.add(ptr[idx]);

    delete []ptr;
    return points;
}

void store_bb(XArrayList<Point3D> points, string filename){
    Point3D lt, rb;
    bbox(points, lt, rb);
    //
    vector<string> x_vec, y_vec;
    XArrayList<Point3D>::Iterator it;
    for(it=points.begin(); it != points.end(); it++){
        Point3D point = *it;
        stringstream xos, yos;
        xos << fixed << setw(8) << setprecision(4) << point.getX();
        yos << fixed << setw(8) << setprecision(4) << point.getY();
        x_vec.push_back(xos.str());
        y_vec.push_back(yos.str());
    }
    
    vector<string> ltx_vec, lty_vec, rbx_vec, rby_vec;
    stringstream ltxos, ltyos, rbxos, rbyos;
    ltxos  << fixed << setw(8) << setprecision(4) << lt.getX();
    ltyos  << fixed << setw(8) << setprecision(4) << lt.getY();
    rbxos  << fixed << setw(8) << setprecision(4) << rb.getX();
    rbyos  << fixed << setw(8) << setprecision(4) << rb.getY();
    ltx_vec.push_back(ltxos.str());
    lty_vec.push_back(ltyos.str());
    rbx_vec.push_back(rbxos.str());
    rby_vec.push_back(rbyos.str());
    DataFrame df;
    df.add("x", x_vec);
    df.add("y", y_vec);
    df.add("lt.x", ltx_vec);
    df.add("lt.y", lty_vec);
    df.add("rb.x", rbx_vec);
    df.add("rb.y", rby_vec);
    
    df.write(filename, ';');
}

void store_points(XArrayList<Point3D> points, string filename){
    vector<string> x_vec, y_vec, z_vec;
    XArrayList<Point3D>::Iterator it;
    for(it=points.begin(); it != points.end(); it++){
        Point3D point = *it;
        stringstream xos, yos, zos;
        xos << fixed << setw(8) << setprecision(4) << point.getX();
        yos << fixed << setw(8) << setprecision(4) << point.getY();
        zos << fixed << setw(8) << setprecision(4) << point.getZ();
        x_vec.push_back(xos.str());
        y_vec.push_back(yos.str());
        z_vec.push_back(zos.str());
    }
    DataFrame df;
    df.add("x", x_vec);
    df.add("y", y_vec);
    df.add("z", z_vec);
    df.write(filename);
}

int main(int argc, char **argv){
    XArrayList<Point3D> grid = make_grid(-5, 5, -5, 5, 10);
    XArrayList<Point3D> grid2 = make_grid(-5, 5, -5, 5, 100);
    XArrayList<Point3D> parabol = make_parabol(grid2);

    XArrayList<Point3D> points = gen_points(200);

    store_points(grid, "grid.csv");
    store_points(parabol, "parabol.csv");
    store_bb(points, "bbox.csv");

    return 0;
}