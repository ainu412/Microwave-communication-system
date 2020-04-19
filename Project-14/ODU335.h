#pragma once
#include "ODU.h"
class ODU335 : public ODU
{
public:
	ODU335(ODU_TYPE oduType = ODU_TYPE::ODU_TYPE_335);
	bool heartBeat() override;//重写虚函数时注意!名字是否相同!

	string name() override;
};