#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<string>
#include"test.h"
class Networking
{
private:
	sf::IpAddress ip;
	sf::TcpSocket socket;
	sf::Packet pack;
	char connectionType{};


public:
	Networking()
	{
		ip = sf::IpAddress::getLocalAddress();
		setServer();
	}
	void setServer()
	{
		std::string text = "Connected to:";
		std::cout << "Enter (S) for Server , Enter(C)for client:" << std::endl;
		std::cin >> connectionType;

		if (connectionType == 'S' || connectionType == 's')
		{
			sf::TcpListener listener;
			listener.listen(2000);
			if (listener.accept(socket) != sf::Socket::Done)
			{
				std::cerr << "Error while connecting:";

			}
			text += "Server\n";
			std::cout << text;
		}
		if (connectionType == 'C' || connectionType == 'c')
		{
			socket.connect(ip, 2000);
			text += "Client\n";
			std::cout << text;
		}

	}
	bool isServer()
	{
		if (connectionType == 's' || connectionType == 'S')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isClient()
	{
		if (connectionType == 'c' || connectionType == 'C')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void sendData(std::string sender)
	{
		pack << sender;
		socket.send(pack);
	}
	void sendData(int sender)
	{
		pack << sender;
		socket.send(pack);
	}
	void sendData(float sender)
	{
		pack << sender;
		socket.send(pack);
	}
	void sendData(sf::Vector2f sender)
	{
		pack << sender.x<<sender.y;
		socket.send(pack);
	}
	void sendData(test player) {
		char h = player.getName();
		pack << &h << player.getScore() << player.getPosition().x
			<< player.getPosition().y << player.getBulletcount();
		socket.send(pack);
	}
	test getPlayerData() {
		socket.receive(pack);
		int s, b;
		sf::Vector2f v1;
		char n;
		pack >> &n >> s >> v1.x >> v1.y >> b;
		return test(s, n, v1, b);
	}
	std::string getStringdata()
	{
		socket.receive(pack);
		//pack.getData();
		std::string getdata;
		pack >> getdata;
		return getdata;
	}
	int getIntdata()
	{
		socket.receive(pack);
		//pack.getData();
		int getdata;
		pack >> getdata;
		//std::cout << getdata;
		return getdata;
	}
	float getFloatdata()
	{
		socket.receive(pack);
		//pack.getData();
		float getdata;
		pack >> getdata;
		return getdata;
	}
	sf::Vector2f getVectordata()
	{
		float x1, y1;
		socket.receive(pack);
		//pack.getData();
		pack >> x1>>y1;
		return sf::Vector2f(x1, y1);
	}

	sf::Packet getData()
	{
		socket.receive(pack);
		return pack;
	}
};
	






