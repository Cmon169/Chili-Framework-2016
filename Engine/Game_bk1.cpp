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
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (inhibitRight) {

		} else {
			velocity_x = velocity_x + 1;
			inhibitRight = true;
		}		
	} else {
		inhibitRight = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (inhibitLeft) {

		} else {
			velocity_x = velocity_x - 1;
			inhibitLeft = true;
		}
	} else {
		inhibitLeft = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (inhibitUp) {

		} else {
			velocity_y = velocity_y - 1;
			inhibitUp = true;
		}
	} else {
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (inhibitDown) {

		} else {
			velocity_y = velocity_y + 1;
			inhibitDown = true;
		}
	} else {
		inhibitDown = false;
	}

	x = x + velocity_x;
	y = y + velocity_y;

	if (x + 5 >= gfx.ScreenWidth) {
		x = gfx.ScreenWidth - 6;
		velocity_x = 0;
	}

	if (-5 + x <= 0) {
		x = 6;
		velocity_x = 0;
	}
	
	if (y + 5 >= gfx.ScreenHeight) {
		y = gfx.ScreenHeight - 6;
		velocity_y = 0;
	}

	if (y - 5 <= 0) {
		y = 6;
		velocity_y = 0;
	}

	if (x >= 395 && x <= 405 && y >= 295 && y <= 305) {
		collision= true;
	} else {
		collision = false;
	}


	if ( wnd.kbd.KeyIsPressed(VK_CONTROL) || controlIsPressed || collision)	{
		gb = 0;
	} else {
		gb = 255;
	}

	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
}

void Game::ComposeFrame()
{
		
	/*gfx.PutPixel(395, 300, 255, 255, 255);
	gfx.PutPixel(396, 300, 255, 255, 255);
	gfx.PutPixel(397, 300, 255, 255, 255);
	gfx.PutPixel(403, 300, 255, 255, 255);
	gfx.PutPixel(404, 300, 255, 255, 255);
	gfx.PutPixel(405, 300, 255, 255, 255);
	gfx.PutPixel(400, 295, 255, 255, 255);
	gfx.PutPixel(400, 296, 255, 255, 255);
	gfx.PutPixel(400, 297, 255, 255, 255);
	gfx.PutPixel(400, 303, 255, 255, 255);
	gfx.PutPixel(400, 304, 255, 255, 255);
	gfx.PutPixel(400, 305, 255, 255, 255);*/

	// some arbitary location which is not good
	//gfx.PutPixel( 695 + dx, 500 + dy, 255, 255, 255);
	//gfx.PutPixel( 696 + dx, 500 + dy, 255, 255, 255);
	//gfx.PutPixel( 697 + dx, 500 + dy, 255, 255, 255);
	//gfx.PutPixel( 703 + dx, 500 + dy, 255, 255, 255);
	//gfx.PutPixel( 704 + dx, 500 + dy, 255, 255, 255);
	//gfx.PutPixel( 705 + dx, 500 + dy, 255, 255, 255);
	//gfx.PutPixel( 700 + dx, 495 + dy, 255, 255, 255);
	//gfx.PutPixel( 700 + dx, 496 + dy, 255, 255, 255);
	//gfx.PutPixel( 700 + dx, 497 + dy, 255, 255, 255);
	//gfx.PutPixel( 700 + dx, 503 + dy, 255, 255, 255);
	//gfx.PutPixel( 700 + dx, 504 + dy, 255, 255, 255);
	//gfx.PutPixel( 700 + dx, 505 + dy, 255, 255, 255);

	//const bool cond = wnd.kbd.KeyIsPressed( VK_UP );  // windows keyboard key is pressed, check for the up button

	// start at location (0,0), or top left corner
	
	/*if (controlIsPressed)
	{
		gb = 0;
	}
	else {
		gb = 255;
	}*/


	// fixed box
	gfx.PutPixel(395, 295, 255, gb, gb);
	gfx.PutPixel(395, 296, 255, gb, gb);
	gfx.PutPixel(395, 297, 255, gb, gb);
	gfx.PutPixel(396, 295, 255, gb, gb);
	gfx.PutPixel(397, 295, 255, gb, gb);
	gfx.PutPixel(395, 305, 255, gb, gb);
	gfx.PutPixel(395, 304, 255, gb, gb);
	gfx.PutPixel(395, 303, 255, gb, gb);
	gfx.PutPixel(396, 305, 255, gb, gb);
	gfx.PutPixel(397, 305, 255, gb, gb);
	gfx.PutPixel(405, 295, 255, gb, gb);
	gfx.PutPixel(405, 296, 255, gb, gb);
	gfx.PutPixel(405, 297, 255, gb, gb);
	gfx.PutPixel(404, 295, 255, gb, gb);
	gfx.PutPixel(403, 295, 255, gb, gb);
	gfx.PutPixel(405, 305, 255, gb, gb);
	gfx.PutPixel(405, 304, 255, gb, gb);
	gfx.PutPixel(405, 303, 255, gb, gb);
	gfx.PutPixel(404, 305, 255, gb, gb);
	gfx.PutPixel(403, 305, 255, gb, gb);

	// mobile cursor
	if ( shapeIsChanged ) {
		gfx.PutPixel(-5 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, -4 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, -3 + y, 255, gb, gb);
		gfx.PutPixel(-4 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(-3 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, 4 + y, 255, gb, gb);
		gfx.PutPixel(-5 + x, 3 + y, 255, gb, gb);
		gfx.PutPixel(-4 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(-3 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, -4 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, -3 + y, 255, gb, gb);
		gfx.PutPixel(4 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(3 + x, -5 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, 4 + y, 255, gb, gb);
		gfx.PutPixel(5 + x, 3 + y, 255, gb, gb);
		gfx.PutPixel(4 + x, 5 + y, 255, gb, gb);
		gfx.PutPixel(3 + x, 5 + y, 255, gb, gb);		
	} else {
		gfx.PutPixel(-5 + x, y, 255, gb, gb);
		gfx.PutPixel(-4 + x, y, 255, gb, gb);
		gfx.PutPixel(-3 + x, y, 255, gb, gb);
		gfx.PutPixel(3 + x, y, 255, gb, gb);
		gfx.PutPixel(4 + x, y, 255, gb, gb);
		gfx.PutPixel(5 + x, y, 255, gb, gb);
		gfx.PutPixel(x, -5 + y, 255, gb, gb);
		gfx.PutPixel(x, -4 + y, 255, gb, gb);
		gfx.PutPixel(x, -3 + y, 255, gb, gb);
		gfx.PutPixel(x, 3 + y, 255, gb, gb);
		gfx.PutPixel(x, 4 + y, 255, gb, gb);
		gfx.PutPixel(x, 5 + y, 255, gb, gb);
	}

	/*void Game::drawBox() {

		const int r_fixed = 0;
		const int g_fixed = 255;
		const int b_fixed = 0;

		gfx.PutPixel(-5 + x_fixed_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(-5 + x_fixed_fixed, -4 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(-5 + x_fixed_fixed, -3 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(-4 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(-3 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(-5 + x_fixed_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(-5 + x_fixed_fixed, 4 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(-5 + x_fixed_fixed, 3 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(-4 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(-3 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(5 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(5 + x_fixed, -4 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(5 + x_fixed, -3 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(4 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(3 + x_fixed, -5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(5 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(5 + x_fixed, 4 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(5 + x_fixed, 3 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(4 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);
		gfx.PutPixel(3 + x_fixed, 5 + y_fixed, r_fixed, g_fixed, b_fixed);

	}*/
}
