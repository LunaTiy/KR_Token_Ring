#include "Frame.h"

int main(int argc, char* argv[]) {
	Frame frame;
	Frame_answ frame_answ;
	int action, number_r, number_s;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "Select action:\n1. Send normal frame\n2. Send frame with error\n3. Exit\n";
		cin >> action;

		switch (action) {
		case 1:
			system("cls");
			frame.Normal_Frame();
			number_r = frame.get_recv();
			number_s = frame.get_send();
			for (int i = 0; i < M; i++) {
				if (frame.check_init()) {
					if (i == number_r) {
						if (frame.check_summ()) {
							cout << "I am station number " << number_r << ". I receive frame from station number " << number_s << ":\n";
							frame.display();
							cout << "------------\n";

							frame_answ.Normal_Frame();
							number_r = frame_answ.get_recv();
							number_s = frame_answ.get_send();
							for (int j = 0; j < M + 1; j++) {
								if (frame_answ.check_init()) {
									if (j == number_r) {
										cout << "I am station number " << number_r << ". I receive frame_answ from station number " << number_s << ":\n";
										frame_answ.display();										
									}
								}
								else {
									cout << "Error in init of Frame!!!\n";
									break;
								}
							}
						}
						else {
							cout << "Error in check summ of Frame!!!\n";
							break;
						}
					}
				}
				else {
					cout << "Error in init of Frame!!!\n";
					break;
				}
			}
			system("pause");
			break;
		case 2:
			system("cls");
			frame.Err_Frame();
			number_r = frame.get_recv();
			number_s = frame.get_send();
			for (int i = 0; i < M; i++) {
				if (frame.check_init()) {
					if (i == number_r) {
						if (frame.check_summ()) {
							cout << "I am station number " << number_r << ". I receive frame from station number " << number_s << ":\n";
							frame.display();
							cout << "------------\n";

							frame_answ.Normal_Frame();
							number_r = frame_answ.get_recv();
							number_s = frame_answ.get_send();
							for (int j = 0; j < M + 1; j++) {
								if (frame_answ.check_init()) {
									if (j == number_r) {
										cout << "I am station number " << number_r << ". I receive frame_answ from station number " << number_s << ":\n";
										frame_answ.display();
									}
								}
								else {
									cout << "Error in init of Frame!!!\n";
									break;
								}
							}
						}
						else {
							cout << "Error in check summ of Frame!!!\n";
							cout << "I am station number " << number_r << ". I receive frame from station number " << number_s << ":\n";
							frame.display();
							cout << "------------\n";

							frame_answ.Err_Frame();
							number_r = frame_answ.get_recv();
							number_s = frame_answ.get_send();
							for (int j = 0; j < M + 1; j++) {
								if (frame_answ.check_init()) {
									if (j == number_r) {
										cout << "I am station number " << number_r << ". I receive frame_answ from station number " << number_s << ":\n";
										frame_answ.display();
									}
								}
								else {
									cout << "Error in init of Frame!!!\n";
									break;
								}
							}
							break;
						}
					}
				}
				else {
					cout << "Error in init of Frame!!!\n";
					break;
				}
			}
			system("pause");
			break;
		case 3:
			flag = false;
			break;
		default:
			cout << "Ooops, pls input again...\n";
			system("pause");
			system("cls");
		}
	}

	system("pause");
	return 0;
}