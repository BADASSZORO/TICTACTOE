#include<iostream>

#include<algorithm>
#include<vector>
#include<string>
#include<array>
#include<set>
#include<cstdio>
#include<conio.h>
using namespace std;
char a[3][3];
string p1,p2;
 char ch1,ch2;
  int haha,count1[8];
  //function to display the game box
void printarr(){
 for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         cout<<i<<j<<"->"<< a[i][j]<<"\t";
      }
      cout<<"\n";
   }
}

int checkarr();
   
int main(){
   cout<<"////TIC TAC TOE GAME////\n";
//intializing the game box :
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         a[i][j]=' ';
      }
   }
   
 
 cout<<"This game needs two players Please enter players name one by one\n";

   cout<<"Player one name\n";
   cin>>p1;
   cout<<"Player two name\n";
   cin>>p2;
     int flag;
     //loop to ask the symbol again if wrong symbol is entered;
    do{
      flag=0;
   cout<<"The two symbols used in these games are X and O,choose the symbol for "<<p1<<"\n";
   cin>>ch1;
  
   
   if(ch1=='X'){
    ch2='O';
   }
   else if(ch1=='O') 
   {ch2='X';}
   else{
      cout<<"Wrong entry enter one to try again\n";
      cin>>flag;
   }
   }while (flag==1);
   cout<<p1<<" "<<ch1<<"\n"<<p2<<" "<<ch2<<"\n";
  printarr();
  
cout<<"Press any key to start the game!!";

getch();//-> this function waits till any character is entered
int count=0,check;

for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){ 
      char val,flag=0;
int k,m;
      do{
         flag=0;
         if(count%2==0){
   cout<<"\nEnter the index "<<p1<<"\n";}
   else cout<<"\nEnter the index "<<p2<<"\n";
   cin>>k>>m;

    if(k>=0 && k<3 && m>=0 && m<3){//checking if index is within limit;
   if(a[k][m]==' '){// checking if the entered index is free
      if(count%2==0)
      a[k][m]=ch1;
   else  a[k][m]=ch2;
      count++;
   }
    else{ cout<<"Already entered index press 1 to enter again\n";
    cin>>flag;}
    }
   else{
      cout<<"Wrong index press 1 to enter again\n";
      cin>>flag;
}

   }while(flag==1);
    printarr();

   check=checkarr();
  
   if(check==1)
   break;

   }

   if(check==1)
   break;
}

 return 0;
}

//function to check for win or draw:
int checkarr(){
   int flag=0, num;
   char won;
//for row and columns check:
   for(int i=0;i<3;i++){
 
      for(int j=0;j<3;j++){
  if(a[i][j]==ch1)
    count1[0]++;
   if(a[i][j]==ch2)
   count1[1]++;
 if(a[j][i]==ch1)
    count1[2]++;
   if(a[j][i]==ch2)
   count1[3]++;

 }//j loop ends;
  
      //for diagonal:
     int k=0,m=0;  
     for(int i=0;i<3;i++){
      
         if(a[k+i][m+i]==ch1){
            count1[4]++;
           
         }
         if(a[k+i][m+i]==ch2){
            count1[5]++;
         }
        
     }
     k=2,m=0;
      for(int i=0;i<3;i++){
         if(a[k-i][m+i]==ch1){
            count1[6]++;
         }
         if(a[k-i][m+i]==ch2){
            count1[7]++;
         }
        
     }


     for(int i=0;i<8;i++){
      if(count1[i]==3){
         num=i;
        flag=1;
       break;
      }
     }
   
  //initializing count1 array to 0;
   for(int i=0;i<8;i++){
      count1[i]=0;
   }
   }//i loop ends;

   if(flag==1){
      if(num%2==0){
            cout<<"Player "<<p1<<" has won\n";
         }
         
        else cout<<"Player "<<p2<<" has won\n";
   }
   //if not won,checking for draw:
   if(flag==0){
   int flag1=0;
   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         if(a[i][j]!='X' && a[i][j]!='O'){
         flag1=1;
     // cout<<i<<j<<" "<<a[i][j]<<"\n";
      break;
      }
     
   }
    if(flag1==1)
      break;
   }
  
   if(flag1==0){
      cout<<"Match drawn\n";
      flag=1;
   
   }
   }
   //if flag=0,the main fun asks for another index,else it finishes the program;
   return flag;
}




 
 
