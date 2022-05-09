
// this is a wordle game create By Alabaweh, using C++

#include <bits/stdc++.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <random>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <iterator>
#include <queue>
#include <time.h>
#include "Player.h"




//
void process1(std::queue<char, std::list<char>>pq, std::queue<char, std::list<char>> pq1, std::list<int>&tol, std::list<int>&res_postion, std::list<char>&mylist, std::list<char>&mylist1 ){
    int n=1;
    {
    auto it=mylist.begin();
        auto it1=mylist1.begin();

    while(!pq.empty()) {

        char m1, m2;
        m1 = pq.front();
        m2 = pq1.front();

        if (m1 == m2) {
            tol.push_back(1);
            res_postion.push_back(n);
            *it='T';
            *it1='T';
        }

        pq.pop();
        pq1.pop();
        n++, it++, it1++;
    }

    }

}



//

void process2(std::queue<char, std::list<char>>pq, std::queue<char, std::list<char>>pq1,std::list<int>&tol, std::list<int>&res, std::list<char>&p2list, std::list<char>&p1list ){
    int n=1;

    std::list<char>copy_p2list;

    for(auto cp : p2list)
        copy_p2list.push_back(cp);


     int nm=1;


    auto it3=p2list.begin();
    while(!pq.empty()){

        char m1, m2;
        m1 = pq.front();
        m2 = pq1.front();


        if(m1 == m2);

        else if(m1 != m2){

            auto it2 = std::find(p1list.begin(), p1list.end(), m1);


            if (it2 != p1list.end()){

                *it3='F';
                *it2='0';

                tol.push_back(2);
//                res.push_back(n);

            }

            else{
                auto it2 = std::find(p1list.begin(), p1list.end(), m1);

                if (it2 == p1list.end())
                    tol.push_back(3);
                *it3='*';}}

        pq.pop();
        pq1.pop();

            it3++;

        }
    copy_p2list.clear();
}


//  this function will displat the final results of the game after every input

void display_results(std::list<int>mlist, std::list<char>rec, std::list<char>toli){

    auto it_mlist= mlist.begin();
    auto it_rec=rec.begin();
    auto it_toli= toli.begin();

    for(auto it=mlist.begin();  it!=mlist.end(); it_rec++, it_toli++) {

        if(rec.empty() &&  *it_toli==3)
            std::cout << "*";
        else if (*it_toli==2);
    }

}



// this funtion will clear an queue that  is passed through it
template < class T>
void clear( std::queue<T, std::list<T>> &q )
{
    std::queue<T, std::list<T>> empty;

    // I used the swap alogrithm here to swap between the two list
    std::swap( q, empty );
}


// this  function is a supplementary to the game,it also  check if the word enter By the player
// plalidrome

bool palidrome_check(std::string word){


    std::stack<char, std::list<char>> stk;
    std::queue<char, std::list<char>> que;

    for(int m=0; m<word.size(); m++) {
        if (std::isalnum(word[m])){
            stk.push(word[m]);
            que.push(word[m]);}
    }


    while(!stk.empty()){
        char st, qu;
        st=stk.top();
        qu=que.front();

        stk.pop();
        que.pop();

        if(st!=qu)
            return false;
    }

    if(stk.empty())
        return true;
}



// this function will
template < class T>
void display_queue( std::queue<T, std::list<T>> q, std::string name_wd, int n )
{
        char m1;
        int n1=0;

    if(palidrome_check(name_wd))
        std::cout<<"\nThe word you entered is a plalidrome\n";
    while(!q.empty()){

        m1=q.front();

        q.pop();

        if (n1%n==0){
            std::cout<<std::endl;}

        if (n1%(n*2)==0 && n1!=0)
            std::cout<<std::setw(7)<<std::right<<"   ---------------------\n";


        std::cout<<std::setw(4)<<m1<<" ";

    ++n1;
    }
}



// this function will random pick a word from the map/set  below, depending on the number of words

std::string word_gen(int n){

    std::map<int, std::set<std::string>>words{{4, {"maid", "wash", "line", "lamb", "cope", "pray", "bind", "doll", "gasp", "herb",
                                                                                                                                                     "drop", "hike", "area", "silk", "shed", "know", "dorm", "lace", "tail", "hear", "seek", "snap", "wrap", "pair", "show", "node", "tool", "pile", "bear", "game"}},
                                             {5, {"creed", "bland", "virus", "other", "bring", "cheat", "grave", "color", "scene", "smell", "storm", "money", "level", "table", "fruit",
                                                  "white", "fault", "state", "taste", "entry", "sugar", "issue", "video", "crack", "wagon", "shock", "delay", "anger", "check", "blame"}},
                                             {6,{"change", "deadly", "mirror", "temple", "patent", "behead", "basket", "retire", "window", "vessel", "flawed", "border", "mobile", "flight", "island", "immune",
                                                         "slogan", "breast", "defend", "ethnic", "export", "matrix", "collar", "linger", "weapon", "jacket", "vision", "strike", "endure", "cheese"}}};




    srand(time(NULL));
    auto it = words.find(n);


    auto it1=it->second.begin();
    int random = rand() % 20;
    advance(it1, random);
    std::string nam;

    nam=*it1;

    return nam;
}


void four_words(std::string name,int mylist_ct,int counter,int  &trial_count,std::list<char> mylist, std::list<int> tocheli, std::list<int> results,
                std::stack<char, std::list<char>>stk, std::queue<char, std::list<char>>que, std::queue<char, std::list<char>>que1, std::queue<char,
        std::list<char>>queue_result){


    // thw word_gen will automatically pick a 5 letter word from the list and assign it to word
    std::string word= word_gen(4);
    std::list<char> mylist1;



    while(mylist_ct!=4 && counter!=6) {

        //  the word generate by the word_gen function is copied to a list of characters
        for (auto nm: word)
            mylist1.push_back(tolower(nm));


        std::cout << " \nEnter  a 4-letter word \n";
        std::cin >> name;


        //  this loop will check to see if the name is a 4 letter word
        // if it's not, it will loop through until the user enters a 5 letter word

        while (name.size() != 4) {

            std::cout << " \nEnter  a 4-letter word \n";
            std::cin >> name;

            std::cin.ignore();
            std::cin.clear();
        }

        // inputting the word entered by the use into the list and at the same time converting all
        // letters to lower case
        for (auto nm: name)
            mylist.push_back(tolower(nm));


        //  Queue, stack from mylist
        for (auto nm1: mylist) {
            que.push(nm1);
        }

        // copying ths store word in mylist1 to que
        for (auto nm1: mylist1) { ;
            que1.push(nm1);
        }


        // the word entered by the user is copied into name_display
        // to be displayed at the begin of the results
        std::list<char> name_display;


        for (auto nm1: mylist)
            name_display.push_back(nm1);


        //\ calling the process1 function
        process1(que, que1, tocheli, results, mylist, mylist1);

        // calling the process 2 function
        process2(que, que1, tocheli, results, mylist, mylist1);


        // defining the iterator for mylist
        auto mylist_it = mylist.begin();

        // will will count if the number of T in my list is 5 before it copied to the queue
        // this will help determine if the right word was inputted or not
        // if the total count of T is 5, then the right word was inputted, else the right word wasn't inputted
        int mylist_count = count(mylist.begin(), mylist.end(), 'T');

        mylist_ct=mylist_count;


        // the word entered by is passed into the queue_results queue
        for (auto nm1: name_display) {
            queue_result.push(nm1);
        }

        // the final results after every entry is passes into the queue_results as well
        for (auto nm1: mylist) {
            queue_result.push(nm1);
        }

        int count_1;

        auto count_it= mylist.begin();

        count_1=count(mylist.begin(), mylist.end(), 'T');


        if(count_1!=4)
            std::cout<<"\n You have "<<6-trial_count <<" trys left \n";

        trial_count++;

        // the display_queue function displays the final results after
        // every entry
        display_queue(queue_result, name,4);


        // clearing the mylist for the next entry
        mylist.clear();



        // clearing the queue qu1 and que for the next entry
        results.clear();
        tocheli.clear();

        clear(que);
        clear(que1);

        counter++;

// this will display the right word if the player doesn't  get the right word
// on the final try
        if(counter==6){
            std::cout<<"\n\n The right word was -  ";

            for(int n=0; n<word.size(); n++)
                std::cout<<std::setw(1)<<char(toupper(word[n]))<<" ";

            std::cout<<std::endl;}

        // clearing the mylist1 for the next entry
        mylist1.clear();


        name_display.clear();

    }


}


//  this is the function for the 5 word play process, all the mechanics occur in here
void five_words(std::string name,int mylist_ct,int counter,int  &trial_count,std::list<char> mylist, std::list<int> tocheli, std::list<int> results,
                std::stack<char, std::list<char>>stk, std::queue<char, std::list<char>>que, std::queue<char, std::list<char>>que1, std::queue<char,
                std::list<char>>queue_result){

// thw word_gen will automatically pick a 5 letter word from the list and assign it to word
    std::string word= word_gen(5);
    std::list<char> mylist1;



    while(mylist_ct!=5 && counter!=6) {

        //  the word generate by the word_gen function is copied to a list of characters
        for (auto nm: word)
            mylist1.push_back(tolower(nm));


        std::cout << " \nEnter  a 5-letter word \n";
        std::cin >> name;


        //  this loop will check to see if the name is a 5 letter word
        // if it's not, it will loop through until the user enters a 5 letter word

        while (name.size() != 5) {

            std::cout << " \nEnter  a 5-letter word \n";
            std::cin >> name;

            std::cin.ignore();
            std::cin.clear();
        }

        // inputting the word entered by the use into the list and at the same time converting all
        // letters to lower case
        for (auto nm: name)
            mylist.push_back(tolower(nm));


        //  Queue, stack from mylist
        for (auto nm1: mylist) {
            que.push(nm1);
        }

        // copying ths store word in mylist1 to que
        for (auto nm1: mylist1) { ;
            que1.push(nm1);
        }


        // the word entered by the user is copied into name_display
        // to be displayed at the begin of the results
        std::list<char> name_display;


        for (auto nm1: mylist)
            name_display.push_back(nm1);


        //\ calling the process1 function
        process1(que, que1, tocheli, results, mylist, mylist1);

        // calling the process 2 function
        process2(que, que1, tocheli, results, mylist, mylist1);


    // defining the iterator for mylist
        auto mylist_it = mylist.begin();

        // will count if the number of T in my list is 5 before it copied to the queue
        // this will help determine if the right word was inputted or not
        // if the total count of T is 5, then the right word was inputted, else the right word wasn't inputted
        int mylist_count = count(mylist.begin(), mylist.end(), 'T');

        mylist_ct=mylist_count;


        // the word entered by is passed into the queue_results queue
        for (auto nm1: name_display) {
            queue_result.push(nm1);
        }

        // the final results after every entry is passes into the queue_results as well
        for (auto nm1: mylist) {
            queue_result.push(nm1);
        }

        int count_1;

        auto count_it= mylist.begin();

        count_1=count(mylist.begin(), mylist.end(), 'T');


        if(count_1!=5)
            std::cout<<"\n You have "<<6-trial_count <<" trys left \n";

        trial_count++;

        // the display_queue function displays the final results after
        // every entry
        display_queue(queue_result, name,5);


        // clearing the mylist for the next entry
        mylist.clear();



        // clearing the queue qu1 and que for the next entry
        results.clear();
        tocheli.clear();

        clear(que);
        clear(que1);

        counter++;

// this will display the right word if the player doesn't  get the right word
// on the final try
        if(counter==6){
            std::cout<<"\n\n The right word was -  ";

            for(int n=0; n<word.size(); n++)
          std::cout<<std::setw(1)<<char(toupper(word[n]))<<" ";

        std::cout<<std::endl;}

        // clearing the mylist1 for the next entry
        mylist1.clear();


        name_display.clear();

    }

}



void six_words(std::string name,int mylist_ct,int counter,int  trial_count,std::list<char> mylist, std::list<int> tocheli, std::list<int> results,
                std::stack<char, std::list<char>>stk, std::queue<char, std::list<char>>que, std::queue<char, std::list<char>>que1, std::queue<char,
        std::list<char>>queue_result){

// thw word_gen will automatically pick a 6 letter word from the list and assign it to word
    std::string word= word_gen(6);
    std::list<char> mylist1;



    while(mylist_ct!=6 && counter!=6) {

        //  the word generate by the word_gen function is copied to a list of characters
        for (auto nm: word)
            mylist1.push_back(tolower(nm));


        std::cout << " \nEnter  a 6-letter word \n";
        std::cin >> name;


        //  this loop will check to see if the name is a 6 letter word
        // if it's not, it will loop through until the user enters a 6 letter word

        while (name.size() != 6) {

            std::cout << " \nEnter  a 6-letter word \n";
            std::cin >> name;

            std::cin.ignore();
            std::cin.clear();
        }

        // inputting the word entered by the use into the list and at the same time converting all
        // letters to lower case
        for (auto nm: name)
            mylist.push_back(tolower(nm));


        //  Queue, stack from mylist
        for (auto nm1: mylist) {
            que.push(nm1);
        }

        // copying ths store word in mylist1 to que
        for (auto nm1: mylist1) { ;
            que1.push(nm1);
        }


        // the word entered by the user is copied into name_display
        // to be displayed at the begin of the results
        std::list<char> name_display;


        for (auto nm1: mylist)
            name_display.push_back(nm1);


        //\ calling the process1 function
        process1(que, que1, tocheli, results, mylist, mylist1);

        // calling the process 2 function
        process2(que, que1, tocheli, results, mylist, mylist1);


        // defining the iterator for mylist
        auto mylist_it = mylist.begin();

        // will will count if the number of T in my list is 5 before it copied to the queue
        // this will help determine if the right word was inputted or not
        // if the total count of T is 6, then the right word was inputted, else the right word wasn't inputted
        int mylist_count = count(mylist.begin(), mylist.end(), 'T');

        mylist_ct=mylist_count;


        // the word entered by is passed into the queue_results queue
        for (auto nm1: name_display) {
            queue_result.push(nm1);
        }

        // the final results after every entry is passes into the queue_results as well
        for (auto nm1: mylist) {
            queue_result.push(nm1);
        }

        int count_1;

        auto count_it= mylist.begin();

        count_1=count(mylist.begin(), mylist.end(), 'T');


        if(count_1!=6)
            std::cout<<"\n You have "<<6-trial_count <<" trys left \n";

        trial_count++;

        // the display_queue function displays the final results after
        // every entry
        display_queue(queue_result, name,6);


        // clearing the mylist for the next entry
        mylist.clear();



        // clearing the queue qu1 and que for the next entry
        results.clear();
        tocheli.clear();

        clear(que);
        clear(que1);

        counter++;

// this will display the right word if the player doesn't  get the right word
// on the final try
        if(counter==6){
            std::cout<<"\n\n The right word was -  ";

            for(int n=0; n<word.size(); n++)
                std::cout<<std::setw(1)<<char(toupper(word[n]))<<" ";

            std::cout<<std::endl;}

        // clearing the mylist1 for the next entry
        mylist1.clear();


        name_display.clear();

    }

}





int welcome_option, play_option;
int count;
char quit_option1, quit_option2, quit_option;

int main(){


 std::string p_name;

std::cout<<" Please enter your name \n";
getline(std::cin, p_name);

Player player(p_name);


    std::string name;    
    
    
    

    // defining the list to be use
    std::list<char> mylist;


    std::list<int> tocheli;
    std::list<int> results;

    // defening the stack and Queue to be used in the game
    std::stack<char, std::list<char>>stk;
    std::queue<char, std::list<char>>que;
    std::queue<char, std::list<char>>que1;
    std::queue<char, std::list<char>>queue_result;


    // this will be used in the while loop to help break the loop
    // after 5 iterations
    int mylist_ct, counter =0;

    int trial_count = 1;


    std::string line;


    // first menu selection of the game



    std::cout << " Hi " << player.getname()<<" Welcome the Wordle game\n"
         << "1 = PLAY\n"
         << "2 = Rule of the game\n"
         << "3 = quit\n";
    std::cin >> welcome_option;


    // data validation
    while (!(welcome_option == 1 || welcome_option==2 || welcome_option==3))
    {
        std::cout << "please enter a valid option";
        std::cin >> welcome_option;
    }

    do{

        if (welcome_option == 1)

            {

    // Creating  a sub menu so that the player should be able to select the section the want to  start playing from
                std::cout << "Please select a Level\n"
                          << "1 = 4-letter words (Beginner)\n"
                          << "2 = 5-letter words (Intermediate)\n"
                          << "3 = 6-letter words (Advanced)\n"
                          <<"4 = quit\n";
                std::cin >> play_option;

                switch (play_option) {

                    case 1:

                    { trial_count = 1;
                        four_words(name, mylist_ct, counter, trial_count, mylist, tocheli, results,
                                  stk, que, que1, queue_result);}
                        break;

                    case 2:

                    {trial_count = 1;
                        five_words(name, mylist_ct, counter, trial_count, mylist, tocheli, results,
                                  stk, que, que1, queue_result);}
                        break;

                    case 3:

                    {trial_count = 1;
                        six_words(name, mylist_ct, counter, trial_count, mylist, tocheli, results,
                                  stk, que, que1, queue_result);}
                        break;

                    default: quit_option='n';


                }


        if(quit_option!='n'){
            std::cout << "\nDo you want to continue playing Y/N\n";
            std::cin >> quit_option;}

                quit_option=tolower(quit_option);

            while (!(quit_option == 'y'  || quit_option == 'n' )) // data validation
            {

                std::cout << "\nPlease enter Y/N if you want to continue playing\n";
                std::cin >> quit_option;

                quit_option=tolower(quit_option);
            }

            if (quit_option == 'n')
                std::cout << "Thanks for playing "<< player.getname();

        }


        else if (welcome_option==2)
        {

            if (quit_option2!='y') {

                 std::cout << "-Depending on the level of the game, the user has to enter the required number of words; if the user enters \n" 
 <<"more or less  depending on the level, they won't be able to go to the next stage of play\n"


<<"-	The user  has only 6 attempts to determine the wordle word\n"
<<"-	The player has to enter only words in the English dictionary\n"

<<"Results Display\n"
 <<"   T= The character is in the  wordle word and also in the correct position\n"
 <<"   F= The Character  is  in the wordle word but in the wrong position\n";
            }



            std::cout << "\n Do you want to continue playing - Y/N\n";
            std::cin >> quit_option2;


            quit_option2=tolower(quit_option2);

            while (!(quit_option2 =='n' || quit_option2=='y' ))
            {

                std::cout << "\nPlease input a valid option\n";
                std::cout << "Do you want to continue playing Y/N\n";
                std::cin >> quit_option2;

                quit_option2=tolower(quit_option2);
            }

            quit_option2=tolower(quit_option2);


            if (quit_option2=='y') {

                // Creating  a sub menu so that the player should be able to select the section the want to  start playing from
                std::cout << "Please select a Level\n"
                          << "1 = 4-letter words (Beginner)\n"
                          << "2 = 5-letter words (Intermediate)\n"
                          << "3 = 6-letter words (Advanced)\n"
                          <<"4 = quit\n";
                std::cin >> play_option;


                switch (play_option) {

                    case 1:

                    { trial_count = 1;
                        four_words(name, mylist_ct, counter, trial_count, mylist, tocheli, results,
                                   stk, que, que1, queue_result);}
                        break;

                    case 2:

                    {trial_count = 1;
                        five_words(name, mylist_ct, counter, trial_count, mylist, tocheli, results,
                                   stk, que, que1, queue_result);}
                        break;

                    case 3:

                    {trial_count = 1;
                        six_words(name, mylist_ct, counter, trial_count, mylist, tocheli, results,
                                  stk, que, que1, queue_result);}
                        break;

                    default: quit_option='n';


                }

            }
            else std::cout <<"Thank you\n";
        }
        else if (welcome_option == 3)
            std::cout <<"Thank you\n";

    } while (!(welcome_option == 3) && !(quit_option=='n') && !(quit_option2=='n'));




    return 0;
}