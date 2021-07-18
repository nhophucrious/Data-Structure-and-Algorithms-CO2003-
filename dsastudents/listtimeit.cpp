%%writefile shape.cpp
#include <iostream>
#include <iomanip>
#include "list/XArrayList.h"
#include "sorting/XArrayListSE.h"
#include "util/FileIOLib.h"
#include "geom/Point3D.h"
#include "geom/Vector3D.h"
#include "list/DLinkedList.h"
#include "tree/AVL.h"
#include <cmath>
using namespace std;

/*Point: 2*/
XArrayList<Point3D> linspace(Point3D start, Point3D stop, int num = 100)
{
    XArrayList<Point3D> points;
    float x = (stop.getX() - start.getX()) / num;
    float y = (stop.getY() - start.getY()) / num;
    float z = (stop.getZ() - start.getZ()) / num;
    for (int i = 0; i < num; i++)
    {
        float X = i * x;
        float Y = i * y;
        float Z = i * z;
        points.add(Point3D (start.getX() + X, start.getY() + Y, start.getZ() + Z));
    }
    //YOUR CODE HERE
    return points;
}

/*Point: 1*/
Point3D center(XArrayList<Point3D> &points)
{
    //YOUR CODE HERE
    int count = 0;
    float sumX = 0, sumY = 0, sumZ = 0;
    XArrayList<Point3D>::Iterator it;
    for (it = points.begin(); it != points.end(); it++)
    {
        Point3D vec = *it;
        sumX += vec.getX();
        sumY += vec.getY();
        sumZ += vec.getZ();
        count++;
    }
    return Point3D(sumX / count, sumY / count, sumZ / count);
}
/*Point: 2*/
float distBetween(Point3D &center, Point3D& inputt)
{
    float X = center.getX();
    float Y = center.getY();
    float Z = center.getZ();
    float x = inputt.getX();
    float y = inputt.getY();
    float z = inputt.getZ();
    return (float)sqrt(pow(x - X, 2) + pow(y - Y, 2) + pow(z - Z, 2));
}

int comparator(float &dist1 , float &dist2)
{
    if(dist1 < dist2)
        return -1;
    else if(dist1 == dist2)
        return 1;
    else
        return 0;
}
void percentile(XArrayList<Point3D> &points, Point3D &center_, float &radius, float p = 0.75)
{
    //YOUR CODE HERE
    //task 1:
    center_ = center(points);
    //Task 2:
    XArrayList<Point3D>::Iterator it;
    XArrayListSE<float> distance;
    for (it = points.begin(); it != points.end(); it++)
    {
        float dist = distBetween(center_, *it);
        distance.add(dist);
    }
    distance.sort(&comparator);
    radius = distance.get(p*distance.size());
    return;
}

/*Point: 2*/
XArrayList<Point3D> make_helix(float radius, int nsamples = 100, float dz = 0.1, int npoints = 500)
{
    XArrayList<Point3D> points;
    //YOUR CODE HERE
    float delta = 2 * M_PI / nsamples;
    for (int i = 1; i <= npoints; i++)
    {
        points.add(Point3D(radius * cos(delta * i), radius * sin(delta * i), dz * i));
    }
    return points;
}

/////////////////////////////////////////////////////////////////////////////////
// DO NOT CHANGE THE CODE FOLLOWING

XArrayList<Point3D> gen_points(int size = 100)
{
    XArrayList<Point3D> points;
    //Point3D *ptr = Point3D::genPoints(size, 5, 20, true, 2021);
    float mu[] = {2.0f, 2.0f, 0.0f};
    float sigma[] = {2.0f, 1.0f, 0.0f};
    Point3D *ptr = Point3D::genPointsNormal(size, mu, sigma, true, 2021);
    for (int idx = 0; idx < size; idx++)
        points.add(ptr[idx]);

    delete[] ptr;
    return points;
}

void store_points(XArrayList<Point3D> points, string filename)
{
    vector<string> x_vec, y_vec, z_vec;
    XArrayList<Point3D>::Iterator it;
    for (it = points.begin(); it != points.end(); it++)
    {
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

void store_percentile(XArrayList<Point3D> points, string filename)
{
    Point3D center;
    float radius;
    percentile(points, center, radius);
    //
    vector<string> x_vec, y_vec;
    XArrayList<Point3D>::Iterator it;
    for (it = points.begin(); it != points.end(); it++)
    {
        Point3D point = *it;
        stringstream xos, yos;
        xos << fixed << setw(8) << setprecision(4) << point.getX();
        yos << fixed << setw(8) << setprecision(4) << point.getY();
        x_vec.push_back(xos.str());
        y_vec.push_back(yos.str());
    }

    vector<string> cx_vec, cy_vec, radius_vec;
    stringstream cxos, cyos, radiusos;
    cxos << fixed << setw(8) << setprecision(4) << center.getX();
    cyos << fixed << setw(8) << setprecision(4) << center.getY();
    radiusos << fixed << setw(8) << setprecision(4) << radius;
    cx_vec.push_back(cxos.str());
    cy_vec.push_back(cyos.str());
    radius_vec.push_back(radiusos.str());

    DataFrame df;
    df.add("x", x_vec);
    df.add("y", y_vec);
    df.add("center.x", cx_vec);
    df.add("center.y", cy_vec);
    df.add("radius", radius_vec);

    df.write(filename, ';');
}

int main(int argc, char **argv)
{
    XArrayList<Point3D> helix = make_helix(2.0f, 100, 0.1f, 500);
    store_points(helix, "helix.csv");

    XArrayList<Point3D> line = linspace(Point3D(0, 0, 0), Point3D(10, 10, 10), 10);
    store_points(line, "line.csv");

    XArrayList<Point3D> points = gen_points(200);
    store_percentile(points, "percentile.csv");

    return 0;
}