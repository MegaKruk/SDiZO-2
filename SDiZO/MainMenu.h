#pragma once

#include <iostream>
using namespace std;

class MainMenu
{
private:
	bool atBeginning = true;

public:
	MainMenu();
	int menuFunction();
	~MainMenu();
};

