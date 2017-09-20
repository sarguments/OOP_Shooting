#pragma once

class CScene
{
private:
	
public:
	virtual void Update() = 0;
	virtual void Replace() = 0;
};

/*

씬 업데이트
전후에 바뀔 씬이 있으면 기존 씬 지우고, 새로운 씬 동적 생성

씬 교체
다음에 바뀔 씬만 지정

*/