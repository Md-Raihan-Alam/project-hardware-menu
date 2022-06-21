#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
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
void customersInformationSearch();
void searchItemId();
void searchCustomerName();
void searchPhoneNumber();
void searchItemName();
void searchBrandName();
void searchPrices();
void empInformationSearch();
void searchEmpId();
void searchEmpName();
void searchEmpPos();
void searchEmpPerRate();
void searchEmpSalary();
void searchEmpPhone();
int main(void)
{
    int choices;
    while(1)
    {
        choices=employeeMenu();
        if(choices==1) customerInfo();
        else if(choices==2) customerData();
        else if(choices==3) managerLogin();
        else if(choices==4) customersInformationSearch();
        else if(choices==5) {
            printf("\n---Exiting Program---\n");
            break;
        }
        else printf("Enter number between 1 to 5.\n");
    }
    return 0;
}
int employeeMenu(){
    int optionNo;
    printf("\n---Welcome to hardware management menu as employee---\n");
    printf("1.Enter selling product and customer data.\n");
    printf("2.Customer Informations\n");
    printf("3.Manager Menu\n");
    printf("4.Search Customers Information\n");
    printf("5.Quit Menu\n:");
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
void customersInformationSearch(){
    printf("\n---WELCOME TO CUSTOMER INFORMATION SEARCHING OPTIONS---\n");
    int searchChoices;
    printf("\n1.Search by Item Id.\n");
    printf("2.Search by Customer Name.\n");
    printf("3.Search by Customer Phone Number\n");
    printf("4.Search by Item Name\n");
    printf("5.Search by Item Brand Name\n");
    printf("6.Search by Price\n:");
    scanf("%d",&searchChoices);
    if(searchChoices==1) searchItemId();
    else if(searchChoices==2) searchCustomerName();
    else if(searchChoices==3) searchPhoneNumber();
    else if(searchChoices==4) searchItemName();
    else if(searchChoices==5) searchBrandName();
    else if(searchChoices==6) searchPrices();
    else printf("\nEnter proper number next time\n");
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
            else if(managerChoices==4) customerData();
            else if(managerChoices==5) customerInfo();
            else if(managerChoices==6) empInformationSearch();
            else if(managerChoices==7) {
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
    printf("4.Customer Informations\n");
    printf("5.Enter selling product and customer data\n");
    printf("6.Search Employee Informations\n");
    printf("7.Log out\n:");
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
void searchItemId(){
    long long int searchProductId;
    int found=0;
    FILE *fp;
    struct CUSTOMER cus;
    printf("\n\nEnter the product Id you want to search:");
    scanf("%lld",&searchProductId);
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error in searching the file with product id");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus.productId,&cus.customerName,&cus.customerPhoneNumber,&cus.itemName,&cus.itemBrandName,&cus.price);
            if(cus.productId==searchProductId){
                found=1;
               printf("Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",cus.productId,cus.customerName,cus.customerPhoneNumber,cus.itemName,cus.itemBrandName,cus.price); 
            }
        }else{
            printf("Error in file while searching by item id");
            exit(1);
        }
    }
    if(found==0) printf("\nNo Data found\n");
    fclose(fp);
}
void searchCustomerName(){
    int found=0;
    char searchCusName[100];
    FILE *fp;
    struct CUSTOMER cus;
    fgetc(stdin);
    printf("\n\nEnter the customer name you want to search:");
    fgets(searchCusName,100,stdin);
    searchCusName[strcspn(searchCusName, "\n")] = 0;
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error in searching the file with product id");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    printf(searchCusName);
    printf("\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus.productId,&cus.customerName,&cus.customerPhoneNumber,&cus.itemName,&cus.itemBrandName,&cus.price);
            if(strcmp(cus.customerName,searchCusName)==0){
                found=1;
                printf("Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",cus.productId,cus.customerName,cus.customerPhoneNumber,cus.itemName,cus.itemBrandName,cus.price); 
            }
        }else{
            printf("Error in file while searching by item id");
            exit(1);
        }
    }
    if(found==0) printf("\nNo Data found\n");
    fclose(fp);
}
void searchPhoneNumber(){
    int found=0;
    char searchPhoNum[100];
    FILE *fp;
    struct CUSTOMER cus;
    fgetc(stdin);
    printf("\n\nEnter the customer phone number you want to search:");
    fgets(searchPhoNum,100,stdin);
    searchPhoNum[strcspn(searchPhoNum, "\n")] = 0;
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error in searching the file with product id");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus.productId,&cus.customerName,&cus.customerPhoneNumber,&cus.itemName,&cus.itemBrandName,&cus.price);
            if(strcmp(cus.customerPhoneNumber,searchPhoNum)==0){
                found=1;
                printf("Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",cus.productId,cus.customerName,cus.customerPhoneNumber,cus.itemName,cus.itemBrandName,cus.price); 
            }
        }else{
            printf("Error in file while searching by item id");
            exit(1);
        }
    }
    if(found==0) printf("\nNo Data found\n");
    fclose(fp);
}
void searchItemName(){
    int found=0;
    char searchItName[100];
    FILE *fp;
    struct CUSTOMER cus;
    fgetc(stdin);
    printf("\n\nEnter the Item name you want to search:");
    fgets(searchItName,100,stdin);
    searchItName[strcspn(searchItName, "\n")] = 0;
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error in searching the file with product id");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus.productId,&cus.customerName,&cus.customerPhoneNumber,&cus.itemName,&cus.itemBrandName,&cus.price);
            // printf("%s %d %s\n",searchItName,strcmp(searchItName,cus.itemName),cus.itemName);
            if(strcmp(cus.itemName,searchItName)==0){
                found=1;
                printf("Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",cus.productId,cus.customerName,cus.customerPhoneNumber,cus.itemName,cus.itemBrandName,cus.price); 
            }
        }else{
            printf("Error in file while searching by item id");
            exit(1);
        }
    }
    if(found==0) printf("\nNo Data found\n");
    fclose(fp);
}
void searchBrandName(){
    int found=0;
    char searchBrand[100];
    FILE *fp;
    struct CUSTOMER cus;
    fgetc(stdin);
    printf("\n\nEnter the Item Brand name you want to search:");
    fgets(searchBrand,100,stdin);
    searchBrand[strcspn(searchBrand, "\n")] = 0;
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error in searching the file with product id");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus.productId,&cus.customerName,&cus.customerPhoneNumber,&cus.itemName,&cus.itemBrandName,&cus.price);
            if(strcmp(cus.itemBrandName,searchBrand)==0){
                found=1;
                printf("Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",cus.productId,cus.customerName,cus.customerPhoneNumber,cus.itemName,cus.itemBrandName,cus.price); 
            }
        }else{
            printf("Error in file while searching by item id");
            exit(1);
        }
    }
    if(found==0) printf("\nNo Data found\n");
    fclose(fp);
}
void searchPrices(){
    char ch;
    printf("\n\nDo you wish to select a range?\n(Select Y for range/Select N for specific number)\n:");
    ch=getche();
    if(toupper(ch)=='Y'){
        long long int lowestRange;
        long long int highestRange;
        int found=0;
        FILE *fp;
        struct CUSTOMER cus;
        printf("\nEnter the minimum price you want to set:");
        scanf("%lld",&lowestRange);
        printf("Enter the maximum price you want to set:");
        scanf("%lld",&highestRange);
        if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
            printf("Error in searching the file with price");
            exit(1);
        }
        printf("\n---Search Results---:\n");
        while(!feof(fp)){
            if(!ferror(fp)){
                fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus.productId,&cus.customerName,&cus.customerPhoneNumber,&cus.itemName,&cus.itemBrandName,&cus.price);
                if((cus.price>=lowestRange) && (cus.price<=highestRange)){
                    found=1;
                   printf("Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",cus.productId,cus.customerName,cus.customerPhoneNumber,cus.itemName,cus.itemBrandName,cus.price); 
                }
            }else{
                printf("Error in file while searching by price");
                exit(1);
            }
        }
        if(found==0) printf("\nNo Data found\n");
        fclose(fp);
    }else if(toupper(ch)=='N'){
        long long int searchPrice;
        int found=0;
        FILE *fp;
        struct CUSTOMER cus;
        printf("\n\nEnter the specific price you want to search:");
        scanf("%lld",&searchPrice);
        if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
            printf("Error in searching the file with price");
            exit(1);
        }
        printf("\n---Search Results---:\n");
        while(!feof(fp)){
            if(!ferror(fp)){
                fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus.productId,&cus.customerName,&cus.customerPhoneNumber,&cus.itemName,&cus.itemBrandName,&cus.price);
                if(cus.price==searchPrice){
                    found=1;
                   printf("Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",cus.productId,cus.customerName,cus.customerPhoneNumber,cus.itemName,cus.itemBrandName,cus.price); 
                }
            }else{
                printf("Error in file while searching by price");
                exit(1);
            }
        }
        if(found==0) printf("\nNo Data found\n");
        fclose(fp);
    }
}
void empInformationSearch(){
   printf("\n---WELCOME TO EMPLOYEE INFORMATION SEARCHING OPTION---\n");
   int empOption;
   printf("\n1.Search by employee ID\n");
   printf("2.Search by employee name\n");
   printf("3.Search by employee position\n");
   printf("4.Search by employee performation rate\n");
   printf("5.Search by employee salary\n");
   scanf("%d",&empOption);
   if(empOption==1) searchEmpId();
   else if(empOption==2) searchEmpName();
   else if(empOption==3) searchEmpPos();
   else if(empOption==4) searchEmpPerRate();
   else if(empOption==5) searchEmpSalary();
   else printf("Please enter valid number\n");
}
void searchEmpId(){
    FILE *fp;
    long long int empPerId;
    struct EMPLOYEE emp;
    int found=0;
    printf("\nEnter employee Id you want to search:");
    scanf("%lld",&empPerId);
    if((fp=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error opening employee file in search mode\n");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
            if(empPerId==emp.empId){
                printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
            }
        }else{
            printf("Error in file while searching employee id\n");
            exit(1);
        }
    }
    fclose(fp);
}
void searchEmpName(){
    int found=0;
    char searchEmpNam[100];
    FILE *fp;
    struct EMPLOYEE emp;
    fgetc(stdin);
    printf("\n\nEnter the employee name you want to search:");
    fgets(searchEmpNam,100,stdin);
    searchEmpNam[strcspn(searchEmpNam, "\n")] = 0;
    if((fp=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error in searching the file with employee name");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
            if(strcmp(searchEmpNam,emp.empName)==0){
                found=1;
                printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
            }
        }else{
            printf("Error in file while searching employee name\n");
            exit(1);
        }
    }
    if(found==0) printf("\nNo Data found\n");
    fclose(fp);
}
void searchEmpPos(){
    int found=0;
    char searchEmpPos[100];
    FILE *fp;
    struct EMPLOYEE emp;
    fgetc(stdin);
    printf("\n\nEnter the employee position you want to search:");
    fgets(searchEmpPos,100,stdin);
    searchEmpPos[strcspn(searchEmpPos, "\n")] = 0;
    if((fp=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error in searching the file with employee name");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
            if(strcmp(searchEmpPos,emp.empPos)==0){
                found=1;
                printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
            }
        }else{
            printf("Error in file while searching employee position\n");
            exit(1);
        }
    }
    if(found==0) printf("\nNo Data found\n");
    fclose(fp);
}
void searchEmpPerRate(){
    FILE *fp;
    double searchEmpPerformanceR;
    struct EMPLOYEE emp;
    int pasFound=0;
    int failFound=0;
    printf("\nEnter the passing rate for the employees:");
    scanf("%lf",&searchEmpPerformanceR);
    if((fp=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error opening employee file in search mode\n");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    printf("\nThose who are equal or above the rate you have set:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
            if(searchEmpPerformanceR<=emp.empPerformanceRate){
                pasFound=1;
                printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
            }
        }else{
            printf("Error in file while searching employee id\n");
            exit(1);
        }
    }
    if(pasFound==0) printf("\nNo one passed\n");
    fclose(fp);
    if((fp=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error opening employee file in search mode\n");
        exit(1);
    }
    printf("\nThose who are below the rate you have set:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
            if(searchEmpPerformanceR>emp.empPerformanceRate){
                failFound=1;
                printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
            }
        }else{
            printf("Error in file while searching employee id\n");
            exit(1);
        }
    }
    if(failFound==0) printf("\nNo one failed\n");
    fclose(fp);
}
void searchEmpSalary(){
    char ch;
    printf("\n\nDo you wish to select a range?\n(Select Y for range/Select N for specific number)\n:");
    ch=getche();
    if(toupper(ch)=='Y'){
        long long int lowestRange;
        long long int highestRange;
        int found=0;
        FILE *fp;
        struct EMPLOYEE emp;
        printf("\nEnter the minimum salary you want to set:");
        scanf("%lld",&lowestRange);
        printf("Enter the maximum salary you want to set:");
        scanf("%lld",&highestRange);
        if((fp=fopen("Employee-Info.txt","r"))==NULL){
            printf("Error in searching the file with salary");
            exit(1);
        }
        printf("\n---Search Results---:\n");
        while(!feof(fp)){
            if(!ferror(fp)){
                fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
                if((emp.empSalary>=lowestRange) && (emp.empSalary<=highestRange)){
                    found=1;
                    printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
                }
            }else{
                printf("Error in file while searching by price");
                exit(1);
            }
        }
        if(found==0) printf("\nNo Data found\n");
        fclose(fp);
    }else if(toupper(ch)=='N'){
        long long int searchSalary;
        int found=0;
        FILE *fp;
        struct EMPLOYEE emp;
        printf("\n\nEnter the specific salary you want to search:");
        scanf("%lld",&searchSalary);
        if((fp=fopen("Employee-Info.txt","r"))==NULL){
            printf("Error in searching the file with salary");
            exit(1);
        }
        printf("\n---Search Results---:\n");
        while(!feof(fp)){
            if(!ferror(fp)){
                fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
                if(emp.empSalary==searchSalary){
                    found=1;
                    printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
                }
            }else{
                printf("Error in file while searching by price");
                exit(1);
            }
        }
        if(found==0) printf("\nNo Data found\n");
        fclose(fp);
    }
}
void searchEmpPhone(){
    int found=0;
    char searchEmpPhoneNumber[100];
    FILE *fp;
    struct EMPLOYEE emp;
    fgetc(stdin);
    printf("\n\nEnter the employee phone number you want to search:");
    fgets(searchEmpPhoneNumber,100,stdin);
    searchEmpPhoneNumber[strcspn(searchEmpPhoneNumber, "\n")] = 0;
    if((fp=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error in searching the file with employee text number\n");
        exit(1);
    }
    printf("\n---Search Results---:\n");
    while(!feof(fp)){
        if(!ferror(fp)){
             fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
            if(strcmp(emp.empPhoneNumber,searchEmpPhoneNumber)==0){
                found=1;
                printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
            }
        }else{
            printf("Error in file while searching by item id");
            exit(1);
        }
    }
    if(found==0) printf("\nNo Data found\n");
    fclose(fp);
}