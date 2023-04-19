#include "Rook.h"


vector<pair<int, int>> Rook::getBasicMoves()
{
	return Rook::getValidMoves();
}

//It may move any number of squares horizontally or vertically
vector<pair<int, int>> Rook::getValidMoves()
{
	vector<pair<int, int>> validMoves;

	// up
	auto upMoves = getMovesWithDirection(-1, 0);
	std::copy(upMoves.begin(), upMoves.end(), std::back_inserter(validMoves));

	// down
	auto downMoves = getMovesWithDirection(1, 0);
	std::copy(downMoves.begin(), downMoves.end(), std::back_inserter(validMoves));

	// left
	auto leftMoves = getMovesWithDirection(0, -1);
	std::copy(leftMoves.begin(), leftMoves.end(), std::back_inserter(validMoves));

	// right
	auto rightMoves = getMovesWithDirection(0, 1);
	std::copy(rightMoves.begin(), rightMoves.end(), std::back_inserter(validMoves));

	return validMoves;
}

vector<pair<int, int>> Rook::getMovesWithDirection(int rowOffset, int colOffset)
{
	vector<pair<int, int>> moves;
	int currRow = _position.first + rowOffset;
	int currCol = _position.second + colOffset;
	while (currRow >= 0 && currRow < 8 && currCol >= 0 && currCol < 8)
	{
		// Peaceful move
		if (_board->isEmpty(currRow, currCol))
			moves.push_back(make_pair(currRow, currCol));
		// Take move
		else if (_board->getPiece(currRow, currCol)->getColor() != _color)
		{
			moves.push_back(make_pair(currRow, currCol));
			break;
		}
		else // My piece
			break;
		
		currRow += rowOffset;
		currCol += colOffset;
	}

	return moves;
	
}
