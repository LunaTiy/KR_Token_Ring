#include "Frame.h"

void Frame::Normal_Frame() {
	//Инициализация начала кадра
	this->init[0] = 0;
	this->init[1] = 1;
	this->init[2] = 1;
	this->init[3] = 1;
	this->init[4] = 1;
	this->init[5] = 1;
	this->init[6] = 1;
	this->init[7] = 0;

	//Адрес получателя
	this->recv[0] = 0;
	this->recv[1] = 0;
	this->recv[2] = 1;
	this->recv[3] = 1;
	this->recv[4] = 1;
	this->recv[5] = 1;
	this->recv[6] = 0;
	this->recv[7] = 0;

	//Адрес отправителя
	this->send[0] = 0;
	this->send[1] = 1;
	this->send[2] = 1;
	this->send[3] = 0;
	this->send[4] = 0;
	this->send[5] = 0;
	this->send[6] = 1;
	this->send[7] = 0;

	//Тип пакета
	this->tp = 0;

	//Длина данных
	this->dd[0] = 1;
	for (int i = 1; i < N +2; i++)
		this->dd[i] = 0;

	//Поле данных
	this->pd[0] = 1;
	for (int i = 1; i < N * 95; i++)
		this->pd[i] = 0;

	//Подсчет контрольной суммы
	for (int i = 0; i < N; i++)
		this->ks[i] = 0;

	for (int i = 0; i < N; i++) 
		this->ks[0] += this->recv[i];	
	this->ks[0] = this->ks[0] % 2;

	for (int i = 0; i < N; i++) 
		this->ks[1] += this->send[i];	
	this->ks[1] = this->ks[1] % 2;

	this->ks[2] += this->tp;

	for (int i = 0; i < N + 2; i++) 
		this->ks[3] += this->dd[i];	
	this->ks[3] = this->ks[3] % 2;

	for (int i = 0; i < N * 95; i++)
		this->ks[4] += this->pd[i];
	this->ks[4] = this->ks[4] % 2;

	for (int i = 0; i < N; i++)
		this->ks1[i] = this->ks[i];
}

void Frame::Err_Frame() {
	//Инициализация начала кадра
	this->init[0] = 0;
	this->init[1] = 1;
	this->init[2] = 1;
	this->init[3] = 1;
	this->init[4] = 1;
	this->init[5] = 1;
	this->init[6] = 1;
	this->init[7] = 0;

	//Адрес получателя
	this->recv[0] = 0;
	this->recv[1] = 0;
	this->recv[2] = 1;
	this->recv[3] = 1;
	this->recv[4] = 1;
	this->recv[5] = 1;
	this->recv[6] = 0;
	this->recv[7] = 0;

	//Адрес отправителя
	this->send[0] = 0;
	this->send[1] = 1;
	this->send[2] = 1;
	this->send[3] = 0;
	this->send[4] = 0;
	this->send[5] = 0;
	this->send[6] = 1;
	this->send[7] = 0;

	//Тип пакета
	this->tp = 0;

	//Длина данных
	this->dd[0] = 1;
	for (int i = 1; i < N + 2; i++)
		this->dd[i] = 0;

	//Поле данных
	this->pd[0] = 1;
	this->pd[1] = 1;
	for (int i = 2; i < N * 95; i++)
		this->pd[i] = 0;

	//Подсчет контрольной суммы
	for (int i = 0; i < N; i++)
		this->ks[i] = 0;

	for (int i = 0; i < N; i++)
		this->ks[0] += this->recv[i];
	this->ks[0] = this->ks[0] % 2;

	for (int i = 0; i < N; i++)
		this->ks[1] += this->send[i];
	this->ks[1] = this->ks[1] % 2;

	this->ks[2] += this->tp;

	for (int i = 0; i < N + 2; i++)
		this->ks[3] += this->dd[i];
	this->ks[3] = this->ks[3] % 2;

	for (int i = 0; i < N * 95; i++)
		this->ks[4] += this->pd[i];
	this->ks[4] = this->ks[4] % 2;

	for (int i = 0; i < N; i++)
		this->ks1[i] = this->ks[i];

	this->ks1[4] = 1;
}

void Frame::display() {
	cout << "Frame:\n1. Init: ";
	for (int i = N - 1; i >= 0; i--) 
		cout << this->init[i];
	

	cout << "\n2. Receive: ";
	for (int i = N - 1; i >= 0; i--) 
		cout << this->recv[i];
	

	cout << "\n3. Send: ";
	for (int i = N - 1; i >= 0; i--) 
		cout << this->send[i];
	

	cout << "\n4. Type of frame: ";
	cout << this->tp;

	cout << "\n5. Lenght of data: ";
	for (int i = N + 1; i >= 0; i--)
		cout << this->dd[i];
	
	cout << "\n6. Data: ";
	for (int i = N * 95 - 1; i >= 0; i--)
		cout << this->pd[i];

	cout << "\n7. Kontrol summ: ";
	for (int i = N - 1; i >= 0; i--)
		cout << this->ks[i];

	cout << endl;
}

int Frame::get_recv() {
	int number = 0;
	for (int i = 0; i < N; i++) 
		number += this->recv[i] * pow(2, i);
	
	return number;
}

int Frame::get_send() {
	int number = 0;
	for (int i = 0; i < N; i++)
		number += this->send[i] * pow(2, i);

	return number;
}

bool Frame::check_init() {
	bool flag = true;
	if (this->init[0] == 0) {
		if (this->init[N - 1] == 0) {
			for (int i = 1; i < N - 1; i++) {
				if (this->init[i] != 1)
					flag = false;
			}
		}
		else
			flag = false;
	}
	else
		flag = false;

	return flag;
}

bool Frame::check_summ() {
	bool flag = true;
	for (int i = 0; i < N; i++) {
		if (this->ks[i] == this->ks1[i])
			flag = true;
		else {
			flag = false;
			break;
		}
	}
	return flag;
}

void Frame_answ::Normal_Frame() {
	//Инициализация начала кадра
	this->init[0] = 0;
	this->init[1] = 1;
	this->init[2] = 1;
	this->init[3] = 1;
	this->init[4] = 1;
	this->init[5] = 1;
	this->init[6] = 1;
	this->init[7] = 0;

	//Адрес отправителя
	this->send[0] = 0;
	this->send[1] = 0;
	this->send[2] = 1;
	this->send[3] = 1;
	this->send[4] = 1;
	this->send[5] = 1;
	this->send[6] = 0;
	this->send[7] = 0;

	//Адрес получателя
	this->recv[0] = 0;
	this->recv[1] = 1;
	this->recv[2] = 1;
	this->recv[3] = 0;
	this->recv[4] = 0;
	this->recv[5] = 0;
	this->recv[6] = 1;
	this->recv[7] = 0;

	//Тип пакета
	this->tp = 1;

	//Код ошибки
	for (int i = 0; i < N - 1; i++)
		this->co[i] = 1;

	//Подсчет контрольной суммы
	for (int i = 0; i < 4; i++)
		this->ks[i] = 0;

	for (int i = 0; i < N; i++)
		this->ks[0] += this->recv[i];
	this->ks[0] = this->ks[0] % 2;

	for (int i = 0; i < N; i++)
		this->ks[1] += this->send[i];
	this->ks[1] = this->ks[1] % 2;

	this->ks[2] += this->tp;
}

void Frame_answ::Err_Frame() {
	//Инициализация начала кадра
	this->init[0] = 0;
	this->init[1] = 1;
	this->init[2] = 1;
	this->init[3] = 1;
	this->init[4] = 1;
	this->init[5] = 1;
	this->init[6] = 1;
	this->init[7] = 0;

	//Адрес отправителя
	this->send[0] = 0;
	this->send[1] = 0;
	this->send[2] = 1;
	this->send[3] = 1;
	this->send[4] = 1;
	this->send[5] = 1;
	this->send[6] = 0;
	this->send[7] = 0;

	//Адрес получателя
	this->recv[0] = 0;
	this->recv[1] = 1;
	this->recv[2] = 1;
	this->recv[3] = 0;
	this->recv[4] = 0;
	this->recv[5] = 0;
	this->recv[6] = 1;
	this->recv[7] = 0;

	//Тип пакета
	this->tp = 1;

	//Код ошибки
	this->co[0] = 1;
	this->co[1] = 1;
	for (int i = 2; i < N - 1; i++)
		this->co[i] = 0;

	//Подсчет контрольной суммы
	for (int i = 0; i < 4; i++)
		this->ks[i] = 0;

	for (int i = 0; i < N; i++)
		this->ks[0] += this->recv[i];
	this->ks[0] = this->ks[0] % 2;

	for (int i = 0; i < N; i++)
		this->ks[1] += this->send[i];
	this->ks[1] = this->ks[1] % 2;

	this->ks[2] += this->tp;
}

void Frame_answ::display() {
	cout << "Frame_answ:\n1. Init: ";
	for (int i = N - 1; i >= 0; i--)
		cout << this->init[i];


	cout << "\n2. Receive: ";
	for (int i = N - 1; i >= 0; i--)
		cout << this->recv[i];


	cout << "\n3. Send: ";
	for (int i = N - 1; i >= 0; i--)
		cout << this->send[i];


	cout << "\n4. Type of frame: ";
	cout << this->tp;

	cout << "\n5. Code of error: ";
	for (int i = 6; i >= 0; i--)
		cout << this->co[i];

	cout << "\n6. Kontrol summ: ";
	for (int i = 3; i >= 0; i--)
		cout << this->ks[i];

	cout << endl;
}

int Frame_answ::get_recv() {
	int number = 0;
	for (int i = 0; i < N; i++)
		number += this->recv[i] * pow(2, i);

	return number;
}

int Frame_answ::get_send() {
	int number = 0;
	for (int i = 0; i < N; i++)
		number += this->send[i] * pow(2, i);

	return number;
}

bool Frame_answ::check_init() {
	bool flag = true;
	if (this->init[0] == 0) {
		if (this->init[N - 1] == 0) {
			for (int i = 1; i < N - 1; i++) {
				if (this->init[i] != 1)
					flag = false;
			}
		}
		else
			flag = false;
	}
	else
		flag = false;

	return flag;
}