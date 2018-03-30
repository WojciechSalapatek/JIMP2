//
// Created by wojciechsalapatek on 26.03.18.
//

#include "MemoryChunk.h"
#include <algorithm>
namespace memorychunk {
    MemoryChunk::MemoryChunk(size_t sz) {
        chunk_size = sz;
        memory_pointer = new int8_t[sz];
    }

    MemoryChunk::MemoryChunk(const MemoryChunk &other) {
        memory_pointer = new int8_t[other.ChunkSize()];
        std::copy(other.memory_pointer, other.memory_pointer + other.ChunkSize(), memory_pointer);
        chunk_size = other.chunk_size;
    }

    MemoryChunk& MemoryChunk::operator=(const MemoryChunk &other) {
        if (this == &other) return *this;
        delete [] memory_pointer;
        memory_pointer = new int8_t[other.ChunkSize()];
        std::copy(other.memory_pointer, other.memory_pointer + other.ChunkSize(), memory_pointer);
        chunk_size = other.chunk_size;
    }

    MemoryChunk::MemoryChunk(MemoryChunk &&other) {
        memory_pointer = other.memory_pointer;
        chunk_size = other.chunk_size;
        other.memory_pointer = nullptr;
        other.chunk_size = 0;
    }

    MemoryChunk & MemoryChunk::operator=(MemoryChunk &&other) {
        if (this == &other) return other;
        delete [] memory_pointer;
        memory_pointer = other.memory_pointer;
        chunk_size = other.chunk_size;
        other.memory_pointer = nullptr;
    }

    MemoryChunk::~MemoryChunk() {
        delete [] memory_pointer;
    }

    size_t MemoryChunk::ChunkSize() const {
        return chunk_size;
    }

    int8_t* MemoryChunk::MemoryAt(size_t offset) const {
        return memory_pointer + offset;
    }
}