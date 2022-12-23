#pragma once
class ObLine : public GameObject
{
public:
	Vector2 vertex[2];

	ObLine();
	~ObLine() override;

	void Render() override;
};

