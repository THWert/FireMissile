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
	//�� �ʱ�ȭ
	virtual void Init() override;
	//�� ����
	virtual void Update() override;
	//�� ���
	virtual void Render() override;
};

