#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
#include "Aircraft.h" 
#include <string>
#include <vector>

using namespace std;

class Route{
	
	private:
		string destination; //eg “Hong Kong”
		double flyTime; //the hours taken to reach the destination.
		int passengerVol; //passengers flying on this route each day
		double fare; //We assume all passengers pay the same fare.
	 	vector <Aircraft> planes;//An array of aircraft objects that have been assigned to that route.
	
		
	public:
		Route(){	//Default constructor
		/*	destination = "";
			flyTime = 0.0;
			passengerVol = 0;
			fare = 0.0; */
		}
		
		Route(string destination, double flyTime, int passengerVol){	//Parametrized constructor
			this->destination = destination;
			this->flyTime = flyTime;
			this->passengerVol = passengerVol;
		}

		void toString(){	//A method to show the Route destination, flytime, passengers volume & details of each aircraft in the route 
			cout<<"KLIA - "<<destination<<", "<<flyTime<<" hours, "<<passengerVol<<" passengers"<<endl;
			for(int i=0; i<planes.size(); i++){	
				cout<<"\t\t";	
				planes[i].toString();
			}
		}
		void setFare(double fare){		//A method to assign fare for different route
			this->fare = fare;
		}
		
		double breakEven(){		//A method to calculate total cost of flying planes on that route
			double cost=0;
			for(int i=0; i<planes.size(); i++){
				cost = cost+ planes[i].calcRunningCosts();
			}	
			return cost * flyTime;			
		}
		
		double income(){		//A method to calculate the income generated from passengers paying the fare on that route
			return fare * passengerVol;
		}
		
		void addAircraft (Aircraft a){	//An method to insert the Aircraft object into the next available place in the Aircraft array for that route
 			planes.push_back(a);
		}
		
};

#endif
