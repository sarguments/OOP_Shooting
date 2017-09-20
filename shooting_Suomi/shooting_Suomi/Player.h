#pragma once

class CPlayer : public CBase
{
private:

public:
	CPlayer();
	~CPlayer();

	virtual void Action() override;
	virtual void Draw() override;
};