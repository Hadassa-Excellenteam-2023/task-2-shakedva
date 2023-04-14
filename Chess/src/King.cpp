
#include "King.h"
#include <algorithm>
#include <functional>

//It may move to any adjoining square
//it may also perform a move known as castling
std::vector<std::pair<int, int>> King::getValidMoves()
{
	int currRow = _position.first;
	int currCol = _position.second;
	vector<pair<int, int>> destSquares = {
		{currRow - 1, currCol - 1},
		{currRow - 1, currCol},
		{currRow - 1, currCol + 1},
		{currRow, currCol - 1}, 
		{currRow, currCol + 1},
		{currRow + 1, currCol - 1},
		{currRow + 1, currCol},
		{currRow + 1, currCol + 1}
	};

	destSquares.erase(
		std::remove_if(destSquares.begin(), destSquares.end(),
			[&](const pair<int, int>& p) { return !(_board->isValidCoordinate(p.first, p.second)); }),
		destSquares.end());

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
			if (piece->getPosition() == _position)
				continue;

			vector<pair<int, int>> currPieceValidMoves = piece->getValidMoves();
			piecesValidMoves.insert(piecesValidMoves.end(), currPieceValidMoves.begin(), currPieceValidMoves.end());
		}
	}

	vector<pair<int, int>> validMoves;
	for (pair<int, int> destPos : destSquares)
	{
		// vector does not contain the destination position
		if (std::find(piecesValidMoves.begin(), piecesValidMoves.end(), destPos) == piecesValidMoves.end())
			validMoves.push_back(destPos);
	}
	/*for (pair<int, int> destPos : validMoves)
		std::cout  << _color  << " King " << destPos.first << " " << destPos.second << std::endl;*/

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

