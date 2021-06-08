#pragma once
#include "Header.h"

class Frame {
private:
	int init[N];
	int recv[N];
	int send[N];
	int tp;
	int dd[N + 2];
	int pd[N * 95];
	int ks[N];
	int ks1[N];
public:
	void Normal_Frame();
	void Err_Frame();
	void display();
	int get_recv();
	int get_send();
	bool check_init();
	bool check_summ();
};

class Frame_answ{
private:
	int init[N];
	int recv[N];
	int send[N];
	int tp;
	int co[N - 1];
	int ks[4];
public:
	void Normal_Frame();
	void Err_Frame();
	void display();
	int get_recv();
	int get_send();
	bool check_init();
};