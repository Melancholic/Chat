#include"client.h"
#include<iostream>
#include<stdio.h>
const int MaxLenMsg=1024;
const int MaxLenAdresat=32;

client::client(){
 msg = new char[MaxLenMsg];
 adresat= new char[MaxLenAdresat];
}

void client::add_msg(){
  std::cout<<"\n Введите ник адресата: ";
fgets(adresat,MaxLenAdresat,stdin);
  std::cout<<"\n";
    std::cout<<"\n Введите сообщение: ";

fgets(msg,MaxLenMsg,stdin);
 std::cout<<"\n";
 for (int i=0;i<MaxLenMsg;i++){
   std::cout<<msg[i];
 }
}

client::~client(){
delete[] msg;
 delete[] adresat;
}
char client::GetSymMsg(int i){
  return msg[i];
}
