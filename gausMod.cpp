#include<iostream>
#include<cstdio>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
const int n=3;
using namespace std;
  int i,j,k;
  float matr[n][n+1]={{2,-1,2,6},{-1,1,2,0},{3,1,-1,5}};
  float x[n],tmp,m;
   void vyvod()
{
	 cout<<"\n\n";
     for(i=0;i<n;i++)
     {
      cout<<"\n";               
      for(j=0;j<n+1;j++)
         cout<<"\t"<<matr[i][j];
     }
     cout<<"\n";
}
  void mod(){
  	float f;
  	int b=0,l;
  	for(l=0;l<n;l++){
	  f=matr[1][l];
  	for(i=0;i<n;i++)  if (fabs(matr[i][l]) >fabs(f)){
                f = matr[i][l];
                b=i+1;}
      cout<<"Matrix before:";
	  vyvod();
		   for (j= 0; j < n+1; j++)
            {    tmp = matr[b][j];
                 matr[b][j] = matr[l][j];
                 matr[l][j] = tmp;
            }
            cout<<"rearrangment "<<b<<" i "<<l;
		cout<<"\nMatrix after:";
		vyvod();  
            for(i=l+1;i<n;i++){
			m=matr[i][l];
			for(j=l;j<n+1;j++){
            	matr[i][j]-=matr[l][j]*m/f;}
			}
} 
}

  void resh(){
	float c;
   for (i=n-1; i>=0; i--)
     {
         for (j=i+1,c=0;j<n;j++) c+=matr[i][j]*x[j];
        x[i]=(matr[i][n]-c)/matr[i][i];
     }
}
void vyvodresh(){
	printf("\nSolution:\n");
  for (i=0; i<n; i++)
    printf("x%d=%3.0f\n", i+1, x[i]);
}
 
int main(){
	cout << "Starting matrix:";
	vyvod();
	mod();
	 resh();
     vyvodresh();
     system("PAUSE");
}
