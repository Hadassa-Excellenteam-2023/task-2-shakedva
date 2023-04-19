#include "Bishop.h"
#include "Rook.h"


class Queen : public Rook, public Bishop
{
public:
	using Bishop::Bishop;
	using Rook::Rook;

	Queen(bool, int, int, Board*);
	virtual vector<pair<int, int>> getBasicMoves() override;
	virtual vector<pair<int, int>> getValidMoves() override;
};