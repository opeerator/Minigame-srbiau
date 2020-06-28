/* This is my implementation of shut the box game for OOP class at srbiau with Ms.zamani
 Author: Ali Yamini */


#pragma once
#include <random>
#include <vector>
#include <array>
#include <functional>

// Baraye rahat kardane kare namgozari callback va container ha

typedef std::vector<int> endnum;
typedef std::array<bool, 9> ShutTheBoard;
typedef std::function<endnum(ShutTheBoard& brd, int diceVal)> InputFn;
typedef std::function<void(ShutTheBoard& brd)> Newdisp;
typedef std::function<void()> DispRndFn;
typedef std::function<int()> GetDiceAmt;
typedef std::function<void(int)> UpdateDice;

class ShutTheBox
{
public:
	ShutTheBox(Newdisp& cbPrintBrd, InputFn& cbGetInput, DispRndFn& cbDispRnd, GetDiceAmt& cbGetDiceAmt, UpdateDice& cbDiceUpdate);
	~ShutTheBox();
	int Start();
	static endnum boardToNum(ShutTheBoard& brd, bool invert);
	static bool isMatch(endnum& choice, int diceVal);