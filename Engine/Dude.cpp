#include "Dude.h"
#include "Graphics.h"

void Dude::ClampToScreen()
{
	const int right = Position_X + Width;
	if (Position_X < 0)
	{
		Position_X = 0;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		Position_X = (Graphics::ScreenWidth - 1) - Width; // screen width - 1 will be the valid last position of the screen.
	}
	
	const int buttom = Position_Y + Height;
	if (Position_Y < 0)
	{
		Position_Y = 0;
	}
	else if (buttom >= Graphics::ScreenHeight)
	{
		Position_Y = (Graphics::ScreenHeight - 1) - Height; // screen height - 1 will be the valid last position of the screen.
	}
}
