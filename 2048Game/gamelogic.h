#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#define ROW 4
#define COL 4

enum CMD
{
    CMD_UP,
    CMD_DOWN,
    CMD_LEFT,
    CMD_RIGHT,
};

enum STAT
{
    STAT_WAIT,
    STAT_PROCESS,
    STAT_WIN,
    STAT_LOSE,
};
class GameLogic
{
public:
    GameLogic();
    bool createNum();
    void process(int cmd);
    int judge();
    void initAll();
    void calProb();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    bool getGameStart();
    void setGameStart(bool);
    void setGradeUpCoefficient(float);
    int getData(int,int);
    int getGrade();
    int getGradeBasic();
    int getGradeUp();
    int getStep();

private:
    bool gameStart;
    int data[4][4];
    float grade;
    int gradeBasic;
    float gradeUp;
    int step;
    float gradeUpCoefficient;
    int prob2;
    int prob4;
    int prob8;
    int prob16;
};

#endif // GAMELOGIC_H
