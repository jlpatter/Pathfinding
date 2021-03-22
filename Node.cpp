//
// Created by Joshua on 3/20/2021.
//

#include <ctgmath>
#include <iostream>
#include "Node.h"

Node::Node(double x, double y) {
    this->x = x;
    this->y = y;
    this->visited = false;
    this->isEnd = false;
    this->parent = nullptr;
}

Node::Node(double x, double y, bool isEnd) {
    this->x = x;
    this->y = y;
    this->visited = false;
    this->isEnd = isEnd;
    this->parent = nullptr;
}

void Node::addNeighbor(Node* n) {
    neighbors.push_back(n);
}

Node* Node::getClosest() {
    Node* closest = nullptr;
    double closestDistance = 100000;
    for (Node* n : neighbors) {
        if (!n->getVisited()) {
            double otherDistance = this->getDistance(n);
            if (otherDistance < closestDistance) {
                closest = n;
                closestDistance = otherDistance;
            }
        }
    }
    return closest;
}

double Node::getDistance(const Node* n) const {
    return std::sqrt(std::pow((n->y - y), 2) + std::pow((n->x - x), 2));
}

bool Node::getIsEnd() const {
    return isEnd;
}

void Node::printCoords() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

bool Node::getVisited() const {
    return visited;
}

void Node::setVisited() {
    visited = true;
}

void Node::setParent(Node *n) {
    parent = n;
}

Node *Node::getParent() {
    return parent;
}
