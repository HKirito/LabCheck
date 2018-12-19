#include <sstream>
#include "Encrypt.h"

void Encrypt(){
    string filename="";
    char* temp;
    FILE* fp=NULL;
    string text;
    int i = 0;
    string key;
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

            cout<<"Input the key :";
            getline(cin,key);

            stringstream keys;//getline获取到的string转为int
            keys<<key;
            int keyi;
            keys>>keyi;

            while(text[i]!=NULL){
                text[i]+=keyi;
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
    string key;
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
            cout<<"Input the key :";
            getline(cin,key);

            stringstream keys;//getline获取到的string转为int
            keys<<key;
            int keyi;
            keys>>keyi;

            while(text[i]!=NULL){
                text[i]-=keyi;
                i++;
            }
            cout<<text<<endl;
            cout<<"Please input the output filename :";
            getline(cin,filename);
            cout<<filename;

            ofstream file2(filename);
            cout<<file2.is_open()<<endl;
            file2<<text;
            file2.close();
            cout<<"Complete operation !";
        }
    }
}

//
// Created by Kirito on 2018/12/6.
//

