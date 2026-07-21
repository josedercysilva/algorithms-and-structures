#ifndef EDGE_H
#define EDGE_H

struct Edge {
    int targetId;
    double weight;

    Edge() : targetId(-1), weight(0.0) {}
    Edge(int _target_id, double _weight)
    : targetId(_target_id), weight(_weight) {}
};

#endif
