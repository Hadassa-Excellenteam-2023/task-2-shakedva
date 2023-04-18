#pragma once
#include <iostream>
#include "Piece.h"

class Rook : virtual public Piece
{
public:
	using Piece::Piece;
	virtual vector<pair<int, int>> getBasicMoves() override;
	virtual vector<pair<int, int>> getValidMoves() override;
	vector<pair<int, int>> getMovesWithDirection(int, int, int, int);
};