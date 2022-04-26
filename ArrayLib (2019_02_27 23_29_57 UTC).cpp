//
// Created by jackc on 10/2/2018.
//
#include<iostream>
#include<sstream>
#include "TestLib.h"
#include "ArrayLib.h"
#include <algorithm>
#include <cmath>
#include <exception>

int findRecursive(const int* const arrayPtr, const int size, const int numToFind, const int index,int& numLinesRun) {
    numLinesRun+=5;
    if (size > 0) {
        numLinesRun+=1;
        if (*(arrayPtr) == numToFind) {
            numLinesRun+=2;
            return index;
        } else {
            numLinesRun+=2;
            findRecursive(arrayPtr + 1, size - 1, numToFind, index+1,numLinesRun);
        }
    } else {
        numLinesRun+=2;
        return -1;
    }
}
int find(const int* const arrayPtr, const int size, const int numToFind, int &numLinesRun){
    int index=0;
    numLinesRun+=6;
    return findRecursive(arrayPtr,size,numToFind,index,numLinesRun);
}

int findLastRecursive(const int* const arrayPtr, const int size, const int numToFind, const int index,int& numLinesRun){
    numLinesRun+=5;
    if (size > 0) {
        numLinesRun+=1;
        if (*(arrayPtr) == numToFind) {
            numLinesRun+=2;
            return index;
        } else {
            numLinesRun+=2;
            findLastRecursive(arrayPtr - 1, size - 1, numToFind, index-1,numLinesRun);
        }
    } else {
        numLinesRun+=2;
        return -1;
    }
}
int findLast(const int* const arrayPtr, const int size, const int numToFind, int &numLinesRun){
    numLinesRun+=6;
    int index=size-1;
    return findLastRecursive(arrayPtr+index,size,numToFind,index,numLinesRun);
}

int findMaxIndex(const int* arrayPtr, int size, int &numLinesRun){
    numLinesRun+=4;
    int maxIndex = 0;
    if (size > 1) {
        numLinesRun+=1;
        for (int i = 0; i < size; i++) {
            numLinesRun+=1;
            if (arrayPtr[i] > arrayPtr[maxIndex]) {
                numLinesRun+=2;
                maxIndex = i;
            }
        }
        numLinesRun+=1;
        return maxIndex;
    } else if (size == 1) {
        numLinesRun+=2;
        return maxIndex;
    }if(size<1) {
        numLinesRun+=2;
        throw std::invalid_argument ("Array size must be > 0");
    }
}

std::string toString(const int* arrayPtr, int size){
    std::string newString="{";

    for(int i=0;i<size;i++){
        newString+=std::to_string(arrayPtr[i]);
        if(i<(size-1)){
            newString+=", ";
        }
    }
    newString+="}";
    return newString;
}

int countOccurrences(const int* arrayPtr, int size, int numToFind, int &numLinesRun){
    numLinesRun+=5;
    int totalOccurrence=0;
    for(int i=0; i<size; i++){
        numLinesRun+=1;
        if(arrayPtr[i]==numToFind){
            totalOccurrence+=1;
            numLinesRun+=2;
        }
    }
    numLinesRun+=1;
    return totalOccurrence;
}

int* copyArray(const int* arrayToCopy, int size, int &numLinesRun){
    numLinesRun+=4;
    int* copyOfArray= new int[size];
    for(int i=0;i<size;i++){
        numLinesRun+=2;
        copyOfArray[i]=arrayToCopy[i];
    }
    if (size < 1){
        copyOfArray=nullptr;
        numLinesRun+=3;
        return copyOfArray;
    }else{
        numLinesRun+=2;
        return copyOfArray;
    }
}

int binFindRecursive(const int* const arrayPtr, const int min, const int max, const int numToFind,int& numLinesRun){
    int mid;
    numLinesRun+=6;
    if(min>max){
        numLinesRun+=2;
        return -1;
    }else{
        numLinesRun+=2;
        mid=(min+max)/2;
        if(numToFind<arrayPtr[mid]){
            numLinesRun+=2;
            binFindRecursive(arrayPtr,min,mid-1,numToFind,numLinesRun);
        }else if(numToFind>arrayPtr[mid]){
            numLinesRun+=2;
            binFindRecursive(arrayPtr,mid+1,max,numToFind,numLinesRun);
        }else{
            numLinesRun+=2;
            return mid;
        }
    }
}
int binFind(const int* const arrayPtr, const int size, const int numToFind, int &numLinesRun){
    numLinesRun+=7;
    int min=0;
    int max=size-1;
    return binFindRecursive(arrayPtr,min,max,numToFind,numLinesRun);
}

int genRandInt(int min, int max, int &numLinesRun){
    numLinesRun+=3;
    if(min>max){
        numLinesRun+=2;
        std::swap(min, max);
    }
    int randNum = rand()%(max-min +1) + min;
    numLinesRun+=2;
    return randNum;
}

int* genRandArray(int size, int min, int max, int &numLinesRun){
    numLinesRun+=4;
    if(min>max){
        numLinesRun+=2;
        std::swap(min, max);
    }
    int* randArray=new int[size];
    int* randPtr=randArray;
    int i=0;
    numLinesRun+=3;
    if(size>=1){
        numLinesRun+=1;
        while(i<=size){
            numLinesRun+=4;
            int randNum = rand() % (max - min + 1) + min;
            randArray[i] = randNum;
            i++;
        }
        numLinesRun+=1;
        return randPtr;
    }else{
        numLinesRun+=2;
        return nullptr;
    }
}

//bubble sort
void sort(int* arrayToSort, int size, int &numLinesRun) {
    numLinesRun += 6;
    int i,j;
    bool swapped;
    for(i=0;i<size-1;i++){
        numLinesRun+=2;
        swapped=false;
        for(j=0;j<size-i-1;j++){
            numLinesRun+=1;
            if(arrayToSort[j]>arrayToSort[j+1]){
                numLinesRun+=5;
                int temp= arrayToSort[j];
                arrayToSort[j]=arrayToSort[j+1];
                arrayToSort[j+1]=temp;
                swapped = true;
            }
        }
        if(swapped==false){
            numLinesRun+=2;
            break;
        }
    }
}

int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun){
    int size3=size1+size2;
    int* mergedArray=new int[size3];
    int i=0;
    int j=0;
    int k=0;
    numLinesRun+=10;

    if (size3>1){
        numLinesRun+=1;
        while(i<size1 && j<size2){
            numLinesRun+=1;
            if(a1[i]<a2[j]){
                numLinesRun+=4;
                mergedArray[k]=a1[i];
                i++;
                k++;
            }else{
                numLinesRun+=4;
                mergedArray[k]=a2[j];
                j++;
                k++;
            }
        }while(i<size1){
            numLinesRun+=2;
            mergedArray[k++]=a1[i++];
        }while(j<size2){
            numLinesRun+=2;
            mergedArray[k++]=a2[j++];
        }numLinesRun+=1;
        return mergedArray;
    }else{
        numLinesRun+=2;
        return nullptr;
    }
}
int* mergeSort(const int* arrayToSort, int size, int& numLinesRun){

}

int* genShuffledArray(int size, int &numLinesRun){
    numLinesRun+=4;
    int* shuffledArray= new int[size];
    int temp=0;
    for(int i=0;i<size;i++){
        numLinesRun+=2;
        shuffledArray[i]=i+1;
    }
    for(int i=0;i<size;i++){
        numLinesRun+=5;
        int randomIndex=rand()%size;
        temp=shuffledArray[i];
        shuffledArray[i]=shuffledArray[randomIndex];
        shuffledArray[randomIndex]=temp;
    };

    if (size < 1){
        shuffledArray=0;
        numLinesRun+=3;
        return shuffledArray;
    }else{
        numLinesRun+=2;
        return shuffledArray;
    }
}