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
#include <GL/glew.h>

namespace {

    struct Size {
        size_t l;
        size_t w;
        size_t h;
    };
    constexpr Size chunkSize{16,16,16};

    constexpr auto size = chunkSize.l * chunkSize.w * chunkSize.h;

    struct Position {

        auto operator()() const{
            return std::make_tuple(x,y,z);
        }

        uint32_t x;
        uint32_t y;
        uint32_t z;
    };

    constexpr GLfloat g_vertex_buffer_data[] = {
            -1.0f,-1.0f,-1.0f, // triangle 1 : begin
            -1.0f,-1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f, // triangle 1 : end
            1.0f, 1.0f,-1.0f, // triangle 2 : begin
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f, // triangle 2 : end
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f
    };

    constexpr GLfloat cubeFront[] = {

    };
}

class Chunk {
public:
    Chunk();

    ~Chunk() = default;

    void update(float dt){}

    void render(){}

private:

    void generateMesh();

    static auto convertIndex(const Position& pos);

    void addBlock(Position const& pos, BlockType const& type);

    Block const& getBlock(const Position& pos);

    std::vector<std::unique_ptr<Block>> blocks_{};
};


#endif //VOXEL_CHUNK_H
