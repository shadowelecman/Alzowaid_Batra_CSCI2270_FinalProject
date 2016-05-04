#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <sstream>
#include<vector>
#include "HashTable.h"
#include "Graph.h"

using namespace std;
//THis method creates the graph by adding vertecies
void create(string t,Graph *g)
{
    g->addVertex(t);
}
//a menu to convert the user choice into a string
string menu(int c)
{
    string e;
    if(c==1)
        e="Boston";
    else if(c==2)
        e="Boulder";
    else if(c==3)
        e="Chicago";
    else if(c==4)
        e="Disneyland";
    else if(c==5)
        e="Miami";
    else if(c==6)
        e="New Orleans";
    else if(c==7)
        e="New York";
    else if(c==8)
        e="Portland";
    else if(c==9)
        e="San Francisco";
    else if(c==10)
        e="Seattle";
    else
     e="DNE";
    return e;

}

int main()
{
    HashTable h;
    Graph g;

    /////////////////////////////

    //creating a graph from a file
    vector<string>s;
    ifstream inFile;
    ifstream inFile2;
    string data;
    inFile.open("bestPlaces.txt");
    g.assignDistricts();
    while(getline(inFile,data))
    {
        string t=data.substr(0,data.find(","));
         if(t!="cities")
        {
            g.addVertex(t);
        }
        s.push_back(t);
    }
    inFile2.open("bestPlaces.txt");
    while(getline(inFile2,data))
    {
       string n=data.substr(0,data.find(","));
       if(n!="cities")
       {
           data=data.substr(data.find(",")+1,data.size());
           string test;

          for(int i=1;i<10;i++)
          {
                test = data.substr(0,data.find(","));
               if(test!="0"&&test!="-1")
               {
                   g.addEdge(n,s[i],atoi(test.c_str()));
                   data=data.substr(data.find(",")+1,data.size());
               }
               else
               {
                   data=data.substr(data.find(",")+1,data.size());
               }
               if(data.find(",")==-1)
               {
                    string t2=data;
                    if(t2!="0"&&t2!="-1")
                    {
                       g.addEdge(n,s[i+1],atoi(t2.c_str()));
                    }
               }
          }
       }

    }
    g.assignDistricts();
    ////////////////////////////////////////////
    //adding some movies

    h.insertMovie("Now You See Me",2013,5,"Action","USA","English","Jesse Eisenberg");
    h.insertMovie("Now You See Me",2016,2,"Action","USA","English","Jesse Eisenberg");
    h.insertMovie("Allegiant",2016,7,"Adventure","USA","English","Shailene Woodley");
    h.insertMovie("Divergent",2014,6,"Adventure","USA","English","Shailene Woodley");
    h.insertMovie("Scream",1996,10,"Horror","USA","English","Nave Campbell");
    h.insertMovie("Scream",1997,9,"Horror","USA","English","Nave Campbell");


    /////////////////////////////////////////

    //menu of choices
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

    //////////////////////////////////

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
                if(min>max)
                {
                    cout<<"The start year can't be greater than the end year,Please renter the years!"<<endl;
                    cout << "Enter movies from the year:" << endl;
                    cin>>min;
                    cout << "Enter movies to the year:" << endl;
                    cin>>max;
                }
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
            bool on=true; //this boolean will let the menu reappear if an invalid option is selected
            int c=0;
            string dummy; //this string lets you make a mistake and type in a word by accident, but not make the whole program freak out
            while(on){
                    cout<<"1- Visit Boston"<<endl;
                    cout<<"2- Visit Boulder"<<endl;
                    cout<<"3- Visit Chicago"<<endl;
                    cout<<"4- Visit Disneyland"<<endl;
                    cout<<"5- Visit Miami"<<endl;
                    cout<<"6- Visit New Orleans"<<endl;
                    cout<<"7- Visit New York"<<endl;
                    cout<<"8- Visit Portland"<<endl;
                    cout<<"9- Visit San Francisco"<<endl;
                    cout<<"10- Visit Seattle"<<endl;
                    cin>>dummy;
                    if(dummy=="1"||dummy=="2"||dummy=="3"||dummy=="4"||dummy=="5"||dummy=="6"||dummy=="7"||dummy=="8"||dummy=="9"||dummy=="10"){ //there's probably an easier way to do this but it'll do for now
                            c=stoi(dummy);
                    }
                    g.allOver();
                    if(c>=1&&c<=10)
                    {
                        string s;
                        cout << "Enter the city you're travelling from:" << endl;
                        cin.ignore();
                        getline(cin,s);
                        cin.clear();
                        g.shortestPath(s,menu(c));
                        on=false; //turning this off kills the menu
                    }
                else
                {
                cout<<"Please enter a number from the selection menu !"<<endl;
                }
            }
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
    cout<< "Goodbye!" << endl;
    return 0;
}
/*
1-add cities where they have a comic cone  then find the shortest path from ones city to the comic cone && the shortest path if one wanted to go to all comic cones
2- do you want to add a chart or a balance?
3- add a profit sum? //for every renting and every comic con ticket
4-create the graph
5- more options for the delete algorithms
*/
