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
	for (int i = _position.first - 1; i >= 0; i--)
	{
		// Peaceful move
		if (_board->isEmpty(i, _position.second))
			validMoves.push_back(make_pair(i, _position.second));
		// Take move
		else if (_board->getPiece(i, _position.second)->getColor() != _color) {
			validMoves.push_back(make_pair(i, _position.second));
			break;
		}
		else if (_board->getPiece(i, _position.second)->getColor() == _color)
			break;
	}
	//down
	for (int i = _position.first + 1; i < 8; i++)
	{
		// Peaceful move
		if (_board->isEmpty(i, _position.second))
			validMoves.push_back(make_pair(i, _position.second));
		// Take move
		else if (_board->getPiece(i, _position.second)->getColor() != _color) {
			validMoves.push_back(make_pair(i, _position.second));
			break;
		}
		else if (_board->getPiece(i, _position.second)->getColor() == _color)
			break;
	}
	//left
	for (int i = _position.second - 1; i >= 0; i--)
	{
		// Peaceful move
		if (_board->isEmpty(_position.first, i))
			validMoves.push_back(make_pair(_position.first, i));
		// Take move
		else if (_board->getPiece(_position.first, i)->getColor() != _color) {
			validMoves.push_back(make_pair(_position.first, i));
			break;
		}
		else if (_board->getPiece(_position.first, i)->getColor() == _color)
			break;
	}
	//right
	for (int i = _position.second + 1; i < 8; i++)
	{
		// Peaceful move
		if (_board->isEmpty(_position.first, i))
			validMoves.push_back(make_pair(_position.first, i));
		// Take move
		else if (_board->getPiece(_position.first, i)->getColor() != _color) {
			validMoves.push_back(make_pair(_position.first, i));
			break;
		}
		else if (_board->getPiece(_position.first, i)->getColor() == _color)
			break;
	}

	
	return validMoves;
}

vector<pair<int, int>> Rook::getPeacefulMoves()
{
	return vector<pair<int, int>>();
}

vector<pair<int, int>> Rook::getTakeMoves()
{
	return vector<pair<int, int>>();
}