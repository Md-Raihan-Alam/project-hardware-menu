#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define managerPassword "manager@112233"
struct EMPLOYEE{
    long long int empId;
    char empName[100];
    char empPos[100];
    char empPhoneNumber[100];
    long long int empSalary;
    int empAge;
    double empPerformanceRate;
};
struct CUSTOMER{
    char customerName[100];
    char customerPhoneNumber[100];
    char itemName[100];
    char itemBrandName[100];
    long long int price;
    long long int productId;
};
struct CUSTOMERINFO{
    char customerName[100];
    char customerPhoneNumber[100];
    char itemName[100];
    char itemBrandName[100];
    long long int price;
    long long int productId;
};
int employeeMenu();
void customerData();
void customerInfo();
void managerLogin();
int managerMenu();
void hireEmployee();
void employeeData();
int main(void)
{
    int choices;
    while(1)
    {
        choices=employeeMenu();
        if(choices==1) customerInfo();
        else if(choices==2) customerData();
        else if(choices==3) managerLogin();
        else if(choices==4) {
            printf("\n---Exiting Program---\n");
            break;
        }
        else printf("Enter number between 1 to 4.\n");
    }
    return 0;
}
int employeeMenu(){
    int optionNo;
    printf("\n---Welcome to hardware management menu as employee---\n");
    printf("1.Enter selling product and customer data.\n");
    printf("2.Customer Informations\n");
    printf("3.Manager Menu\n");
    printf("4.Quit Menu\n:");
    scanf("%d",&optionNo);
    return optionNo;
}
void customerData(){
    FILE *fp;
    struct CUSTOMERINFO cus;
    printf("\n---Customer Informations---\n");
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error reading data\n");
        exit(1);
    }
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus.productId,&cus.customerName,&cus.customerPhoneNumber,&cus.itemName,&cus.itemBrandName,&cus.price);
            printf("Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",cus.productId,cus.customerName,cus.customerPhoneNumber,cus.itemName,cus.itemBrandName,cus.price);
        }else{
            printf("Error in reading customer-pricing-data.txt file");
            exit(1);
        }
    }
    fclose(fp);
}
void customerInfo(){
    FILE *fp;
    struct CUSTOMER cus;
    printf("\n---Customer and Item Data---\n");
    fgetc(stdin);
    printf("Enter customer Name:");
    fgets(cus.customerName, 100, stdin);
    printf("Enter customer Phone number:");
    fgets(cus.customerPhoneNumber, 100, stdin);
    printf("Enter Item Name:");
    fgets(cus.itemName, 100, stdin);
    printf("Enter Item Brand Name:");
    fgets(cus.itemBrandName, 100, stdin);
    printf("Enter Item Id no:");
    scanf("%lld",&cus.productId);
    printf("Enter price in bd:");
    scanf("%lld",&cus.price);
    if((fp=fopen("customer-pricing-data.txt","a"))==NULL){
        printf("It seems file needs to be created first\n");
        exit(1);
    }
    if(!ferror(fp)) 
        fprintf(fp,"Product-Id:%lld\nCustomer-Name:%sCustomer-Phone-Number:%sItem-Name:%sItem-Brand-Name:%sPrice:%lld\n------\n",cus.productId,cus.customerName,cus.customerPhoneNumber,cus.itemName,cus.itemBrandName,cus.price);
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
            if(managerChoices==1) employeeData();
            else if(managerChoices==3) hireEmployee();
            else if(managerChoices==5) {
                printf("\n---Logging out---\n");
                break;
            }
            else printf("Enter proper number between 1 to 5\n");
        }
    }else{
        printf("\nWrong Password\n");
    }
}
int managerMenu(){
    printf("\n---Welcome to hardware management menu as manager---\n");
    printf("1.Employee Info\n");
    printf("2.Fire Employee\n");
    printf("3.Hire Employee\n");
    printf("4.Order new quantity\n");
    printf("5.Log out\n:");
    int manager_choices;
    scanf("%d",&manager_choices);
    return manager_choices;
}
void employeeData(){
    FILE *fp;
    if((fp=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error reading file. restart the program");
        exit(1);
    }
    struct EMPLOYEE emp;
    printf("\n\n---Employee Info---\n");
    // printf("%s %*s %*s %*s %*s %*s %*s\n","Employee-ID",20,"Employee-Name",30,"Employee-Phone-Number",20,"Employee-Age",30,"Employee-Position",30,"Employee-Salary",30,"Employee-Performance-Rate\n");
    while (!feof(fp))
    {
        if(ferror(fp)){
            printf("Error in file\n");
            exit(1);
        }else{
            fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
            // printf("%lld\t\t%s\t\t%s\t\t%d\t\t%s\t%20lld\t%lf\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
            printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
        }
    }
    fclose(fp);
}
void hireEmployee(){
    FILE *fp;
    struct EMPLOYEE emp;
    printf("Enter Employee Id:");
    scanf("%lld",&emp.empId);
    fgetc(stdin);
    printf("Enter Employee Name:");
    // scanf("%s",&emp.empName);
    fgets(emp.empName,100,stdin);
    printf("Enter Employee Position:");
    fgets(emp.empPos,100,stdin);
    printf("Enter Employee Phone number:");
    // scanf("%s",&emp.empPhoneNumber);
    fgets(emp.empPhoneNumber,100,stdin);
    printf("Enter Employee Age:");
    scanf("%d",&emp.empAge);
    printf("Enter Employee Salary in bd:");
    scanf("%lld",&emp.empSalary);
    printf("Enter Employee Performace Rate:");
    scanf("%lf",&emp.empPerformanceRate);
    if((fp=fopen("Employee-Info.txt","a"))==NULL){
        printf("Error writing employee file");
        exit(1);
    }
    if(!ferror(fp))
        fprintf(fp,"Employee-Id:%lld\nEmployee-Name:%sEmployee-Phone-Number:%sEmployee-Age:%d\nEmployee-Position:%sEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
    else
        printf("Error in file\n");
    fclose(fp);
}