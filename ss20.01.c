#include<stdio.h>
 typedef struct{
	char bookID[20];
	char title[200];
	char author[100];
	float price;
	char category[50];
	
}Book;
void addBook(Book book[],int n);
void displayBook(Book book[],int n);
void addBookPosition(Book book[],int *n); 
void deleteBookID(Book book[],int *n);
void updateBookID(Book book[],int *n);
void sortBook(Book book[],int *n,int ascending);
void searchBook( Book book[],int *n);
int main(){
	Book books[100];
	int n=0;
	int choice;
	do{
		printf("**********MENU********** \n");
		printf("1.nhap so luong va thong tin sach \n");
		printf("2.hien thi thong tin sach \n");
		printf("3.them sach vao vi tri \n");
		printf("4.xoa sach theo ma sach \n");
		printf("5.cap nhat thong tin sach theo ma sach \n");
		printf("6.sap xep sach theo gia(tang\giam) \n");
		printf("7.tim kiem sach theo ten sach \n");
		printf("8.thoat \n ");
		printf("lua chon cua ban: ");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:{
					printf("nhap so luong sach: ");
	                scanf("%d",&n);
	               getchar();
				addBook(books,n);
				break ;
				
			}
			case 2:{
				displayBook(books,n);
				break;
			}
			case 3:{
				addBookPosition(books,&n);
				break;
			}
			case 4:{
				deleteBookID(books,&n);
				
				break;
			}
			case 5:{
				updateBookID(books,&n);
				break;
			}
			case 6:{
			printf("Sap xep tang (1) hay giam (0): ");
                int ascending;
                scanf("%.2f", &ascending);
                sortBook(books,n, ascending);
				break;
			}
			case 7:{
				searchBook(books,&n);
				break;
			}
			case 8:{
				printf("thoat chuong trinh");
				
				
				break;
			}
			default:
				printf("lua chon khong hop le \n");
			
		}
		
	}while(choice!=8);
	return 0;
}
void addBook(Book book[],int n){

	for (int i=0;i<n;i++){
		printf("nhap thong tin sach thu %d: \n",i+1);
		printf("ma sach: ");
		fgets(book[i].bookID,sizeof(book[i].bookID),stdin);
		book[i].bookID[strcspn(book[i].bookID,"\n")]='\0';
		
		printf("ten sach: ");
		fgets(book[i].title,sizeof(book[i].title),stdin);
		book[i].title[strcspn(book[i].title,"\n")]='\0';
		
		printf("ten tac gia: ");
		fgets(book[i].author,sizeof(book[i].author),stdin);
		book[i].author[strcspn(book[i].author,"\n")]='\0';
		
		printf("gia sach: ");
		scanf("%f",&book[i].price);
		getchar();
		
		printf("the loai:");
		fgets(book[i].category,sizeof(book[i].category),stdin);
		book[i].category[strcspn(book[i].category,"\n")]='\0';
		
	}
}
void displayBook(Book books[], int n){
	for(int i=0;i<n;i++){
		printf("Sach thu %d \n",i+1);
		printf("ma sach: %s \n",books[i].bookID);
		printf("ten sach: %s \n",books[i].title);
		printf("tac gia: %s \n",books[i].author);
		printf("gia tien: %.2f\n",books[i].price);
		printf("the loai: %s\n" ,books[i].category);
	}
}
void addBookPosition(Book book[],int *n){
int position;
printf("moi ban nhap vao vi tri ma ban muon them sach: ");
scanf("%d",&position);
getchar();
printf("\n");
if(position<0||position>*n){
	printf("vi tri nay khong hop le\n"); 
}else{
for(int i=*n; i>position; i--){
	book[i]=book[i-1];
}
        printf("nhap thong tin sach moi: \n");
		printf("ma sach: ");
		fgets(book[position].bookID,sizeof(book[position].bookID),stdin);
		book[position].bookID[strcspn(book[position].bookID,"\n")]='\0';
		
		printf("ten sach: ");
		fgets(book[position].title,sizeof(book[position].title),stdin);
		book[position].title[strcspn(book[position].title,"\n")]='\0';
		
		printf("ten tac gia: ");
		fgets(book[position].author,sizeof(book[position].author),stdin);
		book[position].author[strcspn(book[position].author,"\n")]='\0';
		
		printf("gia sach: ");
		scanf("%f",&book[position].price);
		getchar();
		
		printf("the loai:");
		fgets(book[position].category,sizeof(book[position].category),stdin);
		book[position].category[strcspn(book[position].category,"\n")]='\0';
		
		(*n)++;
		printf("them sach thanh cong \n");
}
}
void deleteBookID(Book book[],int *n){
	char bookID[20];
	printf("moi ban nhap ID sach ma ban muon xoa: ");
	fgets(bookID,sizeof(bookID),stdin);
	bookID[strcspn(bookID,"\n")]='\0';
	int indexToDelete=-1;
	for (int i=0;i<*n;i++){
		if(strcmp(book[i].bookID,bookID)==0){
			indexToDelete=i;
			break;
		}
	}
	if(indexToDelete ==-1){
		printf("khong tim thay sach tuong ung voi ma: %s\n",bookID);
		return;
	}
	for(int i=indexToDelete;i<*n;i++){
		book[i]=book[i+1];
		
	}
	(*n)--;
	printf("xoa phan tu thanh cong \n");
}
void updateBookID(Book book[],int *n){
	char bookID[20];
	printf("moi ban nhap vao ID sach ma ban muon cap nhat: ");
	fgets(bookID,sizeof(bookID),stdin);
	bookID[strcspn(bookID,"\n")]='\0';
	int indexToUpdate=-1;
	for (int i=0;i<*n;i++){
		if(strcmp(book[i].bookID,bookID)==0){
			indexToUpdate=i;
		  break;
		}
	}
	if(indexToUpdate==-1){
		printf("khong tim thay sach tuong ung voi ma: %s\n",bookID);
		return;
	}
	printf("moi ban nhap thong tin sach\n");
	printf("ten sach: ");
	fgets(book[indexToUpdate].title,sizeof(book[indexToUpdate].title),stdin);	
	book[indexToUpdate].title[strcspn(book[indexToUpdate].title,"\n")]='\0';
	
	printf("tac gia: ");
	fgets(book[indexToUpdate].author,sizeof(book[indexToUpdate].author),stdin);
	book[indexToUpdate].author[strcspn(book[indexToUpdate].author,"\n")]='\0';
	
	printf("gia sach: ");
     scanf("%.2f",book[indexToUpdate].price);
	getchar();
	
	printf("the loai: ");
	fgets(book[indexToUpdate].category,sizeof(book[indexToUpdate].category),stdin);
	book[indexToUpdate].category[strcspn(book[indexToUpdate].category,"\n")]='\0';
   
   printf("cap nhat thanh cong");
}
void sortBook(Book book[],int *n,int ascending){
	for(int i=0;i<*n;i++){
		for(int j=0;j<*n;j++){
			if((ascending&&book[i].price>book[j].price)||(!ascending&&book[i].price<book[j].price)){
				Book temp=book[i];
				book[i] =book[i];
				book[j]=temp;
			}
		}
	}
	printf("sap xep thanh cong.\n");
	
}
/*void searchBook( Book book[],int *n){
	char bookSearchName;
	printf("moi ban nhap vao ten sach ma ban muon tim: ");
	fgets(bookSearchName,sizeof(bookSearchName),stdin);
	bookSearchName[strcspn(bookSearchName,"\n")]='\0';
	int indexToSearch=-1;
	for(int i=0;i<n;i++){
		if(strcmp(bookSearchName,book[i].title)==0){
			indexToSearch=i;
			break;
			
		}
	}
	if(indexToSearch==-1){
		printf("sach %s khong ton tai trong thu vien \n",bookSearchName);
		return;
	}
	    printf("thong tin sach %s trong thu vien:  \n",bookSearchName);
		printf("ma sach: %s \n",books[indexToSearch].bookID);
		printf("ten sach: %s \n",books[indexToSearch].title);
		printf("tac gia: %s \n",books[indexToSearch].author);
		printf("gia tien: %.2f\n",books[indexToSearch].price);
		printf("the loai: %s\n" ,books[indexToSearch].category);

	
} */
 
