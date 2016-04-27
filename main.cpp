#include "HashTable.h"
#include "Graph.h"
#include <iostream>
using namespace std;

void create(string t,Graph *g)
{
    g->addVertex(t);
}
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
        vector<string>s;
    ifstream inFile;
    ifstream inFile2;
    string data;
    inFile.open("bestPlaces.txt");
    while(getline(inFile,data))
    {
        string t=data.substr(0,data.find(","));
         if(t!="cities")
        {
            g.addVertex(t);
        }
        s.push_back(t);
    }
    inFile2.open(argv[1]);
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
    /////////////////////////////////////////////////
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
                if(min>max)
                {
                    cout<<"The start year can't be greater than the end year,Please re-enter the years!"<<endl;
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
            int c;
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
            cin>>c;
            string s;
            cout << "Enter the city you're travelling from:" << endl;
            cin.ignore();
            getline(cin,s);
            cin.clear();
            g.allOver();
            g.shortestPath(s,menu(c));
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
