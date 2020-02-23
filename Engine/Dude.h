#pragma once

class Dude
{
public :

	void ClampToScreen();
	int Position_X = 400;  // Character position
	int Position_Y = 300;
	int Velocity_X;
	int Velocity_Y;

	static constexpr int Width = 20;
	static constexpr int Height = 20;
};