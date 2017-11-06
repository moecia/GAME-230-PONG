#pragma once
#include "Entity.h"
using namespace sf;
using namespace std;
class Paddle : public Entity
{
public:
private:
	int plyarNum;
	float velocityControl = 5.0f;
};