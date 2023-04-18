#pragma once
#include <iostream>
#include "Piece.h"

class Bishop : virtual public Piece
{
public:
	using Piece::Piece;
	virtual vector<pair<int, int>> getBasicMoves() override;
	virtual std::vector<std::pair<int, int>> getValidMoves() override;
};