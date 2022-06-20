#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define managerPassword "manager@112233"
int employeeMenu();
void customerData();
void managerLogin();
int managerMenu();
// void exitMenu();
int main(void)
{
    int choices;
    while(1)
    {
        choices=employeeMenu();
        if(choices==1) customerData();
        else if(choices==2) managerLogin();
        // else if(choices==3) exitMenu();
        else printf("Enter number between 1 to 3.\n");
    }
    return 0;
}
int employeeMenu(){
    int optionNo;
    printf("\n---Welcome to hardware shop menu as employee---\n");
    printf("1.Enter selling product and customer data.\n");
    printf("2.Manager Menu\n");
    printf("3.Quit Menu\n:");
    scanf("%d",&optionNo);
    return optionNo;
}
void customerData(){
    FILE *fp;
    char customerName[100];
    char customerPhoneNumber[100];
    char itemName[100];
    char itemBrandName[100];
    long long int price;
    long long int productId;
    printf("\n---Customer and Product Data---\n");
    printf("Enter product Id no:");
    scanf("%lld",&productId);
    printf("Enter customer Name:");
    scanf("%s",&customerName);
    printf("Enter customer Phone number:");
    scanf("%s",&customerPhoneNumber);
    printf("Enter Item Name:");
    scanf("%s",&itemName);
    printf("Enter Item Brand Name:");
    scanf("%s",&itemBrandName);
    printf("Enter price in bd:");
    scanf("%lld",&price);
    // printf("Name:%s,productId:%lld,PhoneNumber:%s,ItemName:%s,ItemBrandName:%s,Price:%lld\n",customerName,productId,customerPhoneNumber,itemName,itemBrandName,price);
    if((fp=fopen("customer-pricing-data.txt","a"))==NULL){
        printf("It seems file needs to be created first\n");
        exit(1);
    }
    if(!ferror(fp)) 
        fprintf(fp,"Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",productId,customerName,customerPhoneNumber,itemName,itemBrandName,price);
    else {
        printf("Error writing data\n");
        exit(1);
    }
    fclose(fp);
    printf("\n");
}
void managerLogin(){
    printf("\n---Manager Login---\n");
    char pass[100];
    printf("Enter password:");
    scanf("%s",&pass);
    if((strcmp(pass,managerPassword))==0){
        while(1){
            int managerChoices=managerMenu();
        }
    }else{
        printf("\nWrong Password\n");
    }
}
int managerMenu(){
    printf("\n---Welcome to hardware shop menu as manager---\n");
    printf("\n1.Employee Info\n");
    printf("\n2.Fire Employee\n");
    printf("\n3.Hire Employee\n");
    printf("\n4.Order new quantity\n:");
    int manager_choices;
    scanf("%d",&manager_choices);
    return manager_choices;
}