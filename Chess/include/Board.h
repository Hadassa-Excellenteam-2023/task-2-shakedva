#pragma once
#include <iostream>
#include <vector>
#include <string>

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
	bool checkForCheck(bool);
	int extractRow(char);
	int extractCol(char);
	std::vector<std::unique_ptr<Piece>> m_pieces;
	King* m_whiteKing;
	King* m_blackKing;
	bool m_turn; // true is white's turn
};