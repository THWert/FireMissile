#pragma once
class ObLine; //���漱��

class GameObject
{
private:
	static ObLine* axis;

	//static member function
public:
	static void CreateStaticMember();
	static void DeleteStaticMember();

	//member
private:
	Matrix		S, R, T, R2, RT;
	Matrix*		P;
	Vector2		position;

protected:
	Matrix		W;

public:
	Vector2		scale;
	float		rotation;
	float		revolution;
	bool		isAxis;

	//member function
public:
	GameObject();
	virtual ~GameObject();

	//�����Լ�
	//�ڽ��� ������ �� ���̶�� ����� �� ���
	virtual void Update();
	virtual void Render();

public:
	//getter setter
	Vector2 GetRight()
	{
		return Vector2(RT._11, RT._12);
	}
	Vector2 GetDown()
	{
		return Vector2(RT._21, RT._22);
	}
	Vector2 GetLocalPos()
	{
		return position;
	}	
	Vector2 GetWorldPos()
	{
		if (!P)
		{
			return position;
		}

		return Vector2(RT._41, RT._42);
	}
	//�̵���ų�� +=
	void MoveLocalPos(Vector2 Velocity)
	{
		position += Velocity;
	}
	void MoveWorldPos(Vector2 Velocity)
	{
		if (!P)
		{
			position += Velocity;
		}
		else
		{
			//								(x, y, z, 0)
			Vector2 locVelocity = Vector2::TransformNormal(Velocity, (*P).Invert());
			position += locVelocity;
		}
	}
	//��ġ�� �����Ҷ� =
	void SetLocalPos(Vector2 localpos)
	{
		position = localpos;
	}
	void SetWorldPos(Vector2 worldPos)
	{
		if (!P)
		{
			position = worldPos;
		}
		else
		{
			//							(x, y, z, 1)
			Vector2 localpos = Vector2::Transform(worldPos, (*P).Invert());
			position = localpos;
		}
	}
	void SetParentRT(GameObject& src)
	{
		P = &src.RT;
	}
};

