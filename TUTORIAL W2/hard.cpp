using System;

class Program
{
    static int FindMaxValue(int[][] mat, int n)
    {
        int maxValue = int.MinValue;
        int[,] maxMatrix = new int[n, n];

        maxMatrix[0, 0] = mat[0][0];

        for (int j = 1; j < n; j++)
        {
            maxMatrix[0, j] = Math.Min(mat[0][j], maxMatrix[0, j - 1]);
        }

        for (int i = 1; i < n; i++)
        {
            maxMatrix[i, 0] = Math.Min(mat[i][0], maxMatrix[i - 1, 0]);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (mat[i][j] - maxMatrix[i - 1, j - 1] > maxValue)
                {
                    maxValue = mat[i][j] - maxMatrix[i - 1, j - 1];
                }

                maxMatrix[i, j] = Math.Min(mat[i][j], 
                                  Math.Min(maxMatrix[i - 1, j], maxMatrix[i, j - 1]));
            }
        }

        return maxValue;
    }

    static void Main()
    {
        int[][] mat = new int[][]
        {
            new int[] { 1, 2, -1, -4, -20 },
            new int[] { -8, -3, 4, 2, 1 },
            new int[] { 3, 8, 6, 1, 3 },
            new int[] { -4, -1, 1, 7, -6 },
            new int[] { 0, -4, 10, -5, 1 }
        };

        int n = mat.Length;
        Console.WriteLine(FindMaxValue(mat, n));
    }
}