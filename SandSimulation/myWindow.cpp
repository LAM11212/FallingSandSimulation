#include "myWindow.h"

void myWindow::initVars()
{
	this->window = nullptr;
}

void myWindow::initWindow()
{
	this->videomode.height = 600;
	this->videomode.width = 800;
	this->window = new sf::RenderWindow(this->videomode, "Falling Sand", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void myWindow::initSand(float deltaTime)
{
	this->dropTimer += deltaTime;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && dropTimer >= dropInterval)
	{
		sf::RectangleShape sand(sf::Vector2f(this->sandLength, this->sandHeight));
		sand.setPosition(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y);
		sand.setFillColor(sf::Color::Yellow);
		this->sands.push_back(sand);
		this->onGround.push_back(false);
		this->velocityY.push_back(0.0f);
		this->dropTimer = 0.0f;
	}
}

myWindow::myWindow()
{
	this->initVars();
	this->initWindow();
}

myWindow::~myWindow()
{
	delete this->window;
}

const bool myWindow::running() const
{
	return this->window->isOpen();
}

void myWindow::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}

	}
}

void myWindow::update()
{
	this->pollEvents();

	//DELTA TIME CLOCK
	static sf::Clock clock;
	float deltaTime = clock.restart().asSeconds();

	this->updateSand(deltaTime);
	this->initSand(deltaTime);
}

void myWindow::render()
{
	this->window->clear();

	for (const auto& x : sands)
	{
		this->window->draw(x);
	}

	this->window->display();
}