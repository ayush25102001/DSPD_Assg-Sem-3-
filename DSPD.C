#include<stdio.h>
#include<string.h>
struct vehicle                   //Creating the vehicles structure
{
	char vehicletype[100];
	char maker[100];
	int yearofmanufacture;
	char engineno[100];
	char registrationno[100];
	unsigned int vehicleprice;
	int owners_ID;
};
struct owner                   //Creating the owners structure
{
	int owners_ID;        //Every owner would have a different id.
	char ownersname[100];
	char fathersname[100];
	char address[100];
	struct vehicle vehicles[5]; //important
	int dateofpurchase[5];
	int monthofpurchase[5];
	int yearofpurchase[5];
	double purchaseamount[5];
	int count;
};
void InitializeOwner_Db(struct owner owner_Db[])       
{
	int i=0;
	for(i=0;i<100;i++)
	{
		owner_Db[i].owners_ID=0;
		owner_Db[i].count=0;
		owner_Db[i].ownersname[0]='\0';
		owner_Db[i].fathersname[0]='\0';
		owner_Db[i].address[0]='\0';
		int j=0;
		for(j=0;j<5;j++)
		{
			owner_Db[i].dateofpurchase[j]=0;
		    owner_Db[i].monthofpurchase[j]=0;
		    owner_Db[i].yearofpurchase[j]=0;
		    owner_Db[i].purchaseamount[j]=0;
		    owner_Db[i].vehicles[j].vehicletype[0]='\0';     //initializing the array of struct vehicle in owner
		    owner_Db[i].vehicles[j].maker[0]='\0';
		    owner_Db[i].vehicles[j].yearofmanufacture=0;
		    owner_Db[i].vehicles[j].engineno[0]='\0';
		    owner_Db[i].vehicles[j].registrationno[0]='\0';
		    owner_Db[i].vehicles[j].owners_ID=0;
		}
	}
}
void InitializeVehicle_Db(struct vehicle vehicle_Db[])
{
	int i=0;
	for(i=0;i<500;i++)
	{
		vehicle_Db[i].vehicletype[0]='\0';
	    vehicle_Db[i].maker[0]='\0';
	    vehicle_Db[i].yearofmanufacture=0;
	    vehicle_Db[i].engineno[0]='\0';
	    vehicle_Db[i].registrationno[0]='\0';
	    vehicle_Db[i].vehicleprice=0;
	    vehicle_Db[i].owners_ID=0;
	}
}
void AddNewOwner(struct owner owner_Db[])
{
	int id=0;
	printf("Enter the owners id:");
	scanf("%d",&id);
	int i=0;
	int j=-1;
	int flag=-1;
	int neww=-1;
	while(i<100&&flag&&neww)
	{
		if(owner_Db[i].owners_ID==id)
		{
			flag=0;
		}
		if(owner_Db[i].owners_ID==0)
		{
			j=i;
			neww=0;
		}
		else
		{
			i++;
		}
	}
	if(flag==0)
	{
		printf("User with the given id already exists\n");
	}
	else
	{
		char ownName[100];
		char fatherName[100];
		char address[100];
		owner_Db[j].owners_ID=id;
		printf("Enter owners name:");
		scanf("%s",&ownName);
		printf("Enter fathers name:");
		scanf("%s",&fatherName);
		printf("Enter Address:");
		scanf("%s",&address);
		strcpy(owner_Db[j].ownersname,ownName);
		strcpy(owner_Db[j].fathersname,fatherName);
		strcpy(owner_Db[j].address,address);
	}
}
void AddNewCar(struct owner owner_Db[])
{
	int id=0;
	printf("Enter Owner Id:");
	scanf("%d",&id);
	int i=0;
	int j=-1;
	for(i=0;i<100;i++)
	{
		if(owner_Db[i].owners_ID==id)
		{
			j=i;      //id matched with ith indexed owner, j=i 
			break;
		}
	}
	if(j==-1)
	{
		printf("First Create the Owners entry\n");
	}
	else
	{
		int count=owner_Db[j].count;
		if(owner_Db[j].count==5)
		{
			printf("Owner cannot have more than 5 vehicles");
		}
		else
		{
			printf("ENTER-VEHICLE-DETAILS");
			printf("\n");
			char vehicletype[100];
			char maker[100];
			int yearofmanufacture;
			char engineno[100];
			char registrationno[100];
			unsigned int vehicleprice;
			int owners_ID[100];
			int dateofpurchase;
			int monthofpurchase;
			int yearofpurchase;
			double purchaseamount;
			printf("Enter vehicle type:");
			scanf("%s",&vehicletype);
			strcpy(owner_Db[j].vehicles[count].vehicletype,vehicletype);
			printf("Enter vehicle maker:");
			scanf("%s",&maker);
			strcpy(owner_Db[j].vehicles[count].maker,maker);
			printf("Enter year of manufacture:");
			scanf("%d",&yearofmanufacture);
			owner_Db[j].vehicles[count].yearofmanufacture=yearofmanufacture;
			printf("Enter engine number:");
			scanf("%s",&engineno);
			strcpy(owner_Db[j].vehicles[count].engineno,engineno);
			printf("Enter registration number:");
			scanf("%s",&registrationno);
			strcpy(owner_Db[j].vehicles[count].registrationno,registrationno);
			printf("Enter vehicle price:");
			scanf("%d",&vehicleprice);
			owner_Db[j].vehicles[count].vehicleprice=vehicleprice;
			printf("Enter date of purchase-");
			scanf("%d",&dateofpurchase);
			printf("Enter month of purchase-");
			scanf("%d",&monthofpurchase);
			printf("Enter year of purchase-");
			scanf("%d",&yearofpurchase);
			purchaseamount=vehicleprice;
			owner_Db[j].dateofpurchase[count]=dateofpurchase;
			owner_Db[j].monthofpurchase[count]=monthofpurchase;
			owner_Db[j].yearofpurchase[count]=yearofpurchase;
			owner_Db[j].purchaseamount[count]=vehicleprice;
			owner_Db[i].vehicles[count].owners_ID=id;
			owner_Db[j].count++;
		}
	}
}
void DeleteCar(struct owner owner_Db[])
{
	printf("Enter the ID/Registration number of the vehicle to be deleted:");
	char r[100];
	scanf("%s",&r);
	int i=0;
	int j=0;
	int io=-1;
	int jv=-1;
	for(i=0;i<100;i++)
	{
		for(j=0;j<5;j++)
		{
			if(strcmp(owner_Db[i].vehicles[j].registrationno,r)==0)
			{
				io=i;
				jv=j;
				i=100;
				j=5;
			}
		}
	}
	if(owner_Db[io].count==1)
	{
		owner_Db[io].owners_ID=0;
		owner_Db[io].count=0;
		owner_Db[io].ownersname[0]='\0';
		owner_Db[io].fathersname[0]='\0';
		owner_Db[io].address[0]='\0';
		owner_Db[io].dateofpurchase[0]=0;
		owner_Db[io].monthofpurchase[0]=0;
		owner_Db[io].yearofpurchase[0]=0;
		owner_Db[io].purchaseamount[0]=0;
		owner_Db[io].vehicles[0].vehicletype[0]='\0';     
		owner_Db[io].vehicles[0].maker[0]='\0';
		owner_Db[io].vehicles[0].yearofmanufacture=0;
		owner_Db[io].vehicles[0].engineno[0]='\0';
		owner_Db[io].vehicles[0].registrationno[0]='\0';
		owner_Db[io].vehicles[0].owners_ID=0;
	}
	else
	{
		int j=jv;
		for(j=jv+1;j<5;j++)
		{
			int d=owner_Db[io].dateofpurchase[j-1];
			owner_Db[io].dateofpurchase[j-1]=owner_Db[io].dateofpurchase[j];
			owner_Db[io].dateofpurchase[j]=d;
			int m=owner_Db[io].monthofpurchase[j-1];
			owner_Db[io].monthofpurchase[j-1]=owner_Db[io].monthofpurchase[j];
			owner_Db[io].monthofpurchase[j]=m;
			int y=owner_Db[io].yearofpurchase[j-1];
			owner_Db[io].yearofpurchase[j-1]=owner_Db[io].yearofpurchase[j];
			owner_Db[io].yearofpurchase[j]=y;
			char s[100];
			strcpy(s,owner_Db[io].vehicles[j-1].vehicletype);
			strcpy(owner_Db[io].vehicles[j-1].vehicletype,owner_Db[io].vehicles[j].vehicletype);
			strcpy(owner_Db[io].vehicles[j].vehicletype,s);
			strcpy(s,owner_Db[io].vehicles[j-1].maker);
			strcpy(owner_Db[io].vehicles[j-1].maker,owner_Db[io].vehicles[j].maker);
			strcpy(owner_Db[io].vehicles[j].maker,s);
			strcpy(s,owner_Db[io].vehicles[j-1].engineno);
			strcpy(owner_Db[io].vehicles[j-1].engineno,owner_Db[io].vehicles[j].engineno);
			strcpy(owner_Db[io].vehicles[j].engineno,s);
			strcpy(s,owner_Db[io].vehicles[j-1].registrationno);
			strcpy(owner_Db[io].vehicles[j-1].registrationno,owner_Db[io].vehicles[j].registrationno);
			strcpy(owner_Db[io].vehicles[j].registrationno,s);
			m=owner_Db[io].vehicles[j-1].owners_ID;
			owner_Db[io].vehicles[j-1].owners_ID=owner_Db[io].vehicles[j].owners_ID;
			owner_Db[io].vehicles[j].owners_ID=m;
			m=owner_Db[io].vehicles[j-1].yearofmanufacture;
			owner_Db[io].vehicles[j-1].yearofmanufacture=owner_Db[io].vehicles[j].yearofmanufacture;
			owner_Db[io].vehicles[j].yearofmanufacture=m;
			double val=owner_Db[io].purchaseamount[j-1];
			owner_Db[io].purchaseamount[j-1]=owner_Db[io].purchaseamount[j];
			owner_Db[io].purchaseamount[j]=val;
		}
		//Id of vehicle to be deleted is shifted to the last index of the array
		owner_Db[io].dateofpurchase[4]=0;
		owner_Db[io].monthofpurchase[4]=0;
		owner_Db[io].yearofpurchase[4]=0;
		owner_Db[io].purchaseamount[4]=0;
		owner_Db[io].vehicles[4].vehicletype[0]='\0';     
		owner_Db[io].vehicles[4].maker[0]='\0';
		owner_Db[io].vehicles[4].yearofmanufacture=0;
		owner_Db[io].vehicles[4].engineno[0]='\0';
		owner_Db[io].vehicles[4].registrationno[0]='\0';
		owner_Db[io].vehicles[4].owners_ID=0;
		owner_Db[io].count--;
	}
}
void ListAllCars(struct owner owner_Db[])
{
	int id=0;
	printf("Enter Owner Id:");
    printf("\n");
	scanf("%d",&id);
	int i=0;
	int j=-1;
	for(i=0;i<100;i++)
	{
		if(owner_Db[i].owners_ID==id)
		{
			j=i;      //id matched with ith indexed owner, j=i 
			break;
		}
	}
	if(j==-1)
	{
		printf("First Create the Owners entry\n");
	}
	else
	{
		int count=owner_Db[j].count;
		int i=0;
		int k=0;
		for(i=0;i<count-1;i++)
		{
			for(k=0;k<count-i-1;k++)
			{
				if(owner_Db[j].vehicles[k].yearofmanufacture>owner_Db[j].vehicles[k+1].yearofmanufacture)
				{
					int d=owner_Db[j].dateofpurchase[k];
			        owner_Db[j].dateofpurchase[k]=owner_Db[j].dateofpurchase[k+1];
			        owner_Db[j].dateofpurchase[j]=d;
			        int m=owner_Db[j].monthofpurchase[k];
			        owner_Db[j].monthofpurchase[k]=owner_Db[j].monthofpurchase[k+1];
			        owner_Db[j].monthofpurchase[k+1]=m;
			        int y=owner_Db[j].yearofpurchase[k];
			        owner_Db[j].yearofpurchase[k]=owner_Db[j].yearofpurchase[k+1];
			        owner_Db[j].yearofpurchase[k+1]=y;
			        char s[100];
			        strcpy(s,owner_Db[j].vehicles[k].vehicletype);
			        strcpy(owner_Db[j].vehicles[k].vehicletype,owner_Db[j].vehicles[k+1].vehicletype);
			        strcpy(owner_Db[j].vehicles[k+1].vehicletype,s);
			        strcpy(s,owner_Db[j].vehicles[k].maker);
			        strcpy(owner_Db[j].vehicles[k].maker,owner_Db[j].vehicles[k+1].maker);
			        strcpy(owner_Db[j].vehicles[k+1].maker,s);
			        strcpy(s,owner_Db[j].vehicles[k].engineno);
			        strcpy(owner_Db[j].vehicles[k].engineno,owner_Db[j].vehicles[k+1].engineno);
			        strcpy(owner_Db[j].vehicles[k+1].engineno,s);
			        strcpy(s,owner_Db[j].vehicles[k].registrationno);
			        strcpy(owner_Db[j].vehicles[k].registrationno,owner_Db[j].vehicles[k+1].registrationno);
			        strcpy(owner_Db[j].vehicles[k+1].registrationno,s);
			        m=owner_Db[j].vehicles[k].owners_ID;
			        owner_Db[j].vehicles[k].owners_ID=owner_Db[j].vehicles[k+1].owners_ID;
			        owner_Db[j].vehicles[k+1].owners_ID=m;
			        m=owner_Db[j].vehicles[k].yearofmanufacture;
			        owner_Db[j].vehicles[k].yearofmanufacture=owner_Db[j].vehicles[k+1].yearofmanufacture;
			        owner_Db[j].vehicles[k+1].yearofmanufacture=m;
				}
			}
		}
		i=0;
		printf("USERS CARS COLLECTION:\n");
		for(i=0;i<count;i++)
		{
		    printf("Yearofmanufacture=%d\n",owner_Db[j].vehicles[i].yearofmanufacture);
			printf("Vehicletype=%s\n",owner_Db[j].vehicles[i].vehicletype);
			printf("Maker=%s\n",owner_Db[j].vehicles[i].maker);
			printf("Engineno=%s\n",owner_Db[j].vehicles[i].engineno);
			printf("Registrationno=%s\n",owner_Db[j].vehicles[i].registrationno);
			printf("\n");
		}
	}
}
void MaxAndSecMax(struct owner owner_Db[])
{
	int i=0;
	int maxx=-1;
	int smaxx=-1;
	for(i=0;i<100;i++)
	{
		if(owner_Db[i].count>=maxx)
		{
			maxx=owner_Db[i].count;
		}
	}
	for(i=0;i<100;i++)
	{
		if((owner_Db[i].count>=smaxx)&&(owner_Db[i].count<maxx))
		{
			smaxx=owner_Db[i].count;
		}
	}
	printf("\nOWNER DETAILS WITH MAXIMUM NUMBER OF VEHICLES:\n");
	for(i=0;i<100;i++)
	{
		if(owner_Db[i].count==maxx)
		{
			printf("Owners_ID=%d\n",owner_Db[i].owners_ID);
	        printf("Ownersname=%s\n",owner_Db[i].ownersname);
	        printf("Fathersname=%s\n",owner_Db[i].fathersname);
	        printf("Address=%s\n",owner_Db[i].address);
	        printf("Vehicle count=%d\n",owner_Db[i].count);
		}
	}
	if(smaxx>0)
	{
	printf("\nOWNER DETAILS WITH SECOND MAXIMUM NUMBER OF VEHICLES:");
	for(i=0;i<100;i++)
	{
		if(owner_Db[i].count==smaxx)
		{
			printf("Owners_ID=%d\n",owner_Db[i].owners_ID);
	        printf("Ownersname=%s\n",owner_Db[i].ownersname);
	        printf("Fathersname=%s\n",owner_Db[i].fathersname);
	        printf("Address=%s\n",owner_Db[i].address);
	        printf("Vehicle count=%d\n",owner_Db[i].count);
		}
	}
    }
}
void CostliestVehicleOwned(struct owner owner_Db[])
{
	int id=0;
	printf("Enter Owner Id:");
    printf("\n");
	scanf("%d",&id);
	int i=0;
	int j=-1;
	for(i=0;i<100;i++)
	{
		if(owner_Db[i].owners_ID==id)
		{
			j=i;      
			break;
		}
	}
	if(j==-1)
	{
		printf("First Create the Owners entry\n");
	}
	else
	{
		int i=0;
		double val=0;
		int flag=-1;
		for(i=0;i<5;i++)
		{
			if(owner_Db[j].purchaseamount[i]>val)
			{
				val=owner_Db[j].purchaseamount[i];
				flag=i;
			}
		}
		printf("Price of costliest vehicle owned by user with give id is=%lf",val);
	}
}
void morethan1vehicleofabrand(struct owner owner_Db[])
{
	char brand[100];
	printf("Enter brand name:");
	scanf("%s",&brand);
	int i=0;
	int j=0;
	int cnt=0;
	printf("\nOwner details having more than 1 vehicle of given brand:\n");
	for(i=0;i<100;i++)
	{
		cnt=0;
		for(j=0;j<5;j++)
		{
			if(strcmp(owner_Db[i].vehicles[j].maker,brand)==0)
			{
				cnt=cnt+1;
			}
		}
		if(cnt>1)
		{
			printf("Owners_ID=%d\n",owner_Db[i].owners_ID);
	        printf("Ownersname=%s\n",owner_Db[i].ownersname);
	        printf("Fathersname=%s\n",owner_Db[i].fathersname);
	        printf("Address=%s\n",owner_Db[i].address);
	        printf("Vehicle count=%d\n",owner_Db[i].count);
		}
	}
}
void wheeleringivenyear(struct owner owner_Db[])
{
	int y;
	printf("Enter year:");
	scanf("%d",&y);
	int i=0;
	int j=0;
	char type[100];
	strcpy(type,"3-wheeler");
	for(i=0;i<100;i++)
	{
		for(j=0;j<5;j++)
		{
			if((owner_Db[i].yearofpurchase[j]==y))
			{
				if(strcmp(owner_Db[i].vehicles[j].vehicletype,type)==0)
				{
					printf("\nOwner details:");
				    printf("Owners_ID=%d\n",owner_Db[i].owners_ID);
	                printf("Ownersname=%s\n",owner_Db[i].ownersname);
	                printf("Fathersname=%s\n",owner_Db[i].fathersname);
	                printf("Address=%s\n",owner_Db[i].address);
	                printf("Vehicle count=%d\n",owner_Db[i].count);
	                j=5;
				}
			}
		}
	}
}
void carsbefore1990(struct owner owner_Db[])
{
	int i=0;
	int j=0;
	int k=0;
	for(i=0;i<100;i++)
	{
		for(k=0;k<5;k++)
		{
			if((owner_Db[i].vehicles[k].yearofmanufacture<1990)&&(owner_Db[i].vehicles[k].yearofmanufacture!=0))
			{
				int jv=k;
		        int io=i;
		        for(j=jv+1;j<5;j++)
		        {
			        int d=owner_Db[io].dateofpurchase[j-1];
			        owner_Db[io].dateofpurchase[j-1]=owner_Db[io].dateofpurchase[j];
			        owner_Db[io].dateofpurchase[j]=d;
			        int m=owner_Db[io].monthofpurchase[j-1];
			        owner_Db[io].monthofpurchase[j-1]=owner_Db[io].monthofpurchase[j];
			        owner_Db[io].monthofpurchase[j]=m;
			        int y=owner_Db[io].yearofpurchase[j-1];
			        owner_Db[io].yearofpurchase[j-1]=owner_Db[io].yearofpurchase[j];
			        owner_Db[io].yearofpurchase[j]=y;
			        char s[100];
			        strcpy(s,owner_Db[io].vehicles[j-1].vehicletype);
			        strcpy(owner_Db[io].vehicles[j-1].vehicletype,owner_Db[io].vehicles[j].vehicletype);
			        strcpy(owner_Db[io].vehicles[j].vehicletype,s);
			        strcpy(s,owner_Db[io].vehicles[j-1].maker);
			        strcpy(owner_Db[io].vehicles[j-1].maker,owner_Db[io].vehicles[j].maker);
			        strcpy(owner_Db[io].vehicles[j].maker,s);
			        strcpy(s,owner_Db[io].vehicles[j-1].engineno);
			        strcpy(owner_Db[io].vehicles[j-1].engineno,owner_Db[io].vehicles[j].engineno);
			        strcpy(owner_Db[io].vehicles[j].engineno,s);
			        strcpy(s,owner_Db[io].vehicles[j-1].registrationno);
			        strcpy(owner_Db[io].vehicles[j-1].registrationno,owner_Db[io].vehicles[j].registrationno);
			        strcpy(owner_Db[io].vehicles[j].registrationno,s);
			        m=owner_Db[io].vehicles[j-1].owners_ID;
			        owner_Db[io].vehicles[j-1].owners_ID=owner_Db[io].vehicles[j].owners_ID;
			        owner_Db[io].vehicles[j].owners_ID=m;
			        m=owner_Db[io].vehicles[j-1].yearofmanufacture;
			        owner_Db[io].vehicles[j-1].yearofmanufacture=owner_Db[io].vehicles[j].yearofmanufacture;
			        owner_Db[io].vehicles[j].yearofmanufacture=m;
			        double val=owner_Db[io].purchaseamount[j-1];
			        owner_Db[io].purchaseamount[j-1]=owner_Db[io].purchaseamount[j];
			        owner_Db[io].purchaseamount[j]=val;
		        }
		        owner_Db[io].dateofpurchase[4]=0;
		        owner_Db[io].monthofpurchase[4]=0;
		        owner_Db[io].yearofpurchase[4]=0;
		        owner_Db[io].purchaseamount[4]=0;
		        owner_Db[io].vehicles[4].vehicletype[0]='\0';     
		        owner_Db[io].vehicles[4].maker[0]='\0';
		        owner_Db[io].vehicles[4].yearofmanufacture=0;
		        owner_Db[io].vehicles[4].engineno[0]='\0';
		        owner_Db[io].vehicles[4].registrationno[0]='\0';
		        owner_Db[io].vehicles[4].owners_ID=0;
		        owner_Db[io].count--;
			}
			if(owner_Db[i].count==0)
			{
				owner_Db[i].owners_ID=0;
		        owner_Db[i].count=0;
		        owner_Db[i].ownersname[0]='\0';
		        owner_Db[i].fathersname[0]='\0';
			}
		}
	}
}
void sameyearmorethan12wheeler(struct owner owner_Db[])
{
	int i=0;
	int j=0;
	int k=0;
	for(i=0;i<100;i++)
	{
		for(j=0;j<4;j++)
		{
			if(strcmp(owner_Db[i].vehicles[j].vehicletype,"2-wheeler")==0)
			{
				for(k=j+1;k<5;k++)
				{
					if((strcmp(owner_Db[i].vehicles[k].vehicletype,"2-wheeler")==0)&&(owner_Db[i].yearofpurchase[j]==owner_Db[i].yearofpurchase[k]))
					{
						printf("\nOwner details:");
				        printf("Owners_ID=%d\n",owner_Db[i].owners_ID);
	                    printf("Ownersname=%s\n",owner_Db[i].ownersname);
	                    printf("Fathersname=%s\n",owner_Db[i].fathersname);
	                    printf("Address=%s\n",owner_Db[i].address);
	                    printf("Vehicle count=%d\n",owner_Db[i].count);
	                    k=5;j=4;
					}
				}
			}
		}
	}
}
int main()
{
	struct owner owner_Db[100];
	struct vehicle vehicle_Db[500];
	InitializeOwner_Db(owner_Db);          //completed
	InitializeVehicle_Db(vehicle_Db);      //completed
	int s;
	do
	{
		printf("\n");
		printf("1:Add New Owner\n");
		printf("2:Add new car\n");
		printf("3:Delete car\n");
		printf("4:List cars\n");
		printf("5:Delete cars manufactured before 1990\n");
		printf("6:Find owners with maximum and second maximum number of cars\n");
		printf("7:Owners who purchased more than 1 2-2heeler in same year\n");
		printf("8:Find price of costliest vehicle owned by a owner\n");
		printf("9:Find owners who own more than 1 vehicle of a specified brand\n");
		printf("10:Find owner who purchased 3-wheeler in the given year\n");
		printf("11:EXIT\n");
		printf("Enter choice:\n");
		scanf("%d",&s);
		switch(s)
		{
			case 1:AddNewOwner(owner_Db);break;                       //1
		    case 2:AddNewCar(owner_Db);break;                         //2
			case 3:DeleteCar(owner_Db);break;                         //3
			case 4:ListAllCars(owner_Db);break;                       //4
			case 5:carsbefore1990(owner_Db);break;                    //5
			case 6:MaxAndSecMax(owner_Db);break;                      //6
			case 7:sameyearmorethan12wheeler(owner_Db);break;         //7
			case 8:CostliestVehicleOwned(owner_Db);break;             //8
			case 9:morethan1vehicleofabrand(owner_Db);break;          //9
			case 10:wheeleringivenyear(owner_Db);break;              //10
			case 11:s=0;break;
			default:printf("Invalid_Choice");break;
		}
	}while(s);
    return 0;
}  
