#include "Doodlebug.hpp"

Doodlebug::Doodlebug(Critter ***matrPtr, int matrSize, int startX, int startY, int startStep) :
Critter(matrPtr, matrSize, startX, startY, startStep) {
  breedSteps = 8;
  critterType = "Doodlebug";
  stepsWithoutEating = 0;
};

bool Doodlebug::breed() {
  int counter = rand() % 4;
  bool foundEmpty = false;

  while (!foundEmpty && counter < 7) {

    switch (counter) {

      case 0:
      case 4:

        if (xCoord > 0 && !matrix[xCoord - 1][yCoord]) {
          matrix[xCoord - 1][yCoord] = new Doodlebug(matrix, matrixSize, xCoord - 1, yCoord, stepCounter);
          foundEmpty = true;
        }
        break;

      case 1:
      case 5:

        if (yCoord < matrixSize - 1 && !matrix[xCoord][yCoord + 1]) {
          matrix[xCoord][yCoord + 1] = new Doodlebug(matrix, matrixSize, xCoord, yCoord + 1, stepCounter);
          foundEmpty = true;
        }
        break;

      case 2:
      case 6:

        if (xCoord < matrixSize - 1 && !matrix[xCoord + 1][yCoord]) {
          matrix[xCoord + 1][yCoord] = new Doodlebug(matrix, matrixSize, xCoord + 1, yCoord, stepCounter);
          foundEmpty = true;
        }
        break;

      case 3:

        if (yCoord > 0 && !matrix[xCoord][yCoord - 1]) {
          matrix[xCoord][yCoord - 1] = new Doodlebug(matrix, matrixSize, xCoord, yCoord - 1, stepCounter);
          foundEmpty = true;
        }
        break;

    }
    counter++;
  }
  return foundEmpty;
};

bool Doodlebug::eat() {
  int counter = rand() % 4;
  bool ateAnt = false;
  while (!ateAnt && counter < 7) {
    switch (counter) {
      case 0:
      case 4:
        if (xCoord > 0 && matrix[xCoord - 1][yCoord] && matrix[xCoord - 1][yCoord]->type() == "Ant") {
          delete matrix[xCoord - 1][yCoord];
          matrix[xCoord - 1][yCoord] = this;
          matrix[xCoord][yCoord] = 0;
          xCoord--;
          ateAnt = true;
        }
        break;

      case 1:
      case 5:
        if (yCoord < matrixSize - 1 && matrix[xCoord][yCoord + 1] && matrix[xCoord][yCoord + 1]->type() == "Ant") {
          delete matrix[xCoord][yCoord + 1];
          matrix[xCoord][yCoord + 1] = this;
          matrix[xCoord][yCoord] = 0;
          yCoord++;
          ateAnt = true;
        }
        break;

      case 2:
      case 6:
        if (xCoord < matrixSize - 1 && matrix[xCoord + 1][yCoord] && matrix[xCoord + 1][yCoord]->type() == "Ant") {
          delete matrix[xCoord + 1][yCoord];
          matrix[xCoord + 1][yCoord] = this;
          matrix[xCoord][yCoord] = 0;
          xCoord++;
          ateAnt = true;
        }
        break;

      case 3:
        if (yCoord > 0 && matrix[xCoord][yCoord - 1] && matrix[xCoord][yCoord - 1]->type() == "Ant") {
          delete matrix[xCoord][yCoord - 1];
          matrix[xCoord][yCoord - 1] = this;
          matrix[xCoord][yCoord] = 0;
          yCoord--;
          ateAnt = true;
        }
        break;

    }
    counter++;
  }
  if (ateAnt) {
    stepsWithoutEating = 0;
  }
  return ateAnt;
};

bool Doodlebug::move() {
  bool moved = true;
  if (!eat()) {
    stepsWithoutEating++;
    if (stepsWithoutEating == 3) {
      moved = false;
    } else {
      int direction = rand() % 4;
      switch (direction) {
        case 0:
          if (xCoord != 0 && !matrix[xCoord - 1][yCoord]) {
            matrix[xCoord - 1][yCoord] = this;
            matrix[xCoord][yCoord] = 0;
            xCoord--;
          }
          break;

        case 1:
          if (yCoord != matrixSize - 1 && !matrix[xCoord][yCoord + 1]) {
            matrix[xCoord][yCoord + 1] = this;
            matrix[xCoord][yCoord] = 0;
            yCoord++;
          }
          break;

        case 2:
          if (xCoord != matrixSize - 1 && !matrix[xCoord + 1][yCoord]) {
            matrix[xCoord + 1][yCoord] = this;
            matrix[xCoord][yCoord] = 0;
            xCoord++;
          }
          break;

        case 3:
          if (yCoord != 0 && !matrix[xCoord][yCoord - 1]) {
            matrix[xCoord][yCoord - 1] = this;
            matrix[xCoord][yCoord] = 0;
            yCoord--;
          }
          break;

      }
    }
  }
  return moved;
};