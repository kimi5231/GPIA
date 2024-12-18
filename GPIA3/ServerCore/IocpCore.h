#pragma once

class IocpObject
{
public:
	virtual ~IocpObject();

	virtual HANDLE GetHandle() abstract;
	virtual void Dispatch(struct IocpEvent* iocpEvent, int32 numOfBytes = 0) abstract;
};

class IocpCore
{
public:
	IocpCore();
	~IocpCore();

	HANDLE		GetHandle() { return _iocpHandle; }

	bool		Register(class IocpObject* iocpObject);
	bool		Dispatch(uint32 timeoutMs = INFINITE);

private:
	HANDLE		_iocpHandle;
};

extern IocpCore GIocpCore;