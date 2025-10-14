#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void game(int randnum, int player){
	int guess;
	cout<<"player "<<player<<": enter guess?";
	cin>>guess;
	if(guess==randnum){
		cout<<"player "<<player<<" guessed the correct number";
		return;
	}
	else{
		cout<<(guess<randnum?"too low\n":"too high\n");
		player=(player==1?2:1);
		game(randnum,player);
	}
}
int main(){
	srand(time(0));
	int randnum=rand()%100+1;
	game(randnum,1);
}