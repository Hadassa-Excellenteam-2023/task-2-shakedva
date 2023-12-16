#include "Bishop.h"

// It moves and captures along diagonals 
vector<pair<int, int>> Bishop::getBasicMoves()
{
	return Bishop::getValidMoves();
}

std::vector<std::pair<int, int>> Bishop::getValidMoves()
{
	vector<pair<int, int>> validMoves;
	// up left
	auto upLeftMoves = getMovesWithDirection(-1, -1);
	std::copy(upLeftMoves.begin(), upLeftMoves.end(), std::back_inserter(validMoves));

	// up right
	auto upRightMoves = getMovesWithDirection(-1, 1);
	std::copy(upRightMoves.begin(), upRightMoves.end(), std::back_inserter(validMoves));

	// down left
	auto downLeftMoves = getMovesWithDirection(1, -1);
	std::copy(downLeftMoves.begin(), downLeftMoves.end(), std::back_inserter(validMoves));

	// down right
	auto downRightMoves = getMovesWithDirection(1, 1);
	std::copy(downRightMoves.begin(), downRightMoves.end(), std::back_inserter(validMoves));

	return validMoves;
}
// Same function as in the Rook class. Consider moving it to a global scope.
vector<pair<int, int>> Bishop::getMovesWithDirection(int rowOffset, int colOffset)
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

