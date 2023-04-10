#include "Piece.h"

Piece::Piece(string name, string color, int row, int col)
	: _name(name), _color(color), _position(std::make_pair(row, col)), _isCaptured(false)
{}

string Piece::getName()
{
	return _name;
}

string Piece::getColor()
{
	return _color;
}

bool Piece::getIsCaptured()
{
	return _isCaptured;
}

std::pair<int, int> Piece::getPosition()
{
	return _position;
}

void Piece::setPosition(int row, int col)
{
	_position = std::make_pair(row, col);
}

void Piece::setCaptured()
{
	_isCaptured = true;
}

