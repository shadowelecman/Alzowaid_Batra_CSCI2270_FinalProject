#include "HashTable.h"
#include "Graph.h"
#include <iostream>
using namespace std;

int main()
{
    HashTable h;
    Graph g;
    int ch;
    cout << "======Main Menu======" << endl;
    cout << "1. Insert movie" << endl;
    cout << "2. Delete movie" << endl;
    cout << "3. Find movie" << endl;
    cout << "4. Print all movies" << endl;
    cout << "5. Rent a movie" << endl;
    cout << "6. visit a comic con/ a panel " << endl;
    cout << "7. Quit" << endl;
    cin>>ch;
    while(ch!=7)
    {
        if(ch==1)
        {
            string title;
            int year;

            string language;
            string genres;
            string country;
            string leadActor;
            int qStock;

            cout << "Enter title:" << endl;
            cin.ignore();
            getline(cin,title);
            cin.clear();

            cout << "Enter year:" << endl;
            cin>>year;

            cout << "Enter genres:" << endl;
            cin.ignore();
            getline(cin,genres);
            cin.clear();

            cout << "Enter Country:" << endl;
            getline(cin,country);
            cin.clear();

            cout << "Enter Language:" << endl;
            getline(cin,language);
            cin.clear();

            cout << "Enter lead actor:" << endl;
            getline(cin,leadActor);
            cin.clear();

            cout << "Enter quantity available:" << endl;
            cin>>qStock;

            h.insertMovie(title,year,qStock,genres,country,language,leadActor);
        }
        else if(ch==2)
        {
            string title;
            cout << "Enter title:" << endl;
            cin.ignore();
            getline(cin,title);
            cin.clear();
            h.deleteMovie(title);
        }
        else if(ch==3)
        {
            int selection;
            cout << "Please select :" << endl;
            cout << "1. Find a movie by its title" << endl;
            cout << "2. Find a movie by the year of its release" << endl;
            cout << "3. Find a movie by its language" << endl;
            cout << "4. Find a movie by country" << endl;
            cout << "5. Find a movie by the leading actor" << endl;
            cout << "6. Find a movie by genres" << endl;
            cout << "7. Find a movie by a given range of years" << endl;
            cin>>selection;
            if(selection==1)
            {
                string title;
                cout << "Enter title:" << endl;
                cin.ignore();
                getline(cin,title);
                cin.clear();
                h.findMovie(title);
            }
            else if(selection==2)
            {
                int year;
                cout << "Enter year of release:" << endl;
                cin>>year;
                h.findMovieYear(year);
            }
             else if(selection==3)
            {
                string lang;
                cout << "Enter language:" << endl;
                cin.ignore();
                getline(cin,lang);
                cin.clear();
                h.findMovieLang(lang);
            }
             else if(selection==4)
            {
                string country;
                cout << "Enter country name:" << endl;
                cin.ignore();
                getline(cin,country);
                cin.clear();
                h.findMovieCountry(country);
            }
             else if(selection==5)
            {
                string actor;
                cout << "Enter actor name:" << endl;
                cin.ignore();
                getline(cin,actor);
                cin.clear();
                h.findMovieActor(actor);
            }
             else if(selection==6)
            {
                string g;
                cout << "Enter genres:" << endl;
                cin.ignore();
                getline(cin,g);
                cin.clear();
                h.findMovieGenres(g);
            }
            else if(selection==7)
            {
                int min;
                int max;
                cout << "Enter movies from the year:" << endl;
                cin>>min;
                cout << "Enter movies to the year:" << endl;
                cin>>max;
                h.findMovieRange(min,max);
            }
             else
            {
                cout<<"Please enter a number from the selection menu !"<<endl;
            }

        }
        else if(ch==4)
        {
            h.printTableContents();
        }
        else if( ch==5)
        {
                string title;
                cout << "Enter title:" << endl;
                cin.ignore();
                getline(cin,title);
                cin.clear();
                h.rentMovie(title);
        }
        else if( ch==6)
        {
            //print a menu if 2 choices either see available ones or visit all
            //come up with cities and dates ask for which is the one he want to go to and where he lives to use graphs!
            g.allOver();
            //g.shortestPath(start,end);
        }
        else
        {
         cout<<"Please enter a number from the selection menu !"<<endl;
        }


        cout << "======Main Menu======" << endl;
        cout << "1. Insert movie" << endl;
        cout << "2. Delete movie" << endl;
        cout << "3. Find movie" << endl;
        cout << "4. Print all movies" << endl;
        cout << "5. Rent a movie" << endl;
        cout << "6. visit a comic con" << endl;
        cout << "7. Quit" << endl;
        cin>>ch;
    }
    cout << "Goodbye!" << endl;
    return 0;
}
/*
1-add cities where they have a comic cone  then find the shortest path from ones city to the comic cone && the shortest path if one wanted to go to all comic cones
2- do you want to add a chart or a balance?
3- add a profit sum? //for every renting and every comic con ticket
4-create the graph
*/
