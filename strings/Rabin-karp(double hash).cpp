#include <iostream>

using namespace std;

int MOD1 = 1000003;
int MOD2 = 1000033;

int SPRIME1 = 107;
int SPRIME2 = 101;

// correctly calculates a mod MOD even if a < 0
int mod1(int a)
{
  return (a % MOD1 + MOD1) % MOD1;
}

int mod2(int a)
{
  return (a % MOD2 + MOD2) % MOD2;
}

int hash1(string pattern){
    int h = 0;
    for(int i = 0, len = pattern.length(); i < len; i++){
        h *= SPRIME1;
        h += pattern[i];
        h = mod1(h);
    }
    return h;
}

int hash2(string pattern){
    int h = 0;
    for(int i = 0, len = pattern.length(); i < len; i++){
        h *= SPRIME2;
        h += pattern[i];
        h = mod2(h);
    }
    return h;
}


int power(int l){
    int r = 1;
    for(int i = 0; i<l; i++){
        r *= SPRIME1;
        r = mod1(r);
    }
    return r;
}

int power2(int l){
    int r = 1;
    for(int i = 0; i<l; i++){
        r *= SPRIME2;
        r = mod2(r);
    }
    return r;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int itt = 1; itt <= T; itt++){
        string text;
        string pattern;
        cin >> text >> pattern;

        //idiot proof
        if(pattern.length() > text.length()){
            cout << 0;
            break;
        }

        int length = pattern.length();
        int pwr1 = power(length - 1);
        int pwr2 = power2(length - 1);
        int phash1 = hash1(pattern); //pattern hash1
        int phash2 = hash2(pattern); //pattern hash2
        int fhash1 = hash1(text.substr(0, length)); //first hash1
        int fhash2 = hash2(text.substr(0, length)); //first hash2

        int counter = 0;

        if(phash1 == fhash1 && phash2 == fhash2) counter++;

        //Rabin-Karp alg
        for(int i = 0, len = text.length() - length; i <= len; i++){
            fhash1 -= mod1(text[i] * pwr1);
            fhash1 *= SPRIME1;
            fhash1 += text[i + length];
            fhash1 = mod1(fhash1);

            fhash2 -= mod2(text[i] * pwr2);
            fhash2 *= SPRIME2;
            fhash2 += text[i + length];
            fhash2 = mod2(fhash2);

            if(fhash1 == phash1 && fhash2 == phash2) counter++;
        }
        cout <<"Case "<<itt<<": "<<counter<<endl;
    }
    return 0;
}
