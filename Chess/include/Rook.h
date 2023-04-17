#pragma once
#include <iostream>
#include "Piece.h"

class Rook : virtual public Piece
{
public:
	using Piece::Piece;
	virtual vector<pair<int, int>> getBasicMoves() override;
	virtual vector<pair<int, int>> getValidMoves() override;
	virtual vector<pair<int, int>> getPeacefulMoves() override;
	virtual vector<pair<int, int>> getTakeMoves() override;
private:

};