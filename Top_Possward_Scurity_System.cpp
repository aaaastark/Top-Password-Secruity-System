#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstring>
using namespace std;
void initalize();

class Basic_Information{
	protected:
		string message_with_space;
		string message_without_space;
		int key_number; string Key_vigenere;
		string out_vigenere;
	public:
		virtual void Uer_Input_Cryptography(){}
		virtual void Uer_Input_CaesarClipher(){}
		virtual void Uer_Input_VigenereClipher(){}
		virtual void display_message_Cryptography(){}
		virtual void display_message_CaesarClipher(){}
		virtual void display_message_VigenereClipher(){}
		virtual void Encrypter_Crytography(){}
		virtual void Encrypter_CaesarClipher(){}
		virtual void Encrypter_VigenereClipher(){}
		virtual void Decrypter_Crytography(){}
		virtual void Decrypter_CaesarClipher(){}
		virtual void Decrypter_VigenereClipher(){}
		virtual void key_genrate_vigenere_clipher(){}
};
class File_Save_Password{
	public:
		virtual void output_file_Cryptography(){}
		virtual void input_file_Cryptography(){}
		virtual void output_file_CaesarClipher(){}
		virtual void input_file_CaesarClipher(){}
		virtual void output_file_VigenerClipher(){}
		virtual void input_file_VigenerClipher(){}
};
class Encryption: public Basic_Information, public File_Save_Password{
	private:
		string cryp_mess,caesar_mess,vige_mess; int key; char ch; int i;
	public:
		void key_genrate_vigenere_clipher();
		void Uer_Input_Cryptography();
		void Uer_Input_CaesarClipher();
		void Uer_Input_VigenereClipher();
		void Encrypter_Crytography();
		void Encrypter_CaesarClipher();
		void Encrypter_VigenereClipher();
		void display_message_Cryptography();
		void display_message_CaesarClipher();
		void display_message_VigenereClipher();
		void output_file_CaesarClipher();
		void output_file_Cryptography();
		void output_file_VigenerClipher();
};
void Encryption::key_genrate_vigenere_clipher(){
	string key_vigenere_1;
	cout<<"\nEnter the key of vigenere clipher for password (UPPER CASE LETTER): ";
	cin>>key_vigenere_1;
	for (int i = 0; i < key_vigenere_1.size(); ++i){  
        if (key_vigenere_1[i] >= 'A' && key_vigenere_1[i] <= 'Z')  
            Key_vigenere += key_vigenere_1[i];  
        else if (key_vigenere_1[i] >= 'a' && key_vigenere_1[i] <= 'z')  
        	Key_vigenere += key_vigenere_1[i] + 'A' - 'a';  
    } 
}
void Encryption::Uer_Input_Cryptography(){
	cout<<"Enter Password Message to Encryption for Cryptography (without spacess) : ";
	cin>>message_without_space;
	cryp_mess=message_without_space;
}

void Encryption::Uer_Input_CaesarClipher(){
	cout<<"Enter Password Message to Encryption for Caesar Clipher (without spacess) : ";
	cin>>message_without_space;
	caesar_mess=message_without_space;
	cout<<"Enter Key for Caear Clipher (0 - 9) : ";
	cin>>key_number;
	key=key_number;
}
void Encryption::Uer_Input_VigenereClipher(){
	cout<<"Enter Password Message to Encryption for Vigenere Clipher (without spacess) : ";
	cin>>message_without_space;
	vige_mess = message_without_space;
}
void Encryption::Encrypter_Crytography(){
	for(int i=0; cryp_mess[i]!='\0'; i++){
		cryp_mess[i]= cryp_mess[i] + 2;
	}
}
void Encryption::Encrypter_CaesarClipher(){
	for(i = 0; caesar_mess[i] != '\0'; ++i){
		ch = caesar_mess[i];
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;
			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			caesar_mess[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			caesar_mess[i] = ch;
		}
	}
}
void Encryption::Encrypter_VigenereClipher(){  
    for (int i = 0, j = 0; i < vige_mess.length(); ++i){  
        char c = vige_mess[i];  
        if (c >= 'a' && c <= 'z')  
            c += 'A' - 'a';  
        else if (c < 'A' || c > 'Z')  
            continue;  
        out_vigenere += (c + Key_vigenere[j] - 2 * 'A') % 26 + 'A';  
        j = (j + 1) % Key_vigenere.length();  
    }
}
void Encryption::display_message_Cryptography(){
	cout<<"\nEncrypted Cryptography password message show : "<<cryp_mess<<endl;
}
void Encryption::display_message_CaesarClipher(){
	cout<<"\nEncrypted Caesar Clipher password message show : "<<caesar_mess<<endl;
}
void Encryption::display_message_VigenereClipher(){
	cout<<"\nEncrypted Vigenere Clipher password message show : "<<out_vigenere<<endl;
}

void Encryption::output_file_CaesarClipher(){
	ofstream caesar_cipher_output_file;
	caesar_cipher_output_file.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\CaesarClipherEncrypted.txt");
	caesar_cipher_output_file<<caesar_mess;
}
void Encryption::output_file_Cryptography(){
	ofstream cryptography_output_file;
	cryptography_output_file.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\CryptographyEncrypted.txt");
	cryptography_output_file<<cryp_mess;
}
void Encryption::output_file_VigenerClipher(){
	ofstream vigenere_cipher_output_file;
	vigenere_cipher_output_file.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\VigenereClipherEncrypted.txt");
	vigenere_cipher_output_file<<out_vigenere;
}



class Decryption: public Basic_Information, public File_Save_Password{
	private:
		int choice; string cryp_mess, caes_mess, vige_mess; int i; int key; char ch;
		string cryp_mess_user, caes_mess_user, vige_mess_user;
		string out_vigenere1,out_vigenere2; string key_vigenere1,key_vigenere2;
		string key_vigen1, key_vigen2;
	public:
		friend void User_Informatin(Decryption &choice);
		void input_file_CaesarClipher();
		void input_file_Cryptography();
		void input_file_VigenerClipher();
		void output_file_CaesarClipher();
		void output_file_Cryptography();
		void output_file_VigenerClipher();
		void Decrypter_Crytography();
		void Decrypter_CaesarClipher();
		void Decrypter_VigenereClipher();
		void display_message_Cryptography();
		void display_message_CaesarClipher();
		void display_message_VigenereClipher();
		
};
void User_Informatin(Decryption &ch){
	cout<<"1: When you access the store Encrypted Password\n";
	cout<<"2: When you access the new enter Encrypted Password\n\n";
	cout<<"Enter your choice here : ";
	cin>>ch.choice;
}
void Decryption::input_file_CaesarClipher(){
	if(choice == 1){
		ifstream caesar_cipher_input_file1;
		caesar_cipher_input_file1.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\CaesarClipherEncrypted.txt");
		caesar_cipher_input_file1>>caes_mess;
	}
}
void Decryption::input_file_Cryptography(){
	if(choice == 1){
		ifstream cryptography_input_file1;
		cryptography_input_file1.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\CryptographyEncrypted.txt");
		cryptography_input_file1>>cryp_mess;
	}
}
void Decryption::input_file_VigenerClipher(){
	if(choice == 1){
		ifstream vigenere_cipher_input_file;
		vigenere_cipher_input_file.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\VigenereClipherEncrypted.txt");
		vigenere_cipher_input_file>>vige_mess;
	}
}


void Decryption::output_file_CaesarClipher(){
	if(choice == 1){
		ofstream caesar_cipher_output_file1;
		caesar_cipher_output_file1.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\CaesarClipherDecrypted.txt");
		caesar_cipher_output_file1<<caes_mess;
	}
	else if (choice == 2){
		ofstream caesar_cipher_output_file1;
		caesar_cipher_output_file1.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\CaesarClipherDecrypted.txt");
		caesar_cipher_output_file1<<caes_mess_user;
	}	
}

void Decryption::output_file_Cryptography(){
	if(choice == 1){
		ofstream cryptography_output_file1;
		cryptography_output_file1.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\CryptographyDecrypted.txt");
		cryptography_output_file1<<cryp_mess;
	}
	else if (choice == 2){
		ofstream cryptography_output_file1;
		cryptography_output_file1.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\CryptographyDecrypted.txt");
		cryptography_output_file1<<cryp_mess_user;
	}
}

void Decryption::output_file_VigenerClipher(){
	if(choice == 1){
		ofstream vigenere_cipher_output_file;
		vigenere_cipher_output_file.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\VigenereClipherDecrypted.txt");
		vigenere_cipher_output_file<<out_vigenere1;
	}
	else if (choice == 2){
		ofstream vigenere_cipher_output_file;
		vigenere_cipher_output_file.open("G:\\Simester 3\\OOP CLASS\\Top Scurity Password System\\VigenereClipherDecrypted.txt");
		vigenere_cipher_output_file<<out_vigenere2;
	}
}


void Decryption::Decrypter_Crytography(){
	if(choice == 1){
		for(i = 0; cryp_mess[i] != '\0'; i++){
			cryp_mess[i] = cryp_mess[i] - 2;
		}
	}
	else if (choice == 2){
		cout<<"\nEnter the encrypted password message in cryptography : ";
		cin>>cryp_mess_user;
		for(i = 0; cryp_mess_user[i] != '\0'; i++){
			cryp_mess_user[i] = cryp_mess_user[i] - 2;
		}
	}	
}
void Decryption::Decrypter_CaesarClipher(){
	if(choice == 1){
		cout<<"\nEnter Key for Caear Clipher.You enter at Ecryption time (0 - 9) : ";
		cin>>key;
	}else if (choice == 2){
		cout<<"\nEnter Key for Caear Clipher.You enter at Ecryption time (0 - 9) : ";
		cin>>key;
	}
	
	if(choice == 1){
		for(i = 0; caes_mess[i] != '\0'; ++i){
			ch = caes_mess[i];
			if(ch >= 'a' && ch <= 'z'){
				ch = ch - key;
				if(ch < 'a'){
					ch = ch + 'z' - 'a' + 1;
				}	
			caes_mess[i] = ch;
			}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;
				if(ch > 'a'){
					ch = ch + 'Z' - 'A' + 1;
				}
			caes_mess[i] = ch;
			}
		}	
	}else if(choice == 2){
		cout<<"\nEnter the encrypted password message in caesarclipher : ";
		cin>>caes_mess_user;
		for(i = 0; caes_mess_user[i] != '\0'; ++i){
			ch = caes_mess_user[i];
			if(ch >= 'a' && ch <= 'z'){
				ch = ch - key;
				if(ch < 'a'){
					ch = ch + 'z' - 'a' + 1;
				}
			caes_mess_user[i] = ch;
			}
			else if(ch >= 'A' && ch <= 'Z'){
				ch = ch - key;
				if(ch > 'a'){
					ch = ch + 'Z' - 'A' + 1;
				}
			caes_mess_user[i] = ch;
			}
		}
	}
}
void Decryption::Decrypter_VigenereClipher(){
	if(choice == 1){
		cout<<"\nEnter Key for Vigenere Clipher.You enter at Ecryption time (UPPER CASE LETTER) : ";
		cin>>key_vigenere1;    	
		for (int i = 0; i < key_vigenere1.size(); ++i){  
        	if (key_vigenere1[i] >= 'A' && key_vigenere1[i] <= 'Z')  
           		key_vigen1 += key_vigenere1[i];  
        	else if (key_vigenere1[i] >= 'a' && key_vigenere1[i] <= 'z')  
        		key_vigen1 += key_vigenere1[i] + 'A' - 'a';  
    	} 
	}else if(choice == 2){
		cout<<"\nEnter Key for Vigenere Clipher.You enter at Ecryption time (UPPER CASE LETTER) : ";
		cin>>key_vigenere2;
		for (int i = 0; i < key_vigenere2.size(); ++i){  
        	if (key_vigenere2[i] >= 'A' && key_vigenere2[i] <= 'Z')  
           		key_vigen2 += key_vigenere2[i];  
        	else if (key_vigenere2[i] >= 'a' && key_vigenere2[i] <= 'z')  
        		key_vigen2 += key_vigenere2[i] + 'A' - 'a';  
    	} 
	}
	if(choice == 1){  
        for (int i = 0, j = 0; i < vige_mess.length(); ++i)  
        {  
            char c = vige_mess[i];  
            if (c >= 'a' && c <= 'z')  
                c += 'A' - 'a';  
            else if (c < 'A' || c > 'Z')  
                continue;  
            out_vigenere1 += (c - key_vigen1[j] + 26) % 26 + 'A';  
            j = (j + 1) % key_vigen1.length();  
        }  
	}   
    else if(choice == 2){
    	cout<<"\nEnter the encrypted password message in vigenereclipher : ";
		cin>>vige_mess_user;
		for (int i = 0, j = 0; i < vige_mess_user.length(); ++i)  
        {  
            char c = vige_mess_user[i];  
            if (c >= 'a' && c <= 'z')  
                c += 'A' - 'a';  
            else if (c < 'A' || c > 'Z')  
                continue;  
            out_vigenere2 += (c - key_vigen2[j] + 26) % 26 + 'A';  
            j = (j + 1) % key_vigen2.length();  
        } 
	}
}



void Decryption::display_message_Cryptography(){
	if(choice == 1){
		cout<<"\nDecrypted Cryptography password message show : "<<cryp_mess<<endl;
	}else if(choice == 2){
		cout<<"\nDecrypted Cryptography password message show : "<<cryp_mess_user<<endl;
	}
}
void Decryption::display_message_CaesarClipher(){
	if(choice == 1){
		cout<<"\nDecrypted Caesar Clipher password message show : "<<caes_mess<<endl;
	}else if(choice == 2){
		cout<<"\nDecrypted Caesar Clipher password message show : "<<caes_mess_user<<endl;
	}
}

void Decryption::display_message_VigenereClipher(){
	if(choice == 1){
		cout<<"\nDecrypted Vigenere Clipher password message show : "<<out_vigenere1<<endl;
	}else if(choice == 2){
		cout<<"\nDecrypted Vigenere Clipher password message show : "<<out_vigenere2<<endl;
	}
}


class Cryptography{
	public:
		void show_cryptography_password_encryption(Encryption &en){
			en.Uer_Input_Cryptography();
			en.Encrypter_Crytography();
			en.display_message_Cryptography();
			en.output_file_Cryptography();
		}
		void show_cryptography_password_decryption(Decryption &de){
			User_Informatin(de);  // Friend functons of Decryption Class
			de.input_file_Cryptography();
			de.Decrypter_Crytography();
			de.display_message_Cryptography();
			de.output_file_Cryptography();	
		}
};

class CaesarClipher{
	public:
		void show_caesarclipher_password_ecryption(Encryption &en){
			en.Uer_Input_CaesarClipher();
			en.Encrypter_CaesarClipher();
			en.display_message_CaesarClipher();
			en.output_file_CaesarClipher();
		}
		void show_caesarclipher_password_decryption(Decryption &de){
			User_Informatin(de); // Friend functons of Decryption Class
			de.input_file_CaesarClipher();
			de.Decrypter_CaesarClipher();
			de.display_message_CaesarClipher();
			de.output_file_CaesarClipher();
		}
};
class VigenereClipher{
	public:
		void show_vigenereclipher_password_encryption(Encryption &en){
			en.key_genrate_vigenere_clipher();
			en.Uer_Input_VigenereClipher();
			en.Encrypter_VigenereClipher();
			en.display_message_VigenereClipher();
			en.output_file_VigenerClipher();
		}
		void show_vigenereclipher_password_decryption(Decryption &de){
			User_Informatin(de); // Friend functons of Decryption Class
			de.input_file_VigenerClipher();
			de.Decrypter_VigenereClipher();
			de.display_message_VigenereClipher();
			de.output_file_VigenerClipher();
		}
};



int main(){
	initalize();
	Encryption encryp_1;
	Decryption decryp_1;
	char ch;
	do{
		int num;
		cout<<"\nEnter number : ";
		cin>>num;
		if(num == 1){
			Cryptography cryptography;
			cryptography.show_cryptography_password_encryption(encryp_1);
			cout<<"\n\n";
			cryptography.show_cryptography_password_decryption(decryp_1);
		}
		else if(num == 2){
			CaesarClipher caesarclipher;
			caesarclipher.show_caesarclipher_password_ecryption(encryp_1);
			cout<<"\n\n";
			caesarclipher.show_caesarclipher_password_decryption(decryp_1);
		}
		else if(num == 3){
			VigenereClipher vigenereclipher;
			vigenereclipher.show_vigenereclipher_password_encryption(encryp_1);
			cout<<"\n\n";
			vigenereclipher.show_vigenereclipher_password_decryption(decryp_1);
		}
		cout<<"\n\nDo you continue agian press (Y or y) and exit press (N or n) : ";
		cin>>ch;
		if((ch == 'n') || (ch == 'N')){
			cout<<"\nThanks.Have a nice day.\n";
			exit(2);
		}
	}while((ch == 'y') || (ch == 'Y'));
}

void initalize(){
	cout<<"1:              Cryptography Algorithm\n";
	cout<<"2:             Caesar Clipher Algorithm\n";
	cout<<"3:             Vigener Clipher Algorithm\n";
	cout<<"            ENCRYPTION (GIVEN USER PASSWORD)\n";
	cout<<"            DECRYPTION (GIVEN USER PASSWORD)\n";
	cout<<"E.g.	Cryptography,Caesar Clipher,and Vigenere Cipher\n\n";
}

