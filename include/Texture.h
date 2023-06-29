#ifndef SOIL_H
#define SOIL_H
#include <SOIL/SOIL.h>
#include <string>

enum PieceType {
    PAWN,
    KNIGHT,
    KING,
    QUEEN,
    BISHOP,
    ROCK
};

class Texture{
public:
    static unsigned int get(const PieceType type);
    ~Texture();
private:
    Texture(const PieceType type);
    const PieceType type;
    unsigned int texture;
    static std::string typeToLocation(const PieceType type);
    static Texture** textures;
    static void init(void);
};
#endif