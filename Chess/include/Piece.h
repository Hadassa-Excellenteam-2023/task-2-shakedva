#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Board.h"

using std::string;
using std::vector;
using std::pair;
using std::make_pair;


class Piece
{
public:
	Piece(bool, int, int, Board*);
	virtual ~Piece();
	bool getColor() const;
	bool getIsCaptured() const;
	pair<int, int> getPosition() const;
	void setPosition(int, int);
	void setCaptured();
	virtual vector<pair<int, int>> getBasicMoves() = 0;
	virtual vector<pair<int, int>> getValidMoves() = 0;

protected:
	bool _color; // white is true
	pair<int, int> _position;
	Board* _board;
	bool _isCaptured;
	
};