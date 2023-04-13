#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"

using std::string;

class Piece
{
public:
	Piece(bool, int, int, Board*);
	~Piece();
	bool getColor() const;
	bool getIsCaptured() const;
	std::pair<int, int> getPosition() const;
	void setPosition(int, int);
	void setCaptured();
	virtual std::vector<std::pair<int, int>> getValidMoves() = 0;
	virtual std::vector<std::pair<int, int>> getPeacefulMoves() = 0;
	virtual std::vector<std::pair<int, int>> getTakeMoves() = 0;
protected:
	bool _color; // white is true
	std::pair<int, int> _position;
	Board* _board;
	bool _isCaptured;
	
};