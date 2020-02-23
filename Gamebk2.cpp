/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	// check right arrow key compressed and change variable x location.
	{
		x_mobile = x_mobile + 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT)) 
	// check left arrow key compressed and change variable x location.
	{
		x_mobile = x_mobile - 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) 
	// check down arrow key compressed and change variable y location.
	{
		y_mobile = y_mobile + 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP)) 
	// check up arrow key compressed and change variable y location.
	{
		y_mobile = y_mobile - 1;
	}

	// pass moving box location to check for exceeding window boundaries
	x_mobile = ClampScreenX(x_mobile);
	y_mobile = ClampScreenY(y_mobile);

	// test boxes collision and assign result to variable colliding
	colliding = 
		OverlapTest(x_fixed0, y_fixed0, x_mobile, y_mobile) ||
		OverlapTest(x_fixed1, y_fixed1, x_mobile, y_mobile) ||
		OverlapTest(x_fixed2, y_fixed2, x_mobile, y_mobile) ||
		OverlapTest(x_fixed3, y_fixed3, x_mobile, y_mobile);
}

void Game::ComposeFrame()
{
	
	DrawBox(x_fixed0, y_fixed0, 0, 255, 0);
	DrawBox(x_fixed1, y_fixed1, 0, 255, 0);
	DrawBox(x_fixed2, y_fixed2, 0, 255, 0);
	DrawBox(x_fixed3, y_fixed3, 0, 255, 0);

	if (colliding)
	// Draw a mobile box. If not colliding mobile box will be white. If collides mobile box will be red.
	{
		DrawBox(x_mobile, y_mobile, 255, 0, 0);
	}
	else 
	{
		DrawBox(x_mobile, y_mobile, 255, 255, 255);
	}
}

void Game::DrawBox(int x, int y, int r, int g, int b)  
// Draw box function that will accept the coordinates x and y, and also color RGB values.
{
	gfx.PutPixel(-5 + x, -5 + y, r, g, b);
	gfx.PutPixel(-5 + x, -4 + y, r, g, b);
	gfx.PutPixel(-5 + x, -3 + y, r, g, b);
	gfx.PutPixel(-4 + x, -5 + y, r, g, b);
	gfx.PutPixel(-3 + x, -5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 5 + y, r, g, b);
	gfx.PutPixel(-5 + x, 4 + y, r, g, b);
	gfx.PutPixel(-5 + x, 3 + y, r, g, b);
	gfx.PutPixel(-4 + x, 5 + y, r, g, b);
	gfx.PutPixel(-3 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, -4 + y, r, g, b);
	gfx.PutPixel(5 + x, -3 + y, r, g, b);
	gfx.PutPixel(4 + x, -5 + y, r, g, b);
	gfx.PutPixel(3 + x, -5 + y, r, g, b);
	gfx.PutPixel(5 + x, 5 + y, r, g, b);
	gfx.PutPixel(5 + x, 4 + y, r, g, b);
	gfx.PutPixel(5 + x, 3 + y, r, g, b);
	gfx.PutPixel(4 + x, 5 + y, r, g, b);
	gfx.PutPixel(3 + x, 5 + y, r, g, b);

}

bool Game::OverlapTest(int box0x, int box0y, int box1x, int box1y)
{
	// area of the mobile box
	const int leftbox0 = box0x - 5;
	const int rightbox0 = box0x + 5;
	const int topbox0 = box0y - 5;
	const int bottombox0 = box0y + 5;

	// area of the fixed box
	const int leftbox1 = box1x - 5;
	const int rightbox1 = box1x + 5;
	const int topbox1 = box1y - 5;
	const int bottombox1 = box1y + 5;

	// check boxes collision and return booleen value. No need to use the if statement!!
	return
		leftbox0 <= rightbox1 &&
		rightbox0 >= leftbox1 &&
		topbox0 <= bottombox1 &&
		bottombox0 >= topbox1;
}

int Game::ClampScreenX(int currentPositionX)
{
	const int leftScreenBorder = currentPositionX - 5;
	const int rightScreenBorder = currentPositionX + 5;

	if (leftScreenBorder < 0)
	{
		return 5;
	}
	else if(rightScreenBorder >= gfx.ScreenWidth)
	{
		return gfx.ScreenWidth - 6;
	}
	else
	{
		return currentPositionX;
	}
}

int Game::ClampScreenY(int currentPositionY)
{
	const int topScreenBorder = currentPositionY - 5;
	const int buttomScreenBorder = currentPositionY + 5;

	if (topScreenBorder < 0)
	{
		return 5;
	}
	else if (buttomScreenBorder >= gfx.ScreenHeight)
	{
		return gfx.ScreenHeight - 6;
	}
	else
	{
		return currentPositionY;
	}
}
