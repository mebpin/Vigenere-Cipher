/Vigenere Cipher implementation 
//code by Bipin Timalsina
#include<iostream>
#include<string>
using namespace std;
class VigCipher{
public:
	// mod calculation
	int mod(int a, int b) {
  				int	c = a % b;
  				return (c < 0) ? c + b : c;
		}
	// taking key from user
	string getKey(){
 		string k;
 		cout<<"Enter the key:\n";
 		cin>>k;
 		return k;
	
	 }
	 //taking message
	string getMessage(){
		string m;
		cout<<"Enter the message:\n";
 		cin>>m;
 		return m;
	}
	//generating key as required
	string prepareKey(string s, string k){
			int msglen = s.length();
			int i = 0;
			while(true){
				if(msglen==i)
					i=0;
				if(k.length()==msglen)
					break;
				k.push_back(k[i]);
				i++;
			}
			return k;
		}
	// to encrypt
	void encrypt(string msg, string key){
		string cipherText;
		for(int i= 0;i<msg.size();i++){
			//converting in range 0-25 
			int ch= mod(toupper(msg[i])+toupper(key[i]),26);
			//to convert into alphabets in ASCII
			 ch+= 'A';
			 cipherText.push_back(ch);
			// cout<<cipherText<<endl;
		}
		cout<<"Cipher Text is : \n"<<cipherText<<endl;
	}
	//to decrypt
	void decrypt(string msg, string key){
		string text; 
  
    for (int i = 0 ; i < msg.length(); i++){

        // converting in range 0-25 
        int ch = mod((toupper(msg[i])- toupper(key[i])), 26); 
  
        // convert into alphabets(ASCII) 
        ch += 'A'; 
        text.push_back(ch); 
        //cout<<text<<endl;
    } 
    cout<<"The original text is : \n "<<text<<endl;
	}
};
int main(){
	cout<<"=======VIGENERE CIPHER=========="<<endl<<endl;
	int choice;
	char more='y';
	VigCipher vg;
	string msg,key,s;
	while(more=='y'){
		cout<<"Enter your choice as following :\n";
		cout<<" Press 1 for encryption "<<endl;
		cout<<" Press 2 for decryption "<<endl;
		cin>>choice;
	switch(choice){
		case 1: 
			msg= vg.getMessage();
			s=vg.getKey();
			key =vg.prepareKey(msg,s);
			//cout<<"key = "<< key<<endl<<"---";
			vg.encrypt(msg,key);
			break;
		case 2: 
			msg= vg.getMessage();
			s= vg.getKey();
			key =vg.prepareKey(msg,s);
			vg.decrypt(msg,key);
			break;
		default:
			cout<<"Invalid choice!!"<<endl;	
	}
	
	cout<<"\n\n Do you want to continue?(press y if you want)"<<endl;
	cin>>more;
 }
}
