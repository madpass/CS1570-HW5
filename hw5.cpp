//Programmer: Madison Passolano     ID: 12560375
//File: hw6.cpp                     Date: 02-26-2020
//class: 1570
//Description: organizes all of the lockers willie is in charge of by 
//             keeping track of money, textbooks, occupied lockers, and 
//             locker numbers.

#include <iostream>
#include <cstdio>
#include <string>

using namespace std; 

struct locker
{
  short m_number;                //locker number 
  short m_num_txtbks;           //number of textbooks in locker 
  float m_amt_money;            //amount of money in locker
  string m_last_name;           //last name of locker owner
  bool m_locker_in_use = false; //whether or not the locker is occupied 
};

int main()
{
/*-----------declare variables-------------------------*/ 
  const short LOWEST_MENU_OPT = 1;  //lowest possible menu choice 
  const short HIGHEST_MENU_OPT = 5; //highest possible menu choice  
  const short NUM_LOCKERS = 101;    //number of lockers 
  const short MAX_LOCKER_NUM = 201; //max locker num available 
  const short MIN_LOCKER_NUM = 101; //min locker num available 
  const short MAX_MONEY = 150;      //max total amt of money before willie robs

  short occ_loc = 0;      //keeps track of how many lockers are in use
  short menu_input;       //input for menu choice  
  short input_lock_num;   //placeholder variable for calculations 
  short index_num;        //index value for the lock_arr
  float total_txtbks = 0; //total num txtbks 
  float total_money = 0;  //total amt of money in lockers
  float avg_txtbks = 0;   //avg num of txtbks in the occupied lockers 
  bool quit = false;      //menu choice that terminates program

  locker lock_arr[NUM_LOCKERS]; //array to keep track of lockers 
  //array size 0-100, 101 cells for the 101 lockers 

  //given 
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

/*--------------body of code----------------------------*/
  cout<<"\n\nWelome to the locker organizer."<<endl; 
  do
  {
    //menu
    cout<<endl;  
    cout<<"\t  Menu"<<endl; 
    cout<<"\t--------"<<endl; 
    cout<<"1. Add a locker"<<endl; 
    cout<<"2. Print contents of a locker"<<endl; 
    cout<<"3. Output all locker contents"<<endl; 
    cout<<"4. Delete a locker"<<endl; 
    cout<<"5. Quit"<<endl; 
    cout<<endl; 

    //outputting info on lockers 
    if(occ_loc != 1)
    {
      cout<<"There are "<<occ_loc<<" occupied lockers."<<endl;
      //correct grammar for one locker 
    }
    else
    {
      cout<<"There is "<<occ_loc<<" occupied locker."<<endl; 
    }
    
    cout<<"The average number of textbooks in each locker is "<<avg_txtbks<<"."<<endl; 
    cout<<"The total amout of money in the lockers is $"<<total_money<<"."<<endl; 
    cout<<endl; 


    //selecting an option for the lockers 
    do
    {
      cout<<"Pick an option: "; 
      cin>>menu_input; 
      cout<<endl; 
      if(menu_input<LOWEST_MENU_OPT || menu_input>HIGHEST_MENU_OPT)
      {
        cout<<"Invalid input: only enter numbers 1-5."<<endl; 
      }
    }while(menu_input<LOWEST_MENU_OPT || menu_input>HIGHEST_MENU_OPT);


    /*--------------switch case-----------------------------------*/
    index_num = 0; 

    switch(menu_input)
    {
      case 1: 
        //add a locker 
        do
        {
          cout<<"Enter the locker number (101 - 201): "; 
          cin>>input_lock_num; 
          cout<<endl; 
          if(input_lock_num<MIN_LOCKER_NUM || input_lock_num>MAX_LOCKER_NUM)
          {
            cout<<"Invalid input: only input lockers numbers from 101-201."<<endl; 
          }
        }while(input_lock_num<MIN_LOCKER_NUM || input_lock_num>MAX_LOCKER_NUM); 
        //do while for an input out of range 

        index_num = (input_lock_num-100) - 1; 
        //input_lock_num minus 101 gives you the index of the array  
        lock_arr[index_num].m_number = input_lock_num; 
        //this saves the input lock num to the locker array value 

        if(lock_arr[index_num].m_locker_in_use == true)  //if the locker is being used 
        {
          cout<<"Locker in use... Choose another locker."<<endl; 
        }
        else  //if the locker is available 
        {
          cout<<"Enter the name of the student: "; 
          cin>>lock_arr[index_num].m_last_name; 
          cout<<endl; 

          cout<<"Enter the number of textbooks in the locker: "; 
          cin>>lock_arr[index_num].m_num_txtbks; 
          total_txtbks += lock_arr[index_num].m_num_txtbks;  //adds to the total num textbooks 
          cout<<endl; 

          cout<<"Enter the amout of money in the locker: "; 
          cin>>lock_arr[index_num].m_amt_money; 
          cout<<endl; 
          total_money += lock_arr[index_num].m_amt_money;   //adds to the total amt of money 

          lock_arr[index_num].m_locker_in_use = true; 
          occ_loc++; //number of lockers increases as one is added 
        }
        break; 

      

      case 2: 
        //output specific info on a locker 
        if(occ_loc == 0)  //if there are no open lockers 
        {
          cout<<"There are no occupied lockers... Pick another option."<<endl<<endl; 
        }
        else  //if there are open lockers 
        { 
          do
          {
            cout<<"Enter a locker number: "; 
            cin>>input_lock_num; 
            cout<<endl; 
            if(input_lock_num<MIN_LOCKER_NUM || input_lock_num>MAX_LOCKER_NUM)
            {
              cout<<"Invalid input: only input locker numbers from 101-201."<<endl; 
            }
          }while(input_lock_num<MIN_LOCKER_NUM || input_lock_num>MAX_LOCKER_NUM); 

          index_num = (input_lock_num-100) - 1; 

          if(lock_arr[index_num].m_locker_in_use == false)
          {
            cout<<"This locker is not occupied."<<endl; 
          }
          else 
          {
            cout<<"\t Lockers"<<endl; 
            cout<<"\t---------"<<endl; 
            cout<<lock_arr[index_num].m_number 
                <<"\t\t"<< lock_arr[index_num].m_last_name 
                <<"\t\t"<< lock_arr[index_num].m_num_txtbks;  
            if(lock_arr[index_num].m_num_txtbks == 1)
            {
              cout<<"text\t\t$"; 
            }
            else
            {
              cout<<"texts\t\t$"; 
            }
            cout<<lock_arr[index_num].m_amt_money<<endl;
            cout<<endl; 
          }
        }
        break; 



      case 3: 
        //complete list of all lockers and their contents 
        if(occ_loc == 0)
        {
          cout<<"There are no occupied lockers... Pick another option."<<endl<<endl; 
        }
        else
        {
          cout<<"\t Lockers"<<endl; 
          cout<<"\t---------"<<endl;
          for(int i=0; i<NUM_LOCKERS; i++)
          {
            if(lock_arr[i].m_locker_in_use == true)
            { 
              cout<<lock_arr[i].m_number 
                  <<"\t\t"<<lock_arr[i].m_last_name 
                  <<"\t\t"<<lock_arr[i].m_num_txtbks;  
              if(lock_arr[i].m_num_txtbks == 1)
            {
              cout<<"text\t\t$"; 
            }
            else
            {
              cout<<"texts\t\t$"; 
            }
            cout<<lock_arr[i].m_amt_money<<endl;
            }
          }
        }
        break; 



      case 4: 
        //delete locker, reduce tracked values
        if(occ_loc == 0)
        {
          cout<<"There are no occupied lockers... Pick another option."<<endl<<endl; 
        }
        else
        {
          do
          {
            cout<<"Enter a locker number: "; 
            cin>>input_lock_num; 
            cout<<endl; 
            if(input_lock_num<MIN_LOCKER_NUM || input_lock_num>MAX_LOCKER_NUM)
            {
              cout<<"Invalid input: only input locker numbers from 101-201."<<endl; 
            }
          }while(input_lock_num<MIN_LOCKER_NUM || input_lock_num>MAX_LOCKER_NUM); 

          index_num = (input_lock_num-100) - 1;

          if(lock_arr[index_num].m_locker_in_use == true)
          {
            index_num = (input_lock_num-100) - 1; 
            lock_arr[index_num].m_locker_in_use = false; 
            total_money -= lock_arr[index_num].m_amt_money; 
            total_txtbks -= lock_arr[index_num].m_num_txtbks; 
            occ_loc--; 
            cout<<"Locker "<<input_lock_num<<" has been emptied"<<endl; 
          }

          else
          {
            cout<<"Locker not in use."<<endl; 
          }
        }
        break; 



      case 5: 
        //quitting the program 
        cout<<"Ending the locker organizer..."<<endl<<endl; 
        quit = true; 
        break; 


    }//end of switch 

    //if amt of money goes over $150, willie steaks it 
    if(total_money >= MAX_MONEY)
    {
      total_money = 0; 
      cout<<"----------------------------------"<<endl; 
      cout<<"Willie robbed all the money! Nice!"<<endl; 
      cout<<"----------------------------------"<<endl<<endl; 
      for(int i=0; i<NUM_LOCKERS; i++)
      {
        lock_arr[i].m_amt_money = 0; 
      }
    }

    //computing average textbook value 
    avg_txtbks = total_txtbks/static_cast<float>(occ_loc); 



  }while(quit != true); 

  return 0; 
}















