#include "stdafx.h"

using namespace std;

int Random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void FillVec(vector<int> &someVec, int size) {
	someVec.resize(size);

	for (int i = 0; i < someVec.size(); i++)
		someVec[i] = Random(1, 9);
}

void FillMap(map<int, int> &someMap, int size) {
	someMap.clear();

	for (int i = 0; i < size; i++)
		someMap.insert(pair<int, int>(i, Random(1, 9)));
	}

int DelFromVec(vector<int> &someVec) {		//��������� ��� ������� 1 �������
	int max, del;

	max = someVec.size() - 1; 
	if (max > 15)
		max = 15;

	del = Random(1, max);					//������� ����� �������

	for (int i = 0; i < del; i++)
		someVec.erase(someVec.begin() + Random(0, someVec.size() - 1));

	return del;
}

int DelFromMap(map<int, int> &someMap) {	//��������� ��� ������� 1 �������
	int max, del;

	max = someMap.size() - 1;
	if (max > 15)
		max = 15;

	del = Random(1, max);					//������� ����� �������

	for (int i = 0; i < del; i++) {
		auto it = someMap.begin();
		advance(it, Random(0, someMap.size() - 1));
		someMap.erase(it);
	}

	return del;
}

void Synch(vector<int> &someVec, map<int, int> &someMap) {
	int counter = 0;						//������� ��������� � ����� � ������ ����������; ����� ��� ����,
	bool flag = false;						//����� �������� ������������ �������� ���������� ���������

	auto it = someMap.begin();
	while (it != someMap.end()) {
		int j = 0;
		while (j < someVec.size() && !flag) {
			if (it->second == someVec[j]) {
				flag = true;
			}
			else {
				j++;
			}	
		}
		if (!flag){							//�������� �������� ��� ����
			someMap.erase(it);
			it = someMap.begin();
			advance(it, counter);			//���������� ��������
		}
		else {
			flag = false;
			counter++;						//���������� �������� ��� ���������� ������� ��������
			it++;
		}
	}
	counter = 0;
	flag = false;

	auto itVec = someVec.begin();
	while (itVec != someVec.end()) {
		auto it = someMap.begin();
		while (it != someMap.end() && !flag) {
			if (*itVec == it->second) {
				flag = true;
			}
			else {
				it++;
			}
		}
		if (!flag) {						//�������� �������� ��� ����
			someVec.erase(itVec);
			itVec = someVec.begin();
			advance(itVec, counter);		//���������� ��������
		}
		else {
			flag = false;
			counter++;						//���������� �������� ��� ���������� ������� ��������
			itVec++;
		}
	}
}
