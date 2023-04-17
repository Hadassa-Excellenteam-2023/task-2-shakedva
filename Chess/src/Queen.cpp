#include "Queen.h"

Queen::Queen(bool color, int row, int col, Board* board) :
	Piece(color, row, col, board),
	Bishop(color, row, col, board),
	Rook(color, row, col, board)
{}

vector<pair<int, int>> Queen::getBasicMoves()
{
	return getValidMoves();
}

vector<pair<int, int>> Queen::getValidMoves()
{
	vector<pair<int, int>> allMoves = Bishop::getBasicMoves();
	vector<pair<int, int>> rookMoves = Rook::getBasicMoves();
	allMoves.insert(allMoves.end(), rookMoves.begin(), rookMoves.end());
	return allMoves;
}

vector<pair<int, int>> Queen::getPeacefulMoves()
{
	return vector<pair<int, int>>();
}

vector<pair<int, int>> Queen::getTakeMoves()
{
	return vector<pair<int, int>>();
}
