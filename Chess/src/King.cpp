
#include "King.h"

vector<pair<int, int>> King::getBasicMoves()
{
	int currRow = m_position.first;
	int currCol = m_position.second;

	//one move to any adjoining square
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
	// Remove moves that could be threatened by enemie pieces
	basicMoves.erase(
		std::remove_if(
			basicMoves.begin(),
			basicMoves.end(),
			[&](const pair<int, int>& p) { return !(m_board->isValidCoordinate(p.first, p.second)); }
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
	pair<int, int> kingPosition = m_position;
	m_position = std::make_pair(OFF_BOARD, OFF_BOARD);
	m_position = std::make_pair(OFF_BOARD, OFF_BOARD);
	
	vector<pair<int, int>> piecesValidMoves = getPiecesMoves(kingPosition, true);
	vector<pair<int, int>> validMoves;
	
	for (pair<int, int> destPos : destSquares)
	{
		// vector does not contain the destination position
		if (std::find(piecesValidMoves.begin(), piecesValidMoves.end(), destPos) == piecesValidMoves.end())
			validMoves.push_back(destPos);
	}
	m_position = kingPosition;
	return validMoves;
}

// Checks if the king is currently under check from enemy pieces.
bool King::isInCheck() 
{
	vector<pair<int, int>> piecesValidMoves = getPiecesMoves(m_position, false);

	for (pair<int, int> pos : piecesValidMoves)
		if (pos == m_position) // at least one of the pieces is threatening the king
			return true;
	return false;
}

bool King::isInCheckmate()
{
	return isInCheck() && getValidMoves().size() == 0;
}

vector<pair<int, int>> King::getPiecesMoves(pair<int, int> kingPosition, bool playerPiecesPosition)
{
	vector<pair<int, int>> piecesValidMoves;
	// entire board
	for (size_t i = BOARD_MIN; i < BOARD_MAX; i++)
	{
		for (size_t j = BOARD_MIN; j < BOARD_MAX; j++)
		{
			if (m_board->isEmpty(i, j))
				continue;
			Piece* piece = m_board->getPiece(i, j);
			//Check if it is the king
			if (piece->getPosition() == kingPosition)
				continue;
			if (piece->getColor() != m_color) {
				vector<pair<int, int>> currPieceValidMoves = piece->getBasicMoves();
				piecesValidMoves.insert(piecesValidMoves.end(), currPieceValidMoves.begin(), currPieceValidMoves.end());
			}
			else if (playerPiecesPosition)
			{
				// Piece is the same color as the king - save it's position
				// so the king won't override pieces of the same color.
				piecesValidMoves.push_back(piece->getPosition());
			}
		}
	}

	return piecesValidMoves;
}

