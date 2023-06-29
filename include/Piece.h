#ifndef PIECE_H
#define PIECE_H
#include "Square.h"
#include "Texture.h"

class Piece: public Shape{
public:
    inline Piece(const int size, const PieceType type);
    Piece(const int size, const int x, const int y, const PieceType type);
    inline PieceType getType(void) {return type;}
    bool upgradePiece(PieceType type);
    void render(void) const override;
private:
    unsigned int* texture;
    PieceType type;
};

inline Piece::Piece(const int size, PieceType type): Piece(size, 0.f, 0.f, type) {}

#endif