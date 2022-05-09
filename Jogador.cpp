#include "Jogador.h"

void Jogador::Change()
{
	this->TurnIndex = (this->TurnIndex == 0 ? 1 : 0);
}

int Jogador::GetTurnIndex()
{
	return TurnIndex;
}

char Jogador::GetSimbols(int simbol)
{
	return Simbols[simbol];
}
