#include <iostream>
#define matrixDimension 10
using namespace std;
long double matrix[matrixDimension][matrixDimension]={0};
long double expectedRow[matrixDimension]={0};
long double expectedColumn[matrixDimension]={0};
long double a[matrixDimension];
long double b[matrixDimension];
unsigned int interpolationCounter=0;

void takeInputs(void);
void interPolation(void);
void printResult(void);
int main(void){
	char next;
	takeInputs();
	/*setting values of b to 1*/
	for(int i=0;i<matrixDimension;i++)
	{
		b[i]=1;
	}
	interPolation();
	while(1){
		interPolation();
		printResult();
		cin>>next;
		if(next=='Y'||next=='y')
			continue;
		else break;

	}


}

void takeInputs(){
	for(int i=0;i<matrixDimension;i++){
	cout<<"Enter the row number "<<i+1<<endl;
			for(int x=0;x<matrixDimension;x++){
				cout<<"a"<<i+1<<x+1<<" ";
			}
			cout<<endl;
			for(int x=0;x<matrixDimension;x++){
						cin>>matrix[i][x];
					}
	}
	cout<<endl;
	cout<<"Enter expected values column"<<endl;
	for(int i=0;i<matrixDimension;i++){
		cin>>expectedColumn[i];
	}
	cout<<endl;
	cout<<"Enter expected values row"<<endl;
	for(int i=0;i<matrixDimension;i++){
		cin>>expectedRow[i];
	}

}
void interPolation(){
	interpolationCounter++;
	long double tempSum=0;
	/*calculating A*/
	for(int i=0;i<matrixDimension;i++){
		tempSum=0;
		for(int x=0;x<matrixDimension;x++)
		{
			tempSum=tempSum+(long double)b[x]*matrix[i][x];
		}
		a[i]=(long double)expectedColumn[i]/(long double)tempSum;
	}
	/*calculation B*/
	for(int i=0;i<matrixDimension;i++){
		tempSum=0;
		for(int x=0;x<matrixDimension;x++){
			tempSum=tempSum+(long double)a[x]*matrix[x][i];
		}
		b[i]=(long double)expectedRow[i]/(long double)tempSum;
	}

}
void printResult(){
	cout<<"________________________________________________________________"<<endl;
			cout<<"Result After interpolation number "<<interpolationCounter<<endl;
			for(int i=0;i<matrixDimension;i++){
				cout<<"A"<<i+1<<" = "<<a[i]<<endl;
			}
			for(int i=0;i<matrixDimension;i++){
						cout<<"B"<<i+1<<" = "<<b[i]<<endl;
					}
			cout<<"________________________________________________________________"<<endl;
			cout<<"step forward press 'Y'"<<endl<<"to end the program press 'N'"<<endl;

}
