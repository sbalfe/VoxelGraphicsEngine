//
// Created by shriller44 on 10/9/22.
//

#ifndef VOXEL_CHUNK_H
#define VOXEL_CHUNK_H

#include <array>
#include <vector>
#include <memory>
#include <iostream>
#include <tuple>
#include <utility>
#include <fmt/format.h>
#include "Block.h"

namespace {

    struct Size {
        size_t l;
        size_t w;
        size_t h;
    };
    constexpr Size chunkSize{16,16,16};

    constexpr auto size = chunkSize.l * chunkSize.w * chunkSize.h;
}

class Chunk {

public:

    struct Position {

        auto operator()() const{
            return std::make_tuple(x,y,z);
        }

        uint32_t x;
        uint32_t y;
        uint32_t z;
    };

    Chunk();

    ~Chunk() = default;

    void update(float dt){}

    void render(){}

private:

    void generateMesh(){
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

    static auto convertIndex(const Position& pos){
        auto [x,y,z] = pos();
        return x * chunkSize.h * chunkSize.l + y * chunkSize.l + z;
    }

    void addBlock(const Position& pos, const BlockType& type){
        blocks_[convertIndex(pos)] = std::make_unique<Block>(type);
    }

    Block const & getBlock(const Position& pos){
        return *blocks_[convertIndex(pos)];
    }

    std::vector<std::unique_ptr<Block>> blocks_{};
};


#endif //VOXEL_CHUNK_H
