#pragma once
#include <cassert>
#include <iostream>

template<typename T, std::size_t Tsize>
class heapArray {

    std::size_t end;
    T* elements;

public:
    heapArray() {
        this->end = 0;
        this->elements = (T*)malloc(sizeof(T) * Tsize);
    }

    inline bool is_empty() {
        return (this->end == Tsize);
    }

    inline std::size_t get_size() {
        return Tsize;
    }

    inline int push_back(T item) {
        assert(!this->is_empty());
        this->elements[(this->end)++] = item;
        return 1;
    }

    inline int set(std::size_t index, T item) {
        assert(index < this->end);
        this->elements[index] = item;
        return 0;
    }

    inline T get(std::size_t index) {
        assert(index < this->end);
        return this->elements[index];
    }

    ~heapArray() {
        free(this->elements);
    }

};
