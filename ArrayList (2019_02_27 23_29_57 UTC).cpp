//
// Created by jackc on 10/16/2018.
//
#include "ArrayList.h"
#include <iostream>
#include <string>
#include "list"

ArrayList::ArrayList(int initialCapacity){
    currItemCount=0;
    currCapacity=initialCapacity;
    if(initialCapacity<1){
        throw std::invalid_argument ("Array size must be > 0");
    }else{
        array=new int[currCapacity];
    }
}

void ArrayList::doubleCapacity() {
    currCapacity=currCapacity*2;
    int *doubleArray=new int[currCapacity];
    for(int i=0;i<currCapacity;i++){
        doubleArray[i]=array[i];
    }
    delete[] array;
    array= doubleArray;
}

ArrayList::ArrayList(const ArrayList &arrayListToCopy) {
    currItemCount=arrayListToCopy.currItemCount;
    currCapacity=arrayListToCopy.currCapacity;
    array=new int[arrayListToCopy.currCapacity];
    for(int i=0;i<arrayListToCopy.currCapacity;i++){
        array[i]=arrayListToCopy.array[i];
    }
}

ArrayList& ArrayList::operator=(const ArrayList &arrayListToCopy) {
    if(this != &arrayListToCopy){
        delete[] array;
        array= nullptr;

        currItemCount=arrayListToCopy.currItemCount;
        currCapacity=arrayListToCopy.currCapacity;
        array=new int[arrayListToCopy.currCapacity];
        for(int i=0;i<arrayListToCopy.currCapacity;i++) {
            array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}

ArrayList::~ArrayList() {
    delete[] array;
    array= nullptr;
}

void ArrayList::insertAtEnd(int itemToAdd) {
    if(currCapacity<currItemCount){
        doubleCapacity();
        array[currItemCount]=itemToAdd;
        currItemCount++;
    }else{
        array[currItemCount]=itemToAdd;
        currItemCount++;
    }
}

int ArrayList::getValueAt(int index) {
    if(index>=currItemCount || index<0){
        throw std::out_of_range ("Out of range index");
    }
    else{
        return array[index];
    }
}

std::string ArrayList::toString() {
    std::string newString="{";

    for(int i=0;i<currItemCount;i++){
        newString+=std::to_string(array[i]);
        if(i<(currItemCount-1)){
            newString+=", ";
        }
    }
    newString+="}";
    return newString;
}

bool ArrayList::isEmpty() {
    if(currItemCount<1){
        return true;
    }else{
        return false;
    }
}

int ArrayList::itemCount() {
    return currItemCount;
}

void ArrayList::clearList() {
    currItemCount=0;
}

int ArrayList::find(int numToFind) {
    int i=0;
    while(i<currItemCount){
        if(array[i]==numToFind){
            return i;
        }else{
            i++;
        }
    }if(i==currItemCount){
        return -1;
    }
}

int ArrayList::findLast(int numToFind) {
    int i=(currItemCount-1);
    while(i>-1){
        if(array[i]==numToFind){
            return i;
        }else{
            i--;
        }
    }if(i==-1){
        return -1;
    }
}

int ArrayList::findMaxIndex() {
    if(currItemCount>0) {
        int i = 0;
        int maxIndex = 0;
        while (i < currItemCount) {
            if (array[i] > array[maxIndex]) {
                maxIndex = i;
                i++;
            } else if (array[i] == array[maxIndex]) {
                maxIndex = maxIndex;
                i++;
            } else {
                i++;
            }
        } return maxIndex;
    }else{
        throw std::out_of_range ("In findMaxIndex, List Must have items");
    }
}

void ArrayList::insertAtFront(int itemToAdd){
    if(currItemCount==currCapacity){
        doubleCapacity();
        currItemCount++;
        for(int i=currItemCount; i>0; i--){
            array[i]=array[i-1];
        }array[0]=itemToAdd;
    }else{
        currItemCount++;
        for(int i=currItemCount; i>0; i--){
            array[i]=array[i-1];
        }array[0]=itemToAdd;
    }
}

void ArrayList::insertAt(int itemToAdd, int index) {
    if(index<0 || index>currItemCount){
        throw std:: out_of_range("Bad Index");
    }else{
        if(currCapacity<=currItemCount){
            doubleCapacity();
            currItemCount++;
            for(int i=currItemCount; i>index; i--){
                array[i]=array[i-1];
            }array[index]=itemToAdd;
        }else{
            currItemCount++;
            for(int i=currItemCount; i>index; i--){
                array[i]=array[i-1];
            }array[index]=itemToAdd;
        }
    }
}

int ArrayList::removeValueAtEnd() {
    if(currItemCount>0){
        currItemCount--;
        return array[currItemCount];
    }else{
        throw std:: out_of_range("In removeValueAtEnd, List must have items");
    }

}

int ArrayList::removeValueAtFront() {
    if(currItemCount>0){
        int value=array[0];
        currItemCount--;
        for(int i=0; i<currItemCount; i++){
            array[i]=array[i+1];
        }return value;
    }else{
        throw std::out_of_range("In removeValueAtFront, List must have items");
    }
}

int ArrayList::removeValueAt(int index) {
    if(index<0 || index>currItemCount-1){
        throw std:: out_of_range("Bad Index");
    }else{
        currItemCount--;
        int value=array[index];
        for(int i=index; i<currItemCount; i++){
            array[i]=array[i+1];
        }return value;
    }
}