#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "macros.h"

Board::Board() : m_turn(true) // White starts
{
	//white pieces
	m_pieces.push_back(std::make_unique<Rook>(true, 0, 0, this));
	m_pieces.push_back(std::make_unique<Bishop>(true, 0, 2, this));
	m_pieces.push_back(std::make_unique<King>(true, 0, 3, this));
	m_pieces.push_back(std::make_unique<Queen>(true, 0, 4, this));
	m_pieces.push_back(std::make_unique<Bishop>(true, 0, 5, this));
	m_pieces.push_back(std::make_unique<Rook>(true, 0, 7, this));

	//black pieces
	m_pieces.push_back(std::make_unique<Rook>(false, 7, 0, this));
	m_pieces.push_back(std::make_unique<Bishop>(false, 7, 2, this));
	m_pieces.push_back(std::make_unique<King>(false, 7, 3, this));
	m_pieces.push_back(std::make_unique<Queen>(false, 7, 4, this));
	m_pieces.push_back(std::make_unique<Bishop>(false, 7, 5, this));
	m_pieces.push_back(std::make_unique<Rook>(false, 7, 7, this));
	
	m_whiteKing = (King*)getPiece(0, 3);
	m_blackKing = (King*)getPiece(7, 3);
}

Board::~Board()
{
	delete m_whiteKing;
	delete m_blackKing;
}

bool Board::isEmpty(int row, int col)
{
	return !getPiece(row, col);
}

Piece* Board::getPiece(int row, int col)
{
	if (!isValidCoordinate(row, col)) 
		throw std::out_of_range("Invalid Coordinate");

	std::pair<int, int> pos = std::make_pair(row, col);
	for (const auto& piece : m_pieces)
		if(piece->getPosition() == pos)
			return piece.get();
	return nullptr;
}

bool Board::isValidCoordinate(int row, int col) const
{
	return row >= BOARD_MIN && row < BOARD_MAX&& col >= BOARD_MIN && col < BOARD_MAX;
}

//Illegal movements :
//11 - there is not piece at the source
//12 - the piece in the source is piece of your opponent
//13 - there one of your pieces at the destination
//21 - illegal movement of that piece
//31 - this movement will cause you checkmate
//
//legal movements :
//41 - the last movement was legal and cause check
//42 - the last movement was legal, next turn

int Board::movePiece(string input)
{
	int src_row = extractRow(input[0]);
	int src_col = extractCol(input[1]);
	
	int trg_row = extractRow(input[2]);
	int trg_col = extractCol(input[3]);

	if (!isValidCoordinate(src_row, src_col))
		return SRC_EMPTY;
	if (!isValidCoordinate(trg_row, trg_col))
		return ILLEGAL_PIECE_MOVE;

	Piece* src_piece = getPiece(src_row, src_col);
	Piece* trg_piece = getPiece(trg_row, trg_col);

	if (!src_piece) 
		return SRC_EMPTY;
	
	if (src_piece->getColor() != m_turn) 
		return SRC_IS_ENEMY;

	if (trg_piece && trg_piece->getColor() == m_turn)
		return TRG_IS_CURR_PLAYER;

	std::vector<std::pair<int, int>> validMoves = src_piece->getValidMoves();
	for (size_t i = 0; i < validMoves.size(); i++)
	{
		if (validMoves[i] == std::make_pair(trg_row, trg_col)) 
		{
			src_piece->setPosition(trg_row, trg_col);
			if (trg_piece)
				trg_piece->setCaptured(true); 

			// check if this move makes self-check
			if (checkForCheck(m_turn)) {
				src_piece->setPosition(src_row, src_col);
				
				if (trg_piece) {
					trg_piece->setPosition(trg_row, trg_col);
					trg_piece->setCaptured(false);
				}
				return CAUSE_SELF_CHECK;
			}
			// Legal moves from now on

			//check if the move makes check againts enemy
			if (checkForCheck(!m_turn)) {
				m_turn = !m_turn;
				return CAUSE_CHECK;
			}

			m_turn = !m_turn;
			return REGULAR_MOVE;
		}
	}
	return ILLEGAL_PIECE_MOVE;
}
// Check if there is check againts the king of the color received
bool Board::checkForCheck(bool color)
{
	return color ? m_whiteKing->isInCheck() : m_blackKing->isInCheck();
}

int Board::extractRow(char input)
{
	return input - 'a';
}

int Board::extractCol(char input)
{
	return input - '1';
}



