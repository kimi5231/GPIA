#pragma once
class UI
{
public:
	UI();
	virtual ~UI();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render(HDC hdc);

	void SetSize(Vec2Int size) { _size = size; }
	void SetPos(Vec2 pos) { _pos = pos;}
	Vec2 GetPos() { return _pos;}

	RECT GetRect();
	bool IsMouesInRect();

protected:
	Vec2 _pos = { 400, 300 };
	Vec2Int _size = { 150, 150 };
};

