#pragma once
#include <iostream>
#include "Piece.h"

class Bishop : virtual public Piece
{
public:
	using Piece::Piece;
	virtual vector<pair<int, int>> getBasicMoves() override;
	virtual vector<pair<int, int>> getValidMoves() override;
	vector<pair<int, int>> getMovesWithDirection(int, int);
};