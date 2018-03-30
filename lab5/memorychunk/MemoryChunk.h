//
// Created by wojciechsalapatek on 26.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H
#include <cstdint>
#include <algorithm>
namespace memorychunk {
    class MemoryChunk {
    public:
        MemoryChunk(size_t sz);

        ~MemoryChunk();

        MemoryChunk(const MemoryChunk &other);

        MemoryChunk & operator=(const MemoryChunk & other);

        MemoryChunk(MemoryChunk &&other);

        MemoryChunk & operator=(MemoryChunk &&other);

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;

    private:
        size_t chunk_size;
        int8_t *memory_pointer;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
