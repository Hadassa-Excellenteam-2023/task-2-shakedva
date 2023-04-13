#pragma once
#include <iostream>
#include <vector>
#include <string>

using std::string;

class Piece;

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
	std::vector<std::unique_ptr<Piece>> _pieces;
	
	bool _turn; // true is white's turn
};