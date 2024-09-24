#include <stdio.h>

int main() {
	int jishu(int pass, int passN, int passG, int passP);
	int pass, unitprice, number;//buy为购买通道，sc为投币数目,n为购买数目,m，i，signal为判断
	char goods;
	int passN[6] = { 0 };
	int passP[6] = { 0 };
	int passG[6] = { 0 };
	printf("请装填货物，按照名称 通道 单价 数量顺序填写\n");
	int j = 0;
	do {
		scanf_s("%c", &goods,1);//货物名称
		scanf_s("%d", &pass);
		scanf_s("%d", &unitprice);
		scanf_s("%d", &number);
		if (pass > 5 || pass < 1) {
			printf("不存在此通道\n");
		}
		else if (goods > 90 || goods < 65) {
			printf("不存在此货物\n");
		}
		else if (unitprice > 9 || unitprice < 1) {
			printf("定价不合理\n");
		}
		else if(passN[pass]==0){
			passN[pass] = number; 
			passP[pass] = unitprice;
			passG[pass] = goods;
			j++;
		}
		else if (passN[pass] != 0) {
			printf("当前通道已有货物请重新放置\n");
		}
		scanf_s("%*c");
	}//通道 单价 数量
	while(pass > 5 || pass < 1 || unitprice > 9 || unitprice < 1 || goods > 90 || goods < 65||j<5);
	while(j==5){
	int unitsum = 0;
	int p = 0;
	int sum = 0;
	do {
		printf("请输入购买通道:");
		scanf_s("%d", &pass);
		switch (pass) {
		case 1:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 2:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 3:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 4:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 5:
			unitprice = 0;
			unitsum += jishu(pass, passN[pass], passG[pass], passP[pass]);
			passN[pass] -= unitsum / passP[pass];
			sum += unitsum;
			printf("当前共需要%d元，输入0结束购买\n", sum);
			break;
		case 0:
			p = 1;
			break;
		default:
			printf("不存在此通道，请重新输入");
			break;
		};
	} while (p != 1);
		printf("共需要%d元，请投币\n", sum);
		int coin;
		scanf_s("%d", &coin);   //第三步：投币
		int sc = 0;
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
		sc = 0;//初始化金额
		printf("是否继续购买,输入1继续\n");  //是否继续购买
		int m = 0;  
		scanf_s("%d", &m);
		if (m ==1) {
			continue;
		}
		else { break; };
	};
	printf("祝您购物愉快");
	return 0;
	}
static int jishu(int pass, int passN, int passG, int passP) {
	int n;
	int sum = 0;
	printf("通道%d:", pass);
	for (int i = 0; i < passN; i++) {
		printf("%c", passG);
	};
	printf("此商品单价为%d\n",passP);
	while (passN > 0) {                      //进入购买页面
		printf("需要购买的数量\n");       //第二步：购买数量
		scanf_s("%d", &n);
		if (n <= passN) {
			passN -= n;
			sum += passP * n;
			break;
		}
		else {       //数量不足
			printf("商品数量不足\n");
		};
	};
	return sum;
}
