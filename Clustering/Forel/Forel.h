#ifndef FOREL_H
#define FOREL_H

#include <utility>
#include <list>
#include <vector>
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <algorithm>

using ObjCoord = std::pair<double, double>;
using ObjCoordVector = std::vector<ObjCoord>;
using ObjCoordList = std::list<ObjCoord>;

class Forel
{
public:
    Forel() = delete;
    ~Forel() = delete;

    static void forel_clustering(const ObjCoordVector &source_obj_vector, ObjCoordVector &cluster_centr, double &cluster_radius);

private:
    static void fill_clustering_mark_list(const ObjCoordVector &source_obj_vector, ObjCoordList &not_clustering_obj);
    static bool check_distance(ObjCoord current_obj, ObjCoord checking_obj, double &cluster_radius);

    static bool clusterisation_not_finished(const ObjCoordList &not_clustering_obj);
    static ObjCoord get_random_object(const ObjCoordList &not_clustering_obj);
    static ObjCoordList get_neighbour_objects(ObjCoord current_obj, const ObjCoordList &not_clustering_obj, double &cluster_radius);
    static ObjCoord center_of_objects(const ObjCoordList &neighbour_objs);
    static void delete_objects(const ObjCoordList &neighbour_objects, ObjCoordList &not_clustering_obj);

};
/*
#define R 30 //ширина поиска локальных сгущений - входной параметр алгоритма
clusterisation_not_finished(); //все ли объекты кластеризованы
get_random_object(); //возвращает произвольный некластеризованный объект
get_neighbour_objects(type *object); //возвращает массив объектов, расположенных на расстоянии <= R от текущего
center_of_objects(type *mass_of_objects); //возвращает центр тяжести указанных объектов
delete_objects(type *mass_of_objects); //удаляет указанные объекты из выборки (мы их уже кластеризовали)

while(clusterisation_not_finished())
{
   current_object = get_random_object();
   neighbour_objects = get_neighbour_objects(current_object);
   center_object = center_of_objects(neighbour_objects);

   while (center_object != current_object)  //пока центр тяжести не стабилизируется
   {
      current_object = center_object;
      neighbour_objects = get_neighbour_objects(current_object);
      center_object = center_of_objects(neighbour_objects);
   }
   delete_objects(neighbour_objects);
}
*/
#endif // FOREL_H
