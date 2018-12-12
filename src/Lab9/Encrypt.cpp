#include "Encrypt.h"

void Encrypt(){
    string filename="";
    char* temp;
    FILE* fp=NULL;
    string text;
    int i = 0;
    cout << "Please input filename you want to encrypt :";
    getline(cin,filename);
    if (filename==""){
        cout << "input error !" <<endl;
    }else{
        fstream file(filename);
        if (!file.is_open()){
            cout<<"error open file!";
        }else{
            cout<<"succeed open file"<<endl;
            int size = file.tellg();
            temp = new char [size];
            file.read(temp,size);
            file>>text;
            file.close();

            cout<<text<<endl;
            while(text[i]!=NULL){
                text[i]+=2;
                i++;
            }
            cout<<text<<endl;
            cout<<"Please input the output filename :";
            getline(cin,filename);
            cout<<filename;

            ofstream file2(filename);
            cout<<file2.is_open();
            file2<<text;
            file2.close();
            cout<<"Complete operation !";
        }
    }
}

void Encrypted(){
    string filename="";
    char* temp;
    FILE* fp=NULL;
    string text;
    int i = 0;
    cout << "Please input filename you want to encrypted :";
    getline(cin,filename);
    if (filename==""){
        cout << "input error !" <<endl;
    }else{
        fstream file(filename);
        if (!file.is_open()){
            cout<<"error open file!";
        }else{
            cout<<"succeed open file"<<endl;
            int size = file.tellg();
            temp = new char [size];
            file.read(temp,size);
            file>>text;
            file.close();

            cout<<text<<endl;
            while(text[i]!=NULL){
                text[i]-=2;
                i++;
            }
            cout<<text<<endl;
            cout<<"Please input the output filename :";
            getline(cin,filename);
            cout<<filename;

            ofstream file2(filename);
            cout<<file2.is_open();
            file2<<text;
            file2.close();
            cout<<"Complete operation !";
        }
    }
}

//
// Created by Kirito on 2018/12/6.
//

