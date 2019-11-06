/*Algorithm

1) Pick up the first element. It has two sides: A[0] and B[0].

2) Check if one could make all elements in A row or B row to be equal to A[0]. If yes, return the minimum number of rotations needed.

3) Check if one could make all elements in A row or B row to be equal to B[0]. If yes, return the minimum number of rotations needed.

4)Otherwise return -1.

*/

class Solution {
  public:
  /*
  Return min number of rotations 
  if one could make all elements in A or B equal to x.
  Else return -1.
  */
  int check(int x, vector<int>& A, vector<int>& B, int n) 
  {
        // how many rotations should be done
        // to have all elements in A equal to x
        // and to have all elements in B equal to x
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < n; i++) {
          // rotations coudn't be done
          if (A[i] != x && B[i] != x) return -1;
          // A[i] != x and B[i] == x
          else if (A[i] != x) rotations_a++;
          // A[i] == x and B[i] != x    
          else if (B[i] != x) rotations_b++;
        }
        // min number of rotations to have all
        // elements equal to x in A or B
        return min(rotations_a, rotations_b);
  }

  int minDominoRotations(vector<int>& A, vector<int>& B) 
  {
        int n = A.size();
        int rotations = check(A[0], A, B, n);
        // If one could make all elements in A or B equal to A[0]
        if (rotations != -1 || A[0] == B[0]) return rotations;
        // If one could make all elements in A or B equal to B[0]
        else return check(B[0], A, B, n);
  }
};
