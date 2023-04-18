#pragma once
#include <iostream>
#include "Piece.h"


class King : public Piece
{
public:
	using Piece::Piece;
	virtual vector<pair<int, int>> getBasicMoves() override;
	virtual std::vector<std::pair<int, int>> getValidMoves() override;
	bool isInCheck();
	bool isInCheckmate();
};