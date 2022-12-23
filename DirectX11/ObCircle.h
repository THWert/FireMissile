#pragma once
class ObCircle : public GameObject
{
public:
	Vector2 vertex[60];

	ObCircle();
	~ObCircle() override;

	void Render() override;
};

