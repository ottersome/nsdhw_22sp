#include <iostream>
#include <pybind11/pybind11.h>
#include <math.h>

namespace py = pybind11;

struct OttrVector{
    OttrVector(float x, float y):
    x(x),y(y){ }
    float norm(){
        return sqrt(pow(x,2)+pow(y,2));
    }
    float x;
    float y;
};

float get_dem_rads_boi(OttrVector & v1, OttrVector & v2){
    return acos(v1.x*v2.x + v1.y*v2.y/(v1.norm()*v2.norm()));
}

//We are adding the structure for vectors to python
PYBIND11_MODULE(vectormath,m){
    py::class_<OttrVector>(m,"_vector")
        .def(py::init<float, float>())
        .def("norm",&OttrVector::norm);
}
