#pragma once
#include "Jogador.h"

class TicTacToe
{
	char Board[9] { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ' };
	Jogador Player;
	bool GameOver = false;
	int WinningSequences[8][3] = {
		{0,1,2}, {3,4,5}, {6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8}, {2,4,6}
	};

	public:
		void Init();
		void Draw();
		bool MakePlay(int posicao);
		bool CheckWinningSequences(char Simbol);
		bool CheckTie();
		void GamesOver();
};