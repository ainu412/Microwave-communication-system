#include "ODU335.h"

ODU335::ODU335(ODU_TYPE oduType):ODU(oduType)
{
	cout << name() << __FUNCTION__ << endl;
	//txFreq = 33500;子类对象调用父类,可利用父类数据,无需自己再创建数据.直接将自己数据存至父类即可.子类的数据存在子类对象中
	//rxFreq = 33500;
	//txPower = 20;
	//rxLevel = 0;
}

bool ODU335::heartBeat()
{
	cout << __FUNCTION__ << endl;
	cout << name() << "模拟串口协议读取数据：获取心跳包的反馈..."
		<< "【" << ODU_TYPE_335_FLAG << "】" << endl;
	string response;
	cin >> response;

	if (ODU_TYPE_335_FLAG == response) {
		type = ODU_TYPE::ODU_TYPE_335;
		return true;
	}
	else {
		return false;
	}

	return false;
}

string ODU335::name()
{
	return ODU_TYPE_335_FLAG;
}
