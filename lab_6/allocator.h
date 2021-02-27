#include<iostream>
#include<list>

template<typename T, std::size_t Alloc_Size>
struct TAllocator{
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    TAllocator(): Used_blocks(nullptr){}
    ~TAllocator() {
        while (!Free_blocks.empty()) {
            Free_blocks.pop_back();
        }
        delete Used_blocks;
    }

    template<typename U>
    struct rebind {
        using other = TAllocator<U, Alloc_Size>;
    };

    T* allocate() {
        if (Used_blocks == nullptr) {
            Used_blocks = new T[Alloc_Size];
            for (size_t i = 0; i < Alloc_Size; ++i)
                Free_blocks.push_back(Used_blocks + i);
        }
        if (!Free_blocks.empty())
        {
            T* point = Free_blocks.back();
            Free_blocks.pop_back();
            return point;
        }
        else {
            return nullptr;
        }
    }


    void deallocate(T* ptr,  long long n = 1) {
        for (int i = 0; i < n; ++i){
            Free_blocks.push_front(ptr + i);
        }
    }

    std::list<T*> Free_blocks;
    T* Used_blocks;
};
