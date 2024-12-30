#include <iostream>
using namespace std;


void insertionSort(vector<int>& array)
{

    for (int i = 1; i < array.size();i++)
    {

        const int key = array[i];

        //Finding the Correct Postion for Key in Sorted Array
        int j = i - 1;
        while(j>=0 and array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1 ] = key;
    }

}

int main()
{
    vector<int> array = {19,8,19,0,1,2,5,6};

    insertionSort(array);
    for(int& i:array)
    {
        cout<<i << " ";
    }
    return 0;
}
