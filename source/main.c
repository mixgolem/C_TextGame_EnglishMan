//게임의 메인 소스코드

#include "헤더.h"

int main()
{
	system("mode con cols=120 lines=50");//cmd창의 크기 조절

	player son = { 2, 1000, 10, 0, 10 };//캐릭터 번호, 골드, 체력, 민첩, 힘 순서
	player* a = NULL;//캐릭터 포인터 선언
	a = &son;//캐릭터 선언

	int eventcount = 0;//이벤트 몇번 진행했는지 카운트
	int ran[COUNT_EVENT] = { COUNT_EVENT + 1, };
	sys_random_event_occur(ran);//이벤트 순서 랜덤으로 만들어서 ran배열에 저장
	
	system("cls");


	//게임 시작 함수
	sys_opening();
	//캐릭터 선택 함수
	sys_selectplayer(a);
	//튜토리얼 실행
	sys_tutorial(a);

	
	//루프 실행
	while (1) {
		eventcount = sys_playevent(eventcount, ran, a);//playevent함수 한번 실행 시 이벤트 한개씩 실행됨
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

		//한 루프 종료 후 다시 이벤트의 순서를 무작위로 배열
		eventcount = 0;
		memset(ran, COUNT_EVENT + 1, COUNT_EVENT);
		sys_random_event_occur(ran);
	}
	
	return 0;
}