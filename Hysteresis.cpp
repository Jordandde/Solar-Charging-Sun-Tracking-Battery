#include <iostream>
#include <stdlib.h>
enum State { START, DONE, GOT_ZERO, GOT_ONE, GOT_KTH_ZERO, GOT_KTH_ONE};
int countZerosAndOnes(const int zeroOneData[], const int numSamples,const int kMax,int& zeroCount, int& oneCount){
	if(kMax < 0){
		return -1;
	}
	oneCount = 0;
	if(numSamples <= 0){
		return -1;
	}
	State s = START;

	int k = 1;
	int j = 0;
	int counter = 0;
	int num;
	zeroCount = 0;
	while(s != DONE && counter < numSamples){
		num = zeroOneData[counter];
		if(num != 1 && num != 0){
			return -1;
		}
		switch(s){
			case START:
				if(num == 1){
					s = GOT_KTH_ONE;
					k++;
				}else if(num == 0){
					s = GOT_KTH_ZERO;
					j = 1;
				}else{
					return -1;
				}
				counter++;
				break;
			case GOT_KTH_ONE:
				if(num == 1){
					k++;
				}else if(num == 0){
					if(j > kMax){
						s = GOT_ZERO;
						 
					}else{
						s = GOT_KTH_ZERO;
						counter -= 1;
					}
					counter++;
					break;
				}
				if(k > kMax){
					s = GOT_ONE;
					oneCount++;
				}
				counter++;
				break;
			case GOT_ONE:
				if(num == 0){
					s = GOT_KTH_ZERO;
					j = 0;
					counter = counter - 1;
				}
				counter++;
				break;
			case GOT_KTH_ZERO:
				if(num == 0){
					j++;
				}else if(num == 1){
					if(k > kMax){
						s = GOT_ONE;
					}else{
	
						s = GOT_KTH_ONE;
						counter -= 1;
					}
					counter++;
					break;
				}if(j > kMax){
					s = GOT_ZERO;
					zeroCount++;
				}		
				counter++;
				break;
			case GOT_ZERO:
				if(num == 1){
					k = 0;
					s = GOT_KTH_ONE;
					counter = counter - 1;
				}	
				counter++;
				break;
			case DONE:
				break;
		}	
	}
	if(oneCount == 0){
		oneCount = 1;
	}
	return 0;
}
/*using namespace std;
int main(const int argc, const char* const argv[]){
	int zeroCount = 0;
	int oneCount = 0;
	int zeroOneData[17] = {1,0,1,0,1,0,0,0,1,1,1,0,0,0,1};
	countZerosAndOnes(zeroOneData,15,2,zeroCount,oneCount);
	cout << oneCount << endl << zeroCount << endl;
	return 0;
}*/
