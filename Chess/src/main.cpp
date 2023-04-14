// Chess 
#include "Chess.h"
#include "Board.h"

int main()
{
	string board = "R###K##R################################################r###k##r"; 
	//string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
	//string board = "##########K###############################R#############r#r#####";
	Board* b = new Board();
	Chess a(board);
	int codeResponse = 0;
	string res = a.getInput();
	
	
	/*string res;
	std::cin >> res;
	b->movePiece(res);*/
	while (res != "exit")
	{
		/* 
		codeResponse value : 
		Illegal movements : 
		11 - there is not piece at the source  
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination 
		21 - illegal movement of that piece 
		31 - this movement will cause you checkmate

		legal movements : 
		41 - the last movement was legal and cause check 
		42 - the last movement was legal, next turn 
		*/

		/**/ 
		{ // put your code here instead that code
			cout << "code response >> ";
			//cin >> codeResponse;
			try {
				codeResponse = b->movePiece(res);
			}
			catch (const std::out_of_range& e)
			{}
		}
		/**/

		a.setCodeResponse(codeResponse);
		res = a.getInput();
		//std::cin >> res; // todo delete
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}