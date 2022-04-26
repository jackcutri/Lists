//
// Created by Toby Dragon on 10/30/18.
//

#include "LinkedList.h"

/**
     * Constructor
     */
     //O(1)
LinkedList::LinkedList(){
    front = nullptr;
    end = nullptr;
}

//Destructor
//O(1)
LinkedList::~LinkedList(){
    while(front != nullptr){
        LinkedNode* toDelete = front;
        front = front->getNext();
        delete toDelete;
    }
}

/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 */
 //O(1)
void LinkedList::insertAtEnd(int itemToAdd){
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    if(front == nullptr){
        front = newNode;
        end = newNode;
    }else{
        end->setNext(newNode);
        end = newNode;
    }
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
 //O(n)
int LinkedList::getValueAt(int index){
    LinkedNode* tempPtr = front;
    if(index<0 || front== nullptr){
        throw std::out_of_range("Bad index given.");
    }else{
        for(int i=0;i<index;i++){
            tempPtr = tempPtr->getNext();
            if(tempPtr== nullptr){
                throw std::out_of_range("Bad index given.");
            }
        }
        int valueAt = tempPtr->getItem();
        return valueAt;
    }
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
 //O(n)
std::string LinkedList::toString(){
    LinkedNode* tempPtr = front;
    std::string newString="{";

    while(tempPtr!= nullptr){
        newString+=std::to_string(tempPtr->getItem());
        if(tempPtr->getNext()!= nullptr){
            newString+=", ";
        }tempPtr = tempPtr->getNext();
    }newString+="}";
    return newString;
}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 */
 //O(1)
bool LinkedList::isEmpty(){
    if (front == nullptr){
        return true;
    }else{
        return false;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
//O(n)
int LinkedList::itemCount(){
    LinkedNode* tempPtr = front;
    int items = 0;
    while(tempPtr!= nullptr){
        tempPtr = tempPtr->getNext();
        items++;
    }return items;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 */
 //O(n)
void LinkedList::clearList(){
    while(front!= nullptr){
        LinkedNode* toDelete = front;
        front = front->getNext();
        delete toDelete;
    }
}

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
 //O(n)
int LinkedList::find(int numToFind){
    LinkedNode* tempPtr = front;
    int index=0;
    while(tempPtr->getItem() != numToFind){
        if(tempPtr==end){
            return -1;
        }tempPtr = tempPtr->getNext();
        index++;
    }return index;
}

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
 //O(n)
int LinkedList::findLast(int numToFind){
    LinkedNode* tempPtr = front;
    int index=0;
    int lastIndex=0;
    int found=0;
    while(tempPtr!= nullptr){
        if(tempPtr->getItem() == numToFind){
            found++;
            lastIndex=index;
        }
        tempPtr=tempPtr->getNext();
        index++;
    }
    if(found==0){
        return -1;
    }else{
        return lastIndex;
    }

}

/**
 * finds the largest value in the array
 * @return the first index of the maximum value
 * @throws out_of_range exception if there is no item to remove
 */
 //O(n)
int LinkedList::findMaxIndex(){
    if(front== nullptr){
        throw std::out_of_range("In findMaxIndex, List must have items");
    }else{
        int index=0;
        int maxIndex=0;
        int max= front->getItem();
        LinkedNode* tempPtr = front;

        while(tempPtr!=nullptr){
            if(tempPtr->getItem() > max){
                maxIndex=index;
                max=tempPtr->getItem();
                index++;
                tempPtr=tempPtr->getNext();
            }else{
                index++;
                tempPtr=tempPtr->getNext();
            }
        }return maxIndex;
    }
}

/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
 //O(1)
void LinkedList::insertAtFront(int itemToAdd){
    LinkedNode* newNode= new LinkedNode(itemToAdd);
    if(front == nullptr){
        front = newNode;
        end=newNode;
    }else{
        newNode->setNext(front);
        front=newNode;
    }

}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
 */
 //O(n)
void LinkedList::insertAt(int itemToAdd, int index) {
    if(index<0){
        throw std::out_of_range("Bad index given.");
    }else{
        LinkedNode* newNode = new LinkedNode(itemToAdd);
        LinkedNode* tempPtr = front;
        LinkedNode* tempPtr2 = nullptr;
        int at = 0;
        if(index==0){
            front=newNode;
            end=newNode;
        }

        while (at < index-1) {
            tempPtr = tempPtr->getNext();
            at++;
            if(tempPtr== nullptr){
                throw std::out_of_range("Bad index given.");
            }
        }
        tempPtr2 = tempPtr->getNext();
        newNode->setNext(tempPtr2);
        tempPtr->setNext(newNode);
    }
}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
 //O(n)

int LinkedList::removeValueAtEnd(){
    if(end== nullptr){
        throw std::out_of_range("In removeValueAtEnd, List must have items");
    }else {
        LinkedNode *tempPtr = front;
        while (tempPtr->getNext() != end && tempPtr!= nullptr) {
            tempPtr = tempPtr->getNext();
        }
        LinkedNode* toDelete = tempPtr->getNext();
        int value = toDelete->getItem();
        end = tempPtr;
        delete toDelete;
        return value;
    }
}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
 //O(1)
int LinkedList::removeValueAtFront(){
    if(front != nullptr){
        LinkedNode *toDelete = front;
        front = front->getNext();
        int value=toDelete->getItem();
        delete toDelete;
        return value;
    }else {
        throw std::out_of_range("In removeValueAtFront, List must have items");
    }
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
 //O(n)
int LinkedList::removeValueAt(int index){
    LinkedNode* tempPtr=front;
    LinkedNode* tempPtr2= nullptr;
    int at=0;

    while(at<index-1){
        tempPtr=tempPtr->getNext();
        at++;
    }int value= tempPtr->getNext()->getItem();
    LinkedNode* toDelete = tempPtr->getNext();
    tempPtr2=tempPtr->getNext();
    tempPtr2=tempPtr2->getNext();
    tempPtr->setNext(tempPtr2);
    delete toDelete;
    return value;

}