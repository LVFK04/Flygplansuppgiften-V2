#pragma once
class Data
{
public:
	Data(){}
	~Data(){}
	virtual bool tick() = 0;
	virtual void info() = 0;
};

