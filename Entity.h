#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;
class Entity : public Sprite
{
public:
	Entity()
	{
		this->texture = new Texture();
	}
	void Load(string filename)
	{
		this->texture->loadFromFile("Images/" + filename);
		this->setTexture(*this->texture);
	}

	bool CheckCollision(Entity* entity)
	{
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}

	~Entity()
	{
		delete this->texture;
	}
private:
	Texture* texture;
};