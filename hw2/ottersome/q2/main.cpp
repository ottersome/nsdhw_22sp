#include <iostream>
#include <pybind11/pybind11.h>
#include <math.h>
#include <string.h>

namespace py = pybind11;

struct Vector{
    Vector(float x, float y):
    x(x),y(y){ }
    float norm(){
        return sqrt(pow(x,2)+pow(y,2));
    }
    float x;
    float y;
};

float get_angle_rad(Vector & v1, Vector & v2){
    //return acos(v1->x*v2->x + v1->y*v2->y/(v1->norm()*v2->norm()));
    return acos((v1.x*v2.x + v1.y*v2.y)/(v1.norm()*v2.norm()));
    //return v1.x;
}

//We are adding the structure for vectors to python
PYBIND11_MODULE(vector,m){
    m.doc() = "Vector class for hw2";
    py::class_<Vector>(m,"Vector")
        .def(py::init<float, float>())
        .def("norm",&Vector::norm)
        .def("__repr__",
                [](const Vector& vec){
                    return "<vector.Vector with values x="+std::to_string(vec.x)+",y="+std::to_string(vec.y)+"\n";
                });

    m.def("get_angle_rad",&get_angle_rad, "Function for getting angle between given vectors ");

}
