#pragma once

class Jogador
{
	int TurnIndex = 0;
	char Simbols[2]{ 'X','O' };

	public:
		void Change();
		int GetTurnIndex();
		char GetSimbols(int simbol);
};