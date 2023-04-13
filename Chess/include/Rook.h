#pragma once
#include <iostream>
#include "Piece.h"

class Rook : public Piece
{
public:
	using Piece::Piece;
	virtual std::vector<std::pair<int, int>> getValidMoves() override;
	virtual std::vector<std::pair<int, int>> getPeacefulMoves() override;
	virtual std::vector<std::pair<int, int>> getTakeMoves() override;
private:

};