#include "Piece.h"

Piece::Piece(bool color, int row, int col, Board* board)
	: _color(color), _position(make_pair(row, col)), _board(board), _isCaptured(false)
{}

Piece::~Piece()
{
	delete[] _board;
}


bool Piece::getColor() const
{
	return _color;
}

bool Piece::getIsCaptured() const
{
	return _isCaptured;
}

std::pair<int, int> Piece::getPosition() const
{ 
	return _position;
}

void Piece::setPosition(int row, int col)
{
	_position = make_pair(row, col);
}

void Piece::setCaptured(bool captured)
{
	if(captured)
		_position = make_pair(-9, -9);
	_isCaptured = captured;
}
