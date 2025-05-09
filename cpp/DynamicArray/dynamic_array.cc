#include <cassert>
#include <cstdio>

class DynamicArray {
public:
    int capacity;
    int size;
    int* array;

    DynamicArray(int capacity) {
        int* new_array = new int[capacity];

        this->capacity = capacity;
        this->array = new_array;
        this->size = 0;
    }

    int get(int i) {
        if (i > size) { return -1; }

        return this->array[i];
    }

    void set(int i, int n) {
        if (i > size) { return; }

        this->array[i] = n;
    }

    void pushback(int n) {
        if (this->size >= this->capacity) {
            this->resize();
        }

        this->array[this->size++] = n;
    }

    int popback() {
        if (this->size == 0) {
            return -1;
        }

        return this->array[--this->size];
    }

    void resize() {
        int new_capacity = this->capacity * 2;
        int* new_array = new int[new_capacity];

        // zero the contents of the array.
        for (int i = 0; i < new_capacity; i++) {
            new_array[i] = 0;
        }

        // copy contents of old array into the new one.
        for (int i = 0; i < this->size; i++) {
            new_array[i] = this->array[i];
        }

        this->capacity = new_capacity;
        this->array = new_array;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
};

int main() {
    // test cases:
    auto case1 = DynamicArray(1);
    assert(case1.getSize() == 0);

    // ["Array", 1, "pushback", 1, "getCapacity", "pushback", 2, "getCapacity"]
    auto case2 = DynamicArray(1);
    case2.pushback(1);
    assert(case2.getCapacity() == 1);
    case2.pushback(2);
    assert(case2.getCapacity() == 2);

    // ["Array", 1, "getSize", "getCapacity", "pushback", 1, "getSize", "getCapacity", "pushback", 2, "getSize", "getCapacity", "get", 1, "set", 1, 3, "get", 1, "popback", "getSize", "getCapacity"]
    auto case3 = DynamicArray(1);
    assert(case3.getSize() == 0);
    assert(case3.getCapacity() == 1);
    case3.pushback(1);
    assert(case3.getSize() == 1);
    assert(case3.getCapacity() == 1);
    case3.pushback(2);
    assert(case3.getSize() == 2);
    assert(case3.getCapacity() == 2);
    assert(case3.get(1) == 2);
    case3.set(1, 3);
    assert(case3.get(1) == 3);
    assert(case3.popback() == 3);
    assert(case3.getSize() == 1);
    assert(case3.getCapacity() == 2);

    std::printf("All tests pass.\n");
}
