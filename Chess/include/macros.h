enum CodeResponse
{
	SRC_EMPTY = 11,
	SRC_IS_ENEMY = 12,
	TRG_IS_CURR_PLAYER = 13, 

	ILLEGAL_PIECE_MOVE = 21, 
	CAUSE_SELF_CHECK = 31,
	
	CAUSE_CHECK = 41,	
	REGULAR_MOVE = 42
};

const int BOARD_MIN = 0;
const int BOARD_MAX = 8;
const int OFF_BOARD = -9;

