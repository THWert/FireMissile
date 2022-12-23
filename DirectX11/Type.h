#pragma once

class Scene //추상클래스 인터페이스 interface
{
public:

	virtual ~Scene() {};

	//순수가상함수
	//씬 초기화
	virtual void Init() = 0;
	//씬 갱신
	virtual void Update() = 0;
	//씬 출력
	virtual void Render() = 0;
};

template <typename T>
class Singleton
{
public:
    virtual ~Singleton() {};
    static T* GetInstance()
    {
        static T* Instance = new T;
        return Instance;
    };
    void DeleteSingleton()
    {
        delete GetInstance();
    };
};

static float DirToRadian(Vector2 Dir)
{
    //만약 단위벡터가 아닐수도있으니까
    Dir.Normalize();
    float Seta;
    if (Dir.y < 0)
    {
        //          360.0*TORADIAN
        Seta = 2.0f * PI - acosf(Dir.x);
    }
    else
    {
        Seta = acosf(Dir.x);
    }
    return Seta;
}
