class prime{
	int number;
	int nextPrimeNumber;
	void nextPrime(){
		int num = (number&1) ? number+2 : number+1;
		for(int i=num;i<INT_MAX;i+=2){
			int j=2;
			for(;j*j<=i;j++){
				if(i%j==0){
					break;
				}
			}
			if(j*j>i){
				nextPrimeNumber = i;
				break;
			}
		}
	}
public:
	prime(const int number){
		this->number = number;
		nextPrime();
	}
	int getNextPrime(){
		return nextPrimeNumber;
	}
};