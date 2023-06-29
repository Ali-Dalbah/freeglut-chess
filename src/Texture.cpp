#include "../include/Texture.h"
Texture** Texture::textures = nullptr;

unsigned int Texture::get(const PieceType type) {
    if (textures == nullptr)
        init();
    int i;
    for (i = 0; i < 6; i++) {
        if (textures[i] == NULL)
            break;
        if (textures[i]->type == type)
            return textures[i]->texture;
    }
    textures[i] = new Texture(type);
    return textures[i]->texture;
}

void Texture::init(void) {
    textures = new Texture*[6];
    for (int i = 0; i < 6; i++)
        textures[i] = nullptr;
}

std::string Texture::typeToLocation(const PieceType type) {
    switch (type) {
    case PAWN:
        return std::string("textures/pawn.jpg");
    case KNIGHT:
        return std::string("textures/knight.jpg");
    case BISHOP:
        return std::string("textures/bishop.jpg");
    case KING:
        return std::string("textures/king.jpg");
    case QUEEN:
        return std::string("textures/queen.jpg");
    case ROCK:
        return std::string("textures/rock.jpg");
    }
}

Texture::~Texture() {

}

Texture::Texture(const PieceType type): type(type) {
    texture = SOIL_load_OGL_texture(typeToLocation(type).c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_NTSC_SAFE_RGB);
}