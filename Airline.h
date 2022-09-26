#ifndef AIRLINE_H
#define AIRLINE_H
#include "Route.h"
#include <iostream>
#include <vector>
using namespace std;

class Airline{
	private:
		string name;
		vector <Route> routes; 	//dynamic array of routes
		
	public:
		Airline (){				//Default Constructor
		}
		Airline(string name){ 	//Parametrized Constructor
			this->name = name;
		}
		void toString(){		//A method to show airline name and a list of the Route objects it flies
			cout<<name<<endl;
			for (int i=0; i<routes.size(); i++){
			cout<<"\t";	
			routes[i].toString();
			}
		}
		
		void addRoute(Route r){	//Accepts a Route object as a parameter and places it in the next available position in the Route array
        	routes.push_back(r);
		}
		
		double calcDailyProfit(){	//A method to calculate the daily profit value.

			double dailyProfit=0;
			for (int i=0; i<routes.size(); i++){
				dailyProfit = dailyProfit + (routes[i].income()-routes[i].breakEven());	
			}
			return dailyProfit;
		}
};
#endif
