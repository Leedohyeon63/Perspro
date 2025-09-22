#pragma once
class Battle
{
public:
	virtual ~Battle() {}
public:
	virtual void AppleyDamge(Battle* InTarget) = 0;
	virtual void Takedamge(int InDamge) = 0;
};

