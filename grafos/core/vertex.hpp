#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <utility>

struct Vertex {
    std::string name;
    int age;

    Vertex() : name(""), age(0) {}
    Vertex(std::string _name, int _age)
    : name(_name), age(_age) {}
};

#endif
