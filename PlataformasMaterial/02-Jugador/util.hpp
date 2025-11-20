#pragma once

struct Vector2i
{
	int x;
	int y;

	bool operator==(Vector2i const& obj)
	{
		return x == obj.x and y == obj.y;
	}
};