#pragma once
#include <iostream>
#include "Piece.h"

class Bishop : public Piece
{
public:
	using Piece::Piece;
	virtual vector<pair<int, int>> getBasicMoves() override;
	virtual std::vector<std::pair<int, int>> getValidMoves() override;
	virtual std::vector<std::pair<int, int>> getPeacefulMoves() override;
	virtual std::vector<std::pair<int, int>> getTakeMoves() override;
};