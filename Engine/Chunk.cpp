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
    this->generateMesh();
}

auto Chunk::convertIndex(const Position &pos)  {
    auto [x,y,z] = pos();
    return x * chunkSize.h * chunkSize.l + y * chunkSize.l + z;
}

Block const& Chunk::getBlock(const Position &pos) {
    return *blocks_[convertIndex(pos)];
}

void Chunk::addBlock(const Position &pos, const BlockType &type) {
    blocks_[convertIndex(pos)] = std::make_unique<Block>(type);
}

void Chunk::generateMesh() {
    for (uint32_t x = 0; x <  chunkSize.l; x++) {
        for (uint32_t y = 0; y < chunkSize.w ; y++) {
            for (uint32_t z = 0; z < chunkSize.h; z++) {
                auto& block = getBlock({x,y,z});
                auto& block2 = getBlock({x,y,z});

                if (getBlock({x,y,z})){
                    std::cout << "active" << std::endl;
                }
            }
        }
    }
}
