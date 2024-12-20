#include "pch.h"
#include "Button.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Sprite.h"

Button::Button()
{
}

Button::~Button()
{
}

void Button::BeginPlay()
{
	Super::BeginPlay();

	SetButtonState(BS_Default);

	
}

void Button::Tick()
{
	Super::Tick();

	POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	if (_state == BS_Clicked)
	{
		_sumTime += deltaTime;
		if (_sumTime >= 0.2f)
		{
			_sumTime = 0.f;
			SetButtonState(BS_Default);
		}
	}

	if (IsMouesInRect())
	{
		if (GET_SINGLE(InputManager)->GetButtonPress(KeyType::LeftMouse))
		{
			SetButtonState(BS_Pressed);
		}
		else
		{
			if (_state == BS_Pressed)
			{
				SetButtonState(BS_Clicked);
				if (_onClick)
					_onClick();
			}
		}
	}
	else
	{
		SetButtonState(BS_Default);
	}
}

void Button::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_currentSprite)
	{
		::TransparentBlt(hdc,
			(int32)_pos.x - _size.x / 2,
			(int32)_pos.y - _size.y / 2,
			_size.x,
			_size.y,
			_currentSprite->GetDC(),
			_currentSprite->GetPos().x,
			_currentSprite->GetPos().y,
			_currentSprite->GetSize().x,
			_currentSprite->GetSize().y,
			_currentSprite->GetTransparent());
	}
	else
	{
		Utils::DrawRect(hdc, _pos, _size.x, _size.y);
	}
}

void Button::SetButtonState(ButtonState state)
{
	_state = state;

	if (_sprites[state])
		SetCurrentSprite(_sprites[state]);
}
