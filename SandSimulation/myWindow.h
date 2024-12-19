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
	const float sandLength = 5.0f;
	const float sandHeight = 5.0f;
	const float sandArea = 100.0f;

	//on Mouse pressed function
	void initSand(float DeltaTime);
	float dropTimer = 0.0f;
	const float dropInterval = 0.1f;

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
				sands[i].setPosition(this->sands[i].getPosition().x, 600.0f - 5.0f);
				this->onGround[i] = true;
			}

			for (int j = 0; j < sands.size(); j++)
			{
				if (i != j && !onGround[j] && sands[j].getGlobalBounds().intersects(sands[i].getGlobalBounds()))
				{
					
					sands[j].setPosition(sands[i].getPosition().x, sands[i].getPosition().y - 5.0f);
					this->onGround[j] = true;
					velocityY[j] = 0.0f;
				}

				if (i != j && !onGround[j] && sands[j].getGlobalBounds().intersects(sands[i].getGlobalBounds()))
				{
					sands[j].setPosition(sands[i].getPosition().x - 5.0f, sands[i].getPosition().y);
				}
			}

		}
	}
};

