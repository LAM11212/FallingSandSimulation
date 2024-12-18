#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <random>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class myWindow
{

private:

	//Window settings
	sf::RenderWindow* window;
	sf::VideoMode videomode;
	sf::Event event;

	//sand initialization
	std::vector<sf::RectangleShape> sands;
	std::vector<bool> onGround;
	std::vector<float> velocityY;

	//on runtime functions
	void initVars();
	void initWindow();

	//constants
	const float gravity = 980.0f;

	//on Mouse pressed function
	void initSand();

public:
	myWindow();
	virtual ~myWindow();
	const bool running() const;

	//window functions
	void pollEvents();
	void update();
	void render();

	void updateSand(float deltaTime)
	{
		for (int i = 0; i < this->sands.size(); i++)
		{
			if (!this->onGround[i])
			{
				this->velocityY[i] += gravity * deltaTime;
				this->sands[i].move(0.0f, this->velocityY[i] * deltaTime);
			}

			if (sands[i].getPosition().y >= 600.0f)
			{
				sands[i].setPosition(this->sands[i].getPosition().x, 600.0f - 10.0f);
				this->onGround[i] = true;
			}
		}
	}
};

