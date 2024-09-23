#include <stdio.h>

int main(){
	int pass, unitprice, number, i, n, coin, sc = 0, buy, signal,m;//buy为购买通道，sc为投币数目,n为购买数目,m，i，signal为判断
	char goods;
	printf("请装填货物，按照名称 通道 单价 数量顺序填写\n");
	do{scanf_s("%c", &goods);//货物名称
		scanf_s("%d %d %d", &pass, &unitprice, &number);
		if (pass > 5 ||pass<1|| unitprice > 9 ||unitprice<1|| goods > 90 || goods < 65) {
			printf("参数异常，请重新输入\n");
		}
	}//通道 单价 数量
	while(pass > 5 || unitprice > 10 || goods > 90 || goods < 65);
	printf("通道%d:",pass);                  //显示装填情况
	for (i = 0; i < number; i++) {
		printf("%c", goods);
	};
	printf(" 单价为%d\n", unitprice);
	do {                                      //第一步：购买通道
		printf("请输入购买通道\n");
		scanf_s("%d", &buy);
		if (buy!= pass) {
			signal = 1;
			printf("该通道不存在或该通道没有商品\n");
		}
		else { break; }
	} while (signal == 1);
	while (number > 0) {                      //进入购买页面
		printf("通道%d情况",buy);
			for (i = 0; i < number; i++) {
				printf("%c", goods);
			};
			printf("\n");
		while (number > 0) {
			printf("需要购买的数量\n");       //第二步：购买数量
			scanf_s("%d", &n);         
			if (n <= number) {
				number -= n;
				break;
			}
			else {       //数量不足
				printf("商品数量不足\n");
			};
		};
		const int sum = unitprice * n;
		printf("需要%d元，请投币\n", sum);
		scanf_s("%d", &coin);                 //第三步：投币
		sc += coin;
		while (coin == 1 || coin == 2 || coin == 5 && sum > 0) {
			printf("已投入%d元\n", sc);
			scanf_s("%d", &coin);
			if (coin != 1 && coin != 2 && coin != 5) {
				break;
			};
			sc += coin;
			if (sc == sum) {
				printf("购物结束\n");
				break;
			};
			if (sc > sum) {
				printf(" 购物结束,找零%d\n", sc - sum);
				break;
			};
		};
		if (coin != 1 && coin != 2 && coin != 5) {   //投币限制
			printf("不合规\n");
			number += n;//商品退回
		};
		sc = 0;//初始化金额
		printf("是否继续购买,输入1继续\n");       //是否继续购买
		scanf_s("%d", &m);
		if (m ==1) {
			continue;
		}
		else { break; };
	};
	return 0;
	}