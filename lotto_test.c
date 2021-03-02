//사용자에게 이번 당첨번호와 구매한 로또번호를 입력받아 당첨결과를 처리해주는 프로그램이다.
#include <stdio.h>
#include <stdlib.h>
#define COUNT 2
int main(void) // int는 함수의 출력타입, main은 함수의 이름, ()안의 void는 입력이 없다는 의미이다.
{
	int prize[7];
	int num[COUNT][6];
	int bonus[COUNT];
	int i, j, k, l;//for반복문
	int a, b, c;//for반복문
	int point = 0; //당첨개수
	int bonus_point = 0; //보너스 당첨확인
	int won = 0;//상금

	printf("당첨번호를 입력해주세요 : ");
	scanf("%d %d %d %d %d %d %d", &prize[0], &prize[1], &prize[2], &prize[3], &prize[4], &prize[5], &prize[6]);
	printf("\n");

	for (i = 0; i < COUNT; i++)
	{
		printf("구매하신 %d번째 로또 번호를 입력해주세요 : ", i + 1);
		scanf("%d %d %d %d %d %d %d", &num[i][0], &num[i][1], &num[i][2], &num[i][3], &num[i][4], &num[i][5], &bonus[i]);
	}

	for (a = 0; a < COUNT; a++)
	{
		for (b = 0; b < 6; b++)
		{
			for (c = 0; c < 6; c++)
			{
				if (prize[b] == num[a][c])
				{
					point++;
				}
			}
		}
		if (prize[6] == bonus[a])
		{
			bonus_point++;
		}
		switch (point)
		{
		case 3:
			printf(" %d번째 로또는 5등입니다. (상금 : 5,000원)\n", a + 1);
			won += 5000;
			break;
		case 4:
			printf(" %d번째 로또는 4등입니다. (상금 : 50,000원)\n", a + 1);
			won += 50000;
			break;
		case 5:
			if (bonus_point == 0)
			{
				printf(" %d번째 로또는 3등입니다. (상금 : 1,500,000원)\n", a + 1);
				won += 1500000;
			}
			else
			{
				printf(" %d번째 로또는 2등입니다. (상금 : 60,000,000원)\n", a + 1);
				won += 60000000;
			}
			break;
		case 6:
			printf(" %d번째 로또는 1등입니다. (상금 : 2,000,000,000원)\n", a + 1);
			won += 2000000000;
			break;
		default:
			printf(" %d번째 로또는 당첨되지않았습니다. \n", a + 1);
		}
		point = 0;
	}

	printf("\n");
	printf("총 당첨금액은 %d원 입니다.\n", won);

	return 0; // 함수를 종료시키면서 0을 반환한다는 의미이다.

}
