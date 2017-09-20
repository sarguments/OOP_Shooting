#pragma once

class CTitleScene : public CScene
{
private:

public:
	CTitleScene();
	~CTitleScene();
	virtual void Update() override;
	virtual void Replace() override;
};