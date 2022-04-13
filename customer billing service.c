#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


struct items{
      char item[20];
      float price ;
         int qty;
      };
      struct orders{
      char customer [50];
      char date[50];
      int numOfItems;
      struct  items itm[50];
      };


void generateBillHeader(char name[50],char date [50]){
   printf("\n\n");
                     printf("\t   AITH.Restaurant");
                     printf("\n\t  -------------------------");
                     printf("Date:%s", date);
                     printf("\n Invoice To : %s", name);
                     printf("\n");
                     printf("------------------------------------------\n");
                     printf("Items\t\t");
                     printf("Qty\t\t");
                   //  printf("Qty\t\t");
                     printf("Total\t\t");
                     printf("\n---------------------------------");
                     printf("n\n");
                                                    }
  void generateBillBody(char item [30], int qty, float price){
                      printf("%s\t\t",item);
                      printf("%d\t\t",qty);
                      printf("%f\t\t",qty *price);
                      printf("\n");
                       }


  void generateBillFooter(float total){
                     printf("\n");
                     float dis =0.1*total;
                     float netTotal = total-dis;
                     float cgst= 0.09*netTotal,grandTotal = netTotal + 2*cgst;
                     printf("-------------------------------------\n");
                     printf("Sub Total\t\t\t %.2f", total);
                     printf("Discount @10%s\t\t\t%.2f","%",dis);
                     printf("\n\t\t\t\t-------------");
                     printf("\nNet total \t\t\t%.2f",netTotal);
                     printf("\nCGST @9 %s\t\t\t%.2f", "%",cgst);
                     printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
                     printf("\n-------------------------------------------");
                     printf("Grand Total \t\t\t %.2f",grandTotal);
                     printf("\n-------------------------------------------\n");

                     }
             int main (){
                 int opt ,n;
                 //int invoiceFound =0;
                   float total=0;
                 struct orders ord;
                 struct orders order;
                 char saveBill ='y',contFlag;

                 char name[50];
                 FILE *fp;



                 //dash board



 while (contFlag!=4)
   {
                  // system("clear");
                   float total = 0;
                    int invoiceFound =0;
                 printf("\n \n \xcd\xcd\xcd\ AITH Restaurant\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n \n ");
                 printf("\n\n Please select your prefered operation ");
                 printf("\n1.Generate Invoice ");
                 printf("\n2. Show all Invoice");
                 printf("\n3. Search Invoice ");
                 printf ("\n4.Exit");

                 printf("\n\n Your choice :");
                 scanf("%d",&opt);
                 fgetc(stdin);


                 switch(opt){
                 case 1:
                    //system ("clear");
                 printf("\n Please enter the name customers:\t");
                 fgets(ord.customer,50,stdin);
                 ord.customer[strlen(ord.customer)-1]=0;
                 strcpy(ord.date,__DATE__);
                 printf("\n Please enter the number of items:\t");
                 scanf("%d",&n);
                //  ord.numOfItems=n;

                 for(int i=0;i<n;i++){
                    fgetc(stdin);
                    printf("\n\n");
                    printf("Please enter the item %d :\t", i+1);
                    fgets(ord.itm[i].item,20,stdin);
                    ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
                    printf("\n Please enter the quantity :\t");
                    scanf("%d",&ord.itm[i].qty);
                    printf("\n please enter the unit price :\t");
                    scanf("%f",&ord.itm[i].price);
                    total+=ord.itm[i].qty *ord.itm[i].price;
                 }
                                generateBillHeader(ord.customer,ord.date);
                               //generateBillHeader(order.customer,order.date);
                                for(int i=0;i<ord.numOfItems;i++){
                                    generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
                                }
                                    generateBillFooter(total);
                                    printf("\n Do you want to save the invoice:\t");
                                    scanf("%s",&saveBill);

                                    if (saveBill=='y'){
                                        fp =fopen("RestaurantBill.dat","w");
                                        //a+
                                        fwrite(&ord,sizeof(struct orders) ,1,fp);
                                        if (fwrite !=0)
                                            printf("\n Successfully saved");
                                        else
                                            printf("\n Error saving");
                                        fclose(fp);


                                    }
                                     break;

              case 2:
            //system("clear");
                                    fp =fopen("RestaurantBill.dat","r");
                                     printf("\n *******YOUR PREVIOUS INVOICES*********\n");
                                      while (fread(&order,sizeof(struct orders),1,fp));{
                                  float tot =0;
                                   generateBillHeader(order.customer,order.date);
                                   for (int i=0;i<order.numOfItems; i++){
                                    // generateBillbody(order.itm,order.itm[i].qty.order.itm[i].price);
                                      generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                                  tot+= order.itm[i].qty *order.itm[i].price;
                                      }
                                   generateBillFooter(tot);
                                   }
                                   fclose(fp);
                                    break;

              case 3:
                  printf("\n enter the name of the customer : \t");
                  //fgetc(stdin);
                  fgets(name,50,stdin);
                  name[strlen(name)-1]=0;
                         // system ("clear");
                                    fp =fopen ("RestaurantBill.dat","r");
                                     printf("\n ******* INVOICES of %s *********\n",name);
                                      while (fread(&order,sizeof(struct orders),1,fp));{
                                 float tot =0;
                     if (!strcmp(ord.customer,name))
                        {           generateBillHeader(order.customer,order.date);
                                   for (int i=0;i<order.numOfItems; i++){
                                     generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                                  tot += order.itm[i].qty *order.itm[i].price;
                                      }
                                   generateBillFooter(tot);
                                   invoiceFound=1;
                                   }
                                      }
                                      if (!invoiceFound){
                                        printf("sorry the invoice for %s does not exists",name);
                                      }
                                   fclose(fp);
                                    break;

                        case 4 :printf("\n\t\t Bye Bye \n\n");
                                printf("\n\t\tVisit Again Aith\n\n");
                                printf("\n\t\tThank You \n\n");
                        exit (0);
                        break ;


                        default :
                            printf("Sorry Invalid option  \n");
                            break;

                 }
                 printf("\n Do you want to perform another operation?[y\n]:\n");
                scanf("%s",&contFlag);


             }

                                    printf("\n\t\t Bye Bye \n\n");
                                    printf("\n\t\tVisit Again Aith\n\n");
                                    printf("\n\t\tThank You \n\n");
                                  printf("\n\n ");
                                  return 0;

}





























