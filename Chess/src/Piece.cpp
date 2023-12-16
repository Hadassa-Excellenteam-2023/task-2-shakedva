#include "Piece.h"

Piece::Piece(bool color, int row, int col, Board* board)
	: m_color(color), m_position(make_pair(row, col)), m_board(board), m_isCaptured(false)
{}

Piece::~Piece()
{
	delete[] m_board;
}


bool Piece::getColor() const
{
	return m_color;
}

bool Piece::getIsCaptured() const
{
	return m_isCaptured;
}

std::pair<int, int> Piece::getPosition() const
{ 
	return m_position;
}

void Piece::setPosition(int row, int col)
{
	m_position = make_pair(row, col);
}

void Piece::setCaptured(bool captured)
{
	if(captured)
		m_position = make_pair(OFF_BOARD, OFF_BOARD);
	m_isCaptured = captured;
}
