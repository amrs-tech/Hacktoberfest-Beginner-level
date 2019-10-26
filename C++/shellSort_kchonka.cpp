// Shell Sort sorting algorithm in C++
// By Kat Chonka, 10/26/19

#include <iostream>
#include <vector>
using namespace std;

// Post-condition: Sorts the data vector according to the shell-sort algorithm
// Parameters: data[] is the vector to be sorted
void shellSort(vector<int> & data, int & size);

int main()
{
  cout << "Welcome to the Shell Sort sorting program." << endl << endl;
  cout << "Enter a 0 when you are done inputting numbers." << endl << endl;

  vector<int> user_data;
  int input = 1;
  while ( input != 0 )
  {
    cout << "Please enter a number: ";
    cin >> input;

    if (input != 0)
      user_data.push_back(input);
  }

  int size = user_data.size();
  shellSort(user_data, size);

  cout << endl;
  cout << "The newly sorted data is: ";
  for (int x : user_data)
    cout << x << " ";
  cout << endl;

  return 0;
}

// Post-condition: Sorts the data vector according to the shell-sort algorithm
// Parameters: data[] is the vector to be sorted
void shellSort(vector<int> & data, int & size)
{
  // Gap is the space between the index of the element to be compared
  // Initial gap is of size/2. In each iteration, reduce the gap.
  for (int gap = size/2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; i++)
    {
        for (int j = i - gap; j >= 0; j = j-gap)
        {
          if (data[j+gap] >= data[j])
            break;
          else //swap the values
          {
            int temp = data[j];
            data[j] = data[j+1];
            data[j+1] = temp;
          }
        }
    }
  }
}
