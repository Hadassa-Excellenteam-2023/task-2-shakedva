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
	int currRow = m_position.first + rowOffset;
	int currCol = m_position.second + colOffset;
	while (currRow >= BOARD_MIN && currRow < BOARD_MAX && currCol >= BOARD_MIN && currCol < BOARD_MAX)
	{
		// Peaceful move
		if (m_board->isEmpty(currRow, currCol))
			moves.push_back(make_pair(currRow, currCol));
		// Take move
		else if (m_board->getPiece(currRow, currCol)->getColor() != m_color)
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
