#include "pch.h"
#include "FilpbookActor.h"
#include "Flipbook.h"
#include "Sprite.h"
#include "TimeManager.h"
#include "Texture.h"
#include "SceneManager.h"

FilpbookActor::FilpbookActor()
{

}

FilpbookActor::~FilpbookActor()
{

}

void FilpbookActor::BeginPlay()
{
	Super::BeginPlay();
}

void FilpbookActor::Tick()
{
	Super::Tick();

	if (_flipbook == nullptr)
		return;

	const FlipbookInfo& info = _flipbook->GetInfo();
	if (info.loop == false && _idx == info.end)
		return;

	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	_sumTime += deltaTime;

	int32 frameCount = info.end - info.start + 1;
	float delta = info.duration / frameCount;

	if (_sumTime >= delta)
	{
		_sumTime = 0.f;
		_idx = (_idx + 1) % frameCount;
	}
}

void FilpbookActor::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_flipbook == nullptr)
		return;

	const FlipbookInfo& info = _flipbook->GetInfo();

	Vec2 cameraPos = GET_SINGLE(SceneManager)->GetCameraPos();

	::TransparentBlt(hdc, 
		(int32)_pos.x - info.size.x / 2 - ((int32)cameraPos.x - GWinSizeX / 2), 
		(int32)_pos.y - info.size.y / 2 - ((int32)cameraPos.y - GWinSizeY / 2),
		info.size.x, 
		info.size.y, 
		info.texture->GetDC(), 
		(info.start + _idx) * info.size.x, 
		info.line * info.size.y, 
		info.size.x, 
		info.size.y, 
		info.texture->GetTransparent());
}

void FilpbookActor::SetFlipbook(Flipbook* flipbook)
{
	if (flipbook && _flipbook == flipbook)
		return;

	_flipbook = flipbook;
	Reset();
}

void FilpbookActor::Reset()
{
	_sumTime = 0.f;
	_idx = 0;
}