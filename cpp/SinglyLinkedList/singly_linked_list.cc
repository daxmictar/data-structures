#include <vector>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val, Node* next = nullptr) {
        this->val = val;
        this->next = next;
    }
};

struct LinkedList {
    Node* front;
    Node* back;

    LinkedList() {
        front = new Node(-1);
        back = front;
    }

    int get(int index) {
        auto* current = front->next;
        int pos = 0;
        while (current != nullptr) {
            if (pos == index) {
                return current->val;
            }

            current = current->next;
            ++pos;
        }

        return -1;
    }

    void insertHead(int val) {
        auto new_node = new Node(val);
        // first non-dummy position
        new_node->next = front->next;
        front->next = new_node;
        if (new_node->next == nullptr) {
            back = new_node;
        }
    }

    void insertTail(int val) {
        this->back->next = new Node(val);
        this->back = this->back->next;
    }

    bool remove(int index) {
        int pos = 0;
        auto current = this->front;
        while (pos < index && current != nullptr) {
            current = current->next;
            ++pos;
        }

        if (current != nullptr && current->next != nullptr) {
            if (current->next == this->back) {
                this->back = current;
            }

            auto junk = current->next;
            current->next = current->next->next;
            delete junk;

            return true;
        }

        return false;
    }

    vector<int> getValues() {
        auto values = vector<int>();

        // go to the node right before the desired node
        auto current = this->front->next;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }

        return values;
    }
};
