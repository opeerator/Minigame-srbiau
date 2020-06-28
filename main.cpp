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

// loop avalie baraye vaghaye badi shutthebox
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
		cb_DiceUpdate(diceResult);

		if ((!board[0] && diceResult == 1) || (!board[1] && diceResult == 2))
			break;

		if (!shouldContinue(boardToNum(board, false), diceResult))
			break;

		if (calcScore() < diceResult)
			break;

		endnum input = cb_GetInput(board, diceResult);
		if (ShutTheBox::isMatch(input, diceResult))
		{
			for (size_t i = 0; i < input.size(); i++)
			{
				board.at(input.at(i) - 1) = false;
			}

			cb_DispRnd();
		}
	}

	return score;
}


endnum ShutTheBox::boardToNum(ShutBoard& brd, bool invert)
{
	std::vector<int> numOut;
	numOut.reserve(9);

	for (size_t i = 0; i < 9; i++)
	{
		if (invert)
		{
			if (brd.at(i) == false)
				numOut.push_back(i + 1);
		}
		else
		{
			if (brd.at(i) == true)
				numOut.push_back(i + 1);
		}
	}

	return numOut;
}