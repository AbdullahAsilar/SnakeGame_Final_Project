#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.


// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

// constructor 
objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; // 200 elements on the heap
    listSize = 0; //no valid element in the list at the beginning
    arrayCapacity = ARRAY_MAX_CAP; //array capacity is set to max
}

// destructor. 
objPosArrayList::~objPosArrayList()
{
    delete[] aList; //deleting the array from the memory
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize<arrayCapacity){ //shifting elements, it is needed in order to add a header to the list index 0 should be empty
        for(int i = listSize; i>0; i--){
            aList[i].setObjPos(aList[i-1]); // changing the object at index i-1 to index i
        }

        aList[0].setObjPos(thisPos);

        listSize++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize < arrayCapacity){ // element shifting is not needed as we are adding at the end
        aList[listSize].setObjPos(thisPos);
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    if(listSize < arrayCapacity){ 
        for(int i =0; i< listSize; i++){ //removing the head by shifting the element to the left
            aList[i].setObjPos(aList[i+1]);
        }

        listSize--; // updating the listSize as the head is removed
    }
}

void objPosArrayList::removeTail()
{
    if(listSize< arrayCapacity){
        listSize--; //removing the tail, shifting is not needed
    }
}

objPos objPosArrayList::getHeadElement() const
{
    if(listSize>0){
        return aList[0];
    }
         
}

objPos objPosArrayList::getTailElement() const
{
    if(listSize>0){
        return aList[listSize-1];
    }
}

objPos objPosArrayList::getElement(int index) const
{
    if(index>=0 && index<listSize){
        return aList[index];
    }
}