#pragma once

class CEnemy : public CBase
{
private:

public:
	CEnemy();
	~CEnemy();

	virtual void Action() override;
	virtual void Draw() override;
};