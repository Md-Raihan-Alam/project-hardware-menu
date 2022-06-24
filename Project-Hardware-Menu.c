#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#define managerPassword "manager@112233"
#define MAX_ARRAY_SIZE 1000
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
struct TEMP{
    char customerName[100];
    char customerPhoneNumber[100];
    char itemName[100];
    char itemBrandName[100];
    long long int price;
    long long int productId; 
};
struct TEMP2{
    long long int empId;
    char empName[100];
    char empPos[100];
    char empPhoneNumber[100];
    long long int empSalary;
    int empAge;
    double empPerformanceRate;
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
void fireEmployee();
void sortingCustomerMenu();
void pricesSort(int order);
void customerSort();
void brandSort();
void productSort();
void employeeSortingMenu();
void sortSalary(int order);
void sortPerformanceRate();
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
        else if(choices==5) sortingCustomerMenu();
        else if(choices==6) {
            printf("\n---Program Closed---\n");
            break;
        }
        else printf("Enter number between 1 to 5.\n");
    }
    getch();
}
int employeeMenu(){
    int optionNo;
    printf("\n---Welcome to hardware management menu as employee---\n");
    printf("1.Enter selling product and customer data.\n");
    printf("2.Customer Informations\n");
    printf("3.Manager Menu\n");
    printf("4.Search Customers Information\n");
    printf("5.Sorting information from customer data\n");
    printf("6.Quit Menu\n:");
    scanf("%d",&optionNo);
    return optionNo;
}
void customerData(){
    FILE *fp;
    struct CUSTOMER cus;
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
    while(1){
    printf("\n---WELCOME TO CUSTOMER INFORMATION SEARCHING OPTIONS---\n");
    int searchChoices;
    printf("\n1.Search by Item Id.\n");
    printf("2.Search by Customer Name.\n");
    printf("3.Search by Customer Phone Number\n");
    printf("4.Search by Item Name\n");
    printf("5.Search by Item Brand Name\n");
    printf("6.Search by Price\n");
    printf("7.Quit Customer Information Searching Menu\n:");
    scanf("%d",&searchChoices);
    if(searchChoices==1) searchItemId();
    else if(searchChoices==2) searchCustomerName();
    else if(searchChoices==3) searchPhoneNumber();
    else if(searchChoices==4) searchItemName();
    else if(searchChoices==5) searchBrandName();
    else if(searchChoices==6) searchPrices();
    else if(searchChoices==7) break;
    else printf("\nEnter proper number next time\n");
    }
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
            else if(managerChoices==2) fireEmployee();
            else if(managerChoices==3) hireEmployee();
            else if(managerChoices==4) customerData();
            else if(managerChoices==5) customerInfo();
            else if(managerChoices==6) empInformationSearch();
            else if(managerChoices==7) customersInformationSearch();
            else if(managerChoices==8) employeeSortingMenu();
            else if(managerChoices==9) {
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
    printf("7.Search Customers Information\n");
    printf("8.Additional Information About Employee\n");
    printf("9.Log out\n:");
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
    while(1){
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
        char ch;
        printf("\n--Do you want to enter more data about hired employee(Y/N):");
        ch=getche();
        if(toupper(ch)=='N') break;
        printf("\n");
    }
}
void fireEmployee(){
    FILE *fp1,*fp2;
    long long int fireEmployeeId;
    struct EMPLOYEE emp;
    printf("Enter the employee id you want to fire:");
    scanf("%lld",&fireEmployeeId);
    if((fp1=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error reading employee file in fire employee function\n");
        exit(1);
    }
    if((fp2=fopen("temp.txt","a"))==NULL){
        printf("Error creating temp file");
        exit(1);
    }
    while(!feof(fp1)){
        if(!ferror(fp1)){
            fscanf(fp1,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
            if(fireEmployeeId!=emp.empId){
                if(!ferror(fp2))
                    fprintf(fp2,"Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
                else{
                    printf("Error writing file temp fireEmployee");
                    remove("temp.txt");
                    exit(1);
                }
            }
        }else{
            printf("Error file Employee-Info.txt fireEmployee");
            remove("temp.txt");
            exit(1);
        }
    }
    fclose(fp2);
    fclose(fp1);
    remove("Employee-Info.txt");
    if((fp1=fopen("Employee-Info.txt","a"))==NULL){
        printf("Error recreating file 1 fireEmployee\n");
        exit(1);
    }
    if((fp2=fopen("temp.txt","r"))==NULL){
        printf("Error reading temp file fireEmployee");
        exit(1);
    }
    while(!feof(fp2)){
        if(!ferror(fp2)){
            fscanf(fp2,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp.empId,&emp.empName,&emp.empPhoneNumber,&emp.empAge,&emp.empPos,&emp.empSalary,&emp.empPerformanceRate);
            if(!ferror(fp1))
                fprintf(fp1,"Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp.empId,emp.empName,emp.empPhoneNumber,emp.empAge,emp.empPos,emp.empSalary,emp.empPerformanceRate);
            else{
                printf("Error writng file 1 hireEmployee\n");
                exit(1);
            }
        }else{
            printf("Error in file 2 fireEmployee");
            remove("temp.txt");
            exit(1);
        }
    }
    fclose(fp2);
    fclose(fp1);
    remove("temp.txt");
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
   while(1){
    printf("\n---WELCOME TO EMPLOYEE INFORMATION SEARCHING OPTION---\n");
   int empOption;
   printf("\n1.Search by employee ID\n");
   printf("2.Search by employee name\n");
   printf("3.Search by employee position\n");
   printf("4.Search by employee performation rate\n");
   printf("5.Search by employee salary\n");
   printf("6.Search by employee phone number\n");
   printf("7.Quit Employee Information Searching Menu\n:");
   scanf("%d",&empOption);
   if(empOption==1) searchEmpId();
   else if(empOption==2) searchEmpName();
   else if(empOption==3) searchEmpPos();
   else if(empOption==4) searchEmpPerRate();
   else if(empOption==5) searchEmpSalary();
   else if(empOption==6) searchEmpPhone();
   else if(empOption==7) break;
   else printf("Please enter valid number\n");
   }
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
void sortingCustomerMenu(){
    int sortingOption;
    printf("\n---Welcome to sorting customer menu options---\n");
    printf("1.Sort customers informations from lowest to heighest prices\n");
    printf("2.Sort customers informations from highest to lowest prices\n");
    printf("3.Check Regular Customers\n");
    printf("4.Check Demanding Brands\n");
    printf("5.Check Demanding Products\n");
    scanf("%d",&sortingOption);
    if(sortingOption==1) pricesSort(1);
    else if(sortingOption==2) pricesSort(2);
    else if(sortingOption==3) customerSort();
    else if(sortingOption==4) brandSort();
    else if(sortingOption==5) productSort();
    else printf("\nEnter a valid option number\n");
}
void pricesSort(int order){
    struct CUSTOMER cus[MAX_ARRAY_SIZE];
    struct TEMP temp;
    FILE *fp;
    int i=0,j,k;
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error:while reading pricesSort");
        exit(1);
    }
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus[i].productId,&cus[i].customerName,&cus[i].customerPhoneNumber,&cus[i].itemName,&cus[i].itemBrandName,&cus[i].price);
            i++;
        }else{
            printf("Error:retreiving data pricesSort\n");
            exit(1);
        }
    }
    printf("\n---Wait, Data is being sorted---\n");
    if(order==1){
        for(j=0;j<i;j++){
            for(k=0;k<i-1;k++){
                if(cus[k].price>cus[k+1].price){
                    temp.price=cus[k].price;
                    strcpy(temp.customerName,cus[k].customerName);
                    strcpy(temp.customerPhoneNumber,cus[k].customerPhoneNumber);
                    strcpy(temp.itemName,cus[k].itemName);
                    strcpy(temp.itemBrandName,cus[k].itemBrandName);
                    temp.productId=cus[k].productId;
                    cus[k].price=cus[k+1].price;
                    strcpy(cus[k].customerName,cus[k+1].customerName);
                    strcpy(cus[k].customerPhoneNumber,cus[k+1].customerPhoneNumber);
                    strcpy(cus[k].itemName,cus[k+1].itemName);
                    strcpy(cus[k].itemBrandName,cus[k+1].itemBrandName);
                    cus[k].productId=cus[k+1].productId;
                    cus[k+1].price=temp.price;
                    strcpy(cus[k+1].customerName,temp.customerName);
                    strcpy(cus[k+1].customerPhoneNumber,temp.customerPhoneNumber);
                    strcpy(cus[k+1].itemName,temp.itemName);
                    strcpy(cus[k+1].itemBrandName,temp.itemBrandName);
                    cus[k+1].productId=temp.productId;
                }
            }
        }
    }else if(order==2){
        for(j=0;j<i;j++){
            for(k=0;k<i-1;k++){
                if(cus[k].price<cus[k+1].price){
                    temp.price=cus[k].price;
                    strcpy(temp.customerName,cus[k].customerName);
                    strcpy(temp.customerPhoneNumber,cus[k].customerPhoneNumber);
                    strcpy(temp.itemName,cus[k].itemName);
                    strcpy(temp.itemBrandName,cus[k].itemBrandName);
                    temp.productId=cus[k].productId;
                    cus[k].price=cus[k+1].price;
                    strcpy(cus[k].customerName,cus[k+1].customerName);
                    strcpy(cus[k].customerPhoneNumber,cus[k+1].customerPhoneNumber);
                    strcpy(cus[k].itemName,cus[k+1].itemName);
                    strcpy(cus[k].itemBrandName,cus[k+1].itemBrandName);
                    cus[k].productId=cus[k+1].productId;
                    cus[k+1].price=temp.price;
                    strcpy(cus[k+1].customerName,temp.customerName);
                    strcpy(cus[k+1].customerPhoneNumber,temp.customerPhoneNumber);
                    strcpy(cus[k+1].itemName,temp.itemName);
                    strcpy(cus[k+1].itemBrandName,temp.itemBrandName);
                    cus[k+1].productId=temp.productId;
                }
            }
        }
    }
    printf("\n--Results--\n");
    for(j=0;j<i;j++){
         printf("Product-Id:%lld\nCustomer-Name:%s\nCustomer-Phone-Number:%s\nItem-Name:%s\nItem-Brand-Name:%s\nPrice:%lld\n------\n",cus[j].productId,cus[j].customerName,cus[j].customerPhoneNumber,cus[j].itemName,cus[j].itemBrandName,cus[j].price);
    }
}
void customerSort(){
    struct CUSTOMER cus[MAX_ARRAY_SIZE];
    char names[100][100];
    int customerVisits[100];
    char tempName[100];
    int tempValue;
    int tempVisits=0;
    int totalCustomers=0;
    int maximumVisits=0;
    int namesPresence=0;
    FILE *fp;
    int i=0,j,k,arrayLength=0;
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error:customer Sort file read");
        exit(1);
    }
    printf("\n---Wait, DATA IS IN PROGRESSED---\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus[i].productId,&cus[i].customerName,&cus[i].customerPhoneNumber,&cus[i].itemName,&cus[i].itemBrandName,&cus[i].price);
            i++;
        }else{
            printf("Error:retreiving data name sort\n");
            exit(1);
        }
    }
    for(j=0;j<i;j++){
        for(k=0;k<i;k++){
            if(strcmp(cus[j].customerName,cus[k].customerName)==0){
                tempVisits++;
            }
        }
        for(k=0;k<j;k++){
            if(strcmp(cus[j].customerName,names[k])==0)
                namesPresence=1;
        }
        if(namesPresence==0){
            strcpy(names[totalCustomers],cus[j].customerName);
            customerVisits[totalCustomers]=tempVisits;
            if(tempVisits>maximumVisits) maximumVisits=tempVisits;
            arrayLength++;
            totalCustomers++;
        }
        tempVisits=0;
        namesPresence=0;
    }
    for(j=0;j<arrayLength;j++){
        for(k=0;k<arrayLength-1;k++){
            if(customerVisits[k]<customerVisits[k+1]){
                tempValue=customerVisits[k];
                strcpy(tempName,names[k]);
                customerVisits[k]=customerVisits[k+1];
                strcpy(names[k],names[k+1]);
                customerVisits[k+1]=tempValue;
                strcpy(names[k+1],tempName);
            }
        }
    }
    printf("\nYou should consider giving them some offer as they seems to be regular:\n");
    for(j=0;j<arrayLength;j++){
        if(customerVisits[j]>=maximumVisits)
            printf("%s visits %d times\n",names[j],customerVisits[j]);
    }
    printf("------\nThey seems to be irregular\n");
    for(j=0;j<arrayLength;j++){
        if(customerVisits[j]<maximumVisits)
            printf("%s visits %d times\n",names[j],customerVisits[j]);
    }
}
void brandSort(){
    struct CUSTOMER cus[MAX_ARRAY_SIZE];
    char brandNames[100][100];
    int brandOrders[100];
    char tempBrandName[100];
    int tempValue;
    int tempOrder=0;
    int totalBrands=0;
    int maximumOrders=0;
    int brandPresence=0;
    FILE *fp;
    int i=0,j,k,arrayLength=0;
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error:customer soort file brand read");
        exit(1);
    }
    printf("\n---Wait, DATA IS IN PROGRESSED---\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus[i].productId,&cus[i].customerName,&cus[i].customerPhoneNumber,&cus[i].itemName,&cus[i].itemBrandName,&cus[i].price);
            i++;
        }else{
            printf("Error: retrieving data brand sort\n");
            exit(1);
        }
    }
    for(j=0;j<i;j++){
        for(k=0;k<i;k++){
            if(strcmp(cus[j].itemBrandName,cus[k].itemBrandName)==0){
                tempOrder++;
                // printf("%s=%s =%d\n",cus[j].itemBrandName,cus[k].itemBrandName,tempOrder);
            }
        }
        for(k=0;k<j;k++){
            if(strcmp(cus[j].itemBrandName,brandNames[k])==0){
                brandPresence=1;
            }
        }
        if(brandPresence==0){
            strcpy(brandNames[totalBrands],cus[j].itemBrandName);
            // printf("item added=%s \n",brandNames[j]);
            brandOrders[totalBrands]=tempOrder;
            // printf("item number=%d\n",brandOrders[j]);
            if(tempOrder>maximumOrders) maximumOrders=tempOrder;
            // printf("Maximum number=%d\n",maximumOrders);
            arrayLength++;
            totalBrands++;
        }
        brandPresence=0;
        tempOrder=0;
    }
    for(j=0;j<arrayLength;j++){
        for(k=0;k<arrayLength-1;k++){
            if(brandOrders[k]<brandOrders[k+1]){
                tempValue=brandOrders[k];
                strcpy(tempBrandName,brandNames[k]);
                brandOrders[k]=brandOrders[k+1];
                strcpy(brandNames[k],brandNames[k+1]);
                brandOrders[k+1]=tempValue;
                strcpy(brandNames[k+1],tempBrandName);
            }
        }
    }
    printf("\nYou should consider ordering more as these brands seem to be liked by client:\n");
    for(j=0;j<arrayLength;j++){
        if(brandOrders[j]>=maximumOrders){
            printf("%s\n",brandNames[j]);
        }    
    }
}
void productSort(){
    struct CUSTOMER cus[MAX_ARRAY_SIZE];
    char productNames[100][100];
    int productOrders[100];
    char tempProductName[100];
    int tempValue;
    int tempOrder=0;
    int totalProduct=0;
    int maximumOrders=0;
    int productPresence=0;
    FILE *fp;
    int i=0,j,k,arrayLength=0;
    if((fp=fopen("customer-pricing-data.txt","r"))==NULL){
        printf("Error:customer sort file product read");
        exit(1);
    }
    printf("\n---Wait, DATA IS IN PROGRESSED---\n");
    while(!feof(fp)){
        if(!ferror(fp)){
            fscanf(fp,"Product-Id:%lld\nCustomer-Name:%99[^\n]\nCustomer-Phone-Number:%99[^\n]\nItem-Name:%99[^\n]\nItem-Brand-Name:%99[^\n]\nPrice:%lld\n------\n",&cus[i].productId,&cus[i].customerName,&cus[i].customerPhoneNumber,&cus[i].itemName,&cus[i].itemBrandName,&cus[i].price);
            i++;
        }else{
            printf("Error: retrieving data brand sort\n");
            exit(1);
        }
    }
    for(j=0;j<i;j++){
        for(k=0;k<i;k++){
            if(strcmp(cus[j].itemName,cus[k].itemName)==0){
                // printf("%s %s\n",cus[j].itemName,cus[k].itemName);
                tempOrder++;
                // printf("%d\n",tempOrder);
            }
        }
        for(k=0;k<j;k++){
            if(strcmp(cus[j].itemName,productNames[k])==0){
                productPresence=1;
            }
        }
        if(productPresence==0){
            strcpy(productNames[totalProduct],cus[j].itemName);
            productOrders[totalProduct]=tempOrder;
            // printf("temp Order=%d",tempOrder);
            if(tempOrder>maximumOrders) maximumOrders=tempOrder;
            arrayLength++;
            totalProduct++;
        }
        productPresence=0;
        tempOrder=0;
    }
    // printf("Here %d maxi\n",maximumOrders);
    // for(j=0;j<totalProduct;j++){
    //     printf("%s brought %d times\n",productNames[j],productOrders[j]);
    // }
    for(j=0;j<arrayLength;j++){
        for(k=0;k<arrayLength-1;k++){
            if(productOrders[k]<productOrders[k+1]){
                tempValue=productOrders[k];
                strcpy(tempProductName,productNames[k]);
                productOrders[k]=productOrders[k+1];
                strcpy(productNames[k],productNames[k+1]);
                productOrders[k+1]=tempValue;
                strcpy(productNames[k+1],tempProductName);
            }
        }
    }
    printf("\nYou should consider ordering more as these items seem to be liked by client:\n");
    
    for(j=0;j<arrayLength;j++){
        if(productOrders[j]>=maximumOrders){
            printf("%s\n",productNames[j]);
        }
    }
}
void employeeSortingMenu(){
    while(1){
        printf("\n---Welcome to additional Employee Infomation Menu Option---\n");
        int sortingEmpOption;
        printf("1.Sort By Salary from heighest to lowest\n");
        printf("2.Sort by Salary from lowest to heighest\n");
        printf("3.Sort by Performance Rate(highest to lowest)\n");
        printf("4.Quit Additional information menu options\n:");
        scanf("%d",&sortingEmpOption);
        if(sortingEmpOption==1) sortSalary(1);
        else if(sortingEmpOption==2) sortSalary(2);
        else if(sortingEmpOption==3) sortPerformanceRate();
        else if(sortingEmpOption==4) {
            printf("\n---Quiting Additional Employee Information Menu---\n");
            break;
        }
        else printf("\nEnter valid number\n");
    }
}
void sortSalary(int order){
    FILE *fp;
    struct EMPLOYEE emp[MAX_ARRAY_SIZE];
    struct TEMP2 tmp;
    int i=0,j,k;
    if((fp=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error:sort salary\n");
        exit(1);
    }
    while(!feof(fp)){
        if(!ferror(fp)){
             fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp[i].empId,&emp[i].empName,&emp[i].empPhoneNumber,&emp[i].empAge,&emp[i].empPos,&emp[i].empSalary,&emp[i].empPerformanceRate);
             i++;
        }else{
            printf("Error:retreiving data sort salary\n");
            exit(1);
        }
    }
    printf("\n---Wait, Data is being sorted---\n");
    if(order==1){
        for(j=0;j<i;j++){
            for(k=0;k<i-1;k++){
                if(emp[k].empSalary<emp[k+1].empSalary){
                    tmp.empSalary=emp[k].empSalary;
                    strcpy(tmp.empName,emp[k].empName);
                    strcpy(tmp.empPhoneNumber,emp[k].empPhoneNumber);
                    strcpy(tmp.empPos,emp[k].empPos);
                    tmp.empId=emp[k].empId;
                    tmp.empAge=emp[k].empAge;
                    tmp.empPerformanceRate=emp[k].empPerformanceRate;
                    emp[k].empSalary=emp[k+1].empSalary;
                    strcpy(emp[k].empName,emp[k+1].empName);
                    strcpy(emp[k].empPhoneNumber,emp[k+1].empPhoneNumber);
                    strcpy(emp[k].empPos,emp[k+1].empPos);
                    emp[k].empId=emp[k+1].empId;
                    emp[k].empAge=emp[k+1].empAge;
                    emp[k].empPerformanceRate=emp[k+1].empPerformanceRate;
                    emp[k+1].empSalary=tmp.empSalary;
                    strcpy(emp[k+1].empName,tmp.empName);
                    strcpy(emp[k+1].empPhoneNumber,tmp.empPhoneNumber);
                    strcpy(emp[k+1].empPos,tmp.empPos);
                    emp[k+1].empId=tmp.empId;
                    emp[k+1].empAge=tmp.empAge;
                    emp[k+1].empPerformanceRate=tmp.empPerformanceRate;
                }
            }
        }
    }else{
        for(j=0;j<i;j++){
            for(k=0;k<i-1;k++){
                if(emp[k].empSalary>emp[k+1].empSalary){
                    tmp.empSalary=emp[k].empSalary;
                    strcpy(tmp.empName,emp[k].empName);
                    strcpy(tmp.empPhoneNumber,emp[k].empPhoneNumber);
                    strcpy(tmp.empPos,emp[k].empPos);
                    tmp.empId=emp[k].empId;
                    tmp.empAge=emp[k].empAge;
                    tmp.empPerformanceRate=emp[k].empPerformanceRate;
                    emp[k].empSalary=emp[k+1].empSalary;
                    strcpy(emp[k].empName,emp[k+1].empName);
                    strcpy(emp[k].empPhoneNumber,emp[k+1].empPhoneNumber);
                    strcpy(emp[k].empPos,emp[k+1].empPos);
                    emp[k].empId=emp[k+1].empId;
                    emp[k].empAge=emp[k+1].empAge;
                    emp[k].empPerformanceRate=emp[k+1].empPerformanceRate;
                    emp[k+1].empSalary=tmp.empSalary;
                    strcpy(emp[k+1].empName,tmp.empName);
                    strcpy(emp[k+1].empPhoneNumber,tmp.empPhoneNumber);
                    strcpy(emp[k+1].empPos,tmp.empPos);
                    emp[k+1].empId=tmp.empId;
                    emp[k+1].empAge=tmp.empAge;
                    emp[k+1].empPerformanceRate=tmp.empPerformanceRate;
                }
            }
        }        
    }
    printf("\n--Results--\n");
    for(j=0;j<i;j++){
        printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp[j].empId,emp[j].empName,emp[j].empPhoneNumber,emp[j].empAge,emp[j].empPos,emp[j].empSalary,emp[j].empPerformanceRate);
    }
}
void sortPerformanceRate(){
    FILE *fp;
    struct EMPLOYEE emp[MAX_ARRAY_SIZE];
    struct TEMP2 tmp;
    int i=0,j,k;
    if((fp=fopen("Employee-Info.txt","r"))==NULL){
        printf("Error:performance rate sort\n");
        exit(1);
    }
    while(!feof(fp)){
        if(!ferror(fp)){
             fscanf(fp,"Employee-Id:%lld\nEmployee-Name:%99[^\n]\nEmployee-Phone-Number:%99[^\n]\nEmployee-Age:%d\nEmployee-Position:%99[^\n]\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",&emp[i].empId,&emp[i].empName,&emp[i].empPhoneNumber,&emp[i].empAge,&emp[i].empPos,&emp[i].empSalary,&emp[i].empPerformanceRate);
             i++;
        }else{
            printf("Error:retreiving data performance rate sort\n");
            exit(1);
        }
    }
    printf("\n---Wait, Data is being sorted---\n");
        for(j=0;j<i;j++){
            for(k=0;k<i-1;k++){
                if(emp[k].empPerformanceRate<emp[k+1].empPerformanceRate){
                    tmp.empSalary=emp[k].empSalary;
                    strcpy(tmp.empName,emp[k].empName);
                    strcpy(tmp.empPhoneNumber,emp[k].empPhoneNumber);
                    strcpy(tmp.empPos,emp[k].empPos);
                    tmp.empId=emp[k].empId;
                    tmp.empAge=emp[k].empAge;
                    tmp.empPerformanceRate=emp[k].empPerformanceRate;
                    emp[k].empSalary=emp[k+1].empSalary;
                    strcpy(emp[k].empName,emp[k+1].empName);
                    strcpy(emp[k].empPhoneNumber,emp[k+1].empPhoneNumber);
                    strcpy(emp[k].empPos,emp[k+1].empPos);
                    emp[k].empId=emp[k+1].empId;
                    emp[k].empAge=emp[k+1].empAge;
                    emp[k].empPerformanceRate=emp[k+1].empPerformanceRate;
                    emp[k+1].empSalary=tmp.empSalary;
                    strcpy(emp[k+1].empName,tmp.empName);
                    strcpy(emp[k+1].empPhoneNumber,tmp.empPhoneNumber);
                    strcpy(emp[k+1].empPos,tmp.empPos);
                    emp[k+1].empId=tmp.empId;
                    emp[k+1].empAge=tmp.empAge;
                    emp[k+1].empPerformanceRate=tmp.empPerformanceRate;
                }
            }
        }        
    printf("\n--Results--\n");
    for(j=0;j<i;j++){
        printf("Employee-Id:%lld\nEmployee-Name:%s\nEmployee-Phone-Number:%s\nEmployee-Age:%d\nEmployee-Position:%s\nEmployee-Salary:%lld\nEmployee-Performance-Rate:%lf\n------\n",emp[j].empId,emp[j].empName,emp[j].empPhoneNumber,emp[j].empAge,emp[j].empPos,emp[j].empSalary,emp[j].empPerformanceRate);
    }
}