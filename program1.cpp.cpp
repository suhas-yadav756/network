#include <iostream> 
#include <cstring> 
#include <cctype> 
using namespace std; 

char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM"; 

char reverse_key[26]; 

void generate_reverse_key() { 
for (int i = 0; i < 26; i++) { 
reverse_key[key[i] - 'A'] = 'A' + i; 
} 
} 

void encrypt(char text[]) { 
for (int i = 0; text[i] != '\0'; i++) { 

        if (isalpha(text[i])) { 
 
            
            bool upper = isupper(text[i]); 
 
            int index = toupper(text[i]) - 'A'; 
 
            text[i] = upper ? key[index] : tolower(key[index]); 
        } 
    } 
} 
 
void decrypt(char text[]) { 
    for (int i = 0; text[i] != '\0'; i++) { 
 
        if (isalpha(text[i])) { 
 
            bool upper = isupper(text[i]); 
 
            int index = toupper(text[i]) - 'A'; 
 
            text[i] = upper ? reverse_key[index] : tolower(reverse_key[index]); 
        } 
    } 
} 
 
int main() { 
    char text[100]; 
 
    generate_reverse_key(); 
 

    cout << "Enter a string: "; 
    cin.getline(text, 100); 
 

    encrypt(text); 
    cout << "Encrypted text: " << text << endl; 
 

    decrypt(text); 
    cout << "Decrypted text: " << text << endl; 
 
    return 0; 
} 
 
 

