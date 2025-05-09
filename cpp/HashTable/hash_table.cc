#include <cassert>
#include <cmath>
#include <cstdint>
#include <functional>
#include <numbers>
#include <vector>

class IntegerHashTable {
public:
    using HashFunction = std::function<int64_t(int64_t, int64_t)>; 

    IntegerHashTable(HashFunction func = IntegerHashTable::divisionHash) {
        hash = func;
        region = std::vector<int64_t>(INITIAL_REGION_SIZE);
        size = 0;
    }

    ~IntegerHashTable() = default;

    bool add(int64_t key, int64_t value) {
        auto hash_value = hash(key, capacity);

        assert(hash_value < capacity);

        region[hash_value] = value;
    }

    int64_t remove(int64_t key) {
        auto hash_value = hash(key, capacity);

        assert(hash_value < capacity);

        region[hash_value] = 0;
    }

private:
    constexpr static int64_t INITIAL_REGION_SIZE = 10;
    constexpr static double MAX_LOAD_FACTOR = 67.5;

    HashFunction hash = nullptr;
    std::vector<int64_t> region;
    int64_t capacity = INITIAL_REGION_SIZE;
    int64_t size = 0;


    static int64_t divisionHash(int64_t key, int64_t capacity) {
        return key % capacity;
    }

    static int64_t multiplicationHash(int64_t key, int64_t capacity) {
        return static_cast<int64_t>(std::floor(capacity * (std::fmod((key * std::numbers::phi), 1))));
    }

    int64_t rehashRegion() {
        auto new_capacity = this->capacity * 2;
        auto new_region = std::vector<int64_t>(new_capacity);
        for(int64_t idx = 0; idx < this->region.size(); idx += 1) {
            // TODO: rehash table region with new keys
        }
    }

    double loadFactor() {
        return static_cast<double>(size) / static_cast<double>(capacity);
    }

};