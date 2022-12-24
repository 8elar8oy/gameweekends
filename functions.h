#pragma once
#include "SFML/Graphics.hpp"
#include "Bat.h"
void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
void initBall(sf::CircleShape& ball, const sf::Vector2f ballPosition)
{
	ball.setRadius(BALL_RADIUS);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(ballPosition);
}
void initBat(Bat& bat)
{
	bat.shape.setSize(BAT_SIZE);
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(BAT_START_POS);
	bat.speedx = 0.f;
}
void controlBat(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf:: Keyboard::Left)) bat.speedx = -BAT_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) bat.speedx = BAT_SPEED;
	bat.shape.move(bat.speedx, 0.f);
	bat.speedx = 0.f;
}
void batReboundEdges(Bat& bat) {
	float batx = bat.shape.getPosition().x;
	float baty = bat.shape.getPosition().y;
	if (batx <= 0) bat.shape.setPosition(0.f, baty);
	if (batx >= WINDOW_WIDTH - LENGTH_BAT) bat.shape.setPosition(WINDOW_WIDTH - LENGTH_BAT, baty);
}
void updateGame(Bat& bat) {
	
	controlBat(bat);
	batReboundEdges(bat);
}
void checkCollisions() {}
void drawGame(sf::RenderWindow& window, Bat bat) {
	window.clear(sf::Color::Cyan);
	window.draw(bat.shape);
	window.display();
}
