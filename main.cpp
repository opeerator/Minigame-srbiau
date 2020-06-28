/* This is my implementation of shut the box game for OOP class at srbiau with Ms.zamani
 Author: Ali Yamini */

# include "gamecl.h"

// Meghdar dehi avalie baray callback ha va maghadir mojod darar bakhsh private
ShutTheBox::ShutTheBox(Newdisp& cbPrintBrd, InputFn& cbGetInput, DispRndFn& cbDispRnd, GetDiceAmt& cbGetDiceAmt, UpdateDice& cbDiceUpdate) : board{true, true, true, true, true, true, true, true, true}
{
	cb_printBoardState = cbPrintBrd;
	cb_GetInput = cbGetInput;
	cb_DispRnd = cbDispRnd;
	cb_GetDiceAmt = cbGetDiceAmt;
	cb_DiceUpdate = cbDiceUpdate;
	rng.seed(std::random_device()());
}

ShutTheBox::~ShutTheBox()
{
}

// Main Event Loop of shutbox class executes the rest of logic
int ShutTheBox::Start()
{
	endnum input{};
	input.reserve(3);

	while (true)
	{
		cb_printBoardState(board);

		if (!board[6] && !board[7] && !board[8])
		{
			rollDice(cb_GetDiceAmt());
		}
		else
		{
			rollDice(2);
		}

		}
	}

	return score;
}