#include "Poo.h"
#include "Graphics.h"

void Poo::Update()
{
	Position_X += Velocity_X;
	Position_Y += Velocity_Y;

	const int right = Position_X + Width;
	if (Position_X < 0)
	{
		Position_X = 0;
		Velocity_X = -Velocity_X;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		Position_X = (Graphics::ScreenWidth - 1) - Width; // screen width - 1 will be the valid last position of the screen.
		Velocity_X = -Velocity_X;
	}
	
	const int buttom = Position_Y + Height;
	if (Position_Y < 0)
	{
		Position_Y = 0;
		Velocity_Y = -Velocity_Y;
	}
	else if (buttom >= Graphics::ScreenHeight)
	{
		Position_Y = (Graphics::ScreenHeight - 1) - Height; // screen height - 1 will be the valid last position of the screen.
		Velocity_Y = -Velocity_Y;
	}

}

void Poo::ProcessConsumption(int dudeX, int dudeY, int dudeWidth, int dudeHeight)
{
	const int right0 = dudeX + dudeWidth;  // dude x position + dude icon width. Remember to count from top left corner.
	const int buttom0 = dudeY + dudeHeight;  // dude y position + dude icon height.
	const int right1 = Position_X + Width;  // poo x position + poo icon width.
	const int buttom1 = Position_Y + Height;  // poo y position + poo icon width.

	if (right0 >= Position_X &&    // test to see if dude and poo are overlapping.
		dudeX <= right1 &&
		buttom0 >= Position_Y &&
		dudeY <= buttom1)
	{
		Collected = true;
	}
}
