#pragma once

class CEndScene: public CScene
{
private:

public:
	CEndScene();
	~CEndScene();
	virtual void Update() override;
	virtual void Replace() override;
};