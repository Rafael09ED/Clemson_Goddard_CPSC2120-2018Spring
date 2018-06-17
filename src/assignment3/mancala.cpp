//
// Created by Rafael Dejesus on 4/21/2018.
//

#include <fstream>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <list>
#include "Position.h"
#include "PositionTreeNode.h"

using namespace std;


struct PositionHasher {
    size_t operator()(const PositionTreeNode *t) const {
        return hash<string>()(t->value->toString());
    }
};

struct PositionEqualer {
    bool operator()(const PositionTreeNode *lhs, const PositionTreeNode *rhs) const {
        return *(lhs->value) == *(rhs->value);
    }
};

class MancalaSolver {
    bool wantsUnique;
    int boardSize;
    PositionTreeNode *rootNode;
    PositionTreeNode *shortestPath;
    list<PositionTreeNode *> nodesList;
    unordered_set<PositionTreeNode *, PositionHasher, PositionEqualer> set;
    queue<PositionTreeNode *> breadthIterator;

public:
    MancalaSolver(vector<int> *rootState, bool _wantsUnique);

    string getResults();;

    ~MancalaSolver();

private:
    void solve();

    void hashSolve();

    PositionTreeNode *makeNext(PositionTreeNode *parent, int moveIndex);
};

static const int NUMBER_OF_STATES = 5;

int main(int argc, char *argv[]) {

    bool wantsUnique = false;
    switch (argc) {
        case NUMBER_OF_STATES + 1:
            break;
        case NUMBER_OF_STATES + 2:
            wantsUnique = true;
            break;
        default:
            cout << "State of 5 is required as input:\n"
                 << "ex:\n"
                 << "[exec] 1 2 3 4 5\n"
                 << "or a state of five followed by a flag for unique values\n";
            exit(-1);
    }

    vector<int> rootState;
    cout << "Running: Mancala ";
    for (int i = 1; i < argc - 1; ++i) {
        cout << argv[i] << " ";
        rootState.push_back(stoi(argv[i]));
    }
    cout << ((wantsUnique) ? "hash" : "") << endl;

    //for (int j = 0; j < 10; ++j) {
    MancalaSolver solver(&rootState, wantsUnique);
    cout << solver.getResults() << endl;
    cout.flush();
    //}
}

MancalaSolver::MancalaSolver(vector<int> *rootState, bool _wantsUnique)
        : rootNode(new PositionTreeNode(new Position(*rootState))),
          wantsUnique(_wantsUnique) {
    breadthIterator.push(rootNode);
    set.insert(rootNode);
    boardSize = rootState->size();
    (wantsUnique) ? hashSolve() : solve();
}

MancalaSolver::~MancalaSolver() {
    for (auto i = set.begin(); i != set.end(); i++)
        delete *i;
    set.clear();

    for (auto i = nodesList.begin(); i != nodesList.end(); i++)
        delete *i;
    nodesList.clear();

/*    delete rootNode->value;
    delete rootNode;*/
}

void MancalaSolver::solve() {
    for (; !breadthIterator.empty(); breadthIterator.pop()) {
        PositionTreeNode *currentNode = breadthIterator.front();

        for (int i = 1; i <= boardSize; i++) {
            auto nextPositionNode = makeNext(currentNode, i);
            if (nextPositionNode == nullptr) continue;

            nodesList.push_back(nextPositionNode);
            if (nextPositionNode->value->isDone()) {
                shortestPath = nextPositionNode;
                return;
            }
            breadthIterator.push(nextPositionNode);
        }
    }
}

void MancalaSolver::hashSolve() {
    for (; !breadthIterator.empty(); breadthIterator.pop()) {
        PositionTreeNode *currentNode = breadthIterator.front();

        for (int i = 1; i <= boardSize; i++) {
            auto nextPositionNode = makeNext(currentNode, i);
            if (nextPositionNode == nullptr) continue;

            bool isNew = set.insert(nextPositionNode).second;
            if (!isNew) {
                delete nextPositionNode;
                continue;
            }
            if (nextPositionNode->value->isDone())
                shortestPath = nextPositionNode;

            breadthIterator.push(nextPositionNode);
        }
    }
}


PositionTreeNode *MancalaSolver::makeNext(PositionTreeNode *parent, int moveIndex) {
    auto nextPosition = parent->value->afterMove(moveIndex);
    if (nextPosition == nullptr) {
        delete nextPosition;
        return nullptr;
    }
    return new PositionTreeNode(nextPosition, parent, moveIndex);
}

string MancalaSolver::getResults() {
    string output;
    vector<string> pathOutput;
    for (PositionTreeNode *ptr = shortestPath; ptr->parent != nullptr; ptr = ptr->parent)
        pathOutput.push_back("Move: " + to_string(ptr->positionPicked) + " -> " + ptr->value->toString());


    output += wantsUnique ? "Unique states found: " + to_string(set.size() - 1) + "\n"
                          : "Positions found: " + to_string(set.size() + nodesList.size()) + "\n";

    output += "NUMBER OF MOVES: " + to_string(pathOutput.size()) + "\n";
    output += rootNode->value->toString() + "\n";
    for (auto iterator = pathOutput.end(); iterator-- != pathOutput.begin();)
        output += *iterator + "\n";

    return output;
}
