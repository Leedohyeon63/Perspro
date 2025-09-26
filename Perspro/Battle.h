#pragma once
//기본적인 데미지와 피해를 가지는 클래스, 가상함수를 사용하여 객체가 직접 구현함
class Battle
{
public:
	virtual ~Battle() {}
public:
	virtual void AppleyDamge(Battle* InTarget) = 0;
	virtual void Takedamge(int InDamge) = 0;
};

