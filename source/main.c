//������ ���� �ҽ��ڵ�

#include "header.h"

int main()
{
	system("mode con cols=120 lines=50");//cmdâ�� ũ�� ����

	player son = { 2, 1000, 10, 0, 10 };//ĳ���� ��ȣ, ���, ü��, ��ø, �� ����
	player* a = NULL;//ĳ���� ������ ����
	a = &son;//ĳ���� ����

	int eventcount = 0;//�̺�Ʈ ��� �����ߴ��� ī��Ʈ
	int ran[COUNT_EVENT] = { COUNT_EVENT + 1, };
	sys_random_event_occur(ran);//�̺�Ʈ ���� �������� ���� ran�迭�� ����
	
	system("cls");


	//���� ���� �Լ�
	sys_opening();
	//ĳ���� ���� �Լ�
	sys_selectplayer(a);
	//Ʃ�丮�� ����
	sys_tutorial(a);

	
	//���� ����
	while (1) {
		eventcount = sys_playevent(eventcount, ran, a);//playevent�Լ� �ѹ� ���� �� �̺�Ʈ �Ѱ��� �����
		eventcount = sys_playevent(eventcount, ran, a);
		game_casino(a);
		eventcount = sys_playevent(eventcount, ran, a);
		eventcount = sys_playevent(eventcount, ran, a);
		game_casino(a);
		eventcount = sys_playevent(eventcount, ran, a);
		eventcount = sys_playevent(eventcount, ran, a);
		game_casino(a);
		eventcount = sys_playevent(eventcount, ran, a);
		eventcount = sys_playevent(eventcount, ran, a);
		eventcount = sys_playevent(eventcount, ran, a);
		game_casino(a);

		//�� ���� ���� �� �ٽ� �̺�Ʈ�� ������ �������� �迭
		eventcount = 0;
		memset(ran, COUNT_EVENT + 1, COUNT_EVENT);
		sys_random_event_occur(ran);
	}
	
	return 0;
}