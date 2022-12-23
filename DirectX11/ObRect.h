#pragma once
class ObRect : public GameObject
{
public:
	Vector2 vertex[4];

	ObRect();
	~ObRect() override;

	void Render() override;
};

