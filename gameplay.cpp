#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
class play
{
	public:
		int score;
		char result;
		play *next;
};
class game
{
	public:
		play *start;
		game *begin;
		char name[15];
		game()
		{
			begin=NULL;
			start=NULL;
		}
		void clear();
		void createplayer();
		void gameplay();
		void display();
		void help();
		
};
void game::clear()
{
	
	if(start==NULL)
	{
		return;
	}
	else
	{
		play *current,*delnode;
		current=start;
		while(current!=NULL)
		{
			delnode=current;
			delete delnode;
			current=current->next;
		}
		start=NULL;
	}
}
void game::createplayer()
{
	game* g=new game;
	begin=g;
	game access;
	access.clear();
	
	char name[20];
	cout<<endl<<"Enter the Name to the Player : "<<endl;
	cin>>name;
	cout<<endl<<"Welcome to the game "<<name<<endl;
	strcpy(begin->name,name);
	cout<<endl;
}
void game::gameplay()
{
	play *newplay= new play;
	play *current= new play;
	current=start;
	int i;
	int prize;
	int guess,j;
	i=int(rand()%100+1);
	if(begin==NULL)
	{
		cout<<endl<<"! You need to set up a player before playing the game !"<<endl;
		cout<<endl;
		return;
	}
	cout<<endl<<"Guess a number between 1-100 "<<endl;
	for(j=0;j<3;j++)
	{
		
		cin>>guess;
		
		if(guess>100)
		{
			cout<<endl<<"Sorry,only numbers between 1-100 are valid"<<endl;
				
		}
		else if(guess<i && j<3)
		{
			cout<<endl<<"You need to go a little higher"<<endl;
			if((i-guess)<=10)
			{
				cout<<"!!You are very close"<<endl;
			}
		}
		else if(guess>i && j<3)
		{
			cout<<endl<<"You need to go a little lower"<<endl;
			if((guess-i)<=10)
			{
				cout<<"!!You are very close"<<endl;
			}
		}
		else if(guess==i)
		{
			break;
		}
	}
	cout<<endl<<"Your final guess is : "<<guess<<endl;
	cout<<endl<<"The number was :"<<i<<endl;
	if(guess==i)
	{
			cout<<endl<<"The number was: "<<i<<endl;
			cout<<endl<<"Your guess is :"<<guess<<endl;
			cout<<"Congratulations!! You Won  $10"<<endl;
			newplay->score=10;
			newplay->result='W';
			if(start==NULL)
			{
				newplay->next=NULL;
				start=newplay;
				return;
			}
			else
			{
				while(current->next!=NULL)
				{
					current=current->next;
				}
				current->next=newplay;
				newplay->next=NULL;
				return;
			}
	}
	if((guess-i)>0 && (guess-i)<=5)
	{
			cout<<"Congratulations you won a consolation prize of $5"<<endl;
			cout<<endl;
			if(start==NULL)
				{
					newplay->result='W';
					newplay->score=5;
					newplay->next=NULL;
					start=newplay;
					return;
				}
			else
			{
				while(current->next!=NULL)
				{
					current=current->next;
				}
				newplay->score=5;
				newplay->result='W';
				current->next=newplay;
				newplay->next=NULL;
				return;
			}
		
	}
	else if((guess-i)<0 && (i-guess)<=5)
	{
		
			cout<<"Congratulations you won a consolation prize of $5"<<endl;
			cout<<endl;
			if(start==NULL)
				{
					newplay->result='W';
					newplay->score=5;
					newplay->next=NULL;
					start=newplay;
					return;
				}
			else
			{
				while(current->next!=NULL)
				{
					current=current->next;
				}
				newplay->score=5;
				newplay->result='W';
				current->next=newplay;
				newplay->next=NULL;
				return;
			}
		
	}
	else
	{
		cout<<"Sorry better luck next time"<<endl;
		cout<<endl;
		if(start==NULL)
			{
				newplay->score=-1;
				newplay->result='L';
				newplay->next=NULL;
				start=newplay;
				return;
			}
		else
			{
				while(current->next!=NULL)
				{
					current=current->next;
				}
				newplay->score=-1;
				newplay->result='L';
				current->next=newplay;
				newplay->next=NULL;
				return;
			}
	}
	
}
void game::display()
{
	play *travel=new play;
	int w=0,n=0;
	int money=0;
	int percent;
	travel=start;
	cout<<endl<<"Player Name: "<<begin->name<<endl;
	cout<<endl;
	if(start==NULL)
	{
		cout<<"! No statistics to display !"<<endl;
		cout<<"! NO games played !"<<endl;
		cout<<endl;
		return;
	}
	while(travel!=NULL)
	{
			
		if(travel->result=='W')
		{
			w++;
			money=money+travel->score;
			n++;
			travel=travel->next;
		}
		else
		{
			money=money+travel->score;
			n++;
			travel=travel->next;
		}
	}
	
	percent=(w*100)/n;
	cout<<"The statistics are as follows: "<<endl;
	cout<<"The player has "<<w<<" wins and "<<n-w<<" losses"<<endl;
	cout<<"Winning percentage is: "<<percent<<"%"<<endl;
	cout<<"Total winnings are : $"<<money<<endl;
	cout<<endl;
}
void game::help()
{
	cout<<endl<<"Guide to the Game"<<endl;
	cout<<endl<<"1. This is a guessing game wherein the player needs to guess a number between 1-100"<<endl;
	cout<<"2. The player gets three chances in which he needs to guess the number based on then clues"<<endl;
	cout<<"3. The computer provides the clues after the first guess "<<endl;
	cout<<"4. At the end of three chances the number is displayed and the last number guessed is evaluated"<<endl;
	cout<<"5. A perfect guess yields a $10 prize and close enough guesses yield $5 prize whereas a far guess"<<endl;
	cout<<"   yields penalty of $1"<<endl;
	cout<<endl<<"Thank you"<<endl;
}
int main()
{
	char ch;
	game mygame;
	while(1)
	{
		cout<<"Welcome to the guessing game"<<endl;
		cout<<"1. Change or set up player"<<endl;
		cout<<"2. Play a round"<<endl;
		cout<<"3. Display player statistics"<<endl;
		cout<<"4. Game instructions"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<endl<<"Choose an option"<<endl;
		cin>>ch;
		switch(ch)
		{
			case '1':
				{
					mygame.createplayer();
				}break;
				
			case '2':
				{
					mygame.gameplay();	
				}break;
				
			case '3':
				{
					mygame.display();
				}break;
				
			case '4':
				{
					mygame.help();
				}break;
				
			case '5':
				{
					cout<<endl<<"! Thank You for playing !"<<endl;
					exit(0);
				}break;
				
			default:
				{
					cout<<endl<<"Invalid choice try again"<<endl;
				}break;
		}
	}
	return(0);
}
