class Solution:
    def gameOfLife(self, board: list[list[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # Following possibilities are there and we can represent it with different codes:
        #i) dead -> remain dead (0)
        #ii) alive -> remain alive (1)
        #iii) dead -> alive (2)
        #iv) alive -> dead (-1)

        dx = [-1, -1, -1, 0, 0, 1, 1, 1]
        dy = [-1, 0, 1, -1, 1, -1, 0, 1]
        m = len(board)
        n = len(board[0])

        for i in range(m):
            for j in range(n):
                # count the number of alive cells in neighbor
                count = 0
                for k in range(len(dx)):
                    x = i + dx[k]
                    y = j + dy[k]
                    
                    if (x >= 0 and x < m) and (y >= 0 and y < n):
                        if board[x][y] == 1 or board[x][y] == -1:
                            count+=1
                    
                # dies because of over or underpopulation
                if (count > 3 or count < 2) and board[i][j]==1:
                    board[i][j] = -1

                # becomes alive
                elif count == 3 and board[i][j] == 0: 
                    board[i][j] = 2

        #changing 2 -> 1 and -1 to 0
        for i in range(m):
            for j in range(n):
                if board[i][j] == 2:
                    board[i][j] = 1
                elif board[i][j] == -1:
                    board[i][j] = 0



def main():
    obj = Solution()
    board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
    obj.gameOfLife(board)
    print(board)

if __name__=="__main__":
    main()