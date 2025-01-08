/* Count the number of possible triangles -> GFG Daily Problem
Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. 
NOTE: A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.
*/

  int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int count = 0;
        int i, j, k; // Three pointers
        k = n - 1;
        while (k >= 2) {
            j = k - 1;
            i = 0;
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
            k--;
        }
        return count;
    }
