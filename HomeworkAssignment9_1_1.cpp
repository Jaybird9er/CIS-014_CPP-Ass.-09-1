// YOUR INCLUDE HERE
#include <iostream>
#include <vector>

using namespace std;

// DO NOT MODIFY: this is your C++ class named CIS14 with a method
// that you need to define/implement.
class CIS14
{
    public:
        int getMaxPoints(vector<vector<int>> &maze);
};

/**
 * MEMBER FUNCTION NAME:
 *    getMaxPoints
 * PURPOSE:
 *    The following class method takes the input
 *    vector nested within a vector to determine
 *    the optimal route for a pinball to travel to
 *    get the maximum number of points
 * PARAMETER:
 *    vector<vector<int>> &maze
 * RETURN VALUE:
 *    int: returns the maximum points possible
 */
int CIS14::getMaxPoints(vector<vector<int>> &maze)
{

    vector<int> maxRoute;
    int j, valueIndex;
    // begin on second row from the bottom and find the max value
    // of each possibility
    for (int i = maze.size() - 2; i >= 0; --i)
    {
        int maxVal;
        /// this is works only for the first 2 sets
//        for (j; j < i + 1; ++j)
//        {
//            if(maze[i][j] + maze[i + 1][j] > maze[i][j] + maze[i + 1][j + 1])
//            {
//                maxVal = maze[i + 1][j];
//                valueIndex = j;
//            }
//            else
//            {
//                maxVal = maze[i + 1][j + 1];
//                valueIndex = j;
//            }
//        }
        /// only the last set works here
        int temp;
        for (j; j < i + 1;)
        {
            if(j == 0)
            {
                temp = maze[i][j] + maze[i + 1][j];
                maxVal = maze[i + 1][j];
            }
            if(temp > maze[i][j] + maze[i + 1][j] && temp > maze[i][j] + maze[i + 1][j + 1])
                ++j;
            else
            {
                if(maze[i][j] + maze[i + 1][j] > maze[i][j] + maze[i + 1][j + 1] && maze[i][j] + maze[i + 1][j] > temp)
                {
                    maxVal = maze[i + 1][j];
                    valueIndex = j;
                    temp = maze[i][j] + maze[i + 1][j];
                    ++j;
                }
                else
                {
                    maxVal = maze[i + 1][j + 1];
                    valueIndex = j;
                    temp = maze[i][j] + maze[i + 1][j + 1];
                    ++j;
                }

            }
        }
        // gets value from row just before last row
        if(i == 1 && valueIndex == 2)
        {
            maxRoute.push_back(maze[i][1]);
            i = 0;
        }
        // the rest are meant to align the next column
        else if(valueIndex == maze[i -1].size() - 1)
        {
            j = maze[i - 1].size() - 1;
            cout << "test" << endl;
        }
        else if(valueIndex > 0)
        {
            j = valueIndex - 2;
        }
        else
            j = 0;

        maxRoute.push_back(maxVal);
    }
    maxRoute.push_back(maze[0][0]);

    int maxSum = 0;
    for(int l = 0; l < maxRoute.size(); ++l)
    {
        maxSum += maxRoute[l];
    }
    /// to deal with empty arrays or arrays that are not triangles
    /// test it by determining that each row size is greater by +1
    /// if true program enters while loop containing the process
    /// to get the max value, when it finishes, the while loop
    /// condition is set to false exiting the while loop


    // the function should account for empty vector arrays
    // a row must have one more element than the preceding row
    // when input is empty, your function should return 0


    // determine if maze vector is valid
    for(int x = maze.size() - 1; x > 0; --x)
    {
        if(maze[x].size() <= maze[x - 1].size())
            return 0;
        else
            return maxSum;
    }
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;

    // Construct an input maze
    vector<vector<int>> maze1 = {{0}, {4,1}, {5,3,8}, {1,6,7,3}};

    // Run the getMaxPoints method in the cis14 instance
    cout << cis14.getMaxPoints(maze1) << endl; // 16

    vector<vector<int>> maze2 = {{1}, {1,1}, {1,1,1}, {1,1,1,1}};
    cout << cis14.getMaxPoints(maze2) << endl; // 4


    vector<vector<int>> maze3 = {{3}, {7,4}, {2,4,6}, {8,5,9,3}};
    cout << cis14.getMaxPoints(maze3) << endl; // 4


    vector<vector<int>> maze4 = {{1}, {1,22305}, {1,29394,1}, {1,1,1234,1}, {1,1,3,1,10}};
    cout << cis14.getMaxPoints(maze4) << endl; // 4

    return 0;
}
