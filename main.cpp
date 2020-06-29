/* This is my implementation of shut the box game for OOP class at srbiau with Ms.zamani
 Author: Ali Yamini */

#include "gamecl.h"
#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>


// halghe asli
int main()
{
	try
	{

		GetDiceAmt di = getAmtOfDiceToRoll;
		UpdateDice dp = dicePrint;

		Newdisp pb = printBoard;
		InputFn gi = getInput;
		DispRndFn dr = dispRound;

        // Shoroe game
		ShutTheBox marhale1(pb, gi, dr, di, dp);
		std::cout << "Emtiaze shoma: " << marhale1.Start() << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Program: " << ex.what() << std::endl;
	}

	system("stop");
	return 0;
	return 0;
}