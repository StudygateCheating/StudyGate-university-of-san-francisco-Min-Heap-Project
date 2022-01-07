#include <iostream>
#include <vector>
using namespace std;


// In this project, implement a minimum heap using vector
// Implement two functions
// -- insert(int key): insert a new key into the heap
// -- remove(): remove the root key from the heap
// In the main function, we will first input 10 keys into the heap
// Then, we will enumarate them from the vector
// The enumeration Function has been implemented for you


class heap
{

    public:
        void enumerate ();  // enumerate all elements in the heap
        void insert (int key);  // insert a new key into the heap vector
        void remove ();     // remove root key from the heap
        vector < int >x;

        void MoveUp(int index); // swap the child node to parent node when parent > child
        void MoveDown(int index); // same as BubbleUp but will work for both left and right child nodes

};


void heap::enumerate ()  // enumerate all elements in the heap
{

    for (int i = 0; i < x.size (); i++)
    {
        cout << x[i] << ' ';
    }

}

void heap::insert (int val)  // insert a new key into the heap vector
{
    int length = x.size ();
    x.push_back(val);
    MoveUp(length); // swap the child node to parent node when parent > child
}

void heap::remove()  // remove root key from the heap
{
    int length = x.size();

    if(length == 0)
        return;


    x[0] = x[length-1];
    x.pop_back();

   MoveDown(0);
}

void heap::MoveUp(int index) // swap the child node to parent node when parent > child
{
    if(index == 0) //if index=0, no need to swap
        return;

    int pIndex = (index-1)/2;

    if(x[pIndex] > x[index]) // swapping parent index with index when parent index > index
    {
        int temp = x[pIndex];
        x[pIndex] = x[index];
        x[index] = temp;
        MoveUp(pIndex); // recursive function to make the lowest value go up as root of tree
    }
}

void heap::MoveDown(int index) 
{
    int length = x.size(); // assigning size of vector as length
    int leftChild = 2*index + 1; // assigning left child index
    int rightChild = 2*index + 2; // assigning right child index

    if(leftChild >= length)
        return;

    int minIndex = index; // assigning min index

    if(x[index] > x[leftChild]) //comparing the min index with left child index
    {
        minIndex = leftChild; // assigning left child index as min index 
    }

    if((rightChild < length) && (x[minIndex] > x[rightChild])) //comparing the min index with right child index
    {
        minIndex = rightChild; // assigning right child index as min index as condition was satisfied
    }

    if(minIndex != index) //swapping min index with index
    {
        int temp = x[index];
        x[index] = x[minIndex];
        x[minIndex] = temp;
        MoveDown(minIndex); //recursive function to send the lowest value to root and bigger values to child nodes
    }
}

int main ()
{

    int tmp[10];

    for (int i = 0; i < 10; i++)
    {

        cin >> tmp[i];

    }

    heap x;

    for (int i = 0; i < 10; i++)
    {

        x.insert (tmp[i]);

    }
    int operationChoice;

    cin >> operationChoice;

    if (operationChoice == 1)
    {               // enumerate key
        x.enumerate ();

    }

    else if (operationChoice == 2)
    {               // remove the smallest element from the heap and update the heap
        x.remove ();

        x.enumerate ();

    }

}


