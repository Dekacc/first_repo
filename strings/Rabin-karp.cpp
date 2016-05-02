#include <iostream>

using namespace std;

int MOD = 1000003;
int SPRIME = 107;

// correctly calculates a mod MOD even if a < 0
int mod(int a)
{
  return (a % MOD + MOD) % MOD;
}

int whash(string pattern){
    int h = 0;
    for(int i = 0, len = pattern.length(); i < len; i++){
        h *= SPRIME;
        h += pattern[i];
        h = mod(h);
    }
    return h;
}

int power(int l){
    int r = 1;
    for(int i = 0; i<l; i++){
        r *= SPRIME;
        r = mod(r);
    }
    return r;
}

int main()
{
    string text;
    string pattern;
    cin >> text >> pattern;

    //idiot proof
    if(pattern.length() > text.length()){
        cout << 0;
        return 0;
    }

    int length = pattern.length();
    int pwr = power(length - 1);
    int phash = whash(pattern); //pattern hash
    int fhash = whash(text.substr(0, length)); //first hash

    int counter = 0;

    if(phash == fhash){
        if(pattern == text.substr(0, length)) counter++;
    }

    //Rabin-Karp alg
    for(int i = 0, len = text.length() - length; i <= len; i++){
        fhash -= mod(text[i] * pwr);
        fhash *= SPRIME;
        fhash += text[i + length];
        fhash = mod(fhash);

        if(fhash == phash){
            //possible match
            if(pattern == text.substr(i+1, length)) counter++;
        }

    }
    cout << counter;
    return 0;
}
