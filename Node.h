//
// Created by Joshua on 3/20/2021.
//

#ifndef PATHFINDING_NODE_H
#define PATHFINDING_NODE_H

#include <vector>

class Node {
private:
    double x, y;
    bool visited;
    bool isEnd;
    Node* parent;
    std::vector<Node*> neighbors;
public:
    Node(double x, double y, bool isEnd);
    void addNeighbor(Node* n);
    void setVisited();
    void setParent(Node* n);
    Node* getParent();
    Node* getClosest();
    double getDistance(const Node* n) const;
    bool getVisited() const;
    bool getIsEnd() const;
    void printCoords() const;
};

#endif //PATHFINDING_NODE_H
