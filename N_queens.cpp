//CSCI 487 Assignment 1
//by Sharath Sreenivas
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>

using namespace std;


int count;
int S[8]; 

void initialize(){ 
	for(int i=0;i<8;i++){
		int val=rand()%8+0; //random number between 1 and 8
		S[i]=val;
	}
}

int ConflictCount(int x,int y){ //counts conflict for each position

	count=0; 

	for(int i=0;i<8;i++){
		if(S[i] == x)
			count++;
 		else if(abs(S[i]-x)==abs(y-i)) //checks diagonal conflict
 			count++;
	}
	//cout<<count;
return count;
}

void printState(){
	cout << "[";
	for(int i=0;i<8;i++){
		if(i!=7)
		cout << S[i] <<",";
		else
		cout << S[i];
	}
	cout <<"]"<< endl;
}

void printCon(int arr[]){ //prints the array of conflicts
	cout << "[";
	for(int i=0;i<8;i++){
		if(i!=7)
		cout << arr[i] <<",";
		else
		cout << arr[i];
	}
	cout <<"]"<< endl;
}

void search(){ 

	int min,minPos;
	int numCon=0;
	int minCon[8];
	
	for(int col=0;col<8;col++){
		for(int row=0;row<8;row++){
			numCon=ConflictCount(row,col);
			minCon[row]=numCon; //creates an array of conflict values
		}
		cout << "For queen: "<<col<<" --> MinCon:=";
		printCon(minCon); //prints the minimum conflict array
		minPos=0; 
		min=minCon[0];
		for(int i=1;i<8;i++){
			if(minCon[i] < min){
				minPos=i;
				min=minCon[i];}
		}
		cout << "MinPos: "<<minPos<<endl; //position of least conflicts
		S[col]=minPos; //replace queen posiion with position of last conflicts
		cout << "Resulting state: ";
		printState();	//state after swapping queen
		cout << endl;
	}
}

bool isFinalState(){ 

	count=0;
	int numCon=0;
	
	for(int col=0;col<8;col++){
		for(int row=0;row<8;row++){
			numCon=ConflictCount(row,col);
			if(numCon==0)          //checking if number of conflicts at each postion is 0
				count++;         
		}	
	}
	if(count==64)
		return true;
	else
		return false;
}


			
main(){
	srand(time(0)); 
	initialize();  //setting the state
	printState();
	search();
	bool x=isFinalState();
	cout << "Is final state?"<<x<<endl;
	int times=0;
	while(x==0 && times<10){ //continues until isFinalState is true
		search();
		times++; //added this variable so program doesn't continue indefinitely without termination. Can be removed for exection
	}
}

    
	