#include <iostream>
#include <vector>
#include <ctgmath>

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
    return std::sqrt(std::pow((n->y - y), 2) + std::pow((n->x - x), 2));
}

bool Node::getIsEnd() const {
    return isEnd;
}

void Node::printCoords() const {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

int main() {
    auto* start = new Node(1, 2, false);
    auto* oneXOneY = new Node(1, 1, false);
    auto* oneX = new Node(1, 0, false);
    auto* twoX = new Node(2, 0, false);
    auto* threeX = new Node(3, 0, false);

    auto* threeXOneY = new Node(3, 1, false);
    auto* threeXTwoY = new Node(3, 2, false);
    auto* threeXThreeY = new Node(3, 3, false);
    auto* threeXFourY = new Node(3, 4, false);
    auto* twoXFourY = new Node(2, 4, false);

    auto* fourX = new Node(4, 0, false);
    auto* fiveX = new Node(5, 0, false);

    auto* fiveXOneY = new Node(5, 1, false);
    auto* fiveXTwoY = new Node(5, 2, false);
    auto* fiveXThreeY = new Node(5, 3, false);
    auto* fiveXFourY = new Node(5, 4, true);

    start->addNeighbor(oneXOneY);
    oneXOneY->addNeighbor(oneX);
    oneX->addNeighbor(twoX);
    twoX->addNeighbor(threeX);

    threeX->addNeighbor(threeXOneY);
    threeXOneY->addNeighbor(threeXTwoY);
    threeXTwoY->addNeighbor(threeXThreeY);
    threeXThreeY->addNeighbor(threeXFourY);
    threeXFourY->addNeighbor(twoXFourY);

    threeX->addNeighbor(fourX);
    fourX->addNeighbor(fiveX);
    fiveX->addNeighbor(fiveXOneY);
    fiveXOneY->addNeighbor(fiveXTwoY);
    fiveXTwoY->addNeighbor(fiveXThreeY);
    fiveXThreeY->addNeighbor(fiveXFourY);

    auto current = start->getClosest();
    while (!current->getIsEnd()) {
        current->printCoords();
        current = current->getClosest();
    }

    current->printCoords();
    std::cout << current->getIsEnd() << std::endl;

    delete start;
    delete oneXOneY;
    delete oneX;
    delete twoX;
    delete threeX;
    delete threeXOneY;
    delete threeXTwoY;
    delete threeXThreeY;
    delete threeXFourY;
    delete twoXFourY;
    delete fourX;
    delete fiveX;
    delete fiveXOneY;
    delete fiveXTwoY;
    delete fiveXThreeY;
    delete fiveXFourY;
    return 0;
}
