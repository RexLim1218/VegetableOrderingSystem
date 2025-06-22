#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>//new adding
#include<string.h>//new adding
#pragma warning(disable:4996)
#define PA 24.50
#define PB 26.00
#define PC 27.50
#define PD 29.00

void drawlogoWelcome();
void InputproOutput();
char nameCus[50], phNum[30], address1[50], address2[50], address3[50], address4[20], nCustomer;//date had been cancel
int a1, b1, c1, d1, customer=1;
double a2, b2, c2, d2, packChar, totalAmt, deliveryFEES, discount;
time_t t;//new adding


void main() {
	
	drawlogoWelcome();
	
	do
	{
		InputproOutput();
		printf("\t\tNext customer(Y=yes)>");
		scanf("%c", &nCustomer);
		customer++;
	} while (nCustomer=='Y' || nCustomer == 'y');

	system("pause");
}




void drawlogoWelcome() {
	//variable declaration


	printf("\t\t\t\t       GGGGGGG   H         H     \n");
	printf("\t\t\t\t      GG     GG  H         H     \n");
	printf("\t\t\t\t      GG         H         H     \n");
	printf("\t\t\t\t      GG         H HHHHHHH H     \n");
	printf("\t\t\t\t      GG   GGGG  H         H     \n");
	printf("\t\t\t\t      GG     GG  H         H     \n");
	printf("\t\t\t\t      GG     GG  H         H     \n");
	printf("\t\t\t\t       GGGGGGG   H         H     \n");
	printf("\n");
	printf("\t\t\t      Welcome to GH Organic Vegetables Farm!!!\n");
	printf("\t\t\t\t    GH Organic Vegetables Farm\n \t\t\t\t     617,Taman JX,10106,Penang. \n");
	printf("\t\t--------------------------------------------------------------------------------------------");

	printf("\n");

	//input

}
void InputproOutput() {

	printf(" %61s \n", "Vegetable Ordering System");

	printf("\t\tCustomer No.%d",customer);
	rewind(stdin);
	printf("\n\n");

	printf("\t\tEnter name                  >");
	scanf("%[^\n]", nameCus);
	rewind(stdin);

	printf("\t\tEnter phone number          >");
	scanf("%[^\n]", phNum);
	rewind(stdin);



	printf("\t\tEnter house no.,area        >");
	scanf("%[^\n]", address1);
	rewind(stdin);



	printf("\t\tEnter state                 >");
	scanf("%[^\n]", address2);
	rewind(stdin);

	printf("\t\tEnter city or town          >");
	scanf("%[^\n]", address3);
	rewind(stdin);

	printf("\t\tEnter postal code           >");
	scanf("%[^\n]", address4);
	rewind(stdin);

	//date had been  cancel

	printf("\n");

	printf("\t\tEnter order quantity of package\n");
	printf("\t\tPackage A RM24.50=");
	scanf("%d", &a1);
	rewind(stdin);

	printf("\n\t\tPackage B RM26.00=");
	scanf("%d", &b1);
	rewind(stdin);

	printf("\n\t\tPackage C RM27.50=");
	scanf("%d", &c1);
	rewind(stdin);

	printf("\n\t\tPackage D RM29.00=");
	scanf("%d", &d1);
	rewind(stdin);

	//process
	a2 = a1 * PA;
	b2 = b1 * PB;
	c2 = c1 * PC;
	d2 = d1 * PD;
	packChar = a2 + b2 + c2 + d2;
	deliveryFEES = 5.00;
	/*totalAmt = packChar + deliveryFEES;
	discount = packChar * 0.15;*/

	//discount
	if (packChar >= 80.00) {
		deliveryFEES = 0.00;
		if (packChar >= 100) {
			discount = packChar * 0.15;
			totalAmt = packChar - discount;
		}
		else
		{
			discount = 0.00;
			totalAmt = packChar;
		}
	}
	else
	{
		deliveryFEES = 5.00;
		discount = 0.00;
		totalAmt = packChar + deliveryFEES;
	}



	time(&t);//new adding
	printf("\n\n");
	printf("\a");
	
	//output
	printf("\n\t\t--------------------------------------------------------------------------------------------\n");

	printf("\n\n");

	printf(" %61s \n", "Invoice");

	printf("\n");

	printf("\t\tBill from:\n");
	printf("\t\t617,GH Organic Vegetable Farm\n");
	printf("\t\tKepong,41000,Kuala Lumpur\n");
	printf("\n\n");


	printf("\t\tName:Mr/Ms %s", strupr(nameCus));
	
	printf("\n");

	printf("\t\tTelephone:%s\n", phNum);

	printf("\t\tAddress:%s,\n\t\t\t%s,%s,%s\n", strupr(address1), strupr(address3), strupr(address2), strupr(address4));//new adding
	
	printf("\t\tPAYMENT METHOD: <CASH ON DELIVERY>\n");

	printf("\t\tDate: <%s>\n", ctime(&t));

	printf("\n");
	printf("\n");

	printf(" %69s \n", "CUSTOMER ORDERS");

	printf("\t\tNO                   PACKAGES                      QUANTITY    BASEPRICE(RM)    Amount(RM)\n");
	printf("\t\t--   ------------------------------------------   ----------   -------------   ------------ \n");
	printf("\t\t1    %-44s %10d %15.2f %14.2f\n", "A.KANGKUNG,CABBAGE,LADIES FINGER,BANANA", a1, 24.50, a2);
	printf("\t\t2    %-44s %10d %15.2f %14.2f\n", "B.YAM LEAVES,LONG BEAN,BRINJAL,GUAVA", b1, 26.00, b2);
	printf("\t\t3    %-44s %10d %15.2f %14.2f\n", "C.SNAKE BEANS,BROCCOLI,SPINACH,PAPAYA", c1, 27.50, c2);
	printf("\t\t4    %-44s %10d %15.2f %14.2f\n", "D.BAK CHOY,ASPARAGUS,BRINJAL,DRAGON FRUIT", d1, 29.00, d2);

	printf("\t\t\t\t\t\t\t\t\t\t               ------------\n");
	printf("%92s %14.2f\n", "PACKAGE CHARGES", packChar);
	printf("%92s %14.2f\n", "Discount", discount);
	printf("%92s %14.2f\n", "DELIVERY FEES", deliveryFEES);
	printf("%92s %14.2f\n", "TOTAL PAYMENT", totalAmt);
	printf("\t\t\t\t\t\t\t\t\t\t               ------------\n\n");
	printf("\n\t\t--------------------------------------------------------------------------------------------\n");
	printf("%91s\n", "THANK YOU FOR SUPPORTING OUR BUSINESS DURING COVID-19 PANDEMIC");
	printf(" %61s \n", "Stays Safe!");





	/*
	just double check
	printf("\t\tPACKAGE A %d @ RM24.50 = RM%.2f\n", a1, a2);
	printf("\t\tPACKAGE B %d @ RM26.00 = RM%.2f\n", b1, b2);
	printf("\t\tPACKAGE C %d @ RM27.50 = RM%.2f\n", c1, c2);
	printf("\t\tPACKAGE D %d @ RM29.00 = RM%.2f\n", d1, d2);
	printf("\t\tPACKAGE Charges =RM%.2f\n", packChar);
	printf("\t\tDelivery Fees   =RM%.2f\n", DeliveryFEES);
	printf("\t\tTotal to pay    =RM%.2f\n", totalAmt);

	*/







}