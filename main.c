#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void start(); //'�ʱ�ȭ��'�Լ�
void join(); //'ȸ������'�Լ�
void login(); //'�α���'�Լ�
void NonMem(); //��ȸ�� ���� �Լ�
void menu(int * cnt);  //'���θ޴�'�Լ�
void Park(int * cnt);  //'�����ϱ�'�Լ�
void ShowPark(int * cnt); //'������Ȳ'����
void NonMemShowPark();  //��ȸ�� ���� ������Ȳ���� �Լ�
void Service(int * cnt); //'��ǰ�ֹ�'�Լ�
void AdmPhone(int * cnt); //'������ ����ó'�Լ�
void CheckOut(int * cnt); //'����ϱ�'�Լ�
void RoadStat(int * cnt); //'�ֺ����λ�Ȳ'�Լ�
void ParkSearch(int * cnt); //'�ֺ������� �˻�'�Լ�
void ParkFee(int * cnt); //'������� ����'�Լ�
void NonMemParkFee(); //��ȸ�� ���� ������� ���� �Լ�
void TimeNow(int * cnt); //'����ð�'�Լ�
void Admin(); //'������ ���� �޴�' �Լ�
void AdminMenu(int * cnt); //������ ���� �޴�
void AdjAdmin(int * cnt); //������ �߰� �� ����
void ShowMember(int * cnt); //ȸ�� ��ȸ
void DelMember(int * cnt); //ȸ�� ����
void Income(int * cnt); //���Գ�����ȸ
void AddAdmin(int * cnt); //������ �߰�
void DelAdmin(int * cnt); //������ ����
void ChangeGradeAdmin(int * cnt); //������ ��� ����
int Re_Check(char memid[20], int * pt);

int PerFee=8000; //��������� ���������� �����Ͽ� �� ������ �����ϸ� ���α׷����� ���� ��� ������������� ���ŵȴ�.
int CarWash=25000, Tire=35000, Refuel=1935;

int main(void)
{
	start();   //start(�ʱ�ȭ��)�Լ� ȣ��
	return 0;
}

void start()
{
	int i;
	system("cls");
	printf("\n\n\n\n\n");
	printf("######################################");
	printf("#######################################\n");
	printf("##									   ##\n");
	printf("##									   ##\n");
	printf("##	��	��	��	��	��	 A 	 P	 P	   ##\n");
	printf("##									   ##\n");
	printf("##									   ##\n");
	printf("######################################");
	printf("#######################################\n");
	printf("\n\n\n\n\n");

	printf("1. ȸ������ \n2. �α��� \n3. ��ȸ��\n4. �����ڷα���\n5. ����\n\n");
	printf("Choose: ");
	scanf("%d", &i);  //�޴��� ��ȣ�� �޾� ���� i�� ����
	if (i==1) //����ڰ� �Է��� �޴��� ��ȣ�� �´� �Լ� ȣ��
		join();
	else if(i==2)
		login();
	else if(i==3)
		NonMem();
	else if(i==4)
		Admin();
	else if(i==5)
		exit(0);
	else
	{
		puts("��ȿ�� �޴��� �ƴմϴ�.");  //1~4�� �ƴ� ���ڸ� �Է��� ��� ������ ���� �޼��� ��� �� start�Լ� �� ȣ��
		puts("Press any key to refresh");
		getch();
		system("cls");
		start();
	}
}

void join()
{
	typedef struct member //ȸ�������� �ޱ� ���� ȸ�� ���� ����ü
	{
		char id[15];
		char pw[20];
		int carnum;
		char phon[15];
		int order;
	}Member;

	FILE * fp=fopen("member.txt", "at");
	int ret, cnt;
	char exit[]="exit";
	
	Member mem;
	system("cls");
	puts("---------- ȸ������ ----------");
	puts("10�������� ����/���� ������ ���̵� �Է��Ͻʽÿ�.");
	puts("���̵� �Ǵ� ��й�ȣ �Է�ĭ�� 'exit'��� �Է��ϸ� �ʱ�ȭ������ �̵�");
	while(1)
	{
		mem.id[0]=0;mem.id[1]=0;mem.id[2]=0;mem.id[3]=0;mem.id[4]=0;mem.id[5]=0;mem.id[6]=0;mem.id[7]=0;mem.id[8]=0;
		mem.id[9]=0;mem.id[10]=0;mem.id[11]=0;mem.id[12]=0;mem.id[13]=0;mem.id[14]=0;// ������ �迭��� �ʱ�ȭ...
		printf("���̵�: "); scanf("%s", mem.id);
		ret=Re_Check(mem.id, &cnt);//�Է¹��� ���̵� Re_Check�Լ��� ������ ȸ���� ������ ���̵� �ִ��� �ߺ� �˻�
		if((mem.id[10]>47&&mem.id[10]<58)||(mem.id[10]>64&&mem.id[10]<91)||(mem.id[10]>96&&mem.id[10]<123))
		{   //11��° �迭 ��Ұ� �ΰ��� �ƴ� ���Ĺ��̳� ���ڰ��� ������ ������ 10�ڸ� �ʰ��� ������ ����
			puts("���̵� 10�ڸ� �ʰ��Ͽ����ϴ�.");
			continue;
		}
		else if (!strcmp(mem.id, exit))
		{
			puts("�ʱ�ȭ������ �̵�");
			getch();
			start();
		}
		else if(!((mem.id[0]>='0'&&mem.id[0]<='9')||(mem.id[0]>='A'&&mem.id[0]<='Z')||(mem.id[0]>='a'&&mem.id[0]<='z'))
			||!((mem.id[1]>='0'&&mem.id[1]<='9')||(mem.id[1]>='A'&&mem.id[1]<='Z')||(mem.id[1]>='a'&&mem.id[1]<='z')||(mem.id[1]==0))
			||!((mem.id[2]>='0'&&mem.id[2]<='9')||(mem.id[2]>='A'&&mem.id[2]<='Z')||(mem.id[2]>='a'&&mem.id[2]<='z')||(mem.id[2]==0)||(mem.id[2]==-52))
			||!((mem.id[3]>='0'&&mem.id[3]<='9')||(mem.id[3]>='A'&&mem.id[3]<='Z')||(mem.id[3]>='a'&&mem.id[3]<='z')||(mem.id[3]==0)||(mem.id[3]==-52))
			||!((mem.id[4]>='0'&&mem.id[4]<='9')||(mem.id[4]>='A'&&mem.id[4]<='Z')||(mem.id[4]>='a'&&mem.id[4]<='z')||(mem.id[4]==0)||(mem.id[4]==-52))
			||!((mem.id[5]>='0'&&mem.id[5]<='9')||(mem.id[5]>='A'&&mem.id[5]<='Z')||(mem.id[5]>='a'&&mem.id[5]<='z')||(mem.id[5]==0)||(mem.id[5]==-52))
			||!((mem.id[6]>='0'&&mem.id[6]<='9')||(mem.id[6]>='A'&&mem.id[6]<='Z')||(mem.id[6]>='a'&&mem.id[6]<='z')||(mem.id[6]==0)||(mem.id[6]==-52))
			||!((mem.id[7]>='0'&&mem.id[7]<='9')||(mem.id[7]>='A'&&mem.id[7]<='Z')||(mem.id[7]>='a'&&mem.id[7]<='z')||(mem.id[7]==0)||(mem.id[7]==-52))
			||!((mem.id[8]>='0'&&mem.id[8]<='9')||(mem.id[8]>='A'&&mem.id[8]<='Z')||(mem.id[8]>='a'&&mem.id[8]<='z')||(mem.id[8]==0)||(mem.id[8]==-52))
			||!((mem.id[9]>='0'&&mem.id[9]<='9')||(mem.id[9]>='A'&&mem.id[9]<='Z')||(mem.id[9]>='a'&&mem.id[9]<='z')||(mem.id[9]==0)||(mem.id[9]==-52)))
		{  //���̵� ����/���ڰ� �ƴ� �ٸ� ���ڰ� �ִ��� �˻�
			puts("���̵�� ����/���� �������θ� ������ �� �ֽ��ϴ�.");
			continue;
		}
		else if(mem.id[0]==48&&mem.id[1]==0)
		{
			puts("���̵�� ���� 0�� ����� �� �����ϴ�.");//���߿� ȸ�� �����ÿ� ȸ���� ��� ������ 0���� �ʱ�ȭ ��ų����
			continue;                                  //���ο� �� ����
		}
		else if (ret)  //Re_Check�Լ��� ��ȯ���� ���� ���̵� �ߺ����� �Ǻ�
		{
			puts("����� �� �ִ� ���̵� �Դϴ�.");
			break;
		}
		else
		{
			puts("�̹� ������� ���̵� �Դϴ�.");
			continue;
		}
		
	}
	puts("15�������� ����/���� �������� ��й�ȣ�� �Է��Ͻʽÿ�.");
	while(1)
	{
		mem.pw[1]=0;mem.pw[2]=0;mem.pw[3]=0;mem.pw[4]=0;mem.pw[5]=0;mem.pw[6]=0;mem.pw[7]=0;mem.pw[8]=0;mem.pw[9]=0;mem.pw[10]=0;
		mem.pw[11]=0;mem.pw[12]=0;mem.pw[13]=0;mem.pw[14]=0;mem.pw[15]=0;mem.pw[16]=0;mem.pw[17]=0;mem.pw[18]=0;mem.pw[19]=0;mem.pw[0]=0;
		printf("��й�ȣ: "); scanf("%s", mem.pw);
		if((mem.pw[15]>47&&mem.pw[15]<58)||(mem.pw[15]>64&&mem.pw[15]<91)||(mem.pw[15]>96&&mem.pw[15]<123))
		{//���̵�� ���������� 16��° �迭��� �˻�
			puts("��й�ȣ�� 15�ڸ� �ʰ��Ͽ����ϴ�.");
			continue;
		}
		else if (!strcmp(mem.pw, exit))
		{
			puts("�ʱ�ȭ������ �̵�");
			getch();
			start();
		}
		else if(!((mem.pw[0]>='0'&&mem.pw[0]<='9')||(mem.pw[0]>='A'&&mem.pw[0]<='Z')||(mem.pw[0]>='a'&&mem.pw[0]<='z'))
			||!((mem.pw[1]>='0'&&mem.pw[1]<='9')||(mem.pw[1]>='A'&&mem.pw[1]<='Z')||(mem.pw[1]>='a'&&mem.pw[1]<='z')||(mem.pw[1]==0))
			||!((mem.pw[2]>='0'&&mem.pw[2]<='9')||(mem.pw[2]>='A'&&mem.pw[2]<='Z')||(mem.pw[2]>='a'&&mem.pw[2]<='z')||(mem.pw[2]==0)||(mem.pw[2]==-52))
			||!((mem.pw[3]>='0'&&mem.pw[3]<='9')||(mem.pw[3]>='A'&&mem.pw[3]<='Z')||(mem.pw[3]>='a'&&mem.pw[3]<='z')||(mem.pw[3]==0)||(mem.pw[3]==-52))
			||!((mem.pw[4]>='0'&&mem.pw[4]<='9')||(mem.pw[4]>='A'&&mem.pw[4]<='Z')||(mem.pw[4]>='a'&&mem.pw[4]<='z')||(mem.pw[4]==0)||(mem.pw[4]==-52))
			||!((mem.pw[5]>='0'&&mem.pw[5]<='9')||(mem.pw[5]>='A'&&mem.pw[5]<='Z')||(mem.pw[5]>='a'&&mem.pw[5]<='z')||(mem.pw[5]==0)||(mem.pw[5]==-52))
			||!((mem.pw[6]>='0'&&mem.pw[6]<='9')||(mem.pw[6]>='A'&&mem.pw[6]<='Z')||(mem.pw[6]>='a'&&mem.pw[6]<='z')||(mem.pw[6]==0)||(mem.pw[6]==-52))
			||!((mem.pw[7]>='0'&&mem.pw[7]<='9')||(mem.pw[7]>='A'&&mem.pw[7]<='Z')||(mem.pw[7]>='a'&&mem.pw[7]<='z')||(mem.pw[7]==0)||(mem.pw[7]==-52))
			||!((mem.pw[8]>='0'&&mem.pw[8]<='9')||(mem.pw[8]>='A'&&mem.pw[8]<='Z')||(mem.pw[8]>='a'&&mem.pw[8]<='z')||(mem.pw[8]==0)||(mem.pw[8]==-52))
			||!((mem.pw[9]>='0'&&mem.pw[9]<='9')||(mem.pw[9]>='A'&&mem.pw[9]<='Z')||(mem.pw[9]>='a'&&mem.pw[9]<='z')||(mem.pw[9]==0)||(mem.pw[9]==-52))
			||!((mem.pw[10]>='0'&&mem.pw[10]<='9')||(mem.pw[10]>='A'&&mem.pw[10]<='Z')||(mem.pw[10]>='a'&&mem.pw[10]<='z')||(mem.pw[10]==0)||(mem.pw[10]==-52))
			||!((mem.pw[11]>='0'&&mem.pw[11]<='9')||(mem.pw[11]>='A'&&mem.pw[11]<='Z')||(mem.pw[11]>='a'&&mem.pw[11]<='z')||(mem.pw[11]==0)||(mem.pw[11]==-52))
			||!((mem.pw[12]>='0'&&mem.pw[12]<='9')||(mem.pw[12]>='A'&&mem.pw[12]<='Z')||(mem.pw[12]>='a'&&mem.pw[12]<='z')||(mem.pw[12]==0)||(mem.pw[12]==-52))
			||!((mem.pw[13]>='0'&&mem.pw[13]<='9')||(mem.pw[13]>='A'&&mem.pw[13]<='Z')||(mem.pw[13]>='a'&&mem.pw[13]<='z')||(mem.pw[13]==0)||(mem.pw[13]==-52))
			||!((mem.pw[14]>='0'&&mem.pw[14]<='9')||(mem.pw[14]>='A'&&mem.pw[14]<='Z')||(mem.pw[14]>='a'&&mem.pw[14]<='z')||(mem.pw[14]==0)||(mem.pw[14]==-52)))
		{   //��й�ȣ�� ����/���ڿܿ� �ٸ� ���ڰ� �ִ��� �˻�
			puts("��й�ȣ�� ����/���� �������θ� ������ �� �ֽ��ϴ�.");
			continue;
		}
		else
			break;
	}
	puts("4�ڸ��� ������ȣ�� �Է��Ͻʽÿ�. ex) 1234");
	while(1)
	{
		printf("������ȣ: "); scanf("%d", &mem.carnum);
		if(mem.carnum>999&&mem.carnum<10000)  //�ݵ�� 4�ڸ��� ���ڸ� �޵��� ����
			break;
		else
		{
			puts("4�ڸ��� ������ȣ�� �ùٸ��� �Է��Ͻʽÿ�.");
			continue;
		}
	}
	printf("��ȭ��ȣ(ex. 010-111-1111): "); scanf("%s", mem.phon);
	mem.order=0;

	fprintf(fp, "%-12s %-17s %-6d %-17s %-10d\n", mem.id, mem.pw, mem.carnum, mem.phon, mem.order);
	puts("ȸ�������� �Ϸ� �Ǿ����ϴ�.");
	puts("Press any key to continue");
	getch();
	fclose(fp);
	start();  //start�Լ� ȣ��
}

int Re_Check(char memid[15], int * cnt)
{
	FILE * fp=fopen("member.txt", "rt");
	typedef struct member //ȸ�������� �ޱ� ���� ȸ�� ���� ����ü
	{
		char id[15];
		char pw[20];
		int carnum;
		char phon[15];
		int order;
	}Member;
	Member mem;
	*cnt=0;

	while (1)
	{
		fscanf(fp, "%s %s %d %s %d", mem.id, mem.pw, &mem.carnum, mem.phon, &mem.order);
		/*fseek(fp, 67*(*cnt), 0);
		fscanf(fp, "%s\n", tempid);*/
		*cnt += 1;
		if (!strcmp(memid, mem.id))
		{
			return 0;
			break;
		}
		else if (feof(fp))
		{
			return 1;
			break;
		}
		else
			continue;
	}
	fclose(fp);
}
int Re_Check_Admin(char memid[15], int * cnt)//Re_Check�Լ��� ��������� �����ڸ޴��� ���� ���� ���� �Լ�
{
	FILE * fp=fopen("administrator.txt", "rt");

	char tempid[15], temppw[20];
	int grade;
	*cnt=1;
	fscanf(fp, "%s", tempid); //���Ϸκ��� ���̵� �Է¹���
	if(!strcmp(memid, tempid))//����ڰ� �Է��� ���̵�� ��
	{
		fclose(fp);
		return 0;
	}
	while (1)
	{
		fscanf(fp, "%s %s %d", tempid, temppw, &grade);
		if (!strcmp(memid, tempid))
		{
			fclose(fp);
			return 0;
			break;
		}
		else if (feof(fp))
		{
			fclose(fp);
			return 1;
			break;
		}
		else
			continue;
	}
	fclose(fp);
}
void login()
{
	FILE * fp=fopen("member.txt", "rt"); //ȸ�������� ������ִ� member������ ���� ���������� fp�� �ʱ�ȭ
	typedef struct member //ȸ������ ����ü
	{
		char id[15];
		char pw[20];
		int carnum;
		char phon[15];
		int order;
	}Member;
	Member mem;
	char id[15], pw[20];
	int cnt, ret, i;
	system("cls");
	printf("---------------�α���---------------\n");
	while(1)
	{
		printf("���̵�: "); scanf("%s", id);
		ret=Re_Check(id, &cnt);//Re_Check�Լ��� �Է��� ���̵� member���Ͽ� �����ϴ��� �Ǻ��ϰ�, ���� cnt�� �ּҰ��� �Ѱ��� ��
		if(ret)            //�� �� ���� �� ���� ���� cnt�� ++������ �Ͽ� �� ��° ���̵����� �˾Ƴ���.
		{
			puts("�������� �ʴ� ���̵� �Դϴ�.\n");
			getch();
			system("cls");
			printf("---------------�α���---------------\n");
			continue;
		}
		else
			break;
	}
	
	printf("��й�ȣ: "); scanf("%s", pw);
	fseek(fp, 0, SEEK_SET);
	for(i=0; i<cnt; i++) //�ռ� ������Re_Check�Լ��� ���� �� ��° ȸ������ ���� cnt�� ����������Ƿ� for���� ����
	{                    //cnt�� ����� ���ڸ�ŭ fscanf���� �ݺ��ϸ� ���̵� ��ġ�ϴ� ��й�ȣ�� �������� �� �� �ִ�.
		fscanf(fp, "%s %s %d %s %d", mem.id, mem.pw, &mem.carnum, mem.phon, &mem.order);
	}
	if(strcmp(pw, mem.pw))//���� for���� ���� �˾Ƴ� ��й�ȣ�� ����ڰ� �Է��� ��й�ȣ�� ���Ѵ�.
	{
		puts("��й�ȣ�� ��ġ���� �ʽ��ϴ�.");
		puts("�ٽ� �α����� �ֽʽÿ�.");
		getch();
		system("cls");
		login();
	}
	else
	{
		printf("%s�� �α��εǾ����ϴ�.\n", id);
		puts("Press any key to continue");
		getch();
		menu(&cnt);
	}
	fclose(fp);
}

void NonMem() //��ȸ�� �޴� �Լ�
{
	int i;
	system("cls");
	puts("---------------��ȸ�� �޴�---------------");
	printf("1. ������Ȳ ��ȸ \n2. ������� ��ȸ \n3. ȸ������ \n4. ���ư��� \n5. ����\n");
	printf("Choose: "); scanf("%d", &i);
	switch(i)
	{
	case 1:
		NonMemShowPark();
		break;
	case 2:
		NonMemParkFee();
		break;
	case 3:
		join();
		break;
	case 4:
		start();
		break;
	case 5:
		exit(0);
		break;
	default:
		printf("��ȿ���� ���� �޴��Դϴ�. �ٽ� ������ �ּ���.\n");
		puts("Press any key to refresh");
		getch();
		NonMem();
	}
}

void NonMemShowPark()
{
	FILE * fp=fopen("parkstatus.txt", "rt");
	char park[3][10][10][7];
	int i, j, k, score;
	int cnt;

	for(i=0;i<3;i++)  //���Ͽ� ������մ� ������Ȳ������ �迭�� �ҷ���
	{
		for(j=0;j<10;j++)
		{
			fscanf(fp, "%s %s %s %s %s %s %s %s %s %s", park[i][j][0], park[i][j][1], park[i][j][2], park[i][j][3], park[i][j][4],
				park[i][j][5], park[i][j][6], park[i][j][7], park[i][j][8], park[i][j][9]);
		}
	}
	system("cls");
	puts("---------------������Ȳ---------------");
	printf("�� ���� ������Ȳ�� ���ðڽ��ϱ�?: ");
	scanf("%d", &score);

	if(score<1||score>3)
	{
		puts("�� �������� �� 3������ �����Ǿ��ֽ��ϴ�.");
		puts("1~3�� �� ���� �ٽ� �Է��� �ֽʽÿ�.");
		getch();
		NonMemShowPark();
	}

	for(j=0;j<10;j++)
	{
		for(k=0;k<10;k++)
		{
			printf("%7s", park[score-1][j][k]);
		}
		printf("\n");
	}
	printf("\n\n");
	puts("1. �ٸ� ���� ������Ȳ ����"); puts("2. ���ư���");
	printf("Choose: "); scanf("%d", &i);
	switch(i)
	{
		case 1:
			puts("Press any key to continue");
			getch();
			NonMemShowPark();
			break;
		case 2:
			puts("Press any key to continue");
			getch();
			NonMem();
			break;
		default:
			puts("��ȿ���� �ʴ� �޴��Դϴ�.");
			puts("Press any key to refresh");
			getch();
			NonMemShowPark();
	}
}

void NonMemParkFee()
{
	system("cls");

	puts("---------------���� ���---------------");
	printf("\n");
	printf("�ð��� ���: %d��\n\n", PerFee);

	puts("Press any key to return");
	getch();
	NonMem();
}

void menu(int * cnt) //���θ޴��Լ�
{
	int i;
	system("cls");
	printf("---------------�޴�---------------\n");
	puts("1. �����ϱ�            2. ������Ȳ ����");
	puts("3. ����(��ǰ) �ֹ�   4. ������ ����ó");
	puts("5. ��ݰ��            6. ���� ���� ��Ȳ");
	puts("7. ������ ������ �˻�  8. ���� ���");
	puts("9. ���� �ð� ����      10. �α׾ƿ�");
	puts("11. ����");
	printf("choose: "); scanf("%d", &i);
	switch (i)
	{
		case 1:
			Park(cnt); //'�����ϱ�'�Լ� ȣ��
			break;
		case 2:
			ShowPark(cnt);//'������Ȳ����'�Լ� ȣ��
			break;
		case 3:
			Service(cnt); //'��ǰ�ֹ�'�Լ� ȣ��
			break;
		case 4:
			AdmPhone(cnt);//'�����ڿ���ó'�Լ� ȣ��
			break;
		case 5:
			CheckOut(cnt);//'��ݰ��'�Լ� ȣ��
			break;
		case 6:
			RoadStat(cnt);//'�ֺ����λ�Ȳ'�Լ� ȣ��
			break;
		case 7:
			ParkSearch(cnt);//'�ֺ�������˻�'�Լ� ȣ��
			break;
		case 8:
			ParkFee(cnt);//'��������'�Լ� ȣ��
			break;
		case 9:
			TimeNow(cnt);//'����ð�'�Լ� ȣ��
			break;
		case 10:
			start();//start�Լ� ȣ��
			break;
		case 11:
			exit(0);//���α׷�����
			break;
		default:
			printf("��ȿ�� �޴��� �ƴմϴ�.\n");
			printf("1 ~ 11 ������ �޴��� ������ �ֽʽÿ�\n");
			puts("Press any key to refresh");
			getch();
			menu(cnt);
	}
}

void Park(int * cnt)
{
	FILE * fp1=fopen("park.txt", "at");
	FILE * fp2=fopen("park.txt", "rt");
	FILE * fp3=fopen("parkstatus.txt", "rt");
	FILE * fp4=fopen("parkstatus.txt", "r+");//������Ȳ ������ �����ϱ����� ���������� fp4
	FILE * fp5=fopen("member.txt", "rt");
	typedef struct member //ȸ������ ����ü
	{
		char id[15];
		char pw[20];
		int carnum;
		char phon[15];
		int order;
	}Member;
	Member mem;
	char park[3][10][10][7];
	char seatnum[5];
	int i, j, k, score, tc=*cnt;
	int tmpcnt, tmpi, tmpj, tmpk, tmptime;
	char tmpid[15];
	system("cls");
	puts("---------------�����ϱ�---------------");

	for(i=0;i<3;i++)  //���Ͽ� ����� ������Ȳ������ �������迭 park�� ����
	{
		for(j=0;j<10;j++)
		{
			fscanf(fp3, "%s %s %s %s %s %s %s %s %s %s", park[i][j][0], park[i][j][1], park[i][j][2], park[i][j][3], park[i][j][4],
				park[i][j][5], park[i][j][6], park[i][j][7], park[i][j][8], park[i][j][9]);
		}
	}
	while(1) //�α����� ȸ���� ���� ������������ �Ǻ��� ���� ���� �������̸� �� �ٽ� ������ �� �������Ѵ�.
	{
		fscanf(fp2, "%d %d %d %d %d", &tmpcnt, &tmpi, &tmpj, &tmpk, &tmptime);
		if(*cnt==tmpcnt)
		{
			while(tc)  //cnt������ŭ fscanf���� ������� �ش� ȸ���� ������ �Է¹޴´�.
			{
				fscanf(fp5, "%s %s %d %s %d", mem.id, mem.pw, &mem.carnum, mem.phon, &mem.order);
				tc--;
			}
			printf("%s���� �̹� %s�ڸ��� ������ �Դϴ�.\n", mem.id, park[tmpi][tmpj][tmpk]);
			puts("Press any key to refresh");
			getch();
			menu(cnt);
		}
		else if(feof(fp2)) //������ ���� �������� ��� ���ѷ����� ����������.
			break;
		else
			continue;
	}
	printf("������ ���� �Է��Ͻʽÿ�.(1~3��): ");
	scanf("%d", &score); //������ ���� �Է¹޾� ���� score�� ����
	if (!(score>=1&&score<=3))
	{
		puts("���� �������� �� 3������ �����Ǿ� �ֽ��ϴ�.");puts("1~3������ ���� �� ������ �ֽʽÿ�.");
		getch();
		fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5);
		Park(cnt);
	}
	
	for(j=0;j<10;j++)
	{
		for(k=0;k<10;k++)
		{
			printf("%7s", park[score-1][j][k]);//�� 3������ ������ �����忡�� �ռ� �Է¹��� ���� ������ ����Ѵ�.
		}                                      //(��� ���� ������ �� ���� ����ϸ� ���� ���� �������� �˾ƺ��� ����)
		printf("\n");
	}
	printf("\n\n");
	printf("�ݷ�(:)�� �������� ������ �ڸ� �����̸��̰�, ������ ���� ���θ� ��Ÿ���ϴ�.\n");
	printf("�ݷ�(:)�������� ���ڰ� 0�̸� ���������ϰ�, 1�̸� �̹� ������ �ڸ��Դϴ�.\n");
	printf("������ ���ϴ� �ڸ��� �����̸��� �Է��Ͻʽÿ�: ");
	scanf("%s", seatnum);  //������ ���ϴ� �ڸ��� �����̸��� �Է¹޾� �迭seatnum�� ����
	if(!(seatnum[0]>='A'&&seatnum[0]<='C')||!(seatnum[1]>='A'&&seatnum[1]<='J')||!(seatnum[2]>='0'&&seatnum[2]<='9'))
	{  //����ڰ� �Է��� �ڸ� �̸��� �ùٸ� �������� �˻�
		puts("�ùٸ� �ڸ� �̸��� �ƴմϴ�.");
		getch();
		fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5);
		Park(cnt);
	}
	i=seatnum[0]-65; j=seatnum[1]-65; k=seatnum[2]-48; //������ �迭��ҿ��� ������ ������ ���Ͽ� �迭�� ���� ���� ���
	if (park[i][j][k][4]=='1') //���� ����ڰ� �Է��� �ڸ��� �����̸��� ������ ���ڰ� 1�ΰ��� �̹� �������ִ� �¼��̹Ƿ�
	{                          //�ٸ� �ڸ������� �䱸
		puts("�̹� ������ �ڸ��Դϴ�. �ٸ� �ڸ��� �������ֽʽÿ�.");
		puts("Press any key to refresh");
		getch();
		fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5);
		Park(cnt);
	}

	park[i][j][k][4]='1';  //������ �����Ƿ� �ڸ� �����̸��� ������ ���ڸ� 0���� 1�ΰ�ħ
	fprintf(fp1, "%-5d %d %d %d %-15d\n", *cnt, i, j, k, time(NULL)); //���������� ���Ͽ� ����
	                                 //������ ����-(cnt)�� ȸ����ȣ, (i, j, k)�� �迭��ȣ, �׸��� (time(NULL))����ð� ������ ����
	for(i=0;i<3;i++)//������ ������Ȳ ������ �ٽ� ���Ͽ� ����
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<10;k++)
			{
				fprintf(fp4, "%s ", park[i][j][k]);
			}
			fprintf(fp4, "\n");
		}
	}
	printf("%s�ڸ��� ������� �Ϸ�Ǿ����ϴ�. �� �ð����� ��������� ���˴ϴ�.\n", seatnum);
	puts("Press any key to continue");
	getch();
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	menu(cnt);
}

void ShowPark(int * cnt)
{
	FILE * fp=fopen("parkstatus.txt", "rt");
	char park[3][10][10][7];
	int i, j, k, score;

	for(i=0;i<3;i++)
	{
		for(j=0;j<10;j++)
		{
			fscanf(fp, "%s %s %s %s %s %s %s %s %s %s", park[i][j][0], park[i][j][1], park[i][j][2], park[i][j][3], park[i][j][4],
				park[i][j][5], park[i][j][6], park[i][j][7], park[i][j][8], park[i][j][9]);
		}
	}
	system("cls");
	puts("---------------������Ȳ---------------");
	printf("�� ���� ������Ȳ�� ���ðڽ��ϱ�?: ");
	scanf("%d", &score);
	if(score<1||score>3)
	{
		puts("�� �������� �� 3������ �����Ǿ��ֽ��ϴ�.");
		puts("1~3�� �� ���� �ٽ� �Է��� �ֽʽÿ�.");
		getch();
		ShowPark(cnt);
	}

	for(j=0;j<10;j++)
	{
		for(k=0;k<10;k++)
		{
			printf("%7s", park[score-1][j][k]);
		}
		printf("\n");
	}
	printf("\n\n");
	puts("1. �ٸ� ���� ������Ȳ ����"); puts("2. ���ư���");
	printf("Choose: "); scanf("%d", &i);
	switch(i)
	{
		case 1:
			puts("Press any key to continue");
			getch();
			ShowPark(cnt);
			break;
		case 2:
			puts("Press any key to continue");
			getch();
			menu(cnt);
			break;
		default:
			puts("��ȿ���� �ʴ� �޴��Դϴ�.");
			puts("Press any key to refresh");
			getch();
			ShowPark(cnt);
	}
}

void Service(int * cnt)
{
	FILE * fp1=fopen("member.txt", "rt");
	FILE * fp2=fopen("member.txt", "r+");
	FILE * fp3=fopen("park.txt", "rt");
	typedef struct member
	{
		char id[15];
		char pw[20];
		int carnum;
		char phon[15];
		int order;
	}Member;
	Member mem;
	int i=0, n, oil;
	int tmpcnt, a, b, c, StartT;
	int tc=*cnt;
	while(tc)
	{
		fscanf(fp1, "%s %s %d %s %d\n", mem.id, mem.pw, &mem.carnum, mem.phon, &mem.order);
		tc--;
	}

	while(1)//*cnt�� ȸ���� ���ڵ�͵� ���� �������� ��� �Լ����� ���� �Ѱ������μ� �� �� �α����� ȸ���� ����ؼ�
	{      //�α��εǾ��ִ� ȿ���� �ְ�, �ٸ� ���Ͽ��� ȸ���� ������ ��������ִ� �ٸ� ���ҵ� �Ѵ�.(�ſ� �߿��� �����̱� ������ �ڵ� �������� ���� ���� �������� �ʵ��� ����)
		fscanf(fp3, "%d %d %d %d %d", &tmpcnt, &a, &b, &c, &StartT);
		if(*cnt==tmpcnt)
			break;
		else if(feof(fp3))//�������� �̿� ������ ������� ���񽺻�ǰ ���� �̿��� �� ����.(���⼭ �����ϴ� ���񽺴� ������ �����ڸ��� ��ġ�� �ڵ�ȭ ��⸦ ���ؼ� �����Ǳ� ������ ������ ���� �ʰ��� �̿��� �� ����)
		{  //park.txt���Ͽ� ����� cnt�������� ���� �������� ȸ���� cnt�������� �����غ����μ� �������� �̿������� �� �� �ִ�.
			system("cls");
			puts("---------------���� �ֹ�---------------");
			puts("�� ��ǰ�� ���� �����忡 ���� ���� ���� ������� �ϴ� �ΰ����� ��ǰ�̹Ƿ�");
			puts("���� �����忡 �������� ���� ������ �ֹ��Ͻ� �� �����ϴ�.");
			puts("���� '�����ϱ�'�޴��� ���� ������ ������ �ֽñ� �ٶ��ϴ�.");
			puts("Press any key to return");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			menu(cnt);
		}
		else
			continue;
	}
	system("cls");
	puts("---------------���� �ֹ�---------------");
	printf("1. ����(%d��) \n2. ����(���ʹ� %d��) \n3. Ÿ�̾� ��ü(%d��)\n4. ���ư���\n", CarWash, Refuel, Tire);
	printf("Choose: "); scanf("%d", &i);
	switch (i)
	{
	case 1:
		puts("��������� ������ݿ� �ջ�û���˴ϴ�. ���� �ֹ��Ͻðڽ��ϱ�?");
		puts("1. Yes    2. No");
		printf("Choose: "); scanf("%d", &n);
		if (n==1)
		{
			mem.order += CarWash;
			fseek(fp2, 67*(*cnt-1)+56+(*cnt-1), 0);//fseek������ member���Ͽ��ִ� order������ �����Ͽ� �����Ѵ�.
			fprintf(fp2, "%-10d", mem.order);
			puts("�ֹ��� �Ϸ� �Ǿ����ϴ�.");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			menu(cnt);
		}
		else if(n==2)
		{
			puts("�ֹ��� ��� �Ǿ����ϴ�.");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			Service(cnt);
		}
		else
		{
			puts("��ȿ���� ���� �����Դϴ�. �ٽ� �ֹ��� �ֽʽÿ�.");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			Service(cnt);
		}
		break;
	case 2:
		puts("��������� ������ݿ� �ջ�û���˴ϴ�. ���� �ֹ��Ͻðڽ��ϱ�?");
		puts("1. Yes    2. No");
		printf("Choose: "); scanf("%d", &n);
		if(n==1)
		{
			printf("�� ���� ���� �Ͻðڽ��ϱ�? "); scanf("%d", &oil);
			mem.order += (Refuel*oil);
			fseek(fp2, 67*(*cnt-1)+56+(*cnt-1), 0);
			fprintf(fp2, "%-10d", mem.order);
			puts("�ֹ��� �Ϸ� �Ǿ����ϴ�.");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			menu(cnt);
		}
		else if(n==2)
		{
			puts("�ֹ��� ��� �Ǿ����ϴ�.");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			Service(cnt);
		}
		else
		{
			puts("��ȿ���� ���� �����Դϴ�. �ٽ� �ֹ��� �ֽʽÿ�.");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			Service(cnt);
		}
		break;
	case 3:
		puts("Ÿ�̾� ��ü����� ������ݿ� �ջ�û���˴ϴ�. ���� �ֹ��Ͻðڽ��ϱ�?");
		puts("1. Yes    2. No");
		printf("Choose: "); scanf("%d", &n);
		if (n==1)
		{
			mem.order += Tire;
			fseek(fp2, 67*(*cnt-1)+56+(*cnt-1), 0);
			fprintf(fp2, "%-10d", mem.order);
			puts("�ֹ��� �Ϸ� �Ǿ����ϴ�.");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			menu(cnt);
		}
		else if(n==2)
		{
			puts("�ֹ��� ��� �Ǿ����ϴ�.");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			Service(cnt);
		}
		else
		{
			puts("��ȿ���� ���� �����Դϴ�. �ٽ� �ֹ��� �ֽʽÿ�.");
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3);
			Service(cnt);
		}
		break;
	case 4:
		puts("Press any key to return");
		getch();
		fclose(fp1); fclose(fp2); fclose(fp3);
		menu(cnt);
		break;
	default:
		puts("�������� �ʴ� �޴��Դϴ�.");
		getch();
		fclose(fp1); fclose(fp2); fclose(fp3);
		Service(cnt);
	}
}

void AdmPhone(int * cnt)
{
	system("cls");

	puts("---------------������ ����ó---------------");
	printf("�� ������(5TEAM): 010-5555-5555 \n��� ������: 010-1111-1111 \n�� ����: 070-8282-8282\n\n");

	puts("Press any key to return");
	getch();
	menu(cnt);
}

void CheckOut(int * cnt)
{
	FILE * fp1=fopen("member.txt", "rt");
	FILE * fp2=fopen("park.txt", "rt");
	FILE * fp3=fopen("member.txt", "r+");
	FILE * fp4=fopen("park.txt", "r+");
	FILE * fp5=fopen("parkstatus.txt", "rt");
	FILE * fp6=fopen("income.txt", "at");
	FILE * fp7=fopen("parkstatus.txt", "r+");
	time_t ltime;
	struct tm * today;
	typedef struct member
	{
		char id[20];
		char pw[20];
		int carnum;
		char phon[15];
		int order;
	}Member;
	Member mem;
	char park[3][10][10][7];
	int a, b, c, StartT, tmpcnt;
	int total, i;
	int choose;
	int j, k, l, tc=*cnt;

	system("cls");
	puts("---------------��ݰ��---------------");
	for(j=0;j<3;j++)//���Ͽ� ������ִ� ������Ȳ������ �ҷ�����
	{
		for(k=0;k<10;k++)
		{
			fscanf(fp5, "%s %s %s %s %s %s %s %s %s %s", park[j][k][0], park[j][k][1], park[j][k][2], park[j][k][3],
				park[j][k][4], park[j][k][5], park[j][k][6], park[j][k][7], park[j][k][8], park[j][k][9]);
		}
	}
	i=0;
	while(tc)//���⼭ tc�� cnt������ ���� �Ѱܹ����Լ� cnt������ ���� ���� ������ cnt������ ���� ������ �ʵ��� �����ϱ�����
	{
		fscanf(fp1, "%s %s %d %s %d", mem.id, mem.pw, &mem.carnum, mem.phon, &mem.order);
		tc--;
	}
	while(1)
	{
		//fseek(fp2, 28*i, 0);
		fscanf(fp2, "%d %d %d %d %d", &tmpcnt, &a, &b, &c, &StartT);//park���Ͼȿ� ����ȭ�� �ڷ�� �� ù ��° �����ʹ� cnt�����̹Ƿ�
		if(*cnt==tmpcnt)                                     //���� ������� cnt������ ������ �����μ� ���� ������� ���������� �ҷ��� �� �ִ�.
		{
			total=((time(NULL)-StartT)*(PerFee/3600))+mem.order;
			printf("%s���� ��������� �̿� ����� %d�� �Դϴ�.\n", mem.id, total);
			break;
		}
		else if(feof(fp2))//���� ���� ������� cnt������ ��ġ�ϴ� ���� ���ٸ� ������ ���� ���� ��!
		{
			printf("%s���� �̿볻���� �����ϴ�.\n", mem.id);
			getch();
			fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4);
			menu(cnt);
		}
		else
		{
			i++;
			continue;
		}
	}
	i=0;
	printf("1. �����ϱ� \n2. ���ư���\n");
	printf("Choose: "); scanf("%d", &choose);
	if(choose==1)
	{
		fseek(fp3, 67*(*cnt-1)+56+(*cnt-1), 0);//�����ϱ⸦ �����ϸ� member������ �ֹ������� 0���� �ʱ�ȭ�Ѵ�.
		fprintf(fp3, "0         ");
		while(1)
		{
			fscanf(fp4, "%d %d %d %d %d", &tmpcnt, &a, &b, &c, &StartT);
			i++;
			if(*cnt==tmpcnt)
				break;
		}
		park[a][b][c][4]='0'; //������ �ϸ� ����ڰ� ����ߴ� �ڸ��� �ٽ� �� �ڸ��� �ǹǷ� �ڸ� �̸��� ������ ����(�ݷ� ������ ��)�� �ٽ� 0���� �ٲ��ش�.
		for(j=0;j<3;j++)
		{
			for(k=0;k<10;k++)
			{
				for(l=0;l<10;l++)
				{
					fprintf(fp7, "%s ", park[j][k][l]);//�ٲ� ������Ȳ ������ ���Ͽ� �����Ѵ�.
				}
				fprintf(fp7, "\n");
			}
		}
		time(&ltime);
		today = localtime(&ltime);
		fprintf(fp6, "%04d %02d %02d %-12s %-15d\n", today->tm_year+1900, today->tm_mon+1, today->tm_mday, mem.id, total);
		fseek(fp4, 29*(i-1), 0);   //�ð����� ������ ���� ���̵�, �׸��� �ݾ��� income���Ͽ� ����
		fprintf(fp4, "0     ");   //�����ڸ޴����� ���Գ��� ��ȸ�� �������ؼ�
		puts("������ �Ϸ� �Ǿ����ϴ�.");
		getch();
		fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5); fclose(fp6); fclose(fp7);
		menu(cnt);//fclose�� ���� �� ���ָ� �ٷ� ������ ���ŵ��� �ʴ� ������ �߻��߾���!!
	}
	else if(choose==2)
	{
		puts("Press any key to return");
		getch();
		fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5); fclose(fp6); fclose(fp7);
		menu(cnt);
	}
	else
	{
		puts("��ȿ���� �ʴ� �޴��Դϴ�.");
		getch();
		fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5); fclose(fp6); fclose(fp7);
		CheckOut(cnt);
	}
}

void RoadStat(int * cnt)
{
	char a[6][70]={{"�ֺ� ���ΰ� ���� �մϴ�"},
	{"�ֺ� ���ΰ� �ѻ� �մϴ�"},
	{"�ֺ� ���ο� ��� �ֽ��ϴ�"},
	{"�ֺ� ���ΰ� ��ü ���Դϴ�. ��ȸ�Ͻʽÿ�."},
	{"GPS��ȣ�� ���մϴ�. ��� �� �ٽ� �õ��Ͻʽÿ�."},
	{"�ֺ� ���ΰ� ���� ���̿��� ��ȸ�Ͻʽÿ�."}};
	int temp;

	system("cls");
	printf("---------------���� ���� ��Ȳ---------------\n\n");
	srand(time(NULL));

	temp =(rand()%(6-0)+0); //�����Լ��� �̿��� ���Ƿ� �޼����� �ѷ���

	printf("%s\n\n",a[temp]);
	puts("Press any key to return");
	getch();
	menu(cnt);
}

void ParkSearch(int * cnt)  //���������� ��������
{
	char b[4][80] ={"�Ѱ� �������� ���� �������ϴ�.","���� �������� ���� �������ϴ�.","���� �������� ���� �������ϴ�.", "���� ������������ ���� �������ϴ�."};
	int temp;

	system("cls");
	printf("---------------�ֺ� ������ �˻�---------------\n\n");
	srand(time(NULL));

	temp =(rand()%(4-0)+0);

	printf("%s\n\n",b[temp]);
	puts("Press any key to return");
	getch();
	menu(cnt);
}

void ParkFee(int * cnt)
{
	system("cls");

	puts("---------------���� ���---------------");
	printf("\n");
	printf("�ð��� ���: %d��\n\n", PerFee);

	puts("Press any key to return");
	getch();
	menu(cnt);
}

void TimeNow(int * cnt)
{
	int i=0;
	time_t ltime;
	struct tm * today;
	int OldSec=0;

	system("cls");
	while (i<1)
	{
		printf("---------------����ð�---------------\n");
		time(&ltime);
		today = localtime(&ltime);
		if (OldSec != today->tm_sec)
		{
			printf("����ð�: %04d-%02d-%02d %02d:%02d\n", today->tm_year+1900,
				today->tm_mon+1, today->tm_mday, today->tm_hour, today->tm_min);
			OldSec = today->tm_sec;//���� �ð��� ���
			i++;
		}
	}
	puts("Press any key to return");
	getch();
	menu(cnt);
}

void Admin()
{
	FILE * fp=fopen("administrator.txt", "rt");
	
	char id[15], pw[20];
	char tempid[15], temppw[20];
	char exit[]="exit";
	int tempgrade;
	int cnt=0;

	system("cls");
	puts("---------------������ �α���---------------");
	puts("������ �޴��� �����ϱ� ���ؼ��� ������ ���̵�� �α��� �ؾ� �մϴ�.");
	puts("���̵� �Ǵ� ��й�ȣ���� 'exit'�� ġ�� �ʱ�ȭ������ �� �� �ֽ��ϴ�.");
	printf("������ ���̵�: "); scanf("%s", id);
	while(1)
	{
		fscanf(fp, "%s %s %d", tempid, temppw, &tempgrade);
		cnt++;
		if(!strcmp(id, tempid))
			break;
		else if (!strcmp(id, exit))
		{
			puts("�ʱ�ȭ������ ���ư��ϴ�.");
			getch();
			fclose(fp);
			start();
		}
		else if(feof(fp))
		{
			puts("��ġ�ϴ� ���̵� �����ϴ�.");
			getch();
			fclose(fp);
			Admin();
		}
		else
			continue;
	}
	while(1)
	{
		printf("��й�ȣ: "); scanf("%s", pw);
		if(!strcmp(pw, temppw))
			break;
		else if(!strcmp(pw, exit))
		{
			puts("�ʱ�ȭ������ ���ư��ϴ�.");
			getch();
			fclose(fp);
			start();
		}
		else
		{
			puts("��й�ȣ�� ��ġ���� �ʽ��ϴ�.");
			continue;
		}
	}
	puts("Press any key to continue");
	getch();
	fclose(fp);
	AdminMenu(&cnt);
}

void AdminMenu(int * cnt)//��� �����ڸ޴����� cnt������ �״� �ʿ䰡 ������. (�����ڴ� ����� �����ϰų� �ֹ��� ������ �ʰ�, ���� ��ü������ ���� ������ �������� �ʱ� ������)
{
	int n;
	system("cls");
	puts("---------------������ �޴�---------------");
	
	printf("1. ������ �߰�/���� �� ��޺���\n2. ȸ������ ��ȸ\n3, ȸ�� ����\n4. ���Գ���\n5. ���ư���\n");
	printf("Choose: "); scanf("%d", &n);
	if(n==1)
		AdjAdmin(cnt);
	else if(n==2)
		ShowMember(cnt);
	else if(n==3)
		DelMember(cnt);
	else if(n==4)
		Income(cnt);
	else if(n==5)
		start();
	else
	{
		puts("1~5������ �޴��� ������ �ֽʽÿ�.");
		getch();
		AdminMenu(cnt);
	}
}

void AdjAdmin(int * cnt)
{
	FILE * fp=fopen("administrator.txt", "rt");
	int grade, n;
	n=*cnt;
	n-=2;
	if(*cnt==1)
	{
		fseek(fp, 31, 0);
		fscanf(fp, "%d", &grade);
	}
	else if (*cnt==2)
	{
		fseek(fp, 35, 0);
		fseek(fp, 31, 1);
		fscanf(fp, "%d", &grade);
	}
	else
	{
		fseek(fp, 35, 0);
		while(n)
		{
			fseek(fp, 35, 1);
			n--;
		}
		fseek(fp, 31, 1);
		fscanf(fp, "%d", &grade);
	}
	if (grade>1)
	{
		puts("�� �޴��� �Ѱ�����(Grade==1)�� ������ �� �ֽ��ϴ�.");
		getch();
		fclose(fp);
		AdminMenu(cnt);
	}

	system("cls");
	puts("---------------������ �߰�/���� �� ��޺���---------------");
	puts("1. ������ �߰�");
	puts("2. ������ ����");
	puts("3. ������ ��޺���");
	puts("4. ���ư���");
	printf("Choose: "); scanf("%d", &n);
	if(n==1)
		AddAdmin(cnt);
	else if(n==2)
		DelAdmin(cnt);
	else if(n==3)
		ChangeGradeAdmin(cnt);
	else if(n==4)
	{
		puts("Press any key to return");
		getch();
		fclose(fp);
		AdminMenu(cnt);
	}
	else
	{
		puts("1~4������ �޴��� ������ �ֽʽÿ�.");
		getch();
		fclose(fp);
		AdjAdmin(cnt);
	}
}

void AddAdmin(int * cnt)
{
	FILE * fp=fopen("administrator.txt", "at");
	char id[15], pw[20];
	int grade, ret, tempcnt=0, n;
	system("cls");
	puts("---------------������ �߰�---------------");
	while(1)
	{
		id[0]=0;id[1]=0;id[2]=0;id[3]=0;id[4]=0;id[5]=0;id[6]=0;id[7]=0;id[8]=0;
		id[9]=0;id[10]=0;id[11]=0;id[12]=0;id[13]=0;id[14]=0;
		printf("���̵�: "); scanf("%s", id);

		ret=Re_Check_Admin(id, &tempcnt);
		
		if((id[10]>47&&id[10]<58)||(id[10]>64&&id[10]<91)||(id[10]>96&&id[10]<123))
		{
			puts("���̵� 10�ڸ� �ʰ��Ͽ����ϴ�.");
			continue;
		}
		else if(!((id[0]>='0'&&id[0]<='9')||(id[0]>='A'&&id[0]<='Z')||(id[0]>='a'&&id[0]<='z'))
			||!((id[1]>='0'&&id[1]<='9')||(id[1]>='A'&&id[1]<='Z')||(id[1]>='a'&&id[1]<='z')||(id[1]==0))
			||!((id[2]>='0'&&id[2]<='9')||(id[2]>='A'&&id[2]<='Z')||(id[2]>='a'&&id[2]<='z')||(id[2]==0)||(id[2]==-52))
			||!((id[3]>='0'&&id[3]<='9')||(id[3]>='A'&&id[3]<='Z')||(id[3]>='a'&&id[3]<='z')||(id[3]==0)||(id[3]==-52))
			||!((id[4]>='0'&&id[4]<='9')||(id[4]>='A'&&id[4]<='Z')||(id[4]>='a'&&id[4]<='z')||(id[4]==0)||(id[4]==-52))
			||!((id[5]>='0'&&id[5]<='9')||(id[5]>='A'&&id[5]<='Z')||(id[5]>='a'&&id[5]<='z')||(id[5]==0)||(id[5]==-52))
			||!((id[6]>='0'&&id[6]<='9')||(id[6]>='A'&&id[6]<='Z')||(id[6]>='a'&&id[6]<='z')||(id[6]==0)||(id[6]==-52))
			||!((id[7]>='0'&&id[7]<='9')||(id[7]>='A'&&id[7]<='Z')||(id[7]>='a'&&id[7]<='z')||(id[7]==0)||(id[7]==-52))
			||!((id[8]>='0'&&id[8]<='9')||(id[8]>='A'&&id[8]<='Z')||(id[8]>='a'&&id[8]<='z')||(id[8]==0)||(id[8]==-52))
			||!((id[9]>='0'&&id[9]<='9')||(id[9]>='A'&&id[9]<='Z')||(id[9]>='a'&&id[9]<='z')||(id[9]==0)||(id[9]==-52)))
		{
			puts("���̵�� ����/���� �������θ� ������ �� �ֽ��ϴ�.");
			continue;
		}
		else if(id[0]==48&&id[1]==0)
		{
			puts("���̵�� ���� 0�� ����� �� �����ϴ�.");
			continue;
		}
		else if (ret)
		{
			puts("����� �� �ִ� ���̵� �Դϴ�.");
			break;
		}
		else
		{
			puts("�̹� ������� ���̵� �Դϴ�.");
			continue;
		}
		
	}
	puts("15�������� ����/���� �������� ��й�ȣ�� �Է��Ͻʽÿ�.");
	while(1)
	{
		pw[1]=0;pw[2]=0;pw[3]=0;pw[4]=0;pw[5]=0;pw[6]=0;pw[7]=0;pw[8]=0;pw[9]=0;pw[10]=0;
		pw[11]=0;pw[12]=0;pw[13]=0;pw[14]=0;pw[15]=0;pw[16]=0;pw[17]=0;pw[18]=0;pw[19]=0;pw[0]=0;
		printf("��й�ȣ: "); scanf("%s", pw);
		if((pw[15]>47&&pw[15]<58)||(pw[15]>64&&pw[15]<91)||(pw[15]>96&&pw[15]<123))
		{
			puts("��й�ȣ�� 15�ڸ� �ʰ��Ͽ����ϴ�.");
			continue;
		}
		else if(!((pw[0]>='0'&&pw[0]<='9')||(pw[0]>='A'&&pw[0]<='Z')||(pw[0]>='a'&&pw[0]<='z'))
			||!((pw[1]>='0'&&pw[1]<='9')||(pw[1]>='A'&&pw[1]<='Z')||(pw[1]>='a'&&pw[1]<='z')||(pw[1]==0))
			||!((pw[2]>='0'&&pw[2]<='9')||(pw[2]>='A'&&pw[2]<='Z')||(pw[2]>='a'&&pw[2]<='z')||(pw[2]==0)||(pw[2]==-52))
			||!((pw[3]>='0'&&pw[3]<='9')||(pw[3]>='A'&&pw[3]<='Z')||(pw[3]>='a'&&pw[3]<='z')||(pw[3]==0)||(pw[3]==-52))
			||!((pw[4]>='0'&&pw[4]<='9')||(pw[4]>='A'&&pw[4]<='Z')||(pw[4]>='a'&&pw[4]<='z')||(pw[4]==0)||(pw[4]==-52))
			||!((pw[5]>='0'&&pw[5]<='9')||(pw[5]>='A'&&pw[5]<='Z')||(pw[5]>='a'&&pw[5]<='z')||(pw[5]==0)||(pw[5]==-52))
			||!((pw[6]>='0'&&pw[6]<='9')||(pw[6]>='A'&&pw[6]<='Z')||(pw[6]>='a'&&pw[6]<='z')||(pw[6]==0)||(pw[6]==-52))
			||!((pw[7]>='0'&&pw[7]<='9')||(pw[7]>='A'&&pw[7]<='Z')||(pw[7]>='a'&&pw[7]<='z')||(pw[7]==0)||(pw[7]==-52))
			||!((pw[8]>='0'&&pw[8]<='9')||(pw[8]>='A'&&pw[8]<='Z')||(pw[8]>='a'&&pw[8]<='z')||(pw[8]==0)||(pw[8]==-52))
			||!((pw[9]>='0'&&pw[9]<='9')||(pw[9]>='A'&&pw[9]<='Z')||(pw[9]>='a'&&pw[9]<='z')||(pw[9]==0)||(pw[9]==-52))
			||!((pw[10]>='0'&&pw[10]<='9')||(pw[10]>='A'&&pw[10]<='Z')||(pw[10]>='a'&&pw[10]<='z')||(pw[10]==0)||(pw[10]==-52))
			||!((pw[11]>='0'&&pw[11]<='9')||(pw[11]>='A'&&pw[11]<='Z')||(pw[11]>='a'&&pw[11]<='z')||(pw[11]==0)||(pw[11]==-52))
			||!((pw[12]>='0'&&pw[12]<='9')||(pw[12]>='A'&&pw[12]<='Z')||(pw[12]>='a'&&pw[12]<='z')||(pw[12]==0)||(pw[12]==-52))
			||!((pw[13]>='0'&&pw[13]<='9')||(pw[13]>='A'&&pw[13]<='Z')||(pw[13]>='a'&&pw[13]<='z')||(pw[13]==0)||(pw[13]==-52))
			||!((pw[14]>='0'&&pw[14]<='9')||(pw[14]>='A'&&pw[14]<='Z')||(pw[14]>='a'&&pw[14]<='z')||(pw[14]==0)||(pw[14]==-52)))
		{
			puts("��й�ȣ�� ����/���� �������θ� ������ �� �ֽ��ϴ�.");
			continue;
		}
		else
			break;
	}
	puts("1->�ְ������ 2->�߰������� 3->�Ϲݰ�����");//�����ڿ��� ����� �ο�, ��޿� ���� ������ �� �ִ� �޴��� �ٸ�
	printf("�������� ���: "); scanf("%d", &grade);
	fprintf(fp, "%-12s %-17s %-2d\n", id, pw, grade);
	puts("������ �߰� �Ϸ�.\n");
	puts("1. ������ ��޿� ���ؼ� �� �˾ƺ���");
	puts("2. ���ư���");
	printf("Choose: "); scanf("%d", &n);
	if(n==1)
	{
		puts("1���, 2���, 3������� ������ ����� ������ ��޿� ���� ������ �� �ִ� ������ ����޴���");
		puts("�������� �� �ֽ��ϴ�. 1��� �����ڴ� ��� ������ ����޴��� ������ �� �ְ�, 2��� �����ڴ�");
		puts("������ �߰�/���� �� ��޺��� �޴��� ������ ��� �޴��� ���� �����մϴ�. ");
		puts("3��� �����ڴ� ȸ������ ��ȸ �� ���Գ��� ��ȸ �޴����� ���� �����մϴ�.");
		puts("Press any key to return");
		getch();
		fclose(fp);
		AdminMenu(cnt);
	}
	else if (n==2)
	{
		puts("Press any key to return");
		getch();
		fclose(fp);
		AdjAdmin(cnt);
	}
}

void DelAdmin(int * cnt)
{
	FILE * fp1=fopen("administrator.txt", "rt");
	FILE * fp2=fopen("administrator.txt", "r+");
	
	char id[15];
	char tempid[15], temppw[20];
	int grade, tc=0, n;
	int i=0, j=0, k=0;
	system("cls");
	puts("---------------������ ���� ����---------------");
	puts("1. ������ ����"); puts("2. ���ư���");
	printf("Choose: "); scanf("%d", &n);
	if(n==1)
	{
		printf("������ ������ ���̵�: "); scanf("%s", id);
		while(1)
		{
			fscanf(fp1, "%s %s %d", tempid, temppw, &grade);
			tc++;
			if(!strcmp(id, tempid))
				break;
			else if(feof(fp1))
			{
				puts("��ϵ��� ���� ���̵��Դϴ�.");
				getch();
				fclose(fp1); fclose(fp2);
				DelAdmin(cnt);
			}
			else
				continue;
		}
		fseek(fp2, 35, 0);
		if(tc>2)
		{
			n=tc-2;
			while(n)
			{
				fseek(fp2, 35, 1);
				n--;
			}
		}
		fprintf(fp2, "%-12d %-17d %-2d", i, j, k);
		puts("������ �Ϸ�Ǿ����ϴ�.");
		getch();
		fclose(fp1); fclose(fp2);
		AdjAdmin(cnt);
	}
	else if(n==2)
	{
		puts("Press any key to return");
		getch();
		fclose(fp1); fclose(fp2);
		AdjAdmin(cnt);
	}
	else
	{
		puts("1~2������ �޴��� ������ �ּ���");
		getch();
		fclose(fp1); fclose(fp2);
		DelAdmin(cnt);
	}

}

void ChangeGradeAdmin(int * cnt)
{
	FILE * fp1=fopen("administrator.txt", "rt");
	FILE * fp2=fopen("administrator.txt", "r+");
	int n, i;
	char id[15];
	char tempid[15], temppw[20];
	int grade, tempgrade, tc=0;
	system("cls");
	puts("---------------������ ��� ����---------------");
	puts("1. ������ ��� ����"); puts("2. ���ư���");
	printf("Choose: "); scanf("%d", &i);
	if(i==1)
	{
		printf("���� �� ���̵�: "); scanf("%s", id);
		while(1)
		{
			fscanf(fp1, "%s %s %d", tempid, temppw, &grade);
			tc++;
			if(!strcmp(id, tempid))
				break;
			else if(feof(fp1))
			{
				puts("��ϵ��� ���� ���̵��Դϴ�.");
				getch();
				fclose(fp1); fclose(fp2);
				DelAdmin(cnt);
			}
			else
				continue;
		}
		tempgrade=grade;
		printf("���� %d ����� ������ �����Դϴ�.\n", grade);
		printf("�� ������� �ٲٽðڽ��ϱ�?: "); scanf("%d", &grade);
		if (tempgrade == grade)
		{
			puts("�ٲٽ÷��� ��ް� ������ ����� �Ȱ����ϴ�.");
			getch();
			fclose(fp1); fclose(fp2);
			ChangeGradeAdmin(cnt);
		}
		if(tc==1)
		{
			fseek(fp2, 31, 0);
			fprintf(fp2, "%-2d", grade);
			puts("���� �Ϸ� �ƽ��ϴ�.");
			getch();
			fclose(fp1); fclose(fp2);
			AdjAdmin(cnt);
		}
		else if(tc==2)
		{
			fseek(fp2, 35, 0);
			fseek(fp2, 31, 1);
			fprintf(fp2, "%-2d", grade);
			puts("���� �Ϸ� �ƽ��ϴ�.");
			getch();
			fclose(fp1); fclose(fp2);
			AdjAdmin(cnt);
		}
		else
		{
			n=tc-2;
			fseek(fp2, 35, 0);
			while(n)
			{
				fseek(fp2, 35, 1);
				n--;
			}
			fseek(fp2, 31, 1);
			fprintf(fp2, "%-2d", grade);
			puts("���� �Ϸ� �ƽ��ϴ�.");
			getch();
			fclose(fp1); fclose(fp2);
			AdjAdmin(cnt);
		}
	}
	else if(i==2)
	{
		puts("Press any key to return");
		getch();
		fclose(fp1); fclose(fp2);
		AdjAdmin(cnt);
	}
	else
	{
		puts("1~2 ���� ���� �޴��� ������ �ֽʽÿ�.");
		getch();
		fclose(fp1); fclose(fp2);
		ChangeGradeAdmin(cnt);
	}
}

void ShowMember(int * cnt)
{
	FILE * fp=fopen("member.txt", "rt");
	typedef struct member
	{
		char id[20];
		char pw[20];
		int carnum;
		char phon[15];
		int order;
	}Member;
	Member mem;
	int tc=0, i;
	system("cls");
	puts("---------------ȸ����ȸ---------------");
	printf("���̵�   ��й�ȣ   ������ȣ     ��ȭ��ȣ\n");
	while(1)
	{
		fscanf(fp, "%s %s %d %s %d", mem.id, mem.pw, &mem.carnum, mem.phon, &mem.order);
		tc++;
		if(feof(fp))
			break;
	}
	fseek(fp, 0, 0);
	tc-=1;
	for(i=0; i<tc; i++)
	{
		fscanf(fp, "%s %s %d %s %d\n", mem.id, mem.pw, &mem.carnum, mem.phon, &mem.order);
		printf("%-8s %-10s %-12d %-17s\n", mem.id, mem.pw, mem.carnum, mem.phon);
	}
	puts("1. ȸ�� ����"); puts("2. ���ư���");
	printf("Choose: "); scanf("%d", &i);
	if (i==1)
	{
		fclose(fp);
		DelMember(cnt);
	}
	else if(i==2)
	{
		fclose(fp);
		AdminMenu(cnt);
	}
	else
	{
		puts("1~2������ �޴��� ������ �ֽʽÿ�.");
		getch();
		fclose(fp);
		ShowMember(cnt);
	}
}

void DelMember(int * cnt)
{
	FILE * fp=fopen("administrator.txt", "rt");
	FILE * fp1=fopen("member.txt", "rt");
	FILE * fp2=fopen("member.txt", "r+");
	int i, n, grade;
	char id[15];
	typedef struct member
	{
		char id[20];
		char pw[20];
		int carnum;
		char phon[15];
		int order;
	}Member;
	Member mem;
	int tc=0;

	n=*cnt; n-=2;
	if(*cnt==1)
	{
		fseek(fp, 31, 0);
		fscanf(fp, "%d", &grade);
	}
	else if (*cnt==2)
	{
		fseek(fp, 35, 0);
		fseek(fp, 31, 1);
		fscanf(fp, "%d", &grade);
	}
	else
	{
		fseek(fp, 35, 0);
		while(n)
		{
			fseek(fp, 35, 1);
			n--;
		}
		fseek(fp, 31, 1);
		fscanf(fp, "%d", &grade);
	}
	if (grade>1)
	{
		puts("�� �޴��� �Ѱ����� �Ǵ� �߰�������(Grade 2 �̻�)�� ������ �� �ֽ��ϴ�.");
		getch();
		fclose(fp);
		AdminMenu(cnt);
	}
	system("cls");
	puts("---------------�Ϲ�ȸ�� ���� ����---------------");
	puts("1. ȸ�� ��ȸ"); puts("2. ȸ�� ����"); puts("3. ���ư���");
	printf("Choose: "); scanf("%d", &i);

	if(i==1)
	{
		ShowMember(cnt);
	}
	else if(i==2)
	{
		printf("������ ȸ�� ���̵�: "); scanf("%s", id);
		while(1)
		{
			fscanf(fp1, "%s %s %d %s %d", mem.id, mem.pw, &mem.carnum, mem.phon, &mem.order);
			tc++;
			if(!strcmp(id, mem.id))
				break;
			else if(feof(fp1))
			{
				puts("��ϵ��� ���� ���̵��Դϴ�.");
				getch();
				fclose(fp1); fclose(fp2);
				DelMember(cnt);
			}
			else
				continue;
		}
		n=tc; n-=2;
		if(tc==1)
		{
			fprintf(fp2, "%-12d %-17d %-6d %-17d %-10d", 0, 0, 0, 0, 0);
			puts("���� �Ϸ�!");
			getch();
			fclose(fp1); fclose(fp2);
			AdminMenu(cnt);
		}
		else if(tc==2)
		{
			fseek(fp2, 68, 0); //fseek�Լ��� ��ĩ �߸��ϸ� ���Ͼ��� �����͸� ���׹������� ���� ���� �־� ����Կ��־� �ſ� ���ɽ�������.
			fprintf(fp2, "%-12d %-17d %-6d %-17d %-10d", 0, 0, 0, 0, 0);
			puts("���� �Ϸ�!");
			getch();
			fclose(fp1); fclose(fp2);
			AdminMenu(cnt);
		}
		else
		{
			fseek(fp2, 68, 0);
			while(n)
			{
				fseek(fp2, 68, 1);
				n--;
			}
			fprintf(fp2, "%-12d %-17d %-6d %-17d %-10d", 0, 0, 0, 0, 0);
			puts("���� �Ϸ�!");
			getch();
			fclose(fp1); fclose(fp2);
			AdminMenu(cnt);
		}
	}
}

void Income(int * cnt)
{
	FILE * fp=fopen("income.txt", "rt"); 

	int year, month, day, income, total=0, tc=0;
	char id[15];
	system("cls");
	puts("---------------�ҵ� ���� ��ȸ---------------");
	while(1)
	{
		fscanf(fp, "%d %d %d %s %d", &year, &month, &day, id, &income);
		tc++;
		if (feof(fp))
			break;
	}
	tc-=1;
	fseek(fp, 0, 0);
	while(tc)
	{
		fscanf(fp, "%d %d %d %s %d", &year, &month, &day, id, &income);
		total += income;
		printf("%d�� %d�� %d�� ���̵�: %s  �ݾ�: %d��\n", year, month, day, id, income);
		tc--;
	}
	printf("�� ��: %d��\n", total);
	puts("Press any key to return");
	getch();
	fclose(fp);
	AdminMenu(cnt);

}