#include<stdio.h>
#include<stdlib.h>

void decrypt(FILE *encrypted_file,FILE *key, FILE *decrypted_file){
    int character,key_character,decrypted_character;
    while((character=fgetc(encrypted_file))!=EOF){
        key_character=fgetc(key);
        decrypted_character=character ^ key_character;
        fputc(decrypted_character,decrypted_file);
        
    }
}



int main(int argc, char *argv[]){
    FILE *encrypted_file,*key,*decrypted_file;

    encrypted_file = fopen(argv[1],"r");
    if(encrypted_file == NULL){
        printf("Error: Could not open file %s\n",argv[1]);
        exit(1);
    }
    key=fopen(argv[2],"r");
    if(key == NULL){
        printf("Error: Could not open key file %s\n",argv[2]);
        exit(1);
    }
    decrypted_file=fopen("decrypted.txt","w");

    decrypt(encrypted_file,key,decrypted_file);
    fclose(encrypted_file);
    fclose(key);

}