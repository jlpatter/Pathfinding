#include <iostream>
#include <vector>
#include "Node.h"

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
    current->setVisited();
    while (!current->getIsEnd()) {
        current->printCoords();
        Node* closest = current->getClosest();
        if (closest == nullptr || closest->getVisited()) {
            current = current->getParent();
        }
        else {
            closest->setParent(current);
            current = closest;
            current->setVisited();
        }
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
