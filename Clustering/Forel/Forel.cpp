#include "Forel.h"

void Forel::forel_clustering(const ObjCoordVector &source_obj_vector, ObjCoordVector &cluster_centr, double &cluster_radius)
{
    cluster_centr.clear();
    ObjCoordList not_clustering_obj;
    fill_clustering_mark_list(source_obj_vector, not_clustering_obj);

    ObjCoord current_object, center_object;
    ObjCoordList neighbour_objects;

    while (clusterisation_not_finished(not_clustering_obj)) {
        current_object = get_random_object(not_clustering_obj);
        neighbour_objects = get_neighbour_objects(current_object, not_clustering_obj, cluster_radius);
        center_object = center_of_objects(neighbour_objects);
        while (center_object != current_object) {
            current_object = center_object;
            neighbour_objects = get_neighbour_objects(current_object, not_clustering_obj, cluster_radius);
            center_object = center_of_objects(neighbour_objects);
        }
        cluster_centr.push_back(center_object);
        delete_objects(neighbour_objects, not_clustering_obj);
    }
}

void Forel::fill_clustering_mark_list(const ObjCoordVector &source_obj_vector, ObjCoordList &not_clustering_obj)
{
    for (auto source_obj : source_obj_vector) {
        not_clustering_obj.push_back(source_obj);
    }
}

bool Forel::check_distance(ObjCoord current_obj, ObjCoord checking_obj, double &cluster_radius)
{
    double delta_x = fabs(current_obj.first - checking_obj.first);
    double delta_y = fabs(current_obj.second - checking_obj.second);
    double distance = sqrt(pow(delta_x,2) + pow(delta_y,2));
    if(distance > cluster_radius)
        return false;
    else
        return true;
}

bool Forel::clusterisation_not_finished(const ObjCoordList &not_clustering_obj)
{
    return !not_clustering_obj.empty();
}

ObjCoord Forel::get_random_object(const ObjCoordList &not_clustering_obj)
{
    auto list_size = not_clustering_obj.size();
    srand(time(NULL));
    auto rnd_index = rand()%list_size;
    auto it = not_clustering_obj.begin();
    for(auto i = 0; i < rnd_index; ++it, ++i){}
    return std::move(*it);
}

ObjCoordList Forel::get_neighbour_objects(ObjCoord current_obj, const ObjCoordList &not_clustering_obj, double &cluster_radius)
{
    ObjCoordList result_list;
    for (auto checking_obj: not_clustering_obj) {
        if(check_distance(current_obj, checking_obj, cluster_radius))
            result_list.push_back(checking_obj);
    }
    return std::move(result_list);
}

ObjCoord Forel::center_of_objects(const ObjCoordList &neighbour_objs)
{
    ObjCoord centr;
    size_t list_size = neighbour_objs.size();
    double_t sum_x{0}, sum_y{0};
    for (auto obj : neighbour_objs) {
        sum_x += obj.first;
        sum_y += obj.second;
    }
    centr.first = sum_x/list_size;
    centr.second = sum_y/list_size;
    return std::move(centr);
}

void Forel::delete_objects(const ObjCoordList &neighbour_objects, ObjCoordList &not_clustering_obj)
{
    for (auto obj : neighbour_objects) {
        auto it = std::find(not_clustering_obj.begin(),not_clustering_obj.end(),obj);
        not_clustering_obj.erase(it);
    }
}
