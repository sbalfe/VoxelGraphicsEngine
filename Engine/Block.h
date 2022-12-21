//
// Created by shriller44 on 10/9/22.
//

#ifndef VOXEL_BLOCK_H
#define VOXEL_BLOCK_H



enum class BlockType {
        BlockType_Default = 0,
        BlockType_Grass,
        BlockType_Dirt,
        BlockType_Water,
        BlockType_Stone,
        BlockType_Wood,
        BlockType_Sand,
        BlockType_Air,
        BlockType_NumTypes,
};

class Block {
public:

    explicit Block(const BlockType& type): type_{type}, active_{true}{}

    [[nodiscard]] explicit operator bool() const {
        return active_;
    }

    void setActive(bool active){
        active_ = active;
    }

    [[nodiscard]] BlockType getType() const { return type_;}

    void addQuad (){

    }

private:
    BlockType type_;
    //std::vector<Quad, 6>
    bool active_{};
};

#endif //VOXEL_BLOCK_H
