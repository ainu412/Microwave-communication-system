#include "ODU.h"
#include "ODU335.h"
#include <Windows.h>
#include <thread>
void test(ODU& odu, int n) {
	odu.setRxFreq(n);
	cout << odu.getRxFreq() << endl;
}
ODU* odu = NULL;//ȫ�ֱ��������ں����ڲ�ʹ�ò���,��ʹ��
void oduMonitorHandler() {
	while (1) {
		if ( odu->heartBeat() == false) {//ֻҪ�����Ϊ�����Ӧ��,�ͻ᷵��false,�ʰ����豸�������331Ҳ������335״��
			switch (odu->type) {
			case ODU_TYPE::ODU_TYPE_331:
				//odu->type = ODU_TYPE::ODU_TYPE_335;
				delete odu;
				odu = new ODU335;
				break;
			case ODU_TYPE::ODU_TYPE_335:
				//odu->type = ODU_TYPE::ODU_TYPE_331;
				delete odu;
				odu = new ODU;
				break;
				//default:
				//	odu = NULL;
				//	return;
			}
		}
		Sleep(1000);
	}
}
int main() {
	ODU odu331;
	ODU335 odu335;

	test(odu331, 1000);
	test(odu335, 5000);
	//���Ϸ�������������һ������������ӦΪfalseֹͣ������һ������������������һ���Ͳ�������һ���͵�������
	//��ֻ���ͻ�ԾODU��������������������һ����
	//ODU* odu = new ODU;//�ǵò�Ҫ�ض���
	odu = new ODU;
	odu = &odu331;//�ǵ��ȷ���ֵ,��ȻoduΪ��
	//���ľ�Windows�̣߳�������Linux�߳�
	//���߳�-ͬʱ�������
	//�����߳�,��ODU�����������
	// ����һ���̣߳����ڶ�ODU���м��
	std::thread oduMonitor(oduMonitorHandler);

	// ���̵߳ȴ��߳�oduMonitor�Ľ���
	oduMonitor.join();


	return 0;
}
//
//#include <iostream>
//#include <Windows.h>
//#include <thread>
//#include "ODU.h"
//#include "ODU335.h"
//class ODU;
//using namespace std;
//
//ODU* odu = NULL;
//
//void oduMonitorHandler() {
//	while (1) {
//		if (odu->heartBeat() == false) {
//			// �л�ODU
//			ODU_TYPE type = odu->type;
//			switch (type) {
//			case ODU_TYPE::ODU_TYPE_331:
//				delete odu;
//				odu = new ODU335;
//				break;
//			case ODU_TYPE::ODU_TYPE_335:
//				delete odu;
//				odu = new ODU;
//				break;
//			default:
//				odu = NULL;
//				return;
//			}
//		}
//
//		Sleep(3000);
//	}
//}
//
//int main(void) {
//	odu = new ODU();
//
//	// ����һ���̣߳����ڶ�ODU���м��
//	std::thread oduMonitor(oduMonitorHandler);
//
//	// ���̵߳ȴ��߳�oduMonitor�Ľ���
//	oduMonitor.join();
//
//	return 0;
//}