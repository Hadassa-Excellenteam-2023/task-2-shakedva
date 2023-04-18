#pragma once
#include <iostream>
#include <vector>
#include <string>
//#include "Piece.h"

using std::string;

class Piece;
class King;

class Board
{
public:
	Board();
	~Board();
	bool isEmpty(int, int);
	Piece* getPiece(int, int);
	bool isValidCoordinate(int, int) const;
	int movePiece(string);

private:
	bool checkForCheck();
	std::vector<std::unique_ptr<Piece>> _pieces;
	King* _whiteKing;
	King* _blackKing;
	bool _turn; // true is white's turn
};