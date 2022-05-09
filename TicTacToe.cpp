#include <iostream>
#include "TicTacToe.h"

void TicTacToe::Init()
{
	int posicao = 0;
	do{
		system("cls");
		Draw();
		std::cout << "Jogador " << (Player.GetTurnIndex()) + 1 << ":\n";
		std::cout << "Digite uma posicao: ( 1 ate 9) ";
		std::cin >> posicao;
		MakePlay(posicao - 1);
	} while (!GameOver);
}


void TicTacToe::Draw()
{
	int Size = sizeof(Board) / sizeof(char);

	for (int i = 0; i < Size; i++)
	{
		std::cout << Board[i] << " |";
		if ((i + 1) % 3 == 0) std::cout << "\n----------\n" ;
	}
}

bool TicTacToe::MakePlay(int posicao)
{
	if (GameOver) return false;
	if (Board[posicao] == ' ')
	{
		Board[posicao] = Player.GetSimbols(Player.GetTurnIndex());
		bool WinningSequencesIndex = CheckWinningSequences(Player.GetSimbols(Player.GetTurnIndex()));
		if( WinningSequencesIndex || CheckTie())
		{ 
			GamesOver();
		}
		else {
			Player.Change();
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool TicTacToe::CheckWinningSequences(char Simbol)
{
	for (int i = 0; i < 8; i++)
	{
		if (Board[WinningSequences[i][0]] == Simbol && Board[WinningSequences[i][1]] == Simbol && Board[WinningSequences[i][2]] == Simbol)
		{
			std::cout << "Jogador " << (Player.GetTurnIndex() + 1) << " ganhou!" << "\n";
			return true;
		}
	}
	return false;
}

bool TicTacToe::CheckTie()
{
	for (int i = 0; i < 9; i++)
	{
		if(Board[i] == ' ')
		{
			return false;
		}
	}
	std::cout << "Empate!!!!\n";
	return true;
}

void TicTacToe::GamesOver()
{
	GameOver = true;
	std::cout << "GAME OVER \n";
}
