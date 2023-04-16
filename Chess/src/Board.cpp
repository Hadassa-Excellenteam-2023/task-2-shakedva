#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"

//string board = "R######R################################################r######r";
Board::Board() : _turn(true)
{
	//white pieces
	_pieces.push_back(std::make_unique<Rook>(true, 0, 0, this));
	_pieces.push_back(std::make_unique<Bishop>(true, 0, 2, this));
	_pieces.push_back(std::make_unique<King>(true, 0, 3, this));
	_pieces.push_back(std::make_unique<Bishop>(true, 0, 5, this));
	_pieces.push_back(std::make_unique<Rook>(true, 0, 7, this));

	//black pieces
	_pieces.push_back(std::make_unique<Rook>(false, 7, 0, this));
	_pieces.push_back(std::make_unique<Bishop>(false, 7, 2, this));
	_pieces.push_back(std::make_unique<King>(false, 7, 3, this));
	_pieces.push_back(std::make_unique<Bishop>(false, 7, 5, this));
	_pieces.push_back(std::make_unique<Rook>(false, 7, 7, this));
	

}

Board::~Board()
{}

bool Board::isEmpty(int row, int col)
{
	//todo: use getPiece
	if (!isValidCoordinate(row, col))
		throw std::out_of_range("Invalid Coordinate");
	
	std::pair<int, int> pos = std::make_pair(row, col);
	for (size_t i = 0; i < _pieces.size(); i++)
		if (_pieces[i]->getPosition() == pos)
			return false;
	return true;
}

Piece* Board::getPiece(int row, int col)
{
	if (!isValidCoordinate(row, col)) 
		throw std::out_of_range("Invalid Coordinate");

	std::pair<int, int> pos = std::make_pair(row, col);
	for (size_t i = 0; i < _pieces.size(); i++)
		if (_pieces[i]->getPosition() == pos)
			return _pieces[i].get();

	return nullptr;
}

bool Board::isValidCoordinate(int row, int col) const
{
	return row >= 0 && row < 8 && col >= 0 && col < 8;
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
	int src_row = (input[0] - 'a');
	int src_col = (input[1] - '1');
	
	int trg_row = (input[2] - 'a');
	int trg_col = (input[3] - '1');

	if (!isValidCoordinate(src_row, src_col))
		return 11;
	if (!isValidCoordinate(trg_row, trg_col))
		return 21;

	Piece* src_piece = getPiece(src_row, src_col);
	Piece* trg_piece = getPiece(trg_row, trg_col);

	if (!src_piece) 
		return 11;
	else {
		if (src_piece->getColor() != _turn) 
			return 12;
		else if (trg_piece && trg_piece->getColor() == _turn)
			return 13;
		else
		{
			std::vector<std::pair<int, int>> validMoves = src_piece->getValidMoves();
			/*for (size_t i = 0; i < validMoves.size(); i++)
				std::cout << typeid(*src_piece).name() << " " << validMoves[i].first << ", " << validMoves[i].second << std::endl;
			*/
			for (size_t i = 0; i < validMoves.size(); i++)
			{
				if (validMoves[i] == std::make_pair(trg_row, trg_col)) 
				{
					//todo: check if this move makes self checkmate 
					//todo: check if this move makes checkmate againts enemy
					if (trg_piece)
						trg_piece->setCaptured();
					src_piece->setPosition(trg_row, trg_col);
					_turn = !_turn;
					return 42;
				}
			}
			return 21;

			for (size_t i = 0; i < validMoves.size(); i++)
				std::cout << validMoves[i].first << ", " << validMoves[i].second << std::endl;
		}
	}
	//return 42;
}



