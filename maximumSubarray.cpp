#include <iostream>
using namespace std;
int findLargest(int num1, int num2, int num3) {
    if (num1 >= num2 && num1 >= num3) {
        return num1;
    } else if (num2 >= num1 && num2 >= num3) {
        return num2;
    } else {
        return num3;
    }
}
struct values
{
    int maxLeft;
    int maxRight;
    int sum;
    values(int v1, int v2, int v3): maxLeft(v1),maxRight(v2),sum(v3){}
};

 values findMaxCrossing(vector<int>& array, int low, int mid,int high)
{
     int leftSum = INT32_MIN;
     int sum = 0;
     int maxLeft;

     for(int i = mid; i >= low; --i)
     {
         sum += array[i] ;
         if(sum > leftSum)
         {
             leftSum = sum;
             maxLeft = i;
         }

     }

     int rightSum = INT32_MIN;
     sum = 0;
     int maxRight;

     for(int i = mid + 1; i <= high; ++i)
     {
         sum += array[i] ;
         if(sum > rightSum)
         {
             rightSum = sum;
             maxRight = i;
         }

     }

     return {maxLeft,maxRight,leftSum + rightSum};


}

values findSubArray (vector<int> array, int low, int high)
 {
     if(low == high)
     {
         return {low,high,array[low]};
     }
     int mid = (low + high)/2;
     values left= ( findSubArray(array,low,mid));
     values right = findSubArray(array,mid + 1,high);
     values crossRegion = findMaxCrossing(array,low,mid,high);

     int maxim = findLargest(left.sum,right.sum,crossRegion.sum);

     if(maxim == left.sum)
     {
         return left;
     }
     if(maxim== right.sum)
     {
         return right;
     }
     if(maxim == crossRegion.sum)
     {
         return crossRegion;
     }

 }

int main()
{


    vector<int> array = {8,2,-6,9,1,2};


     values v = findSubArray(array,0,array.size()-1);

     cout<<"sum = >" << v.sum;
     cout<<"left Index = >" << v.maxLeft;
     cout<<"Right Index = >" << v.maxRight;



}
