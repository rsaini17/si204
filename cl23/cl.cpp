#include <iostream>
#include <fstream>
using namespace std;

double** readGrades(int* pns, int* pnp);
double* getAveragePercentage(double** P, int ns, int np);
int indexOfMin(double* A, int np);

int main()
{
  int ns, np;
  double** P = readGrades(&ns, &np);
  double* A = getAveragePercentage(P,ns,np);
  int imin = indexOfMin(A,np);
  cout << "Problem p" << imin+1 << " is hardest (ave = "
  	<< A[imin] << "%)" << endl;

  for(int i=0; i < ns; i++)
    delete[] P[i];
  delete [] P;
  delete [] A;

  return 0;
}

double** readGrades(int* pns, int* pnp)
{
  ifstream fin("scores.txt");
  string x;
  fin >> *pns >> x >> *pnp >> x;

  int students = *pns;
  int problems = *pnp;
  double** P = new double*[students];
  for(int i = 0; i < students; i++)
    P[i] = new doubl[problems];

  for(int j = 0; j < problems; j++) 
    fin >> junk;
  for(int i = 0; i < students; i++)
    for(int j = 0; j < problems; j++)
      fin >> P[i][j];

  return P;
}
