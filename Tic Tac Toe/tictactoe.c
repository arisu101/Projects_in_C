#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifdef WIN_32
#define CLEAR_SCREENSCREEN "cls"
#else
#define CLEAR_SCREEN "clear"

#endif

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

void printBoard() {
  printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
  printf("\n---|---|---\n\n");
}

int checkFreeSpaces() {
  int freeSpaces = 9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        freeSpaces--;
      }
    }
  }
  return freeSpaces;
}

void playerMove() {
  int x, y;
  printf("Enter row #(1-3): ");
  scanf("%d", &x);
  x--;
  printf("Enter column #(1-3): ");
  scanf("%d", &y);
  y--;
  do {
    if (board[x][y] != ' ') {
      printf("Invalid move try again.\n");
      printBoard();
      playerMove();
    } else {
      board[x][y] = PLAYER;
      break;
    }

  } while (board[x][y] == ' ');
}

void printWinner(char winner) {
  if (winner == PLAYER) {
    printf("Player Wins!\n");
  } else if (winner == COMPUTER) {
    printf("Computer Wins!\n");
  } else {
    printf("It's a tie!\n");
  }
}

void computerMove() {
  srand(time(0));
  int x, y;
  if (checkFreeSpaces() > 0) {
    do {
      x = rand() % 3;
      y = rand() % 3;
    } while (board[x][y] != ' ');
    board[x][y] = COMPUTER;
  } else {
    printWinner(' ');
  }
}

char checkWinner() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
      return board[i][0];
    }
  }

  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return board[0][i];
    }
  }

  if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return board[0][0];
  }

  if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
    return board[0][2];
  }
  return ' ';
}

void credits() {
  printf("\n\t\t\t\tPROJECT\n\t\t\t    Tic Tac Toe ON C");
  printf("\n\n\n\t\t\t\tCSIT 2081\n\t\tSagarmatha College of Science and "
         "Technology");
  sleep(4);
  printf("\n\n\t\t\tDeveloped BY\n\t\t   "
         "1.Bikhyat Shrestha\n\t\t   "
         "2.Charchil Neupane\n\t\t   "
         "3.Ayush Paudel");

  puts("\n\n\n");
}

const char PX = 'X';
const char PO = 'O';

int freeSpaceCheck() {
  int freeSpaces = 9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != ' ') {
        freeSpaces--;
      }
    }
  }
  return freeSpaces;
}

void playerMoveFriend(char currentPlayer) {
  int x, y;
  printf("Player %c, enter row #(1-3): ", currentPlayer);
  scanf("%d", &x);
  x--;
  printf("Player %c, enter column #(1-3): ", currentPlayer);
  scanf("%d", &y);
  y--;
  do {
    if (board[x][y] != ' ') {
      printf("Invalid move, try again.\n");
      printBoard();
      playerMoveFriend(currentPlayer);
    } else {
      board[x][y] = currentPlayer;
      break;
    }

  } while (board[x][y] == ' ');
}

char checkWinnerFriend() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
      return board[i][0];
    }
  }

  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return board[0][i];
    }
  }

  if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return board[0][0];
  }

  if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
    return board[0][2];
  }

  return ' ';
}

void printWinnerFriend(char winner) {
  if (winner == PX) {
    printf("Player X Wins!\n");
  } else if (winner == PO) {
    printf("Player O Wins!\n");
  } else {
    printf("It's a tie!\n");
  }
}

int comp() {
  char winner = ' ', response;
  do {
    winner = ' ';
    response = ' ';
    resetBoard();
    while (winner == ' ' && checkFreeSpaces() != 0) {

      printBoard();
      playerMove();
      winner = checkWinner();
      if (winner != ' ' || checkFreeSpaces() == 0) {
        break;
      }
      printBoard();
      computerMove();
      winner = checkWinner();
      if (winner != ' ' || checkFreeSpaces() == 0) {
        break;
      }
    }
    printBoard();
    printWinner(winner);
    printf("\nDo you want to play again? (Y/N)\n");
    scanf(" %c", &response);
    if (response == 'Y' || response == 'y') {
      system(CLEAR_SCREEN);
    }
  } while (response == 'Y' || response == 'y');
  return 0;
}
void Friends() {
  char winner = ' ';
  char response;
  do {
    winner = ' ';
    response = ' ';
    resetBoard();
    while (winner == ' ' && freeSpaceCheck() != 0) {
      printBoard();
      playerMoveFriend(PX);
      winner = checkWinnerFriend();
      if (winner != ' ' || freeSpaceCheck() == 0) {
        break;
      }
      printBoard();
      playerMoveFriend(PO);
      winner = checkWinnerFriend();
      if (winner != ' ' || freeSpaceCheck() == 0) {
        break;
      }
    }
    printBoard();
    printWinnerFriend(winner);
    printf("\nDo you want to play again? (Y/N)\n");
    scanf(" %c", &response);
    if (response == 'Y' || response == 'y') {
      system(CLEAR_SCREEN);
    }
  } while (response == 'Y' || response == 'y');
}
int main() {
  credits();
  sleep(4);
  char c;
  printf("Play against computer or friend (if you have any :-)) (C/F)\n");
  scanf(" %c", &c);
  if (c == 'C' || c == 'c') {
    comp();
  } else if (c == 'F' || c == 'f') {
    Friends();
  }
  printf("Sad to see you go.");
  return 0;
}
