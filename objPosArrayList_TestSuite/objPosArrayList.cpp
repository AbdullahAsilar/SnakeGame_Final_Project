#include "objPosArrayList.h"

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
    objPos returnPos;
    if(listSize>0){ //validation
        returnPos.setObjPos(aList[0]);
    }
    
    return returnPos;
}

objPos objPosArrayList::getTailElement() const
{
    objPos returnPos;
    if(listSize>0){ //validation
        returnPos.setObjPos(aList[listSize-1]);
    }
    return returnPos;
}

objPos objPosArrayList::getElement(int index) const
{
    objPos returnPos;
    if(index>=0 && index<listSize){
        returnPos.setObjPos(aList[index]);
    }
    return returnPos;
}