#include <iostream> // Įtraukiame iostream biblioteką, kad galėtume naudoti įvesties ir išvesties operacijas.

#include <fstream> // Įtraukiame iomanip biblioteką, naudosime vėliau rezultatų formatavimui.
using namespace std; // Kad nereikėtų rašyti std prie kiekvienos funkcijos

int main()
{
	ifstream fd("technika.txt");
	if (!fd) //patikrinu ar failas atsidare
	{
		return 0;
	}

	int n, gn, gs,
		kaina,
		sum1=0,sum2=0,sum3=0,sum4=0; //kintamieji

	fd >> n; //nuskaitomas duomenu eiluciu skaicius
	for (int i = 0; i < n; i++) //pirmas ciklas praeina pro visas eilutes
	{
		fd >> gn;
		fd >> gs;
		for (int j = 0; j < gs; j++) //antras ciklas praeina pro eilutes duomenis
		{
			fd >> kaina;
			//tikrinamas reikmenu tipas
			if (gn == 1)  //Pjaustykle
			{
				sum1 += kaina;
			}
			if (gn == 2) //Virduliai
			{
				sum2 += kaina;
			}
			if (gn == 3) //Mikseriai
			{
				sum3 += kaina;
			}
			if (gn == 4) //Plaktuvai
			{
				sum4 += kaina;
			}
		}
	}
	ofstream fr("pagaminta.txt");
	fr << "Pjaustykliu: " << sum1 << " Eur" << endl;
	fr << "Virduliu: " << sum2 << " Eur" << endl;
	fr << "Mikseriu: " << sum3 << " Eur" << endl;
	fr << "Plaktuviu: " << sum4 << " Eur" << endl;
	return 0;
}
