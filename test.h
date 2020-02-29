#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<string>
#include<iostream>

class test
{
private:
	int score;
	char name;
	sf::Vector2f position;
	int bulletcount;

public:

	test() :score(5), name('c'), position(4, 5), bulletcount(9) {}

	test(int s, char n, sf::Vector2f v1, int c) :score(s), name(n), position(v1), bulletcount(c)
	{}
	int getScore()
	{
		return score;
	}
	char getName()
	{
		return name;
	}
	sf::Vector2f getPosition()
	{
		return position;
	}
	int getBulletcount()
	{
		return bulletcount;
	}
	void setValues(int s, char n, sf::Vector2f v1, int c)
	{
		score = s;
		name = n;
		position = v1;
		bulletcount = c;
	}
	void display()
	{
		std::cout << "score of " << name << " is " << score <<std::endl;
		std::cout << "and is located at (" << position.x << "," << position.y << ") with " << bulletcount << "bullets\n" ;

	}
};

