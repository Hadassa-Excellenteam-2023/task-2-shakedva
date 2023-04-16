
#include "King.h"
#include <algorithm>
#include <functional>

vector<pair<int, int>> King::getBasicMoves()
{
	int currRow = _position.first;
	int currCol = _position.second;
	vector<pair<int, int>> basicMoves = {
		{currRow - 1, currCol - 1},
		{currRow - 1, currCol},
		{currRow - 1, currCol + 1},
		{currRow, currCol - 1},
		{currRow, currCol + 1},
		{currRow + 1, currCol - 1},
		{currRow + 1, currCol},
		{currRow + 1, currCol + 1}
	};

	basicMoves.erase(
		std::remove_if(
			basicMoves.begin(),
			basicMoves.end(),
			[&](const pair<int, int>& p) { return !(_board->isValidCoordinate(p.first, p.second)); }
		),
		basicMoves.end()
	);
	return basicMoves;
}

//It may move to any adjoining square
//it may also perform a move known as castling
std::vector<std::pair<int, int>> King::getValidMoves()
{
	vector<pair<int, int>> destSquares = getBasicMoves();
	// move temporarily the king from its position, in order to check the other pieces range of valid moves
	pair<int, int> truePos = _position;
	_position = std::make_pair(-9, -9);
	vector<pair<int, int>> piecesValidMoves;
	// entire board
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (_board->isEmpty(i, j))
				continue;
			Piece* piece = _board->getPiece(i, j);
			//Check if it is the king
			//if (piece->getPosition() == _position)
			if (piece->getPosition() == truePos)
				continue;
			if (piece->getColor() != _color) {
				vector<pair<int, int>> currPieceValidMoves = piece->getBasicMoves();
				piecesValidMoves.insert(piecesValidMoves.end(), currPieceValidMoves.begin(), currPieceValidMoves.end());
			}
			else
			{
				// Piece is the same color as the king - save it's position
				// so the king won't override pieces of the same color.
				piecesValidMoves.push_back(piece->getPosition());
			}
		}
	}

	vector<pair<int, int>> validMoves;
	for (pair<int, int> destPos : destSquares)
	{
		// vector does not contain the destination position
		if (std::find(piecesValidMoves.begin(), piecesValidMoves.end(), destPos) == piecesValidMoves.end())
			validMoves.push_back(destPos);
	}
	_position = truePos;
	return validMoves;
}

vector<pair<int, int>> King::getPeacefulMoves()
{
	return vector<pair<int, int>>();
}

vector<pair<int, int>> King::getTakeMoves()
{
	return vector<pair<int, int>>();
}

bool King::isInCheck() const
{
	return false;
}

