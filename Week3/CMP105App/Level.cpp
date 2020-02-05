#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rect.setSize(sf::Vector2f(150, 210));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Magenta);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape)) {
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}
}

// Update game objects
void Level::update(float dt)
{
	rect.move(speed * dt, 0);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}