class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        left, right = 0, n-1
        while left < right:
            # top and bottom will be same as left and right
            top, bottom = left, right
            for i in range(right - left):
                temp = matrix[top][left+i]
                matrix[top][left+i] = matrix[bottom - i][left]
                matrix[bottom - i][left] = matrix[bottom][right-i]
                matrix[bottom][right-i] = matrix[top+i][right]
                matrix[top+i][right] = temp
            left+=1
            right-=1

def main():
    obj = Solution()
    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
    obj.rotate(matrix)
    print(matrix)

if __name__=="__main__":
    main()
 