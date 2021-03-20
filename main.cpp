#include <iostream>
#include <vector>

class Node {
private:
    double x, y;
    bool isEnd;
    std::vector<Node*> neighbors;
public:
    Node(double x, double y, bool isEnd);
    void addNeighbor(Node* n);
    Node* getClosest();
    double getDistance(const Node* n) const;
    bool getIsEnd() const;
    void printCoords() const;
};

Node::Node(double x, double y, bool isEnd) {
    this->x = x;
    this->y = y;
    this->isEnd = isEnd;
}

void Node::addNeighbor(Node* n) {
    neighbors.push_back(n);
}

Node* Node::getClosest() {
    Node* closest = nullptr;
    double closestDistance = 100000;
    for (Node* n : neighbors) {
        double otherDistance = this->getDistance(n);
        if (otherDistance < closestDistance) {
            closest = n;
            closestDistance = otherDistance;
        }
    }
    return closest;
}

double Node::getDistance(const Node* n) const {
    return (n->y - y) / (n->x - x);
}

bool Node::getIsEnd() const {
    return isEnd;
}

void Node::printCoords() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

int main() {
    auto* start = new Node(0, 0, false);
    auto* oneX = new Node(1, 0, true);
    auto* oneY = new Node(0, 1, false);
    auto* oneXOneY = new Node(1, 1, false);
    auto* dest = new Node(3, 2, false);

    start->addNeighbor(oneX);
    start->addNeighbor(oneY);
    start->addNeighbor(oneXOneY);
    oneY->addNeighbor(dest);
    oneXOneY->addNeighbor(dest);
    oneX->addNeighbor(dest);

    auto current = start->getClosest();
    while (!current->getIsEnd()) {
        current->printCoords();
        current = current->getClosest();
    }

    current->printCoords();
    std::cout << current->getIsEnd() << std::endl;

    delete start;
    delete oneX;
    delete oneY;
    delete oneXOneY;
    delete dest;
    return 0;
}
