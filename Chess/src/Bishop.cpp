#include "Bishop.h"

// It moves and captures along diagonals 
vector<pair<int, int>> Bishop::getBasicMoves()
{
	return Bishop::getValidMoves();
}

std::vector<std::pair<int, int>> Bishop::getValidMoves()
{
	vector<pair<int, int>> validMoves;

	//up left
	for (int i = _position.first - 1, j = _position.second - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (_board->isEmpty(i, j))
			validMoves.push_back(make_pair(i, j));
		// Take move
		else if (_board->getPiece(i, j)->getColor() != _color) {
			validMoves.push_back(make_pair(i, j));
			break;
		}
		else if (_board->getPiece(i, j)->getColor() == _color)
			break;
	}
	// up right
	for (int i = _position.first - 1, j = _position.second + 1; i >= 0 && j < 8; i--, j++)
	{
		if (_board->isEmpty(i, j))
			validMoves.push_back(make_pair(i, j));
		// Take move
		else if (_board->getPiece(i, j)->getColor() != _color) {
			validMoves.push_back(make_pair(i, j));
			break;
		}
		else if (_board->getPiece(i, j)->getColor() == _color)
			break;
	}
	//down left
	for (int i = _position.first + 1, j = _position.second - 1; i < 8 && j >= 0; i++, j--)
	{
		if (_board->isEmpty(i, j))
			validMoves.push_back(make_pair(i, j));
		// Take move
		else if (_board->getPiece(i, j)->getColor() != _color) {
			validMoves.push_back(make_pair(i, j));
			break;
		}
		else if (_board->getPiece(i, j)->getColor() == _color)
			break;
	}
	// down right
	for (int i = _position.first + 1, j = _position.second + 1; i < 8 && j < 8; i++, j++)
	{
		if (_board->isEmpty(i, j))
			validMoves.push_back(make_pair(i, j));
		// Take move
		else if (_board->getPiece(i, j)->getColor() != _color) {
			validMoves.push_back(make_pair(i, j));
			break;
		}
		else if (_board->getPiece(i, j)->getColor() == _color)
			break;
	}
	return validMoves;
}

std::vector<std::pair<int, int>> Bishop::getPeacefulMoves()
{
	return std::vector<std::pair<int, int>>();
}

std::vector<std::pair<int, int>> Bishop::getTakeMoves()
{
	return std::vector<std::pair<int, int>>();
}
