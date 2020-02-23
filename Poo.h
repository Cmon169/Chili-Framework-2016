#pragma once

class Poo
// Members of the class is default as private.  Need to address which members are public. 
{
public :
	void Update();
	void ProcessConsumption(int dudeX, int dudeY, int dudeWidth, int dudeHeight);
	int Position_X;  // collect object 1 position
	int Position_Y;
	int Velocity_X;
	int Velocity_Y;

	// Instead of having separate values in each class, Static will share the same variable by every object of Poo. No redundency.
	// Constexpr means the value is not going to change, and the value will be known during the time of compiling. That is a head of time and not during the code is running.
	// Only if you want to initialize it in a class. Initialing the variable without it the complier will complain.
	// Constexpr is different from the normal Const is the value declared Constexpr WILL NEVER CHANGE. Const on the other hand will be initialized and stay
	// when it gets to the line of code, but it may have a different value when the line is being revisited. Value in first loop could be different from the 2nd loop.
	static constexpr int Width = 24;
	static constexpr int Height = 24;
	bool Collected = false; // collect object 1 check
};