// Chess 
#include "Chess.h"
#include "Board.h"

int main()
{
	string board = "R#BKQB#R################################################r#bkqb#r"; 
	Board* b = new Board();
	Chess a(board);
	int codeResponse = 0;
	string res = a.getInput();
	
	while (res != "exit")
	{
		{ 
			cout << "code response >> ";
			try {
				codeResponse = b->movePiece(res);
			}
			catch (const std::out_of_range& e)
			{}
		}

		a.setCodeResponse(codeResponse);
		res = a.getInput();
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}