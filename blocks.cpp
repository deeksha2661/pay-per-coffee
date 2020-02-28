#include <iostream>
#include "picosha2.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class transaction{
public:
	string payer;
	string payee;
	int amount;
}

class block{
public:
       transaction trans[5];
       string prev_hash;
       string cur_hash;
} 

int main(){
	string hash_payer[5];
	string hash_payee[5];
	string initial;
	block b;


	cout << "hello" << endl;

	cout << "enter string for initial hash" << endl;
	cin >> initial >> endl;
	picosha2 :: hash256_hex_string(initial, b.prev_hash);
	
	string hash_total = b.prev_hash;

	cout << "plse enter transaction details" << endl;

	 for(int i = 0; i < 5; i++){
                cout << "enter payer" << i << endl;
                cin >> b.trans[i].payer >> endl;
                cout << "enter payee" << i << endl;
                cin >> b.trans[i].payee >> endl;
                cout << "enter amount" << endl;
                cin >> b.trans[i].amount >> endl;

                picosha2 :: hash256_hex_string(b.trans[i].payer, hash_payer[i]);
       		picosha2 :: hash256_hex_string(b.trans[i].payee, hash_payee[i]);
        	
		hash_total += hash_payer[i];
		hash_total += hash_payee[i];
		hash_total += to_string(b.trans[i].amount);
	 }

	 picosha2 :: hash256_hex_string(hash_total, b.cur_hash);
	
	 cout << b.prev_hash << endl;
	 cout << b.cur_hash << endl;



	return 0;
}

