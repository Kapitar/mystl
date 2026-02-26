#pragma once
#include <cstddef>

namespace mystl {
    template<class T>
    class vector {
    private:
        T *start = nullptr;
        T *end = nullptr;
        T *cap = nullptr;

        void resize() {
            if (this->capacity() == this->size()) {
                return;
            }


        }

    public:
        explicit vector() {
        }

        void push_back(const T &elem) {
            resize();
            new(static_cast<void *>(end)) T(elem);
            ++end;
        }

        void pop_back() {
            if (this->empty()) return;
            --end;
            end->~T();
        }

        size_t capacity() {
            return cap - start;
        }

        size_t size() {
            return end - start;
        }

        size_t empty() {
            return start == end;
        }
    };
}
