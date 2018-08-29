# include <iostream>
#include <math.h>
#include<iomanip>
/*#include<fcntl.h>*/
#include<windows.h>
using namespace std;
int main()
{
	float P0, Ho, T0, D0, R, a, g0, Pt, Tt, Dt, P, T, D, M ; //declaring the variables
	/* Pt, Tt,Dt are the valuss of pressure and temperature in tropopause at the altitude of 11000 meters*/
	int H;
	double Tc; //Temperature in degree celcius
	char CalculateAgain;
	float p,h,t,A;
	P0 = 101325;
	T0 = 288.16;
	a  = -0.0065;
	g0 = 9.80665;
	D0 = 1.225;
	M = 28.966; // molecular weight of the dry air
	Tt = 216.66;
	Pt = 22632;  // put exp (variable) in e^ computation
	R = 287.026; //specific gas constant for dry air
	
	
	HANDLE Hconsole = GetStdHandle(STD_OUTPUT_HANDLE); //color control
	SetConsoleTextAttribute(Hconsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	cout<<"This is a program to calculate the PRESSURE, TEMPERATURE, and DENSITY for different altitudes based on standard atmosphere model by ICAO. \nAll the values assumed in this calculation is in accordance with the considerations of ICAO agreement."<<endl;
/*need to allign and make a table for pressure adensity and temperature
use cout<<left(for allignment)<<setw(15)<<pressure;
use cout<<right(for allignment)<<setw(15)<<density;
use cout<<right(for allignment)<<setw(15)<<temperature;
*/
	
	
	
do{     


         FlushConsoleInputBuffer(Hconsole);
         SetConsoleTextAttribute(Hconsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		 cout<< "\n \nEnter the altitude in meters. \nAltitude = ";
         cin>> H;  //Altitude input
         
              FlushConsoleInputBuffer(Hconsole);
			  while ( !cin )
			    {
			    cin.clear ();    // Restore input stream to working state
			    cin.ignore ( 100 , '\n' );    // empty the previous inputs
			    SetConsoleTextAttribute(Hconsole, FOREGROUND_RED );
			    cout << "Please enter a valid Number. \nEnter the altitude in meters again: ";
			    cin >> H;    // After cin is restored and any garbage in the stream has been cleared, store user input in number again
			    }
	
	            FlushConsoleInputBuffer(Hconsole);
		        if (H<0)
				{
					SetConsoleTextAttribute(Hconsole, 8 );
					cout<<"Altitude cannot be negative. Please enter a positive value above mean sea level.";
				    printf("\nPress Y to calculate again or any key to exit.\n");
				    cin.clear ();    // Restore input stream to working state
			        cin.ignore ( 100 , '\n' );    // empty the previous inputs
					cin>>CalculateAgain;
					FlushConsoleInputBuffer(Hconsole);
				}
			
				else if(H==0)
				{
					SetConsoleTextAttribute(Hconsole, 6 );
					Tc= T0 - 273.16;
					cout<<"This is the standard values at mean sea level.";
					cout<< "value of Pressure is "<< P0<<" pascals."<<endl;
				    

					cout<<"value of Density is ";
					std::cout <<fixed<< std::setprecision(4) << std::showpoint;
				    std::cout << D0 <<"  kg/m3" << endl;
				
				    cout<<"value of temperature is  "<<T0<< "  kelvin or" << Tc << "\370Celcius"<<endl;
				
					printf("Press Y to calculate again or any key to exit.\n");
					cin.clear ();    // Restore input stream to working state
			        cin.ignore ( 100 , '\n' );    // empty the previous inputs
					cin>>CalculateAgain;
					FlushConsoleInputBuffer(Hconsole);
				}
				
				else if ( H>0 & H< 11000)
				{ 
				float dat1, dat2, dat3;
				    SetConsoleTextAttribute(Hconsole, 12 );
				    T = T0 + a*H;
				    
				    Tc= T - 273.16;
				    
				    dat1= -1*g0/(R*a); // break for power calculation pow function easyness
				    dat2= T/T0; //break 2 for power
				    P=P0 * pow (dat2,dat1);
				    
				    dat3=-(-dat1 + 1);//break 3
				    D=D0 * pow (dat2,dat1);
				     SetConsoleTextAttribute(Hconsole, FOREGROUND_GREEN );
				    cout<< "value of Pressure is "<< P<<" pascals."<<endl;
				
					
					cout<<"value of Density is ";
					std::cout <<fixed << std::setprecision(8) << std::showpoint;
					std::cout << D <<"  kg/m3"<< endl;
					cout<<"value of temperature is  "<<T<< "  kelvin or " << Tc << "\370C"<<"Celcius"<<endl;
					
					printf("Press Y to calculate again or any key to exit.\n");
					cin.clear ();    // Restore input stream to working state
			        cin.ignore ( 100 , '\n' );    // empty the previous inputs
					cin>>CalculateAgain;
					FlushConsoleInputBuffer(Hconsole);
				    
				}
				else if ( H>= 11000 & H<=20000) 
				{   
				    SetConsoleTextAttribute(Hconsole, 8 );
					float dat4; 
					float Ht=11000, Dt=0.36392;  // values are strictly referred to ISA manual
					dat4=exp (-9.80665*((H-Ht)/(R*Tt)));//break 4
					P=Pt * dat4 ;
					D=Dt * dat4 ;
					T = Tt;
					Tc= T - 273.16;
					cout<< "value of Pressure is "<< P<<" pascals."<<endl;
				
					cout<<"value of Density is ";
					 std::cout << fixed<<std::setprecision(8)<<std::showpoint ;
				     std::cout << D <<"  kg/m3"  << endl;
					
					cout<<"value of temperature is  "<<T<< "  kelvin or" << Tc << "\370C"<<"Celcius"<<endl;
						
					printf("\n Press Y to calculate again or any key to exit.\n");
					cin.clear ();    // Restore input stream to working state
			        cin.ignore ( 100 , '\n' );    // empty the previous inputs
					cin>>CalculateAgain;
					FlushConsoleInputBuffer(Hconsole);
				}
				
				else if(H>20000)
				{
					SetConsoleTextAttribute(Hconsole, 13 );
					cout<<"The calculation is limited to altitude range within the passesnger aircraft flight. please enter the altitude below 20 km";
					printf("Press Y to calculate again or any key to exit.\n");
					cin.clear ();    // Restore input stream to working state
			        cin.ignore ( 100 , '\n' );    // empty the previous inputs
					cin>>CalculateAgain;
					FlushConsoleInputBuffer(Hconsole);
				}
			
				
				
	
		
	}
	while (CalculateAgain == 'Y'|| CalculateAgain == 'y');
	
	return 0;
	}
	

	  
	
	

