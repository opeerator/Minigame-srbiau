/* This is my implementation of shut the box game for OOP class at srbiau with Ms.zamani
 Author: Ali Yamini */

# include "gamecl.h"

// Meghdar dehi avalie baray callback ha va maghadir mojod darar bakhsh private
ShutTheBox::ShutTheBox(
	Newdisp& cbPrintBrd,
	InputFn& cbGetInput,
	DispRndFn& cbDispRnd,
	GetDiceAmt& cbGetDiceAmt,
	UpdateDice& cbDiceUpdate) : board{true, true, true, true, true, true, true, true, true}
{
	cb_printBoardState = cbPrintBrd;
	cb_GetInput = cbGetInput;
	cb_DispRnd = cbDispRnd;
	cb_GetDiceAmt = cbGetDiceAmt;
	cb_DiceUpdate = cbDiceUpdate;
	rng.seed(std::random_device()());
}

// tolid maghadir 1 ta 6 baraye tass
void ShutTheBox::rollDice(int diceToRoll)
{
	int tot{};

	for (size_t i = 0; i < diceToRoll; i++)
	{
		tot += dist(rng);
	}

	diceResult = tot;
}


// meghdar true agar majmoe maghadir dar vector be andaze dice val shavad
bool ShutTheBox::isMatch(endnum& choice, int diceVal)
{
	int total{};

	for (size_t i = 0; i < choice.size(); i++)
	{
		total += choice.at(i);
	}

	if (total == diceVal)
		return true;

	return false;
}

// agar harchizi bename v vared shavad mitavanad to sum jam shode va true bedahad
bool ShutTheBox::shouldContinue(endnum& v, int sum)
{
	const int MAX_ELEMENT = 100;
	const int MAX_ELEMENT_VALUE = 1000;
	// i think the memset below sets all the array values to 0
	static int dp[MAX_ELEMENT*MAX_ELEMENT_VALUE + 1]; memset(dp, 0, sizeof(dp));

	dp[0] = 1;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = MAX_ELEMENT*MAX_ELEMENT_VALUE; j >= 0; j--)
		{
			if (j - v.at(i) < 0) continue;
			if (dp[j - v.at(i)]) dp[j] = 1;
		}
	}

	return dp[sum] ? true : false;
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

	int score = calcScore();
	if (score == diceResult)
		score = 0;

	return score;
}

int ShutTheBox::calcScore()
{
	int score{};
	endnum scoreVec = boardToNum(board, false);

	for (size_t i = 0; i < scoreVec.size(); i++)
	{
		score += scoreVec.at(i);
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





