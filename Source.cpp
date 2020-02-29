
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<string>
#include<iostream>
#include"Networking.h"
#include "Source.h"
#include"test.h"

int main()
{
	Networking net;
	//float a = 5.0;
	//int b = 2;
	sf::Vector2f v(4,5);
	test player(4,'k',v,5);
	//player.display();
	//int g=player.getBulletcount();
	if (net.isServer())
	{
		//net.sendData("\n kriti is a client");
		//net.sendData(b);
		net.sendData(player);
	}
	if (net.isClient())
	{
		//std::string s = net.getStringdata();
		//int d = net.getIntdata();
		//float f = net.getFloatdata();
		//net.getIntdata();
		test p = net.getPlayerData();
		//std::cout << d << "\n" << s << "\n" << f;
		p.display();
	}

	

	system("pause");
    return 0;
}
