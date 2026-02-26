#include <iostream>
using namespace std;

int jod(int arr[], int size)
{
    int ans = 0;
    for(int i = 0; i < size ; i++)
    {
        ans = ans + arr[i];
    }


    return ans; 
}

int main()
{
    int size;
    cout << "what is the size of array:"<<endl; 
    cin >> size;
    int list[50];
    cout << endl << "enter the values of array:"<< endl;
    for (int i = 0; i < size; i++)
    {
        cin >> list[i];
    }
    int final = jod(list,size);
    cout<<endl<< final <<endl;

    return 0;
}