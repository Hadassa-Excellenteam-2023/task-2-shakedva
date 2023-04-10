#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::string;

class Piece
{
public:
	Piece(string, string, int, int);
	string getName();
	string getColor();
	bool getIsCaptured();
	std::pair<int, int> getPosition();
	void setPosition(int, int);
	void setCaptured();
	virtual std::vector<std::pair<int, int>> getValidMoves() = 0;
	virtual std::vector<std::pair<int, int>> getPeacefulMoves() = 0;
	virtual std::vector<std::pair<int, int>> getTakeMoves() = 0;
	
private:
	string _name;
	string _color;
	std::pair<int, int> _position;
	bool _isCaptured;
};