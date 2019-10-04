#include<iostream>
#include<string>
using namespace std;

class Bucket {  

private:
string name;
int capacity;
int content = 0;

public:
Bucket(string n, int cap);  //takes in bucket name & capacity
void print();  //prints the bucket info
void fill();      //fills bucket to max 
void empty();    // fully empties bucket
int pour_into(Bucket& bucket2 );    //pours from one bucket to another
};


int main() {

int select;
int empty_value;
int transfer;

Bucket bigGal("Bucket A", 5);
Bucket smallGal("Bucket B", 3);


bigGal.print();
smallGal.print();

while (select !=0) {
cout<<"0 - Exit"<<endl;
cout<<"1 - Fill Bucket A"<<endl;
cout<<"2 - Empty Bucket A"<<endl;
cout<<"3 - Pour A into B"<<endl;
cout<<"4 - Fill Bucket B"<<endl;
cout<<"5 - Empty Bucket B"<<endl;
cout<<"6 - Pour B into A"<<endl;


while( !(select>=0 && select <=6)){
cout<< "Enter a number: ";
cin>>select;
cout<<endl;
}

switch(select){
case 0:cout<<"Program Exited";
break;
case 1:bigGal.fill(); 
            bigGal.print();
            smallGal.print(); 
break;
case 2:bigGal.empty(); 
             bigGal.print();
             smallGal.print(); 
break;
case 3:transfer =bigGal.pour_into(smallGal); 
            cout<<transfer<<" gallons were transfered from A into B"<<endl;
            bigGal.print();
            smallGal.print(); 
break;
case 4:smallGal.fill();
            bigGal.print();
            smallGal.print(); 
break;
case 5:smallGal.empty();
             bigGal.print();
             smallGal.print();  
break;
case 6:transfer = smallGal.pour_into(bigGal);
              cout<<transfer<<" gallons were transfered from B into A "<<endl;
             bigGal.print();
            smallGal.print();    
break;
}
if(select == 0) {select = 0;}
else {select = empty_value;} //clears the select's value
}

return 0; 
}


//Class Definition

Bucket::Bucket(string n, int cap)
{
name = n;
capacity= cap;
}

void Bucket::print()
{
cout<<name<<"\'s max capacity: "<<capacity<<" gallons"<<endl;
cout<<name<<"\'s current content: "<<content<<" gallons \n"<<endl;
 if(content == 4){
cout<<"CONGRATS !!  You Solved The Riddle!  \n \n";
}
}

void Bucket::fill(){
content = capacity;
}

void Bucket::empty(){
content = 0;
}

int Bucket::pour_into(Bucket& bucket2){
int trans; 
trans= content;
 
if(bucket2.content  <  bucket2.capacity ){
while (bucket2.content  <  bucket2.capacity && content > 0){
        bucket2.content++;
        content--;
        }
  return trans-=content;  // transfer - (remaining_content of the "pouring outof" bucket)
}
  else  return trans =0;

}
