 //case 12|345|678   ,numEachFold=3
long long int foldshift(long long int a, int numEachFold){    
    int countDigit = 0;
    long long int tempA = a;
    int numOfFold=1;
    int sum = 0;
    while(tempA!=0){
        tempA /= 10;
        countDigit++;
    }
    int numOfPart = countDigit / numEachFold;
    for(int i = 0 ; i < numEachFold;i++)
        numOfFold*=10;
    while(a > 0) {
        sum += a%numOfFold;
        a/=numOfFold;
    }
    return sum%numOfFold;
}

//case 123|456|78  ,numEachFold=3
long long int foldshift1(long long int a, int numEachFold){    
    
    int countDigit = 0;
    long long int tempA = a;
    int numOfFold=1;
    int sum = 0;
    while(tempA!=0){
        tempA /= 10;
        countDigit++;
    }
    int lastPartLen = countDigit%numEachFold, p=1;
    for(int i = 0 ; i < lastPartLen ;i++) numOfFold*=10;
    sum += a%numOfFold; a/=numOfFold;
    for(int i = 0 ; i < numEachFold - lastPartLen ;i++) numOfFold*=10;
    while(a>0){
        sum+=a%numOfFold;
        a/=numOfFold;
    }
    return sum%numOfFold;
}

long long int digitExtraction(long long int a, int index[], int size){
    int countDigit = 0;
    long long int tempA = a;
    while(tempA!=0){
        tempA /= 10;
        countDigit++;
    }
    int cur = countDigit-1;
    int indexOfAr=size-1;
    int mult = 1;
    long long int sum = 0;
    while(indexOfAr >= 0){
        int mod = a%10;
        if(cur == index[indexOfAr]){
            sum += mult*mod ;
            mult*=10;
            indexOfAr--;
        }
        cur--;
        a/=10;
    }
    return sum;
}

long rotation(long long a){
    int countDigit = 0;
    long long int tempA = a;
    while(tempA!=0){
        tempA /= 10;
        countDigit++;
    }
    int mult = 1;
    for(int i = 0 ; i < countDigit -1; i++){
        mult*=10;
    }
    long long int firstDigit = (a- a%mult)/mult;
    long long int rest = a - firstDigit*mult;
    return rest*10 + firstDigit;
}

