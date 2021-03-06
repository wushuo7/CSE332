// Lab0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "card1.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<exception>
using namespace std;

card::card()
	:suits(suit::c), rank(card_rank::two)
{}
card::card(suit suit_name, card_rank rank_name)
	: suits(suit_name), rank(rank_name)
{}

hand::hand(card a, card b, card c, card d, card e) {
	a_ = a;
	b_ = b;
	c_ = c;
	d_ = d;
	e_ = e;

}

hand::hand() {
	a_ = card();
	b_ = card();
	c_ = card();
	d_ = card();
	e_ = card();
}


int usage() {
	cout << "Lab0 is a read card from a file and prient all the card in this file out" << endl;
	cout << "you need to set the input as this form : Lab0.exe card_file.txt" << endl;
	cout << "run the lab0.exe and set the care_file.txt as it input file" << endl;

	return 0;
}




bool card::operator<(const card &another_card) {

	if (rank < another_card.rank) {
		return true;
	}
	else if (rank > another_card.rank) {
		return false;
	}
	else {
		if (suits < another_card.suits) {
			return true;
		}
		else {
			return false;
		}
	}
};

bool hand::operator<(const hand &another_hand) {
	vector<card> that;
	that.push_back(a_);
	that.push_back(b_);
	that.push_back(c_);
	that.push_back(d_);
	that.push_back(e_);

	int a1 = check_rank_new(that);
	vector<card> another;
	
	another.push_back(another_hand.a_);
	another.push_back(another_hand.b_);
	another.push_back(another_hand.c_);
	another.push_back(another_hand.d_);
	another.push_back(another_hand.e_);
	int a2 = check_rank_new(another);
	if (a1< a2) {
		return true;
	}
	else if(a1 >a2){
		return false;
	}
	else {
		
		if (a1 == a2&&a2 == 8) {
			if (a_.rank < another_hand.a_.rank) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (a1 ==a2&& a2 == 7) {
			if (c_.rank < another_hand.c_.rank) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (a1 == a2&& a2 == 6) {
			if (c_.rank < another_hand.c_.rank) {
				return true;
			}
			else if (c_.rank > another_hand.c_.rank){
				return false;
			}
			else {
				if (a_.rank == c_.rank && another_hand.a_.rank == another_hand.c_.rank) {
					if (d_.rank < another_hand.d_.rank) {
						return true;
					}
					else {
						return false;
					}
				}
				if (a_.rank == c_.rank && another_hand.a_.rank != another_hand.c_.rank) {
					if (d_.rank < another_hand.a_.rank) {
						return true;
					}
					else {
						return false;
					}
				}
				if (a_.rank != c_.rank && another_hand.a_.rank != another_hand.c_.rank) {
					if (a_.rank < another_hand.a_.rank) {
						return true;
					}
					else {
						return false;
					}
				}
				if (a_.rank != c_.rank && another_hand.a_.rank == another_hand.c_.rank) {
					if (a_.rank < another_hand.d_.rank) {
						return true;
					}
					else{
						return false;
					}
				}
			}
		}
		else if (a1 == a2&&a2 == 5) {
			if (e_.rank < another_hand.e_.rank) {
				
				return true;
			}
			else if (e_.rank > another_hand.e_.rank){
				return false;
			}
			else {
				if (d_.rank < another_hand.d_.rank) {
					return true;
				}
				else if (d_.rank > another_hand.d_.rank) {
					return false;
				}
				else {
					if (c_.rank < another_hand.c_.rank) {
						return true;
					}
					else if(c_.rank > another_hand.c_.rank){
						return false;
					}
					else {
						if (b_.rank < another_hand.b_.rank) {
							return true;
						}
						else if (b_.rank > another_hand.b_.rank) {
							return false;
						}
						else {
							if (a_.rank < another_hand.a_.rank) {
								return true;
							}
							else {
								return false;
							}

						}

					}
				}
			}
		}
		else if (a1 == a2&& a2 == 4) {
			if (a_.rank < another_hand.a_.rank) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (a1 == a2&&a2 == 3) {
			if (c_.rank<another_hand.c_.rank) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (a1 == a2&& a2 == 2) {
			if (e_.rank<another_hand.e_.rank) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (a1 == a2&&a2 == 1) {
			if (e_.rank<another_hand.e_.rank) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (a1 == a2&&a2 == 0) {
			if (e_.rank<another_hand.e_.rank) {
				return true;
			}
			else {
				return false;
			}
		}
		
		
	}

};



card_rank change_to_rank(int value) {
	switch (value)
	{
	case 2: 
		return two;
		break;
	case 3: 
		return three;
		break;
	case 4: 
		return four;
		break;
	case 5: 
		return five;
		break;
	case 6: 
		return six;
		break;
	case 7: 
		return seven;
		break;
	case 8:
		return eight;
		break;
	case 9: 
		return nine;
		break;
	case 10: 
		return ten;
		break;
	case 11: 
		return jack;
		break;
	case 12: 
		return queen;
		break;
	case 13:
		return king;
		break;
	case 14:
		return ace;
		break;
	default:
		return nan1;
		break;
	}

}

suit change_to_suit(char suit) {
	switch (suit)
	{
	case 'c': 
		return c;
		break;
	case 'C':
		return c;
		break;
	case 'd':
		return d;
		break;
	case 'D':
		return d;
		break;
	case 'h':
		return h;
		break;
	case 'H':
		return h;
		break;
	case 's':
		return s;
		break;
	case 'S':
		return s;
		break;
	default:
		return nan2;
		break;
	}
}

string string_of_card_suit(suit suit) {
	if (suit == 1) {
		return "Clubs";
	}
	else if (suit == 2) {
		return "Diamonds";
	}
	else if (suit == 3) {
		return "Hearts";
	}
	else if (suit == 4) {
		return "Spades";
	}
	else {
		return "invalid typle";
	}
}

string string_of_card_rank(card_rank rank) {
	if (rank == 2) {
		return "two";
	}
	else if (rank == 3) {
		return "three";
	}
	else if (rank == 4) {
		return "four";
	}
	else if (rank == 5) {
		return "five";
	}
	else if (rank == 6) {
		return "six";
	}
	else if (rank == 7) {
		return "seven";
	}
	else if (rank == 8) {
		return "eight";
	}
	else if (rank == 9) {
		return "nine";
	}
	else if (rank == 10) {
		return "ten";
	}
	else if (rank == 11) {
		return "jack";
	}
	else if (rank == 12) {
		return "queen";
	}
	else if (rank == 13) {
		return "king";
	}
	else if (rank == 14) {
		return "ace";
	}
	else {
		return "can't read this card";
	}
}

//print all cards
int print_all_cards(const vector<card> & deck) {
	if (deck.size() == 0) {
		cout << "no card inside in the deck" << endl;
		return fail;
	}
	for (size_t i = 0; i != deck.size(); ++i) {
		int number = static_cast<int>(i);
		if (number%5 ==0) {
			cout << "" << endl;
			cout << "!!!!A new poker hand starts here: " << endl;
		}
		
		card x = deck[number];
		cout << "This card infomation: rank is :" << x.rank ;
		cout << " and suit is :" << string_of_card_suit(x.suits) << endl;
	}
	return success;
}

int print_all_sorted_cards(const vector<card> & deck) {
	if (deck.size() == 0) {
		cout << "no card inside in the deck" << endl;
		return fail;
	}
	vector<card> sorted = deck;
	sort(sorted.begin(), sorted.end());
	for (size_t i = 0; i != sorted.size(); ++i) {
		int number1 = static_cast<int>(i);
		card sort_card = sorted[number1];
		cout << "[" << sort_card.rank <<"]";
		cout << "[" << string_of_card_suit(sort_card.suits) <<"]"<< " ";

	}
	
	return success;

}

// change the deck into sub-vector of size 5 and then sort them by order
int sorted_all_divide_5(const vector<card> & deck) {
	int size = deck.size();
	try {
		if (size % 5 != 0) {
			cout << "the input vector for sorted is invalid vector" << endl;
			throw "invalid vector";
		}
		// temp vecotr to hold the five card
		vector<card> sub_set;
		int number = size/5;
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < 5; j++) {
				sub_set.push_back(deck[j+i*5]);
			}
			
			if (sub_set.size() != 5) {
				throw "invalid size of sub vector";
			}
			vector<card> sorted = sub_set;
			sort(sorted.begin(), sorted.end());


			cout << "A new SORTED Poker Hand Starts here: " << endl;
			for (size_t i = 0; i != sorted.size();i++) {
				int answer = static_cast<int>(i);
				cout << "This card information: ";
				cout << " Rank: " << sorted[answer].rank;
				cout << " Suit is : " << string_of_card_suit(sorted[answer].suits) << endl;
				
			}
			cout << "//" ;
			check_rank(sorted);
			//cout << check_rank(sorted) << endl;


			cout << "" << endl;
			
			
			//clear the subset
			sub_set.clear();

		}
	
	}
	catch (const char* message) {
		return invalid_vector;
	}
	return success;
}


int sorted_all_divide_5_extension(const vector<card> & deck, vector<hand> check) {
	int size = deck.size();
	
	//vector <hand> dsja= deck;
	try {
		if (size % 5 != 0) {
			cout << "the input vector for sorted is invalid vector" << endl;
			throw "invalid vector";
		}
		// temp vecotr to hold the five card
		vector<card> sub_set;
		int number = size / 5;
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < 5; j++) {
				sub_set.push_back(deck[j + i * 5]);
			}

			if (sub_set.size() != 5) {
				throw "invalid size of sub vector";
			}
			vector<card> sorted = sub_set;
			sort(sorted.begin(),sorted.end());
			hand inter(sorted[0],sorted[1],sorted[2], sorted[3], sorted[4]);
			
			check.push_back(inter);
			
			sub_set.clear();

		}

	}
	catch (const char* message) {
		return invalid_vector;
	}
	
	
	sorted_hand_and_print_it(check);
	return success;
}

int sorted_hand_and_print_it(const vector<hand> & test) {
	vector<hand> sorted = test;
	sort(sorted.begin(), sorted.end());
	
	for (size_t i = 0; i != sorted.size(); ++i) {
		int index = static_cast<int>(i);
		cout << "" << endl;
		if (index ==8) {
			cout << " !!!!!!!!YOU GOT StraightFlush !!!!!" << endl;
		}
		if (index == 7) {
			cout << " !!!!!!!!YOU GOT FourOfAKind !!!!!" << endl;
		}
		if (index == 6) {
			cout << " !!!!!!!!YOU GOT FullHouse !!!!!" << endl;
		}
		if (index == 5) {
			cout << " !!!!!!!!YOU GOT Flush !!!!!" << endl;
		}
		if (index == 4) {
			cout << " !!!!!!!!YOU GOT Straight !!!!!" << endl;
		}
		if (index == 3) {
			cout << " !!!!!!!!YOU GOT ThreeOfAKind !!!!!" << endl;
		}
		if (index == 2) {
			cout << " !!!!!!!!YOU GOT TwoPairs !!!!!" << endl;
		}
		if (index == 1) {
			cout << " !!!!!!!!YOU GOT OnePair !!!!!" << endl;
		}
		if (index == 0) {
			cout << " !!!!!!!!YOU GOT NO RAnk, please ask professor for the reason !!!!!" << endl;
		}
		cout << " The " << index << " TH hand is here : It contains the following cards: " << endl;
		cout << "This card information is here: Card's rank is : " << sorted[i].a_.rank;
		cout << " and Card's suit is : " << sorted[i].a_.suits << endl;
		cout << "This card information is here: Card's rank is : " << sorted[i].b_.rank;
		cout << " and Card's suit is : " << sorted[i].b_.suits << endl;
		cout << "This card information is here: Card's rank is : " << sorted[i].c_.rank;
		cout << " and Card's suit is : " << sorted[i].c_.suits << endl;
		cout << "This card information is here: Card's rank is : " << sorted[i].d_.rank;
		cout << " and Card's suit is : " << sorted[i].d_.suits << endl;
		cout << "This card information is here: Card's rank is : " << sorted[i].e_.rank;
		cout << " and Card's suit is : " << sorted[i].e_.suits << endl;
		cout << "" << endl;
		cout << "" << endl;


	
	}
	return success;

}

bool IsStraightFlush(const vector<card> & case1) {
	if (case1.size()!=5) {
		return false;
	}
	int value = case1[0].rank;
	for (size_t i = 1; i < 5; i++) {
		if (case1[i].suits != case1[i - 1].suits) {
			return false;
		}
		if (case1[i].rank != value+1) {
			return false;
		}
		value=value+1;
	}
	return true;
}

bool  IsFourOfAKind(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	//will be true if a0=a1=a2=a3and !=a4
	if (case1[0].rank== case1[1].rank&& case1[1].rank== case1[2].rank && case1[2].rank== case1[3].rank&&case1[3].rank!= case1[4].rank) {
		return true;
	}
	//will be true if a1=a2=a3=a4 != a0
	if (case1[0].rank != case1[1].rank&& case1[1].rank == case1[2].rank && case1[2].rank == case1[3].rank&&case1[3].rank == case1[4].rank) {
		return true;
	}
	return false;
}

bool  IsFullHouse(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	//will be true if a0=a1=a2=a3and !=a4
	if (case1[0].rank == case1[1].rank&& case1[1].rank == case1[2].rank && case1[3].rank == case1[4].rank&&case1[0].rank != case1[4].rank) {
		return true;
	}
	//will be true if a1=a2=a3=a4 != a0
	if (case1[0].rank == case1[1].rank&& case1[2].rank == case1[3].rank && case1[3].rank == case1[4].rank&&case1[0].rank != case1[4].rank) {
		return true;
	}
	return false;

}

bool  IsFlush(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	if (case1[0].suits==case1[1].suits&&case1[1].suits == case1[2].suits&&case1[2].suits == case1[3].suits&&case1[3].suits == case1[4].suits) {
		return true;
	}
	return false;
}

bool  IsStraight(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	if (case1[0].rank == case1[1].rank-1&& case1[1].rank == case1[2].rank - 1 &&case1[2].rank == case1[3].rank-1 && case1[3].rank == case1[4].rank-1) {
		return true;
	}
	return false;
}

bool  IsThreeOfAKind(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	if (case1[0].rank == case1[1].rank && case1[1].rank == case1[2].rank ) {
		return true;
	}
	if (case1[1].rank == case1[2].rank && case1[2].rank == case1[3].rank) {
		return true;
	}
	if (case1[2].rank == case1[3].rank && case1[3].rank == case1[4].rank) {
		return true;
	}
	
	return false;
}

bool  IsTwoPairs(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}

	if (case1[0].rank == case1[1].rank && case1[2].rank == case1[3].rank) {
		return true;
	}
	else if (case1[0].rank == case1[1].rank && case1[3].rank == case1[4].rank) {
		return true;
	}
	else if (case1[1].rank == case1[2].rank && case1[3].rank == case1[4].rank) {
		return true;
	}

	return false;
}


bool  IsOnePair(const vector<card> & case1) {
	if (case1.size() != 5) {
		return false;
	}
	if (case1[0].rank == case1[1].rank ) {
		return true;
	}
	if (case1[1].rank == case1[2].rank ) {
		return true;
	}
	if (case1[2].rank == case1[3].rank) {
		return true;
	}
	if ( case1[3].rank == case1[4].rank) {
		return true;
	}

	return false;
}

int check_rank(const vector<card> & deck) {
	//cout << "nice: "<< no_rank << endl;
	if (IsStraightFlush(deck)) {
		cout << "nice hand, you will win the game first place since you got straight flush" << endl;
		cout << "Straight Flush " << endl;
		cout << "" << endl;

		return StraightFlush;
	}
	else if (IsFourOfAKind(deck)) {
		cout << "nice hand, you will got four of a kind" << endl;
		cout << "Four a Kind " << endl;
		cout << "" << endl;

		return FourOfAKind;
	}
	else if (IsFullHouse(deck)) {
		cout << "good luck, you got full house" << endl;
		cout << "Full House" << endl;
		cout << "" << endl;

		return FullHouse;
	}
	else if (IsFlush(deck)) {
		cout << "nice job, you got flush" << endl;
		cout << "Flush " << endl;
		cout << "" << endl;

		return Flush;
	}
	else if (IsStraight(deck)) {
		cout << "pretty cool, you got Straight" << endl;
		cout << "Straight " << endl;
		cout << "" << endl;

		return Straight;
	}
	else if (IsThreeOfAKind(deck)) {
		cout << "Hey, you got three a kind card" << endl;
		cout << "Three A Kind " << endl;
		cout << "" << endl;

		return ThreeOfAKind;
	}
	else if (IsTwoPairs(deck)) {
		cout << "not bad, you got two pairs in hand" << endl;
		cout << "Two Pairs " << endl;
		cout << "" << endl;

		return TwoPairs;
	}
	else if (IsOnePair(deck)) {
		cout << "that's good , you still have some chance to win" << endl;
		cout << "One Pair " << endl;
		cout << "" << endl;

		return OnePair;
	}
	cout << "sorry  , you got nothing this round" << endl;
	cout << "No Rank " << endl;
	cout << "" << endl;
	return No_Rank;
}


int check_rank_new(const vector<card> & deck) {
	//cout << "nice: "<< no_rank << endl;
	if (IsStraightFlush(deck)) {
	

		return StraightFlush;
	}
	else if (IsFourOfAKind(deck)) {
		

		return FourOfAKind;
	}
	else if (IsFullHouse(deck)) {
		

		return FullHouse;
	}
	else if (IsFlush(deck)) {
		

		return Flush;
	}
	else if (IsStraight(deck)) {
		
		return Straight;
	}
	else if (IsThreeOfAKind(deck)) {
		
		return ThreeOfAKind;
	}
	else if (IsTwoPairs(deck)) {
		return TwoPairs;
	}
	else if (IsOnePair(deck)) {
		return OnePair;
	}

	return No_Rank;
}

int parse_card(vector<card> &deck, char * filename) {
	vector<card> temp_deck;
	string line;
	string report;
	int lineNumber = 0;
	string new_line;
	ifstream ifs;
	ifs.open(filename);

	if (!ifs.is_open())
	{
		cout << "the file: " << filename << " can't be opened or can't be found for reading" << endl;
		return wrong_name;
	}
	int i = 0;
	try {
		while (!ifs.eof())
		{
			
			stringstream middle;
		
			getline(ifs,line);

			if ( line.empty() || line.size() <=15) {
				continue;
			}
			middle<< line;
			
			

			int value;
			char suit;

			while (middle >> new_line) {
				//cout << "new line" << new_line << endl;

				if (new_line=="//"|| new_line ==""|| new_line == " "|| new_line == "  "|| new_line == "   ") {
					break;
				}
				try {
					if (new_line.length() == 1) {
						throw "Can't read this card because it's only one character ";
					}

					else if (new_line.length() == 3&& (new_line[2] =='s'|| new_line[2]=='S'|| new_line[2]=='h'|| new_line[2]=='H'|| new_line[2]=='D'|| new_line[2]=='d'|| new_line[2]=='C'|| new_line[2]=='c')) {
						int v1 = new_line[0] - '0';
						int v2 = new_line[1] - '0';
						value = v1 * 10 + v2;
						if (value == 10) {
							suit = new_line[2];
						}
						else {
							throw "Can't read this card because it three char and isn't value 10";
						}
					}
					else if (new_line.length() == 2 &&(new_line[1] == 's' || new_line[1] == 'S' || new_line[1] == 'h' || new_line[1] == 'H' || new_line[1] == 'D' || new_line[1] == 'd' || new_line[1] == 'C' || new_line[1] == 'c')) {
						if (new_line[0] == '2') {
							value = 2;
							suit = new_line[1];
						}
						else if (new_line[0] == '3') {
							value = 3;
							suit = new_line[1];
						}
						else if (new_line[0] == '4') {
							value = 4;
							suit = new_line[1];
						}
						else if (new_line[0] == '5') {
							value = 5;
							suit = new_line[1];
							
						}
						else if (new_line[0] == '6') {
							value = 6;
							suit = new_line[1];
						}
						else if (new_line[0] == '7') {
							value = 7;
							suit = new_line[1];
						}
						else if (new_line[0] == '8') {
							value = 8;
							suit = new_line[1];
						}
						else if (new_line[0] == '9') {
							value = 9;
							suit = new_line[1];
						}
						else if (new_line[0] == 'j' || new_line[0] == 'J') {
							value = 11;
							suit = new_line[1];
						}
						else if (new_line[0] == 'q' || new_line[0] == 'Q') {
							value = 12;
							suit = new_line[1];
						}
						else if (new_line[0] == 'k' || new_line[0] == 'K') {
							value = 13;
							suit = new_line[1];
						}
						else if (new_line[0] == 'a' || new_line[0] == 'A') {
							value = 14;
							suit = new_line[1];
						}
						else {

							throw "Invalid card 1";
						}
					}
					else {
						throw "InValid card ";
					}


					card c = { change_to_suit(suit), change_to_rank(value) };
					if (c.rank != -1 && c.suits != -1) {
						temp_deck.push_back(c);
					}
					
				}
				catch (const char* message) {
					cout << "line " << lineNumber+1 << " contains some invalid cards as following : Please check" << endl;
					cout << message << endl;
					cout << "" << endl;
				}
			}
			
				   lineNumber++;
			if (temp_deck.size() == 5) {
				
				
				 
				//cout << "line : " << lineNumber << endl;
				for (int i = 0; i != temp_deck.size(); i++) {
					deck.push_back(temp_deck[i]);
					//cout << deck[i].rank << endl;
					//cout << deck[i].suits << endl;
				}
				
				cout << "Line number: " << lineNumber;
				cout << " contains five valid cards"  << endl;
				
			}
			else {
				if (temp_deck.size()<5) {
					cout << "" << endl;
					cout << "Line number: " << lineNumber ;
					cout << " contains too few cards" << " and the requeired number is 5" << endl;
					

				}
				else {
					cout << "" << endl;
					cout << "Line number: " << lineNumber ;
					cout << " contains too many cards" << " and the requeired number is 5" << endl;

				}
			}

			temp_deck.clear();
			
		}
	}
	catch (const int* i) {
		cout << "there is a big problem  : "<< i << endl;
		cout << "I don't like it" << endl;
		
		return big_problem;
	}

	return success;

}





