    #include <stdio.h>
    #include<stdlib.h>
    #include <math.h>
    #include <string.h>
    typedef struct
    {
        int day;
        int month;
        int year;
    } Dates;
    Dates dates[100];
    struct contact
    {
        char firstname[50];
        char lastname[50];
        char address[50];
        char email[50];
        char PhoneNumber[20];
    } contacts[100];
    int i=0;
    void ADD()
    {
        while(1)
        {
            printf("Enter first name:");
            scanf("\n%[^\n]",contacts[i].firstname);
            printf("Enter last name: ");
            scanf("\n%[^\n]",contacts[i].lastname);
            printf("Enter date of birth in the form DD/MM/YYYY: ");
            LOOP:scanf("%d/%d/%d", &dates[i].day, &dates[i].month, &dates[i].year);
            printf("Enter address: ");
            scanf("\n%[^\n]",contacts[i].address);
            printf("Enter Email address: ");
            scanf("\n%[^\n]",contacts[i].email);
            printf("Enter phone number: ");
            scanf("%s",&contacts[i].PhoneNumber);
            i++;
            printf("Continue(Y/N)");
            char ch[1];
            scanf("%s",&ch);
            if(ch[0] =='N' || ch[0] =='n')
                break;

        }
    }
    void savetofile()
    {
        FILE *f;
        f=fopen("contacts.txt", "w");
        int j;
        for(j=0; j<i; j++)
        {
            fprintf(f,"%s,",contacts[j].firstname);
            fprintf(f,"%s,",contacts[j].lastname);
            fprintf(f,"%d-%d-%d,",dates[j].day, dates[j].month, dates[j].year);
            fprintf(f,"%s,",contacts[j].address);
            fprintf(f,"%s,",contacts[j].email);
            fprintf(f,"%s\n",contacts[j].PhoneNumber);
        }
        fclose(f);
    }
    void sort()
    {
        int x;
        printf("\nEnter 1 to sort by name and phone number and 2 to sort by date of birth\n");
        scanf("%d",&x);
        int j, k;
        struct contact temp2;
        Dates temp1;
        if(x==1) goto LOOP2; if(x==2) goto LOOP3;
        LOOP2:
        for (j=0;j<i-1;j++)
            {
                for(k=0;k<i-1;k++)
                    {
                        if(strcasecmp(contacts[k].firstname, contacts[k+1].firstname)>0)
                            {
                                temp2=contacts[k];
                                contacts[k]=contacts[k+1];
                                contacts[k+1]=temp2;
                                temp1=dates[k];
                                dates[k]=dates[k+1];
                                dates[k+1]=temp1;
                            }
                        if(strcasecmp(contacts[k].firstname,contacts[k+1].firstname)==0)
                            {
                                if((strcasecmp(contacts[k].lastname, contacts[k+1].lastname))>0)
                                {
                                    temp2=contacts[k];
                                    contacts[k]=contacts[k+1];
                                    contacts[k+1]=temp2;
                                    temp1=dates[k];
                                    dates[k]=dates[k+1];
                                    dates[k+1]=temp1;
                                }
                        if((strcasecmp(contacts[k].lastname, contacts[k+1].lastname)==0))
                            {
                            if(strcmp(contacts[k].PhoneNumber,contacts[k+1].PhoneNumber)>0)
                                {
                                    temp2=contacts[k];
                                    contacts[k]=contacts[k+1];
                                    contacts[k+1]=temp2;
                                    temp1=dates[k];
                                    dates[k]=dates[k+1];
                                    dates[k+1]=temp1;
                                }
                            }
                        }
                    }
        }
        return;
        LOOP3: for (j=0;j<i-1;j++)
        {
            for(k=0;k<i-1;k++)
            {
            if(dates[k].year>dates[k+1].year)
                {
                    temp2=contacts[k];
                    contacts[k]=contacts[k+1];
                    contacts[k+1]=temp2;
                    temp1=dates[k];
                    dates[k]=dates[k+1];
                    dates[k+1]=temp1;
                }
            if(dates[k].year==dates[k+1].year)
                {
                if(dates[k].month>dates[k+1].month)
                    {
                        temp2=contacts[k];
                        contacts[k]=contacts[k+1];
                        contacts[k+1]=temp2;
                        temp1=dates[k];
                        dates[k]=dates[k+1];
                        dates[k+1]=temp1;
                    }
                if(dates[k].month==dates[k+1].month)
                    {
                    if(dates[k].day>dates[k+1].day)
                        {
                            temp2=contacts[k];
                            contacts[k]=contacts[k+1];
                            contacts[k+1]=temp2;
                            temp1=dates[k];
                            dates[k]=dates[k+1];
                            dates[k+1]=temp1;
                        }
                    }
                }
            }
        }
    }
void printDirectory()
    {
        sort();
        printf("Printing %d contacts\n", i);
        int l;
        for(l=0;l<i;l++)
            {
                printf("\nFirst name: %s\n",contacts[l].firstname);
                printf("Last name: %s\n",contacts[l].lastname);
                printf("Date of Birth: %d/%d/%d\n",dates[l].day,dates[l].month,dates[l].year);
                printf("Address: %s\n",contacts[l].address);
                printf("Email Address: %s\n",contacts[l].email);
                printf("Phone Number: %s\n",contacts[l].PhoneNumber);
            }
    }
    void modify()
    {
        char lastname[50];
        int j,k[100],m=0,l,x;
        printf("Please enter the last name of the contact you wish to modify:\n");
        scanf("%s",lastname);
        for(j=0;j<i;j++)
        {
            if(strcasecmp(lastname,contacts[j].lastname)==0)
            {
                printf("\n%d\nFirst name: %s\nLast name: %s\nAddress: %s\nEmail Address: %s\nDate of birth:%d/%d/%d\nPhone number:%s\n",m+1,contacts[j].firstname,contacts[j].lastname,contacts[j].address,contacts[j].email,dates[j].day,dates[j].month,dates[j].year,contacts[j].PhoneNumber);
                k[m]=j;
                m++;
            }
        }
        printf("\nPlease choose the contact you wish to modify from the list: \n");
            LOOP: scanf("%d",&l);
            if(l>(m))
                {
                printf("\nPlease choose a contact from the list\n");
                goto LOOP;
                }
        LOOP1: printf("\nEnter the field you wish to modify:\n1.First Name\n2.Last Name\n3.Date of Birth\n4.Address\n5.Email Address\n6.Phone Number\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            printf("New first name: ");
            scanf("%s",contacts[k[l-1]].firstname);
            break;
        case 2:
            printf("New last name: ");
            scanf("%s",contacts[k[l-1]].lastname);
            break;
        case 3:
            printf("New date of birth[DD/MM/YYYY]: ");
            scanf("%d/%d/%d",&dates[k[l-1]].day,&dates[k[m]].month,&dates[k[m]].year);
            break;
        case 4:
            printf("New Address: ");
            scanf("\n%[^\n]s",contacts[k[l-1]].address);
            break;
        case 5:
            printf("New Email Address: ");
            scanf("%s",contacts[k[l-1]].email);
            break;
        case 6:
            printf("New phone number: ");
            scanf("%s",contacts[k[l-1]].PhoneNumber);
            break;
        default: printf("Please choose a number from the list\n");
        goto LOOP1;
        }
    }
    void search()
    {
        int j,h=0;
        char lastname[50];
        printf("Enter last name:\n");
        scanf("%s",&lastname);
        for(j=0; j<i; j++)
        {
            if(strcasecmp(lastname,contacts[j].lastname)==0)
            {
                printf("\nLast name: %s\nFirst name: %s\nAddress: %s\nEmail Address: %s\nDate of birth:%d/%d/%d\nPhone number:%s\n",contacts[j].lastname,contacts[j].firstname,contacts[j].address,contacts[j].email,dates[j].day,dates[j].month,dates[j].year,contacts[j].PhoneNumber);
                h++;
            }
        }
        if(h==0) printf("Not found");
        else printf("\nFound %d contacts with the lastname %s",h,lastname);
    }
    void readfromfile()
    {
        i=0;
        FILE *f;
        f= fopen("contacts.txt", "r");
        while(!feof(f))
        {
            fscanf(f,"%[^,],",contacts[i].firstname);
            fscanf(f,"%[^,],",contacts[i].lastname);
            fscanf(f,"%d-%d-%d,",&dates[i].day,&dates[i].month,&dates[i].year);
            fscanf(f,"%[^,],",contacts[i].address);
            fscanf(f,"%[^,],",contacts[i].email);
            fscanf(f,"%[^\n]\n",contacts[i].PhoneNumber);
            i++;
        }
        printf("Loaded %d contacts.", i);
        fclose(f);
    }
    void delete()
{
    int j,k[100],l,m=0,flag=0;
    char lastname[50];
    printf("Enter the last name of the contact you wish to delete\n");
    scanf("%s",lastname);
    for(j=0;j<i;j++)
    {
        if(strcasecmp(lastname,contacts[j].lastname)==0)
        {
            printf("\n%d\nFirst name: %s\nLast name: %s\nAddress: %s\nEmail Address: %s\nDate of birth:%d/%d/%d\nPhone number:%s\n",m+1,contacts[j].firstname,contacts[j].lastname,contacts[j].address,contacts[j].email,dates[j].day,dates[j].month,dates[j].year,contacts[j].PhoneNumber);
            k[m]=j;
            m++;
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("Not found.");
    }
    else
   {
    printf("\nPlease choose the contact you wish to delete from the list: \n");
        LOOP: scanf("%d",&l);
        if(l>(m))
            {
            printf("\nPlease choose a contact from the list\n");
            goto LOOP;
            }
            contacts[k[l-1]]=contacts[k[l-1]+1];
            dates[k[l-1]]=dates[k[l-1]+1];
            printf("Contact deleted\n");
}
i--;
}
    void main()
{
    readfromfile();
    int choice;
    do
    {
        puts("\n------------------------------------");
        puts("\nMenu");
        puts("1. Search");
        puts("2. Add");
        puts("3. Delete");
        puts("4. Modify");
        puts("5. Print(Sorted)");
        puts("6. Save");
        puts("7. Quit\n");
        puts("------------------------------------");
        scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                search();
                break;
            case 2:
                ADD();
                break;
            case 3:
                delete();
                break;
            case 4:
                modify();
                break;
            case 5:
                printDirectory();
                break;
            case 6:
                savetofile();
                puts("Saved");
                break;
            case 7:
                puts("Exiting");
                return;
                break;
            default:
                printf("Enter again\n");
                break;
            }
        }
        while (1);
    }
