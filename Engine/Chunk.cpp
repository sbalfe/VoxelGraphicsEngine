//
// Created by shriller44 on 10/9/22.
//

#include "Chunk.h"

Chunk::Chunk() {
    blocks_.resize(size);
    for (uint32_t x = 0; x <  chunkSize.l; x++) {
        for (uint32_t y = 0; y < chunkSize.w ; y++) {
            for (uint32_t z = 0; z < chunkSize.h; z++) {
                addBlock({x, y, z}, BlockType::BlockType_Dirt);
            }
        }
    }

    generateMesh();
}
