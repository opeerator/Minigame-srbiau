/* This is my implementation of shut the box game for OOP class at srbiau with Ms.zamani
 Author: Ali Yamini */


#pragma once
#include <random>
#include <vector>
#include <array>
#include <functional>

typedef std::array<bool, 9> ShutBoard;
typedef std::vector<int> ShutNum;
typedef std::function<void(ShutBoard& brd)> DispBrdFn;
typedef std::function<ShutNum(ShutBoard& brd, int diceVal)> InputFn;
typedef std::function<void()> DispRndFn;
typedef std::function<int()> GetDiceAmt;
typedef std::function<void(int)> UpdateDice;