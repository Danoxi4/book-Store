#include<iostream>//adding important header files used to maipulate the operations on our code
#include<string.h>
#include<fstream>
using namespace std;

struct book
//declaring the structure
{
//defining the members of the structure
	char name[50];
	int year_of_publication;
	char author[20];
	float price;
	char genre[20];
	int page;
};

/***********************************************************************************************/

	book bk[15],bk2[15],bkt;//declaring an array that will accept the data that will be inserted
	int index,min,max,numofbk; //declaring important variables later to be used in the program 
	char word[50];
	
	//declaring important functions which later will be used in the program
	void search();
	void accept();
	void count();
	void delet();
	void menu();
	void maximum();
	void minimum();
	void average();
	int display(int,int);
	void inputfile();
	void outputfile();
	void update();
	void upyear(int,int);
	void upname(int,int);
	void upauthor(int,int);
	void upprice(int,int);
	void upgenre(int,int);
	void uppage(int,int);
	int swich(int,int);
	void top();
	
/*************************************************************************************************/

	
int main(){
	int dec1;//variabes to accept diffrent decisions of users
	int dec2;
	
	cout<<"\t\t\t\twellcome to our program!!!"<<endl<<endl<<endl;//first interface page

		
bg:	cout<<"\t\tplease enter the number of books you want to work with"<<endl<<endl;
	
	cin>>numofbk;
	if(cin.fail()){
		cin.clear();
		cin.ignore();
	numofbk=0;
	goto bg;
	}
		//accepting the number of books the user wants to work with
	
		cout<<"\t\twhich option would you like to procced with?"<<endl<<endl;
L:	
	cout<<"\t\tpress [1] if you want to enter your own data"<<endl;

	cout<<"\t\tpress [2] if you want to use existing data"<<endl;
	
	cin>>dec1;
	
	if(dec1==1)//checking the decision of user and redirecting according to it
	
		accept();
	
	else if(dec1==2){
		
 		inputfile();		
		outputfile();	
}
	else{
	
		cout<<"\t\tplease select correctly"<<endl<<endl;//returning command incase the user inputs
														//wrong input
		goto L;
	
		}
menu();

	
	
return 0;	
}

void menu(){
	int dec2;
beg:cout<<endl<<"\t\tpress[1]to delete an entry"<<endl<<endl;//second display for informing user 
	cout<<"\t\tpress[2]to update an entry"<<endl<<endl;//of the diffrent functions of the program
	cout<<"\t\tpress[3]to search an entry"<<endl<<endl;
	cout<<"\t\tpress[4]to view all entries"<<endl<<endl;
	cout<<"\t\tpress[5]to find averages of entries"<<endl<<endl;
	cout<<"\t\tpress[6]to find the maximum of enteries"<<endl<<endl;
	cout<<"\t\tpress[7]to find the minimum of enteries"<<endl<<endl;
	cout<<"\t\tpress[8]to see top list"<<endl<<endl;
	cout<<"\t\tpress[9]to count entries"<<endl<<endl;
	cout<<"\t\tpress[0]to to send current entries to notepad file"<<endl<<endl;

	cin>>dec2;//accepting decision of user
	
	if(dec2==1){//directing towards the function that the user desired
	
		delet();
		
			}
	else if(dec2==0){
		outputfile();
	}
	else if(dec2==3){
		
		search();	
		
			}	
	else if(dec2==6){
	
		maximum();}
	
	else if(dec2==7){
	
		minimum();
		
	}
	else if(dec2==5){
	
		average();		
	}
	else if(dec2==4){
	
		display(0,numofbk);	
		
	}
	else if(dec2==9){
	
		count();
	
	}
	else if(dec2==2){
	
		update();	
		
	}

		
	else if(dec2==8){
		top();
		
	}
	else {
		cout<<"\t\tplease enter correct choice"<<endl<<endl;//incase user inputs wrong input
		menu();
	}	
	
}

/************************************************************************************************/


void inputfile()//function for accepting data from a notepad file
{
   ifstream indata("C:\\books.txt");//specifing location and name of docuument
   if(indata.fail())
   {
     cout << "\nError opening file!\n";//error message in case file opeing fails
   }
   for(int i = 0; i < numofbk; i++)//accepting data from file
   {
        indata.getline(bk[i].name, 50);
        indata >> bk[i].year_of_publication;
        indata.getline(bk[i].author, 20);
		indata.getline(bk[i].author, 20);
        indata >> bk[i].price;
        indata >> bk[i].page;
        indata.getline(bk[i].genre, 20);
        indata.getline(bk[i].genre, 20);
       

        
   }

   indata.close();
   
   display(0,numofbk);//displaying retrivied data for assurance
	menu();//return to menu
   cout << "Data read successfully! Enter any key to continue...";
   

}

/*************************************************************************************************/


void outputfile()//a function that writes the data entered in the program it into file 
{
	cout<<"\n\t\tenter the name of file you want to send your files to";
	cin.getline(word,20);
	cin.getline(word,20);
	
    ofstream outdata(word);//locating or creating notepad file
    
    if(outdata.fail())
       cout << "Error opening file!\n";//notification in case process fails
    
 outdata << "The information of all books in the structure:\n";
    for(int i = 0; i < numofbk; i++)//sending data to the notepade file
    {
        outdata << "\n book " << i + 1 << endl;
        outdata << "________\n";
        outdata << bk[i].name << endl;
        outdata << bk[i].year_of_publication << endl;
        outdata << bk[i].price<< endl;
        outdata << bk[i].page << endl;
        outdata << bk[i].genre<< endl;
    }

    outdata.close();
    cout << "operation performed!";
	menu();//return to menu 
    
}


/************************************************************************************************/


void accept()
{
//a functio that accepts input from the keyboard
	for(int i=0;i<numofbk;i++){
	cout<<"book num"<<i+1<<"\t";
	cout<<"please enter the book name\t";
	cin.getline(bk[i].name,50);
	cin.getline(bk[i].name,50);
a:	cout<<"please enter the year of publication\t";
	cin>>bk[i].year_of_publication;
	if(cin.fail())
	goto a;
	cout<<"please enter the name of the author\t";
	cin.getline(bk[i].author,50);
	cin.getline(bk[i].author,50);
b:	cout<<"please enter the price of the book\t";
	cin>>bk[i].price;
	if(cin.fail())
	goto b;
	cout<<"please enter the gener\t";
	cin.getline(bk[i].genre,50);
	cin.getline(bk[i].genre,50);
c:	cout<<"plese enter the page number";
	cin>>bk[i].page;
	if(cin.fail())
	goto c;
	}	
	menu();//return to menu 
}


/*************************************************************************************************/


void delet()// a function that delets and entry
{
	int dec2,i;
	char confirmation;//giving option for the user to select criteria of deletion
K:	cout<<"\t\tby what criteria do you wish to delete an entry?\n";
	cout<<"\t\tpress [1] if you wish to delete by name\n";
	cout<<"\t\tpress [2] if you wish to delete by year of publication\n";
	cout<<"\t\tpress [3] if you wish to delete by genre\n";
	cout<<"\t\tpress [4] if you wish to delete by author\n";
	cout<<"\t\tpress [5] if you wish to delete by price\n";
	cout<<"\t\tpress [6] if you wish to delete by page number\n";
	cout<<"\t\tpress [7] if you wish to delete by rank of entry\n";
	cout<<"\t\tpress [8] to delete book with maximum price\n";
	cout<<"\t\tpress [9] to delete book with minimum price\n\n\n\n";
	cin>>dec2;//accepting decision of user
	if(dec2==1){//redirecting according to users wish
		cout<<"\t\t\tplease enter the name of the book you wish to delete\n\n";
		cin.getline(word,50);
		cin.getline(word,50);
		for(i=0;i<numofbk;i++){
			if(stricmp(bk[i].name,word)==0){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to delete?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation=='y'){
				strcpy(bk[i].name,0);
				strcpy(bk[i].author,0);
				bk[i].year_of_publication=0;
				bk[i].page=0;
				bk[i].price=0;
				strcpy(bk[i].genre,0);
				cout<<bk<<"\n\nthe entery has been deleted";
				}
			}			
		}
			if(stricmp(bk[numofbk-1].name,word)!=0)
			cout<<"sorry there is no book by the name "<<word<<" in your entry";
	}
	else if(dec2==2){
		cout<<"\tplease enter the year of publication for the book you wish to delete\n";
		cin>>index;
		for(i=0;i<numofbk;i++){
			if(bk[i].year_of_publication==index){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to delete?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
				strcpy(bk[i].name,0);
				strcpy(bk[i].author,0);
				bk[i].year_of_publication=0;
				bk[i].page=0;
				bk[i].price=0;
				strcpy(bk[i].genre,0);
				cout<<"\n\n\tthe entery has been deleted";
				}
			}			
		}
			if(bk[numofbk-1].year_of_publication != index)
			cout<<"sorry there is no book published in"<<index<<"in your entry";
	}
	
	else if(dec2==3){
		cout<<"\tplease enter the genre of the book you wish to delete\n";	
		cin.getline(word,50);
		cin.getline(word,50);
		for(i=0;i<numofbk;i++){
			if(stricmp(bk[i].genre,word)==0){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to delete?\npress 'y' for yes\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
				strcpy(bk[i].name,0);
				strcpy(bk[i].author,0);
				bk[i].year_of_publication=0;
				bk[i].page=0;
				bk[i].price=0;
				strcpy(bk[i].genre,0);
				cout<<"\tthe entery has been deleted";
				}
			}			
		}
		
			if(stricmp(bk[numofbk-1].genre,word)!=0)
			cout<<"sorry there is no book by the genre"<<word<<"in your entry";
	}
	else if(dec2==4){
		cout<<"\t\tplease enter the author of the book you wish to delete\n";	
		cin.getline(word,50);
		cin.getline(word,50);
		for(i=0;i<numofbk;i++){
			if(stricmp(bk[i].author,word)==0){
				display(i,i+1);
			cout<<"\tis this the entery you wish to delete?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
				strcpy(bk[i].name,0);
				strcpy(bk[i].author,0);
				bk[i].year_of_publication=0;
				bk[i].page=0;
				bk[i].price=0;
				strcpy(bk[i].genre,0);
				cout<<"\n\tthe entery has been deleted";
				}
			}			
		}
			if(stricmp(bk[numofbk-1].author,word)!=0)
			cout<<"sorry there is no book with the author"<<word<<"in your entry";
	}
	else if(dec2==5){
		cout<<"\t\tplease enter the price of the book you wish to delete\n";
		cin>>index;
		for(i=0;i<numofbk;i++){
			if(bk[i].price=index){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to delete?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
				strcpy(bk[i].name,0);
				strcpy(bk[i].author,0);
				bk[i].year_of_publication=0;
				bk[i].page=0;
				bk[i].price=0;
				strcpy(bk[i].genre,0);
				cout<<"\t\tthe entery has been deleted";
				}
			}	
		}	
			if(bk[numofbk-1].price != index)
			cout<<"sorry there is no book with the price"<<index<<"in your entry";		
		
	}
	else if(dec2==6){
		cout<<"\tplease enter the page number of the book you wish to delete\n";
		cin>>index;
		for(i=0;i<numofbk;i++){
			if(bk[i].page=index){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to delete?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
				strcpy(bk[i].name,0);
				strcpy(bk[i].author,0);
				bk[i].year_of_publication=0;
				bk[i].page=0;
				bk[i].price=0;
				strcpy(bk[i].genre,0);
				cout<<"\tthe entery has been deleted";
				}
			}			
		}	
			if(bk[numofbk-1].page != index)
			cout<<"sorry there is no book with the page number"<<index<<"in your entry";
		
	}
	else if(dec2==8){
		::min=bk[0].price;
    for(i=0; i<numofbk; i++) {
       
        if(bk[i].price > ::min) {
            ::min= bk[i].price;
            index = i;
        }}
    for(int j=0;j<numofbk;j++){
    	if(bk[j].price==bk[index].price){
    		display(i,i+1);
   			cout<<"\t\tdo you  wish to delete ths entry?\nenter 'y' for yes";
   			cin>>confirmation;
   			switch(confirmation){
   				case 'y':{		
				strcpy(bk[j].name,0);
				strcpy(bk[j].author,0);
				bk[j].year_of_publication=0;
				bk[j].page=0;
				bk[j].price=0;
				strcpy(bk[j].genre,0);
				cout<<"\n\n\tthe entery has been deleted";
					break;
				   }
			   }
			   }
	}}
		
	else if(dec2==7){
Q:		cout<<"\tplease enter the rank in which you entered this data you wish to delete\n";
		cin>>index;
		if(index<1 || index>numofbk){
			cout<<"there is no file with such index number please enter again\n";
			goto Q;
		}
		else{
			display(index,index+1);
			cout<<"\t\tis this the entery you wish to delete?\npress 'y' for yes\n press 'n' for no";
			cin>>confirmation;
			if(confirmation='n')
				goto Q;
			else if(confirmation='y'){
				strcpy(bk[index].name,0);
				strcpy(bk[index].author,0);
				bk[index].year_of_publication=0;
				bk[index].page=0;
				bk[index].price=0;
				strcpy(bk[index].genre,0);
				cout<<"\tthe entery has been deleted";
			}
		}	
		
	}
	
	else if(dec2==9){
		::max=bk[0].price;
    for(i=0; i<numofbk; i++) {
       
        if(bk[i].price < ::max) {
            ::max= bk[i].price;
            index = i;
        }}
    for(int j=0;j<numofbk;j++){
    	if(bk[j].price==bk[index].price){		
    	    cout<<"\t\tThe book with Maximum price is: \n";
    	    display(j,j+1);
   			cout<<"\t\tdo you  wish to delete ths entry?\nenter 'y' for yes";
   			cin>>confirmation;
   			switch(confirmation){
   				case 'y':{		
				strcpy(bk[j].name,0);
				strcpy(bk[j].author,0);
				bk[j].year_of_publication=0;
				bk[j].page=0;
				bk[j].price=0;
				strcpy(bk[j].genre,0);
				cout<<"\tthe entery has been deleted";
					break;
				   }
			   }
			   }
	}
	}
	else{
		cout<<"\tplease enter a correct choice";
		goto K;
		
	}
		menu();//return to menu 
	
}


/*************************************************************************************************/


void search( )

//a function that searches the desired information from the stored/preexisting data

{
	char confirmation;
	int dec2;
	
E:	cout<<"\t\t\t\t\tby what criteria do you wish to search?\n";//asking user for criteria of search
	cout<<"\n\t\tpress [1] if you wish to search by name\n";
	cout<<"\t\tpress [2] if you wish to search by year of publication\n";
	cout<<"\t\tpress [3] if you wish to search by genre\n";
	cout<<"\t\tpress [4] if you wish to search by author\n";
	cout<<"\t\tpress [5] if you wish to search by price\n";
	cout<<"\t\tpress [6] if you wish to search by page number\n";
	cout<<"\t\tpress [7] if you wish to search by rank of entry\n";
	cin>>dec2;//accepting users decison
	if(dec2==1){//rediricting according to the users wish
		cout<<"\t\t\tplease enter the name of the book you wish to search\n";
		cin.getline(word,50);
		cin.getline(word,50);
		for(int i=0;i<numofbk;i++){
			if(stricmp(bk[i].name,word)==0){
				display(i,i+1);
			cout<<"\tis this the entery you wish to looked for?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
			 	break;
				}
			}
			if(stricmp(bk[numofbk-1].name,word)!=0)
			cout<<"sorry there is no book by the name"<<word<<"in your entry";//incase the file is not found		
		}
	}
	else if(dec2==2){
		cout<<"\t\t\tplease enter the year of publication for the book you wish to search\n";
		cin>>index;
		for(int i=0;i<numofbk;i++){
			if(bk[i].year_of_publication=index){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to look at?\npress 'y' for yes\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
			 break;
				}
			}
			if(bk[numofbk-1].year_of_publication != index)
			cout<<"sorry there is no book published in"<<index<<"in your entry";			
		}
	}
	
	else if(dec2==3){
		cout<<"\t\t\tplease enter the genre of the book you wish to search\n";	
		cin.getline(word,50);
		cin.getline(word,50);
		for(int i=0;i<numofbk;i++){
			if(stricmp(bk[i].genre,word)==0){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to search?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
			 break;
				}
			}			
			if(stricmp(bk[numofbk-1].genre,word)!=0)//incase search result not found
			cout<<"sorry there is no book by the genre"<<word<<"in your entry";			
		}
	}
	else if(dec2==4){
		cout<<"\t\tplease enter the author of the book you wish to search\n";	
		cin.getline(word,50);
		cin.getline(word,50);
		for(int i=0;i<numofbk;i++){
			if(stricmp(bk[i].author,word)==0){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to search?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
			 break;
				}
			}
			if(stricmp(bk[numofbk-1].author,word)!=0)
			cout<<"sorry there is no book with the author"<<word<<"in your entry";			
		}
	}
	else if(dec2==5){
		cout<<"\t\t\tplease enter the price of the book you wish to search\n";
		cin>>index;
		for(int i=0;i<numofbk;i++){
			if(bk[i].price=index){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to serach?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
			 break;
				}
			}
			if(bk[numofbk-1].price != index)
			cout<<"sorry there is no book with the price"<<index<<"in your entry";			
		}	
		
	}
	else if(dec2==6){
		cout<<"\t\t\tplease enter the page number of the book you wish to search\n";
		cin>>index;
		for(int i=0;i<numofbk;i++){
			if(bk[i].page=index){
				display(i,i+1);
			cout<<"\t\tis this the entery you wish to search?\n\npress 'y' for yes\n\n press any other key for no";
			cin>>confirmation;
			 if(confirmation='y'){
			 break;
				}
			}
			if(bk[numofbk-1].page != index)
			cout<<"sorry there is no book with the page number"<<index<<"in your entry";			
		}	
		
	}
		
	else if(dec2==7){
A:		cout<<"\t\tplease enter the rank in which you entered this data you wish to search\n";
		cin>>index;
		if(index<1 || index>numofbk){
			cout<<"\tthere is no file with such index number please enter again\n";
			goto A;
		}
		else{
			display(index,index+1);
			cout<<"\t\tis this the entery you wish to search?\npress 'y' for yes\n press 'n' for no";
			}
		}	
		
	
	else{
		cout<<"please enter a correct choice";
		goto E;
		
	}
		menu();//return to menu
}
	
/************************************************************************************************/
	
void minimum()

//a function that compares ad displays the minimum value 

{

    int i,minimum,index,dec2;
    cout<<"\t\t\twhich minimum valeud book would you like to see?\n";
    cout<<"\t\tenter [1] for minimum price\n";
	cout<<"\t\tenter [2] for minimum page number?\n";
    cin>>dec2;
    switch (dec2){
    case 1:{
		minimum=bk[0].price;
    for(i=0; i<numofbk; i++) {
       
        if(bk[i].price < minimum) {
            minimum = bk[i].price;
            index = i;
        }}
    for(int j=0;j<numofbk;j++){
    	if(bk[j].price==bk[index].price){		
    	    cout<<"\t\tThe book with Minimum price is: \n";
    	    display(j,j+1);
			   }
	}
	break;		
	}
	case 2:{
		minimum=bk[0].page;
    for(i=0; i<numofbk; i++) {
       
        if(bk[i].page < minimum) {
            minimum = bk[i].price;
            index = i;
        }}
    for(int j=0;j<numofbk;j++){
    	if(bk[j].page==bk[index].page){		
    	    cout<<"\t\tThe book with Minimum page is: \n";
    	    display(j,j+1);
			   }
	}
		break;
	}	
	}
		menu();//return to menu 
    

}

/*************************************************************************************************/



void maximum() 

//a function that compares and displays the maximum value

{

    int i,maximum,index,dec2;
    cout<<"\t\t\twhich maximum valeud book would you like to see?\n";
    cout<<"\t\tenter [1] for maximum price\n";
	cout<<"\t\tenter [2] for maximum page number?\n";
    cin>>dec2;
    switch (dec2){
    case 1:{maximum=bk[0].price;
    for(i=0; i<numofbk; i++) {
       
        if(bk[i].price > maximum) {
            maximum = bk[i].price;
            index = i;
        }
    }
    for(int j=0;j<numofbk;j++){
		if(bk[j].price==bk[index].price){
		
    cout<<"The book with Maximum page numbers is: \n";

		display(index,index+1);
	}}
		break;
	}
	case 2:{
		{maximum=bk[0].page;
    for(i=0; i<numofbk; i++) {
       
        if(bk[i].page > maximum) {
            maximum = bk[i].page;
            index = i;
        }
    }
    for(int j=0;j<numofbk;j++){
		if(bk[j].page==bk[index].page){
		
    cout<<"\t\tThe book with Maximum page numbers is: \n";

		display(index,index+1);
	}}
		break;
	}
    
}
}
	menu();//return to menu 
}


/*************************************************************************************************/


void average()//a function that calculates the average of the pagenumbers
{
	int dec2,sum,average;
	cout<<"\t\t\twhich average valeu would you like to see?\n";
    cout<<"\t\tenter [1] for average price\n";
	cout<<"\t\tenter [2] for average page number?\n";
    cin>>dec2;
    switch(dec2){
    	case 1:{
    		
    sum = 0;

    for(int i = 0; i < 10; i++) {

        sum += bk[i].price;

    }

    average=(float)sum /numofbk;

    cout << "\t\tAverage price is = " << average;
			break;
		}
		case 2:{
			
    sum = 0;


    for(int i = 0; i < numofbk; i++) {

        sum += bk[i].page;

    }

    average = (float)sum /numofbk;

    cout << "\t\tAverage page number is = " << average;
			break;
		}
	}
	menu();//return to menu 
}



/************************************************************************************************/



 int display(int x,int y)
 
 /*a function that recieves information from the
  above other functiona and displays them to the screen*/
 
 {
	for(int i=x;i<y;i++){
			cout<<"\t\tname of the book\t"<<bk[i].name<<endl;
			cout<<"\t\tauthor of the book\t"<<bk[i].author<<endl;
			cout<<"\t\tpublication year of the book\t"<<bk[i].year_of_publication<<endl;
			cout<<"\t\tpage number of the book\t"<<bk[i].page<<endl;
			cout<<"\t\tprice of the book\t"<<bk[i].price<<endl;
			cout<<"\t\tgenre of the book\t"<<bk[i].genre<<endl<<endl<<endl<<endl;
	}
	return 0;
}

/*************************************************************************************************/


void count()
//a function that counts the entries by th desire of the user


{
	
		int dec2;

K:	cout<<"\t\t\tby what criteria do you wish to count entris?\n";
	cout<<"\t\tenter [1] if you wish to count by name\n";
	cout<<"\t\tenter [2] if you wish to count by year of publication\n";
	cout<<"\t\tenter [3] if you wish to count by genre\n";
	cout<<"\t\tenter [4] if you wish to count by author\n";
	cout<<"\t\tenter [5] if you wish to count by price\n";
	cout<<"\t\tenter [6] if you wish to count by page number\n";
	cout<<"\t\tenter [7] if you wish to count all books";
	cin>>dec2;
	switch(dec2){
		case 1:{
			cout<<"\n\tenter the name you are searching for \t";
    		cin.getline(word,50);
    		cin.getline(word,50);
			 int result=0;
 			int i;
 			 for(i=0;i<numofbk;i++) {
   			    if(stricmp(bk[i].name,word)==0)
   		         result++;
  					 }
  			 if(result==0){
        cout<<"\nGiven name [ "<<word<<" ] not found.\n";
   						}
  			 else{
        cout<<"\nNo. of Occurrences of [ " <<word<<" ] name is :: "<<result<<" times.\n";
   				}
			break;
		}
		case 2:{
			int x;
			cout<<"\tenter the year you are searching for \t";
    		cin>>x;
			 int result=0;
 			 for(int i=0;i<10;i++) {
   			    if(bk[i].year_of_publication==x)
   		         result++;
  					 }
  			 if(result==0){
        cout<<"\n\tGiven year [ "<<x<<" ] not found.\n";
   						}
  			 else{
        cout<<"\n\tNo. of Occurrences of [ " <<x<<" ] year is :: "<<result<<" times.\n";
   				}
			break;
		}
		case 3:{
			
			cout<<"\t\tenter the genre you are searching for \t";
    		cin.getline(word,50);
    		cin.getline(word,50);
			 int result=0;
 			int i;
 			 for(i=0;i<numofbk;i++) {
   			    if(stricmp(bk[i].genre,word)==0)
   		         result++;
  					 }
  			 if(result==0){
        cout<<"\nGiven genre [ "<<word<<" ] not found.\n";
   						}
  			 else{
        cout<<"\nNo. of Occurrences of [ " <<word<<" ] genre is :: "<<result<<" times.\n";
   				}
			break;
		}
		case 4:{
			
			cout<<"\t\tenter the author you are searching for \t";
    		cin.getline(word,50);
			cin.getline(word,50);
			 int result=0;
 			int i;
 			 for(i=0;i<numofbk;i++) {
   			    if(stricmp(bk[i].author,word)==0)
   		         result++;
  					 }
  			 if(result==0){
        cout<<"\nGiven author [ "<<word<<" ] not found.\n";
   						}
  			 else{
        cout<<"\nNo. of Occurrences of [ " <<word<<" ] author is :: "<<result<<" times.\n";
   				}
			break;
		}
		case 5:{
			float x;
			cout<<"\t\tenter the price you are searching for \t";
    		cin>>x;
			 int result=0;
 			int i;
 			 for(i=0;i<numofbk;i++) {
   			    if(bk[i].price==x)
   		         result++;
  					 }
  			 if(result==0){
        cout<<"\nGiven price [ "<<x<<" ] not found.\n";
   						}
  			 else{
        cout<<"\nNo. of Occurrences of [ " <<x<<" ] price is :: "<<result<<" times.\n";
   				}
			break;
		}
		case 6:{
			int x;
			cout<<"\t\tenter the page you are searching for \t";
    		cin>>x;
			 int result=0;
 			int i;
 			 for(i=0;i<numofbk;i++) {
   			    if(bk[i].page==x)
   		         result++;
  					 }
  			 if(result==0){
        cout<<"\nGiven page [ "<<x<<" ] not found.\n";
   						}
  			 else{
        cout<<"\nNo. of Occurrences of [ " <<x<<" ] page is :: "<<result<<" times.\n";
   				}
			break;
		}
		case 7:{
			int result=0;
			for(int i=0;i<numofbk;i++) {
   		         result++;
  					 }
  					 
  			cout<<"\t\tthe total number of books is  "<<result;
			break;
		}
		}
			menu();//return to menu 
	}
	
/*************************************************************************************************/


void update()/* a function that offers the user to update or 
manipulate the  former information present in the entry*/

{
	
	int x,n,i=sizeof(bk)/sizeof(book);
		 cout<<"dear user, we organize our database by using natural numbers as index ";
		 cout<<"of objects start from 1\n so if you want to update a book in our database \n please use the assigned index of the book "<<endl; 
 
		 cin>>x;

		cout<<"\t\tif you want to update name, enter 1\n";
		cout<<"\t\tif you want to update year of publisher,enter 2\n";
	    cout<< "\t\tif you want to update auther name, enter 3\n";
 	   cout<<"\t\tif you want to update price,enter 4\n";
 	   cout<< "\t\tif you want to update genre, enter 5\n";
 	   cout<< "\t\tif you want to update page , enter 6\n ";
askTheUser:  cin>>n;
switch (n)

{
	case 1: cout<<"\t\tenter the new name of the book\n";
	       upname(x,i);
	        break;
	case 2:cout<<"\t\tenter the publishing year of book\n";
         	upyear(x,i);
	        break;
	case 3: cout<<"\t\tenter auther name\n";
	       upauthor(x,i);
	       break;
    case 4: cout<<"\t\tenter the price of the book\n";
	              upprice(x,i);
	              break;
	case 5: cout<<"\t\tenter the genre of the book\n";
	           upgenre(x,i);
	              break;
	case 6: cout<<"\t\tenter the number of page of book\n";    
	          uppage(x,i);
	              break;
   default: cout<<"\t\tyou enter invalid index!!\n ,please enter again!"<<endl; 
	          goto askTheUser;            
}
	menu();//return to menu 
}
	void upname(int x,int i){//function for updating name
     if(i>x)
      cin>> bk[x].name;
    	menu();//return to menu
     }
     
	void upyear(int x,int i){//function for updating year of publication
     if(i>x)
      cin>> bk[x].year_of_publication;
		menu();//return to menu
     }
     
	void  upauthor(int x,int i){//function for updating name of author
     if(i>x)
      cin>> bk[x].author;
   		menu();//return to menu 
     }
     
     void  upprice(int x,int i){//function for updating price
     if(i>x)
      cin>> bk[x].price;
      	menu();//return to menu 
     }
     
     void  upgenre(int x,int i){//function for updating genre
     if(i>x)
      cin>> bk[x].genre;
      	menu();//return to menu 
     }
     
      void  uppage(int x,int i){//function for updating page number
     if(i>x)
      cin>> bk[x].page;
      	menu();//return to menu 
     }
     
/*************************************************************************************************/
//function for viewing top list
void top(){

char dec2;
char temp[50];


for(int i=0;i<numofbk;i++){
	strcpy(bk2[i].name,bk[i].name);
	bk2[i].year_of_publication=bk[i].year_of_publication;
	strcpy(bk2[i].author,bk[i].author);
	bk2[i].price=bk[i].price;
	strcpy(bk2[i].genre,bk[i].genre);
	bk2[i].page=bk[i].page;
}

cout<<"\t\twchich top list do you wish to see"<<endl<<endl;
cout<<"\t\tenter [n]  to see top five names when listed alphabeticaly"<<endl<<endl;
cout<<"\t\tenter [y] to see the top 7 oldest books"<<endl<<endl;
cout<<"\t\tenter [a] to see top three names of authors when alphabeticaly ordered"<<endl<<endl;
cout<<"\t\tenter [p] to see top 10 expensive books"<<endl<<endl;
cout<<"\t\tenter [g] to see the top6 longest books " <<endl<<endl;
cin>>dec2;

switch(dec2){
	case 'n':{
		for(int i=0;i<numofbk;i++){
			for(int j=i+1;j<numofbk;j++){
				if(stricmp(bk2[j].name,bk2[i].name)<0){
				swich(j,i);				
				}
			}
		}
		
		for(int i=0;i<5;i++){
			cout<<bk2[i].name<<endl<<endl;
		}
		
		break;
	}
	case 'y':{
		for(int i=0;i<numofbk;i++){
			for(int j=i+1;j<numofbk;j++){
				if(bk2[j].year_of_publication<bk2[i].year_of_publication){
				swich(j,i);					
				}
			}
		}
		
		for(int i=0;i<7;i++){
			cout<<bk2[i].name<<endl;
			cout<<bk2[i].year_of_publication<<endl;
		}
		break;
	}
	case 'a':{
		for(int i=0;i<numofbk;i++){
			for(int j=i+1;j<numofbk;j++){
				if(stricmp(bk2[j].author,bk2[i].author)<0){
				swich(j,i);					
				}
			}
		}
		
		for(int i=0;i<3;i++){
			cout<<bk2[i].author<<endl<<endl;
		}		
		break;
	}
	case 'p':{
				for(int i=0;i<numofbk;i++){
			for(int j=i+1;j<numofbk;j++){
				if(bk2[j].price>bk2[i].price){
				swich(j,i);				
				}
			}
		}
		
		for(int i=0;i<10;i++){
			cout<<bk2[i].name<<endl;
			cout<<bk2[i].price<<endl;
		}
		break;
	}
	case 'g':{
		for(int i=0;i<numofbk;i++){
			for(int j=i+1;j<numofbk;j++){
				if(bk2[j].page>bk2[i].page){
				swich(j,i);					
				}
			}
		}
		
		for(int i=0;i<6;i++){
			cout<<bk2[i].name<<endl;
			cout<<bk2[i].page<<endl;
		}
		break;
	}
	
}

	menu();//return to menu 
}
int swich(int j,int i){
				strcpy(bkt.name,bk2[j].name);
				strcpy(bk2[j].name,bk2[i].name);
				strcpy(bk2[i].name,bkt.name);
				strcpy(bkt.author,bk2[j].author);
				strcpy(bk2[j].author,bk2[i].author);
				strcpy(bk2[i].author,bkt.author);
				strcpy(bkt.genre,bk2[j].genre);
				strcpy(bk2[j].genre,bk2[i].genre);
				strcpy(bk2[i].genre,bkt.genre);
				bkt.price=bk2[j].price;
				bk2[j].price=bk2[i].price;
				bk2[i].price=bkt.price;
				bkt.year_of_publication=bk2[j].year_of_publication;
				bk2[j].year_of_publication=bk2[i].year_of_publication;
				bk2[i].year_of_publication=bkt.year_of_publication;
				bkt.page=bk2[j].page;
				bk2[j].page=bk2[i].page;
				bk2[i].page=bkt.page;
				
	return 0;	
	
}

