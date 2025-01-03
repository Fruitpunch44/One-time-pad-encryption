#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void encrypt(FILE *Unencrypted_file,FILE *keyfile,FILE *EncryptedFile){
    int character;
    int key;
    while((character=fgetc(Unencrypted_file))!=EOF){
        srand(time(NULL));
        key=rand();
        int encrpyted_content=character ^ key;
        fputc(encrpyted_content,EncryptedFile);
        fputc(key,keyfile);}
}
int main(int argc,char *argv[]){
    if(argc!=2){
        printf("usage : script <filename");
    }
    FILE *Unencrypted_file;
    FILE *key;
    FILE *EncryptedFile;

    Unencrypted_file=fopen(argv[1],"r");
     if(Unencrypted_file==NULL){
        printf("error in opening file");
    }
    key=fopen("key.txt","w");
    EncryptedFile=fopen("EncryptedFile.txt","w");
    encrypt(Unencrypted_file,key,EncryptedFile);
    fclose(Unencrypted_file);
    fclose(key);   
    fclose(EncryptedFile);

    return 0;

}