#include <iostream>

#include "Forel.h"

using namespace std;

ObjCoordVector source_vector{ObjCoord(1,2), ObjCoord(1,3), ObjCoord(4,7),ObjCoord(5,8),
                             ObjCoord(8,0),ObjCoord(6,1),ObjCoord(7,2),ObjCoord(7,7)};
ObjCoordVector cluster_centr;
ClusteringMarkList clustering_mark_list;
double radius{3.0};

int main()
{
    Forel::forel_clustering(source_vector, cluster_centr, radius);
    cout << "Hello World!" << endl;
    return 0;
}
