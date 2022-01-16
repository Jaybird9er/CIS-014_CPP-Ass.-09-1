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
    // checks to make sure it's a triangle
    for(int x = 0; x < maze.size(); x++)
    {
        if(maze[x].size() == maze[x+1].size())
        {
            return 0;
        }
    }

    // since each preceding row has one less value than
    // the one below, just eliminate the value sum that
    // is the minimum for each row -- I way over thought this!!!
    for(int i = maze.size() - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            if(maze[i+1][j] > maze[i+1][j+1])
                maze[i][j] += maze[i+1][j];
            else
                maze[i][j] += maze[i+1][j+1];
        }
    }
    return maze[0][0];
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
