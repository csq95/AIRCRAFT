#include <iostream>
#include "Airline.h"
#include "Aircraft.h"
#include "Route.h"
#include <iomanip>
void runAirline();

int main ()
{
	runAirline();
}
void runAirline()
{
	//--- Create Aircraft objects --------
	Aircraft A330 ("Airbus A330", 220,14,600,4.0);
	Aircraft B747 ("Boeing 747", 350,20,1000,7.0);
	Aircraft B737 ("Boeing 737", 150,7,450,2.5);
	Aircraft BAe464 ("BAe 464", 60,4,300,1.3);
	//--- Create Routes -----------
	Route HNK ("Hong Kong", 9.5, 300);
	Route SNG ("Singapore", 7.5, 500);
	Route AUC ("Auckland", 4.0, 400);
	Route PER ("Perth", 3.5, 270);
	Route MTG ("Mt Gambier", 0.75, 45);
	//--- Assign sufficient aircraft to routes to cover passenger
	//volume
	HNK.addAircraft(A330);
	HNK.addAircraft(B737);
	SNG.addAircraft(B747);
	SNG.addAircraft(B737);
	AUC.addAircraft(A330);
	AUC.addAircraft(A330);
	PER.addAircraft(B737);
	PER.addAircraft(B737);
	MTG.addAircraft(BAe464);
	//--- Assign fares to routes and display route costs ---
	cout<<fixed<<setprecision(2);
	cout<<"\nRoute Costs : "<<endl;
	HNK.setFare(1100);
	cout<<"HNK : $"<<HNK.breakEven()<<endl;
	SNG.setFare(800);
	cout<<"SNG : $"<<SNG.breakEven()<<endl;
	AUC.setFare(450);
	cout<<"AUC : $"<<AUC.breakEven()<<endl;
	PER.setFare(450);
	cout<<"PER : $"<<PER.breakEven()<<endl;
	MTG.setFare(130);
	cout<<"MTG : $"<<MTG.breakEven()<<endl;
	//--- Create Airline object ---
	Airline a1 ("Dingo Air");
	//--- Assign Routes to Airline ---
	a1.addRoute(HNK);
	a1.addRoute(SNG);
	a1.addRoute(AUC);
	a1.addRoute(PER);
	a1.addRoute(MTG);
	//--- Display the Airline object ---
	cout<<endl;
	a1.toString();

	//--- Display the daily profit ---
	cout<<"\nDaily profit: ";
	cout<<a1.calcDailyProfit()<<endl;

}
