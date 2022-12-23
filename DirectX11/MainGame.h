#pragma once
class MainGame : public Scene
{
private:
	ObRect player;
	ObCircle pet;

	ObLine missile[10];

	int maxmissile;

	bool isFired;

public:
	~MainGame() override;
	//æ¿ √ ±‚»≠
	virtual void Init() override;
	//æ¿ ∞ªΩ≈
	virtual void Update() override;
	//æ¿ √‚∑¬
	virtual void Render() override;
};

